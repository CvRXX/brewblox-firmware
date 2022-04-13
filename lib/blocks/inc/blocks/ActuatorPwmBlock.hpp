#pragma once

#include "blocks/Block.hpp"
#include "blocks/DigitalActuatorBlock.hpp"
#include "cbox/CboxPtr.hpp"
#include "control/ActuatorAnalogConstrained.hpp"
#include "control/ActuatorDigitalConstrained.hpp"
#include "control/ActuatorPwm.hpp"

class ActuatorPwmBlock final : public Block<brewblox_BlockType_ActuatorPwm> {
private:
    cbox::CboxPtr<ActuatorDigitalConstrained> actuator;
    ActuatorPwm pwm;
    ActuatorAnalogConstrained constrained;

    bool previousSettingValid = false;

public:
    ActuatorPwmBlock()
        : pwm(actuator.lockFunctor())
        , constrained(pwm)
    {
    }
    ~ActuatorPwmBlock() = default;

    cbox::CboxError read(const cbox::PayloadCallback& callback) const override;
    cbox::CboxError readStored(const cbox::PayloadCallback& callback) const override;
    cbox::CboxError write(const cbox::Payload& payload) override;
    cbox::update_t updateHandler(const cbox::update_t& now) override;
    void* implements(cbox::obj_type_t iface) override;

    const cbox::CboxPtr<ActuatorDigitalConstrained>& targetLookup() const
    {
        return actuator;
    }

    ActuatorPwm& getPwm()
    {
        return pwm;
    }

    const ActuatorPwm& getPwm() const
    {
        return pwm;
    }

    ActuatorAnalogConstrained& getConstrained()
    {
        return constrained;
    }

    const ActuatorAnalogConstrained& getConstrained() const
    {
        return constrained;
    }
};
