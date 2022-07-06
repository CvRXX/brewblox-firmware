#include "blocks/DigitalActuatorBlock.hpp"
#include "blocks/ConstraintsProto.hpp"
#include "cbox/PayloadConversion.hpp"

void DigitalActuatorBlock::addPersistedStateToMessage(blox_DigitalActuator_Block& message) const
{
    message.hwDevice = hwDevice.getId();
    message.channel = actuator.channel();
    message.invert = actuator.invert();
    message.desiredState = blox_IoArray_DigitalState(constrained.desiredState());

    getDigitalConstraints(message.constrainedBy, constrained);
}

cbox::CboxError
DigitalActuatorBlock::read(const cbox::PayloadCallback& callback) const
{
    blox_DigitalActuator_Block message = blox_DigitalActuator_Block_init_zero;
    std::vector<cbox::obj_field_tag_t> excluded;

    addPersistedStateToMessage(message);
    auto state = actuator.state();
    if (state == ActuatorDigitalBase::State::Unknown) {
        excluded.push_back(blox_DigitalActuator_Block_state_tag);
    } else {
        message.state = blox_IoArray_DigitalState(actuator.state());
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
            if (hwDevice.getId() != message.hwDevice) {
                actuator.channel(0); // unregister at old hwDevice
                hwDevice.setId(message.hwDevice);
            }
        }
        if (parser.hasField(blox_DigitalActuator_Block_channel_tag)) {
            actuator.channel(message.channel);
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
DigitalActuatorBlock::updateHandler(const cbox::update_t& now)
{
    actuator.update();
    return constrained.update(now);
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
