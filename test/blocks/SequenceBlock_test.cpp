#include <catch.hpp>

#include "AppTicks.hpp"
#include "TestHelpers.hpp"
#include "TestTimeHelpers.hpp"
#include "blocks/ActuatorPwmBlock.hpp"
#include "blocks/DigitalActuatorBlock.hpp"
#include "blocks/SequenceBlock.hpp"
#include "blocks/SetpointProfileBlock.hpp"
#include "blocks/SetpointSensorPairBlock.hpp"
#include "blocks/TempSensorMockBlock.hpp"
#include "cbox/Application.hpp"
#include "cbox/Box.hpp"
#include "control/TicksTypes.hpp"
#include "proto/ActuatorPwm_test.pb.h"
#include "proto/DigitalActuator_test.pb.h"
#include "proto/Sequence_test.pb.h"
#include "proto/SetpointProfile_test.pb.h"
#include "proto/SetpointSensorPair_test.pb.h"
#include "proto/TempSensorMock_test.pb.h"
#include "spark/Brewblox.hpp"

SCENARIO("A Sequence block with basic targets")
{
    cbox::getStorage().clear();
    cbox::getObjects().clearAll();
    platform::particle::setupSystemBlocks();

    test::resetTime(0, 0);
    test::update(0); // resets lastUpdateTime

    auto sensorId = cbox::obj_id_t(100);
    auto setpointId = cbox::obj_id_t(101);
    auto sequenceId = cbox::obj_id_t(102);

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
            instruction->set_allocated_wait_temp_above(waitTempAbove);

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

    WHEN("System time is not yet set, the Sequence will do nothing")
    {
        test::resetTime(0, 0);
        test::update(0);

        CHECK(sequence->state().status == blox_Sequence_SequenceStatus_ERROR);
        CHECK(sequence->state().error == blox_Sequence_SequenceError_SYSTEM_TIME_NOT_AVAILABLE);
        CHECK(sequence->state().activeInstruction == 0);

        test::resetTime(2'000'000'000, 0); // 2033/05/18

        // Time is set, sequence is active
        test::update(2000);
        CHECK(sequence->state().status == blox_Sequence_SequenceStatus_NEXT);
        CHECK(sequence->state().error == blox_Sequence_SequenceError_NONE);
        CHECK(sequence->state().activeInstruction == 1);
        CHECK(setpoint->get().setting() == 25);
    }

    WHEN("An instruction finishes, there is no delay for the next update")
    {
        test::resetTime(2'000'000'000, 0); // 2033/05/18

        test::update(2000);
        CHECK(sequence->state().activeInstruction == 1);

        test::update(2000);
        CHECK(sequence->state().status == blox_Sequence_SequenceStatus_NEXT);
        CHECK(sequence->state().error == blox_Sequence_SequenceError_NONE);
        CHECK(sequence->state().activeInstruction == 2);
        CHECK(setpoint->get().setting() == 30);
    }

    WHEN("An instruction is still waiting, there is a delay")
    {
        test::resetTime(2'000'000'000, 0); // 2033/05/18

        test::update(1000);
        CHECK(sequence->state().activeInstruction == 1);

        test::update(1000);
        CHECK(sequence->state().activeInstruction == 2);

        test::update(1000);
        CHECK(sequence->state().activeInstruction == 2);
        CHECK(sequence->state().status == blox_Sequence_SequenceStatus_WAIT);
        CHECK(sequence->state().error == blox_Sequence_SequenceError_NONE);

        sensor->get().setting(temp_t(30.5));

        // Setpoint is not updated immediately
        CHECK(setpoint->get().value() == temp_t(20));

        // nothing yet
        test::update(1000);
        CHECK(sequence->state().activeInstruction == 2);
        CHECK(sequence->state().status == blox_Sequence_SequenceStatus_WAIT);

        // updated again, and the condition is active
        test::update(2000);
        CHECK(setpoint->get().value() == temp_t(30.5));
        CHECK(sequence->state().activeInstruction == 3);
        CHECK(sequence->state().status == blox_Sequence_SequenceStatus_NEXT);

        // updated again, and the WAIT_TEMPERATURE_ABOVE passes immediately
        test::update(2000);
        CHECK(sequence->state().activeInstruction == 4);
        CHECK(sequence->state().status == blox_Sequence_SequenceStatus_NEXT);

        // this was the last instruction
        // next update is immediately, and will set end status
        test::update(2000);
        CHECK(sequence->state().activeInstruction == 4);
        CHECK(sequence->state().status == blox_Sequence_SequenceStatus_END);
    }

    WHEN("A Sequence is written with the same instructions, it retains its state")
    {
        test::resetTime(2'000'000'000, 0); // 2033/05/18

        test::update(1000);
        CHECK(sequence->state().activeInstruction == 1);

        test::update(1000);
        CHECK(sequence->state().activeInstruction == 2);

        test::update(1000);
        CHECK(sequence->state().activeInstruction == 2);
        CHECK(sequence->state().status == blox_Sequence_SequenceStatus_WAIT);

        {
            auto cmd = cbox::TestCommand(sequenceId, SequenceBlock::staticTypeId());
            messageToPayload(cmd, sequenceMessage);
            CHECK(cbox::writeBlock(cmd.request, cmd.callback) == cbox::CboxError::OK);
        }

        test::update(2000);
        CHECK(sequence->state().activeInstruction == 2);
        CHECK(sequence->state().status == blox_Sequence_SequenceStatus_WAIT);
    }

    WHEN("A Sequence is written with different instructions, it resets its state")
    {
        test::resetTime(2'000'000'000, 0); // 2033/05/18

        test::update(1000);
        CHECK(sequence->state().activeInstruction == 1);

        test::update(1000);
        CHECK(sequence->state().activeInstruction == 2);

        test::update(1000);
        CHECK(sequence->state().activeInstruction == 2);
        CHECK(sequence->state().status == blox_Sequence_SequenceStatus_WAIT);

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
        CHECK(sequence->state().status == blox_Sequence_SequenceStatus_NEXT);

        test::update(1000);
        CHECK(sequence->state().activeInstruction == 1);
        CHECK(sequence->state().status == blox_Sequence_SequenceStatus_END);
    }

    WHEN("A Sequence is written with overrideState enabled, current position is reset")
    {
        test::resetTime(2'000'000'000, 0); // 2033/05/18
        test::update(1000);

        CHECK(sequence->state().activeInstruction == 1);
        {
            auto cmd = cbox::TestCommand(sequenceId, SequenceBlock::staticTypeId());

            sequenceMessage.set_overridestate(true);
            sequenceMessage.set_activeinstruction(3);
            sequenceMessage.set_activeinstructionstartedat(100'000);
            sequenceMessage.set_disabledduration(200);

            messageToPayload(cmd, sequenceMessage);
            CHECK(cbox::writeBlock(cmd.request, cmd.callback) == cbox::CboxError::OK);
        }

        CHECK(sequence->state().activeInstruction == 3);
        CHECK(sequence->state().status == blox_Sequence_SequenceStatus_WAIT);
        CHECK(sequence->state().activeInstructionStartedAt == 100'000);
        CHECK(sequence->state().disabledDuration == 200);
    }

    WHEN("A change is made, it is not stored immediately")
    {
        test::resetTime(2'000'000'000, 0); // 2033/05/18

        test::update(1000);
        CHECK(sequence->state().activeInstruction == 1);
        CHECK(sequence->state().status == blox_Sequence_SequenceStatus_NEXT);

        test::update(2000);
        CHECK(sequence->state().activeInstruction == 2);
        CHECK(sequence->state().status == blox_Sequence_SequenceStatus_NEXT);

        test::update(3000);
        CHECK(sequence->state().activeInstruction == 2);
        CHECK(sequence->state().status == blox_Sequence_SequenceStatus_WAIT);
        CHECK(sequence->state().stored == false);

        CHECK(setpoint->get().setting() == temp_t(30));
        cbox::getStorage().loadObject(setpointId, [&setpoint](const cbox::Payload& payload) {
            return setpoint->write(payload);
        });
        CHECK(setpoint->get().setting() == temp_t(21));
    }

    WHEN("A change is made, it is stored after spending 60s on the same instruction")
    {
        test::resetTime(2'000'000'000, 0); // 2033/05/18

        test::update(1'000);
        CHECK(sequence->state().activeInstruction == 1);
        CHECK(sequence->state().status == blox_Sequence_SequenceStatus_NEXT);
        CHECK(sequence->state().stored == false);

        test::update(2'000);
        CHECK(sequence->state().activeInstruction == 2);
        CHECK(sequence->state().status == blox_Sequence_SequenceStatus_NEXT);
        CHECK(sequence->state().stored == false);

        test::update(3'000);
        CHECK(sequence->state().activeInstruction == 2);
        CHECK(sequence->state().status == blox_Sequence_SequenceStatus_WAIT);
        CHECK(sequence->state().stored == false);

        test::update(63'000);
        CHECK(sequence->state().activeInstruction == 2);
        CHECK(sequence->state().status == blox_Sequence_SequenceStatus_WAIT);
        CHECK(sequence->state().stored == true);

        CHECK(setpoint->get().setting() == temp_t(30));
        cbox::getStorage().loadObject(setpointId, [&setpoint](const cbox::Payload& payload) {
            return setpoint->write(payload);
        });
        CHECK(setpoint->get().setting() == temp_t(30));
    }
}

SCENARIO("A Sequence block with a RESTART instruction")
{
    cbox::getObjects().clearAll();
    platform::particle::setupSystemBlocks();

    test::resetTime(2'000'000'000, 0);
    test::update(0); // resets lastUpdateTime

    auto pinsId = cbox::obj_id_t(19);
    auto digitalId = cbox::obj_id_t(100);
    auto sequenceId = cbox::obj_id_t(101);

    // Create Digital Actuator
    auto actuatorMessage = blox_test::DigitalActuator::Block();
    {
        auto cmd = cbox::TestCommand(digitalId, DigitalActuatorBlock::staticTypeId());

        actuatorMessage.set_hwdevice(pinsId);
        actuatorMessage.set_channel(1);
        actuatorMessage.set_desiredstate(blox_test::IoArray::Inactive);

        messageToPayload(cmd, actuatorMessage);
        CHECK(cbox::createBlock(cmd.request, cmd.callback) == cbox::CboxError::OK);
    }

    // create Sequence
    auto sequenceMessage = blox_test::Sequence::Block();
    {
        auto cmd = cbox::TestCommand(sequenceId, SequenceBlock::staticTypeId());

        sequenceMessage.set_enabled(true);
        {
            auto* instruction = sequenceMessage.add_instructions();
            auto* setDigital = new blox_test::Sequence::SetDigital();
            instruction->set_allocated_set_digital(setDigital);

            setDigital->set_target(digitalId);
            setDigital->set_setting(blox_test::IoArray::Active);
        }
        {
            auto* instruction = sequenceMessage.add_instructions();
            auto* restart = new blox_test::Sequence::Restart();
            instruction->set_allocated_restart(restart);
        }
        {
            auto* instruction = sequenceMessage.add_instructions();
            auto* waitDigital = new blox_test::Sequence::WaitDigital();
            instruction->set_allocated_wait_digital(waitDigital);

            waitDigital->set_target(digitalId);
        }
        {
            auto* instruction = sequenceMessage.add_instructions();
            auto* restart = new blox_test::Sequence::Restart();
            instruction->set_allocated_restart(restart);
        }

        messageToPayload(cmd, sequenceMessage);
        CHECK(cbox::createBlock(cmd.request, cmd.callback) == cbox::CboxError::OK);
    }

    auto actuatorLookup = cbox::CboxPtr<DigitalActuatorBlock>(digitalId);
    auto actuator = actuatorLookup.lock();
    REQUIRE(actuator);

    auto sequenceLookup = cbox::CboxPtr<SequenceBlock>(sequenceId);
    auto sequence = sequenceLookup.lock();
    REQUIRE(sequence);

    WHEN("A RESTART is executed, the Sequence jumps to start")
    {
        CHECK(sequence->state().activeInstruction == 1);
        CHECK(sequence->state().status == blox_Sequence_SequenceStatus_NEXT);

        test::update(0);
        CHECK(sequence->state().activeInstruction == 0);
        CHECK(sequence->state().status == blox_Sequence_SequenceStatus_RESTART);

        // There's an enforced 1s after restarting
        test::update(0);
        CHECK(sequence->state().activeInstruction == 0);
        CHECK(sequence->state().status == blox_Sequence_SequenceStatus_RESTART);

        test::update(1000);
        CHECK(sequence->state().activeInstruction == 1);
        CHECK(sequence->state().status == blox_Sequence_SequenceStatus_NEXT);

        // jump to a RESTART instruction
        sequence->reset(3);
        test::update(1100);
        CHECK(sequence->state().activeInstruction == 0);
        CHECK(sequence->state().status == blox_Sequence_SequenceStatus_RESTART);
    }
}

SCENARIO("A Sequence block with invalid targets")
{
    cbox::getObjects().clearAll();
    platform::particle::setupSystemBlocks();

    test::resetTime(2'000'000'000, 0);
    test::update(0); // resets lastUpdateTime

    auto targetId = cbox::obj_id_t(100);
    auto sequenceId = cbox::obj_id_t(101);

    // create Sequence
    auto sequenceMessage = blox_test::Sequence::Block();
    {
        auto cmd = cbox::TestCommand(sequenceId, SequenceBlock::staticTypeId());

        sequenceMessage.set_enabled(true);
        {
            auto* instruction = sequenceMessage.add_instructions();
            auto* waitSetpoint = new blox_test::Sequence::WaitSetpoint();
            instruction->set_allocated_wait_setpoint(waitSetpoint);

            waitSetpoint->set_target(targetId);
            waitSetpoint->set_precision(cnl::unwrap(temp_t(1)));
        }

        messageToPayload(cmd, sequenceMessage);
        CHECK(cbox::createBlock(cmd.request, cmd.callback) == cbox::CboxError::OK);
    }

    auto sequenceLookup = cbox::CboxPtr<SequenceBlock>(sequenceId);
    auto sequence = sequenceLookup.lock();
    REQUIRE(sequence);

    WHEN("Target does not exist")
    {
        test::update(1000);
        CHECK(sequence->state().status == blox_Sequence_SequenceStatus_ERROR);
        CHECK(sequence->state().error == blox_Sequence_SequenceError_INVALID_TARGET);
        CHECK(sequence->state().activeInstruction == 0);
    }

    WHEN("Target exists, but is not a setpoint")
    {
        // create mock sensor
        auto sensorMessage = blox_test::TempSensorMock::Block();
        {
            auto cmd = cbox::TestCommand(targetId, TempSensorMockBlock::staticTypeId());

            sensorMessage.set_setting(cnl::unwrap(temp_t(20.0)));
            sensorMessage.set_connected(true);

            messageToPayload(cmd, sensorMessage);
            CHECK(cbox::createBlock(cmd.request, cmd.callback) == cbox::CboxError::OK);
        }

        // Note: we can't yet distinguish between INVALID_TARGET and INVALID_TARGET_TYPE
        test::update(1000);
        CHECK(sequence->state().status == blox_Sequence_SequenceStatus_ERROR);
        CHECK(sequence->state().error == blox_Sequence_SequenceError_INVALID_TARGET);
        CHECK(sequence->state().activeInstruction == 0);
    }

    WHEN("Target exists, but is disabled")
    {
        // create setpoint
        auto setpointMessage = blox_test::SetpointSensorPair::Block();
        {
            auto cmd = cbox::TestCommand(targetId, SetpointSensorPairBlock::staticTypeId());

            setpointMessage.set_sensorid(0);
            setpointMessage.set_storedsetting(cnl::unwrap(temp_t(25)));
            setpointMessage.set_enabled(false);
            setpointMessage.set_filter(blox_test::SetpointSensorPair::FilterChoice::FILTER_NONE);
            setpointMessage.set_filterthreshold(cnl::unwrap(temp_t(1)));

            messageToPayload(cmd, setpointMessage);
            CHECK(cbox::createBlock(cmd.request, cmd.callback) == cbox::CboxError::OK);
        }

        auto setpointLookup = cbox::CboxPtr<SetpointSensorPairBlock>(targetId);
        auto setpoint = setpointLookup.lock();
        REQUIRE(setpoint);

        test::update(1000);
        CHECK(sequence->state().status == blox_Sequence_SequenceStatus_ERROR);
        CHECK(sequence->state().error == blox_Sequence_SequenceError_DISABLED_TARGET);
        CHECK(sequence->state().activeInstruction == 0);

        // Setpoint is enabled, but does not have a sensor
        setpoint->get().enabler.set(true);
        test::update(2000);
        CHECK(sequence->state().status == blox_Sequence_SequenceStatus_ERROR);
        CHECK(sequence->state().error == blox_Sequence_SequenceError_INACTIVE_TARGET);
        CHECK(sequence->state().activeInstruction == 0);
    }
}

SCENARIO("A Sequence block with time-related instructions")
{
    cbox::getStorage().clear();
    cbox::getObjects().clearAll();
    platform::particle::setupSystemBlocks();

    test::resetTime(0, 0);
    test::update(0); // resets lastUpdateTime

    auto sequenceId = cbox::obj_id_t(100);

    // create Sequence
    auto sequenceMessage = blox_test::Sequence::Block();
    {
        auto cmd = cbox::TestCommand(sequenceId, SequenceBlock::staticTypeId());

        sequenceMessage.set_enabled(true);
        {
            auto* instruction = sequenceMessage.add_instructions();
            auto* waitDuration = new blox_test::Sequence::WaitDuration();
            instruction->set_allocated_wait_duration(waitDuration);

            waitDuration->set_duration(10);
        }
        {
            auto* instruction = sequenceMessage.add_instructions();
            auto* waitDuration = new blox_test::Sequence::WaitDuration();
            instruction->set_allocated_wait_duration(waitDuration);

            waitDuration->set_duration(100);
        }
        {
            auto* instruction = sequenceMessage.add_instructions();
            auto* waitDuration = new blox_test::Sequence::WaitDuration();
            instruction->set_allocated_wait_duration(waitDuration);

            waitDuration->set_duration(0);
        }
        {
            auto* instruction = sequenceMessage.add_instructions();
            auto* waitUntil = new blox_test::Sequence::WaitUntil();
            instruction->set_allocated_wait_until(waitUntil);

            waitUntil->set_time(2'000'000'000);
        }
        {
            auto* instruction = sequenceMessage.add_instructions();
            auto* waitUntil = new blox_test::Sequence::WaitUntil();
            instruction->set_allocated_wait_until(waitUntil);

            waitUntil->set_time(2'000'001'000);
        }

        messageToPayload(cmd, sequenceMessage);
        CHECK(cbox::createBlock(cmd.request, cmd.callback) == cbox::CboxError::OK);
    }

    auto sequenceLookup = cbox::CboxPtr<SequenceBlock>(sequenceId);
    auto sequence = sequenceLookup.lock();
    REQUIRE(sequence);

    WHEN("System time is not yet set, the WAIT_DURATION does not start")
    {
        CHECK(sequence->state().error == blox_Sequence_SequenceError_SYSTEM_TIME_NOT_AVAILABLE);
        CHECK(sequence->state().activeInstruction == 0);

        test::update(2'000);

        CHECK(sequence->state().error == blox_Sequence_SequenceError_SYSTEM_TIME_NOT_AVAILABLE);
        CHECK(sequence->state().activeInstruction == 0);

        test::resetTime(2'000'000'000, 0); // 2033/05/18
        test::update(5'000);               // instruction starts now, not when written

        CHECK(sequence->state().status == blox_Sequence_SequenceStatus_WAIT);
        CHECK(sequence->state().activeInstruction == 0);
        CHECK(sequence->state().activeInstructionStartedAt == 2'000'000'005);

        test::update(13'000); // should not yet be done
        CHECK(sequence->state().status == blox_Sequence_SequenceStatus_WAIT);
        CHECK(sequence->state().activeInstruction == 0);

        test::update(15'000);
        CHECK(sequence->state().status == blox_Sequence_SequenceStatus_NEXT);
        CHECK(sequence->state().activeInstruction == 1);

        sequence->enabler.set(false);
        test::update(15'000);
        CHECK(sequence->state().status == blox_Sequence_SequenceStatus_PAUSED);
        CHECK(sequence->state().activeInstruction == 1);
        CHECK(sequence->state().activeInstructionStartedAt == 2'000'000'015);
        CHECK(sequence->state().disabledAt == 2'000'000'015);

        sequence->enabler.set(true);
        test::update(115'000); // disabled time should not count towards the wait
        CHECK(sequence->state().status == blox_Sequence_SequenceStatus_WAIT);
        CHECK(sequence->state().activeInstruction == 1);
        CHECK(sequence->state().activeInstructionStartedAt == 2'000'000'015);
        CHECK(sequence->state().disabledAt == 0);
        CHECK(sequence->state().disabledDuration == 100);

        // Still waiting
        test::update(214'000);
        CHECK(sequence->state().status == blox_Sequence_SequenceStatus_WAIT);
        CHECK(sequence->state().activeInstruction == 1);

        // Now we're done (115'000 -> 215'000)
        test::update(215'000);
        CHECK(sequence->state().status == blox_Sequence_SequenceStatus_NEXT);
        CHECK(sequence->state().activeInstruction == 2);
        CHECK(sequence->state().disabledAt == 0);
        CHECK(sequence->state().disabledDuration == 0);

        // The WAIT_DURATION has 0 length. Continue immediately.
        test::update(215'000);
        CHECK(sequence->state().status == blox_Sequence_SequenceStatus_NEXT);
        CHECK(sequence->state().activeInstruction == 3);

        // The WAIT_UNTIL time is in the past. Continue immediately.
        test::update(215'000);
        CHECK(sequence->state().status == blox_Sequence_SequenceStatus_NEXT);
        CHECK(sequence->state().activeInstruction == 4);

        // Disabled duration does not impact WAIT_UNTIL end.
        sequence->enabler.set(false);
        test::update(215'000);
        sequence->enabler.set(true);
        test::update(315000);
        CHECK(sequence->state().status == blox_Sequence_SequenceStatus_WAIT);
        CHECK(sequence->state().activeInstruction == 4);
        CHECK(sequence->state().disabledDuration == 100);

        test::update(1'000'000);
        CHECK(sequence->state().status == blox_Sequence_SequenceStatus_NEXT);
        CHECK(sequence->state().activeInstruction == 5);
    }
}

SCENARIO("A Sequence with a sensor target")
{
    cbox::getStorage().clear();
    cbox::getObjects().clearAll();
    platform::particle::setupSystemBlocks();

    test::resetTime(2'000'000'000, 0); // 2033/05/18
    test::update(0);                   // resets lastUpdateTime

    auto sensorId = cbox::obj_id_t(100);
    auto sequenceId = cbox::obj_id_t(101);

    // create mock sensor
    auto sensorMessage = blox_test::TempSensorMock::Block();
    {
        auto cmd = cbox::TestCommand(sensorId, TempSensorMockBlock::staticTypeId());

        sensorMessage.set_setting(cnl::unwrap(temp_t(20.0)));
        sensorMessage.set_connected(true);

        messageToPayload(cmd, sensorMessage);
        CHECK(cbox::createBlock(cmd.request, cmd.callback) == cbox::CboxError::OK);
    }

    // create Sequence
    auto sequenceMessage = blox_test::Sequence::Block();
    {
        auto cmd = cbox::TestCommand(sequenceId, SequenceBlock::staticTypeId());

        sequenceMessage.set_enabled(true);
        {
            auto* instruction = sequenceMessage.add_instructions();
            auto* waitTempBelow = new blox_test::Sequence::WaitTemperatureBoundary();
            instruction->set_allocated_wait_temp_below(waitTempBelow);

            waitTempBelow->set_target(sensorId);
            waitTempBelow->set_value(cnl::unwrap(temp_t(10)));
        }
        {
            auto* instruction = sequenceMessage.add_instructions();
            auto* waitTempAbove = new blox_test::Sequence::WaitTemperatureBoundary();
            instruction->set_allocated_wait_temp_above(waitTempAbove);

            waitTempAbove->set_target(sensorId);
            waitTempAbove->set_value(cnl::unwrap(temp_t(30)));
        }
        {
            auto* instruction = sequenceMessage.add_instructions();
            auto* waitTempBetween = new blox_test::Sequence::WaitTemperatureRange();
            instruction->set_allocated_wait_temp_between(waitTempBetween);

            waitTempBetween->set_target(sensorId);
            waitTempBetween->set_lower(cnl::unwrap(temp_t(0)));
            waitTempBetween->set_upper(cnl::unwrap(temp_t(1)));
        }
        {
            auto* instruction = sequenceMessage.add_instructions();
            auto* waitTempBetween = new blox_test::Sequence::WaitTemperatureRange();
            instruction->set_allocated_wait_temp_not_between(waitTempBetween);

            waitTempBetween->set_target(sensorId);
            waitTempBetween->set_lower(cnl::unwrap(temp_t(0)));
            waitTempBetween->set_upper(cnl::unwrap(temp_t(1)));
        }
        {
            auto* instruction = sequenceMessage.add_instructions();
            auto* waitTempBetween = new blox_test::Sequence::WaitTemperatureRange();
            instruction->set_allocated_wait_temp_unexpected(waitTempBetween);

            waitTempBetween->set_target(sensorId);
            waitTempBetween->set_lower(cnl::unwrap(temp_t(0)));
            waitTempBetween->set_upper(cnl::unwrap(temp_t(1)));
        }

        messageToPayload(cmd, sequenceMessage);
        CHECK(cbox::createBlock(cmd.request, cmd.callback) == cbox::CboxError::OK);
    }

    auto sensorLookup = cbox::CboxPtr<TempSensorMockBlock>(sensorId);
    auto sensor = sensorLookup.lock();
    REQUIRE(sensor);

    auto sequenceLookup = cbox::CboxPtr<SequenceBlock>(sequenceId);
    auto sequence = sequenceLookup.lock();
    REQUIRE(sequence);

    WHEN("Waiting for temperature values")
    {
        CHECK(sequence->state().status == blox_Sequence_SequenceStatus_WAIT);
        CHECK(sequence->state().activeInstruction == 0);

        // below 10
        sensor->get().setting(temp_t(9.5));

        test::update(1000);
        CHECK(sequence->state().status == blox_Sequence_SequenceStatus_NEXT);
        CHECK(sequence->state().activeInstruction == 1);

        test::update(1000);
        CHECK(sequence->state().status == blox_Sequence_SequenceStatus_WAIT);
        CHECK(sequence->state().activeInstruction == 1);

        // above 30
        sensor->get().setting(temp_t(30.5));

        test::update(2000);
        CHECK(sequence->state().status == blox_Sequence_SequenceStatus_NEXT);
        CHECK(sequence->state().activeInstruction == 2);

        test::update(2000);
        CHECK(sequence->state().status == blox_Sequence_SequenceStatus_WAIT);
        CHECK(sequence->state().activeInstruction == 2);

        // between 0-1
        sensor->get().setting(temp_t(0));

        test::update(3000);
        CHECK(sequence->state().status == blox_Sequence_SequenceStatus_NEXT);
        CHECK(sequence->state().activeInstruction == 3);

        // not between 0-1
        test::update(3000);
        CHECK(sequence->state().status == blox_Sequence_SequenceStatus_WAIT);
        CHECK(sequence->state().activeInstruction == 3);

        sensor->get().setting(temp_t(2));
        test::update(4000);
        CHECK(sequence->state().status == blox_Sequence_SequenceStatus_NEXT);
        CHECK(sequence->state().activeInstruction == 4);

        // not between 0-1, or inactive
        sensor->get().setting(temp_t(0));
        sensor->get().connected(false);
        test::update(4000);
        CHECK(sequence->state().status == blox_Sequence_SequenceStatus_NEXT);
        CHECK(sequence->state().activeInstruction == 5);
    }
}

SCENARIO("A Sequence with Actuator targets")
{
    cbox::getStorage().clear();
    cbox::getObjects().clearAll();
    platform::particle::setupSystemBlocks();

    test::resetTime(2'000'000'000, 0);
    test::update(0); // resets lastUpdateTime

    auto pinsId = cbox::obj_id_t(19);
    auto digitalId = cbox::obj_id_t(100);
    auto pwmId = cbox::obj_id_t(101);
    auto sequenceId = cbox::obj_id_t(102);

    // Create Digital Actuator
    auto actuatorMessage = blox_test::DigitalActuator::Block();
    {
        auto cmd = cbox::TestCommand(digitalId, DigitalActuatorBlock::staticTypeId());

        actuatorMessage.set_hwdevice(pinsId);
        actuatorMessage.set_channel(1);
        actuatorMessage.set_desiredstate(blox_test::IoArray::Inactive);

        messageToPayload(cmd, actuatorMessage);
        CHECK(cbox::createBlock(cmd.request, cmd.callback) == cbox::CboxError::OK);
    }

    // Create PWM
    auto pwmMessage = blox_test::ActuatorPwm::Block();
    {
        auto cmd = cbox::TestCommand(pwmId, ActuatorPwmBlock::staticTypeId());

        pwmMessage.set_enabled(false); // disabled for now
        pwmMessage.set_actuatorid(digitalId);
        pwmMessage.set_desiredsetting(cnl::unwrap(ActuatorPwm::value_t(0)));
        pwmMessage.set_period(1000);

        messageToPayload(cmd, pwmMessage);
        CHECK(cbox::createBlock(cmd.request, cmd.callback) == cbox::CboxError::OK);
    }

    // create Sequence
    auto sequenceMessage = blox_test::Sequence::Block();
    {
        auto cmd = cbox::TestCommand(sequenceId, SequenceBlock::staticTypeId());

        sequenceMessage.set_enabled(true);
        {
            auto* instruction = sequenceMessage.add_instructions();
            auto* setDigital = new blox_test::Sequence::SetDigital();
            instruction->set_allocated_set_digital(setDigital);

            setDigital->set_target(digitalId);
            setDigital->set_setting(blox_test::IoArray::Active);
        }
        {
            auto* instruction = sequenceMessage.add_instructions();
            auto* waitDigital = new blox_test::Sequence::WaitDigital();
            instruction->set_allocated_wait_digital(waitDigital);

            waitDigital->set_target(digitalId);
        }
        {
            auto* instruction = sequenceMessage.add_instructions();
            auto* setPwm = new blox_test::Sequence::SetPwm();
            instruction->set_allocated_set_pwm(setPwm);

            setPwm->set_target(pwmId);
            setPwm->set_setting(cnl::unwrap(ActuatorPwm::value_t(20)));
        }

        messageToPayload(cmd, sequenceMessage);
        CHECK(cbox::createBlock(cmd.request, cmd.callback) == cbox::CboxError::OK);
    }

    auto digitalLookup = cbox::CboxPtr<DigitalActuatorBlock>(digitalId);
    auto digital = digitalLookup.lock();
    REQUIRE(digital);

    auto pwmLookup = cbox::CboxPtr<ActuatorPwmBlock>(pwmId);
    auto pwm = pwmLookup.lock();
    REQUIRE(pwm);

    auto sequenceLookup = cbox::CboxPtr<SequenceBlock>(sequenceId);
    auto sequence = sequenceLookup.lock();
    REQUIRE(sequence);

    WHEN("Setting and waiting for Digital Actuator state")
    {
        CHECK(sequence->state().status == blox_Sequence_SequenceStatus_NEXT);
        CHECK(sequence->state().activeInstruction == 1);

        CHECK(digital->getConstrained().desiredState() == ActuatorDigital::State::Active);

        test::update(1000);
        CHECK(digital->getConstrained().state() == ActuatorDigital::State::Active);
        CHECK(sequence->state().status == blox_Sequence_SequenceStatus_NEXT);
        CHECK(sequence->state().activeInstruction == 2);
    }
}

SCENARIO("A Sequence with a SetpointProfile target")
{
    cbox::getStorage().clear();
    cbox::getObjects().clearAll();
    platform::particle::setupSystemBlocks();

    test::resetTime(2'000'000'000, 0);
    test::update(0); // resets lastUpdateTime

    auto sensorId = cbox::obj_id_t(100);
    auto setpointId = cbox::obj_id_t(101);
    auto profileId = cbox::obj_id_t(102);
    auto sequenceId = cbox::obj_id_t(103);

    // Create sensor
    {
        auto cmd = cbox::TestCommand(sensorId, TempSensorMockBlock::staticTypeId());
        auto message = blox_test::TempSensorMock::Block();

        message.set_setting(cnl::unwrap(temp_t(20.0)));
        message.set_connected(true);

        messageToPayload(cmd, message);
        CHECK(cbox::createBlock(cmd.request, cmd.callback) == cbox::CboxError::OK);
    }

    // Create setpoint
    {
        auto cmd = cbox::TestCommand(setpointId, SetpointSensorPairBlock::staticTypeId());
        auto message = blox_test::SetpointSensorPair::Block();

        message.set_sensorid(sensorId);
        message.set_storedsetting(cnl::unwrap(temp_t(99)));
        message.set_enabled(true);

        messageToPayload(cmd, message);
        CHECK(cbox::createBlock(cmd.request, cmd.callback) == cbox::CboxError::OK);
    }

    // Create profile
    {
        auto cmd = cbox::TestCommand(profileId, SetpointProfileBlock::staticTypeId());
        auto message = blox_test::SetpointProfile::Block();

        message.set_targetid(setpointId);
        message.set_enabled(true);
        message.set_start(2'000'000'000); // starts immediately
        {
            auto newPoint = message.add_points();
            newPoint->set_time(10);
            newPoint->set_temperature(cnl::unwrap(temp_t(20)));
        }

        {
            auto newPoint = message.add_points();
            newPoint->set_time(20);
            newPoint->set_temperature(cnl::unwrap(temp_t(21)));
        }

        messageToPayload(cmd, message);
        CHECK(cbox::createBlock(cmd.request, cmd.callback) == cbox::CboxError::OK);
    }

    // create Sequence
    auto sequenceMessage = blox_test::Sequence::Block();
    {
        auto cmd = cbox::TestCommand(sequenceId, SequenceBlock::staticTypeId());

        sequenceMessage.set_enabled(true);
        {
            auto* instruction = sequenceMessage.add_instructions();
            auto* waitProfile = new blox_test::Sequence::TargetProfile();
            instruction->set_allocated_wait_profile(waitProfile);

            waitProfile->set_target(profileId);
        }
        {
            auto* instruction = sequenceMessage.add_instructions();
            auto* startProfile = new blox_test::Sequence::TargetProfile();
            instruction->set_allocated_start_profile(startProfile);

            startProfile->set_target(profileId);
        }
        {
            auto* instruction = sequenceMessage.add_instructions();
            auto* waitProfile = new blox_test::Sequence::TargetProfile();
            instruction->set_allocated_wait_profile(waitProfile);

            waitProfile->set_target(profileId);
        }

        messageToPayload(cmd, sequenceMessage);
        CHECK(cbox::createBlock(cmd.request, cmd.callback) == cbox::CboxError::OK);
    }

    auto profileLookup = cbox::CboxPtr<SetpointProfileBlock>(profileId);
    auto profile = profileLookup.lock();
    REQUIRE(profile);

    auto sequenceLookup = cbox::CboxPtr<SequenceBlock>(sequenceId);
    auto sequence = sequenceLookup.lock();
    REQUIRE(sequence);

    WHEN("Starting and waiting for a Setpoint Profile")
    {
        test::update(1'000);
        CHECK(sequence->state().status == blox_Sequence_SequenceStatus_WAIT);
        CHECK(sequence->state().activeInstruction == 0);

        test::update(19'000);
        CHECK(sequence->state().status == blox_Sequence_SequenceStatus_WAIT);
        CHECK(sequence->state().activeInstruction == 0);

        test::update(20'000);
        CHECK(sequence->state().status == blox_Sequence_SequenceStatus_NEXT);
        CHECK(sequence->state().activeInstruction == 1);

        test::update(20'000);
        CHECK(sequence->state().status == blox_Sequence_SequenceStatus_NEXT);
        CHECK(sequence->state().activeInstruction == 2);
        CHECK(profile->get().startTime() == 2'000'000'020);

        // Stay in error mode while profile is disabled
        profile->get().enabler.set(false);
        test::update(21'000);
        CHECK(sequence->state().error == blox_Sequence_SequenceError_DISABLED_TARGET);
        CHECK(sequence->state().activeInstruction == 2);

        // Still in error mode, even if profile is technically done
        test::update(40'000);
        CHECK(sequence->state().error == blox_Sequence_SequenceError_DISABLED_TARGET);
        CHECK(sequence->state().activeInstruction == 2);

        // As soon as profile is enabled, instruction is done
        profile->get().enabler.set(true);
        test::update(41'000);
        CHECK(sequence->state().status == blox_Sequence_SequenceStatus_NEXT);
        CHECK(sequence->state().activeInstruction == 3);
    }
}

SCENARIO("A Sequence with a Sequence target")
{
    cbox::getStorage().clear();
    cbox::getObjects().clearAll();
    platform::particle::setupSystemBlocks();

    test::resetTime(2'000'000'000, 0);
    test::update(0); // resets lastUpdateTime

    auto sequenceId1 = cbox::obj_id_t(100);
    auto sequenceId2 = cbox::obj_id_t(101);

    // create Sequence 1
    auto sequenceMessage1 = blox_test::Sequence::Block();
    {
        auto cmd = cbox::TestCommand(sequenceId1, SequenceBlock::staticTypeId());

        sequenceMessage1.set_enabled(true);
        {
            auto* instruction = sequenceMessage1.add_instructions();
            auto* waitDuration = new blox_test::Sequence::WaitDuration();
            instruction->set_allocated_wait_duration(waitDuration);

            waitDuration->set_duration(10);
        }

        messageToPayload(cmd, sequenceMessage1);
        CHECK(cbox::createBlock(cmd.request, cmd.callback) == cbox::CboxError::OK);
    }

    // create Sequence 2
    auto sequenceMessage2 = blox_test::Sequence::Block();
    {
        auto cmd = cbox::TestCommand(sequenceId2, SequenceBlock::staticTypeId());

        sequenceMessage2.set_enabled(true);
        {
            auto* instruction = sequenceMessage2.add_instructions();
            auto* waitSequence = new blox_test::Sequence::TargetSequence();
            instruction->set_allocated_wait_sequence(waitSequence);

            waitSequence->set_target(sequenceId1);
        }
        {
            auto* instruction = sequenceMessage2.add_instructions();
            auto* startSequence = new blox_test::Sequence::TargetSequence();
            instruction->set_allocated_start_sequence(startSequence);

            startSequence->set_target(sequenceId1);
        }

        messageToPayload(cmd, sequenceMessage2);
        CHECK(cbox::createBlock(cmd.request, cmd.callback) == cbox::CboxError::OK);
    }

    auto sequenceLookup1 = cbox::CboxPtr<SequenceBlock>(sequenceId1);
    auto sequence1 = sequenceLookup1.lock();
    REQUIRE(sequence1);

    auto sequenceLookup2 = cbox::CboxPtr<SequenceBlock>(sequenceId2);
    auto sequence2 = sequenceLookup2.lock();
    REQUIRE(sequence2);

    WHEN("Waiting for and restarting a Sequence")
    {
        // Waiting 10s
        CHECK(sequence1->state().status == blox_Sequence_SequenceStatus_WAIT);
        CHECK(sequence1->state().activeInstruction == 0);

        // Waiting for sequence1 to finish
        CHECK(sequence2->state().status == blox_Sequence_SequenceStatus_WAIT);
        CHECK(sequence2->state().activeInstruction == 0);

        // Duration wait done
        test::update(10'000);
        CHECK(sequence1->state().status == blox_Sequence_SequenceStatus_NEXT);
        CHECK(sequence1->state().activeInstruction == 1);

        // Sequence 1 is still in NEXT status
        CHECK(sequence2->state().status == blox_Sequence_SequenceStatus_WAIT);
        CHECK(sequence2->state().activeInstruction == 0);

        // Sequence 1 is now in END status
        // Sequence 2 finishes its wait
        test::update(11'000);
        CHECK(sequence1->state().status == blox_Sequence_SequenceStatus_END);
        CHECK(sequence1->state().activeInstruction == 1);

        CHECK(sequence2->state().status == blox_Sequence_SequenceStatus_NEXT);
        CHECK(sequence2->state().activeInstruction == 1);

        // Sequence 1 has been reset, but it was updated first.
        // It will re-evaluate its state next update.
        // Sequence 2 completed its START instruction
        test::update(12'000);
        CHECK(sequence1->state().status == blox_Sequence_SequenceStatus_UNKNOWN);
        CHECK(sequence1->state().activeInstruction == 0);

        CHECK(sequence2->state().status == blox_Sequence_SequenceStatus_NEXT);
        CHECK(sequence2->state().activeInstruction == 2);

        // Sequence 1 is waiting again
        // Sequence 2 is now in END status
        test::update(13'000);
        CHECK(sequence1->state().status == blox_Sequence_SequenceStatus_WAIT);
        CHECK(sequence1->state().activeInstruction == 0);

        CHECK(sequence2->state().status == blox_Sequence_SequenceStatus_END);
        CHECK(sequence2->state().activeInstruction == 2);
    }
}

SCENARIO("Mutually starting Sequences")
{
    cbox::getStorage().clear();
    cbox::getObjects().clearAll();
    platform::particle::setupSystemBlocks();

    test::resetTime(2'000'000'000, 0);
    test::update(0); // resets lastUpdateTime

    auto sequenceId1 = cbox::obj_id_t(100);
    auto sequenceId2 = cbox::obj_id_t(101);

    // create Sequence 1
    auto sequenceMessage1 = blox_test::Sequence::Block();
    {
        auto cmd = cbox::TestCommand(sequenceId1, SequenceBlock::staticTypeId());

        sequenceMessage1.set_enabled(false);
        {
            auto* instruction = sequenceMessage1.add_instructions();
            auto* startSequence = new blox_test::Sequence::TargetSequence();
            instruction->set_allocated_start_sequence(startSequence);

            startSequence->set_target(sequenceId2);
        }

        messageToPayload(cmd, sequenceMessage1);
        CHECK(cbox::createBlock(cmd.request, cmd.callback) == cbox::CboxError::OK);
    }

    // create Sequence 2
    auto sequenceMessage2 = blox_test::Sequence::Block();
    {
        auto cmd = cbox::TestCommand(sequenceId2, SequenceBlock::staticTypeId());

        sequenceMessage2.set_enabled(false);
        {
            auto* instruction = sequenceMessage2.add_instructions();
            auto* startSequence = new blox_test::Sequence::TargetSequence();
            instruction->set_allocated_start_sequence(startSequence);

            startSequence->set_target(sequenceId1);
        }

        messageToPayload(cmd, sequenceMessage2);
        CHECK(cbox::createBlock(cmd.request, cmd.callback) == cbox::CboxError::OK);
    }

    auto sequenceLookup1 = cbox::CboxPtr<SequenceBlock>(sequenceId1);
    auto sequence1 = sequenceLookup1.lock();
    REQUIRE(sequence1);

    auto sequenceLookup2 = cbox::CboxPtr<SequenceBlock>(sequenceId2);
    auto sequence2 = sequenceLookup2.lock();
    REQUIRE(sequence2);

    WHEN("Both Sequences only start each other")
    {
        sequence1->enabler.set(true);
        sequence2->enabler.set(true);

        test::update(1000);

        // Sequence 1 hasn't reloaded its active instruction yet
        CHECK(sequence1->state().status == blox_Sequence_SequenceStatus_UNKNOWN);
        CHECK(sequence1->state().activeInstruction == 0);

        // Sequence 2 was last to update
        CHECK(sequence2->state().status == blox_Sequence_SequenceStatus_NEXT);
        CHECK(sequence2->state().activeInstruction == 1);

        test::update(1100);

        // Sequence 1 started Sequence 2
        CHECK(sequence1->state().status == blox_Sequence_SequenceStatus_UNKNOWN);
        CHECK(sequence1->state().activeInstruction == 0);

        // Sequence 2 immediately restarted Sequence 1
        CHECK(sequence2->state().status == blox_Sequence_SequenceStatus_NEXT);
        CHECK(sequence2->state().activeInstruction == 1);

        test::update(1200);

        // Sequence 1 started Sequence 2
        CHECK(sequence1->state().status == blox_Sequence_SequenceStatus_UNKNOWN);
        CHECK(sequence1->state().activeInstruction == 0);

        // Sequence 2 immediately restarted Sequence 1
        CHECK(sequence2->state().status == blox_Sequence_SequenceStatus_NEXT);
        CHECK(sequence2->state().activeInstruction == 1);
    }
}
