/*
 * Copyright 2018 BrewPi
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

#include "AppTicks.hpp"
#include "TestHelpers.hpp"
#include "blocks/SetpointProfileBlock.hpp"
#include "blocks/SetpointSensorPairBlock.hpp"
#include "blocks/TempSensorMockBlock.hpp"
#include "blocks/TicksBlock.hpp"
#include "cbox/Box.hpp"
#include "proto/SetpointProfile_test.pb.h"
#include "proto/SetpointSensorPair_test.pb.h"
#include "proto/TempSensorMock_test.pb.h"
#include "proto/Ticks_test.pb.h"
#include "spark/Brewblox.hpp"
#include <catch.hpp>
#include <sstream>

SCENARIO("A SetpointProfile block")
{
    WHEN("a SetpointProfileBlock is created")
    {
        ticks.ticksImpl().reset(0);
        ticks.setUtc(0);

        cbox::getObjects().clearAll();
        platform::particle::setupSystemBlocks();

        auto sensorId = cbox::obj_id_t(100);
        auto setpointId = cbox::obj_id_t(101);
        auto profileId = cbox::obj_id_t(102);

        auto update = [](cbox::update_t now) {
            ticks.ticksImpl().reset(now);
            cbox::update(now);
        };

        update(0);

        // Create sensor
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
            message.set_storedsetting(cnl::unwrap(temp_t(99)));
            message.set_enabled(true);

            messageToPayload(cmd, message);
            CHECK(cbox::createBlock(cmd.request, cmd.callback) == cbox::CboxError::OK);
        }

        // Create profile
        {
            auto cmd = cbox::TestCommand(profileId, SetpointProfileBlock::staticTypeId());
            auto message = blox_test::SetpointProfile::Block();

            message.set_targetid(setpointId);
            message.set_enabled(true);
            message.set_start(20'000);
            {
                auto newPoint = message.add_points();
                newPoint->set_time(10);
                newPoint->set_temperature(cnl::unwrap(temp_t(20)));
            }

            {
                auto newPoint = message.add_points();
                newPoint->set_time(20);
                newPoint->set_temperature(cnl::unwrap(temp_t(21)));
            }

            messageToPayload(cmd, message);
            CHECK(cbox::createBlock(cmd.request, cmd.callback) == cbox::CboxError::OK);
        }

        update(10'000);

        auto pairLookup = cbox::CboxPtr<SetpointSensorPairBlock>(101);
        auto pairPtr = pairLookup.lock();
        auto profileLookup = cbox::CboxPtr<SetpointProfileBlock>(102);
        auto profilePtr = profileLookup.lock();
        auto claimLookup = cbox::CboxPtr<cbox::Claimable>(101);
        auto claimPtr = claimLookup.lock();

        REQUIRE(profilePtr);
        REQUIRE(pairPtr);
        REQUIRE(claimPtr);

        WHEN("The box has not received the current time (in seconds since epoch")
        {
            THEN("It does not change the setpoint")
            {
                CHECK(pairPtr->get().setting() == temp_t(99));
            }

            THEN("It does not claim the target setpoint")
            {
                CHECK(claimPtr->claimedBy() == 0);
            }
        }

        WHEN("The box has received the current time (in seconds since epoch")
        {
            ticks.setUtc(20'000);
            update(25000); // system is running for 25 seconds, so seconds since epoch should be 20'015 now

            THEN("It claims the target setpoint")
            {
                CHECK(claimPtr->claimedBy() == 102);
                AND_THEN("Another claiming cbox ptr cannot get write access to the setpoint")
                {
                    auto secondLookup = cbox::CboxPtr<SetpointSensorPairBlock>(101);
                    auto secondClaimer = cbox::CboxClaimingPtr<SetpointSensorPairBlock>(secondLookup);
                    CHECK(secondClaimer.lock() == nullptr);

                    AND_WHEN("The profile is disabled")
                    {
                        profilePtr->get().enabler.set(false);
                        update(10'1000);
                        THEN("It no longer claims the setpoint, and the second claimer can get write access")
                        {
                            CHECK(claimPtr->claimedBy() == 0);
                            CHECK(secondClaimer.lock() != nullptr);
                        }
                    }
                }
            }

            THEN("The setpoint is valid")
            {
                CHECK(pairPtr->get().setting().has_value() == true);
            }
            AND_THEN("The setting is correctly interpolated")
            {
                CHECK(pairPtr->get().setting() == temp_t(20.5)); // halfway between points
            }
            AND_WHEN("The SetpointProfile block streams out protobuf settings, the data is as expected")
            {
                auto cmd = cbox::TestCommand(profileId, SetpointProfileBlock::staticTypeId());
                auto message = blox_test::SetpointProfile::Block();

                CHECK(cbox::readBlock(cmd.request, cmd.callback) == cbox::CboxError::OK);
                payloadToMessage(cmd, message);

                // 20.5 * 4096 = 83968
                CHECK(message.ShortDebugString() ==
                      "points { time: 10 temperature: 81920 } "
                      "points { time: 20 temperature: 86016 } "
                      "enabled: true "
                      "targetId: 101 "
                      "drivenTargetId: 101 "
                      "start: 20000");
            }
        }

        WHEN("A point at 0s and temp 0.0 is written, it does not disappear")
        {

            auto cmd = cbox::TestCommand(profileId, SetpointProfileBlock::staticTypeId());
            auto message = blox_test::SetpointProfile::Block();

            message.set_targetid(101);
            message.set_enabled(true);
            message.set_start(20'000);
            {
                auto newPoint = message.add_points();
                newPoint->set_time(0);
                newPoint->set_temperature(cnl::unwrap(temp_t(0)));
            }

            {
                auto newPoint = message.add_points();
                newPoint->set_time(20);
                newPoint->set_temperature(cnl::unwrap(temp_t(21)));
            }

            messageToPayload(cmd, message);
            CHECK(cbox::writeBlock(cmd.request, cmd.callback) == cbox::CboxError::OK);

            auto reply = blox_test::SetpointProfile::Block();
            payloadToMessage(cmd, reply);

            CHECK(reply.ShortDebugString() ==
                  "points { temperature: 0 } "
                  "points { time: 20 temperature: 86016 } "
                  "enabled: true "
                  "targetId: 101 "
                  "drivenTargetId: 101 "
                  "start: 20000");
        }
    }
}
