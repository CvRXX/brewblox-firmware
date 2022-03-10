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

#include "spark/WiFiSettingsBlock.h"
#include "proto/WiFiSettings.pb.h"
#include "spark/Connectivity.h"

cbox::CboxError WiFiSettingsBlock::read(cbox::Command& cmd) const
{
    blox_WiFiSettings_Block message = blox_WiFiSettings_Block_init_zero;

    printWiFiIp(message.ip);
    printWifiSSID(message.ssid, sizeof(message.ssid));
    message.signal = wifiSignal();

    return writeProtoToCommand(cmd,
                               &message,
                               blox_WiFiSettings_Block_fields,
                               blox_WiFiSettings_Block_size,
                               objectId,
                               staticTypeId());
}

cbox::CboxError WiFiSettingsBlock::readPersisted(cbox::Command& cmd) const
{
    return writeEmptyToCommand(cmd, objectId, staticTypeId());
}

cbox::CboxError WiFiSettingsBlock::write(cbox::Command& cmd)
{
    blox_WiFiSettings_Block message = blox_WiFiSettings_Block_init_zero;
    auto res = readProtoFromCommand(cmd, &message, blox_WiFiSettings_Block_fields);

    if (res == cbox::CboxError::OK) {
        if (message.password[0] != 0) {
            // new wifi credentials received
            setWifiCredentials(message.ssid, message.password, message.security, message.cipher);
        }
    }

    return res;
}
