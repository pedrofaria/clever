/**
 * Clever programming language
 * Copyright (c) Clever Team
 *
 * This file is distributed under the MIT license. See LICENSE for details.
 */

#ifdef CLEVER_DEBUG
#include <stdio.h>
#include "core/opcode.h"
#endif
#include "core/scope.h"
#include "core/value.h"
#include "types/type.h"
#include "core/vm.h"

namespace clever {

/// Displays an error message
void VM::error(ErrorLevel level, const char* msg) const
{
	switch (level) {
		case WARNING:
			std::cerr << "Warning: " << msg << std::endl;
			break;
		case ERROR:
			std::cerr << "Error: " << msg << std::endl;
			CLEVER_EXIT_FATAL();
			break;
	}
}

/// Fetchs a Value ptr from the Symbol table
CLEVER_FORCE_INLINE Value* VM::getValue(size_t scope_id, size_t value_id) const
{
	return (*m_scope_pool)[scope_id]->getValue(value_id);
}

/// Fetchs a Value ptr according to the operand type
CLEVER_FORCE_INLINE Value* VM::getValue(Operand& operand) const
{
	switch (operand.op_type) {
		case FETCH_CONST:
			return (*m_const_pool)[operand.value_id];
		case FETCH_VAR:
			return getValue(operand.scope_id, operand.value_id);
		case FETCH_TMP:
			return (*m_tmp_pool)[operand.value_id];
		default:
			return NULL;
	}
}

#ifdef CLEVER_DEBUG
void VM::dumpOperand(Operand& op) const
{
	const char *type[] = {
		"UNUSED", "FETCH_VAR", "FETCH_CONST", "FETCH_TMP", "JMP_ADDR"
	};

	switch (op.op_type) {
		case FETCH_VAR:
			::printf("%3u:%3u ", op.value_id, op.scope_id);
			break;
		case JMP_ADDR:
		case FETCH_CONST:
		case FETCH_TMP:
			::printf("%7u ", op.value_id);
			break;
		case UNUSED:
			::printf("        ");
			break;
	}
	::printf(" (%-11s) | ", type[op.op_type]);
}

void VM::dumpOpcodes() const
{
	for (size_t i = 0, j = m_inst.size(); i < j; ++i) {
		IR& ir = m_inst[i];
		::printf("[%03u] %-12s |", i, get_opcode_name(ir.opcode));
		dumpOperand(ir.op1);
		dumpOperand(ir.op2);
		dumpOperand(ir.result);
		::printf("\n");
	}
}
#endif

// Saves function argument and local variables
void VM::saveVars()
{/*
	Scope* arg_vars   = m_call_stack.top().arg_vars;
	Scope* local_vars = m_call_stack.top().local_vars;

	if (arg_vars) {
		// Save the function argument values
		for (size_t i = 0, j = arg_vars->size(); i < j; ++i) {
			Value* tmp = new Value();

			tmp->copy(getValue(arg_vars->at(i).value_id));
			m_call_stack.top().vars.push_back(
				std::pair<size_t, Value*>(
					arg_vars->at(i).value_id, tmp));
		}
	}
	if (EXPECTED(local_vars != NULL)) {
		// Save the local variables
		for (size_t i = 0, j = local_vars->size(); i < j; ++i) {
			Value* tmp = new Value();

			tmp->copy(getValue(local_vars->at(i).value_id));
			m_call_stack.top().vars.push_back(
				std::pair<size_t, Value*>(
					local_vars->at(i).value_id, tmp));
		}
	}*/
}

// Restore the argument and local variables values
void VM::restoreVars() const
{/*
	FuncVars::const_iterator it = m_call_stack.top().vars.begin(),
		end = m_call_stack.top().vars.end();

	while (EXPECTED(it != end)) {
		Value* var = getValue((*it).first);
		var->copy((*it).second);
		++it;
	}*/
}

// Make a copy of VM instance
void VM::copy(VM* vm)
{
	this->m_pc = vm->m_pc;

	this->m_scope_pool = new ScopePool(vm->m_scope_pool->size());

	this->m_scope_pool->at(0) = vm->m_scope_pool->at(0);
	this->m_scope_pool->at(1) = vm->m_scope_pool->at(1);

	for (size_t id = 2; id < vm->m_scope_pool->size(); ++id) {
		Scope* s = new Scope;

		s->copy(vm->m_scope_pool->at(id));

		this->m_scope_pool->at(id) = s;
	}

	for (size_t i = 0; i < NUM_OPCODES; ++i) {
		this->m_handlers[i] = vm->m_handlers[i];
	}

	this->m_tmp_pool = vm->m_tmp_pool;
	this->m_const_pool = vm->m_const_pool;
	this->f_mutex = vm->getMutex();
}

CLEVER_FORCE_INLINE void VM::increment(IR& op)
{
	Value* value = getValue(op.op1);

	if (value->isNull()) {
		error(VM::ERROR, "Cannot increment null value");
	}
	if (op.opcode == OP_PRE_INC) {
		value->getType()->increment(value);
		getValue(op.result)->copy(value);
	} else {
		getValue(op.result)->copy(value);
		value->getType()->increment(value);
	}
}

CLEVER_FORCE_INLINE void VM::decrement(IR& op)
{
	Value* value = getValue(op.op1);

	if (value->isNull()) {
		error(VM::ERROR, "Cannot decrement null value");
	}
	if (op.opcode == OP_PRE_DEC) {
		value->getType()->decrement(value);
		getValue(op.result)->copy(value);
	} else {
		getValue(op.result)->copy(value);
		value->getType()->decrement(value);
	}
}

void VM::wait()
{
	for (size_t i = 0, j = m_thread_pool.size(); i < j; ++i) {
		void* status;

		pthread_join(m_thread_pool[i]->t_handler, &status);

		delete m_thread_pool[i]->vm_handler;
		delete m_thread_pool[i];
	}
	m_thread_pool.clear();
}

static void* _thread_control(void* arg)
{
	Thread* thread = static_cast<Thread*>(arg);
	VM* vm_handler = thread->vm_handler;


	vm_handler->nextPC();
	vm_handler->run();

	return NULL;
}

// Executes the VM opcodes in a continuation-passing style
void VM::run()
{
	OPCODES;
	OP(OP_RET):
		if (m_call_stack.size()) {
			const StackFrame& frame = m_call_stack.top();

			if (OPCODE.op1.op_type != UNUSED) {
				const Value* val = getValue(OPCODE.op1);

				if (val) {
					m_call_stack.top().ret_val->copy(getValue(OPCODE.op1));
				}
			}
			m_call_stack.pop();

			// Go back to the caller
			VM_GOTO(frame.ret_addr);
		} else {
			// Terminates the execution
			VM_GOTO(m_inst.size());
		}
		DISPATCH;

	OP(OP_ASSIGN):
		{
			Value* var = getValue(OPCODE.op1);
			Value* value = getValue(OPCODE.op2);

			var->copy(value);
		}
		DISPATCH;

	OP(OP_ADD):
		{
			Value* lhs = getValue(OPCODE.op1);
			Value* rhs = getValue(OPCODE.op2);

			if (EXPECTED(!lhs->isNull() && !rhs->isNull())) {
				if (lhs->getType() == CLEVER_INT_TYPE
					&& rhs->getType() == CLEVER_INT_TYPE) {
					getValue(OPCODE.result)->setInt(lhs->getInt() + rhs->getInt());
					getValue(OPCODE.result)->setType(lhs->getType());
				}
			} else {
				error(ERROR, "Operation cannot be executed on null value");
			}
		}
		DISPATCH;

	OP(OP_SUB):
		{
			Value* lhs = getValue(OPCODE.op1);
			Value* rhs = getValue(OPCODE.op2);

			if (EXPECTED(!lhs->isNull() && !rhs->isNull())) {
				if (lhs->getType() == CLEVER_INT_TYPE
					&& rhs->getType() == CLEVER_INT_TYPE) {
					getValue(OPCODE.result)->setInt(lhs->getInt() - rhs->getInt());
					getValue(OPCODE.result)->setType(lhs->getType());
				}
			} else {
				error(ERROR, "Operation cannot be executed on null value");
			}
		}
		DISPATCH;

	OP(OP_MUL):
		{
			Value* lhs = getValue(OPCODE.op1);
			Value* rhs = getValue(OPCODE.op2);

			if (EXPECTED(!lhs->isNull() && !rhs->isNull())) {
				if (lhs->getType() == CLEVER_INT_TYPE
					&& rhs->getType() == CLEVER_INT_TYPE) {
					getValue(OPCODE.result)->setInt(lhs->getInt() * rhs->getInt());
					getValue(OPCODE.result)->setType(lhs->getType());
				}
			} else {
				error(ERROR, "Operation cannot be executed on null value");
			}
		}
		DISPATCH;

	OP(OP_DIV):
		{
			Value* lhs = getValue(OPCODE.op1);
			Value* rhs = getValue(OPCODE.op2);

			if (EXPECTED(!lhs->isNull() && !rhs->isNull())) {
				if (lhs->getType() == CLEVER_INT_TYPE
					&& rhs->getType() == CLEVER_INT_TYPE) {
					getValue(OPCODE.result)->setInt(lhs->getInt() / rhs->getInt());
					getValue(OPCODE.result)->setType(lhs->getType());
				}
			} else {
				error(ERROR, "Operation cannot be executed on null value");
			}
		}
		DISPATCH;

	OP(OP_MOD):
		{
			Value* lhs = getValue(OPCODE.op1);
			Value* rhs = getValue(OPCODE.op2);

			if (EXPECTED(!lhs->isNull() && !rhs->isNull())) {
				if (lhs->getType() == CLEVER_INT_TYPE
					&& rhs->getType() == CLEVER_INT_TYPE) {
					getValue(OPCODE.result)->setInt(lhs->getInt() % rhs->getInt());
					getValue(OPCODE.result)->setType(lhs->getType());
				}
			} else {
				error(ERROR, "Operation cannot be executed on null value");
			}
		}
		DISPATCH;

	OP(OP_JMP):
		VM_GOTO(OPCODE.op1.value_id);

	OP(OP_FCALL):
		{
			Value* func = getValue(OPCODE.op1);
			Function* fdata = static_cast<Function*>(func->getObj());

			clever_assert_not_null(fdata);

			if (fdata->isUserDefined()) {
				if (m_call_stack.size()) {
					saveVars();
				}
				m_call_stack.push(StackFrame());
				m_call_stack.top().ret_addr = m_pc + 1;
				m_call_stack.top().ret_val  = getValue(OPCODE.result);

				// Function argument value binding
				if (fdata->hasArgs()) {
					Scope* arg_scope = fdata->getArgVars();

					m_call_stack.top().arg_vars = arg_scope;

					for (size_t i = 0, j = arg_scope->size(); i < j; ++i) {
						Value* arg_val = getValue(
							arg_scope->at(i).scope->getId(),
							arg_scope->at(i).value_id);

						if (i < m_call_args.size()) {
							arg_val->copy(m_call_args[i]);
						} else {
							arg_val->setNull();
						}
					}
				}
				m_call_args.clear();
				VM_GOTO(fdata->getAddr());
			} else {
				fdata->getPtr()(m_call_args);
				m_call_args.clear();
			}
		}
		DISPATCH;

	OP(OP_BTHREAD):
		{
			Thread* thread = new Thread;

			thread->vm_handler = new VM(this->m_inst);
			thread->vm_handler->copy(this);

			thread->vm_handler->setChild();

			m_thread_pool.push_back(thread);

			pthread_attr_t attr;
			pthread_attr_init(&attr);
			pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_JOINABLE);

			pthread_create(&(thread->t_handler), &attr,
				_thread_control, static_cast<void*>(thread));

			pthread_attr_destroy(&attr);

			VM_GOTO(OPCODE.op1.value_id);
		}

	OP(OP_ETHREAD):
		if (this->isChild()) {
			for (size_t id = 2; id < m_scope_pool->size(); ++id) {
				delete m_scope_pool->at(id);
			}

			delete m_scope_pool;

			VM_EXIT();
		}
		DISPATCH;

	OP(OP_LEAVE):
		{
			const StackFrame& frame = m_call_stack.top();

			if (m_call_stack.size() > 1) {
				restoreVars();
			}

			m_call_stack.pop();

			VM_GOTO(frame.ret_addr);
		}

	OP(OP_SEND_VAL):
		m_call_args.push_back(getValue(OPCODE.op1));
		DISPATCH;

	OP(OP_JMPZ):
		{
			Value* value = getValue(OPCODE.op1);

			if (value->isNull() || !value->asBool()) {
				if (OPCODE.result.op_type != UNUSED) {
					getValue(OPCODE.result)->setNull(); // TODO: boolean
				}
				VM_GOTO(OPCODE.op2.value_id);
			}
			if (OPCODE.result.op_type != UNUSED) {
				getValue(OPCODE.result)->setInt(1); // TODO: boolean
			}
		}
		DISPATCH;

	OP(OP_PRE_INC):
		increment(OPCODE);
		DISPATCH;

	OP(OP_PRE_DEC):
		decrement(OPCODE);
		DISPATCH;

	OP(OP_POS_INC):
		increment(OPCODE);
		DISPATCH;

	OP(OP_POS_DEC):
		decrement(OPCODE);
		DISPATCH;

	OP(OP_JMPNZ):
		{
			Value* value = getValue(OPCODE.op1);

			if (!value->isNull() || value->asBool()) {
				if (OPCODE.result.op_type != UNUSED) {
					getValue(OPCODE.result)->setInt(1); // TODO: boolean
				}
				VM_GOTO(OPCODE.op2.value_id);
			}
			if (OPCODE.result.op_type != UNUSED) {
				getValue(OPCODE.result)->setNull(); // TODO: boolean
			}
		}
		DISPATCH;

	OP(OP_AND):
		{
			Value* lhs = getValue(OPCODE.op1);

			if (!lhs->asBool()) {
				getValue(OPCODE.result)->setNull();
				VM_GOTO(OPCODE.op2.value_id);
			}
			getValue(OPCODE.result)->copy(lhs);
		}
		DISPATCH;

	OP(OP_OR):
		{
			Value* lhs = getValue(OPCODE.op1);

			if (lhs->asBool()) {
				getValue(OPCODE.result)->copy(lhs);
				VM_GOTO(OPCODE.op2.value_id);
			}
		}
		DISPATCH;

	OP(OP_EQUAL):
		DISPATCH;

	OP(OP_NEQUAL):
		DISPATCH;

	OP(OP_LOCK):
		getMutex()->lock();
		DISPATCH;

	OP(OP_UNLOCK):
		getMutex()->unlock();
		DISPATCH;

	OP(OP_HALT):
		VM_EXIT();

	END_OPCODES;
exit:
	wait();
}

} // clever
