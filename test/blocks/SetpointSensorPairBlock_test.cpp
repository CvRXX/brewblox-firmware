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
#include "blocks/SetpointSensorPairBlock.hpp"
#include "blocks/TempSensorMockBlock.hpp"
#include "cbox/Box.hpp"
#include "control/Temperature.hpp"
#include "proto/SetpointSensorPair_test.pb.h"
#include "proto/TempSensorMock_test.pb.h"
#include "spark/Brewblox.hpp"

SCENARIO("A Blox SetpointSensorPair object can be created from streamed protobuf data")
{
    cbox::objects.clearAll();
    platform::particle::setupSystemBlocks();
    cbox::update(0);

    auto sensorId = cbox::obj_id_t(100);
    auto setpointId = cbox::obj_id_t(101);

    // Create mock sensor
    {
        auto cmd = cbox::TestCommand(sensorId, TempSensorMockBlock::staticTypeId());
        auto message = blox_test::TempSensorMock::Block();

        message.set_setting(cnl::unwrap(temp_t(20.0)));
        message.set_connected(true);

        messageToPayload(cmd, message);
        CHECK(cbox::createBlock(cmd.request, cmd.callback) == cbox::CboxError::OK);
    }

    // Create setpoint
    {
        auto cmd = cbox::TestCommand(setpointId, SetpointSensorPairBlock::staticTypeId());
        auto message = blox_test::SetpointSensorPair::Block();

        message.set_sensorid(sensorId);
        message.set_settingenabled(true);
        message.set_storedsetting(cnl::unwrap(temp_t(21)));
        message.set_filter(blox_test::SetpointSensorPair::FilterChoice::FILTER_3m);
        message.set_filterthreshold(cnl::unwrap(temp_t(0.5)));

        messageToPayload(cmd, message);
        CHECK(cbox::createBlock(cmd.request, cmd.callback) == cbox::CboxError::OK);
    }

    WHEN("Reading the setpoint")
    {
        auto cmd = cbox::TestCommand(setpointId, SetpointSensorPairBlock::staticTypeId());
        auto message = blox_test::SetpointSensorPair::Block();

        CHECK(cbox::readBlock(cmd.request, cmd.callback) == cbox::CboxError::OK);
        payloadToMessage(cmd, message);

        CHECK(message.ShortDebugString() ==
              "sensorId: 100 "
              "setting: 86016 "
              "value: 81920 "
              "settingEnabled: true "
              "storedSetting: 86016 "
              "filter: FILTER_3m "
              "filterThreshold: 2048 "
              "valueUnfiltered: 81920");
    }

    WHEN("The sensor is invalid for over 10 seconds")
    {
        auto cboxPtr = cbox::CboxPtr<TempSensorMockBlock>(100);
        auto ptr = cboxPtr.lock();
        REQUIRE(ptr);

        ptr->get().connected(false);

        for (cbox::update_t t = 1000; t <= 12000; t += 100) {
            cbox::update(t);
        }

        THEN("The input value is flagged as stripped field")
        {
            auto cmd = cbox::TestCommand(setpointId, SetpointSensorPairBlock::staticTypeId());
            auto message = blox_test::SetpointSensorPair::Block();

            CHECK(cbox::readBlock(cmd.request, cmd.callback) == cbox::CboxError::OK);
            payloadToMessage(cmd, message);

            CHECK(message.ShortDebugString() ==
                  "sensorId: 100 "
                  "setting: 86016 "
                  "settingEnabled: true "
                  "storedSetting: 86016 "
                  "filter: FILTER_3m "
                  "filterThreshold: 2048 "
                  "strippedFields: 6 "
                  "strippedFields: 11");
        }
    }

    WHEN("The mock sensor value is changed to 25")
    {
        auto cboxPtr = cbox::CboxPtr<TempSensorMockBlock>(100);
        auto ptr = cboxPtr.lock();
        REQUIRE(ptr);

        ptr->get().setting(25);

        cbox::update(1000);

        THEN("The value that is read is still at the old value due to filtering immediately after")
        {
            auto cmd = cbox::TestCommand(setpointId, SetpointSensorPairBlock::staticTypeId());
            auto message = blox_test::SetpointSensorPair::Block();

            CHECK(cbox::readBlock(cmd.request, cmd.callback) == cbox::CboxError::OK);
            payloadToMessage(cmd, message);

            CHECK(message.ShortDebugString() ==
                  "sensorId: 100 "
                  "setting: 86016 "
                  "value: 81920 "
                  "settingEnabled: true "
                  "storedSetting: 86016 "
                  "filter: FILTER_3m "
                  "filterThreshold: 2048 "
                  "valueUnfiltered: 102400");
        }

        AND_THEN("Sending a filter reset trigger will force the filter state to the current value")
        {
            auto cmd = cbox::TestCommand(setpointId, SetpointSensorPairBlock::staticTypeId());
            auto message = blox_test::SetpointSensorPair::Block();

            CHECK(cbox::readBlock(cmd.request, cmd.callback) == cbox::CboxError::OK);
            payloadToMessage(cmd, message);

            message.set_resetfilter(true);

            cmd.responses.clear();
            messageToPayload(cmd, message);
            CHECK(cbox::writeBlock(cmd.request, cmd.callback) == cbox::CboxError::OK);
            payloadToMessage(cmd, message);

            CHECK(message.ShortDebugString() ==
                  "sensorId: 100 "
                  "setting: 86016 "
                  "value: 102400 "
                  "settingEnabled: true "
                  "storedSetting: 86016 "
                  "filter: FILTER_3m "
                  "filterThreshold: 2048 "
                  "valueUnfiltered: 102400");
        }
    }
}
