#pragma once

#include "blocks/Block.h"
#include "control/ActuatorAnalogConstrained.h"
#include "control/ActuatorAnalogMock.h"

namespace cbox {
class ObjectContainer;
}

class ActuatorAnalogMockBlock : public Block<brewblox_BlockType_ActuatorAnalogMock> {
private:
    ActuatorAnalogMock actuator;
    ActuatorAnalogConstrained constrained;

public:
    ActuatorAnalogMockBlock()
        : actuator(0, 0, 100)
        , constrained(actuator)
    {
    }

    virtual cbox::CboxError streamFrom(cbox::DataIn& dataIn) override final;

    virtual cbox::CboxError streamTo(cbox::DataOut& out) const override final;

    virtual cbox::CboxError streamPersistedTo(cbox::DataOut& out) const override final;

    virtual cbox::update_t update(const cbox::update_t& now) override final
    {
        return update_never(now);
    }

    virtual void* implements(const cbox::obj_type_t& iface) override final;

    ActuatorAnalogMock& get()
    {
        return actuator;
    }
};
