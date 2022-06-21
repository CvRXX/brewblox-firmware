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

#include "spark/WiFiSettingsBlock.hpp"
#include "cbox/PayloadConversion.hpp"
#include "proto/WiFiSettings.pb.h"
#include "spark/Connectivity.hpp"

namespace platform::particle {

cbox::CboxError WiFiSettingsBlock::read(const cbox::PayloadCallback& callback) const
{
    blox_WiFiSettings_Block message = blox_WiFiSettings_Block_init_zero;

    printWiFiIp(message.ip);
    printWifiSSID(message.ssid, sizeof(message.ssid));
    message.signal = wifiSignal();

    return cbox::PayloadBuilder(*this)
        .withContent(&message,
                     blox_WiFiSettings_Block_fields,
                     blox_WiFiSettings_Block_size)
        .respond(callback)
        .status();
}

cbox::CboxError WiFiSettingsBlock::readStored(const cbox::PayloadCallback& callback) const
{
    return cbox::PayloadBuilder(*this)
        .respond(callback)
        .status();
}

cbox::CboxError WiFiSettingsBlock::write(const cbox::Payload& payload)
{
    blox_WiFiSettings_Block message = blox_WiFiSettings_Block_init_zero;
    auto parser = cbox::PayloadParser(payload);

    if (parser.fillMessage(&message, blox_WiFiSettings_Block_fields)) {
        if (parser.hasField(blox_WiFiSettings_Block_password_tag)) {
            // all or nothing
            // we don't support patching only the password or ssid
            if (message.password[0] != 0) {
                setWifiCredentials(message.ssid, message.password, message.security, message.cipher);
            }
        }
    }

    return parser.status();
}

} // end namespace platform::particle
