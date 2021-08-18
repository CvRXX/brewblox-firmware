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

#include "MockI2CDevice.hpp"
#include "TCA9538.hpp"
#include "TCA9538Mock.hpp"
#include <catch.hpp>

SCENARIO("writing outputs of TCA9538")
{
    addMockI2CDevice(std::unique_ptr<MockI2CDevice>(new TCA9538Mock(0)));

    TCA9538 device(0);

    WHEN("The outputs are written")
    {
        device.set_outputs(100);

        THEN("They read back the same as what was written")
        {
            uint8_t result;
            REQUIRE(device.get_outputs(result));
            CHECK(result == 100);
        }
    }
}
