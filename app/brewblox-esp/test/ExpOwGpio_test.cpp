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

    WHEN("The gpio driver is updated for the first time, it is automatically initialized")
    {
        gpio.update();

        THEN("The config register of the DRV8908 is set to 0b10000011")
        {
            REQUIRE(drv->registers[int(DRV8908::RegAddr::CONFIG_CTRL)] == 0b10000011);
        }
    }

    WHEN("An single pin SSR is added using 1 pin")
    {
        gpio.setupChannel(1, ExpOwGpio::FlexChannel{blox_GpioDeviceType_ONE_PIN_SSR, 0b00001000});

        THEN("The pullups are configured as expected")
        {
            CHECK(gpio.pullUpWhenActive() == 0b1000);
            CHECK(gpio.pullDownWhenActive() == 0b0);
            CHECK(gpio.pullUpWhenInactive() == 0b0);
            CHECK(gpio.pullDownWhenInactive() == 0b1000);
        }
    }

    WHEN("An single pin SSR is added using 4 pins")
    {
        gpio.setupChannel(1, ExpOwGpio::FlexChannel{blox_GpioDeviceType_ONE_PIN_SSR, 0b00001111});

        THEN("The pullups are configured as expected")
        {
            CHECK(gpio.pullUpWhenActive() == 0b1111);
            CHECK(gpio.pullDownWhenActive() == 0b0);
            CHECK(gpio.pullUpWhenInactive() == 0b0);
            CHECK(gpio.pullDownWhenInactive() == 0b1111);
        }
    }

    WHEN("An two pin SSR is added using 2 pins")
    {
        gpio.setupChannel(1, ExpOwGpio::FlexChannel{blox_GpioDeviceType_TWO_PIN_SSR, 0b00000011});

        THEN("The pullups are configured as expected")
        {
            CHECK(gpio.pullUpWhenActive() == 0b0010);
            CHECK(gpio.pullDownWhenActive() == 0b01);
            CHECK(gpio.pullUpWhenInactive() == 0b00);
            CHECK(gpio.pullDownWhenInactive() == 0b11);
        }
    }

    WHEN("An two pin SSR is added using 4 pins")
    {
        gpio.setupChannel(1, ExpOwGpio::FlexChannel{blox_GpioDeviceType_TWO_PIN_SSR, 0b00001111});

        THEN("The pullups are configured as expected")
        {
            CHECK(gpio.pullUpWhenActive() == 0b001100);
            CHECK(gpio.pullDownWhenActive() == 0b0011);
            CHECK(gpio.pullUpWhenInactive() == 0b0000);
            CHECK(gpio.pullDownWhenInactive() == 0b1111);
        }

        AND_THEN("When it is replaced by a 2 pin SSR, the now unused bits are reset")
        {
            gpio.setupChannel(1, ExpOwGpio::FlexChannel{blox_GpioDeviceType_TWO_PIN_SSR, 0b00000011});
            CHECK(gpio.pullUpWhenActive() == 0b0010);
            CHECK(gpio.pullDownWhenActive() == 0b01);
            CHECK(gpio.pullUpWhenInactive() == 0b00);
            CHECK(gpio.pullDownWhenInactive() == 0b11);
        }
    }

    removeMockI2CDevice(0x70);
    removeMockSpiDevice(-1);
}
