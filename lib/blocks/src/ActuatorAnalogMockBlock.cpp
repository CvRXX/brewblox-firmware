#include "blocks/ActuatorAnalogMockBlock.h"
#include "blocks/ConstraintsProto.h"
#include "blocks/FieldTags.h"
#include "control/ActuatorAnalogConstrained.h"
#include "proto/ActuatorAnalogMock.pb.h"

cbox::CboxError ActuatorAnalogMockBlock::read(const cbox::PayloadCallback& callback) const
{
    blox_ActuatorAnalogMock_Block message = blox_ActuatorAnalogMock_Block_init_zero;
    FieldTags stripped;

    if (constrained.valueValid()) {
        message.value = cnl::unwrap(constrained.value());
    } else {
        stripped.add(blox_ActuatorAnalogMock_Block_value_tag);
    }
    if (constrained.settingValid()) {
        message.setting = cnl::unwrap(constrained.setting());
    } else {
        stripped.add(blox_ActuatorAnalogMock_Block_setting_tag);
    };

    message.desiredSetting = cnl::unwrap(constrained.desiredSetting());
    message.minSetting = cnl::unwrap(actuator.minSetting());
    message.maxSetting = cnl::unwrap(actuator.maxSetting());
    message.minValue = cnl::unwrap(actuator.minValue());
    message.maxValue = cnl::unwrap(actuator.maxValue());

    getAnalogConstraints(message.constrainedBy, constrained);

    return callWithMessage(callback,
                           objectId,
                           staticTypeId(),
                           0,
                           &message,
                           blox_ActuatorAnalogMock_Block_fields,
                           blox_ActuatorAnalogMock_Block_size);
}

cbox::CboxError ActuatorAnalogMockBlock::readStored(const cbox::PayloadCallback& callback) const
{
    blox_ActuatorAnalogMock_Block message = blox_ActuatorAnalogMock_Block_init_zero;

    message.desiredSetting = cnl::unwrap(constrained.desiredSetting());
    message.minSetting = cnl::unwrap(actuator.minSetting());
    message.maxSetting = cnl::unwrap(actuator.maxSetting());
    message.minValue = cnl::unwrap(actuator.minValue());
    message.maxValue = cnl::unwrap(actuator.maxValue());

    getAnalogConstraints(message.constrainedBy, constrained);

    return callWithMessage(callback,
                           objectId,
                           staticTypeId(),
                           0,
                           &message,
                           blox_ActuatorAnalogMock_Block_fields,
                           blox_ActuatorAnalogMock_Block_size);
}

cbox::CboxError ActuatorAnalogMockBlock::write(const cbox::Payload& payload)
{
    blox_ActuatorAnalogMock_Block message = blox_ActuatorAnalogMock_Block_init_zero;
    auto res = payloadToMessage(payload, &message, blox_ActuatorAnalogMock_Block_fields);

    if (res == cbox::CboxError::OK) {
        actuator.minSetting(cnl::wrap<ActuatorAnalog::value_t>(message.minSetting));
        actuator.maxSetting(cnl::wrap<ActuatorAnalog::value_t>(message.maxSetting));
        actuator.minValue(cnl::wrap<ActuatorAnalog::value_t>(message.minValue));
        actuator.maxValue(cnl::wrap<ActuatorAnalog::value_t>(message.maxValue));
        setAnalogConstraints(message.constrainedBy, constrained);
        constrained.setting(cnl::wrap<ActuatorAnalog::value_t>(message.desiredSetting));
    }

    return res;
}

void* ActuatorAnalogMockBlock::implements(cbox::obj_type_t iface)
{
    if (iface == brewblox_BlockType_ActuatorAnalogMock) {
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
