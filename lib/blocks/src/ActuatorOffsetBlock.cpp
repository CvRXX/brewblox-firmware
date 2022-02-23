#include "blocks/ActuatorOffsetBlock.h"
#include "blocks/ConstraintsProto.h"
#include "blocks/FieldTags.h"
#include "proto/ActuatorOffset.pb.h"
#include "proto/Constraints.pb.h"

cbox::CboxError
ActuatorOffsetBlock::streamFrom(cbox::DataIn& dataIn)
{
    blox_ActuatorOffset_Block newData = blox_ActuatorOffset_Block_init_zero;
    cbox::CboxError result = streamProtoFrom(dataIn, &newData, blox_ActuatorOffset_Block_fields, blox_ActuatorOffset_Block_size);
    if (result == cbox::CboxError::OK) {
        target.setId(newData.targetId);
        reference.setId(newData.referenceId);
        offset.enabled(newData.enabled);
        offset.selectedReference(ActuatorOffset::ReferenceKind(newData.referenceSettingOrValue));
        setAnalogConstraints(newData.constrainedBy, constrained);
        constrained.setting(cnl::wrap<ActuatorAnalog::value_t>(newData.desiredSetting));
    }
    return result;
}

cbox::CboxError
ActuatorOffsetBlock::streamTo(cbox::DataOut& out) const
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

    return streamProtoTo(out, &message, blox_ActuatorOffset_Block_fields, blox_ActuatorOffset_Block_size);
}

cbox::CboxError
ActuatorOffsetBlock::streamPersistedTo(cbox::DataOut& out) const
{
    blox_ActuatorOffset_Block persisted = blox_ActuatorOffset_Block_init_zero;

    persisted.targetId = target.getId();
    persisted.referenceId = reference.getId();
    persisted.referenceSettingOrValue = _blox_ActuatorOffset_ReferenceKind(offset.selectedReference());
    persisted.enabled = offset.enabled();
    persisted.desiredSetting = cnl::unwrap(constrained.desiredSetting());
    getAnalogConstraints(persisted.constrainedBy, constrained);

    return streamProtoTo(out, &persisted, blox_ActuatorOffset_Block_fields, blox_ActuatorOffset_Block_size);
}

cbox::update_t
ActuatorOffsetBlock::update(const cbox::update_t& now)
{
    offset.update();
    constrained.update();
    return now + 1000;
}

void* ActuatorOffsetBlock::implements(const cbox::obj_type_t& iface)
{
    if (iface == brewblox_BlockType_ActuatorOffset) {
        return this; // me!
    }
    if (iface == cbox::interfaceId<ActuatorAnalogConstrained>()) {
        // return the member that implements the interface in this case
        ActuatorAnalogConstrained* ptr = &constrained;
        return ptr;
    }
    return nullptr;
}
