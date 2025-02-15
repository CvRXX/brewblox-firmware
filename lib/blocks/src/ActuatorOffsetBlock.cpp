#include "blocks/ActuatorOffsetBlock.hpp"
#include "blocks/ConstraintsProto.hpp"
#include "blocks/FieldTags.hpp"
#include "proto/ActuatorOffset.pb.h"
#include "proto/Constraints.pb.h"

cbox::CboxError ActuatorOffsetBlock::read(const cbox::PayloadCallback& callback) const
{
    blox_ActuatorOffset_Block message = blox_ActuatorOffset_Block_init_zero;
    FieldTags stripped;

    message.targetId = target.getId();
    message.referenceId = reference.getId();
    message.referenceSettingOrValue = blox_ActuatorOffset_ReferenceKind(offset.selectedReference());
    message.enabled = offset.enabled();

    if (constrained.valueValid()) {
        message.value = cnl::unwrap(constrained.value());
    } else {
        stripped.add(blox_ActuatorOffset_Block_value_tag);
    }
    if (constrained.settingValid()) {
        message.setting = cnl::unwrap(constrained.setting());
        if (offset.enabled()) {
            message.drivenTargetId = message.targetId;
        }
    } else {
        stripped.add(blox_ActuatorOffset_Block_setting_tag);
    };
    message.desiredSetting = cnl::unwrap(constrained.desiredSetting());

    getAnalogConstraints(message.constrainedBy, constrained);

    stripped.copyToMessage(message.strippedFields, message.strippedFields_count, 2);

    return callWithMessage(callback,
                           objectId(),
                           staticTypeId(),
                           0,
                           &message,
                           blox_ActuatorOffset_Block_fields,
                           blox_ActuatorOffset_Block_size);
}

cbox::CboxError ActuatorOffsetBlock::readStored(const cbox::PayloadCallback& callback) const
{
    blox_ActuatorOffset_Block message = blox_ActuatorOffset_Block_init_zero;

    message.targetId = target.getId();
    message.referenceId = reference.getId();
    message.referenceSettingOrValue = _blox_ActuatorOffset_ReferenceKind(offset.selectedReference());
    message.enabled = offset.enabled();
    message.desiredSetting = cnl::unwrap(constrained.desiredSetting());
    getAnalogConstraints(message.constrainedBy, constrained);

    return callWithMessage(callback,
                           objectId(),
                           staticTypeId(),
                           0,
                           &message,
                           blox_ActuatorOffset_Block_fields,
                           blox_ActuatorOffset_Block_size);
}

cbox::CboxError ActuatorOffsetBlock::write(const cbox::Payload& payload)
{
    blox_ActuatorOffset_Block message = blox_ActuatorOffset_Block_init_zero;
    auto res = payloadToMessage(payload, &message, blox_ActuatorOffset_Block_fields);

    if (res == cbox::CboxError::OK) {
        target.setId(message.targetId);
        reference.setId(message.referenceId);
        offset.enabled(message.enabled);
        offset.selectedReference(ActuatorOffset::ReferenceKind(message.referenceSettingOrValue));
        setAnalogConstraints(message.constrainedBy, constrained);
        constrained.setting(cnl::wrap<ActuatorAnalog::value_t>(message.desiredSetting));
    }

    return res;
}

cbox::update_t
ActuatorOffsetBlock::updateHandler(const cbox::update_t& now)
{
    offset.update();
    constrained.update();
    return now + 1000;
}

void* ActuatorOffsetBlock::implements(cbox::obj_type_t iface)
{
    if (iface == staticTypeId()) {
        return this; // me!
    }
    if (iface == cbox::interfaceId<ActuatorAnalogConstrained>()) {
        // return the member that implements the interface in this case
        ActuatorAnalogConstrained* ptr = &constrained;
        return ptr;
    }
    return nullptr;
}
