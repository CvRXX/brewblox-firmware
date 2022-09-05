#include "blocks/ActuatorPwmBlock.hpp"
#include "blocks/ConstraintsProto.hpp"
#include "cbox/PayloadConversion.hpp"
#include "proto/ActuatorPwm.pb.h"
#include "proto/Constraints.pb.h"

cbox::CboxError
ActuatorPwmBlock::read(const cbox::PayloadCallback& callback) const
{
    blox_ActuatorPwm_Block message = blox_ActuatorPwm_Block_init_zero;
    std::vector<cbox::obj_field_tag_t> excluded;

    message.actuatorId = actuator.getId();

    message.period = pwm.period();
    message.enabled = pwm.enabler.get();
    if (auto val = constrained.desiredSetting()) {
        message.desiredSetting = cnl::unwrap(*val);
    } else {
        excluded.push_back(blox_ActuatorPwm_Block_desiredSetting_tag);
    }

    if (auto val = constrained.value()) {
        message.value = cnl::unwrap(*val);
    } else {
        excluded.push_back(blox_ActuatorPwm_Block_value_tag);
    }
    if (auto val = constrained.setting()) {
        message.setting = cnl::unwrap(*val);
    } else {
        excluded.push_back(blox_ActuatorPwm_Block_setting_tag);
    };
    message.claimedBy = claim.claimedBy();

    getAnalogConstraints(message.constrainedBy, constrained, true);

    return cbox::PayloadBuilder(*this)
        .withContent(&message,
                     blox_ActuatorPwm_Block_fields,
                     blox_ActuatorPwm_Block_size)
        .withMask(cbox::MaskMode::EXCLUSIVE, std::move(excluded))
        .respond(callback)
        .status();
}

cbox::CboxError
ActuatorPwmBlock::readStored(const cbox::PayloadCallback& callback) const
{
    blox_ActuatorPwm_Block message = blox_ActuatorPwm_Block_init_zero;

    message.actuatorId = actuator.getId();
    message.period = pwm.period();
    message.enabled = pwm.enabler.get();
    // default setting to 0 if it is invalid no not have to store excluded field in eeprom
    message.desiredSetting = cnl::unwrap(constrained.desiredSetting().value_or(0));

    getAnalogConstraints(message.constrainedBy, constrained, false);

    return cbox::PayloadBuilder(*this)
        .withContent(&message,
                     blox_ActuatorPwm_Block_fields,
                     blox_ActuatorPwm_Block_size)
        .respond(callback)
        .status();
}

cbox::CboxError
ActuatorPwmBlock::write(const cbox::Payload& payload)
{
    blox_ActuatorPwm_Block message = blox_ActuatorPwm_Block_init_zero;
    auto parser = cbox::PayloadParser(payload);

    if (parser.fillMessage(&message, blox_ActuatorPwm_Block_fields)) {
        if (parser.hasField(blox_ActuatorPwm_Block_actuatorId_tag)) {
            actuator.setId(message.actuatorId, objectId());
        }
        if (parser.hasField(blox_ActuatorPwm_Block_period_tag)) {
            pwm.period(message.period);
        }
        if (parser.hasField(blox_ActuatorPwm_Block_constrainedBy_tag)) {
            setAnalogConstraints(message.constrainedBy, constrained);
        }
        if (parser.hasField(blox_ActuatorPwm_Block_desiredSetting_tag)) {
            constrained.setting(cnl::wrap<ActuatorAnalog::value_t>(message.desiredSetting));
        }
        if (parser.hasField(blox_ActuatorPwm_Block_enabled_tag)) {
            pwm.enabler.set(message.enabled);
        }
    }

    return parser.status();
}

cbox::update_t
ActuatorPwmBlock::updateHandler(cbox::update_t now)
{
    constrained.update();
    auto nextUpdate = pwm.update(now);
    auto settingValid = pwm.setting().has_value();
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
    if (iface == cbox::interfaceId<cbox::Claimable>()) {
        cbox::Claimable* ptr = &claim;
        return ptr;
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
    if (iface == cbox::interfaceId<Enabler>()) {
        Enabler* ptr = &pwm.enabler;
        return ptr;
    }
    return nullptr;
}
