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

    WHEN("ActuatorDigitalSoft is newly constructed and transition time is set to 0")
    {
        THEN("The state is set to Inactive")
        {

            CHECK(mock.state() == State::Inactive);
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
        mock.setTransitionTime(200);
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

            auto bit = 1.0 / 4096;
            THEN("duty is 1 bit above zero after state change")
            {
                CHECK(getDuty() == bit);
            }

            AND_THEN("duty increases gradually with regular updates")
            {
                mock.update(110);
                CHECK(getDuty() == bit + 5);

                mock.update(120);
                CHECK(getDuty() == bit + 10);
            }

            AND_THEN("duty increases by 25% when update interval is too slow")
            {
                mock.update(201);
                CHECK(getDuty() == bit + 25);

                mock.update(301);
                CHECK(getDuty() == bit + 50);

                mock.update(401);
                CHECK(getDuty() == bit + 75);

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

    WHEN("Channel capability flags are checked")
    {

        THEN("The correct flags are set")
        {
            auto capabilities = io.ptr->getChannelCapabilities(1);
            CHECK(capabilities.flags.digitalOutput);
            CHECK(capabilities.flags.pwm100Hz);
            CHECK(!capabilities.flags.pwm200Hz);
            CHECK(!capabilities.flags.pwm2000Hz);
            CHECK(!capabilities.flags.bidirectional);
            CHECK(!capabilities.flags.digitalInput);
        };

        THEN("Multiple flags can be checked at once")
        {
            CHECK(io.ptr->channelSupports(1, {.flags{.digitalOutput = 1}}));
            CHECK(io.ptr->channelSupports(1, {.flags{.digitalOutput = 1, .pwm100Hz = 1}}));
            CHECK(!io.ptr->channelSupports(1, {.flags{.digitalOutput = 1, .pwm200Hz = 1}}));
        };
    }
}
