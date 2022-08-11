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

#include <catch.hpp>

#include "control/ActuatorAnalogMock.hpp"

SCENARIO("ActuatorAnalogMock test")
{
    WHEN("An ActuatorAnalogMock is constructed, initial values are corrent and min/max is applied")
    {
        {
            ActuatorAnalogMock act;
            REQUIRE(act.setting().has_value());
            REQUIRE(act.value().has_value());
            CHECK(act.setting().value() == 0);
            CHECK(act.value().value() == 0);
        }
        {
            ActuatorAnalogMock act(50);
            REQUIRE(act.setting().has_value());
            REQUIRE(act.value().has_value());
            CHECK(act.setting().value() == 50);
            CHECK(act.value().value() == 50);
        }
        {
            ActuatorAnalogMock act(110, 0, 100);
            REQUIRE(act.setting().has_value());
            REQUIRE(act.value().has_value());
            CHECK(act.setting().value() == 100);
            CHECK(act.value().value() == 100);
        }
        {
            ActuatorAnalogMock act(-10, 5, 100);
            REQUIRE(act.setting().has_value());
            REQUIRE(act.value().has_value());
            CHECK(act.setting().value() == 5);
            CHECK(act.value().value() == 5);
        }
    }
}
