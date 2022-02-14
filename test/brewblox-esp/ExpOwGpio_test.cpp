/*
 * Copyright 2021 BrewPi B.V.
 *
 * This file is part of Brewblox.
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

#include "DRV8908.hpp"
#include "DRV8908Mock.hpp"
#include "MockI2CDevice.hpp"
#include "MockSpiDevice.hpp"
#include "TCA9538.hpp"
#include "TCA9538Mock.hpp"
#include "control/ActuatorDigital.h"
#include "main/ExpOwGpio.hpp"
#include <catch.hpp>

SCENARIO("OneWire + GPIO module using mock hw")
{
    auto tca = std::make_shared<TCA9538Mock>(0);
    auto drv = std::make_shared<DRV8908Mock>(-1); // is actually selected by i2c, but for now this works

    addMockI2CDevice(tca);
    addMockSpiDevice(drv);

    auto gpio = std::make_shared<ExpOwGpio>(0);

    WHEN("Internal and external channel bits are converted to each other")
    {
        ExpOwGpio::ChanBits a;
        ExpOwGpio::ChanBitsInternal b;

        a.bits.all = 0x00FF;
        b = a;
        ExpOwGpio::ChanBits c = b;
        THEN("The bits are rearranged correctly")
        {
            CHECK(a.bits.all == c.bits.all);
            CHECK(a.bits.all != b.bits.all);
            CHECK(a.bits.pin.c1 == b.bits.pin.c1);
            CHECK(a.bits.pin.c2 == b.bits.pin.c2);
            CHECK(a.bits.pin.c3 == b.bits.pin.c3);
            CHECK(a.bits.pin.c4 == b.bits.pin.c4);
            CHECK(a.bits.pin.c5 == b.bits.pin.c5);
            CHECK(a.bits.pin.c6 == b.bits.pin.c6);
            CHECK(a.bits.pin.c7 == b.bits.pin.c7);
            CHECK(a.bits.pin.c8 == b.bits.pin.c8);
            CHECK(b.bits.all == 0b0011001100001111);
        }
    }

    WHEN("The gpio driver is updated for the first time, it is automatically initialized")
    {
        gpio->update();

        THEN("The config register of the DRV8908 is set to 0b10000011")
        {
            REQUIRE(drv->registers[int(DRV8908::RegAddr::CONFIG_CTRL)] == 0b00000011);
        }
    }

    WHEN("An single pin SSR is added using 1 pin")
    {
        gpio->setupChannel(1, ExpOwGpio::FlexChannel{blox_OneWireGpioModule_GpioDeviceType_GPIO_DEV_SSR_1P, 1, 0b00001000});

        THEN("The pullups are configured as expected")
        {
            CHECK(gpio->pullUpWhenActive() == 0b1000);
            CHECK(gpio->pullDownWhenActive() == 0b0);
            CHECK(gpio->pullUpWhenInactive() == 0b0);
            CHECK(gpio->pullDownWhenInactive() == 0b1000);
            CHECK(gpio->pullUpDesired() == 0b0000);
            CHECK(gpio->pullUpStatus() == 0b0000);
        }
    }

    WHEN("An single pin SSR is added using 4 pins")
    {
        gpio->setupChannel(1, ExpOwGpio::FlexChannel{blox_OneWireGpioModule_GpioDeviceType_GPIO_DEV_SSR_1P, 4, 0b00001111});

        THEN("The pullups are configured as expected")
        {
            CHECK(gpio->pullUpWhenActive() == 0b1111);
            CHECK(gpio->pullDownWhenActive() == 0b0);
            CHECK(gpio->pullUpWhenInactive() == 0b0);
            CHECK(gpio->pullDownWhenInactive() == 0b1111);
        }
    }

    WHEN("An two pin SSR is added using 2 pins")
    {
        gpio->setupChannel(1, ExpOwGpio::FlexChannel{blox_OneWireGpioModule_GpioDeviceType_GPIO_DEV_SSR_2P, 2, 0b00000011});

        THEN("The pullups are configured as expected")
        {
            CHECK(gpio->pullUpWhenActive() == 0b0010);
            CHECK(gpio->pullDownWhenActive() == 0b01);
            CHECK(gpio->pullUpWhenInactive() == 0b00);
            CHECK(gpio->pullDownWhenInactive() == 0b11);
        }

        THEN("It can be driven by a digital actuator")
        {
            ActuatorDigital act([gpio]() { return gpio; }, 1);
            CHECK(gpio->pullUpStatus() == 0b0000);
            CHECK(gpio->pullDownStatus() == 0b0011);
            CHECK(act.state() == ActuatorDigital::State::Inactive);
            act.state(ActuatorDigital::State::Active);
            CHECK(act.state() == ActuatorDigital::State::Active);
            CHECK(gpio->pullUpStatus() == 0b0010);
            CHECK(gpio->pullDownStatus() == 0b0001);
            act.state(ActuatorDigital::State::Inactive);
            CHECK(act.state() == ActuatorDigital::State::Inactive);
            CHECK(gpio->pullUpStatus() == 0b0000);
            CHECK(gpio->pullDownStatus() == 0b0011);
        }
    }

    WHEN("An two pin SSR is added using 4 pins")
    {
        gpio->setupChannel(1, ExpOwGpio::FlexChannel{blox_OneWireGpioModule_GpioDeviceType_GPIO_DEV_SSR_2P, 4, 0b00001111});

        THEN("The pullups are configured as expected")
        {
            CHECK(gpio->pullUpWhenActive() == 0b001100);
            CHECK(gpio->pullDownWhenActive() == 0b0011);
            CHECK(gpio->pullUpWhenInactive() == 0b0000);
            CHECK(gpio->pullDownWhenInactive() == 0b1111);
        }

        AND_THEN("When it is replaced by a 2 pin SSR, the now unused bits are reset")
        {
            gpio->setupChannel(1, ExpOwGpio::FlexChannel{blox_OneWireGpioModule_GpioDeviceType_GPIO_DEV_SSR_2P, 2, 0b00000011});
            CHECK(gpio->pullUpWhenActive() == 0b0010);
            CHECK(gpio->pullDownWhenActive() == 0b01);
            CHECK(gpio->pullUpWhenInactive() == 0b00);
            CHECK(gpio->pullDownWhenInactive() == 0b11);
        }
    }

    WHEN("When the width doesn't match the number of ones in the mask")
    {
        gpio->setupChannel(1, ExpOwGpio::FlexChannel{blox_OneWireGpioModule_GpioDeviceType_GPIO_DEV_SSR_1P, 2, 0b00001111});

        THEN("Then no changes are made to the pull-up/pull-down settings")
        {
            CHECK(gpio->pullUpWhenActive() == 0);
            CHECK(gpio->pullDownWhenActive() == 0);
            CHECK(gpio->pullUpWhenInactive() == 0);
            CHECK(gpio->pullDownWhenInactive() == 0);
        }
    }

    WHEN("When the ones in the mask are not consecutive")
    {
        gpio->setupChannel(1, ExpOwGpio::FlexChannel{blox_OneWireGpioModule_GpioDeviceType_GPIO_DEV_SSR_1P, 4, 0b00011011});

        THEN("Then no changes are made to the pull-up/pull-down settings")
        {
            CHECK(gpio->pullUpWhenActive() == 0);
            CHECK(gpio->pullDownWhenActive() == 0);
            CHECK(gpio->pullUpWhenInactive() == 0);
            CHECK(gpio->pullDownWhenInactive() == 0);
        }
    }

    WHEN("When the ones in the mask overlap with another channel")
    {
        gpio->setupChannel(1, ExpOwGpio::FlexChannel{blox_OneWireGpioModule_GpioDeviceType_GPIO_DEV_SSR_1P, 4, 0b00001111});

        gpio->setupChannel(2, ExpOwGpio::FlexChannel{blox_OneWireGpioModule_GpioDeviceType_GPIO_DEV_SSR_1P, 4, 0b00111100});

        THEN("Then no changes are made to the pull-up/pull-down settings")
        {
            CHECK(gpio->pullUpWhenActive() == 0b1111);
            CHECK(gpio->pullDownWhenActive() == 0b0);
            CHECK(gpio->pullUpWhenInactive() == 0b0);
            CHECK(gpio->pullDownWhenInactive() == 0b1111);
        }

        THEN("The pin mask of the second channel is cleared")
        {
            CHECK(gpio->getChannel(1).pins() == 0b00001111);
            CHECK(gpio->getChannel(2).pins() == 0);
        }
    }

    WHEN("A channel is moved to different pins")
    {
        gpio->setupChannel(1, ExpOwGpio::FlexChannel{blox_OneWireGpioModule_GpioDeviceType_GPIO_DEV_COIL_2P_BIDIRECTIONAL, 4, 0b00001111});

        CHECK(gpio->pullUpWhenActive() == 0b1100);
        CHECK(gpio->pullDownWhenActive() == 0b0011);
        CHECK(gpio->pullUpWhenInactive() == 0b0011);
        CHECK(gpio->pullDownWhenInactive() == 0b1100);
        CHECK(gpio->pullDownStatus() == 0b1100);
        CHECK(gpio->pullUpStatus() == 0b0011);

        gpio->setupChannel(1, ExpOwGpio::FlexChannel{blox_OneWireGpioModule_GpioDeviceType_GPIO_DEV_COIL_2P_BIDIRECTIONAL, 4, 0b00111100});

        THEN("The bits related to the old pins are cleared")
        {
            CHECK(gpio->pullUpWhenActive() == 0b110000);
            CHECK(gpio->pullDownWhenActive() == 0b001100);
            CHECK(gpio->pullUpWhenInactive() == 0b001100);
            CHECK(gpio->pullDownWhenInactive() == 0b110000);
            CHECK(gpio->pullDownStatus() == 0b110000);
            CHECK(gpio->pullUpStatus() == 0b001100);
        }

        WHEN("The channel is toggled to active before the move")
        {
            gpio->writeChannelImpl(1, IoArray::ChannelConfig::DRIVING_ON);

            THEN("The bits are correct before the move")
            {
                CHECK(gpio->pullUpWhenActive() == 0b110000);
                CHECK(gpio->pullDownWhenActive() == 0b001100);
                CHECK(gpio->pullUpWhenInactive() == 0b001100);
                CHECK(gpio->pullDownWhenInactive() == 0b110000);
                CHECK(gpio->pullDownStatus() == 0b001100);
                CHECK(gpio->pullUpStatus() == 0b110000);

                AND_THEN("The bits correct after the move")
                {
                    gpio->setupChannel(1, ExpOwGpio::FlexChannel{blox_OneWireGpioModule_GpioDeviceType_GPIO_DEV_COIL_2P_BIDIRECTIONAL, 4, 0b00001111});
                    CHECK(gpio->pullUpWhenActive() == 0b1100);
                    CHECK(gpio->pullDownWhenActive() == 0b0011);
                    CHECK(gpio->pullUpWhenInactive() == 0b0011);
                    CHECK(gpio->pullDownWhenInactive() == 0b1100);
                    CHECK(gpio->pullDownStatus() == 0b1100);
                    CHECK(gpio->pullUpStatus() == 0b0011);
                }
            }
        }
    }

    WHEN("A 2 + only channels are created")
    {
        gpio->setupChannel(1, ExpOwGpio::FlexChannel{blox_OneWireGpioModule_GpioDeviceType_GPIO_DEV_SSR_1P, 1, 0b00000001});
        gpio->setupChannel(2, ExpOwGpio::FlexChannel{blox_OneWireGpioModule_GpioDeviceType_GPIO_DEV_SSR_1P, 1, 0b00000010});

        THEN("The masks are correct")
        {
            CHECK(gpio->pullUpWhenActive() == 0b11);
            CHECK(gpio->pullDownWhenActive() == 0b00);
            CHECK(gpio->pullUpWhenInactive() == 0b00);
            CHECK(gpio->pullDownWhenInactive() == 0b11);
            CHECK(gpio->pullDownStatus() == 0b11);
            CHECK(gpio->pullUpStatus() == 0b00);
            CHECK(gpio->pullUpDesired() == 0b00);
            CHECK(gpio->pullDownDesired() == 0b11);
        }

        THEN("When toggled, the status is correct")
        {
            gpio->writeChannelImpl(1, IoArray::ChannelConfig::DRIVING_ON);
            CHECK(gpio->pullUpDesired() == 0b01);
            CHECK(gpio->pullDownDesired() == 0b10);

            gpio->writeChannelImpl(2, IoArray::ChannelConfig::DRIVING_ON);
            CHECK(gpio->pullUpDesired() == 0b11);
            CHECK(gpio->pullDownDesired() == 0b00);

            gpio->writeChannelImpl(2, IoArray::ChannelConfig::DRIVING_OFF);
            CHECK(gpio->pullUpDesired() == 0b01);
            CHECK(gpio->pullDownDesired() == 0b10);

            gpio->writeChannelImpl(1, IoArray::ChannelConfig::DRIVING_OFF);
            CHECK(gpio->pullUpDesired() == 0b00);
            CHECK(gpio->pullDownDesired() == 0b11);
        }
    }
    removeMockI2CDevice(0x70);
    removeMockSpiDevice(-1);
}
