/*
 * Copyright 2020 BrewPi B.V.
 *
 * This file is part of the BrewBlox Control Library.
 *
 * BrewBlox is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * BrewBlox is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with Brewblox.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "control/OneWireDevice.hpp"
#include "AppLogger.hpp"
#include "control/OneWire.hpp"
#include "control/OneWireAddress.hpp"

/**
 * Constructor
 * /param oneWire_ The oneWire bus the device is connected to
 * /param address_ The oneWire address of the device to use.
 */
OneWireDevice::OneWireDevice(ControlPtr<OneWire>& busPtr_, const OneWireAddress& address_)
    : m_bus(busPtr_)
    , m_address(address_)
{
}

void OneWireDevice::connected(bool _connected)
{
    if (m_connected == _connected) {
        return; // state stays the same
    }

    std::string log;

    switch (m_address[0]) {
    case 0x28:
        log += "Temp sensor ";
        break;
    case 0x3A:
        log += "DS2413 ";
        break;
    case 0x29:
        log += "DS2408 ";
        break;                    // LCOV_EXCL_LINE
    default:                      // LCOV_EXCL_LINE
        log += "OneWire device "; // LCOV_EXCL_LINE
    }

    if (!_connected) {
        log += "dis";
    }
    log += "connected: ";

    log += m_address.toString();

    if (_connected) {
        logger::info(log);
    } else {
        logger::warn(log);
    }

    m_connected = _connected;
}

// return valid OneWire bus if both the bus and the device can be found
std::shared_ptr<OneWire> OneWireDevice::selectRom() const
{
    if (auto oneWire = m_bus.lock()) {
        if (oneWire->reset() && oneWire->select(m_address)) {
            return oneWire;
        };
    }
    return {};
}
