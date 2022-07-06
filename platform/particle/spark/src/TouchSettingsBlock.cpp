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

#include "spark/TouchSettingsBlock.hpp"
#include "cbox/PayloadConversion.hpp"
#include "d4d_display/d4d.hpp"
#include "proto/TouchSettings.pb.h"
#include <cstring>

namespace platform::particle {

cbox::CboxError TouchSettingsBlock::read(const cbox::PayloadCallback& callback) const
{
    blox_TouchSettings_Block message = blox_TouchSettings_Block_init_zero;

    auto calib = D4D_TCH_GetCalibration();

    message.calibrated = blox_TouchSettings_Calibrated(calib.ScreenCalibrated);
    message.xOffset = calib.TouchScreenXoffset;
    message.yOffset = calib.TouchScreenYoffset;
    message.xBitsPerPixelX16 = calib.TouchScreenXBitsPerPixelx16;
    message.yBitsPerPixelX16 = calib.TouchScreenYBitsPerPixelx16;

    return cbox::PayloadBuilder(*this)
        .withContent(&message,
                     blox_TouchSettings_Block_fields,
                     blox_TouchSettings_Block_size)
        .respond(callback)
        .status();
}

cbox::CboxError TouchSettingsBlock::readStored(const cbox::PayloadCallback& callback) const
{
    return read(callback);
}

cbox::CboxError TouchSettingsBlock::write(const cbox::Payload& payload)
{
    blox_TouchSettings_Block message = blox_TouchSettings_Block_init_zero;
    auto parser = cbox::PayloadParser(payload);

    if (parser.fillMessage(&message, blox_TouchSettings_Block_fields)) {
        if (parser.hasField(blox_TouchSettings_Block_calibrated_tag)
            && message.calibrated == blox_TouchSettings_Calibrated_CALIBRATED_NEW) {
            auto calib = D4D_GetTouchScreenCalibration();
            calib.ScreenCalibrated = 1;
            if (parser.hasField(blox_TouchSettings_Block_xOffset_tag)) {
                calib.TouchScreenXoffset = message.xOffset;
            }
            if (parser.hasField(blox_TouchSettings_Block_yOffset_tag)) {
                calib.TouchScreenYoffset = message.yOffset;
            }
            if (parser.hasField(blox_TouchSettings_Block_xBitsPerPixelX16_tag)) {
                calib.TouchScreenXBitsPerPixelx16 = message.xBitsPerPixelX16;
            }
            if (parser.hasField(blox_TouchSettings_Block_yBitsPerPixelX16_tag)) {
                calib.TouchScreenYBitsPerPixelx16 = message.yBitsPerPixelX16;
            }
            D4D_TCH_SetCalibration(calib);
        }
    }

    return parser.status();
}
} // end namespace platform::particle
