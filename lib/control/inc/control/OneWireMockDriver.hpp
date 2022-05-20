/*
 * Copyright 2018 BrewPi B.V.
 *
 * This file is part of the BrewBlox Control Library.
 *
 * Brewblox is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * Brewblox is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with Brewblox.  If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once

#include "control/OneWireAddress.hpp"
#include "control/OneWireLowLevelInterface.hpp"
#include "control/OneWireMockDevice.hpp"
#include <memory>
#include <vector>

class OneWireMockDriver : public OneWireLowLevelInterface {

public:
    OneWireMockDriver()
    {
    }
    virtual ~OneWireMockDriver() = default;

public:
    bool init() final
    {
        return true;
    }

    bool read(uint8_t& v) final
    {
        // if multiple devices are answering, the result is a binary AND
        // This will only give valid responses with single bit replies, just like the real hardware
        v = 0xFF;
        for (auto& device : devices) {
            v &= device->read();
        }
        return true;
    }

    bool write(uint8_t b) final
    {
        for (auto& device : devices) {
            device->write(b);
        }
        return true;
    }

    uint8_t search_triplet(bool search_direction) final;

    bool write_bit(bool bit) final
    {
        write(bit ? 0x80 : 0x00);
        return true;
    }
    bool read_bit(bool& bit) final
    {
        uint8_t v;
        if (read(v)) {
            bit = v > 0;
            return true;
        }
        return false;
    }

    bool reset() final
    {

        bool devicePresent = false;
        for (auto& device : devices) {
            devicePresent |= device->reset();
        }
        return devicePresent;
    }

    void attach(std::shared_ptr<OneWireMockDevice> device)
    {
        devices.push_back(std::move(device));
    }

    bool shortDetected() final
    {
        return false;
    }

private:
    std::vector<std::shared_ptr<OneWireMockDevice>> devices;
};
