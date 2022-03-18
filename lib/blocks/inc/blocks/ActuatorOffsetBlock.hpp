#pragma once

#include "blocks/Block.hpp"
#include "cbox/CboxPtr.hpp"
#include "control/ActuatorAnalogConstrained.hpp"
#include "control/ActuatorOffset.hpp"

class ActuatorOffsetBlock : public Block<brewblox_BlockType_ActuatorOffset> {
private:
    cbox::CboxPtr<SetpointSensorPair> target;
    cbox::CboxPtr<SetpointSensorPair> reference;
    ActuatorOffset offset;
    ActuatorAnalogConstrained constrained;

public:
    ActuatorOffsetBlock()
        : offset(target.lockFunctor(), reference.lockFunctor())
        , constrained(offset)
    {
    }

    virtual cbox::CboxError read(const cbox::PayloadCallback& callback) const override final;
    virtual cbox::CboxError readStored(const cbox::PayloadCallback& callback) const override final;
    virtual cbox::CboxError write(const cbox::Payload& payload) override final;
    virtual cbox::update_t update(const cbox::update_t& now) override final;
    virtual void* implements(cbox::obj_type_t iface) override final;

    ActuatorOffset& get()
    {
        return offset;
    }
};
