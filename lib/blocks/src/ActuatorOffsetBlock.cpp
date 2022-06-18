#include "blocks/ActuatorOffsetBlock.hpp"
#include "blocks/ConstraintsProto.hpp"
#include "cbox/PayloadConversion.hpp"
#include "proto/ActuatorOffset.pb.h"
#include "proto/Constraints.pb.h"

cbox::CboxError ActuatorOffsetBlock::read(const cbox::PayloadCallback& callback) const
{
    blox_ActuatorOffset_Block message = blox_ActuatorOffset_Block_init_zero;
    std::vector<cbox::obj_field_tag_t> excluded;

    message.targetId = target.getId();
    message.referenceId = reference.getId();
    message.referenceSettingOrValue = blox_ActuatorOffset_ReferenceKind(offset.selectedReference());
    message.enabled = offset.enabled();

    if (constrained.valueValid()) {
        message.value = cnl::unwrap(constrained.value());
    } else {
        excluded.push_back(blox_ActuatorOffset_Block_value_tag);
    }
    if (constrained.settingValid()) {
        message.setting = cnl::unwrap(constrained.setting());
        if (offset.enabled()) {
            message.drivenTargetId = message.targetId;
        }
    } else {
        excluded.push_back(blox_ActuatorOffset_Block_setting_tag);
    };
    message.desiredSetting = cnl::unwrap(constrained.desiredSetting());

    getAnalogConstraints(message.constrainedBy, constrained);

    return cbox::PayloadBuilder(*this)
        .withContent(&message,
                     blox_ActuatorOffset_Block_fields,
                     blox_ActuatorOffset_Block_size)
        .withMask(cbox::MaskMode::EXCLUSIVE, std::move(excluded))
        .respond(callback)
        .status();
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

    return cbox::PayloadBuilder(*this)
        .withContent(&message,
                     blox_ActuatorOffset_Block_fields,
                     blox_ActuatorOffset_Block_size)
        .respond(callback)
        .status();
}

cbox::CboxError ActuatorOffsetBlock::write(const cbox::Payload& payload)
{
    blox_ActuatorOffset_Block message = blox_ActuatorOffset_Block_init_zero;
    auto parser = cbox::PayloadParser(payload);

    if (parser.fillMessage(&message, blox_ActuatorOffset_Block_fields)) {
        if (parser.hasField(blox_ActuatorOffset_Block_targetId_tag)) {
            target.setId(message.targetId);
        }
        if (parser.hasField(blox_ActuatorOffset_Block_referenceId_tag)) {
            reference.setId(message.referenceId);
        }
        if (parser.hasField(blox_ActuatorOffset_Block_enabled_tag)) {
            offset.enabled(message.enabled);
        }
        if (parser.hasField(blox_ActuatorOffset_Block_referenceSettingOrValue_tag)) {
            offset.selectedReference(ActuatorOffset::ReferenceKind(message.referenceSettingOrValue));
        }
        if (parser.hasField(blox_ActuatorOffset_Block_constrainedBy_tag)) {
            setAnalogConstraints(message.constrainedBy, constrained);
        }
        if (parser.hasField(blox_ActuatorOffset_Block_desiredSetting_tag)) {
            constrained.setting(cnl::wrap<ActuatorAnalog::value_t>(message.desiredSetting));
        }
    }

    return parser.status();
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
