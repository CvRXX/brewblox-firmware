#include "blocks/ActuatorAnalogMockBlock.hpp"
#include "blocks/ConstraintsProto.hpp"
#include "cbox/PayloadConversion.hpp"
#include "control/ActuatorAnalogConstrained.hpp"
#include "proto/ActuatorAnalogMock.pb.h"

cbox::CboxError ActuatorAnalogMockBlock::read(const cbox::PayloadCallback& callback) const
{
    blox_ActuatorAnalogMock_Block message = blox_ActuatorAnalogMock_Block_init_zero;
    std::vector<cbox::obj_field_tag_t> excluded;

    if (auto val = constrained.value()) {
        message.value = cnl::unwrap(*val);
    } else {
        excluded.push_back(blox_ActuatorAnalogMock_Block_value_tag);
    }
    if (auto val = constrained.setting()) {
        message.setting = cnl::unwrap(*val);
    } else {
        excluded.push_back(blox_ActuatorAnalogMock_Block_setting_tag);
    };
    if (auto val = constrained.desiredSetting()) {
        message.desiredSetting = cnl::unwrap(*val);
    } else {
        excluded.push_back(blox_ActuatorAnalogMock_Block_desiredSetting_tag);
    }

    message.minSetting = cnl::unwrap(actuator.minSetting());
    message.maxSetting = cnl::unwrap(actuator.maxSetting());
    message.minValue = cnl::unwrap(actuator.minValue());
    message.maxValue = cnl::unwrap(actuator.maxValue());

    getAnalogConstraints(message.constrainedBy, constrained, true);

    return cbox::PayloadBuilder(*this)
        .withContent(&message,
                     blox_ActuatorAnalogMock_Block_fields,
                     blox_ActuatorAnalogMock_Block_size)
        .withMask(cbox::MaskMode::EXCLUSIVE, std::move(excluded))
        .respond(callback)
        .status();
}

cbox::CboxError ActuatorAnalogMockBlock::readStored(const cbox::PayloadCallback& callback) const
{
    blox_ActuatorAnalogMock_Block message = blox_ActuatorAnalogMock_Block_init_zero;

    // default setting to 0 if it is invalid no not have to store excluded field in eeprom
    message.desiredSetting = cnl::unwrap(constrained.desiredSetting().value_or(0));
    message.minSetting = cnl::unwrap(actuator.minSetting());
    message.maxSetting = cnl::unwrap(actuator.maxSetting());
    message.minValue = cnl::unwrap(actuator.minValue());
    message.maxValue = cnl::unwrap(actuator.maxValue());

    getAnalogConstraints(message.constrainedBy, constrained, false);

    return cbox::PayloadBuilder(*this)
        .withContent(&message,
                     blox_ActuatorAnalogMock_Block_fields,
                     blox_ActuatorAnalogMock_Block_size)
        .respond(callback)
        .status();
}

cbox::CboxError ActuatorAnalogMockBlock::write(const cbox::Payload& payload)
{
    blox_ActuatorAnalogMock_Block message = blox_ActuatorAnalogMock_Block_init_zero;
    auto parser = cbox::PayloadParser(payload);

    if (parser.fillMessage(&message, blox_ActuatorAnalogMock_Block_fields)) {
        if (parser.hasField(blox_ActuatorAnalogMock_Block_minSetting_tag)) {
            actuator.minSetting(cnl::wrap<ActuatorAnalog::value_t>(message.minSetting));
        }
        if (parser.hasField(blox_ActuatorAnalogMock_Block_maxSetting_tag)) {
            actuator.maxSetting(cnl::wrap<ActuatorAnalog::value_t>(message.maxSetting));
        }
        if (parser.hasField(blox_ActuatorAnalogMock_Block_minValue_tag)) {
            actuator.minValue(cnl::wrap<ActuatorAnalog::value_t>(message.minValue));
        }
        if (parser.hasField(blox_ActuatorAnalogMock_Block_maxValue_tag)) {
            actuator.maxValue(cnl::wrap<ActuatorAnalog::value_t>(message.maxValue));
        }
        if (parser.hasField(blox_ActuatorAnalogMock_Block_constrainedBy_tag)) {
            setAnalogConstraints(message.constrainedBy, constrained);
        }
        if (parser.hasField(blox_ActuatorAnalogMock_Block_desiredSetting_tag)) {
            constrained.setting(cnl::wrap<ActuatorAnalog::value_t>(message.desiredSetting));
        }
    }

    return parser.status();
}

void* ActuatorAnalogMockBlock::implements(cbox::obj_type_t iface)
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
        ProcessValue<ActuatorAnalog::value_t>* ptr = &actuator;
        return ptr;
    }
    return nullptr;
}
