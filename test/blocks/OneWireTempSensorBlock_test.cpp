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
#include "blocks/TempSensorOneWireBlock.h"
#include "cbox/Box.h"
#include "proto/TempSensorOneWire_test.pb.h"
#include "spark/Brewblox.h"
#include <sstream>

SCENARIO("A TempSensorOneWireBlock")
{
    WHEN("a TempSensorOneWire object is created")
    {
        cbox::objects.clearAll();
        setupSystemBlocks();
        cbox::update(0);

        // Create sensor
        {
            auto cmd = cbox::TestCommand(100, TempSensorOneWireBlock::staticTypeId());
            auto message = blox_test::TempSensorOneWire::Block();

            message.set_address(0x7E11'1111'1111'1128);
            message.set_offset(2048);
            message.set_value(123); // value is not writable, so this should not have effect
            message.set_onewirebusid(4);

            messageToPayload(cmd, message);
            CHECK(cbox::createBlock(cmd.request, cmd.callback) == cbox::CboxError::OK);
        }

        THEN("The returned protobuf data is as expected")
        {
            auto cmd = cbox::TestCommand(100, TempSensorOneWireBlock::staticTypeId());
            auto message = blox_test::TempSensorOneWire::Block();

            // When the sensor is not yet updated the value is invalid and therefore
            // added to stripped fields to distinguish from value zero
            CHECK(cbox::readBlock(cmd.request, cmd.callback) == cbox::CboxError::OK);
            payloadToMessage(cmd, message);

            CHECK(message.ShortDebugString() ==
                  "offset: 2048 "
                  "address: 9084060688381448488 "
                  "oneWireBusId: 4 "
                  "strippedFields: 1");

            cbox::update(1000);

            // After an update, the sensor returns a valid temperature
            cmd.responses.clear();
            CHECK(cbox::readBlock(cmd.request, cmd.callback) == cbox::CboxError::OK);
            payloadToMessage(cmd, message);

            CHECK(message.ShortDebugString() ==
                  "value: 83968 " // 20*4096 + 2048
                  "offset: 2048 "
                  "address: 9084060688381448488 "
                  "oneWireBusId: 4");

            AND_THEN("The writable settings match what was sent")
            {
                auto lookup = cbox::CboxPtr<TempSensorOneWireBlock>(100);
                auto sensorPtr = lookup.lock();
                REQUIRE(sensorPtr);
                CHECK(sensorPtr->get().address() == OneWireAddress(0x7E11'1111'1111'1128));
                CHECK(sensorPtr->get().getCalibration() == temp_t(0.5));

                AND_THEN("The values that are not writable are unchanged")
                {
                    CHECK(sensorPtr->get().value() == temp_t(20.5));
                    CHECK(sensorPtr->get().valid() == true);
                }
            }
        }

        THEN("An incorrect busId is corrected during discovery")
        {
            auto ptr = cbox::CboxPtr<OneWireDeviceBlock>(100);
            auto block = ptr.lock();
            block->setBusId(0);

            cbox::discoverBlocks();

            CHECK(block->getBusId() == 4);
        }
    }
}
