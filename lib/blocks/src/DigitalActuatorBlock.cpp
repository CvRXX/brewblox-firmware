#include "blocks/DigitalActuatorBlock.hpp"
#include "blocks/ConstraintsProto.hpp"
#include "blocks/FieldTags.hpp"

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
    FieldTags stripped;

    addPersistedStateToMessage(message);
    auto state = actuator.state();
    if (state == ActuatorDigitalBase::State::Unknown) {
        stripped.add(blox_DigitalActuator_Block_state_tag);
    } else {
        message.state = blox_IoArray_DigitalState(actuator.state());
    }

    stripped.copyToMessage(message.strippedFields, message.strippedFields_count, 1);

    return callWithMessage(callback,
                           objectId(),
                           staticTypeId(),
                           0,
                           &message,
                           blox_DigitalActuator_Block_fields,
                           blox_DigitalActuator_Block_size);
}

cbox::CboxError
DigitalActuatorBlock::readStored(const cbox::PayloadCallback& callback) const
{
    blox_DigitalActuator_Block message = blox_DigitalActuator_Block_init_zero;

    addPersistedStateToMessage(message);

    return callWithMessage(callback,
                           objectId(),
                           staticTypeId(),
                           0,
                           &message,
                           blox_DigitalActuator_Block_fields,
                           blox_DigitalActuator_Block_size);
}

cbox::CboxError
DigitalActuatorBlock::write(const cbox::Payload& payload)
{
    blox_DigitalActuator_Block message = blox_DigitalActuator_Block_init_zero;
    auto res = payloadToMessage(payload, &message, blox_DigitalActuator_Block_fields);

    if (res == cbox::CboxError::OK) {
        if (hwDevice.getId() != message.hwDevice) {
            actuator.channel(0); // unregister at old hwDevice
            hwDevice.setId(message.hwDevice);
        }
        actuator.channel(message.channel);
        actuator.invert(message.invert);
        setDigitalConstraints(message.constrainedBy, constrained);
        constrained.desiredState(ActuatorDigitalBase::State(message.desiredState));
    }

    return res;
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
