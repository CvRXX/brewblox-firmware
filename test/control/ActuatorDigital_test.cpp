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
#include "control/ActuatorDigital.hpp"
#include "control/ActuatorDigitalChangeLogged.hpp"
#include "control/MockIoArray.hpp"

SCENARIO("ActuatorDigital test", "[ActuatorDigital]")
{
    using State = ActuatorDigitalBase::State;
    auto io = TestControlPtr<IoArray>(new MockIoArray());
    ActuatorDigital mock(io, 1);

    WHEN("ActuatorDigital is newly constructed")
    {
        THEN("The state is set to Inactive")
        {

            CHECK(mock.state() == State::Inactive);
        }

        THEN("The channel is ready")
        {

            CHECK(mock.channelReady() == true);
        }

        THEN("It can be toggled between active and inactive")
        {
            mock.state(State::Active);
            CHECK(mock.state() == State::Active);

            mock.state(State::Inactive);
            CHECK(mock.state() == State::Inactive);

            mock.state(State::Active);
            CHECK(mock.state() == State::Active);
        }

        THEN("Writing a value other than Active sets it to inactive")
        {
            mock.state(State::Active);
            CHECK(mock.state() == State::Active);

            mock.state(State::Unknown);
            CHECK(mock.state() == State::Inactive);

            mock.state(State::Reverse);
            CHECK(mock.state() == State::Inactive);
        }
    }
}
