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

#include "DRV8908.hpp"
#include "DRV8908Mock.hpp"
#include "MockSpiDevice.hpp"
#include <catch.hpp>

SCENARIO("writing registers of DRV8908")
{
    addMockSpiDevice(std::unique_ptr<MockSpiDevice>(new DRV8908Mock(1)));

    SpiDevice spi(
        hal_spi::Settings{
            .spi_idx = 0,
            .speed = 100000,
            .queueSize = 1,
            .ssPin = 1,
            .mode = hal_spi::Settings::Mode::SPI_MODE1,
            .bitOrder = hal_spi::Settings::BitOrder::MSBFIRST,
        });

    DRV8908 drv(spi);

    WHEN("The op_ctrl registers are written")
    {
        spi.aquire_bus();
        REQUIRE(!drv.writeRegister(DRV8908::RegAddr::OP_CTRL_1, 100));
        REQUIRE(!drv.writeRegister(DRV8908::RegAddr::OP_CTRL_2, 101));

        THEN("They read back the same as what was written")
        {
            uint8_t byte1, byte2;
            REQUIRE(!drv.readRegister(DRV8908::RegAddr::OP_CTRL_1, byte1));
            REQUIRE(!drv.readRegister(DRV8908::RegAddr::OP_CTRL_2, byte2));
            CHECK(byte1 == 100);
            CHECK(byte2 == 101);
        }
        spi.release_bus();
    }
}
