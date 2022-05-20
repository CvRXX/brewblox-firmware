#include <catch.hpp>

#include "AppTicks.hpp"
#include "TestHelpers.hpp"
#include "blocks/SequenceBlock.hpp"
#include "blocks/SetpointSensorPairBlock.hpp"
#include "blocks/TempSensorMockBlock.hpp"
#include "cbox/Application.hpp"
#include "cbox/Box.hpp"
#include "control/TicksTypes.hpp"
#include "proto/Sequence_test.pb.h"
#include "proto/SetpointSensorPair_test.pb.h"
#include "proto/TempSensorMock_test.pb.h"
#include "spark/Brewblox.hpp"

SCENARIO("A Sequence block with a Setpoint target")
{

    cbox::getObjects().clearAll();
    platform::particle::setupSystemBlocks();

    auto sensorId = cbox::obj_id_t(100);
    auto setpointId = cbox::obj_id_t(101);
    auto sequenceId = cbox::obj_id_t(102);

    auto resetTime = [](utc_seconds_t utc, ticks_millis_t now) {
        auto& ticksImpl = ticks.ticksImpl();
        ticksImpl.reset(now);
        ticksImpl.setUtc(utc);
    };

    resetTime(0, 0);
    cbox::update(0); // resets lastUpdateTime

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
        setpointMessage.set_settingenabled(true);
        setpointMessage.set_filter(blox_test::SetpointSensorPair::FilterChoice::FILTER_NONE);
        setpointMessage.set_filterthreshold(cnl::unwrap(temp_t(1)));

        messageToPayload(cmd, setpointMessage);
        CHECK(cbox::createBlock(cmd.request, cmd.callback) == cbox::CboxError::OK);
    }

    // create Sequence
    auto sequenceMessage = blox_test::Sequence::Block();
    {
        auto cmd = cbox::TestCommand(sequenceId, SequenceBlock::staticTypeId());

        sequenceMessage.set_enabled(true);
        {
            auto* instruction = sequenceMessage.add_instructions();
            auto* setSetpoint = new blox_test::Sequence::SetSetpoint();
            instruction->set_allocated_set_setpoint(setSetpoint);

            setSetpoint->set_target(setpointId);
            setSetpoint->set_setting(cnl::unwrap(temp_t(25)));
        }
        {
            auto* instruction = sequenceMessage.add_instructions();
            auto* setSetpoint = new blox_test::Sequence::SetSetpoint();
            instruction->set_allocated_set_setpoint(setSetpoint);

            setSetpoint->set_target(setpointId);
            setSetpoint->set_setting(cnl::unwrap(temp_t(30)));
        }
        {
            auto* instruction = sequenceMessage.add_instructions();
            auto* waitSetpoint = new blox_test::Sequence::WaitSetpoint();
            instruction->set_allocated_wait_setpoint(waitSetpoint);

            waitSetpoint->set_target(setpointId);
            waitSetpoint->set_precision(cnl::unwrap(temp_t(1)));
        }
        {
            auto* instruction = sequenceMessage.add_instructions();
            auto* waitTempAbove = new blox_test::Sequence::WaitTemperatureBoundary();
            instruction->set_allocated_wait_temperature_above(waitTempAbove);

            waitTempAbove->set_target(sensorId);
            waitTempAbove->set_value(cnl::unwrap(temp_t(25)));
        }

        messageToPayload(cmd, sequenceMessage);
        CHECK(cbox::createBlock(cmd.request, cmd.callback) == cbox::CboxError::OK);
    }

    auto sensorLookup = cbox::CboxPtr<TempSensorMockBlock>(sensorId);
    auto setpointLookup = cbox::CboxPtr<SetpointSensorPairBlock>(setpointId);
    auto sequenceLookup = cbox::CboxPtr<SequenceBlock>(sequenceId);

    auto sensor = sensorLookup.lock();
    auto setpoint = setpointLookup.lock();
    auto sequence = sequenceLookup.lock();

    REQUIRE(sensor);
    REQUIRE(setpoint);
    REQUIRE(sequence);

    WHEN("UTC is not yet set, the Sequence will do nothing")
    {
        resetTime(0, 0);
        cbox::update(0);

        CHECK(sequence->state().status == blox_Sequence_SequenceStatus_ERROR);
        CHECK(sequence->state().error == blox_Sequence_SequenceError_SYSTEM_TIME_NOT_AVAILABLE);
        CHECK(sequence->state().activeInstruction == 0);

        resetTime(2'000'000'000, 0); // 2033/05/18

        // Time is set, sequence is active
        cbox::update(2000);
        CHECK(sequence->state().status == blox_Sequence_SequenceStatus_ACTIVE);
        CHECK(sequence->state().error == blox_Sequence_SequenceError_NONE);
        CHECK(sequence->state().activeInstruction == 1);
        CHECK(setpoint->get().setting() == 25);
    }

    WHEN("An instruction finishes, there is no delay for the next update")
    {
        resetTime(2'000'000'000, 0); // 2033/05/18

        cbox::update(2000);
        CHECK(sequence->state().activeInstruction == 1);

        cbox::update(2000);
        CHECK(sequence->state().status == blox_Sequence_SequenceStatus_ACTIVE);
        CHECK(sequence->state().error == blox_Sequence_SequenceError_NONE);
        CHECK(sequence->state().activeInstruction == 2);
        CHECK(setpoint->get().setting() == 30);
    }

    WHEN("An instruction is still waiting, there is a delay")
    {
        resetTime(2'000'000'000, 0); // 2033/05/18

        cbox::update(2000);
        CHECK(sequence->state().activeInstruction == 1);

        cbox::update(2000);
        CHECK(sequence->state().activeInstruction == 2);

        cbox::update(2000);
        CHECK(sequence->state().activeInstruction == 2);
        CHECK(sequence->state().status == blox_Sequence_SequenceStatus_WAITING);
        CHECK(sequence->state().error == blox_Sequence_SequenceError_NONE);

        sensor->get().setting(temp_t(30.5));

        // Setpoint is not updated immediately
        CHECK(setpoint->get().value() == temp_t(20));

        // nothing yet
        cbox::update(2000);
        CHECK(sequence->state().activeInstruction == 2);
        CHECK(sequence->state().status == blox_Sequence_SequenceStatus_WAITING);

        // updated again, and the condition is active
        cbox::update(4000);
        CHECK(setpoint->get().value() == temp_t(30.5));
        CHECK(sequence->state().activeInstruction == 3);
        CHECK(sequence->state().status == blox_Sequence_SequenceStatus_ACTIVE);

        // updated again, and the WAIT_TEMPERATURE_ABOVE passes immediately
        cbox::update(4000);
        CHECK(sequence->state().activeInstruction == 4);
        CHECK(sequence->state().status == blox_Sequence_SequenceStatus_ACTIVE);

        // this was the last instruction
        // next update is immediately, and will set condition done
        cbox::update(4000);
        CHECK(sequence->state().activeInstruction == 4);
        CHECK(sequence->state().status == blox_Sequence_SequenceStatus_DONE);
    }

    WHEN("A Sequence is written with the same instructions, it retains its state")
    {
        resetTime(2'000'000'000, 0); // 2033/05/18

        cbox::update(2000);
        CHECK(sequence->state().activeInstruction == 1);

        cbox::update(2000);
        CHECK(sequence->state().activeInstruction == 2);

        cbox::update(2000);
        CHECK(sequence->state().activeInstruction == 2);
        CHECK(sequence->state().status == blox_Sequence_SequenceStatus_WAITING);

        {
            auto cmd = cbox::TestCommand(sequenceId, SequenceBlock::staticTypeId());
            messageToPayload(cmd, sequenceMessage);
            CHECK(cbox::writeBlock(cmd.request, cmd.callback) == cbox::CboxError::OK);
        }

        cbox::update(4000);
        CHECK(sequence->state().activeInstruction == 2);
        CHECK(sequence->state().status == blox_Sequence_SequenceStatus_WAITING);
    }

    WHEN("A Sequence is written with different instructions, it resets its state")
    {
        resetTime(2'000'000'000, 0); // 2033/05/18

        cbox::update(2000);
        CHECK(sequence->state().activeInstruction == 1);

        cbox::update(2000);
        CHECK(sequence->state().activeInstruction == 2);

        cbox::update(2000);
        CHECK(sequence->state().activeInstruction == 2);
        CHECK(sequence->state().status == blox_Sequence_SequenceStatus_WAITING);

        {
            auto cmd = cbox::TestCommand(sequenceId, SequenceBlock::staticTypeId());

            sequenceMessage.clear_instructions();

            auto* instruction = sequenceMessage.add_instructions();
            auto* enable = new blox_test::Sequence::EnableDisable();
            instruction->set_allocated_enable(enable);

            enable->set_target(setpointId);

            messageToPayload(cmd, sequenceMessage);
            CHECK(cbox::writeBlock(cmd.request, cmd.callback) == cbox::CboxError::OK);
        }

        // the update is done during the write
        CHECK(sequence->state().activeInstruction == 1);
        CHECK(sequence->state().status == blox_Sequence_SequenceStatus_ACTIVE);

        cbox::update(2000);
        CHECK(sequence->state().activeInstruction == 1);
        CHECK(sequence->state().status == blox_Sequence_SequenceStatus_DONE);
    }
}

// TODO:
// - disabled duration
// - invalid target
// - invalid target type
// - disabled target
// - overrideState
// - restart
// - enable / disable
// - wait duration
// - wait until
// - wait temp between
// - wait temp above / below
// - set digital
// - wait digital
// - set pwm
// - wait pwm
// - start profile
// - wait profile
// - start sequence
// - wait sequence
// - recursive sequence
// - delayed storage
