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

#include "I2cScanningFactory.hpp"
#include "blox/ExpOwGpioBlock.hpp"
#include "hal/hal_i2c.h"
#include <algorithm>
#include <vector>

namespace detail {
static std::vector<uint8_t> initializedI2cAdresses = {32, 56}; // skip touch screen driver and main board io expander
static uint8_t nextAddress = 1;

void set_initialized(uint8_t addr)
{
    initializedI2cAdresses.push_back(addr);
}

void set_uninitialized(uint8_t addr)
{
    initializedI2cAdresses.erase(std::remove(initializedI2cAdresses.begin(), initializedI2cAdresses.end(), addr));
}

uint8_t find_next()
{
    while (detail::nextAddress < 128) {
        uint8_t address = detail::nextAddress++;
        if (std::find(initializedI2cAdresses.cbegin(), initializedI2cAdresses.cend(), address) != initializedI2cAdresses.cend()) {
            // already initialized;
            continue;
        }
        auto err = hal_i2c_detect(address, 1000);
        if (!err) {
            return address;
        }
    }
    return 0;
}
}

void I2cScanningFactory::reset()
{
    detail::nextAddress = 1;
}

std::shared_ptr<cbox::Object> I2cScanningFactory::scan(cbox::ObjectContainer& objects)
{
    static constexpr uint8_t FAM_DS2482 = 0x18;
    static constexpr uint8_t FAM_TCA9538 = 0x70;
    uint8_t found = 0;
    do {
        found = detail::find_next();
        uint8_t family = found & uint8_t(0xFC);
        uint8_t lower_bits = found & uint8_t(0x3);
        if (family == FAM_DS2482) {
            uint8_t expander_address = FAM_TCA9538 + lower_bits;
            if (hal_i2c_detect(expander_address) == 0) {
                // OneWire GPIO module detected (OneWire bus master and port expander)
                detail::set_initialized(found);
                detail::set_initialized(expander_address);

                // custom deleter to remove i2c addresses from initialized list when object is deleted
                return std::shared_ptr<ExpOwGpioBlock>(new ExpOwGpioBlock(lower_bits), [found, expander_address](ExpOwGpioBlock* ptr) {
                    detail::set_uninitialized(found);
                    detail::set_uninitialized(expander_address);
                    delete ptr;
                });
            }
        }
    } while (found);
    return nullptr;
}
