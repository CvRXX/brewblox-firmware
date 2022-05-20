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

#include "TestHelpers.hpp"
#include "blocks/DS2408Block.hpp"
#include "blocks/DS2413Block.hpp"
#include "blocks/TempSensorOneWireBlock.hpp"
#include "cbox/Box.hpp"
#include "cbox/CboxPtr.hpp"
#include "proto/TempSensorOneWire_test.pb.h"
#include "spark/Brewblox.hpp"
#include <sstream>

SCENARIO("Auto discovery of OneWire devices")
{
    cbox::getObjects().clearAll();
    platform::particle::setupSystemBlocks();
    cbox::update(0);

    WHEN("An object discovery command is received")
    {
        auto discoverCmd = cbox::TestCommand();
        CHECK(cbox::discoverBlocks(discoverCmd.callback) == cbox::CboxError::OK);

        THEN("New objects are discovered")
        {
            REQUIRE(discoverCmd.responses.size() == 5);
            CHECK(discoverCmd.responses.at(0).blockType == TempSensorOneWireBlock::staticTypeId());
            CHECK(discoverCmd.responses.at(1).blockType == TempSensorOneWireBlock::staticTypeId());
            CHECK(discoverCmd.responses.at(2).blockType == TempSensorOneWireBlock::staticTypeId());
            CHECK(discoverCmd.responses.at(3).blockType == DS2413Block::staticTypeId());
            CHECK(discoverCmd.responses.at(4).blockType == DS2408Block::staticTypeId());

            AND_THEN("These objects can be used as temp sensor")
            {
                auto d1 = cbox::CboxPtr<TempSensor>(100);
                auto d2 = cbox::CboxPtr<TempSensor>(101);
                auto d3 = cbox::CboxPtr<TempSensor>(102);
                auto d4 = cbox::CboxPtr<DS2413Block>(103);
                auto d5 = cbox::CboxPtr<DS2408Block>(104);

                CHECK(d1.lock());
                CHECK(d2.lock());
                CHECK(d3.lock());
                CHECK(d4.lock());
                CHECK(d5.lock());
            }
        }

        AND_WHEN("The command is given for the second time")
        {
            auto repeatedDiscoverCmd = cbox::TestCommand();
            CHECK(cbox::discoverBlocks(repeatedDiscoverCmd.callback) == cbox::CboxError::OK);

            THEN("No new objects are discovered")
            {
                CHECK(repeatedDiscoverCmd.responses.size() == 0);
            }
        }

        AND_WHEN("One of the sensors is removed")
        {
            auto removeCmd = cbox::TestCommand(101, 0);
            CHECK(cbox::deleteBlock(removeCmd.request) == cbox::CboxError::OK);

            THEN("It will be discovered again")
            {
                auto rediscoverCmd = cbox::TestCommand();
                CHECK(cbox::discoverBlocks(rediscoverCmd.callback) == cbox::CboxError::OK);
                CHECK(rediscoverCmd.responses.size() == 1);
            }
        }
    }
}
