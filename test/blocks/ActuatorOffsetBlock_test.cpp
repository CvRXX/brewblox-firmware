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

#include "TestHelpers.h"
#include "blocks/ActuatorOffsetBlock.h"
#include "blocks/SetpointSensorPairBlock.h"
#include "blocks/TempSensorMockBlock.h"
#include "brewblox_particle.hpp"
#include "cbox/Box.h"
#include "control/Temperature.h"
#include "proto/ActuatorOffset_test.pb.h"
#include "proto/SetpointSensorPair_test.pb.h"
#include "proto/TempSensorMock_test.pb.h"

SCENARIO("A Blox ActuatorOffset object can be created from streamed protobuf data")
{
    cbox::objects.clearAll();
    setupSystemBlocks();
    cbox::update(0);

    // Create mock sensor 1
    {
        auto cmd = cbox::TestCommand(100, TempSensorMockBlock::staticTypeId());
        auto message = blox_test::TempSensorMock::Block();
        message.set_setting(cnl::unwrap(temp_t(21.0)));
        message.set_connected(true);

        serializeToRequest(cmd, message);
        CHECK(cbox::createObject(cmd) == cbox::CboxError::OK);
    }

    // Create pair 1 (target)
    {
        auto cmd = cbox::TestCommand(101, SetpointSensorPairBlock::staticTypeId());
        auto message = blox_test::SetpointSensorPair::Block();
        message.set_sensorid(100);
        message.set_storedsetting(cnl::unwrap(temp_t(20.0)));
        message.set_settingenabled(true);

        serializeToRequest(cmd, message);
        CHECK(cbox::createObject(cmd) == cbox::CboxError::OK);
    }

    // Create mock sensor 2
    {
        auto cmd = cbox::TestCommand(102, TempSensorMockBlock::staticTypeId());
        auto message = blox_test::TempSensorMock::Block();
        message.set_setting(cnl::unwrap(temp_t(27.0)));
        message.set_connected(true);

        serializeToRequest(cmd, message);
        CHECK(cbox::createObject(cmd) == cbox::CboxError::OK);
    }

    // Create pair 2 (reference)
    {
        auto cmd = cbox::TestCommand(103, SetpointSensorPairBlock::staticTypeId());
        auto message = blox_test::SetpointSensorPair::Block();
        message.set_sensorid(102);
        message.set_storedsetting(cnl::unwrap(temp_t(20.0)));
        message.set_settingenabled(true);

        serializeToRequest(cmd, message);
        CHECK(cbox::createObject(cmd) == cbox::CboxError::OK);
    }

    // Create actuator
    {
        auto cmd = cbox::TestCommand(104, ActuatorOffsetBlock::staticTypeId());
        auto message = blox_test::ActuatorOffset::Block();
        message.set_targetid(101);
        message.set_referenceid(103);
        message.set_referencesettingorvalue(blox_test::ActuatorOffset::ReferenceKind(ActuatorOffset::ReferenceKind::SETTING));
        message.set_desiredsetting(cnl::unwrap(ActuatorAnalog::value_t(12)));
        message.set_enabled(true);

        serializeToRequest(cmd, message);
        CHECK(cbox::createObject(cmd) == cbox::CboxError::OK);
    }

    cbox::update(0);

    // Read actuator
    {
        auto cmd = cbox::TestCommand(104, ActuatorOffsetBlock::staticTypeId());
        auto message = blox_test::ActuatorOffset::Block();
        CHECK(cbox::readObject(cmd) == cbox::CboxError::OK);
        parseFromResponse(cmd, message);
        CHECK(message.ShortDebugString() ==
              "targetId: 101 referenceId: 103 "
              "setting: 49152 value: 4096 " // setting is 12 (setpoint difference), value is 1 (21 - 20)
              "drivenTargetId: 101 enabled: true "
              "desiredSetting: 49152");
    }

    // Read target pair
    {
        auto cmd = cbox::TestCommand(101, SetpointSensorPairBlock::staticTypeId());
        auto message = blox_test::SetpointSensorPair::Block();
        CHECK(cbox::readObject(cmd) == cbox::CboxError::OK);
        parseFromResponse(cmd, message);
        CHECK(message.ShortDebugString() ==
              "sensorId: 100 "
              "setting: 131072 "
              "value: 86016 "
              "settingEnabled: true "
              "storedSetting: 131072 "
              "filterThreshold: 20480 "
              "valueUnfiltered: 86016"); // setting 32, value 21 (setpoint adjusted to 20 + 12)
    }

    // Read reference pair
    {
        auto cmd = cbox::TestCommand(103, SetpointSensorPairBlock::staticTypeId());
        auto message = blox_test::SetpointSensorPair::Block();
        CHECK(cbox::readObject(cmd) == cbox::CboxError::OK);
        parseFromResponse(cmd, message);
        CHECK(message.ShortDebugString() ==
              "sensorId: 102 "
              "setting: 81920 "
              "value: 110592 "
              "settingEnabled: true "
              "storedSetting: 81920 "
              "filterThreshold: 20480 "
              "valueUnfiltered: 110592"); // 20, 27 (unaffected)
    }

    AND_WHEN("The reference setpoint is disabled")
    {
        auto writeCmd = cbox::TestCommand(103, SetpointSensorPairBlock::staticTypeId());
        auto writeMsg = blox_test::SetpointSensorPair::Block();
        writeMsg.set_storedsetting(cnl::unwrap(temp_t(20.0)));
        writeMsg.set_settingenabled(false);
        serializeToRequest(writeCmd, writeMsg);
        CHECK(cbox::writeObject(writeCmd) == cbox::CboxError::OK);

        cbox::update(5000);

        THEN("The actuator is not driving the target setpoint and setting and value are stripped")
        {
            auto readCmd = cbox::TestCommand(104, ActuatorOffsetBlock::staticTypeId());
            CHECK(cbox::readObject(readCmd) == cbox::CboxError::OK);

            auto readMsg = blox_test::ActuatorOffset::Block();
            parseFromResponse(readCmd, readMsg);

            CHECK(readMsg.ShortDebugString() ==
                  "targetId: 101 "
                  "referenceId: 103 "
                  "enabled: true "
                  "desiredSetting: 49152 "
                  "strippedFields: 7 "
                  "strippedFields: 6");
        }
    }
}
