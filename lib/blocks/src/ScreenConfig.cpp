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
#include "cbox/PayloadConversion.hpp"

cbox::CboxError
ScreenConfig::read(const cbox::PayloadCallback& callback) const
{
    const size_t size = 600;

    // decodedScreenConfig.settings.pages.funcs.encode = gui::dynamic_interface::detail::pageEncoder;
    // decodedScreenConfig.settings.layoutNodes.arg = reinterpret_cast<void*>(&(decodedScreenConfig.layoutNodes));

    // decodedScreenConfig.settings.contentNodes.funcs.encode = gui::dynamic_interface::detail::contentNodeEncoder;
    // decodedScreenConfig.settings.contentNodes.arg = reinterpret_cast<void*>(&(decodedScreenConfig.contentNodes));

    decodedScreenConfig.settings.pages.funcs.encode = gui::dynamic_interface::detail::pageEncoder;
    decodedScreenConfig.settings.pages.arg = reinterpret_cast<void*>(&decodedScreenConfig.pages);

    return cbox::PayloadBuilder(*this)
        .withContent(&decodedScreenConfig.settings,
                     screen_Block_fields,
                     size)
        .respond(callback)
        .status();
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
    decodedScreenConfig.pages.clear();
    message.pages.funcs.decode = gui::dynamic_interface::detail::pageDecoder;
    message.pages.arg = reinterpret_cast<void*>(&(decodedScreenConfig.pages));

    auto parser = cbox::PayloadParser(payload);

    if (parser.fillMessage(&message, screen_Block_fields)) {
        decodedScreenConfig.settings = message;
        m_newSettingsReceived = true;
    }

    return parser.status();
}

// use global static settings, because we only have one display
ScreenConfig::DecodedScreenConfig ScreenConfig::decodedScreenConfig = {screen_Block_init_zero, {}};

bool ScreenConfig::m_newSettingsReceived = false;
