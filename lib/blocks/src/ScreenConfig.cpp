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

#include "blocks/ScreenConfig.hpp"

cbox::CboxError
ScreenConfig::read(const cbox::PayloadCallback& callback) const
{
    const size_t size = screen_ContentNode_size * 10 + screen_LayoutNode_size * 10 + 100;

    decodedScreenConfig.settings.layoutNodes.funcs.encode = gui::dynamic_interface::detail::layoutNodeEncoder;
    decodedScreenConfig.settings.layoutNodes.arg = reinterpret_cast<void*>(&(decodedScreenConfig.layoutNodes));

    decodedScreenConfig.settings.contentNodes.funcs.encode = gui::dynamic_interface::detail::contentNodeEncoder;
    decodedScreenConfig.settings.contentNodes.arg = reinterpret_cast<void*>(&(decodedScreenConfig.contentNodes));

    return callWithMessage(callback,
                           objectId(),
                           staticTypeId(),
                           0,
                           &decodedScreenConfig.settings,
                           screen_Block_fields,
                           size);
}

cbox::CboxError
ScreenConfig::readStored(const cbox::PayloadCallback& callback) const
{
    return read(callback);
}

cbox::CboxError
ScreenConfig::write(const cbox::Payload& payload)
{
    screen_Block message = screen_Block_init_zero;
    decodedScreenConfig.layoutNodes.clear();
    decodedScreenConfig.contentNodes.clear();
    message.layoutNodes.funcs.decode = gui::dynamic_interface::detail::layoutNodeDecoder;
    message.contentNodes.funcs.decode = gui::dynamic_interface::detail::contentNodeDecoder;
    message.layoutNodes.arg = reinterpret_cast<void*>(&(decodedScreenConfig.layoutNodes));
    message.contentNodes.arg = reinterpret_cast<void*>(&(decodedScreenConfig.contentNodes));

    auto res = payloadToMessage(payload, &message, screen_Block_fields);

    if (res == cbox::CboxError::OK) {
        decodedScreenConfig.settings = message;
        m_newSettingsReceived = true;
    }

    return res;
}

// use global static settings, because we only have one display
ScreenConfig::DecodedScreenConfig ScreenConfig::decodedScreenConfig = {screen_Block_init_zero, {}, {}};

bool ScreenConfig::m_newSettingsReceived = false;
