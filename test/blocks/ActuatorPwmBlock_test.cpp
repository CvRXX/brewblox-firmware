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
#include "blocks/ActuatorPwmBlock.h"
#include "blocks/DigitalActuatorBlock.h"
#include "brewblox_particle.hpp"
#include "cbox/Box.h"
#include "proto/ActuatorPwm_test.pb.h"
#include "proto/DigitalActuator_test.pb.h"

SCENARIO("An ActuatorPwm object can be created from protobuf data")
{
    cbox::objects.clearAll();
    setupSystemBlocks();
    cbox::update(0);

    auto actId = cbox::obj_id_t(100);
    auto pwmId = cbox::obj_id_t(101);
    auto sparkPinsId = cbox::obj_id_t(19); // system object 19 is Spark IO pins

    // Create digital actuator with Spark pin as target
    {
        auto cmd = cbox::TestCommand(actId, DigitalActuatorBlock::staticTypeId());
        auto message = blox_test::DigitalActuator::Block();

        message.set_hwdevice(sparkPinsId);
        message.set_channel(1);
        message.set_state(blox_test::IoArray::DigitalState::Inactive);

        serializeToRequest(cmd, message);
        CHECK(cbox::createObject(cmd) == cbox::CboxError::OK);
    }

    // Create PWM actuator
    {
        auto cmd = cbox::TestCommand(pwmId, ActuatorPwmBlock::staticTypeId());
        auto message = blox_test::ActuatorPwm::Block();

        message.set_actuatorid(actId); // predefined system object for pin actuator
        message.set_desiredsetting(cnl::unwrap(ActuatorAnalog::value_t(20)));
        message.set_period(4000);
        message.set_enabled(true);
        auto c = message.mutable_constrainedby()->add_constraints();
        c->set_min(cnl::unwrap(ActuatorAnalog::value_t(10)));

        serializeToRequest(cmd, message);
        CHECK(cbox::createObject(cmd) == cbox::CboxError::OK);
    }

    cbox::update(5000);

    // Read PWM actuator
    {
        auto cmd = cbox::TestCommand(pwmId, ActuatorPwmBlock::staticTypeId());
        auto message = blox_test::ActuatorPwm::Block();

        CHECK(cbox::readObject(cmd) == cbox::CboxError::OK);
        parseFromResponse(cmd, message);

        CHECK(message.ShortDebugString() ==
              "actuatorId: 100 "
              "period: 4000 "
              "setting: 81920 "
              "value: 36404 "
              "constrainedBy { constraints { min: 40960 } } "
              "drivenActuatorId: 100 "
              "enabled: true "
              "desiredSetting: 81920");
    }
}
