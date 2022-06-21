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

#include "blocks/MutexBlock.hpp"
#include "cbox/PayloadConversion.hpp"
#include "proto/Mutex.pb.h"

cbox::CboxError
MutexBlock::read(const cbox::PayloadCallback& callback) const
{
    blox_Mutex_Block message = blox_Mutex_Block_init_zero;
    message.differentActuatorWait = m_mutex.holdAfterTurnOff();
    message.waitRemaining = m_mutex.timeRemaining();

    return cbox::PayloadBuilder(*this)
        .withContent(&message,
                     blox_Mutex_Block_fields,
                     blox_Mutex_Block_size)
        .respond(callback)
        .status();
}

cbox::CboxError
MutexBlock::readStored(const cbox::PayloadCallback& callback) const
{
    return read(callback);
}

cbox::CboxError
MutexBlock::write(const cbox::Payload& payload)
{
    blox_Mutex_Block message = blox_Mutex_Block_init_zero;
    auto parser = cbox::PayloadParser(payload);

    if (parser.fillMessage(&message, blox_Mutex_Block_fields)) {
        if (parser.hasField(blox_Mutex_Block_differentActuatorWait_tag)) {
            m_mutex.holdAfterTurnOff(message.differentActuatorWait);
        }
    }

    return parser.status();
}

void* MutexBlock::implements(cbox::obj_type_t iface)
{
    if (iface == staticTypeId()) {
        return this; // me!
    }
    if (iface == cbox::interfaceId<MutexTarget>()) {
        // return the member that implements the interface in this case
        MutexTarget* ptr = &m_mutex;
        return ptr;
    }
    return nullptr;
}
