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
#include "control/ActuatorDigitalChangeLogged.hpp"
#include "control/ActuatorDigitalSoft.hpp"
#include "control/MockIoArray.hpp"

SCENARIO("ActuatorDigitalSoft test", "[ActuatorDigitalSoft]")
{
    using State = ActuatorDigitalBase::State;
    auto io = TestControlPtr<IoArray>(new MockIoArray());
    ActuatorDigitalSoft mock(io, 1);

    WHEN("ActuatorDigitalSoft is newly constructed")
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

    WHEN("A transition time of 250 ms is used")
    {
        mock.update(100);
        mock.transitionTime(200);
        THEN("The target PWM channel goes from 0 to 100 over 250 ms")
        {
            mock.state(State::Active);
            CHECK(mock.state() == State::Active);

            auto getDuty = [&]() {
                auto channelValue = io.ptr->readChannel(1);
                auto pVal = std::get_if<IoValue::PWM>(&channelValue);
                REQUIRE(pVal);
                return pVal->duty();
            };

            THEN("duty is 1 after state change")
            {
                CHECK(getDuty() == 1);
            }
            AND_THEN("duty increases gradually with regular updates")
            {
                mock.update(110);
                CHECK(getDuty() == 6);

                mock.update(120);
                CHECK(getDuty() == 11);
            }
            AND_THEN("duty increases by 25% when update interval is too slow")
            {
                mock.update(201);
                CHECK(getDuty() == 26);

                mock.update(301);
                CHECK(getDuty() == 51);

                mock.update(401);
                CHECK(getDuty() == 76);

                mock.update(501);
                CHECK(getDuty() == 100);

                AND_WHEN("The actuator is set to inactive, the duty slowy decreases")
                {
                    mock.state(State::Inactive);
                    mock.update(511);
                    CHECK(getDuty() == 95);

                    mock.update(611);
                    CHECK(getDuty() == 70);

                    mock.update(711);
                    CHECK(getDuty() == 45);
                    mock.update(811);
                    CHECK(getDuty() == 20);

                    mock.update(812);
                    CHECK(getDuty() == 19.5);

                    mock.update(911);
                    CHECK(getDuty() == 0);
                }
            }
        }
    }
}
