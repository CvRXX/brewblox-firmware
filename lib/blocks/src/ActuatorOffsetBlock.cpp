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
    message.enabled = offset.enabler.get();

    if (auto val = constrained.value()) {
        message.value = cnl::unwrap(*val);
    } else {
        excluded.push_back(blox_ActuatorOffset_Block_value_tag);
    }
    if (auto val = constrained.setting()) {
        message.setting = cnl::unwrap(*val);
    } else {
        excluded.push_back(blox_ActuatorOffset_Block_setting_tag);
    };

    if (auto val = constrained.desiredSetting()) {
        message.desiredSetting = cnl::unwrap(*val);
    } else {
        excluded.push_back(blox_ActuatorOffset_Block_desiredSetting_tag);
    }
    message.claimedBy = claim.claimedBy();

    getAnalogConstraints(message.constrainedBy, constrained, true);

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
    message.enabled = offset.enabler.get();
    // default setting to 0 if it is invalid no not have to store excluded field in eeprom
    message.desiredSetting = cnl::unwrap(constrained.desiredSetting().value_or(0));
    getAnalogConstraints(message.constrainedBy, constrained, false);

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
            target.setId(message.targetId, objectId());
        }
        if (parser.hasField(blox_ActuatorOffset_Block_referenceId_tag)) {
            reference.setId(message.referenceId);
        }
        if (parser.hasField(blox_ActuatorOffset_Block_enabled_tag)) {
            offset.enabler.set(message.enabled);
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
ActuatorOffsetBlock::updateHandler(cbox::update_t now)
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
    if (iface == cbox::interfaceId<cbox::Claimable>()) {
        cbox::Claimable* ptr = &claim;
        return ptr;
    }
    if (iface == cbox::interfaceId<ActuatorAnalogConstrained>()) {
        // return the member that implements the interface in this case
        ActuatorAnalogConstrained* ptr = &constrained;
        return ptr;
    }
    return nullptr;
}
