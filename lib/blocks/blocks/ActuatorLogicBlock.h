#pragma once

#include "ActuatorDigitalConstrained.h"
#include "FixedPoint.h"
#include "ProcessValue.h"
#include "blocks/Block.h"
#include "cbox/CboxPtr.h"
#include "proto/ActuatorLogic.pb.h"
#include <vector>

namespace cbox {
class ObjectContainer;
}

class DigitalCompare {
public:
    DigitalCompare(const blox_ActuatorLogic_DigitalCompare& data, cbox::ObjectContainer& objects)
        : m_lookup(objects, cbox::obj_id_t(data.id))
        , m_op(data.op)
        , m_result(blox_ActuatorLogic_Result_RESULT_FALSE)
        , m_rhs(ActuatorDigitalBase::State(data.rhs))
    {
    }

    ~DigitalCompare() = default;

    blox_ActuatorLogic_Result eval() const;
    void write(blox_ActuatorLogic_DigitalCompare& dest, bool includeNotPersisted) const;

    void update()
    {
        m_result = eval();
    }

    auto result() const
    {
        return m_result;
    }

private:
    cbox::CboxPtr<ActuatorDigitalConstrained> m_lookup;
    blox_ActuatorLogic_DigitalOperator m_op;
    blox_ActuatorLogic_Result m_result;
    ActuatorDigitalBase::State m_rhs;
};

class AnalogCompare {
public:
    AnalogCompare(const blox_ActuatorLogic_AnalogCompare& data, cbox::ObjectContainer& objects)
        : m_lookup(objects, cbox::obj_id_t(data.id))
        , m_op(data.op)
        , m_result(blox_ActuatorLogic_Result_RESULT_FALSE)
        , m_rhs(cnl::wrap<fp12_t>(data.rhs))
    {
    }

    ~AnalogCompare() = default;

    blox_ActuatorLogic_Result eval() const;
    void write(blox_ActuatorLogic_AnalogCompare& dest, bool includeNotPersisted) const;

    void update()
    {
        m_result = eval();
    }

    auto result() const
    {
        return m_result;
    }

private:
    cbox::CboxPtr<ProcessValue<fp12_t>> m_lookup;
    blox_ActuatorLogic_AnalogOperator m_op;
    blox_ActuatorLogic_Result m_result;
    fp12_t m_rhs;
};

class ActuatorLogicBlock : public Block<brewblox_BlockType_ActuatorLogic> {
private:
    cbox::ObjectContainer& objectsRef; // remember object container reference to create constraints
    cbox::CboxPtr<ActuatorDigitalConstrained> target;
    bool enabled = false;
    std::vector<DigitalCompare> digitals;
    std::vector<AnalogCompare> analogs;
    std::string expression;
    blox_ActuatorLogic_Result m_result = blox_ActuatorLogic_Result_RESULT_FALSE;
    uint8_t m_errorPos = 0;

public:
    ActuatorLogicBlock(cbox::ObjectContainer& objects)
        : objectsRef(objects)
        , target(objects)
    {
    }
    virtual ~ActuatorLogicBlock() = default;

    virtual cbox::CboxError streamFrom(cbox::DataIn& dataIn) override final;

    virtual cbox::CboxError streamTo(cbox::DataOut& out) const override final;

    virtual cbox::CboxError streamPersistedTo(cbox::DataOut& out) const override final;

    virtual cbox::update_t update(const cbox::update_t& now) override final;

    virtual void* implements(const cbox::obj_type_t& iface) override final;

    blox_ActuatorLogic_Result evaluate();

private:
    blox_ActuatorLogic_Result eval(std::string::const_iterator& it, uint8_t level) const;
    void writeMessage(blox_ActuatorLogic_Block& message, bool includeNotPersisted) const;
};
