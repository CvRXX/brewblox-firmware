#pragma once

#include "blocks/Block.hpp"
#include "cbox/CboxClaimingPtr.hpp"
#include "control/ActuatorAnalogConstrained.hpp"
#include "control/ActuatorOffset.hpp"

class ActuatorOffsetBlock final : public Block<brewblox_BlockType_ActuatorOffset> {
private:
    cbox::CboxClaimingPtr<SetpointSensorPair> target;
    cbox::CboxPtr<SetpointSensorPair> reference;
    ActuatorOffset offset;
    ActuatorAnalogConstrained constrained;

public:
    ActuatorOffsetBlock()
        : offset(target, reference)
        , constrained(offset)
    {
    }
    ~ActuatorOffsetBlock() = default;

    cbox::CboxError read(const cbox::PayloadCallback& callback) const override;
    cbox::CboxError readStored(const cbox::PayloadCallback& callback) const override;
    cbox::CboxError write(const cbox::Payload& payload) override;
    cbox::update_t updateHandler(cbox::update_t now) override;
    void* implements(cbox::obj_type_t iface) override;

    ActuatorOffset& get()
    {
        return offset;
    }
};
