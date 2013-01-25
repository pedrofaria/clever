#ifndef CLEVER_IRBUILDER_H
#define CLEVER_IRBUILDER_H

#include "core/environment.h"
#include "core/ir.h"

namespace clever {

/**
 * @brief Covenience class to create CleverVM instructions.
 */
class IRBuilder
{
public:
    IRBuilder(Environment* init_glbenv) {

        m_const_env = new Environment(init_glbenv);
        m_temp_env  = new Environment(init_glbenv);

        // null, true and false
        m_const_env->pushValue(new Value());
        m_const_env->pushValue(new Value(true));
        m_const_env->pushValue(new Value(false));
    }

    /// @brief push an instruction to the IR vector
    IR& push(const IR& ir) {
        m_ir.push_back(ir);
        return m_ir.back();
    }

    /// @brief construct and push an instruction to the IR vector
    IR& push(const Opcode& op) {
        return push(IR(op, getSize()));
    }

    /// @brief construct and push an instruction to the IR vector
    IR& push(const Opcode& op, const Operand& a) {
        return push(IR(op, a, getSize()));
    }

    /// @brief construct and push an instruction to the IR vector
    IR& push(const Opcode& op, const Operand& a, const Operand& b) {
        return push(IR(op, a, b, getSize()));
    }

    Environment* getConstEnv() const { return m_const_env; }
    Environment* getTempEnv() const { return m_temp_env; }

    const IRVector& getIR() const { return m_ir; }

    size_t getSize() const { return m_ir.size(); }

    IR& getLast() { return m_ir.back(); }

    IR& getAt(size_t index) {
        return m_ir.at(index);
    }

    IR getNext(const Opcode& op) const {
        return IR(op, m_ir.size());
    }

    IR getNext(const Opcode& op, const Operand& a) {
        return IR(op, a, m_ir.size());
    }

    IR getNext(const Opcode& op, const Operand& a, const Operand& b) {
        return IR(op, a, b, m_ir.size());
    }

    /// @brief get a constant offset for the `c` value
    ValueOffset getInt(long c) {
        return m_const_env->pushValue(new Value(c, true));
    }

    /// @brief get a constant offset for the `c` value
    ValueOffset getDouble(double c) {
        return m_const_env->pushValue(new Value(c, true));
    }

    /// @brief get a constant offset for the `c` value
    ValueOffset getString(const CString* c) {
        return m_const_env->pushValue(new Value(c, true));
    }

    /// @brief get a constant offset for the `c` value
    ValueOffset getNull() {
        return ValueOffset(0, 0);
    }

    /// @brief get a constant offset for the `c` value
    ValueOffset getTrue() {
        return ValueOffset(0, 1);
    }

    /// @brief get a constant offset for the `c` value
    ValueOffset getFalse() {
        return ValueOffset(0, 2);
    }

    /// @brief get a constant offset for a temporary value
    ValueOffset getTemp() {
        return m_temp_env->pushValue(new Value());
    }

private:

    Environment* m_const_env;
    Environment* m_temp_env;

    IRVector m_ir;
};

}

#endif // CLEVER_IRBUILDER_H