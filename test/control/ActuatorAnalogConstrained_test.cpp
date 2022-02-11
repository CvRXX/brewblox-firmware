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

#include "ActuatorAnalogConstrained.h"
#include "ActuatorAnalogMock.h"
#include "Balancer.h"

SCENARIO("ActuatorAnalogConstrained test", "[constraints]")
{
    WHEN("An actuator is constructed wrapped by a ActuatorAnalogConstrained")
    {
        ActuatorAnalogMock act;
        ActuatorAnalogConstrained cAct(act);

        CHECK(cAct.setting() == 0);
        CHECK(cAct.value() == 0);
        CHECK(cAct.settingValid() == true);

        cAct.setting(50);

        CHECK(act.setting() == 50);
        CHECK(act.value() == 50);
        CHECK(act.settingValid() == true);

        WHEN("A maximum constraint is added, the value is clipped at the maximum")
        {
            cAct.addConstraint(std::make_unique<AAConstraints::Maximum<1>>(25));

            cAct.setting(50);
            CHECK(cAct.setting() == ActuatorAnalog::value_t(25));
            CHECK(act.setting() == ActuatorAnalog::value_t(25));

            AND_WHEN("A minimum constraint is also added, the value is clipped at minimum and maximum")
            {
                cAct.addConstraint(std::make_unique<AAConstraints::Minimum<0>>(15));

                cAct.setting(50);
                CHECK(cAct.setting() == ActuatorAnalog::value_t(25));
                CHECK(act.setting() == ActuatorAnalog::value_t(25));

                cAct.setting(10);
                CHECK(cAct.setting() == ActuatorAnalog::value_t(15));
                CHECK(act.setting() == ActuatorAnalog::value_t(15));

                AND_WHEN("All constraints are removed, the actuator is not clipped anymore")
                {
                    cAct.removeAllConstraints();

                    cAct.setting(50);
                    CHECK(cAct.setting() == ActuatorAnalog::value_t(50));
                    CHECK(act.setting() == ActuatorAnalog::value_t(50));

                    cAct.setting(10);
                    CHECK(cAct.setting() == ActuatorAnalog::value_t(10));
                    CHECK(act.setting() == ActuatorAnalog::value_t(10));
                }
            }
        }

        WHEN("The actuator setting is set to invalid")
        {
            cAct.settingValid(false);
            THEN("The setting value can still be written")
            {
                cAct.setting(50);
                CHECK(cAct.setting() == 50);
            }
        }
    }
}

SCENARIO("When two analog actuators are constrained by a balancer", "[constraints]")
{
    using value_t = ActuatorAnalog::value_t;
    auto balancer = std::make_shared<Balancer<2>>();
    ActuatorAnalogMock act1;
    act1.minSetting(0);
    act1.maxSetting(100);
    ActuatorAnalogConstrained cAct1(act1);
    ActuatorAnalogMock act2;
    act2.minSetting(0);
    act2.maxSetting(100);
    ActuatorAnalogConstrained cAct2(act2);

    cAct1.addConstraint(std::make_unique<AAConstraints::Balanced<2>>([balancer]() { return balancer; }));
    cAct2.addConstraint(std::make_unique<AAConstraints::Balanced<2>>([balancer]() { return balancer; }));

    cAct1.setting(60);
    cAct2.setting(60);

    THEN("The actuator setting is zero until the first update of the balancer")
    {
        CHECK(cAct1.setting() == value_t(0));
        CHECK(cAct2.setting() == value_t(0));
    }

    THEN("After the balancer has updated, the values are constrained to not exceed the maximum available for the balancer, weighted by previous request")
    {
        balancer->update();
        cAct1.setting(60);
        cAct2.setting(60);

        CHECK(cAct1.setting() == Approx(50).margin(0.001));
        CHECK(cAct2.setting() == Approx(50).margin(0.001));

        balancer->update();
        cAct1.setting(70);
        cAct2.setting(30);

        CHECK(cAct1.setting() == Approx(50).margin(0.001));
        CHECK(cAct2.setting() == Approx(30).margin(0.001));

        balancer->update();
        cAct1.setting(70);
        cAct2.setting(30);

        CHECK(cAct1.setting() == Approx(70).margin(0.001));
        CHECK(cAct2.setting() == Approx(30).margin(0.001));
    }

    THEN("Values that are clipped by the actuator are not used by the balancer")
    {
        balancer->update();
        cAct1.setting(-60);
        cAct2.setting(-60);

        for (auto& client : balancer->clients()) {
            CHECK(client.requested == 0);
        }

        balancer->update();
        cAct1.setting(-70);
        cAct2.setting(30);

        for (auto& client : balancer->clients()) {
            CHECK(client.requested >= 0);
        }

        balancer->update();
        cAct1.setting(70);
        cAct2.setting(30);
        balancer->update();
        cAct1.setting(70);
        cAct2.setting(30);

        CHECK(cAct1.setting() == Approx(70).margin(0.001));
        CHECK(cAct2.setting() == Approx(30).margin(0.001));
    }
    THEN("if the previous request didn't exceed the total, the excess is equally distributed for the granted values")
    {
        balancer->update();
        cAct1.setting(20);
        cAct2.setting(0);
        balancer->update();
        cAct1.setting(100);
        cAct2.setting(100);

        CHECK(cAct1.setting() == Approx(60).margin(0.001));
        CHECK(cAct2.setting() == Approx(40).margin(0.001));

        balancer->update();
        cAct1.setting(0);
        cAct2.setting(0);
        balancer->update();
        cAct1.setting(100);
        cAct2.setting(100);

        CHECK(cAct1.setting() == Approx(50).margin(0.001));
        CHECK(cAct2.setting() == Approx(50).margin(0.001));

        AND_THEN("On the next request it is limited")
        {
            balancer->update();
            cAct1.setting(100);
            cAct2.setting(100);
            CHECK(cAct1.setting() == Approx(50).margin(0.001));
            CHECK(cAct2.setting() == Approx(50).margin(0.001));
        }
    }

    AND_WHEN("the actuators also have maximum constraints smaller than the available total")
    {
        cAct1.addConstraint(std::make_unique<AAConstraints::Maximum<1>>(20));
        cAct2.addConstraint(std::make_unique<AAConstraints::Maximum<1>>(30));

        THEN("the balancer uses the value clipped by the maximum constraint")
        {
            cAct1.setting(100);
            cAct2.setting(100);
            balancer->update();
            CHECK(balancer->clients()[0].requested == 20);
            CHECK(balancer->clients()[1].requested == 30);
        }
    }
}
