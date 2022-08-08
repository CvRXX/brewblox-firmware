#include "blocks/DigitalActuatorBlock.hpp"
#include "blocks/ConstraintsProto.hpp"
#include "cbox/PayloadConversion.hpp"
#include <algorithm>

void DigitalActuatorBlock::addPersistedStateToMessage(blox_DigitalActuator_Block& message) const
{
    message.hwDevice = actuator.hwDevice.getId();
    if (auto pAct = std::get_if<ActuatorDigitalSoft>(&actuator.act)) {
        message.channel = pAct->channel();
        message.invert = pAct->invert();

    } else if (auto pAct = std::get_if<ActuatorDigital>(&actuator.act)) {
        message.channel = pAct->channel();
        message.invert = pAct->invert();
    }
    message.desiredState = blox_IoArray_DigitalState(constrained.desiredState());
    message.transitionDurationSetting = transitionDurationSetting;
    message.transitionDurationPreset = transitionDurationPreset;
}

cbox::CboxError
DigitalActuatorBlock::read(const cbox::PayloadCallback& callback) const
{
    blox_DigitalActuator_Block message = blox_DigitalActuator_Block_init_zero;
    std::vector<cbox::obj_field_tag_t> excluded;

    addPersistedStateToMessage(message);
    getDigitalConstraints(message.constrainedBy, constrained, true);

    auto state = actuator.state();
    if (state == ActuatorDigitalBase::State::Unknown) {
        excluded.push_back(blox_DigitalActuator_Block_state_tag);
    } else {
        message.state = blox_IoArray_DigitalState(actuator.state());
    }

    if (auto duration = actuator.transitionDuration()) {
        message.transitionDurationValue = *duration;
    } else {
        excluded.push_back(blox_DigitalActuator_Block_transitionDurationValue_tag);
    }

    return cbox::PayloadBuilder(*this)
        .withContent(&message,
                     blox_DigitalActuator_Block_fields,
                     blox_DigitalActuator_Block_size)
        .withMask(cbox::MaskMode::EXCLUSIVE, std::move(excluded))
        .respond(callback)
        .status();
}

cbox::CboxError
DigitalActuatorBlock::readStored(const cbox::PayloadCallback& callback) const
{
    blox_DigitalActuator_Block message = blox_DigitalActuator_Block_init_zero;

    addPersistedStateToMessage(message);
    getDigitalConstraints(message.constrainedBy, constrained, false);

    return cbox::PayloadBuilder(*this)
        .withContent(&message,
                     blox_DigitalActuator_Block_fields,
                     blox_DigitalActuator_Block_size)
        .respond(callback)
        .status();
}

cbox::CboxError
DigitalActuatorBlock::write(const cbox::Payload& payload)
{
    blox_DigitalActuator_Block message = blox_DigitalActuator_Block_init_zero;
    auto parser = cbox::PayloadParser(payload);

    if (parser.fillMessage(&message, blox_DigitalActuator_Block_fields)) {
        if (parser.hasField(blox_DigitalActuator_Block_hwDevice_tag)) {
            actuator.hwDevice.setId(message.hwDevice);
        }
        if (parser.hasField(blox_DigitalActuator_Block_channel_tag)) {
            if (auto pAct = std::get_if<ActuatorDigitalSoft>(&actuator.act)) {
                pAct->channel(message.channel);
            } else if (auto pAct = std::get_if<ActuatorDigital>(&actuator.act)) {
                pAct->channel(message.channel);
            }
        }
        if (parser.hasField(blox_DigitalActuator_Block_transitionDurationPreset_tag)) {
            transitionDurationPreset = message.transitionDurationPreset;
        }
        if (parser.hasField(blox_DigitalActuator_Block_transitionDurationSetting_tag)) {
            transitionDurationSetting = message.transitionDurationSetting;
        }
        if (parser.hasField(blox_DigitalActuator_Block_invert_tag)) {
            actuator.invert(message.invert);
        }
        if (parser.hasField(blox_DigitalActuator_Block_constrainedBy_tag)) {
            setDigitalConstraints(message.constrainedBy, constrained);
        }
        if (parser.hasField(blox_DigitalActuator_Block_desiredState_tag)) {
            constrained.desiredState(ActuatorDigitalBase::State(message.desiredState));
        }
    }

    return parser.status();
}

cbox::update_t
DigitalActuatorBlock::updateHandler(cbox::update_t now)
{
    auto transitionTime = FastPwm::transitionTimeFromPreset(SoftTransitionsPreset{transitionDurationPreset}, transitionDurationSetting);
    bool useSoft = transitionTime != 0 && actuator.transitionDuration().has_value();
    bool isSoft = std::holds_alternative<ActuatorDigitalSoft>(actuator.act);

    if (useSoft != isSoft) {
        actuator.swapImplementation();
    }

    if (auto pAct = std::get_if<ActuatorDigital>(&actuator.act)) {
        auto nextUpdate = constrained.update(now);
        pAct->update();
        return nextUpdate;
    } else if (auto pAct = std::get_if<ActuatorDigitalSoft>(&actuator.act)) {
        pAct->setTransitionTime(transitionTime);
        return std::min(pAct->update(now), constrained.update(now));
    }

    return now + 1000;
}

void* DigitalActuatorBlock::implements(cbox::obj_type_t iface)
{
    if (iface == staticTypeId()) {
        return this; // me!
    }
    if (iface == cbox::interfaceId<ActuatorDigitalConstrained>()) {
        // return the member that implements the interface in this case
        ActuatorDigitalConstrained* ptr = &constrained;
        return ptr;
    }
    return nullptr;
}
