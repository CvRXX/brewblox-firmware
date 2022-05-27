/*
 * Copyright 2020 BrewPi B.V.
 *
 * This file is part of Brewblox.
 *
 * Brewblox is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * Brewblox is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with Brewblox.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "blocks/MotorValveBlock.hpp"
#include "blocks/ConstraintsProto.hpp"
#include "blocks/FieldTags.hpp"

void MotorValveBlock::addPersistedStateToMessage(blox_MotorValve_Block& message) const
{
    message.desiredState = blox_IoArray_DigitalState(constrained.desiredState());
    message.hwDevice = hwDevice.getId();
    message.startChannel = valve.startChannel();
    getDigitalConstraints(message.constrainedBy, constrained);
}

cbox::CboxError
MotorValveBlock::read(const cbox::PayloadCallback& callback) const
{
    blox_MotorValve_Block message = blox_MotorValve_Block_init_zero;
    FieldTags stripped;

    addPersistedStateToMessage(message);

    auto state = valve.state();
    if (state == ActuatorDigitalBase::State::Unknown) {
        stripped.add(blox_MotorValve_Block_state_tag);
    } else {
        message.state = blox_IoArray_DigitalState(valve.state());
    }
    auto valveState = valve.valveState();
    if (valveState == MotorValve::ValveState::Unknown) {
        stripped.add(blox_MotorValve_Block_valveState_tag);
    } else {
        message.valveState = blox_MotorValve_ValveState(valve.valveState());
    }

    stripped.copyToMessage(message.strippedFields, message.strippedFields_count, 1);

    return callWithMessage(callback,
                           objectId(),
                           staticTypeId(),
                           0,
                           &message,
                           blox_MotorValve_Block_fields,
                           blox_MotorValve_Block_size);
}

cbox::CboxError
MotorValveBlock::readStored(const cbox::PayloadCallback& callback) const
{
    blox_MotorValve_Block message = blox_MotorValve_Block_init_zero;
    addPersistedStateToMessage(message);

    return callWithMessage(callback,
                           objectId(),
                           staticTypeId(),
                           0,
                           &message,
                           blox_MotorValve_Block_fields,
                           blox_MotorValve_Block_size);
}

cbox::CboxError
MotorValveBlock::write(const cbox::Payload& payload)
{
    blox_MotorValve_Block message = blox_MotorValve_Block_init_zero;
    auto res = payloadToMessage(payload, &message, blox_MotorValve_Block_fields);

    if (res == cbox::CboxError::OK) {
        if (hwDevice.getId() != message.hwDevice) {
            valve.startChannel(0); // unregister at old hwDevice
            hwDevice.setId(message.hwDevice);
        }
        valve.startChannel(message.startChannel);
        setDigitalConstraints(message.constrainedBy, constrained);
        constrained.desiredState(ActuatorDigitalBase::State(message.desiredState));
    }

    return res;
}

cbox::update_t
MotorValveBlock::updateHandler(const cbox::update_t& now)
{
    valve.update();
    return constrained.update(now);
}

void* MotorValveBlock::implements(cbox::obj_type_t iface)
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
