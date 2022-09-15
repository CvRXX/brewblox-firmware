#include <catch.hpp>

#include "AppTicks.hpp"
#include "TestHelpers.hpp"
#include "blocks/DigitalActuatorBlock.hpp"
#include "blocks/MockPinsBlock.hpp"
#include "blocks/SetpointProfileBlock.hpp"
#include "blocks/SetpointSensorPairBlock.hpp"
#include "blocks/TempSensorMockBlock.hpp"
#include "cbox/Box.hpp"
#include "proto/DigitalActuator_test.pb.h"
#include "proto/MockPins_test.pb.h"
#include "proto/SetpointProfile_test.pb.h"
#include "proto/SetpointSensorPair_test.pb.h"
#include "proto/Spark3Pins_test.pb.h"
#include "proto/TempSensorMock_test.pb.h"
#include "spark/Brewblox.hpp"
#include "spark/Spark3PinsBlock.hpp"

SCENARIO("A Digital Actuator releasing its channel claims")
{
    cbox::getObjects().clearAll();
    platform::particle::setupSystemBlocks();
    cbox::update(0);

    auto pinsId = cbox::obj_id_t(19);
    auto arrayId = cbox::obj_id_t(100);
    auto actId = cbox::obj_id_t(101);

    {
        auto cmd = cbox::TestCommand(arrayId, MockPinsBlock::staticTypeId());
        auto message = blox_test::MockPins::Block();

        messageToPayload(cmd, message);
        CHECK(cbox::createBlock(cmd.request, cmd.callback) == cbox::CboxError::OK);
    }

    {
        auto cmd = cbox::TestCommand(actId, DigitalActuatorBlock::staticTypeId());
        auto message = blox_test::DigitalActuator::Block();

        message.set_hwdevice(arrayId);
        message.set_channel(1);
        message.set_desiredstate(blox_test::IoArray::DigitalState::Active);

        messageToPayload(cmd, message);
        CHECK(cbox::createBlock(cmd.request, cmd.callback) == cbox::CboxError::OK);
    }

    WHEN("The actuator hwDevice is cleared")
    {
        {
            auto writeCmd = cbox::TestCommand(actId, DigitalActuatorBlock::staticTypeId());
            auto writeMessage = blox_test::DigitalActuator::Block();
            writeMessage.set_hwdevice(0);
            messageToPayload(writeCmd, writeMessage,
                             {blox_test::DigitalActuator::Block::kHwDeviceFieldNumber});
            CHECK(cbox::writeBlock(writeCmd.request, writeCmd.callback) == cbox::CboxError::OK);
        }

        THEN("The channel is no longer claimed")
        {
            auto cmd = cbox::TestCommand(arrayId, MockPinsBlock::staticTypeId());
            auto message = blox_test::MockPins::Block();

            CHECK(cbox::readBlock(cmd.request, cmd.callback) == cbox::CboxError::OK);
            payloadToMessage(cmd, message);

            CHECK(message.ShortDebugString() ==
                  "channels { id: 1 capabilities: 5 } "
                  "channels { id: 2 capabilities: 5 } "
                  "channels { id: 3 capabilities: 5 } "
                  "channels { id: 4 capabilities: 5 } "
                  "channels { id: 5 capabilities: 5 } "
                  "channels { id: 6 capabilities: 5 } "
                  "channels { id: 7 capabilities: 5 } "
                  "channels { id: 8 capabilities: 5 }");
        }
    }

    WHEN("The actuator channel is cleared")
    {
        {
            auto writeCmd = cbox::TestCommand(actId, DigitalActuatorBlock::staticTypeId());
            auto writeMessage = blox_test::DigitalActuator::Block();
            writeMessage.set_channel(0);
            messageToPayload(writeCmd, writeMessage,
                             {blox_test::DigitalActuator::Block::kChannelFieldNumber});
            CHECK(cbox::writeBlock(writeCmd.request, writeCmd.callback) == cbox::CboxError::OK);
        }

        THEN("The pins channel is no longer claimed")
        {
            auto cmd = cbox::TestCommand(arrayId, MockPinsBlock::staticTypeId());
            auto message = blox_test::MockPins::Block();

            CHECK(cbox::readBlock(cmd.request, cmd.callback) == cbox::CboxError::OK);
            payloadToMessage(cmd, message);

            CHECK(message.ShortDebugString() ==
                  "channels { id: 1 capabilities: 5 } "
                  "channels { id: 2 capabilities: 5 } "
                  "channels { id: 3 capabilities: 5 } "
                  "channels { id: 4 capabilities: 5 } "
                  "channels { id: 5 capabilities: 5 } "
                  "channels { id: 6 capabilities: 5 } "
                  "channels { id: 7 capabilities: 5 } "
                  "channels { id: 8 capabilities: 5 }");
        }
    }

    WHEN("The actuator channel is changed")
    {
        {
            auto writeCmd = cbox::TestCommand(actId, DigitalActuatorBlock::staticTypeId());
            auto writeMessage = blox_test::DigitalActuator::Block();
            writeMessage.set_channel(2);
            messageToPayload(writeCmd, writeMessage,
                             {blox_test::DigitalActuator::Block::kChannelFieldNumber});
            CHECK(cbox::writeBlock(writeCmd.request, writeCmd.callback) == cbox::CboxError::OK);
        }

        THEN("The old channel is unclaimed, and the new channel is claimed")
        {
            auto cmd = cbox::TestCommand(arrayId, MockPinsBlock::staticTypeId());
            auto message = blox_test::MockPins::Block();

            CHECK(cbox::readBlock(cmd.request, cmd.callback) == cbox::CboxError::OK);
            payloadToMessage(cmd, message);

            CHECK(message.ShortDebugString() ==
                  "channels { id: 1 capabilities: 5 } "
                  "channels { id: 2 capabilities: 5 claimedBy: 101 } "
                  "channels { id: 3 capabilities: 5 } "
                  "channels { id: 4 capabilities: 5 } "
                  "channels { id: 5 capabilities: 5 } "
                  "channels { id: 6 capabilities: 5 } "
                  "channels { id: 7 capabilities: 5 } "
                  "channels { id: 8 capabilities: 5 }");
        }
    }

    WHEN("The actuator hwDevice is shifted")
    {
        {
            auto writeCmd = cbox::TestCommand(actId, DigitalActuatorBlock::staticTypeId());
            auto writeMessage = blox_test::DigitalActuator::Block();
            writeMessage.set_hwdevice(pinsId);
            messageToPayload(writeCmd, writeMessage,
                             {blox_test::DigitalActuator::Block::kHwDeviceFieldNumber});
            CHECK(cbox::writeBlock(writeCmd.request, writeCmd.callback) == cbox::CboxError::OK);
        }

        THEN("The MockPins channel is no longer claimed")
        {
            auto cmd = cbox::TestCommand(arrayId, MockPinsBlock::staticTypeId());
            auto message = blox_test::MockPins::Block();

            CHECK(cbox::readBlock(cmd.request, cmd.callback) == cbox::CboxError::OK);
            payloadToMessage(cmd, message);

            // Mockpins proto doesn't change when channels are used, but leaving this here for when we change our mind
            CHECK(message.ShortDebugString() ==
                  "channels { id: 1 capabilities: 5 } "
                  "channels { id: 2 capabilities: 5 } "
                  "channels { id: 3 capabilities: 5 } "
                  "channels { id: 4 capabilities: 5 } "
                  "channels { id: 5 capabilities: 5 } "
                  "channels { id: 6 capabilities: 5 } "
                  "channels { id: 7 capabilities: 5 } "
                  "channels { id: 8 capabilities: 5 }");
        }

        AND_THEN("The SparkPins channel is claimed")
        {
            auto cmd = cbox::TestCommand(pinsId, platform::particle::Spark3PinsBlock::staticTypeId());
            auto message = blox_test::Spark3Pins::Block();

            CHECK(cbox::readBlock(cmd.request, cmd.callback) == cbox::CboxError::OK);
            payloadToMessage(cmd, message);

            CHECK(message.ShortDebugString() ==
                  "voltage5: 2050 voltage12: 1788 "
                  "channels { id: 1 capabilities: 5 claimedBy: 101 } "
                  "channels { id: 2 capabilities: 5 } "
                  "channels { id: 3 capabilities: 5 } "
                  "channels { id: 4 capabilities: 5 } "
                  "channels { id: 5 capabilities: 5 }");
        }
    }
}

SCENARIO("A SetpointProfile block releasing its claim")
{
    ticks.ticksImpl().reset(0);
    ticks.setUtc(20'000);

    cbox::getObjects().clearAll();
    platform::particle::setupSystemBlocks();

    auto sensorId = cbox::obj_id_t(100);
    auto setpointId1 = cbox::obj_id_t(101);
    auto setpointId2 = cbox::obj_id_t(102);
    auto profileId = cbox::obj_id_t(103);

    auto update = [](cbox::update_t now) {
        ticks.ticksImpl().reset(now);
        cbox::update(now);
    };

    update(0);

    // Create sensor
    {
        auto cmd = cbox::TestCommand(sensorId, TempSensorMockBlock::staticTypeId());
        auto message = blox_test::TempSensorMock::Block();

        message.set_setting(cnl::unwrap(temp_t(20.0)));
        message.set_connected(true);

        messageToPayload(cmd, message);
        CHECK(cbox::createBlock(cmd.request, cmd.callback) == cbox::CboxError::OK);
    }

    // Create setpoint 1
    {
        auto cmd = cbox::TestCommand(setpointId1, SetpointSensorPairBlock::staticTypeId());
        auto message = blox_test::SetpointSensorPair::Block();

        message.set_sensorid(sensorId);
        message.set_storedsetting(cnl::unwrap(temp_t(99)));
        message.set_enabled(true);

        messageToPayload(cmd, message);
        CHECK(cbox::createBlock(cmd.request, cmd.callback) == cbox::CboxError::OK);
    }

    // Create setpoint 2
    {
        auto cmd = cbox::TestCommand(setpointId2, SetpointSensorPairBlock::staticTypeId());
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

        message.set_targetid(setpointId1);
        message.set_enabled(true);
        message.set_start(20'000);

        {
            auto newPoint = message.add_points();
            newPoint->set_time(0);
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

    cbox::update(1000);

    WHEN("Created")
    {
        THEN("Setpoint 1 is claimed")
        {
            auto cmd = cbox::TestCommand(setpointId1, SetpointSensorPairBlock::staticTypeId());
            auto message = blox_test::SetpointSensorPair::Block();

            CHECK(cbox::readBlock(cmd.request, cmd.callback) == cbox::CboxError::OK);
            payloadToMessage(cmd, message);

            CHECK(message.claimedby() == profileId);
        }
    }

    WHEN("The profile clears its target ID")
    {
        {
            auto cmd = cbox::TestCommand(profileId, SetpointProfileBlock::staticTypeId());
            auto message = blox_test::SetpointProfile::Block();

            message.set_targetid(0);

            messageToPayload(cmd, message, {blox_test::SetpointProfile::Block::kTargetIdFieldNumber});
            CHECK(cbox::writeBlock(cmd.request, cmd.callback) == cbox::CboxError::OK);
        }

        THEN("Setpoint 1 is no longer claimed")
        {
            auto cmd = cbox::TestCommand(setpointId1, SetpointSensorPairBlock::staticTypeId());
            auto message = blox_test::SetpointSensorPair::Block();

            CHECK(cbox::readBlock(cmd.request, cmd.callback) == cbox::CboxError::OK);
            payloadToMessage(cmd, message);

            CHECK(message.claimedby() == 0);
        }
    }

    WHEN("The profile starts targeting Setpoint 2")
    {
        {
            auto cmd = cbox::TestCommand(profileId, SetpointProfileBlock::staticTypeId());
            auto message = blox_test::SetpointProfile::Block();

            message.set_targetid(setpointId2);

            messageToPayload(cmd, message, {blox_test::SetpointProfile::Block::kTargetIdFieldNumber});
            CHECK(cbox::writeBlock(cmd.request, cmd.callback) == cbox::CboxError::OK);
        }

        THEN("Setpoint 1 is no longer claimed")
        {
            auto cmd = cbox::TestCommand(setpointId1, SetpointSensorPairBlock::staticTypeId());
            auto message = blox_test::SetpointSensorPair::Block();

            CHECK(cbox::readBlock(cmd.request, cmd.callback) == cbox::CboxError::OK);
            payloadToMessage(cmd, message);

            CHECK(message.claimedby() == 0);
        }

        AND_THEN("Setpoint 2 is claimed")
        {
            auto cmd = cbox::TestCommand(setpointId2, SetpointSensorPairBlock::staticTypeId());
            auto message = blox_test::SetpointSensorPair::Block();

            CHECK(cbox::readBlock(cmd.request, cmd.callback) == cbox::CboxError::OK);
            payloadToMessage(cmd, message);

            CHECK(message.claimedby() == profileId);
        }
    }
}
