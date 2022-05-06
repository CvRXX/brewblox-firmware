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

#include "TestControlPtr.hpp"
#include "control/SetpointSensorPair.hpp"
#include "control/TempSensorMock.hpp"
#include <catch.hpp>
#include <memory>

SCENARIO("SetpointSensorPair test")
{
    WHEN("A SetpointSensorPair is constructed")
    {
        auto sensor = TestControlPtr<TempSensor>(new TempSensorMock(21.0));
        SetpointSensorPair setpoint(sensor);

        CHECK(setpoint.setting() == 20.0);
        CHECK(setpoint.value() == 21.0);
    }
}
