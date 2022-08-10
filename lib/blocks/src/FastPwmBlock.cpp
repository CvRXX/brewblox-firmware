#include "blocks/FastPwmBlock.hpp"
#include "blocks/ConstraintsProto.hpp"
#include "cbox/PayloadConversion.hpp"
#include "proto/Constraints.pb.h"

void FastPwmBlock::addPersistedStateToMessage(blox_FastPwm_Block& message) const
{
    message.hwDevice = io.getId();
    message.channel = pwm.channel();
    message.frequency = blox_FastPwm_PwmFrequency(pwm.frequency());
    message.desiredSetting = cnl::unwrap(constrained.desiredSetting().value_or(0));
    message.enabled = pwm.enabler.get();
    message.transitionDurationSetting = transitionDurationSetting;
    message.transitionDurationPreset = transitionDurationPreset;
}

cbox::CboxError
FastPwmBlock::read(const cbox::PayloadCallback& callback) const
{
    blox_FastPwm_Block message = blox_FastPwm_Block_init_zero;
    std::vector<cbox::obj_field_tag_t> excluded;

    addPersistedStateToMessage(message);

    if (auto val = constrained.setting()) {
        message.setting = cnl::unwrap(*val);
    } else {
        excluded.push_back(blox_FastPwm_Block_setting_tag);
    };
    if (auto val = constrained.desiredSetting()) {
        message.desiredSetting = cnl::unwrap(*val);
    } else {
        excluded.push_back(blox_FastPwm_Block_desiredSetting_tag);
    }
    if (auto val = constrained.value()) {
        message.value = cnl::unwrap(*val);
    } else {
        excluded.push_back(blox_FastPwm_Block_value_tag);
    }
    message.transitionDurationValue = pwm.getTransitionTime();

    getAnalogConstraints(message.constrainedBy, constrained, true);

    return cbox::PayloadBuilder(*this)
        .withContent(&message,
                     blox_FastPwm_Block_fields,
                     blox_FastPwm_Block_size)
        .withMask(cbox::MaskMode::EXCLUSIVE, std::move(excluded))
        .respond(callback)
        .status();
}

cbox::CboxError
FastPwmBlock::readStored(const cbox::PayloadCallback& callback) const
{
    blox_FastPwm_Block message = blox_FastPwm_Block_init_zero;

    addPersistedStateToMessage(message);
    getAnalogConstraints(message.constrainedBy, constrained, false);

    return cbox::PayloadBuilder(*this)
        .withContent(&message,
                     blox_FastPwm_Block_fields,
                     blox_FastPwm_Block_size)
        .respond(callback)
        .status();
}

cbox::CboxError
FastPwmBlock::write(const cbox::Payload& payload)
{
    blox_FastPwm_Block message = blox_FastPwm_Block_init_zero;
    auto parser = cbox::PayloadParser(payload);

    if (parser.fillMessage(&message, blox_FastPwm_Block_fields)) {
        if (parser.hasField(blox_FastPwm_Block_hwDevice_tag)) {
            io.setId(message.hwDevice);
        }
        if (parser.hasField(blox_FastPwm_Block_channel_tag)) {
            pwm.channel(message.channel);
        }
        if (parser.hasField(blox_FastPwm_Block_frequency_tag)) {
            pwm.frequency(IoValue::Setup::Frequency{message.frequency});
        }
        if (parser.hasField(blox_FastPwm_Block_invert_tag)) {
            pwm.invert(message.invert);
        }
        if (parser.hasField(blox_FastPwm_Block_constrainedBy_tag)) {
            setAnalogConstraints(message.constrainedBy, constrained);
        }
        if (parser.hasField(blox_FastPwm_Block_desiredSetting_tag)) {
            constrained.setting(cnl::wrap<ActuatorAnalog::value_t>(message.desiredSetting));
        }
        if (parser.hasField(blox_FastPwm_Block_enabled_tag)) {
            pwm.enabler.set(message.enabled);
        }
        if (parser.hasField(blox_FastPwm_Block_transitionDurationPreset_tag)) {
            transitionDurationPreset = message.transitionDurationPreset;
        }
        if (parser.hasField(blox_FastPwm_Block_transitionDurationSetting_tag)) {
            transitionDurationSetting = message.transitionDurationSetting;
        }
        auto transitionTime = FastPwm::transitionTimeFromPreset(SoftTransitionsPreset{transitionDurationPreset}, transitionDurationSetting);
        pwm.setTransitionTime(transitionTime);
    }

    return parser.status();
}

cbox::update_t
FastPwmBlock::updateHandler(cbox::update_t now)
{
    constrained.update();
    auto nextUpdate = pwm.update(now);
    return nextUpdate;
}

void* FastPwmBlock::implements(cbox::obj_type_t iface)
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
    if (iface == cbox::interfaceId<Enabler>()) {
        Enabler* ptr = &pwm.enabler;
        return ptr;
    }
    return nullptr;
}
