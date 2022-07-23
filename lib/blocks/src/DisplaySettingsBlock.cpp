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
#include "cbox/PayloadConversion.hpp"
#include "proto/DisplaySettings.pb.h"

cbox::CboxError
DisplaySettingsBlock::read(const cbox::PayloadCallback& callback) const
{
    return cbox::PayloadBuilder(*this)
        .withContent(&m_settings,
                     blox_DisplaySettings_Block_fields,
                     blox_DisplaySettings_Block_size)
        .respond(callback)
        .status();
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
    auto parser = cbox::PayloadParser(payload);

    if (parser.fillMessage(&message, blox_DisplaySettings_Block_fields)) {
        if (parser.hasField(blox_DisplaySettings_Block_widgets_tag)) {
            for (auto i = 0; i < message.widgets_count; i++) {
                blox_DisplaySettings_Widget widget = message.widgets[i];
                m_settings.widgets[i] = widget;
            }
            for (auto i = message.widgets_count; i < 6; i++) {
                blox_DisplaySettings_Widget widget = blox_DisplaySettings_Widget_init_zero;
                m_settings.widgets[i] = widget;
            }
        }
        if (parser.hasField(blox_DisplaySettings_Block_name_tag)) {
            std::copy(std::begin(message.name), std::end(message.name), std::begin(m_settings.name));
        }
        if (parser.hasField(blox_DisplaySettings_Block_tempUnit_tag)) {
            m_settings.tempUnit = message.tempUnit;
        }
        if (parser.hasField(blox_DisplaySettings_Block_brightness_tag)) {
            m_settings.brightness = message.brightness;
        }
        if (parser.hasField(blox_DisplaySettings_Block_timeZone_tag)) {
            std::copy(std::begin(message.timeZone), std::end(message.timeZone), std::begin(m_settings.timeZone));
        }
        m_newSettingsReceived = true;
    }

    return parser.status();
}

// use global static settings, because we only have one display
blox_DisplaySettings_Block DisplaySettingsBlock::m_settings = blox_DisplaySettings_Block_init_zero;
bool DisplaySettingsBlock::m_newSettingsReceived = false;
