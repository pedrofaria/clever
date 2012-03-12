/**
 * Clever programming language
 * Copyright (c) 2011-2012 Clever Team
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
 */

#include "compiler/value.h"
#include "modules/std/net/net.h"
#include "modules/std/net/tcpsocket.h"
#include "modules/std/rpc/rpc.h"
#include "modules/std/rpc/rpcclass.h"
#include "modules/std/rpc/rpcobject.h"
#include "compiler/compiler.h"
#include "compiler/cstring.h"
#include "types/nativetypes.h"

namespace clever { namespace packages { namespace std { namespace rpc {

/**
 * RPC::constructor()
 */
CLEVER_METHOD(RPC::constructor) {
}

/**
 * Void RPC::operator=(RPC object)
 */
CLEVER_METHOD(RPC::do_assign) {

}

CLEVER_METHOD(RPC::client) {
	RPCValue* rv = CLEVER_GET_VALUE(RPCValue*, value);

	rv->createClient(CLEVER_ARG_STR(0).c_str(), CLEVER_ARG_INT(1), CLEVER_ARG_INT(2));
}

CLEVER_METHOD(RPC::server) {
	RPCValue* rv = CLEVER_GET_VALUE(RPCValue*, value);

	rv->createServer(CLEVER_ARG_INT(0), CLEVER_ARG_INT(1));
}

CLEVER_METHOD(RPC::sendString) {
	RPCValue* rv = CLEVER_GET_VALUE(RPCValue*, value);

	rv->sendString(CLEVER_ARG_STR(0).c_str(), CLEVER_ARG_STR(0).size());
}

CLEVER_METHOD(RPC::loadLibrary) {
	RPCValue* rv = CLEVER_GET_VALUE(RPCValue*, value);

	rv->loadLibrary(CLEVER_ARG_STR(0).c_str());
}

CLEVER_METHOD(RPC::addFunction) {
	RPCValue* rv = CLEVER_GET_VALUE(RPCValue*, value);

	rv->addFunction(CLEVER_ARG_STR(0).c_str(), CLEVER_ARG_STR(1).c_str(), CLEVER_ARG_STR(2).c_str());
}

CLEVER_METHOD(RPC::sendInteger) {
	RPCValue* rv = CLEVER_GET_VALUE(RPCValue*, value);

	rv->sendInteger(CLEVER_ARG_INT(0));
}

CLEVER_METHOD(RPC::callFunction) {
	RPCValue* rv = CLEVER_GET_VALUE(RPCValue*, value);
	size_t size = CLEVER_NUM_ARGS();
	const char* fname = CLEVER_ARG_STR(0).c_str();
	int len_fname = CLEVER_ARG_STR(0).size();
	int n_args = size-1;
	int len_args = 0;

	for(size_t i=1;i<size;++i){
		len_args+=sizeof(char);
		if (CLEVER_ARG_IS_INT(i)) {
			len_args+=sizeof(int);
		} else if (CLEVER_ARG_IS_BOOL(i)) {
			len_args+=sizeof(char);
		} else if (CLEVER_ARG_IS_STR(i)) {
			len_args+=CLEVER_ARG_STR(i).size();
		} else if (CLEVER_ARG_IS_BYTE(i)) {
			len_args+=sizeof(char);
		} else if (CLEVER_ARG_IS_DOUBLE(i)) {
			len_args+=sizeof(double);
		} else if ( CLEVER_ARG_IS_USER(i) ) {
		}
	}

	char* buffer = (char*) malloc (len_args*sizeof(char));

	len_args=0;
	for(size_t i=1;i<size;++i){
		if (CLEVER_ARG_IS_INT(i)) {
			buffer[len_args]='i';
			len_args+=sizeof(char);

			int vi = CLEVER_ARG_INT(i);

			memcpy(buffer+len_args,&vi,sizeof(int));
			len_args+=sizeof(int);

		} else if (CLEVER_ARG_IS_BOOL(i)) {
			buffer[len_args]='b';
			len_args+=sizeof(char);

			char vb = CLEVER_ARG_BOOL(i);

			memcpy(buffer+len_args,&vb,sizeof(char));
			len_args+=sizeof(char);

		} else if (CLEVER_ARG_IS_STR(i)) {
			buffer[len_args]='s';
			len_args+=sizeof(char);

			const char* s=CLEVER_ARG_STR(i).c_str();
			int len=CLEVER_ARG_STR(i).size();

			memcpy(buffer+len_args,&len,sizeof(int));
			len_args+=sizeof(int);

			memcpy(buffer+len_args,&s,len);
			len_args+=len;

		} else if (CLEVER_ARG_IS_BYTE(i)) {
			buffer[len_args]='c';
			len_args+=sizeof(char);

			char vb = CLEVER_ARG_BOOL(i);

			memcpy(buffer+len_args,&vb,sizeof(char));
			len_args+=sizeof(char);
		} else if (CLEVER_ARG_IS_DOUBLE(i)) {
			buffer[len_args]='d';
			len_args+=sizeof(char);

			double vd = CLEVER_ARG_DOUBLE(i);

			memcpy(buffer+len_args,&vd,sizeof(double));
			len_args+=sizeof(double);
		} else if ( CLEVER_ARG_IS_USER(i) ) {
		}
	}

	rv->sendFunctionCall(fname,buffer,len_fname,n_args,len_args);
	free(buffer);

	CLEVER_RETURN_DATA_VALUE(rv->receiveObject());
}

void RPC::init() {
	const Type* rpcobj = CLEVER_TYPE("RPCClass");
	const Type* rpcobjvalue = CLEVER_TYPE("RPCObject");

	addMethod(new Method(CLEVER_CTOR_NAME,
		(MethodPtr)&RPC::constructor, rpcobj));

	addMethod(
		(new Method(CLEVER_OPERATOR_ASSIGN, (MethodPtr)&RPC::do_assign,
			rpcobj, false))
			->addArg("rvalue", rpcobj)
	);

	addMethod(
		(new Method("client", (MethodPtr)&RPC::client, CLEVER_VOID))
			->addArg("host", CLEVER_STR)
			->addArg("port", CLEVER_INT)
			->addArg("time", CLEVER_INT)
	);

	addMethod(
		(new Method("server", (MethodPtr)&RPC::server, CLEVER_VOID))
			->addArg("port", CLEVER_INT)
			->addArg("nconnections", CLEVER_INT)
	);

	addMethod(
		(new Method("loadLibrary", (MethodPtr)&RPC::loadLibrary, CLEVER_VOID))
			->addArg("libname", CLEVER_STR)
	);

	addMethod(
		(new Method("addFunction", (MethodPtr)&RPC::addFunction, CLEVER_VOID))
			->addArg("libname", CLEVER_STR)
			->addArg("funcname", CLEVER_STR)
			->addArg("rettype", CLEVER_STR)
	);

	addMethod(
		(new Method("sendString", (MethodPtr)&RPC::sendString, CLEVER_VOID))
			->addArg("value", CLEVER_STR)
	);

	addMethod(
		(new Method("sendInteger", (MethodPtr)&RPC::sendInteger, CLEVER_VOID))
			->addArg("value", CLEVER_INT)
	);

	addMethod(
		(new Method("callFunction", (MethodPtr)&RPC::callFunction, rpcobjvalue))
			->setVariadic()
			->setMinNumArgs(1)
	);

}

DataValue* RPC::allocateValue() const {
	return new RPCValue;
}

void RPC::destructor(Value* value) const {
}

}}}} // clever::packages::std::rpc


