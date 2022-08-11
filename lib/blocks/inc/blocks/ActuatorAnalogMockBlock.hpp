#pragma once

#include "blocks/Block.hpp"
#include "cbox/Claimable.hpp"
#include "control/ActuatorAnalogConstrained.hpp"
#include "control/ActuatorAnalogMock.hpp"

namespace cbox {
class ObjectContainer;
}

class ActuatorAnalogMockBlock final : public Block<brewblox_BlockType_ActuatorAnalogMock> {
private:
    cbox::Claimable claim;
    ActuatorAnalogMock actuator;
    ActuatorAnalogConstrained constrained;

public:
    ActuatorAnalogMockBlock()
        : actuator(0, 0, 100)
        , constrained(actuator)
    {
    }
    ~ActuatorAnalogMockBlock() = default;

    cbox::CboxError read(const cbox::PayloadCallback& callback) const override;
    cbox::CboxError readStored(const cbox::PayloadCallback& callback) const override;
    cbox::CboxError write(const cbox::Payload& payload) override;
    void* implements(cbox::obj_type_t iface) override;

    ActuatorAnalogMock& get()
    {
        return actuator;
    }
};
