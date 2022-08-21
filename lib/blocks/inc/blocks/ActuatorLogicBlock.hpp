#pragma once

#include "blocks/Block.hpp"
#include "cbox/CboxClaimingPtr.hpp"
#include "control/ActuatorDigitalConstrained.hpp"
#include "control/Enabler.hpp"
#include "control/FixedPoint.hpp"
#include "control/ProcessValue.hpp"
#include "proto/ActuatorLogic.pb.h"
#include <vector>

class DigitalCompare {
public:
    explicit DigitalCompare(const blox_ActuatorLogic_DigitalCompare& data)
        : m_lookup(cbox::obj_id_t(data.id))
        , m_op(data.op)
        , m_result(blox_ActuatorLogic_Result_RESULT_FALSE)
        , m_rhs(ActuatorDigitalBase::State(data.rhs))
    {
    }

    [[nodiscard]] blox_ActuatorLogic_Result eval() const;
    void write(blox_ActuatorLogic_DigitalCompare& dest, bool includeNotPersisted) const;

    void update()
    {
        m_result = eval();
    }

    [[nodiscard]] auto result() const
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
    explicit AnalogCompare(const blox_ActuatorLogic_AnalogCompare& data)
        : m_lookup(cbox::obj_id_t(data.id))
        , m_op(data.op)
        , m_result(blox_ActuatorLogic_Result_RESULT_FALSE)
        , m_rhs(cnl::wrap<fp12_t>(data.rhs))
    {
    }

    [[nodiscard]] blox_ActuatorLogic_Result eval() const;
    void write(blox_ActuatorLogic_AnalogCompare& dest, bool includeNotPersisted) const;

    void update()
    {
        m_result = eval();
    }

    [[nodiscard]] auto result() const
    {
        return m_result;
    }

private:
    cbox::CboxPtr<ProcessValue<fp12_t>> m_lookup;
    blox_ActuatorLogic_AnalogOperator m_op;
    blox_ActuatorLogic_Result m_result;
    fp12_t m_rhs;
};

class ActuatorLogicBlock final : public Block<brewblox_BlockType_ActuatorLogic> {
private:
    cbox::CboxClaimingPtr<ActuatorDigitalConstrained> target;
    Enabler enabler;
    std::vector<DigitalCompare> digitals;
    std::vector<AnalogCompare> analogs;
    std::string expression;
    blox_ActuatorLogic_Result m_result = blox_ActuatorLogic_Result_RESULT_FALSE;
    uint8_t m_errorPos = 0;

public:
    [[nodiscard]] cbox::CboxError read(const cbox::PayloadCallback& callback) const override;
    [[nodiscard]] cbox::CboxError readStored(const cbox::PayloadCallback& callback) const override;
    [[nodiscard]] cbox::CboxError write(const cbox::Payload& payload) override;
    [[nodiscard]] cbox::update_t updateHandler(cbox::update_t now) override;
    [[nodiscard]] void* implements(cbox::obj_type_t iface) override;

    blox_ActuatorLogic_Result evaluate();

private:
    blox_ActuatorLogic_Result eval(std::string::const_iterator& it, uint8_t level) const;
    void writeMessage(blox_ActuatorLogic_Block& message, bool includeNotPersisted) const;
};
