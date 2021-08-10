#include "ActuatorPwmBlock.h"
#include "ActuatorAnalogConstraintsProto.h"
#include "blox/FieldTags.h"
#include "proto/cpp/ActuatorPwm.pb.h"
#include "proto/cpp/AnalogConstraints.pb.h"

cbox::CboxError
ActuatorPwmBlock::streamFrom(cbox::DataIn& dataIn)
{
    blox_ActuatorPwm newData = blox_ActuatorPwm_init_zero;
    cbox::CboxError result = streamProtoFrom(dataIn, &newData, blox_ActuatorPwm_fields, blox_ActuatorPwm_size);
    if (result == cbox::CboxError::OK) {
        actuator.setId(newData.actuatorId);
        pwm.period(newData.period);
        setAnalogConstraints(newData.constrainedBy, constrained, objectsRef);
        constrained.setting(cnl::wrap<ActuatorAnalog::value_t>(newData.desiredSetting));
        pwm.enabled(newData.enabled);
    }
    return result;
}

cbox::CboxError
ActuatorPwmBlock::streamTo(cbox::DataOut& out) const
{
    blox_ActuatorPwm message = blox_ActuatorPwm_init_zero;
    FieldTags stripped;
    message.actuatorId = actuator.getId();

    message.period = pwm.period();
    message.enabled = pwm.enabled();
    message.desiredSetting = cnl::unwrap(constrained.desiredSetting());

    if (constrained.valueValid()) {
        message.value = cnl::unwrap(constrained.value());
    } else {
        stripped.add(blox_ActuatorPwm_value_tag);
    }
    if (constrained.settingValid()) {
        message.setting = cnl::unwrap(constrained.setting());
        if (pwm.enabled()) {
            message.drivenActuatorId = message.actuatorId;
        }
    } else {
        stripped.add(blox_ActuatorPwm_setting_tag);
    };

    getAnalogConstraints(message.constrainedBy, constrained);
    stripped.copyToMessage(message.strippedFields, message.strippedFields_count, 2);

    return streamProtoTo(out, &message, blox_ActuatorPwm_fields, blox_ActuatorPwm_size);
}

cbox::CboxError
ActuatorPwmBlock::streamPersistedTo(cbox::DataOut& out) const
{
    blox_ActuatorPwm persisted = blox_ActuatorPwm_init_zero;
    persisted.actuatorId = actuator.getId();
    persisted.period = pwm.period();
    persisted.enabled = pwm.enabled();
    persisted.desiredSetting = cnl::unwrap(constrained.desiredSetting());
    getAnalogConstraints(persisted.constrainedBy, constrained);

    return streamProtoTo(out, &persisted, blox_ActuatorPwm_fields, blox_ActuatorPwm_size);
}

cbox::update_t
ActuatorPwmBlock::update(const cbox::update_t& now)
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

void* ActuatorPwmBlock::implements(const cbox::obj_type_t& iface)
{
    if (iface == BrewBloxTypes_BlockType_ActuatorPwm) {
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
