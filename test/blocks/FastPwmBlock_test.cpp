/*
 * Copyright 2022 BrewPi B.V.
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
#include "blocks/FastPwmBlock.hpp"
#include "cbox/Box.hpp"
#include "proto/FastPwm_test.pb.h"
#include "spark/Brewblox.hpp"

SCENARIO("A FastPwm object can be created from protobuf data")
{
    cbox::getObjects().clearAll();
    platform::particle::setupSystemBlocks();
    cbox::update(0);

    auto pwmId = cbox::obj_id_t(101);
    auto sparkPinsId = cbox::obj_id_t(19); // system object 19 is Spark IO pins

    // Create Fast PWM actuator
    {
        auto cmd = cbox::TestCommand(pwmId, FastPwmBlock::staticTypeId());
        auto message = blox_test::FastPwm::Block();

        message.set_hwdevice(sparkPinsId);
        message.set_channel(1);
        message.set_desiredsetting(cnl::unwrap(ActuatorAnalog::value_t(20)));
        message.set_frequency(blox_test::FastPwm::PwmFrequency::PWM_FREQ_100HZ);
        message.set_enabled(true);
        auto c = message.mutable_constrainedby()->add_constraints();
        c->set_min(cnl::unwrap(ActuatorAnalog::value_t(10)));

        messageToPayload(cmd, message);
        CHECK(cbox::createBlock(cmd.request, cmd.callback) == cbox::CboxError::OK);
    }

    cbox::update(5000);

    AND_THEN("It can be read")
    {

        auto cmd = cbox::TestCommand(pwmId, FastPwmBlock::staticTypeId());
        auto message = blox_test::FastPwm::Block();

        CHECK(cbox::readBlock(cmd.request, cmd.callback) == cbox::CboxError::OK);
        payloadToMessage(cmd, message);

        CHECK(message.ShortDebugString() ==
              "hwDevice: 19 "
              "channel: 1 "
              "frequency: PWM_FREQ_100HZ "
              "setting: 81920 "
              "desiredSetting: 81920 "
              "value: 81920 "
              "constrainedBy { constraints { min: 40960 } } "
              "enabled: true");
    }

    AND_WHEN("It is written below the min constraint")
    {
        auto cmd = cbox::TestCommand(pwmId, FastPwmBlock::staticTypeId());
        auto message = blox_test::FastPwm::Block();
        message.set_desiredsetting(cnl::unwrap(ActuatorAnalog::value_t(5)));

        messageToPayload(cmd, message, {blox_test::FastPwm::Block::kDesiredSettingFieldNumber});
        CHECK(cbox::writeBlock(cmd.request, cmd.callback) == cbox::CboxError::OK);

        cbox::update(5000);
        cbox::update(6000);
        cbox::update(7000);

        payloadToMessage(cmd, message);
        THEN("The minimum value is used")
        {
            CHECK(message.ShortDebugString() ==
                  "hwDevice: 19 "
                  "channel: 1 "
                  "frequency: PWM_FREQ_100HZ "
                  "setting: 40960 "
                  "desiredSetting: 20480 "
                  "value: 40960 "
                  "constrainedBy { constraints { min: 40960 limiting: true } } "
                  "enabled: true");
        }
    }
}
