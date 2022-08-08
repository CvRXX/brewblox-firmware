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

SCENARIO("FastPwm test", "[FastPwm]")
{
    auto io = TestControlPtr<IoArray>(new MockIoArray());
    FastPwm pwm(io, 1);

    auto getDuty = [&]() {
        auto channelValue = io.ptr->readChannel(1);
        auto pVal = std::get_if<IoValue::PWM>(&channelValue);
        REQUIRE(pVal);
        return pVal->duty();
    };

    WHEN("FastPWM is newly constructed")
    {
        THEN("Duty is 0")
        {
            CHECK(pwm.setting() == 0);
            CHECK(pwm.value() == 0);
        }

        THEN("Setting duty configures the io channel")
        {
            pwm.setting(100);
            CHECK(pwm.setting() == 100);
            pwm.update(0);
            CHECK(pwm.value() == 100);
            CHECK(getDuty() == 100);

            pwm.setting(80);
            CHECK(pwm.setting() == 80);
            pwm.update(1);
            CHECK(pwm.value() == 80);
            CHECK(getDuty() == 80);

            AND_THEN("The setting is clipped between 0 and 100")
            {
                pwm.setting(120);
                CHECK(pwm.setting() == 100);
                pwm.update(2);
                CHECK(pwm.value() == 100);
                CHECK(getDuty() == 100);

                pwm.setting(-1);
                CHECK(pwm.setting() == 0);
                pwm.update(2);
                CHECK(pwm.value() == 0);
                CHECK(getDuty() == 0);
            }
        }
    }

    WHEN("A transition time of 250 ms is used")
    {
        pwm.update(100);
        pwm.setTransitionTime(200);
        THEN("The target PWM channel goes from 0 to 100 over 250 ms")
        {
            pwm.setting(100);
            CHECK(pwm.setting() == 100);
            CHECK(pwm.value() == 0);

            THEN("duty is 0 directly after changing setting")
            {
                CHECK(getDuty() == 0);
            }
            AND_THEN("duty increases gradually with regular updates")
            {
                pwm.update(110);
                CHECK(getDuty() == 5);

                pwm.update(120);
                CHECK(getDuty() == 10);
            }
            AND_THEN("duty increases by 25% when update interval is too slow")
            {
                pwm.update(201);
                CHECK(getDuty() == 25);

                pwm.update(301);
                CHECK(getDuty() == 50);

                pwm.update(401);
                CHECK(getDuty() == 75);

                pwm.update(501);
                CHECK(getDuty() == 100);

                AND_WHEN("The actuator is set to 0, the duty slowy decreases")
                {
                    pwm.setting(0);
                    pwm.update(511);
                    CHECK(getDuty() == 95);

                    pwm.update(611);
                    CHECK(getDuty() == 70);

                    pwm.update(711);
                    CHECK(getDuty() == 45);
                    pwm.update(811);
                    CHECK(getDuty() == 20);

                    pwm.update(812);
                    CHECK(getDuty() == 19.5);

                    pwm.update(911);
                    CHECK(getDuty() == 0);
                }
            }
        }
    }

    WHEN("The FastPwm is disabled")
    {
        pwm.setting(100);
        CHECK(pwm.setting() == 100);
        pwm.update(0);

        pwm.enabler.set(false);

        THEN("The target channel is set to duty 0 and the setting is cleared")
        {
            CHECK(pwm.setting().has_value() == false);
            CHECK(getDuty() == 0);
        }
    }

    WHEN("The FastPwm setting is cleared")
    {
        pwm.setting(100);
        CHECK(pwm.setting() == 100);
        pwm.update(0);

        pwm.setting(std::nullopt);

        THEN("The target channel is set to 0%")
        {
            CHECK(pwm.setting().has_value() == false);
            CHECK(getDuty() == 0);
        }
    }
}
