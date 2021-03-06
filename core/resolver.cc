/**
 * Clever programming language
 * Copyright (c) Clever Team
 *
 * This file is distributed under the MIT license. See LICENSE for details.
 */

#include "core/compiler.h"
#include "core/resolver.h"
#include "types/native_types.h"
#include "core/module.h"
#include "core/user.h"

namespace clever { namespace ast {

Resolver::Resolver(const ModManager& ModManager, const std::string& ns_name)
	: Visitor(), m_modmanager(ModManager), m_ns_name(ns_name), m_mod(NULL), m_class(NULL)
{
	// Global environment and scope
	m_symtable = m_scope = new Scope();
	m_scope->setEnvironment(new Environment());
	m_stack.push(m_scope->getEnvironment());

	m_modmanager.importModule(m_scope, m_stack.top(), "std.core");
	m_mod = m_modmanager.getUserModule();
}

void Resolver::visit(Block* node)
{
	m_scope = m_scope->enter();
	m_scope->setEnvironment(m_stack.top());
	m_stack.top()->addRef();

	node->setScope(m_scope);

	Visitor::visit(static_cast<NodeArray*>(node));

	m_scope = m_scope->leave();
}

void Resolver::visit(VariableDecl* node)
{
	const CString* name = node->getIdent()->getName();

	if (m_scope->getLocal(name)) {
		Compiler::errorf(node->getLocation(),
			"Cannot redeclare variable `%S'.", name);
	}

	Value* val = new Value();
	m_scope->pushValue(name, val)->voffset = m_stack.top()->pushValue(val);

	node->getIdent()->accept(*this);

	if (node->hasAssignment()) {
		node->getAssignment()->accept(*this);
	}

	val->setConst(node->isConst());
}

void Resolver::visit(ThreadBlock* node)
{
	if (node->getSize() != NULL) {
		node->getSize()->accept(*this);
	}

	const CString* name = node->getName()->getName();
	clever_assert_not_null(name);

	if (m_scope->getLocal(name)) {
		Compiler::errorf(node->getLocation(),
			"Cannot redeclare thread `%S'.", name);
	}

	Thread* thread = static_cast<Thread*>(CLEVER_THREAD_TYPE->allocData(NULL));

	thread->setUserDefined();

	Value* tval = new Value;
	tval->setObj(CLEVER_THREAD_TYPE, thread);

	thread->setName(*name);
	m_scope->pushValue(name, tval)->voffset = m_stack.top()->pushValue(tval);

	node->getName()->accept(*this);

	m_scope = m_scope->enter();
	m_scope->setEnvironment(new Environment(m_stack.top()));
	m_stack.push(m_scope->getEnvironment());

	thread->setEnvironment(m_scope->getEnvironment());

	node->setScope(m_scope);

	node->getBlock()->accept(*this);

	m_scope = m_scope->leave();
	m_stack.pop();
}

void Resolver::visit(FunctionDecl* node)
{
	static size_t anon_fdecls = 0;

	const CString* name;

	// Create an user-unusable symbol name for anonymous functions
	if (!node->hasIdent() && !node->hasType()) {
		std::stringstream buf;
		buf << "<anonymous " << anon_fdecls++ << ">";

		name = CSTRING(buf.str());

		node->setIdent(new Ident(name, node->getLocation()));
	} else if (node->isCtor()) {
		name = CSTRING("Ctor#" + *node->getType()->getName());
		node->setType(new Type(name, node->getLocation()));
	} else if (node->isDtor()) {
		name = CSTRING("Dtor#" + *node->getType()->getName());
		node->setType(new Type(name, node->getLocation()));
	} else {
		name = node->getIdent()->getName();

		if (!m_ns_name.empty()) {
			name = CSTRING(m_ns_name + ":" + *name);
			node->setIdent(new Ident(name, node->getLocation()));
		}
	}
	clever_assert_not_null(name);

	if (m_scope->getLocal(name)) {
		Compiler::errorf(node->getLocation(),
			"Cannot redeclare function `%S'.", name);
	}

	Function* func = static_cast<Function*>(CLEVER_FUNC_TYPE->allocData(NULL));

	func->setUserDefined();

	Value* fval = new Value;
	fval->setObj(CLEVER_FUNC_TYPE, func);

	func->setName(*name);

	m_scope->pushValue(name, fval)->voffset = m_stack.top()->pushValue(fval);

	if (node->hasIdent()) {
		node->getIdent()->accept(*this);
	} else {
		node->getType()->accept(*this);
	}

	// Check if it is a method
	if (m_class) {
		// Check if it's the constructor
		if (node->isCtor()) {
			m_class->setUserConstructor(func);
		} else if (node->isDtor()) {
			m_class->setUserDestructor(func);
		}
		m_class->addMember(name, fval);
		fval->addRef();
	}

	m_scope = m_scope->enter();

	m_scope->setEnvironment(new Environment(m_stack.top()));
	m_stack.push(m_scope->getEnvironment());
	func->setEnvironment(m_scope->getEnvironment());

	node->setScope(m_scope);

	if (node->hasArgs()) {
		size_t required_args = 0;
		bool found_rhs = false;

		for (size_t i = 0, n = node->numArgs(); i < n;  ++i) {
			Assignment* assign = static_cast<VariableDecl*>(node->getArg(i))->getAssignment();

			assign->setConditional(true);

			if (found_rhs && !assign->getRhs()) {
				Compiler::errorf(assign->getLocation(),
					"Non-default argument found after the default argument list");
			} else if (!found_rhs && assign->getRhs()) {
				found_rhs = assign->getRhs();
			} else {
				++required_args;
			}
		}

		node->getArgs()->accept(*this);

		func->setNumArgs(node->numArgs());
		func->setNumRequiredArgs(required_args);
	}

	if (node->hasVarArg()) {
		node->getVarArg()->getAssignment()->setConditional(true);
		node->getVarArg()->accept(*this);

		func->setVariadic();
	}

	node->getBlock()->accept(*this);

	m_scope = m_scope->leave();
	m_stack.pop();
}

void Resolver::visit(Ident* node)
{
	Symbol* sym = m_scope->getAny(node->getName());

	if (!sym) {
		Compiler::errorf(node->getLocation(),
			"Identifier `%S' not found.", node->getName());
	}

	node->setVOffset(m_scope->getOffset(sym));
	node->setSymbol(sym);
	node->setScope(sym->scope);
}

void Resolver::visit(Type* node)
{
	Symbol* sym = m_scope->getAny(node->getName());

	if (!sym) {
		Compiler::errorf(node->getLocation(),
			"Type `%S' not found.", node->getName());
	}

	node->setVOffset(m_scope->getOffset(sym));
	node->setSymbol(sym);
	node->setScope(sym->scope);
}

void Resolver::visit(Import* node)
{
	size_t kind = node->getFunction() ? ModManager::FUNCTION
		: (node->getType() ? ModManager::TYPE : ModManager::ALL);

	const CString* name = (kind == ModManager::ALL) ? NULL
		: (kind == ModManager::FUNCTION ? node->getFunction()->getName()
			: node->getType()->getName());

	if (node->isNamespaced()) {
		kind |= ModManager::NAMESPACE;
	}

	ast::Node* tree = m_modmanager.importModule(m_scope, m_stack.top(),
		*node->getModule()->getName(), kind, name);

	node->setModuleTree(tree);

	if (tree) {
		Visitor::visit(static_cast<NodeArray*>(tree));
	}
}

void Resolver::visit(Catch* node)
{
	m_scope = m_scope->enter();
	m_scope->setEnvironment(m_stack.top());
	m_stack.top()->addRef();
	node->setScope(m_scope);

	Value* val = new Value();

	m_scope->pushValue(node->getVar()->getName(), val)->voffset = m_stack.top()->pushValue(val);

	node->getVar()->accept(*this);

	Visitor::visit(static_cast<NodeArray*>(node->getBlock()));

	m_scope = m_scope->leave();
}

void Resolver::visit(ClassDef* node)
{
	const CString* name = node->getType()->getName();

	UserType* type = new UserType(name);

	m_mod->addType(type);
	type->init();

	Value* tmp = new Value(type);
	m_scope->pushValue(name, tmp)->voffset = m_stack.top()->pushValue(tmp);

	m_scope = m_scope->enter();
	m_scope->setEnvironment(new Environment(m_stack.top()));
	m_stack.push(m_scope->getEnvironment());
	node->setScope(m_scope);

	Value* val = new Value(type, true);

	m_scope->pushValue(CSTRING("this"), val)->voffset = m_stack.top()->pushValue(val);

	type->setEnvironment(m_stack.top());

	m_class = type;

	if (node->hasAttrs()) {
		node->getAttrs()->accept(*this);
	}

	if (node->hasMethods()) {
		node->getMethods()->accept(*this);
	}

	m_class = NULL;
	m_scope = m_scope->leave();
	m_stack.pop();
}

void Resolver::visit(AttrDecl* node)
{
	const CString* name = node->getIdent()->getName();

	if (m_scope->getLocal(name)) {
		Compiler::errorf(node->getLocation(),
			"Cannot redeclare attribute `%S'.", name);
	}

	Value* val = new Value();
	val->setConst(node->isConst());

//	m_scope->pushValue(name, val)->voffset = m_stack.top()->pushValue(val);
//	node->getIdent()->accept(*this);

	if (node->hasValue()) {
		node->getValue()->accept(*this);
	}

	m_class->addProperty(name, val);

	node->setScope(m_scope);
}

}} // clever::ast
