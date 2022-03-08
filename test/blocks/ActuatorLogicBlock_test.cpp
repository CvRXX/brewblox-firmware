/*
 * Copyright 2020 BrewPi B.V.
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
#include "blocks/ActuatorLogicBlock.h"
#include "blocks/DigitalActuatorBlock.h"
#include "blocks/SetpointSensorPairBlock.h"
#include "blocks/TempSensorMockBlock.h"
#include "brewblox_particle.hpp"
#include "cbox/Box.h"
#include "cbox/DataStreamIo.h"
#include "proto/ActuatorLogic_test.pb.h"
#include "proto/DigitalActuator_test.pb.h"
#include "proto/SetpointSensorPair_test.pb.h"
#include "proto/TempSensorMock_test.pb.h"
#include <sstream>

SCENARIO("Test", "[makelogicblock]")
{
    cbox::objects.clearAll();
    setupSystemBlocks();
    cbox::update(0);

    // acuators 101-105
    // sensors 111-115
    // setpoints 121-125
    // logic 130

    auto setAct = [](cbox::obj_id_t id, blox_test::IoArray::DigitalState state, bool firstCreate = false) -> cbox::CboxError {
        // configure digital actuator by writing to the object
        auto sparkPinsId = cbox::obj_id_t(19); // system object 19 is Spark IO pins

        cbox::TestCommand cmd(id, DigitalActuatorBlock::staticTypeId());

        auto message = blox_test::DigitalActuator::Block();
        message.set_hwdevice(sparkPinsId);
        message.set_channel(uint8_t(id - 100));
        message.set_desiredstate(state);

        serializeToRequest(cmd, message);

        if (firstCreate) {
            return cbox::createObject(cmd);
        } else {
            return cbox::writeObject(cmd);
        }
    };

    auto setSensor = [](cbox::obj_id_t id, temp_t setting, bool firstCreate = false) -> cbox::CboxError {
        auto cmd = cbox::TestCommand(id, TempSensorMockBlock::staticTypeId());
        auto message = blox_test::TempSensorMock::Block();

        message.set_setting(cnl::unwrap(setting));
        message.set_connected(true);

        serializeToRequest(cmd, message);

        if (firstCreate) {
            return cbox::createObject(cmd);
        } else {
            return cbox::writeObject(cmd);
        }
    };

    auto setSetpoint = [](cbox::obj_id_t id, temp_t setting, bool firstCreate = false) -> cbox::CboxError {
        auto cmd = cbox::TestCommand(id, SetpointSensorPairBlock::staticTypeId());
        auto message = blox_test::SetpointSensorPair::Block();

        message.set_sensorid(id - 10);
        message.set_settingenabled(true);
        message.set_storedsetting(cnl::unwrap(setting));
        message.set_filter(blox_test::SetpointSensorPair::FilterChoice::FILTER_NONE);
        message.set_filterthreshold(cnl::unwrap(temp_t(0.5)));

        serializeToRequest(cmd, message);

        if (firstCreate) {
            return cbox::createObject(cmd);
        } else {
            return cbox::writeObject(cmd);
        }
    };

    auto setLogic = [](blox_test::ActuatorLogic::Block& message, bool firstCreate = false) {
        auto cmd = cbox::TestCommand(130, ActuatorLogicBlock::staticTypeId());

        message.set_targetid(105);
        message.set_enabled(true);

        serializeToRequest(cmd, message);

        if (firstCreate) {
            cbox::createObject(cmd);
        } else {
            cbox::writeObject(cmd);
        }

        auto responseMsg = blox_test::ActuatorLogic::Block();
        parseFromResponse(cmd, responseMsg);
        return responseMsg;
    };

    // create 5 digital actuators
    for (cbox::obj_id_t i = 101; i <= 105; i++) {
        CHECK(setAct(i, blox_test::IoArray::DigitalState::Inactive, true) == cbox::CboxError::OK);
    }

    // create 5 mock sensors
    for (cbox::obj_id_t i = 111; i <= 115; i++) {
        CHECK(setSensor(i, temp_t{20}, true) == cbox::CboxError::OK);
    }

    // create 5 setpoints
    for (cbox::obj_id_t i = 121; i <= 125; i++) {
        CHECK(setSetpoint(i, temp_t{21}, true) == cbox::CboxError::OK);
    }

    // create logic block with emty logic
    auto message = blox_test::ActuatorLogic::Block();
    auto result = setLogic(message, true);
    CHECK(result.ShortDebugString() ==
          "targetId: 105 "
          "drivenTargetId: 105 "
          "enabled: true "
          "result: RESULT_EMPTY");

    WHEN("4 digital actuators are combined with various expressions")
    {
        auto message = blox_test::ActuatorLogic::Block();
        {
            auto d = message.add_digital();
            d->set_id(101);
            d->set_rhs(blox_test::IoArray::DigitalState::Active);
            d->set_op(blox_test::ActuatorLogic::DigitalOperator::OP_DESIRED_IS);
        }
        {
            auto d = message.add_digital();
            d->set_id(102);
            d->set_rhs(blox_test::IoArray::DigitalState::Active);
            d->set_op(blox_test::ActuatorLogic::DigitalOperator::OP_DESIRED_IS);
        }
        {
            auto d = message.add_digital();
            d->set_id(103);
            d->set_rhs(blox_test::IoArray::DigitalState::Active);
            d->set_op(blox_test::ActuatorLogic::DigitalOperator::OP_DESIRED_IS);
        }
        {
            auto d = message.add_digital();
            d->set_id(104);
            d->set_rhs(blox_test::IoArray::DigitalState::Active);
            d->set_op(blox_test::ActuatorLogic::DigitalOperator::OP_DESIRED_IS);
        }

        THEN("The target is active when the expression is true")
        {
            // or
            message.set_expression("a|b|c");

            auto result = setLogic(message);
            CHECK(result.ShortDebugString() ==
                  "targetId: 105 "
                  "drivenTargetId: 105 "
                  "enabled: true "
                  "expression: \"a|b|c\" "
                  "digital { op: OP_DESIRED_IS id: 101 rhs: STATE_ACTIVE } "
                  "digital { op: OP_DESIRED_IS id: 102 rhs: STATE_ACTIVE } "
                  "digital { op: OP_DESIRED_IS id: 103 rhs: STATE_ACTIVE } "
                  "digital { op: OP_DESIRED_IS id: 104 rhs: STATE_ACTIVE }");

            setAct(101, blox_test::IoArray::DigitalState::Inactive);
            setAct(102, blox_test::IoArray::DigitalState::Active);
            setAct(103, blox_test::IoArray::DigitalState::Inactive);

            {
                cbox::update(1000);

                cbox::TestCommand cmd(130, 0);
                CHECK(cbox::readObject(cmd) == cbox::CboxError::OK);
                auto decoded = blox_test::ActuatorLogic::Block();
                parseFromResponse(cmd, decoded);
                CHECK(decoded.ShortDebugString() ==
                      "targetId: 105 "
                      "drivenTargetId: 105 "
                      "enabled: true "
                      "result: RESULT_TRUE "
                      "expression: \"a|b|c\" "
                      "digital { op: OP_DESIRED_IS id: 101 rhs: STATE_ACTIVE } "
                      "digital { op: OP_DESIRED_IS result: RESULT_TRUE id: 102 rhs: STATE_ACTIVE } "
                      "digital { op: OP_DESIRED_IS id: 103 rhs: STATE_ACTIVE } "
                      "digital { op: OP_DESIRED_IS id: 104 rhs: STATE_ACTIVE }");
            }

            setAct(101, blox_test::IoArray::DigitalState::Inactive);
            setAct(102, blox_test::IoArray::DigitalState::Inactive);
            setAct(103, blox_test::IoArray::DigitalState::Active);

            {
                cbox::update(2000);

                cbox::TestCommand cmd(130, 0);
                CHECK(cbox::readObject(cmd) == cbox::CboxError::OK);
                auto decoded = blox_test::ActuatorLogic::Block();
                parseFromResponse(cmd, decoded);
                CHECK(decoded.ShortDebugString() ==
                      "targetId: 105 "
                      "drivenTargetId: 105 "
                      "enabled: true "
                      "result: RESULT_TRUE "
                      "expression: \"a|b|c\" "
                      "digital { op: OP_DESIRED_IS id: 101 rhs: STATE_ACTIVE } "
                      "digital { op: OP_DESIRED_IS id: 102 rhs: STATE_ACTIVE } "
                      "digital { op: OP_DESIRED_IS result: RESULT_TRUE id: 103 rhs: STATE_ACTIVE } "
                      "digital { op: OP_DESIRED_IS id: 104 rhs: STATE_ACTIVE }");
            }

            // brackets
            message.set_expression("a|(b&c)");
            result = setLogic(message);
            CHECK(result.result() == blox_test::ActuatorLogic::Result::RESULT_FALSE);
            CHECK(result.errorpos() == 0);

            // invert
            message.set_expression("a|!(b&c)");
            result = setLogic(message);
            CHECK(result.result() == blox_test::ActuatorLogic::Result::RESULT_TRUE);
            CHECK(result.errorpos() == 0);

            setAct(101, blox_test::IoArray::DigitalState::Inactive);
            setAct(102, blox_test::IoArray::DigitalState::Active);
            setAct(103, blox_test::IoArray::DigitalState::Active);

            result = setLogic(message);
            CHECK(result.result() == blox_test::ActuatorLogic::Result::RESULT_FALSE);
            CHECK(result.errorpos() == 0);

            // xor
            message.set_expression("a^b^c");
            result = setLogic(message);
            CHECK(result.result() == blox_test::ActuatorLogic::Result::RESULT_FALSE);
            CHECK(result.errorpos() == 0);

            setAct(101, blox_test::IoArray::DigitalState::Inactive);
            setAct(102, blox_test::IoArray::DigitalState::Active);
            setAct(103, blox_test::IoArray::DigitalState::Inactive);

            result = setLogic(message);
            CHECK(result.result() == blox_test::ActuatorLogic::Result::RESULT_TRUE);
            CHECK(result.errorpos() == 0);

            // nested brackets and all operators
            message.set_expression("a^!((b|c)&(c|d))");
            setAct(101, blox_test::IoArray::DigitalState::Inactive);
            setAct(102, blox_test::IoArray::DigitalState::Active);
            setAct(103, blox_test::IoArray::DigitalState::Inactive);
            setAct(104, blox_test::IoArray::DigitalState::Active);

            result = setLogic(message);
            CHECK(result.result() == blox_test::ActuatorLogic::Result::RESULT_FALSE);
            CHECK(result.errorpos() == 0);

            setAct(101, blox_test::IoArray::DigitalState::Inactive);
            setAct(102, blox_test::IoArray::DigitalState::Active);
            setAct(103, blox_test::IoArray::DigitalState::Inactive);
            setAct(104, blox_test::IoArray::DigitalState::Inactive);

            result = setLogic(message);
            CHECK(result.result() == blox_test::ActuatorLogic::Result::RESULT_TRUE);
            CHECK(result.errorpos() == 0);

            setAct(101, blox_test::IoArray::DigitalState::Active);
            setAct(102, blox_test::IoArray::DigitalState::Active);
            setAct(103, blox_test::IoArray::DigitalState::Inactive);
            setAct(104, blox_test::IoArray::DigitalState::Inactive);

            result = setLogic(message);
            CHECK(result.result() == blox_test::ActuatorLogic::Result::RESULT_FALSE);
            CHECK(result.errorpos() == 0);
        }

        THEN("The target is inactive when the expression has an error and the correct error code and pos is returned")
        {
            message.set_expression("e&c");
            result = setLogic(message);
            CHECK(result.result() == blox_test::ActuatorLogic::Result::RESULT_UNDEFINED_DIGITAL_COMPARE);
            CHECK(result.errorpos() == 0);

            message.set_expression("E&c");
            result = setLogic(message);
            CHECK(result.result() == blox_test::ActuatorLogic::Result::RESULT_UNDEFINED_ANALOG_COMPARE);
            CHECK(result.errorpos() == 0);

            message.set_expression("a(|b&c)");
            result = setLogic(message);
            CHECK(result.result() == blox_test::ActuatorLogic::Result::RESULT_UNEXPECTED_OPEN_BRACKET);
            CHECK(result.errorpos() == 1);

            message.set_expression("a|(b&c");
            result = setLogic(message);
            CHECK(result.result() == blox_test::ActuatorLogic::Result::RESULT_MISSING_CLOSE_BRACKET);
            CHECK(result.errorpos() == 5);

            message.set_expression("a|(b&c))");
            result = setLogic(message);
            CHECK(result.result() == blox_test::ActuatorLogic::Result::RESULT_UNEXPECTED_CLOSE_BRACKET);
            CHECK(result.errorpos() == 7);

            message.set_expression("a|(b&.)");
            result = setLogic(message);
            CHECK(result.result() == blox_test::ActuatorLogic::Result::RESULT_UNEXPECTED_CHARACTER);
            CHECK(result.errorpos() == 5);

            message.set_expression("a|(b&)");
            result = setLogic(message);
            CHECK(result.result() == blox_test::ActuatorLogic::Result::RESULT_EMPTY_SUBSTRING);
            CHECK(result.errorpos() == 5);

            message.set_expression("a|&b");
            result = setLogic(message);
            CHECK(result.result() == blox_test::ActuatorLogic::Result::RESULT_UNEXPECTED_OPERATOR);
            CHECK(result.errorpos() == 2);

            message.set_expression("a||b");
            result = setLogic(message);
            CHECK(result.result() == blox_test::ActuatorLogic::Result::RESULT_UNEXPECTED_OPERATOR);
            CHECK(result.errorpos() == 2);

            message.set_expression("a&|b");
            result = setLogic(message);
            CHECK(result.result() == blox_test::ActuatorLogic::Result::RESULT_UNEXPECTED_OPERATOR);
            CHECK(result.errorpos() == 2);

            message.set_expression("a^|b");
            result = setLogic(message);
            CHECK(result.result() == blox_test::ActuatorLogic::Result::RESULT_UNEXPECTED_OPERATOR);
            CHECK(result.errorpos() == 2);

            message.set_expression("a!&b");
            result = setLogic(message);
            CHECK(result.result() == blox_test::ActuatorLogic::Result::RESULT_UNEXPECTED_OPERATOR);
            CHECK(result.errorpos() == 2);

            message.set_expression("ab");
            result = setLogic(message);
            CHECK(result.result() == blox_test::ActuatorLogic::Result::RESULT_UNEXPECTED_COMPARISON);
            CHECK(result.errorpos() == 1);

            message.set_expression("a(");
            result = setLogic(message);
            CHECK(result.result() == blox_test::ActuatorLogic::Result::RESULT_UNEXPECTED_OPEN_BRACKET);
            CHECK(result.errorpos() == 1);

            {
                cbox::TestCommand cmd(102, 0);
                CHECK(cbox::deleteObject(cmd) == cbox::CboxError::OK);
            }

            message.set_expression("b");
            result = setLogic(message);
            CHECK(result.result() == blox_test::ActuatorLogic::Result::RESULT_BLOCK_NOT_FOUND);
            CHECK(result.errorpos() == 0);
        }

        AND_WHEN("Analog comparisons are used")
        {
            // sensors are 20, setpoints are 21
            message.clear_digital();
            {
                auto d = message.add_analog();
                d->set_id(121);
                d->set_rhs(cnl::unwrap(temp_t{21}));
                d->set_op(blox_test::ActuatorLogic::AnalogOperator::OP_VALUE_GE);
                // false: 20 >= 21
            }
            {
                auto d = message.add_analog();
                d->set_id(122);
                d->set_rhs(cnl::unwrap(temp_t{21}));
                d->set_op(blox_test::ActuatorLogic::AnalogOperator::OP_SETTING_GE);
                // true: 21 >= 21
            }
            {
                auto d = message.add_analog();
                d->set_id(123);
                d->set_rhs(cnl::unwrap(temp_t{21}));
                d->set_op(blox_test::ActuatorLogic::AnalogOperator::OP_VALUE_LE);
                // true: 20 <= 21
            }
            {
                auto d = message.add_analog();
                d->set_id(124);
                d->set_rhs(cnl::unwrap(temp_t{20.5}));
                d->set_op(blox_test::ActuatorLogic::AnalogOperator::OP_SETTING_LE);
                // false: 21 <= 20.5
            }

            message.set_expression("A|B|C|D");
            result = setLogic(message);
            CHECK(result.result() == blox_test::ActuatorLogic::Result::RESULT_TRUE);
            CHECK(result.ShortDebugString() ==
                  "targetId: 105 "
                  "drivenTargetId: 105 "
                  "enabled: true "
                  "result: RESULT_TRUE "
                  "expression: \"A|B|C|D\" "
                  "analog { op: OP_VALUE_GE id: 121 rhs: 86016 } "
                  "analog { op: OP_SETTING_GE result: RESULT_TRUE id: 122 rhs: 86016 } "
                  "analog { result: RESULT_TRUE id: 123 rhs: 86016 } "
                  "analog { op: OP_SETTING_LE id: 124 rhs: 83968 }");

            message.set_expression("(A|B)&(C|D)");
            result = setLogic(message);
            CHECK(result.result() == blox_test::ActuatorLogic::Result::RESULT_TRUE);

            message.set_expression("(A&B)|(C&D)");
            result = setLogic(message);
            CHECK(result.result() == blox_test::ActuatorLogic::Result::RESULT_FALSE);
        }
    }
}
