/*
 * Copyright 2015 BrewPi/Elco Jacobs.
 *
 * This file is part of BrewPi.
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
#include "control/ActuatorOffset.hpp"
#include "control/SetpointSensorPair.hpp"
#include "control/TempSensorMock.hpp"
#include <catch.hpp>
#include <memory>

SCENARIO("ActuatorOffset offsets one setpoint from another", "[ActuatorOffset]")
{
    auto targetSensorMock = TestControlPtr<TempSensorMock>(new TempSensorMock(20.0));
    auto referenceSensorMock = TestControlPtr<TempSensorMock>(new TempSensorMock(19.0));
    auto targetSensor = TestControlPtr<TempSensor>(targetSensorMock);
    auto referenceSensor = TestControlPtr<TempSensor>(referenceSensorMock);

    auto target = TestControlPtr<SetpointSensorPair>(new SetpointSensorPair(targetSensor));
    target.ptr->setting(20);
    auto reference = TestControlPtr<SetpointSensorPair>(new SetpointSensorPair(referenceSensor));
    reference.ptr->setting(20);

    auto act = std::make_shared<ActuatorOffset>(target, reference);

    act->setting(0);
    act->update();

    WHEN("The actuator is written, the target is offset from the reference")
    {
        reference.ptr->setting(20);
        act->setting(10.0);

        CHECK(reference.ptr->setting() == 20.0);
        CHECK(target.ptr->setting() == 30.0);
        CHECK(act->setting() == 10.0); // difference between setpoints is now 10
        CHECK(act->value() == 0.0);    // actual value is still zero, because targetSensor has not changed

        targetSensorMock.ptr->setting(30.0);
        target.ptr->resetFilter();
        act->update();
        CHECK(act->value() == 10.0); // actual value is 10 when sensor has reached setpoint

        act->setting(-10.0);
        CHECK(reference.ptr->setting() == 20.0);
        CHECK(target.ptr->setting() == 10.0);
        CHECK(act->setting() == -10.0); // difference between setpoints is now 10
        act->update();

        CHECK(act->value() == 10.0); // value is still 10, because targetSensor has not changed

        targetSensorMock.ptr->setting(10.0);
        target.ptr->resetFilter();
        act->update();
        CHECK(act->value() == -10.0); // value is -10 when sensor has reached setpoint

        reference.ptr->setting(10.0);
        referenceSensorMock.ptr->setting(15.0);
        reference.ptr->resetFilter();
        target.ptr->setting(20.0);
        targetSensorMock.ptr->setting(20.0);
        target.ptr->resetFilter();
        act->setting(12.0);

        // when using the reference setting as value to offset from (default):
        CHECK(act->value() == 10.0);   // value() returns target sensor - ref setpoint
        CHECK(act->setting() == 12.0); // setting() returns target setpoint - ref setpoint
        CHECK(target.ptr->setting() == 22.0);

        // when using the reference value as value to offset from:
        act->selectedReference(ActuatorOffset::ReferenceKind::VALUE);
        act->setting(12.0);

        CHECK(act->value() == 5.0);    // value() returns target sensor - ref sensor value
        CHECK(act->setting() == 12.0); // setting() returns target setpoint - ref sensor value
        CHECK(target.ptr->setting() == 27.0);
    }

    WHEN(
        "the reference setting is used and valid"
        "and the reference sensor is invalid, "
        "the target actuator is fully valid, because the reference sensor is unused")
    {
        act->selectedReference(ActuatorOffset::ReferenceKind::SETTING);
        target.ptr->setting(20);
        referenceSensorMock.ptr->connected(false);
        act->setting(12.0);

        REQUIRE(target.ptr->setting().has_value());
        CHECK(target.ptr->setting() == 32.0);
        CHECK(act->value() == 0);
        CHECK(act->setting() == 12.0);

        AND_WHEN("The reference setting becomes invalid")
        {
            reference.ptr->setting(std::nullopt);
            act->update();
            THEN("The target setting is set to invalid once, but not on subsequent updates")
            {
                CHECK(target.ptr->setting().has_value() == false);

                target.ptr->setting(33);
                act->update();
                CHECK(target.ptr->setting() == 33);

                target.ptr->setting(31);
                act->update();
                CHECK(target.ptr->setting() == 31);
            }
        }
    }

    WHEN(
        "the reference setting is used but invalid"
        "but the reference sensor is valid, then "
        "target setpoint will be set to invalid, and actuator value is invalid")
    {
        act->selectedReference(ActuatorOffset::ReferenceKind::SETTING);
        referenceSensorMock.ptr->connected(true);
        reference.ptr->setting(std::nullopt);
        act->setting(12.0);

        CHECK(act->value().has_value() == false);
        CHECK(act->setting().has_value() == true);
        CHECK(target.ptr->setting().has_value() == false);
    }

    WHEN(
        "the reference value is used but invalid, "
        "but the reference setpoint is valid, then "
        "target setpoint will be invalid and offset actuator value is invalid")
    {
        act->selectedReference(ActuatorOffset::ReferenceKind::VALUE);
        target.ptr->setting(20);
        referenceSensorMock.ptr->connected(false);
        for (int i = 0; i <= 10; i++) {
            reference.ptr->update(); // will only switch to invalid after 10s disconnected
        }
        CHECK(reference.ptr->value().has_value() == false);
        act->setting(12.0);

        CHECK(act->value().has_value() == false);
        CHECK(act->setting().has_value() == true);
        CHECK(target.ptr->setting().has_value() == false);
    }

    WHEN(
        "the reference value is used and valid, "
        "but the reference setpoint is invalid, then "
        "target setpoint will be valid and actuator is fully valid")
    {
        act->selectedReference(ActuatorOffset::ReferenceKind::VALUE);
        referenceSensorMock.ptr->connected(true);
        reference.ptr->setting(std::nullopt);
        act->setting(12.0);

        CHECK(target.ptr->setting().value() == 31.0);
        CHECK(act->value().value() == 1.0); // ref sensor value is 19, target sensor is 20
        CHECK(act->setting().value() == 12.0);
    }

    WHEN("The offset actuator is disabled")
    {
        act->setting(10.0);
        CHECK(reference.ptr->setting().value() == 20.0);
        CHECK(target.ptr->setting().value() == 30.0);
        act->update();
        CHECK(act->setting() == 10.0); // difference between setpoints is 10

        act->enabler.set(false);
        act->update();

        THEN("The actuator setting is invalid")
        {
            CHECK(act->setting().has_value() == false);
        }

        THEN("This action sets the targets setting to invalid once, and thus also the offset actuator value")
        {
            CHECK(target.ptr->setting().has_value() == false);
            CHECK(act->value().value() == 0);

            AND_THEN("Changing the setting of the actuator afterwards doesn't affect the target")
            {
                target.ptr->setting(30);
                act->setting(50);
                act->update();
                CHECK(target.ptr->setting().value() == 30.0); // still 30
                AND_THEN("the target can be changed externally")
                {
                    target.ptr->setting(40);
                    act->setting(50);
                    act->update();
                    CHECK(target.ptr->setting().value() == 40.0);
                }

                AND_WHEN("the offset actuator is enabled again")
                {
                    target.ptr->setting(40);
                    act->enabler.set(true);
                    act->update();
                    THEN("The actuator setting affects the target again")
                    {
                        act->setting(50);
                        act->update();
                        CHECK(target.ptr->setting().value() == 70.0);
                    }
                }
            }
        }
    }
}
