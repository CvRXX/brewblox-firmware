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

#include <cstdint>

class OneWireLowLevelInterface {
public:
    OneWireLowLevelInterface() = default;

protected:
    virtual ~OneWireLowLevelInterface() = default;

public:
    // Configure the pin or chip
    virtual bool init() = 0;

    // Perform a 1-Wire reset cycle. Returns 1 if a device responds
    // with a presence pulse.  Returns 0 if there is no device or the
    // bus is shorted or otherwise held low for more than 250uS
    virtual bool reset(void) = 0;

    // write a byte
    virtual bool write(uint8_t v) = 0;

    // Read a byte.
    virtual bool read(uint8_t& v) = 0;

    // Write a bit
    virtual bool write_bit(bool v) = 0;

    // Read a bit.
    virtual bool read_bit(bool& v) = 0;

    // Perform a triple operation which will perform 2 read bits and 1 write bit, returns device status
    virtual uint8_t search_triplet(bool search_direction) = 0;

    // Returens whether a short is detected on the bus
    virtual bool shortDetected() = 0;
};
