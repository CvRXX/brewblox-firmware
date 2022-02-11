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

#include "../proto/DS2413_test.pb.h"
#include "../proto/DigitalActuator_test.pb.h"
#include "../proto/MockPins_test.pb.h"
#include "BrewbloxTestBox.h"
#include "OneWireAddress.h"
#include "blocks/DS2413Block.h"
#include "blocks/DigitalActuatorBlock.h"
#include "blocks/MockPinsBlock.h"
#include "cbox/CboxPtr.h"
#include "cbox/DataStreamIo.h"
#include <sstream>

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
    WHEN("a DS2413 block is created")
    {
        BrewbloxTestBox testBox;
        using commands = cbox::Box::CommandID;
        auto ds2413Id = cbox::obj_id_t(100);
        auto actId = cbox::obj_id_t(101);

        testBox.reset();

        testBox.put(uint16_t(0)); // msg id
        testBox.put(commands::CREATE_OBJECT);
        testBox.put(cbox::obj_id_t(ds2413Id));
        testBox.put(uint8_t(0xFF));
        testBox.put(DS2413Block::staticTypeId());

        auto message = blox_test::DS2413::Block();
        message.set_address(0x0644'4444'4444'443A);
        message.set_onewirebusid(4);

        testBox.put(message);

        testBox.processInput();
        CHECK(testBox.lastReplyHasStatusOk());
        testBox.put(uint16_t(0)); // msg id
        testBox.put(commands::READ_OBJECT);
        testBox.put(cbox::obj_id_t(ds2413Id));

        auto decoded = blox_test::DS2413::Block();
        testBox.processInputToProto(decoded);

        THEN("The returned protobuf data is as expected")
        {
            CHECK(testBox.lastReplyHasStatusOk());
            CHECK(decoded.ShortDebugString() == "address: 451560922637681722 connected: true oneWireBusId: 4 channels { id: 1 } channels { id: 2 }");
        }

        THEN("The writable settings match what was sent")
        {
            auto lookup = brewbloxBox().makeCboxPtr<DS2413Block>(ds2413Id);
            auto devicePtr = lookup.lock();
            REQUIRE(devicePtr);
            CHECK(devicePtr->get().address() == OneWireAddress(0x0644'4444'4444'443A));
        }

        AND_WHEN("A DigitalActuator block is created that uses one of the channels")
        {
            testBox.put(uint16_t(0)); // msg id
            testBox.put(commands::CREATE_OBJECT);
            testBox.put(cbox::obj_id_t(actId));
            testBox.put(uint8_t(0xFF));
            testBox.put(DigitalActuatorBlock::staticTypeId());

            auto message = blox_test::DigitalActuator::Block();
            message.set_hwdevice(ds2413Id);
            message.set_channel(1);
            message.set_desiredstate(blox_test::IoArray::DigitalState::Active);

            testBox.put(message);

            testBox.processInput();
            CHECK(testBox.lastReplyHasStatusOk());

            THEN("A read of the actuator is as expected")
            {
                testBox.put(uint16_t(0)); // msg id
                testBox.put(commands::READ_OBJECT);
                testBox.put(cbox::obj_id_t(actId));

                auto decoded = blox_test::DigitalActuator::Block();
                testBox.processInputToProto(decoded);

                CHECK(decoded.ShortDebugString() == "hwDevice: 100 channel: 1 state: STATE_ACTIVE desiredState: STATE_ACTIVE");
            }
            THEN("A read of the DS2413 is as expected")
            {
                testBox.put(uint16_t(0)); // msg id
                testBox.put(commands::READ_OBJECT);
                testBox.put(cbox::obj_id_t(ds2413Id));

                auto decoded = blox_test::DS2413::Block();
                testBox.processInputToProto(decoded);

                // DS2413 proto doesn't change when channels are used, but leaving this here for when we change our mind
                CHECK(decoded.ShortDebugString() == "address: 451560922637681722 connected: true oneWireBusId: 4 channels { id: 1 } channels { id: 2 }");
            }
        }

        AND_WHEN("A DigitalActuator block is created before the target DS2413 block is created")
        {
            auto ds2413Id2 = cbox::obj_id_t(102);

            testBox.put(uint16_t(0)); // msg id
            testBox.put(commands::CREATE_OBJECT);
            testBox.put(cbox::obj_id_t(actId));
            testBox.put(uint8_t(0xFF));
            testBox.put(DigitalActuatorBlock::staticTypeId());

            auto message = blox_test::DigitalActuator::Block();
            message.set_hwdevice(ds2413Id2);
            message.set_channel(1);
            message.set_desiredstate(blox_test::IoArray::DigitalState::Active);

            testBox.put(message);

            testBox.processInput();
            CHECK(testBox.lastReplyHasStatusOk());

            THEN("The configured channel is not lost and the actuator reads as expected")
            {
                testBox.put(uint16_t(0)); // msg id
                testBox.put(commands::READ_OBJECT);
                testBox.put(cbox::obj_id_t(actId));

                auto decoded = blox_test::DigitalActuator::Block();
                testBox.processInputToProto(decoded);

                // in simulation, the hw device will not work and therefore the state will be unknown
                CHECK(decoded.ShortDebugString() == "hwDevice: 102 channel: 1 desiredState: STATE_ACTIVE strippedFields: 3");
            }
        }
    }
}

SCENARIO("A DigitalActuator Block with Mockpins as target")
{
    WHEN("a MockPins block is created")
    {
        BrewbloxTestBox testBox;
        using commands = cbox::Box::CommandID;
        auto arrayId = cbox::obj_id_t(100);
        auto actId = cbox::obj_id_t(101);

        testBox.reset();

        testBox.put(uint16_t(0)); // msg id
        testBox.put(commands::CREATE_OBJECT);
        testBox.put(cbox::obj_id_t(arrayId));
        testBox.put(uint8_t(0xFF));
        testBox.put(MockPinsBlock::staticTypeId());

        auto message = blox_test::MockPins::Block();

        testBox.put(message);

        testBox.processInput();
        CHECK(testBox.lastReplyHasStatusOk());
        testBox.put(uint16_t(0)); // msg id
        testBox.put(commands::READ_OBJECT);
        testBox.put(cbox::obj_id_t(arrayId));

        auto decoded = blox_test::MockPins::Block();
        testBox.processInputToProto(decoded);

        THEN("The returned mock protobuf data is as expected")
        {
            CHECK(testBox.lastReplyHasStatusOk());
            CHECK(decoded.ShortDebugString() == "channels { id: 1 } channels { id: 2 } channels { id: 3 } channels { id: 4 } channels { id: 5 } channels { id: 6 } channels { id: 7 } channels { id: 8 }");
        }

        AND_WHEN("A DigitalActuator block is created that uses one of the channels")
        {
            testBox.put(uint16_t(0)); // msg id
            testBox.put(commands::CREATE_OBJECT);
            testBox.put(cbox::obj_id_t(actId));
            testBox.put(uint8_t(0xFF));
            testBox.put(DigitalActuatorBlock::staticTypeId());

            auto message = blox_test::DigitalActuator::Block();
            message.set_hwdevice(arrayId);
            message.set_channel(1);
            message.set_desiredstate(blox_test::IoArray::DigitalState::Active);

            testBox.put(message);

            testBox.processInput();
            CHECK(testBox.lastReplyHasStatusOk());

            THEN("A read of the actuator is as expected")
            {
                testBox.put(uint16_t(0)); // msg id
                testBox.put(commands::READ_OBJECT);
                testBox.put(cbox::obj_id_t(actId));

                auto decoded = blox_test::DigitalActuator::Block();
                testBox.processInputToProto(decoded);

                CHECK(decoded.ShortDebugString() == "hwDevice: 100 channel: 1 state: STATE_ACTIVE desiredState: STATE_ACTIVE");
            }
            THEN("A read of the mock pins is as expected")
            {
                testBox.put(uint16_t(0)); // msg id
                testBox.put(commands::READ_OBJECT);
                testBox.put(cbox::obj_id_t(arrayId));

                auto decoded = blox_test::MockPins::Block();
                testBox.processInputToProto(decoded);

                // Mockpins proto doesn't change when channels are used, but leaving this here for when we change our mind
                CHECK(decoded.ShortDebugString() == "channels { id: 1 } channels { id: 2 } channels { id: 3 } channels { id: 4 } channels { id: 5 } channels { id: 6 } channels { id: 7 } channels { id: 8 }");
            }
        }
    }
}
