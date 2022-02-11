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

#include "MutexBlock.h"
#include "nanopb_callbacks.h"
#include "proto/Mutex.pb.h"

cbox::CboxError
MutexBlock::streamFrom(cbox::DataIn& dataIn)
{
    blox_Mutex_Block newData = blox_Mutex_Block_init_zero;
    cbox::CboxError result = streamProtoFrom(dataIn, &newData, blox_Mutex_Block_fields, blox_Mutex_Block_size);
    if (result == cbox::CboxError::OK) {
        m_mutex.holdAfterTurnOff(newData.differentActuatorWait);
    }
    return result;
}

cbox::CboxError
MutexBlock::streamTo(cbox::DataOut& out) const
{
    blox_Mutex_Block message = blox_Mutex_Block_init_zero;
    message.differentActuatorWait = m_mutex.holdAfterTurnOff();
    message.waitRemaining = m_mutex.timeRemaining();

    return streamProtoTo(out, &message, blox_Mutex_Block_fields, blox_Mutex_Block_size);
}

void* MutexBlock::implements(const cbox::obj_type_t& iface)
{
    if (iface == brewblox_BlockType_Mutex) {
        return this; // me!
    }
    if (iface == cbox::interfaceId<MutexTarget>()) {
        // return the member that implements the interface in this case
        MutexTarget* ptr = &m_mutex;
        return ptr;
    }
    return nullptr;
}
