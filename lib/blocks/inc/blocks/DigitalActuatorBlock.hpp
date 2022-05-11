#pragma once

#include "blocks/Block.hpp"
#include "cbox/CboxPtr.hpp"
#include "control/ActuatorDigital.hpp"
#include "control/ActuatorDigitalConstrained.hpp"
#include "proto/DigitalActuator.pb.h"

class DigitalActuatorBlock final : public Block<brewblox_BlockType_DigitalActuator> {
private:
    cbox::CboxPtr<IoArray> hwDevice;
    ActuatorDigital actuator;
    ActuatorDigitalConstrained constrained;

public:
    DigitalActuatorBlock()
        : hwDevice()
        , actuator(hwDevice, 0)
        , constrained(actuator)
    {
    }
    ~DigitalActuatorBlock() = default;

    cbox::CboxError read(const cbox::PayloadCallback& callback) const override;
    cbox::CboxError readStored(const cbox::PayloadCallback& callback) const override;
    cbox::CboxError write(const cbox::Payload& payload) override;
    cbox::update_t updateHandler(const cbox::update_t& now) override;
    void* implements(cbox::obj_type_t iface) override;

    ActuatorDigitalConstrained& getConstrained()
    {
        return constrained;
    }

private:
    void addPersistedStateToMessage(blox_DigitalActuator_Block& message) const;
};
