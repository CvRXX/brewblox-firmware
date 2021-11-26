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

uint8_t find_next(const cbox::ObjectContainer& objects, uint8_t lastAddress)
{
    uint8_t address = lastAddress;
    while (address < 128) {
        ++address;
        auto err = hal_i2c_detect(address);
        if (!err) {
            uint8_t pos = (address & uint8_t{0x3}) + 1;
            auto samePosition = [&pos](const cbox::ContainedObject& cobj) {
                if (auto ptr = cbox::asInterface<IoModule>(cobj.object())) {
                    return ptr->modulePosition() == pos;
                };
                return false;
            };
            if (std::find_if(objects.cbegin(), objects.cend(), samePosition) != objects.cend()) {
                // already initialized module at this position;
                continue;
            }

            return address;
        }
    }
    return 0;
}
}

std::shared_ptr<cbox::Object> I2cScanningFactory::scan(cbox::ObjectContainer& objects)
{
    uint8_t address = 0;
    while (true) {
        address = detail::find_next(objects, address);
        if (!address) {
            return nullptr;
        }
        uint8_t family = address & uint8_t{0xFC};
        uint8_t lower_bits = address & uint8_t{0x3};
        if (family == DS248x::base_address()) {
            uint8_t expander_address = TCA9538::base_address() + lower_bits;
            if (hal_i2c_detect(expander_address) == 0) {
                // new OneWire GPIO module detected (OneWire bus master and port expander)
                return std::shared_ptr<cbox::Object>(new ExpOwGpioBlock(lower_bits));
            }
        }
        hal_yield();
    };
    return nullptr;
}
