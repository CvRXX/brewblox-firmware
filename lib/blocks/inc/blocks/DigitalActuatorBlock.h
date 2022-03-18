#pragma once

#include "blocks/Block.h"
#include "cbox/CboxPtr.h"
#include "control/ActuatorDigital.h"
#include "control/ActuatorDigitalConstrained.h"
#include "proto/DigitalActuator.pb.h"

class DigitalActuatorBlock : public Block<brewblox_BlockType_DigitalActuator> {
private:
    cbox::CboxPtr<IoArray> hwDevice;
    ActuatorDigital actuator;
    ActuatorDigitalConstrained constrained;

public:
    DigitalActuatorBlock();
    virtual ~DigitalActuatorBlock() = default;

    virtual cbox::CboxError read(const cbox::PayloadCallback& callback) const override final;
    virtual cbox::CboxError readStored(const cbox::PayloadCallback& callback) const override final;
    virtual cbox::CboxError write(const cbox::Payload& payload) override final;
    virtual cbox::update_t update(const cbox::update_t& now) override final;
    virtual void* implements(cbox::obj_type_t iface) override final;

    ActuatorDigitalConstrained& getConstrained()
    {
        return constrained;
    }

private:
    void addPersistedStateToMessage(blox_DigitalActuator_Block& message) const;
};
