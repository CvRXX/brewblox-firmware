#pragma once

#include "blocks/Block.h"
#include "cbox/CboxPtr.h"
#include "control/ActuatorAnalogConstrained.h"
#include "control/ActuatorOffset.h"

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

    virtual cbox::CboxError read(cbox::Command& cmd) const override final;
    virtual cbox::CboxError readPersisted(cbox::Command& cmd) const override final;
    virtual cbox::CboxError write(cbox::Command& cmd) override final;
    virtual cbox::update_t update(const cbox::update_t& now) override final;
    virtual void* implements(const cbox::obj_type_t& iface) override final;

    ActuatorOffset& get()
    {
        return offset;
    }
};
