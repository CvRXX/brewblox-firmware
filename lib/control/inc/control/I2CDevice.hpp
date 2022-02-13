/*
 * Copyright 2021 BrewPi B.V.
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
#include "lib_hal/hal_i2c.h"
#include <array>
#include <initializer_list>

class I2CDevice {
public:
    virtual uint8_t family_address() const = 0;

    uint8_t address() const
    {
        return addr;
    }

    void set_address_bits(uint8_t lower_bits)
    {
        // use 0xFF as invalid/uninitialized address
        addr = (lower_bits < 4) ? lower_bits + family_address() : 0xFF;
    }

    bool i2c_write(uint8_t value, bool stop = true)
    {
        lastError = hal_i2c_write(addr, &value, 1, stop);
        return lastError == 0;
    }

    bool i2c_write(uint8_t value, uint8_t value2) = delete;

    template <size_t N>
    bool i2c_write(const std::array<uint8_t, N>& values, bool stop = true)
    {
        if (addr == 0xFF) {
            return false;
        }
        lastError = hal_i2c_write(addr, values.data(), values.size(), stop);
        return lastError == 0;
    }

    template <size_t N>
    bool i2c_read(std::array<uint8_t, N>& values, bool stop = true)
    {
        if (addr == 0xFF) {
            return false;
        }

        lastError = hal_i2c_read(addr, values.data(), values.size(), stop);
        return lastError == 0;
    }

    bool i2c_read(uint8_t& value, bool stop = true)
    {
        if (addr == 0xFF) {
            return false;
        }

        lastError = hal_i2c_read(addr, &value, 1, stop);
        return lastError == 0;
    }

    hal_i2c_err_t i2c_last_error()
    {
        return lastError;
    }

private:
    hal_i2c_err_t lastError = 0;
    uint8_t addr = 0xFF;
};

template <uint8_t address_base>
class I2CDeviceBase : public I2CDevice {
public:
    I2CDeviceBase(uint8_t lower_address)
    {
        set_address_bits(lower_address);
    }

    // non virtual for when type is known
    static constexpr uint8_t base_address()
    {
        return address_base;
    }

    // virtual for when type is not known
    virtual uint8_t family_address() const override final
    {
        return address_base;
    }
};
