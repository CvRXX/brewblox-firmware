/*
 * Copyright 2018 BrewPi B.V.
 *
 * This file is part of Brewblox.
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
#include <cstdio>
#include <iomanip>
#include <iostream>

#include "TestHelpers.hpp"
#include "blocks/TempSensorCombiBlock.hpp"
#include "blocks/TempSensorMockBlock.hpp"
#include "cbox/Box.hpp"
#include "control/Temperature.hpp"
#include "proto/TempSensorCombi_test.pb.h"
#include "proto/TempSensorMock_test.pb.h"
#include "spark/Brewblox.hpp"

SCENARIO("A TempSensorCombi block")
{
    cbox::getObjects().clearAll();
    platform::particle::setupSystemBlocks();
    cbox::update(0);

    auto sensorId1 = cbox::obj_id_t(101);
    auto sensorId2 = cbox::obj_id_t(102);
    auto sensorId3 = cbox::obj_id_t(103);
    auto combiSensorId = cbox::obj_id_t(100);

    // Create mock sensor 1
    {
        auto cmd = cbox::TestCommand(sensorId1, TempSensorMockBlock::staticTypeId());
        auto message = blox_test::TempSensorMock::Block();

        message.set_setting(cnl::unwrap(temp_t(21.0)));
        message.set_connected(true);

        messageToPayload(cmd, message);
        CHECK(cbox::createBlock(cmd.request, cmd.callback) == cbox::CboxError::OK);
    }

    // Create mock sensor 2
    {
        auto cmd = cbox::TestCommand(sensorId2, TempSensorMockBlock::staticTypeId());
        auto message = blox_test::TempSensorMock::Block();

        message.set_setting(cnl::unwrap(temp_t(22.0)));
        message.set_connected(true);

        messageToPayload(cmd, message);
        CHECK(cbox::createBlock(cmd.request, cmd.callback) == cbox::CboxError::OK);
    }

    // Create mock sensor 3
    {
        auto cmd = cbox::TestCommand(sensorId3, TempSensorMockBlock::staticTypeId());
        auto message = blox_test::TempSensorMock::Block();

        message.set_setting(cnl::unwrap(temp_t(23.0)));
        message.set_connected(true);

        messageToPayload(cmd, message);
        CHECK(cbox::createBlock(cmd.request, cmd.callback) == cbox::CboxError::OK);
    }

    // Create combi sensor
    {
        auto cmd = cbox::TestCommand(combiSensorId, TempSensorCombiBlock::staticTypeId());
        auto message = blox_test::TempSensorCombi::Block();

        message.add_sensors(sensorId1);
        message.add_sensors(sensorId2);
        message.add_sensors(sensorId3);

        messageToPayload(cmd, message);
        CHECK(cbox::createBlock(cmd.request, cmd.callback) == cbox::CboxError::OK);
    }

    cbox::update(0);

    WHEN("func is set to AVG")
    {
        // AVG is default
        cbox::update(1000);

        THEN("The value of the sensor is the average of the 3")
        {
            auto cmd = cbox::TestCommand(combiSensorId, TempSensorCombiBlock::staticTypeId());
            auto message = blox_test::TempSensorCombi::Block();

            CHECK(cbox::readBlock(cmd.request, cmd.callback) == cbox::CboxError::OK);
            payloadToMessage(cmd, message);

            CHECK(message.ShortDebugString() ==
                  "value: 90112 "
                  "sensors: 101 "
                  "sensors: 102 "
                  "sensors: 103");
        }
    }

    WHEN("func is set to MAX")
    {
        {
            auto cmd = cbox::TestCommand(combiSensorId, TempSensorCombiBlock::staticTypeId());
            auto message = blox_test::TempSensorCombi::Block();

            message.set_combinefunc(blox_test::TempSensorCombi::SensorCombiFunc::SENSOR_COMBI_FUNC_MAX);
            message.add_sensors(sensorId1);
            message.add_sensors(sensorId2);
            message.add_sensors(sensorId3);

            messageToPayload(cmd, message);
            CHECK(cbox::writeBlock(cmd.request, cmd.callback) == cbox::CboxError::OK);
        }

        cbox::update(1000);

        THEN("The value of the sensor is the highest of the 3")
        {
            auto cmd = cbox::TestCommand(combiSensorId, TempSensorCombiBlock::staticTypeId());
            auto message = blox_test::TempSensorCombi::Block();

            CHECK(cbox::readBlock(cmd.request, cmd.callback) == cbox::CboxError::OK);
            payloadToMessage(cmd, message);

            CHECK(message.ShortDebugString() ==
                  "value: 94208 "
                  "combineFunc: SENSOR_COMBI_FUNC_MAX "
                  "sensors: 101 "
                  "sensors: 102 "
                  "sensors: 103");
        }
    }

    WHEN("func is set to MIN")
    {
        {
            auto cmd = cbox::TestCommand(combiSensorId, TempSensorCombiBlock::staticTypeId());
            auto message = blox_test::TempSensorCombi::Block();

            message.set_combinefunc(blox_test::TempSensorCombi::SensorCombiFunc::SENSOR_COMBI_FUNC_MIN);
            message.add_sensors(sensorId1);
            message.add_sensors(sensorId2);
            message.add_sensors(sensorId3);

            messageToPayload(cmd, message);
            CHECK(cbox::writeBlock(cmd.request, cmd.callback) == cbox::CboxError::OK);
        }

        cbox::update(1000);

        THEN("The value of the sensor is the lowest of the 3")
        {
            auto cmd = cbox::TestCommand(combiSensorId, TempSensorCombiBlock::staticTypeId());
            auto message = blox_test::TempSensorCombi::Block();

            CHECK(cbox::readBlock(cmd.request, cmd.callback) == cbox::CboxError::OK);
            payloadToMessage(cmd, message);

            CHECK(message.ShortDebugString() ==
                  "value: 86016 "
                  "combineFunc: SENSOR_COMBI_FUNC_MIN "
                  "sensors: 101 "
                  "sensors: 102 "
                  "sensors: 103");
        }
    }

    WHEN("All 3 sensors are disconnected, the value is a stripped field ")
    {
        // Edit mock sensor 1
        {
            auto cmd = cbox::TestCommand(sensorId1, TempSensorMockBlock::staticTypeId());
            auto message = blox_test::TempSensorMock::Block();

            message.set_setting(cnl::unwrap(temp_t(21.0)));
            message.set_connected(false);

            messageToPayload(cmd, message);
            CHECK(cbox::writeBlock(cmd.request, cmd.callback) == cbox::CboxError::OK);
        }

        // Edit mock sensor 2
        {
            auto cmd = cbox::TestCommand(sensorId2, TempSensorMockBlock::staticTypeId());
            auto message = blox_test::TempSensorMock::Block();

            message.set_setting(cnl::unwrap(temp_t(22.0)));
            message.set_connected(false);

            messageToPayload(cmd, message);
            CHECK(cbox::writeBlock(cmd.request, cmd.callback) == cbox::CboxError::OK);
        }

        // Edit mock sensor 3
        {
            auto cmd = cbox::TestCommand(sensorId3, TempSensorMockBlock::staticTypeId());
            auto message = blox_test::TempSensorMock::Block();

            message.set_setting(cnl::unwrap(temp_t(23.0)));
            message.set_connected(false);

            messageToPayload(cmd, message);
            CHECK(cbox::writeBlock(cmd.request, cmd.callback) == cbox::CboxError::OK);
        }

        cbox::update(1000);

        THEN("The combined sensor has no value")
        {
            auto cmd = cbox::TestCommand(combiSensorId, TempSensorCombiBlock::staticTypeId());
            auto message = blox_test::TempSensorCombi::Block();

            CHECK(cbox::readBlock(cmd.request, cmd.callback) == cbox::CboxError::OK);
            payloadToMessage(cmd, message);

            CHECK(message.ShortDebugString() ==
                  "sensors: 101 "
                  "sensors: 102 "
                  "sensors: 103 "
                  "strippedFields: 1");
        }
    }
}
