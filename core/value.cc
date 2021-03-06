/**
 * Clever programming language
 * Copyright (c) Clever Team
 *
 * This file is distributed under the MIT license. See LICENSE for details.
 */

#include "core/value.h"
#include "modules/std/core/int.h"
#include "modules/std/core/double.h"
#include "modules/std/core/bool.h"
#include "core/cthread.h"

namespace clever {

void Value::deepCopy(const Value* value)
{
	clever_assert_not_null(value);

	if (m_data && m_data->refCount() == 1) {
		if (isInt() && value->isInt()) {
			static_cast<IntObject*>(m_data)->value = value->getInt();
			return;
		} else if (isDouble() && value->isDouble()) {
			static_cast<DoubleObject*>(m_data)->value = value->getDouble();
			return;
		} else if (isBool() && value->isBool()) {
			static_cast<BoolObject*>(m_data)->value = value->getBool();
			return;
		}
	}
	TypeObject* val = value->isNull() ? NULL : value->getObj()->clone();

	if (val) {
		cleanUp();
		setObj(value->getType(),  val);
	} else {
		copy(value);
	}
}

void Value::setInt(long n)
{
	if (m_data && m_data->refCount() == 1 && isInt()) {
		static_cast<IntObject*>(m_data)->value = n;
	} else {
		cleanUp();
		setObj(CLEVER_INT_TYPE, new IntObject(n));
	}
}

long Value::getInt() const
{
	return static_cast<IntObject*>(getObj())->value;
}

void Value::setDouble(double n)
{
	if (m_data && m_data->refCount() == 1 && isDouble()) {
		static_cast<DoubleObject*>(m_data)->value = n;
	} else {
		cleanUp();
		setObj(CLEVER_DOUBLE_TYPE, new DoubleObject(n));
	}
}

double Value::getDouble() const
{
	return static_cast<DoubleObject*>(m_data)->value;
}

void Value::setStr(const CString* str)
{
	cleanUp();
	setObj(CLEVER_STR_TYPE, new StrObject(str));
}

void Value::setStr(StrObject* str)
{
	cleanUp();
	setObj(CLEVER_STR_TYPE, str);
}

const CString* Value::getStr() const
{
	return static_cast<StrObject*>(m_data)->value;
}

void Value::setBool(bool n)
{
	if (m_data && m_data->refCount() == 1 && isBool()) {
		static_cast<BoolObject*>(m_data)->value = n;
	} else {
		cleanUp();
		setObj(CLEVER_BOOL_TYPE, new BoolObject(n));
	}
}

bool Value::getBool() const
{
	return static_cast<BoolObject*>(m_data)->value;
}

} // clever
