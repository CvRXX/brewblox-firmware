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
#include "blocks/ActuatorAnalogMockBlock.hpp"
#include "blocks/PidBlock.hpp"
#include "blocks/SetpointSensorPairBlock.hpp"
#include "blocks/TempSensorMockBlock.hpp"
#include "cbox/Box.hpp"
#include "control/Temperature.hpp"
#include "proto/ActuatorAnalogMock_test.pb.h"
#include "proto/Pid_test.pb.h"
#include "proto/SetpointSensorPair_test.pb.h"
#include "proto/TempSensorMock_test.pb.h"
#include "spark/Brewblox.hpp"

SCENARIO("A Blox Pid object with mock analog actuator")
{
    cbox::getObjects().clearAll();
    platform::particle::setupSystemBlocks();
    cbox::update(0);

    auto sensorId = cbox::obj_id_t(100);
    auto setpointId = cbox::obj_id_t(101);
    auto actuatorId = cbox::obj_id_t(102);
    auto pidId = cbox::obj_id_t(103);

    // create mock sensor
    auto sensorMessage = blox_test::TempSensorMock::Block();
    {
        auto cmd = cbox::TestCommand(sensorId, TempSensorMockBlock::staticTypeId());

        sensorMessage.set_setting(cnl::unwrap(temp_t(20.0)));
        sensorMessage.set_connected(true);

        messageToPayload(cmd, sensorMessage);
        CHECK(cbox::createBlock(cmd.request, cmd.callback) == cbox::CboxError::OK);
    }

    // create setpoint
    auto setpointMessage = blox_test::SetpointSensorPair::Block();
    {
        auto cmd = cbox::TestCommand(setpointId, SetpointSensorPairBlock::staticTypeId());

        setpointMessage.set_sensorid(sensorId);
        setpointMessage.set_storedsetting(cnl::unwrap(temp_t(21)));
        setpointMessage.set_enabled(true);
        setpointMessage.set_filter(blox_test::SetpointSensorPair::FilterChoice::FILTER_15s);
        setpointMessage.set_filterthreshold(cnl::unwrap(temp_t(1)));

        messageToPayload(cmd, setpointMessage);
        CHECK(cbox::createBlock(cmd.request, cmd.callback) == cbox::CboxError::OK);
    }

    // create actuator
    auto actuatorMessage = blox_test::ActuatorAnalogMock::Block();
    {
        auto cmd = cbox::TestCommand(actuatorId, ActuatorAnalogMockBlock::staticTypeId());

        actuatorMessage.set_setting(cnl::unwrap(ActuatorAnalog::value_t(0)));
        actuatorMessage.set_minsetting(cnl::unwrap(ActuatorAnalog::value_t(0)));
        actuatorMessage.set_maxsetting(cnl::unwrap(ActuatorAnalog::value_t(100)));
        actuatorMessage.set_minvalue(cnl::unwrap(ActuatorAnalog::value_t(0)));
        actuatorMessage.set_maxvalue(cnl::unwrap(ActuatorAnalog::value_t(100)));

        messageToPayload(cmd, actuatorMessage);
        CHECK(cbox::createBlock(cmd.request, cmd.callback) == cbox::CboxError::OK);
    }

    // create pid
    auto pidMessage = blox_test::Pid::Block();
    {
        auto cmd = cbox::TestCommand(pidId, PidBlock::staticTypeId());

        pidMessage.set_inputid(setpointId);
        pidMessage.set_outputid(actuatorId);
        pidMessage.set_enabled(true);
        pidMessage.set_kp(cnl::unwrap(Pid::in_t(10)));
        pidMessage.set_ti(2000);
        pidMessage.set_td(200);
        pidMessage.set_boilpointadjust(cnl::unwrap(Pid::in_t(-0.5)));
        pidMessage.set_boilminoutput(cnl::unwrap(Pid::in_t(25)));

        messageToPayload(cmd, pidMessage);
        CHECK(cbox::createBlock(cmd.request, cmd.callback) == cbox::CboxError::OK);
    }

    // update 999 seconds (PID updates every second, now is in ms)
    // one extra update will be triggered on proto receive
    uint32_t now = 0;
    for (; now < 999'000; now += 100) {
        cbox::update(now);
    }

    THEN("The PID can be read with the correct values")
    {
        auto cmd = cbox::TestCommand(pidId, PidBlock::staticTypeId());
        auto message = blox_test::Pid::Block();

        CHECK(cbox::readBlock(cmd.request, cmd.callback) == cbox::CboxError::OK);
        payloadToMessage(cmd, message);

        CHECK(cnl::wrap<Pid::out_t>(message.p()) == Approx(10.0).epsilon(0.01));
        CHECK(cnl::wrap<Pid::out_t>(message.i()) == Approx(10.0 * 1.0 * 1000 / 2000).epsilon(0.01));
        CHECK(cnl::wrap<Pid::out_t>(message.d()) == 0);
        CHECK(cnl::wrap<Pid::out_t>(message.outputvalue()) == Approx(15.0).epsilon(0.01));

        // only nonzero values are shown in the debug string
        CHECK(message.ShortDebugString() ==
              "inputId: 101 outputId: 102 "
              "inputValue: 81920 inputSetting: 86016 "
              "outputValue: 61439 outputSetting: 61439 "
              "enabled: true active: true "
              "kp: 40960 ti: 2000 td: 200 "
              "p: 40960 i: 20479 "
              "error: 4096 integral: 4096000 "
              "drivenOutputId: 102 "
              "boilPointAdjust: -2048 "
              "boilMinOutput: 102400 "
              "derivativeFilter: FILTER_3m");
    }

    THEN("The integral value can be written externally to reset it trough the integralReset field")
    {
        auto cmd = cbox::TestCommand(pidId, PidBlock::staticTypeId());

        pidMessage.set_integralreset(cnl::unwrap(Pid::out_t(20)));

        messageToPayload(cmd, pidMessage);
        CHECK(cbox::writeBlock(cmd.request, cmd.callback) == cbox::CboxError::OK);

        auto decoded = blox_test::Pid::Block();
        payloadToMessage(cmd, decoded);

        CHECK(decoded.ShortDebugString() ==
              "inputId: 101 outputId: 102 "
              "inputValue: 81920 inputSetting: 86016 "
              "outputValue: 122900 outputSetting: 122900 "
              "enabled: true active: true "
              "kp: 40960 ti: 2000 td: 200 "
              "p: 40960 i: 81940 "
              "error: 4096 integral: 16388096 "
              "drivenOutputId: 102 "
              "boilPointAdjust: -2048 "
              "boilMinOutput: 102400 "
              "derivativeFilter: FILTER_3m");
    }

    AND_WHEN("The setpoint is disabled")
    {
        auto cmd = cbox::TestCommand(setpointId, SetpointSensorPairBlock::staticTypeId());

        setpointMessage.set_enabled(false);
        CHECK(cbox::writeBlock(cmd.request, cmd.callback) == cbox::CboxError::OK);

        cbox::update(now + 2000);

        THEN("The PID becomes inactive")
        {
            auto pidLookup = cbox::CboxPtr<PidBlock>(pidId);
            auto pid = pidLookup.lock();
            CHECK(pid->get().active() == false);
        }

        THEN("The Actuator is set to zero and setting invalid")
        {
            auto actuatorLookup = cbox::CboxPtr<ActuatorAnalogMockBlock>(actuatorId);
            auto act = actuatorLookup.lock();
            CHECK(act->get().setting().has_value() == false);
        }
    }

    AND_WHEN("The setpoint is set to 99.5, with boil adjust at -0.5, it activates boil mode")
    {
        // Change mock sensor
        {
            auto cmd = cbox::TestCommand(sensorId, TempSensorMockBlock::staticTypeId());
            auto message = blox_test::TempSensorMock::Block();
            message.set_setting(cnl::unwrap(temp_t(99.5)));
            message.set_connected(true);

            messageToPayload(cmd, message);
            CHECK(cbox::writeBlock(cmd.request, cmd.callback) == cbox::CboxError::OK);
        }

        // Change setpoint
        {
            auto cmd = cbox::TestCommand(setpointId, SetpointSensorPairBlock::staticTypeId());

            setpointMessage.set_enabled(true);
            setpointMessage.set_storedsetting(cnl::unwrap(Pid::in_t(99.5)));
            setpointMessage.set_filter(blox_test::SetpointSensorPair::FilterChoice::FILTER_NONE);

            messageToPayload(cmd, setpointMessage);
            CHECK(cbox::writeBlock(cmd.request, cmd.callback) == cbox::CboxError::OK);
        }

        cbox::update(now + 2000);

        THEN("Boil mode becomes active and the PID output is the minimum output")
        {
            auto cmd = cbox::TestCommand(pidId, PidBlock::staticTypeId());
            auto message = blox_test::Pid::Block();

            CHECK(cbox::readBlock(cmd.request, cmd.callback) == cbox::CboxError::OK);
            payloadToMessage(cmd, message);

            CHECK(message.ShortDebugString() ==
                  "inputId: 101 outputId: 102 "
                  "inputValue: 407552 inputSetting: 407552 "
                  "outputValue: 102400 outputSetting: 102400 "
                  "enabled: true active: true "
                  "kp: 40960 ti: 2000 td: 200 "
                  "drivenOutputId: 102 "
                  "boilPointAdjust: -2048 "
                  "boilMinOutput: 102400 "
                  "boilModeActive: true "
                  "derivativeFilter: FILTER_3m");
        }
    }
}
