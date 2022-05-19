#include "blocks/ActuatorPwmBlock.hpp"
#include "blocks/ConstraintsProto.hpp"
#include "blocks/FieldTags.hpp"
#include "proto/ActuatorPwm.pb.h"
#include "proto/Constraints.pb.h"

cbox::CboxError
ActuatorPwmBlock::read(const cbox::PayloadCallback& callback) const
{
    blox_ActuatorPwm_Block message = blox_ActuatorPwm_Block_init_zero;
    FieldTags stripped;

    message.actuatorId = actuator.getId();

    message.period = pwm.period();
    message.enabled = pwm.enabled();
    message.desiredSetting = cnl::unwrap(constrained.desiredSetting());

    if (constrained.valueValid()) {
        message.value = cnl::unwrap(constrained.value());
    } else {
        stripped.add(blox_ActuatorPwm_Block_value_tag);
    }
    if (constrained.settingValid()) {
        message.setting = cnl::unwrap(constrained.setting());
        if (pwm.enabled()) {
            message.drivenActuatorId = message.actuatorId;
        }
    } else {
        stripped.add(blox_ActuatorPwm_Block_setting_tag);
    };

    getAnalogConstraints(message.constrainedBy, constrained);
    stripped.copyToMessage(message.strippedFields, message.strippedFields_count, 2);

    return callWithMessage(callback,
                           objectId(),
                           staticTypeId(),
                           0,
                           &message,
                           blox_ActuatorPwm_Block_fields,
                           blox_ActuatorPwm_Block_size);
}

cbox::CboxError
ActuatorPwmBlock::readStored(const cbox::PayloadCallback& callback) const
{
    blox_ActuatorPwm_Block message = blox_ActuatorPwm_Block_init_zero;

    message.actuatorId = actuator.getId();
    message.period = pwm.period();
    message.enabled = pwm.enabled();
    message.desiredSetting = cnl::unwrap(constrained.desiredSetting());
    getAnalogConstraints(message.constrainedBy, constrained);

    return callWithMessage(callback,
                           objectId(),
                           staticTypeId(),
                           0,
                           &message,
                           blox_ActuatorPwm_Block_fields,
                           blox_ActuatorPwm_Block_size);
}

cbox::CboxError
ActuatorPwmBlock::write(const cbox::Payload& payload)
{
    blox_ActuatorPwm_Block message = blox_ActuatorPwm_Block_init_zero;
    auto res = payloadToMessage(payload, &message, blox_ActuatorPwm_Block_fields);

    if (res == cbox::CboxError::OK) {
        actuator.setId(message.actuatorId);
        pwm.period(message.period);
        setAnalogConstraints(message.constrainedBy, constrained);
        constrained.setting(cnl::wrap<ActuatorAnalog::value_t>(message.desiredSetting));
        pwm.enabled(message.enabled);
    }

    return res;
}

cbox::update_t
ActuatorPwmBlock::updateHandler(const cbox::update_t& now)
{
    constrained.update();
    auto nextUpdate = pwm.update(now);
    auto settingValid = pwm.settingValid();
    if (previousSettingValid != settingValid) {
        // When the pwm changes whether it has a valid setting
        // ensure that the output actuator target state in EEPROM is inactive
        // to prevent loading older EEPROM data for it on reboot
        // in which the output is still active
        if (auto ptr = actuator.lock()) {
            ptr->desiredState(ActuatorDigitalBase::State::Inactive);
            actuator.store();
        }
        previousSettingValid = settingValid;

        return now;
    }
    return nextUpdate;
}

void* ActuatorPwmBlock::implements(cbox::obj_type_t iface)
{
    if (iface == staticTypeId()) {
        return this; // me!
    }
    if (iface == cbox::interfaceId<ActuatorAnalogConstrained>()) {
        // return the member that implements the interface in this case
        ActuatorAnalogConstrained* ptr = &constrained;
        return ptr;
    }
    if (iface == cbox::interfaceId<ProcessValue<ActuatorAnalog::value_t>>()) {
        // return the member that implements the interface in this case
        ProcessValue<ActuatorAnalog::value_t>* ptr = &constrained;
        return ptr;
    }
    return nullptr;
}
