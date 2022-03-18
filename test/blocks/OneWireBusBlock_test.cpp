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

#include "TestHelpers.hpp"
#include "blocks/Block.hpp"
#include "blocks/OneWireBusBlock.hpp"
#include "cbox/Box.hpp"
#include "cbox/DataStream.hpp"
#include "cbox/Object.hpp"
#include "proto/OneWireBus_test.pb.h"
#include "spark/Brewblox.hpp"

SCENARIO("A Blox OneWireBus can stream a variable number of found addresses")
{

    GIVEN("A Blox OneWireBus")
    {
        cbox::objects.clearAll();
        setupSystemBlocks();
        cbox::update(0);
        cbox::obj_id_t owId(4);

        WHEN("it is encoded to a buffer")
        {
            auto cmd = cbox::TestCommand(owId, OneWireBusBlock::staticTypeId());
            auto message = blox_test::OneWireBus::Block();

            CHECK(cbox::readBlock(cmd.request, cmd.callback) == cbox::CboxError::OK);
            payloadToMessage(cmd, message);

            INFO(message.ShortDebugString());
        }

        WHEN("a family search command is streamed in")
        {
            auto cmd = cbox::TestCommand(owId, OneWireBusBlock::staticTypeId());
            auto message = blox_test::OneWireBus::Block();

            auto owCmd = message.mutable_command();
            owCmd->set_opcode(2);  // OneWire search
            owCmd->set_data(0x28); // family code for onewire temp sensors

            messageToPayload(cmd, message);
            CHECK(cbox::writeBlock(cmd.request, cmd.callback) == cbox::CboxError::OK);

            auto respMessage = blox_test::OneWireBus::Block();
            payloadToMessage(cmd, respMessage);

            INFO(respMessage.ShortDebugString());
            CHECK(respMessage.address_size() == 3); // temp sensors declared in theOneWire()
        }
    }
}
