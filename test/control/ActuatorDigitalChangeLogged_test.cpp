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

#include "ActuatorDigital.h"
#include "ActuatorDigitalChangeLogged.h"
#include "MockIoArray.h"

SCENARIO("ActuatorDigitalChangeLogged test", "[ActuatorChangeLog]")
{
    using State = ActuatorDigitalBase::State;

    auto mockIo = std::make_shared<MockIoArray>();
    ActuatorDigital mock([mockIo]() { return mockIo; }, 1);
    ActuatorDigitalChangeLogged logged(mock);
    ticks_millis_t now = 1000;

    WHEN("ActuatorDigitalChangeLogged is newly constructed")
    {

        THEN("History is initialized at Unknown in the past and current state since construction")
        {

            auto times = logged.getLastStartEndTime(State::Unknown, now);
            CHECK(times.start == -1);
            CHECK(times.end == 0);

            auto millisSinceUnknown = now - times.end;
            CHECK(millisSinceUnknown == 1000);

            // Active has never occurred, so returns now + 1 (as far in the past as possible)
            times = logged.getLastStartEndTime(State::Active, now);
            CHECK(times.start == now + 1);
            CHECK(times.end == now + 1);

            times = logged.getLastStartEndTime(State::Inactive, now);
            CHECK(times.start == 0);
            CHECK(times.end == now);

            CHECK(times.end - times.start == 1000);
        }

        THEN("Changes are logged")
        {
            now = 3000;
            logged.state(State::Active, now);

            // set to inactive a few times to check that only changes are logged, not each time a value is set
            for (now = 4000; now < 4010; ++now) {
                logged.state(State::Inactive, now);
            }

            auto times = logged.getLastStartEndTime(State::Unknown, now);
            CHECK(times.start == -1);
            CHECK(times.end == 0);

            times = logged.getLastStartEndTime(State::Inactive, now);
            CHECK(times.start == 4000);
            CHECK(times.end == 4010);

            times = logged.getLastStartEndTime(State::Active, now);
            CHECK(times.start == 3000);
            CHECK(times.end == 4000);
        }

        THEN("Durations of current and previous period are correctly calculated")
        {
            logged.state(State::Active, 0);
            logged.state(State::Inactive, 1000);
            logged.state(State::Active, 2000);
            logged.state(State::Inactive, 3000);
            logged.state(State::Active, 4000);
            logged.state(State::Inactive, 5000);
            logged.state(State::Active, 6000);
            auto durations = logged.activeDurations(6300);
            CHECK(durations.currentActive == 300);
            CHECK(durations.currentPeriod == 1300);
            CHECK(durations.previousActive == 1000);
            CHECK(durations.previousPeriod == 2000);

            logged.state(State::Inactive, 7000);

            durations = logged.activeDurations(7300);
            CHECK(durations.currentActive == 1000);
            CHECK(durations.currentPeriod == 1300);
            CHECK(durations.previousActive == 1000);
            CHECK(durations.previousPeriod == 2000);
        }

        THEN("Inverting target actuator has no effect on durations")
        {
            mock.invert(true);
            logged.state(State::Active, 0);
            logged.state(State::Inactive, 1000);
            logged.state(State::Active, 2000);
            logged.state(State::Inactive, 3000);
            logged.state(State::Active, 4000);
            logged.state(State::Inactive, 5000);
            logged.state(State::Active, 6000);
            auto durations = logged.activeDurations(6300);
            CHECK(durations.currentActive == 300);
            CHECK(durations.currentPeriod == 1300);
            CHECK(durations.previousActive == 1000);
            CHECK(durations.previousPeriod == 2000);

            logged.state(State::Inactive, 7000);

            durations = logged.activeDurations(7300);
            CHECK(durations.currentActive == 1000);
            CHECK(durations.currentPeriod == 1300);
            CHECK(durations.previousActive == 1000);
            CHECK(durations.previousPeriod == 2000);
        }

        THEN("durations are correct immediately after switching")
        {
            // toggle a few times to erase history
            logged.state(State::Active, 1000);
            logged.state(State::Inactive, 1000);
            logged.state(State::Active, 1000);
            logged.state(State::Inactive, 1000);
            logged.state(State::Active, 1000);
            auto durations = logged.activeDurations(1000);
            CHECK(durations.currentActive == 0);
            CHECK(durations.currentPeriod == 0);
            CHECK(durations.previousActive == 0);
            CHECK(durations.previousPeriod == 0);

            logged.state(State::Inactive, 2000);
            durations = logged.activeDurations(2000);
            CHECK(durations.currentActive == 1000);
            CHECK(durations.currentPeriod == 1000);
            CHECK(durations.previousActive == 0);
            CHECK(durations.previousPeriod == 0);

            logged.state(State::Active, 3000);
            durations = logged.activeDurations(3000);
            CHECK(durations.currentActive == 0);
            CHECK(durations.currentPeriod == 1000);
            CHECK(durations.previousActive == 1000);
            CHECK(durations.previousPeriod == 1000);

            logged.state(State::Inactive, 4000);
            durations = logged.activeDurations(4000);
            CHECK(durations.currentActive == 1000);
            CHECK(durations.currentPeriod == 1000);
            CHECK(durations.previousActive == 1000);
            CHECK(durations.previousPeriod == 2000);

            logged.state(State::Active, 5000);
            durations = logged.activeDurations(5000);
            CHECK(durations.currentActive == 0);
            CHECK(durations.currentPeriod == 1000);
            CHECK(durations.previousActive == 1000);
            CHECK(durations.previousPeriod == 2000);
        }
    }
}
