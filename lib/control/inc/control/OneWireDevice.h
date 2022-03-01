/*
 * Copyright 2018 BrewPi B.V.
 *
 * This file is part of the BrewBlox Control Library.
 *
 * BrewPi is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * BrewPi is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with BrewPi.  If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once

#include "control/OneWire.h"
#include "control/OneWireAddress.h"
#include <functional>
#include <memory>

class OneWireDevice {
public:
    OneWireDevice(std::function<std::shared_ptr<OneWire>()>&& getBus_, const OneWireAddress& address_);

protected:
    ~OneWireDevice() = default;

public:
    OneWireAddress address() const
    {
        return m_address;
    }
    void address(const OneWireAddress& addr)
    {
        m_address = addr;
    }

    bool connected() const
    {
        return m_connected;
    }

    void connected(bool _connected);

    // return valid OneWire bus if both the bus and the device can be found
    std::shared_ptr<OneWire> selectRom() const;

protected:
    std::function<std::shared_ptr<OneWire>()> getBus;
    OneWireAddress m_address;

private:
    bool m_connected = false;
};
