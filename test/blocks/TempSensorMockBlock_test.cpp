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
#include "blocks/TempSensorMockBlock.hpp"
#include "cbox/Box.hpp"
#include "cbox/CboxPtr.hpp"
#include "control/Temperature.hpp"
#include "proto/TempSensorMock_test.pb.h"
#include "spark/Brewblox.hpp"

SCENARIO("A TempSensorMock block")
{
    cbox::objects.clearAll();
    platform::particle::setupSystemBlocks();
    cbox::update(0);

    auto sensorId = cbox::obj_id_t(100);

    {
        auto cmd = cbox::TestCommand(sensorId, TempSensorMockBlock::staticTypeId());
        auto message = blox_test::TempSensorMock::Block();

        message.set_setting(cnl::unwrap(temp_t(20.0)));
        message.set_connected(true);

        messageToPayload(cmd, message);
        CHECK(cbox::createBlock(cmd.request, cmd.callback) == cbox::CboxError::OK);
    }

    WHEN("The mock sensor value is changed to 25")
    {
        auto cboxPtr = cbox::CboxPtr<TempSensorMockBlock>(100);
        auto ptr = cboxPtr.lock();
        REQUIRE(ptr);

        ptr->get().setting(25);

        cbox::update(1000);

        THEN("The value that is read back is correct")
        {
            auto cmd = cbox::TestCommand(sensorId, TempSensorMockBlock::staticTypeId());
            auto message = blox_test::TempSensorMock::Block();

            CHECK(cbox::readBlock(cmd.request, cmd.callback) == cbox::CboxError::OK);
            payloadToMessage(cmd, message);

            CHECK(message.ShortDebugString() ==
                  "value: 102400 "
                  "connected: true "
                  "setting: 102400");
        }
    }

    WHEN("Fluctuations are set")
    {
        {
            auto cmd = cbox::TestCommand(sensorId, TempSensorMockBlock::staticTypeId());
            auto message = blox_test::TempSensorMock::Block();

            message.set_setting(cnl::unwrap(temp_t(20.0)));
            message.set_connected(true);

            {
                auto newFluct = message.add_fluctuations();
                newFluct->set_amplitude(cnl::unwrap(temp_t{2}));
                newFluct->set_period(2000);
            }

            {
                auto newFluct = message.add_fluctuations();
                newFluct->set_amplitude(cnl::unwrap(temp_t{3}));
                newFluct->set_period(3000);
            }

            messageToPayload(cmd, message);
            CHECK(cbox::writeBlock(cmd.request, cmd.callback) == cbox::CboxError::OK);
        }

        cbox::update(1000);

        THEN("The value that is read back is correct")
        {
            auto cmd = cbox::TestCommand(sensorId, TempSensorMockBlock::staticTypeId());
            auto message = blox_test::TempSensorMock::Block();

            CHECK(cbox::readBlock(cmd.request, cmd.callback) == cbox::CboxError::OK);
            payloadToMessage(cmd, message);

            CHECK(message.ShortDebugString() ==
                  "value: 91627 "
                  "connected: true "
                  "setting: 81920 "
                  "fluctuations { amplitude: 8192 period: 2000 } "
                  "fluctuations { amplitude: 12288 period: 3000 }");
        }
    }
}
