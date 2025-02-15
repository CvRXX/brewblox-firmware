/*
 * Copyright 2018 BrewPi B.V.
 *
 * This file is part of Brewblox
 *
 * Brewblox is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with Brewblox.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "blocks/DisplaySettingsBlock.hpp"
#include "proto/DisplaySettings.pb.h"

cbox::CboxError
DisplaySettingsBlock::read(const cbox::PayloadCallback& callback) const
{
    return callWithMessage(callback,
                           objectId(),
                           staticTypeId(),
                           0,
                           &m_settings,
                           blox_DisplaySettings_Block_fields,
                           blox_DisplaySettings_Block_size);
}

cbox::CboxError
DisplaySettingsBlock::readStored(const cbox::PayloadCallback& callback) const
{
    return read(callback);
}

cbox::CboxError
DisplaySettingsBlock::write(const cbox::Payload& payload)
{
    blox_DisplaySettings_Block message = blox_DisplaySettings_Block_init_zero;
    auto res = payloadToMessage(payload, &message, blox_DisplaySettings_Block_fields);

    if (res == cbox::CboxError::OK) {
        m_settings = message;
        m_newSettingsReceived = true;
    }

    return res;
}

// use global static settings, because we only have one display
blox_DisplaySettings_Block DisplaySettingsBlock::m_settings = blox_DisplaySettings_Block_init_zero;
bool DisplaySettingsBlock::m_newSettingsReceived = false;
