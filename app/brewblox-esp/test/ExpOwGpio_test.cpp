/*
 * Copyright 2021 BrewPi B.V.
 *
 * This file is part of BrewBlox.
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

#include "../main/ExpOwGpio.hpp"
#include "DRV8908.hpp"
#include "DRV8908Mock.hpp"
#include "MockI2CDevice.hpp"
#include "MockSpiDevice.hpp"
#include "TCA9538.hpp"
#include "TCA9538Mock.hpp"
#include <catch.hpp>

SCENARIO("OneWire + GPIO module using mock hw")
{
    auto tca = std::make_shared<TCA9538Mock>(0);
    auto drv = std::make_shared<DRV8908Mock>(-1); // is actually selected by i2c, but for now this works

    addMockI2CDevice(tca);
    addMockSpiDevice(drv);

    ExpOwGpio gpio(0);

    WHEN("The gpio driver is initialized")
    {
        gpio.init();

        THEN("The config register of the DRV8908 is set to 0b00000011")
        {
            REQUIRE(drv->registers[int(DRV8908::RegAddr::CONFIG_CTRL)] == 0b00000011);
        }
    }

    WHEN("The gpio driver is updated for the first time, it is automatically initialized")
    {
        gpio.update();

        THEN("The config register of the DRV8908 is set to 0b00000011")
        {
            REQUIRE(drv->registers[int(DRV8908::RegAddr::CONFIG_CTRL)] == 0b00000011);
        }
    }

    removeMockI2CDevice(0x70);
    removeMockSpiDevice(-1);
}
