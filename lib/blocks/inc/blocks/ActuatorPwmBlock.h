#pragma once

#include "blocks/Block.h"
#include "blocks/DigitalActuatorBlock.h"
#include "cbox/CboxPtr.h"
#include "control/ActuatorAnalogConstrained.h"
#include "control/ActuatorDigitalConstrained.h"
#include "control/ActuatorPwm.h"

class ActuatorPwmBlock : public Block<brewblox_BlockType_ActuatorPwm> {
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
    virtual ~ActuatorPwmBlock() = default;

    virtual cbox::CboxError streamFrom(cbox::DataIn& dataIn) override final;

    virtual cbox::CboxError streamTo(cbox::DataOut& out) const override final;

    virtual cbox::CboxError streamPersistedTo(cbox::DataOut& out) const override final;

    virtual cbox::update_t update(const cbox::update_t& now) override final;

    virtual void* implements(const cbox::obj_type_t& iface) override final;

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
