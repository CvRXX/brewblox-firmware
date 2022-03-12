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

    virtual cbox::CboxError toResponse(cbox::Command& cmd) const override final;
    virtual cbox::CboxError toStoredResponse(cbox::Command& cmd) const override final;
    virtual cbox::CboxError fromRequest(cbox::Command& cmd) override final;

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
