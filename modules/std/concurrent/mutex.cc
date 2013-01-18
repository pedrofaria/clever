/**
 * Clever programming language
 * Copyright (c) Clever Team
 *
 * This file is distributed under the MIT license. See LICENSE for details.
 */

#include "core/clever.h"
#include "core/value.h"
#include "modules/std/concurrent/mutex.h"
#include "modules/std/core/function.h"
#include "types/type.h"

namespace clever { namespace packages { namespace std {

void Mutex::dump(const void* data) const
{
	dump(data, ::std::cout);
}

void Mutex::dump(const void* data, ::std::ostream& out) const
{
	Value::DataValue* dvalue =
		static_cast<Value::DataValue*>(const_cast<void*>(data));
	if (dvalue) {

	}
}

void* Mutex::allocData(CLEVER_TYPE_CTOR_ARGS) const
{
	pthread_mutex_t* mutex = new pthread_mutex_t;
	if (mutex) {
		// @TODO(krakjoe) mutex attributes
		pthread_mutex_init(mutex, NULL);
	}
	return mutex;
}

void Mutex::deallocData(void* data)
{
	pthread_mutex_t* mutex = static_cast<pthread_mutex_t*>(data);
	if (mutex) {
		pthread_mutex_destroy(mutex);
		delete mutex;
	}
}

CLEVER_METHOD(Mutex::lock)
{
	pthread_mutex_t* mutex = CLEVER_GET_OBJECT(pthread_mutex_t*, CLEVER_THIS());
	if (!mutex) {
		//CLEVER_THROW(eventually);
		return;
	}

	result->setBool((
		pthread_mutex_lock(
			CLEVER_GET_OBJECT(pthread_mutex_t*, CLEVER_THIS())) == 0)
	);
}

CLEVER_METHOD(Mutex::trylock)
{
	pthread_mutex_t* mutex = CLEVER_GET_OBJECT(pthread_mutex_t*, CLEVER_THIS());
	if (!mutex) {
		//CLEVER_THROW(eventually);
		return;
	}

	result->setBool((
		pthread_mutex_trylock(
			CLEVER_GET_OBJECT(pthread_mutex_t*, CLEVER_THIS())) == 0)
	);
}

CLEVER_METHOD(Mutex::unlock)
{
	pthread_mutex_t* mutex = CLEVER_GET_OBJECT(pthread_mutex_t*, CLEVER_THIS());

	if (!mutex) {
		//CLEVER_THROW(eventually);
		return;
	}

	result->setBool((
		pthread_mutex_unlock(
			CLEVER_GET_OBJECT(pthread_mutex_t*, CLEVER_THIS())) == 0));
}

CLEVER_METHOD(Mutex::ctor)
{
	result->setObj(this, allocData(&args));
}

CLEVER_TYPE_INIT(Mutex::init)
{
	Function* ctor = new Function("Mutex", (MethodPtr) &Mutex::ctor);

	setConstructor(ctor);

	addMethod(ctor);

	addMethod(new Function("lock",    (MethodPtr) &Mutex::lock));
	addMethod(new Function("trylock", (MethodPtr) &Mutex::trylock));
	addMethod(new Function("unlock",  (MethodPtr) &Mutex::unlock));
}

}}} // clever::packages::std
