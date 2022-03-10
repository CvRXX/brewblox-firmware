/*
 * Copyright 2017 BrewPi
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

#include <catch.hpp>

#include "TestHelpers.h"
#include "blocks/Block.h"
#include "blocks/OneWireBusBlock.h"
#include "cbox/Box.h"
#include "cbox/DataStream.h"
#include "cbox/Object.h"
#include "proto/OneWireBus_test.pb.h"
#include "spark/Brewblox.h"

SCENARIO("A Blox OneWireBus can stream a variable number of found addresses")
{

    GIVEN("A Blox OneWireBus")
    {
        cbox::getObjects().clearAll();
        setupSystemBlocks();
        cbox::update(0);
        cbox::obj_id_t owId(4);

        WHEN("it is encoded to a buffer")
        {
            auto cmd = cbox::TestCommand(owId, OneWireBusBlock::staticTypeId());
            auto message = blox_test::OneWireBus::Block();

            CHECK(cbox::readObject(cmd) == cbox::CboxError::OK);
            parseFromResponse(cmd, message);

            INFO(message.ShortDebugString());
        }

        WHEN("a family search command is streamed in")
        {
            auto cmd = cbox::TestCommand(owId, OneWireBusBlock::staticTypeId());
            auto message = blox_test::OneWireBus::Block();

            auto owCmd = message.mutable_command();
            owCmd->set_opcode(2);  // OneWire search
            owCmd->set_data(0x28); // family code for onewire temp sensors

            serializeToRequest(cmd, message);
            CHECK(cbox::writeObject(cmd) == cbox::CboxError::OK);

            auto respMessage = blox_test::OneWireBus::Block();
            parseFromResponse(cmd, respMessage);

            INFO(respMessage.ShortDebugString());
            CHECK(respMessage.address_size() == 3); // temp sensors declared in theOneWire()
        }
    }
}
