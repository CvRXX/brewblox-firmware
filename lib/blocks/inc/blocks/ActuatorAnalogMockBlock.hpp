#pragma once

#include "blocks/Block.hpp"
#include "control/ActuatorAnalogConstrained.hpp"
#include "control/ActuatorAnalogMock.hpp"

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

    virtual cbox::CboxError read(const cbox::PayloadCallback& callback) const override final;
    virtual cbox::CboxError readStored(const cbox::PayloadCallback& callback) const override final;
    virtual cbox::CboxError write(const cbox::Payload& payload) override final;

    virtual cbox::update_t update(const cbox::update_t& now) override final
    {
        return update_never(now);
    }

    virtual void* implements(cbox::obj_type_t iface) override final;

    ActuatorAnalogMock& get()
    {
        return actuator;
    }
};
