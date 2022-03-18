/*
 * Copyright 2018 BrewPi B.V.
 *
 * This file is part of Brewblox
 *
 * Controlbox is free software: you can redistribute it and/or modify
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
 * along with Brewblox. If not, see <http://www.gnu.org/licenses/>.
 */

#include "spark/TouchSettingsBlock.h"
#include "d4d_display/d4d.hpp"
#include "proto/TouchSettings.pb.h"
#include <cstring>

cbox::CboxError TouchSettingsBlock::read(const cbox::PayloadCallback& callback) const
{
    blox_TouchSettings_Block message = blox_TouchSettings_Block_init_zero;

    auto calib = D4D_TCH_GetCalibration();

    message.calibrated = blox_TouchSettings_Calibrated(calib.ScreenCalibrated);
    message.xOffset = calib.TouchScreenXoffset;
    message.yOffset = calib.TouchScreenYoffset;
    message.xBitsPerPixelX16 = calib.TouchScreenXBitsPerPixelx16;
    message.yBitsPerPixelX16 = calib.TouchScreenYBitsPerPixelx16;

    return callWithMessage(callback,
                           objectId,
                           staticTypeId(),
                           0,
                           &message,
                           blox_TouchSettings_Block_fields,
                           blox_TouchSettings_Block_size);
}

cbox::CboxError TouchSettingsBlock::readStored(const cbox::PayloadCallback& callback) const
{
    return read(callback);
}

cbox::CboxError TouchSettingsBlock::write(const cbox::Payload& payload)
{
    blox_TouchSettings_Block message = blox_TouchSettings_Block_init_zero;
    auto res = payloadToMessage(payload, &message, blox_TouchSettings_Block_fields);

    if (res == cbox::CboxError::OK) {
        auto calib = D4D_GetTouchScreenCalibration();
        if (message.calibrated == blox_TouchSettings_Calibrated_CALIBRATED_NEW || calib.ScreenCalibrated == 0) {
            calib.ScreenCalibrated = 1;
            calib.TouchScreenXoffset = message.xOffset;
            calib.TouchScreenYoffset = message.yOffset;
            calib.TouchScreenXBitsPerPixelx16 = message.xBitsPerPixelX16;
            calib.TouchScreenYBitsPerPixelx16 = message.yBitsPerPixelX16;
            D4D_TCH_SetCalibration(calib);
        }
    }

    return res;
}
