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
#include "blocks/DS2413Block.hpp"
#include "blocks/DigitalActuatorBlock.hpp"
#include "blocks/MockPinsBlock.hpp"
#include "cbox/Box.hpp"
#include "cbox/CboxPtr.hpp"
#include "control/OneWireAddress.hpp"
#include "proto/DS2413_test.pb.h"
#include "proto/DigitalActuator_test.pb.h"
#include "proto/MockPins_test.pb.h"
#include "spark/Brewblox.hpp"

namespace Catch {
template <>
struct StringMaker<OneWireAddress> {
    static std::string convert(OneWireAddress const& value)
    {
        return value.toString();
    }
};
}

SCENARIO("A DigitalActuator Block with a DS2413 target")
{
    cbox::getObjects().clearAll();
    platform::particle::setupSystemBlocks();
    cbox::update(0);

    WHEN("a DS2413 block is created")
    {
        auto ds2413Id = cbox::obj_id_t(100);
        auto actId = cbox::obj_id_t(101);

        {
            auto cmd = cbox::TestCommand(ds2413Id, DS2413Block::staticTypeId());
            auto message = blox_test::DS2413::Block();

            message.set_address(0x0644'4444'4444'443A);
            message.set_onewirebusid(4);

            messageToPayload(cmd, message);
            CHECK(cbox::createBlock(cmd.request, cmd.callback) == cbox::CboxError::OK);
        }

        THEN("The returned protobuf data is as expected")
        {
            auto cmd = cbox::TestCommand(ds2413Id, DS2413Block::staticTypeId());
            auto message = blox_test::DS2413::Block();

            CHECK(cbox::readBlock(cmd.request, cmd.callback) == cbox::CboxError::OK);
            payloadToMessage(cmd, message);

            CHECK(message.ShortDebugString() ==
                  "address: 451560922637681722 "
                  "connected: true "
                  "oneWireBusId: 4 "
                  "channels { id: 1 } "
                  "channels { id: 2 }");
        }

        THEN("The writable settings match what was sent")
        {
            auto lookup = cbox::CboxPtr<DS2413Block>(ds2413Id);
            auto devicePtr = lookup.lock();
            REQUIRE(devicePtr);
            CHECK(devicePtr->get().address() == OneWireAddress(0x0644'4444'4444'443A));
        }

        AND_WHEN("A DigitalActuator block is created that uses one of the channels")
        {
            {
                auto cmd = cbox::TestCommand(actId, DigitalActuatorBlock::staticTypeId());
                auto message = blox_test::DigitalActuator::Block();

                message.set_hwdevice(ds2413Id);
                message.set_channel(1);
                message.set_desiredstate(blox_test::IoArray::DigitalState::Active);

                messageToPayload(cmd, message);
                CHECK(cbox::createBlock(cmd.request, cmd.callback) == cbox::CboxError::OK);
            }

            THEN("A read of the actuator is as expected")
            {
                auto cmd = cbox::TestCommand(actId, DigitalActuatorBlock::staticTypeId());
                auto message = blox_test::DigitalActuator::Block();

                CHECK(cbox::readBlock(cmd.request, cmd.callback) == cbox::CboxError::OK);
                payloadToMessage(cmd, message);

                CHECK(message.ShortDebugString() ==
                      "hwDevice: 100 "
                      "channel: 1 "
                      "state: STATE_ACTIVE "
                      "desiredState: STATE_ACTIVE");
            }

            THEN("A read of the DS2413 is as expected")
            {
                auto cmd = cbox::TestCommand(ds2413Id, DS2413Block::staticTypeId());
                auto message = blox_test::DS2413::Block();

                CHECK(cbox::readBlock(cmd.request, cmd.callback) == cbox::CboxError::OK);
                payloadToMessage(cmd, message);

                // DS2413 proto doesn't change when channels are used, but leaving this here for when we change our mind
                CHECK(message.ShortDebugString() ==
                      "address: 451560922637681722 "
                      "connected: true "
                      "oneWireBusId: 4 "
                      "channels { id: 1 } "
                      "channels { id: 2 }");
            }
        }

        AND_WHEN("A DigitalActuator block is created before the target DS2413 block is created")
        {
            auto ds2413Id2 = cbox::obj_id_t(102);

            {
                auto cmd = cbox::TestCommand(actId, DigitalActuatorBlock::staticTypeId());
                auto message = blox_test::DigitalActuator::Block();
                message.set_hwdevice(ds2413Id2);
                message.set_channel(1);
                message.set_desiredstate(blox_test::IoArray::DigitalState::Active);
                message.set_transitiondurationsetting(250);
                message.set_transitiondurationpreset(blox_test::IoArray::TransitionDurationPreset::ST_FAST);

                messageToPayload(cmd, message);
                CHECK(cbox::createBlock(cmd.request, cmd.callback) == cbox::CboxError::OK);
            }

            THEN("The configured channel is not lost and the actuator reads as expected")
            {
                auto cmd = cbox::TestCommand(actId, DigitalActuatorBlock::staticTypeId());
                auto message = blox_test::DigitalActuator::Block();

                CHECK(cbox::readBlock(cmd.request, cmd.callback) == cbox::CboxError::OK);
                payloadToMessage(cmd, message);

                // transitionDurationSetting can be set, but transitionDuration is masked because it is not supported by the DS2413
                REQUIRE(cmd.responses[0].maskMode == cbox::MaskMode::EXCLUSIVE);
                REQUIRE(cmd.responses[0].mask == std::vector<cbox::obj_field_tag_t>{
                            blox_test::DigitalActuator::Block::kStateFieldNumber,
                            blox_test::DigitalActuator::Block::kTransitionDurationValueFieldNumber,
                        });

                // in simulation, the hw device will not work and therefore the state will be unknown
                // soft transition settings are kept, even if not supported
                CHECK(message.ShortDebugString() ==
                      "hwDevice: 102 "
                      "channel: 1 "
                      "desiredState: STATE_ACTIVE "
                      "transitionDurationPreset: ST_FAST "
                      "transitionDurationSetting: 250");
            }
        }
    }
}

SCENARIO("A DigitalActuator Block with Mockpins as target")
{
    cbox::getObjects().clearAll();
    platform::particle::setupSystemBlocks();
    cbox::update(0);

    WHEN("a MockPins block is created")
    {
        auto arrayId = cbox::obj_id_t(100);
        auto actId = cbox::obj_id_t(101);

        {
            auto cmd = cbox::TestCommand(arrayId, MockPinsBlock::staticTypeId());
            auto message = blox_test::MockPins::Block();

            messageToPayload(cmd, message);
            CHECK(cbox::createBlock(cmd.request, cmd.callback) == cbox::CboxError::OK);
        }

        THEN("The returned mock protobuf data is as expected")
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

        AND_WHEN("A DigitalActuator block is created that uses one of the channels")
        {
            {
                auto cmd = cbox::TestCommand(actId, DigitalActuatorBlock::staticTypeId());
                auto message = blox_test::DigitalActuator::Block();

                message.set_hwdevice(arrayId);
                message.set_channel(1);
                message.set_desiredstate(blox_test::IoArray::DigitalState::Active);

                messageToPayload(cmd, message);
                CHECK(cbox::createBlock(cmd.request, cmd.callback) == cbox::CboxError::OK);
            }

            THEN("A read of the actuator is as expected")
            {
                auto cmd = cbox::TestCommand(actId, DigitalActuatorBlock::staticTypeId());
                auto message = blox_test::DigitalActuator::Block();

                CHECK(cbox::readBlock(cmd.request, cmd.callback) == cbox::CboxError::OK);
                payloadToMessage(cmd, message);

                CHECK(message.ShortDebugString() ==
                      "hwDevice: 100 "
                      "channel: 1 "
                      "state: STATE_ACTIVE "
                      "desiredState: STATE_ACTIVE");
            }

            THEN("A read of the mock pins is as expected")
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

            AND_WHEN("When soft transitions are used")
            {
                {
                    auto writeCmd = cbox::TestCommand(actId, DigitalActuatorBlock::staticTypeId());
                    auto writeMessage = blox_test::DigitalActuator::Block();
                    writeMessage.set_transitiondurationsetting(2000);
                    writeMessage.set_transitiondurationpreset(blox_test::IoArray::TransitionDurationPreset::ST_FAST);
                    messageToPayload(writeCmd, writeMessage,
                                     {
                                         blox_test::DigitalActuator::Block::kTransitionDurationSettingFieldNumber,
                                         blox_test::DigitalActuator::Block::kTransitionDurationPresetFieldNumber,
                                     });
                    CHECK(cbox::writeBlock(writeCmd.request, writeCmd.callback) == cbox::CboxError::OK);
                }

                THEN("Then the duration setting is determined by the ST enum, unless custom is selected")
                {
                    {
                        auto readCmd = cbox::TestCommand(actId, DigitalActuatorBlock::staticTypeId());
                        auto readMsg = blox_test::DigitalActuator::Block();
                        CHECK(cbox::readBlock(readCmd.request, readCmd.callback) == cbox::CboxError::OK);
                        payloadToMessage(readCmd, readMsg);

                        REQUIRE(readCmd.responses[0].maskMode == cbox::MaskMode::EXCLUSIVE);
                        REQUIRE(readCmd.responses[0].mask == std::vector<cbox::obj_field_tag_t>{});

                        CHECK(readMsg.ShortDebugString() ==
                              "hwDevice: 100 channel: "
                              "1 state: STATE_ACTIVE "
                              "desiredState: STATE_ACTIVE "
                              "transitionDurationPreset: ST_FAST "
                              "transitionDurationSetting: 2000 "
                              "transitionDurationValue: 100");
                    }
                    {
                        auto writeCmd = cbox::TestCommand(actId, DigitalActuatorBlock::staticTypeId());
                        auto writeMessage = blox_test::DigitalActuator::Block();
                        writeMessage.set_transitiondurationsetting(2000);
                        writeMessage.set_transitiondurationpreset(blox_test::IoArray::TransitionDurationPreset::ST_CUSTOM);
                        messageToPayload(writeCmd, writeMessage,
                                         {
                                             blox_test::DigitalActuator::Block::kTransitionDurationSettingFieldNumber,
                                             blox_test::DigitalActuator::Block::kTransitionDurationPresetFieldNumber,
                                         });
                        CHECK(cbox::writeBlock(writeCmd.request, writeCmd.callback) == cbox::CboxError::OK);
                    }

                    {
                        auto readCmd = cbox::TestCommand(actId, DigitalActuatorBlock::staticTypeId());
                        auto readMsg = blox_test::DigitalActuator::Block();
                        CHECK(cbox::readBlock(readCmd.request, readCmd.callback) == cbox::CboxError::OK);
                        payloadToMessage(readCmd, readMsg);

                        REQUIRE(readCmd.responses[0].maskMode == cbox::MaskMode::EXCLUSIVE);
                        REQUIRE(readCmd.responses[0].mask == std::vector<cbox::obj_field_tag_t>{});

                        CHECK(readMsg.ShortDebugString() ==
                              "hwDevice: 100 channel: "
                              "1 state: STATE_ACTIVE "
                              "desiredState: STATE_ACTIVE "
                              "transitionDurationPreset: ST_CUSTOM "
                              "transitionDurationSetting: 2000 "
                              "transitionDurationValue: 2000");
                    }
                }
            }
        }
    }
}
