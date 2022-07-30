/*
 * Copyright 2022 BrewPi B.V.
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

#include "TestControlPtr.hpp"
#include "control/FastPwm.hpp"
#include "control/MockIoArray.hpp"

#if 0
SCENARIO("ActuatorDigitalSoft test", "[ActuatorDigitalSoft]")
{
    auto io = TestControlPtr<IoArray>(new MockIoArray());
    FastPwm mock(io, 1);

    WHEN("FastPWM is newly constructed")
    {
    }
}
#endif
