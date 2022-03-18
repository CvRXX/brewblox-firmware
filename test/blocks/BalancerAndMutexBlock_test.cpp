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
#include "blocks/BalancerBlock.h"
#include "blocks/DigitalActuatorBlock.h"
#include "blocks/MutexBlock.h"
#include "cbox/Box.h"
#include "proto/ActuatorPwm_test.pb.h"
#include "proto/Balancer_test.pb.h"
#include "proto/DigitalActuator_test.pb.h"
#include "proto/Mutex_test.pb.h"
#include "spark/Brewblox.h"

SCENARIO("Two pin actuators are constrained by a mutex", "[balancer, mutex]")
{
    cbox::objects.clearAll();
    setupSystemBlocks();
    cbox::update(0);

    auto mutexId = cbox::obj_id_t(101);
    auto pin1Id = cbox::obj_id_t(102);
    auto pin2Id = cbox::obj_id_t(103);

    // Create mutex
    {
        auto cmd = cbox::TestCommand(mutexId, MutexBlock::staticTypeId());
        auto message = blox_test::Mutex::Block();

        message.set_differentactuatorwait(100);

        messageToPayload(cmd, message);
        CHECK(cbox::createBlock(cmd.request, cmd.callback) == cbox::CboxError::OK);
    }

    // Create/set digital actuator helper
    auto setPin = [mutexId, pin1Id, pin2Id](uint8_t chan, blox_test::IoArray::DigitalState state, bool firstCreate = false) {
        auto cmd = cbox::TestCommand(chan == 1 ? pin1Id : pin2Id, DigitalActuatorBlock::staticTypeId());
        auto message = blox_test::DigitalActuator::Block();

        message.set_desiredstate(state);
        message.set_invert(false);
        message.set_hwdevice(19);
        message.set_channel(chan);
        auto constraintPtr = message.mutable_constrainedby()->add_constraints();
        constraintPtr->set_mutex(mutexId);

        messageToPayload(cmd, message);
        if (firstCreate) {
            CHECK(cbox::createBlock(cmd.request, cmd.callback) == cbox::CboxError::OK);
        } else {
            CHECK(cbox::writeBlock(cmd.request, cmd.callback) == cbox::CboxError::OK);
        }
    };

    // configure pin actuator 1
    setPin(1, blox_test::IoArray::DigitalState::Active, true);
    // configure pin actuator 2
    setPin(2, blox_test::IoArray::DigitalState::Active, true);

    THEN("The objects read back as expected")
    {
        THEN("Read mutex")
        {
            auto cmd = cbox::TestCommand(mutexId, MutexBlock::staticTypeId());
            auto message = blox_test::Mutex::Block();

            CHECK(cbox::readBlock(cmd.request, cmd.callback) == cbox::CboxError::OK);
            payloadToMessage(cmd, message);

            CHECK(message.ShortDebugString() ==
                  "differentActuatorWait: 100 "
                  "waitRemaining: 100");
        }

        THEN("Read pin actuator 1, which is active")
        {
            auto cmd = cbox::TestCommand(pin1Id, DigitalActuatorBlock::staticTypeId());
            auto message = blox_test::DigitalActuator::Block();

            CHECK(cbox::readBlock(cmd.request, cmd.callback) == cbox::CboxError::OK);
            payloadToMessage(cmd, message);

            CHECK(message.ShortDebugString() ==
                  "hwDevice: 19 "
                  "channel: 1 "
                  "state: STATE_ACTIVE "
                  "constrainedBy { constraints { mutexed { mutexId: 101 hasLock: true } } } "
                  "desiredState: STATE_ACTIVE");
        }

        THEN("Read pin actuator 2, which is constrained and inactive")
        {
            auto cmd = cbox::TestCommand(pin2Id, DigitalActuatorBlock::staticTypeId());
            auto message = blox_test::DigitalActuator::Block();

            CHECK(cbox::readBlock(cmd.request, cmd.callback) == cbox::CboxError::OK);
            payloadToMessage(cmd, message);

            CHECK(message.ShortDebugString() ==
                  "hwDevice: 19 "
                  "channel: 2 "
                  "constrainedBy { constraints { mutexed { mutexId: 101 } remaining: 101 } } "
                  "desiredState: STATE_ACTIVE");
        }
    }

    WHEN("actuator 2 is toggled, it remains constrained while actuator 1 is active")
    {
        auto readPin = [](cbox::obj_id_t id) {
            auto cmd = cbox::TestCommand(id, DigitalActuatorBlock::staticTypeId());
            auto message = blox_test::DigitalActuator::Block();

            CHECK(cbox::readBlock(cmd.request, cmd.callback) == cbox::CboxError::OK);
            payloadToMessage(cmd, message);

            return message.state();
        };

        setPin(1, blox_test::IoArray::DigitalState::Active);
        setPin(2, blox_test::IoArray::DigitalState::Inactive);
        cbox::update(1);

        setPin(2, blox_test::IoArray::DigitalState::Active);
        CHECK(readPin(pin2Id) == blox_test::IoArray::DigitalState::Inactive);
        cbox::update(2);

        setPin(2, blox_test::IoArray::DigitalState::Active);
        CHECK(readPin(pin2Id) == blox_test::IoArray::DigitalState::Inactive);

        setPin(2, blox_test::IoArray::DigitalState::Inactive);
        CHECK(readPin(pin2Id) == blox_test::IoArray::DigitalState::Inactive);
        cbox::update(3);

        setPin(2, blox_test::IoArray::DigitalState::Active);
        CHECK(readPin(pin2Id) == blox_test::IoArray::DigitalState::Inactive);
        cbox::update(4);

        AND_WHEN("Actuator 1 is turned OFF")
        {
            setPin(1, blox_test::IoArray::DigitalState::Inactive);
            CHECK(readPin(pin1Id) == blox_test::IoArray::DigitalState::Inactive);
            cbox::update(5);

            THEN("Actuator 2 can only turn on after the minimum wait time has passed")
            {
                cbox::update(6);
                setPin(2, blox_test::IoArray::DigitalState::Active);
                CHECK(readPin(pin2Id) == blox_test::IoArray::DigitalState::Inactive);

                cbox::update(10);
                setPin(2, blox_test::IoArray::DigitalState::Active);
                CHECK(readPin(pin2Id) == blox_test::IoArray::DigitalState::Inactive);

                cbox::update(103);
                setPin(2, blox_test::IoArray::DigitalState::Active);
                CHECK(readPin(pin2Id) == blox_test::IoArray::DigitalState::Inactive);

                cbox::update(104);
                setPin(2, blox_test::IoArray::DigitalState::Active);
                CHECK(readPin(pin2Id) == blox_test::IoArray::DigitalState::Active);
            }

            THEN("Activating actuator 1 resets the wait time")
            {
                setPin(2, blox_test::IoArray::DigitalState::Active);
                CHECK(readPin(pin2Id) == blox_test::IoArray::DigitalState::Inactive);

                cbox::update(10);
                setPin(2, blox_test::IoArray::DigitalState::Active);
                CHECK(readPin(pin2Id) == blox_test::IoArray::DigitalState::Inactive);

                cbox::update(50);
                setPin(1, blox_test::IoArray::DigitalState::Active);
                CHECK(readPin(pin1Id) == blox_test::IoArray::DigitalState::Active);

                cbox::update(60);
                setPin(1, blox_test::IoArray::DigitalState::Inactive);
                CHECK(readPin(pin1Id) == blox_test::IoArray::DigitalState::Inactive);

                cbox::update(61);
                setPin(2, blox_test::IoArray::DigitalState::Active);
                CHECK(readPin(pin2Id) == blox_test::IoArray::DigitalState::Inactive);

                cbox::update(120);
                setPin(2, blox_test::IoArray::DigitalState::Active);
                CHECK(readPin(pin2Id) == blox_test::IoArray::DigitalState::Inactive);

                cbox::update(155);
                setPin(2, blox_test::IoArray::DigitalState::Active);
                CHECK(readPin(pin2Id) == blox_test::IoArray::DigitalState::Inactive);

                cbox::update(160);
                setPin(2, blox_test::IoArray::DigitalState::Active);
                CHECK(readPin(pin2Id) == blox_test::IoArray::DigitalState::Active);
            }
        }
    }

    WHEN("The pins are driven by 2 balanced PWM actuators")
    {
        auto balancerId = cbox::obj_id_t(200);
        auto pwm1Id = cbox::obj_id_t(201);
        auto pwm2Id = cbox::obj_id_t(202);

        // Create balancer
        {
            auto cmd = cbox::TestCommand(balancerId, BalancerBlock::staticTypeId());
            auto message = blox_test::Balancer::Block();

            messageToPayload(cmd, message);
            CHECK(cbox::createBlock(cmd.request, cmd.callback) == cbox::CboxError::OK);
        }

        // Create pwm actuator 1
        {
            auto cmd = cbox::TestCommand(pwm1Id, ActuatorPwmBlock::staticTypeId());
            auto message = blox_test::ActuatorPwm::Block();

            message.set_actuatorid(pin1Id);
            message.set_desiredsetting(cnl::unwrap(ActuatorAnalog::value_t(80)));
            message.set_period(4000);
            message.set_enabled(true);

            auto c = message.mutable_constrainedby()->add_constraints();
            auto balanced = new blox_test::Constraints::Balanced();
            balanced->set_balancerid(balancerId);
            c->set_allocated_balanced(balanced);

            messageToPayload(cmd, message);
            CHECK(cbox::createBlock(cmd.request, cmd.callback) == cbox::CboxError::OK);
        }

        // Create pwm actuator 2
        {
            auto cmd = cbox::TestCommand(pwm2Id, ActuatorPwmBlock::staticTypeId());
            auto message = blox_test::ActuatorPwm::Block();

            message.set_actuatorid(pin2Id);
            message.set_desiredsetting(cnl::unwrap(ActuatorAnalog::value_t(80)));
            message.set_period(4000);
            message.set_enabled(true);

            auto c = message.mutable_constrainedby()->add_constraints();
            auto balanced = new blox_test::Constraints::Balanced();
            balanced->set_balancerid(balancerId);
            c->set_allocated_balanced(balanced);

            messageToPayload(cmd, message);
            CHECK(cbox::createBlock(cmd.request, cmd.callback) == cbox::CboxError::OK);
        }

        cbox::update(0);
        cbox::update(1000);

        // Read balancer
        {
            auto cmd = cbox::TestCommand(balancerId, BalancerBlock::staticTypeId());
            auto message = blox_test::Balancer::Block();

            CHECK(cbox::readBlock(cmd.request, cmd.callback) == cbox::CboxError::OK);
            payloadToMessage(cmd, message);

            CHECK(message.ShortDebugString() ==
                  "clients { id: 1 requested: 327680 granted: 204800 } "  // 80*4096, 50*4096
                  "clients { id: 2 requested: 327680 granted: 204800 }"); // 80*4096, 50*4096
        }

        // Read pwm actuator 1
        {
            auto cmd = cbox::TestCommand(pwm1Id, ActuatorPwmBlock::staticTypeId());
            auto message = blox_test::ActuatorPwm::Block();

            CHECK(cbox::readBlock(cmd.request, cmd.callback) == cbox::CboxError::OK);
            payloadToMessage(cmd, message);

            CHECK(message.ShortDebugString() ==
                  "actuatorId: 102 "
                  "period: 4000 setting: 204800 "
                  "constrainedBy { "
                  "constraints { "
                  "balanced { balancerId: 200 granted: 204800 id: 1 } "
                  "limiting: true } } "
                  "drivenActuatorId: 102 "
                  "enabled: true "
                  "desiredSetting: 327680");
        }

        // Read pwm actuator 2
        {
            auto cmd = cbox::TestCommand(pwm2Id, ActuatorPwmBlock::staticTypeId());
            auto message = blox_test::ActuatorPwm::Block();

            CHECK(cbox::readBlock(cmd.request, cmd.callback) == cbox::CboxError::OK);
            payloadToMessage(cmd, message);

            CHECK(message.ShortDebugString() ==
                  "actuatorId: 103 "
                  "period: 4000 setting: 204800 "
                  "constrainedBy { "
                  "constraints { "
                  "balanced { balancerId: 200 granted: 204800 id: 2 } "
                  "limiting: true } } "
                  "drivenActuatorId: 103 "
                  "enabled: true "
                  "desiredSetting: 327680");
        }

        // run for a while
        for (ticks_millis_t now = 1001; now < 50000; ++now) {
            cbox::update(now);
        }

        // Read pwm actuator 1
        {
            auto cmd = cbox::TestCommand(pwm1Id, ActuatorPwmBlock::staticTypeId());
            auto message = blox_test::ActuatorPwm::Block();

            CHECK(cbox::readBlock(cmd.request, cmd.callback) == cbox::CboxError::OK);
            payloadToMessage(cmd, message);

            CHECK(message.value() == Approx(cnl::unwrap(ActuatorAnalog::value_t(50))).epsilon(0.05));
        }

        // Read pwm actuator 2
        {
            auto cmd = cbox::TestCommand(pwm2Id, ActuatorPwmBlock::staticTypeId());
            auto message = blox_test::ActuatorPwm::Block();

            CHECK(cbox::readBlock(cmd.request, cmd.callback) == cbox::CboxError::OK);
            payloadToMessage(cmd, message);

            CHECK(message.value() == Approx(cnl::unwrap(ActuatorAnalog::value_t(50))).epsilon(0.05));
        }
    }
}
