/*
 * Clever language
 * Copyright (c) 2011 Clever Team
 *
 * Permission is hereby granted, free of charge, to any person
 * obtaining a copy of this software and associated documentation
 * files (the "Software"), to deal in the Software without
 * restriction, including without limitation the rights to use,
 * copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following
 * conditions:
 * The above copyright notice and this permission notice shall be
 * included in all copies or substantial portions of the Software.
 *
 *  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES
 * OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT
 * HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
 * WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
 * OTHER DEALINGS IN THE SOFTWARE.
 *
 * $Id$
 */

#ifndef CLEVER_VALUE_H
#define CLEVER_VALUE_H

#include <stdint.h>
#include <iostream>
#include <sstream>
#include <cstring>
#include <vector>
#include "refcounted.h"
#include "cstring.h"
#include "global.h"

namespace clever {

class Type;
class Value;
class Method;
class Function;

typedef std::vector<Value*> ValueVector;

/**
 * Base class for value representation
 */
class NO_INIT_VTABLE Value : public RefCounted {
public:
	typedef union {
		int64_t l_value;
		double d_value;
		bool b_value;
		CString* s_value;
		void* u_value;
		ValueVector* v_value;
	} ValueData;

	enum { SET, UNSET, MODIFIED };
	enum { NONE, INTEGER, DOUBLE, STRING, BOOLEAN, VECTOR, USER };
	enum { UNKNOWN, CONST, TEMP };

	Value() : RefCounted(1), m_status(UNSET), m_type(UNKNOWN), m_kind(UNKNOWN), m_type_ptr(NULL) {}
	explicit Value(int kind) : RefCounted(1), m_status(UNSET), m_type(UNKNOWN), m_kind(kind), m_type_ptr(NULL) {}

	virtual ~Value() {
		if (isVector()) {
			ValueVector::const_iterator it = m_data.v_value->begin(), end = m_data.v_value->end();

			while (it != end) {
				(*it)->delRef();
				++it;
			}
			delete m_data.v_value;
		}
	}

	void set_type(int type) { m_type = type; }
	int get_type() const { return m_type; }
	Type* get_type_ptr() const { return m_type_ptr; }
	void set_type_ptr(Type* ptr) { m_type_ptr = ptr; }

	int hasSameType(Value* value) const { return m_type == value->get_type(); }

	virtual bool hasName() const { return false; }
	virtual CString* get_name() const { return NULL; }
	virtual void set_name(CString* name) { /* TODO: throw error */ }

	int get_kind() const { return m_kind; }
	void set_kind(int kind) { m_kind = kind; }

	bool hasSameKind(Value* value) const { return get_kind() == value->get_kind(); }

	bool isConst() const { return m_kind == CONST; }
	bool isTempValue() const { return m_kind == TEMP; }

	int get_status() { return m_status; }
	void set_status(int status) { m_status = status; }

	bool isInitialized() const { return m_status == SET; }
	bool isUninitialized() const { return m_status == UNSET; }
	bool isModified() const { return m_status == MODIFIED; }

	void setInitialized() { m_status = SET; }
	void setUninitialized() { m_status = UNSET; }
	void setModified() { m_status = MODIFIED; }

	bool isPrimitive() const {
		return m_type == INTEGER ||
			m_type == DOUBLE ||
			m_type == BOOLEAN ||
			m_type == STRING;
	}

	/*
	 * Avoid using this check. Type your variables as a
	 * callable value instead of Value to ensure you can call it.
	 */
	virtual bool isCallable() const { return false; }

	bool isInteger() const { return m_type == INTEGER; }
	bool isString() const { return m_type == STRING; }
	bool isDouble() const { return m_type == DOUBLE; }
	bool isBoolean() const { return m_type == BOOLEAN; }
	bool isVector() const { return m_type == VECTOR; }
	bool isUserValue() const { return m_type == USER; }

	void setInteger(int64_t i) { m_data.l_value = i; }
	void setString(CString* s) { m_data.s_value = s; }
	void setDouble(double d) { m_data.d_value = d; }
	void setBoolean(bool b) { m_data.b_value = b; }
	void setVector(ValueVector* v) { m_data.v_value = v; }

	int64_t getInteger() const { return m_data.l_value; }
	CString* getStringP() const { return m_data.s_value; }
	CString getString() const { return *m_data.s_value; }
	double getDouble() const { return m_data.d_value; }
	bool getBoolean() const { return m_data.b_value; }
	ValueVector* getVector() const { return m_data.v_value; }

	const ValueData *get_data() const { return &m_data; }

	void copy(const Value* value) {
		std::memcpy(&m_data, value->get_data(), sizeof(ValueData));
		/* m_type_ptr = value->get_type_ptr(); */
		m_type = value->get_type();
	}

	virtual void set_value(Value* value) { }
	virtual Value* get_value() { return this; }

	virtual std::string toString() {
		std::ostringstream str;

		switch (get_type()) {
			case INTEGER:
				str << getInteger();

				return str.str();
			case DOUBLE:
				str << getDouble();

				return str.str();
			case BOOLEAN:
				return std::string(getBoolean() ? "true" : "false");
			case STRING:
				return getString().c_str();
			default:
				return std::string();
		}
	}

	DISALLOW_COPY_AND_ASSIGN(Value);
private:
	int m_status;
	int m_type;
	int m_kind;
	Type* m_type_ptr;
	ValueData m_data;
};

/**
 * Constant values used for opcodes
 */
class ConstantValue : public Value {
public:
	explicit ConstantValue(double value)
		: Value(CONST) {
		set_type(DOUBLE);
		setDouble(value);
	}

	explicit ConstantValue(int64_t value)
		: Value(CONST) {
		set_type(INTEGER);
		setInteger(value);
	}

	explicit ConstantValue(CString* value)
		: Value(CONST) {
		set_type(STRING);
		setString(value);
	}

	explicit ConstantValue(bool value)
		: Value(CONST) {
		set_type(BOOLEAN);
		setBoolean(value);
	}

	~ConstantValue() { }

	DISALLOW_COPY_AND_ASSIGN(ConstantValue);
};

/**
 * Symbol names used for opcodes.
 *
 * e.g. Functions and Variables.
 */
class NamedValue : public Value {
public:
	NamedValue() { }

	explicit NamedValue(CString* name)
		: Value(), m_name(name) { }

	virtual bool hasName() const { return true; }
	CString* get_name() const { return m_name; }
	void set_name(CString* name) { m_name = name; }

	DISALLOW_COPY_AND_ASSIGN(NamedValue);
private:
	CString* m_name;
};

/**
 * Class that represents the values of functions and methods.
 */
class CallableValue : public NamedValue {
public:
	/* TODO: generate name for anonymous functions, disable set_name(). */
	CallableValue() {}
	explicit CallableValue(CString* name) : NamedValue(name) {}

	~CallableValue() {}

	void set_callback(const Function*& callback) throw() { m_callback.func = callback; }
	void set_callback(const Method*& callback) throw() { m_callback.method = callback; }

	const Function* get_function() throw() {
		m_type = FUNCTION;
		return m_callback.func;
	}
	const Method* get_method() throw() {
		m_type = METHOD;
		return m_callback.method;
	}

	bool isCallable() const { return true; }

	/* TODO: improve/fix this. */
	void call() { }

	DISALLOW_COPY_AND_ASSIGN(CallableValue);
private:
	/* TODO: merge Function/Method */
	union {
		const Function* func;
		const Method* method;
	} m_callback;
	/* TODO: kill this. */
	enum { FUNCTION, METHOD } m_type;
};

/**
 * Temporary storage used for opcodes to storage results
 */
class TempValue : public Value {
public:
	TempValue()
		: Value(TEMP), m_value(NULL) { }

	~TempValue() {
		if (m_value) {
			m_value->delRef();
		}
	}

	Value* get_value() {
		return m_value;
	}

	void set_value(Value* value) {
		if (m_value) {
			m_value->delRef();
		}

		m_value = value;
	}

	std::string toString() {
		if (m_value) {
			return m_value->toString();
		} else {
			return std::string();
		}
	}

	DISALLOW_COPY_AND_ASSIGN(TempValue);
private:
	Value* m_value;
};

} // clever

#endif // CLEVER_VALUE_H
