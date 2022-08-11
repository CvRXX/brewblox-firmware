/*
 * Copyright 2020 BrewPi B.V.
 *
 * This file is part of the BrewBlox Control Library.
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

#include "TestControlPtr.hpp"
#include "control/ActuatorDigital.hpp"
#include "control/DS18B20.hpp"
#include "control/DS18B20Mock.hpp"
#include "control/DS2408.hpp"
#include "control/DS2408Mock.hpp"
#include "control/DS2413.hpp"
#include "control/DS2413Mock.hpp"
#include "control/InputDigital.hpp"
#include "control/MotorValve.hpp"
#include "control/OneWireMockDevice.hpp"
#include "control/OneWireMockDriver.hpp"

namespace Catch {
template <>
struct StringMaker<OneWireAddress> {
    static std::string convert(OneWireAddress const& value)
    {
        return value.toString();
    }
};
}

OneWireAddress
makeValidAddress(uint64_t addressBytes)
{
    auto addr = OneWireAddress{addressBytes};
    addr[7] = OneWireCrc8(&addr[0], 7);
    return addr;
}

SCENARIO("A mocked OneWire bus and mocked slaves", "[onewire]")
{
    OneWireMockDriver owMock;
    auto ow = TestControlPtr<OneWire>(new OneWire(owMock));
    ow.ptr->init();

    WHEN("No devices are on the bus, reset returns false")
    {
        CHECK(ow.ptr->reset() == false);
    }

    WHEN("No devices are on the bus, search returns 0")
    {
        OneWireAddress addr(0);
        ow.ptr->reset_search();
        CHECK(ow.ptr->search() == OneWireAddress{0});
    }

    WHEN("A mock DS18B20 is attached")
    {
        auto addr1 = makeValidAddress(0x0011223344556628);
        auto mockSensor = std::make_shared<DS18B20Mock>(addr1);
        owMock.attach(mockSensor);
        THEN("Reset returns a presence")
        {
            CHECK(ow.ptr->reset() == true);
        }

        THEN("It can be found with a bus search")
        {
            OneWireAddress addr(0);
            ow.ptr->reset();
            addr = ow.ptr->search();
            CHECK(addr == addr1);
        }

        THEN("A read without issueing a command returns 0xFF")
        {
            ow.ptr->reset();
            uint8_t v = 0;
            ow.ptr->read(v);
            CHECK(v == 0xFF);
        }

        THEN("An invalid command is ignored")
        {
            ow.ptr->reset();
            ow.ptr->write(0xFE);
            uint8_t v = 0;
            ow.ptr->read(v);
            CHECK(v == 0xFF);
        }

        THEN("With a single device on the bus, a read ROM command can return its address")
        {
            OneWireAddress addr(0);
            ow.ptr->reset();
            ow.ptr->write(0x33);
            ow.ptr->read_bytes(&addr[0], 8);
            CHECK(addr == addr1);
        }

        THEN("With a single device on the bus, a skip ROM command can select it without knowing the address")
        {
            OneWireAddress addr(0);
            ow.ptr->reset();
            ow.ptr->skip();      // skip selecting by address
            ow.ptr->write(0xB4); // read power supply
            uint8_t v = 0;
            ow.ptr->read(v);
            CHECK(v == 0x80);
        }

        THEN("A OneWire sensor can use it on the fake bus")
        {
            DS18B20 sensor(ow, addr1);
            sensor.update();
            CHECK(sensor.value().has_value() == false); // a reset will be detected, triggering a re-init
            sensor.update();
            CHECK(sensor.value().has_value() == true);
            CHECK(sensor.value() == 20.0);

            mockSensor->setTemperature(temp_t{21.0});
            CHECK(mockSensor->getTemperature() == 21.0);
            sensor.update();
            CHECK(sensor.value() == 21.0);

            mockSensor->setTemperature(temp_t{-10.0});
            CHECK(mockSensor->getTemperature() == -10.0);
            sensor.update();
            CHECK(sensor.value() == -10.0);
        }

        WHEN("The sensor is disconnected")
        {
            DS18B20 sensor(ow, addr1);
            mockSensor->setConnected(false);
            sensor.update();
            sensor.update();

            THEN("It reads as invalid")
            {
                CHECK(sensor.value().has_value() == false);
            }

            THEN("When it comes back, the first value is invalid and the second is valid (reset detection)")
            {
                mockSensor->setConnected(true);
                sensor.update();
                CHECK(sensor.value().has_value() == false);
                sensor.update();
                CHECK(sensor.value().has_value() == true);
            }
        }

        WHEN("Communication bitflips when reading the sensor occur")
        {
            DS18B20 sensor(ow, addr1);
            mockSensor->setTemperature(temp_t{21.0});
            sensor.update();
            sensor.update();

            THEN("A single bitflip will not give an error due to a retry")
            {
                // 9 scratchpad bytes are read, 81 bits
                mockSensor->flipReadBits({13});
                sensor.update();
                CHECK(sensor.value().has_value() == true);
                CHECK(sensor.value() == 21.0);
            }

            THEN("A bitflip in 2 scratchpads will give an error")
            {
                mockSensor->flipReadBits({13, 81 + 13});
                sensor.update();
                CHECK(sensor.value().has_value() == false);
            }
        }

        AND_WHEN("Another sensor is connected")
        {
            auto addr2 = makeValidAddress(0x0099223344556628);
            auto mockSensor2 = std::make_shared<DS18B20Mock>(addr2);
            owMock.attach(mockSensor2);

            DS18B20 sensor1(ow, addr1);
            DS18B20 sensor2(ow, addr2);

            THEN("A bus search finds two sensors")
            {
                OneWireAddress addr(0);
                ow.ptr->reset();
                ow.ptr->reset_search();
                addr = ow.ptr->search();
                CHECK(addr == OneWireAddress(addr1));

                addr = ow.ptr->search();
                CHECK(addr == OneWireAddress(addr2));

                addr = ow.ptr->search();
            }

            sensor1.update();
            sensor2.update();
            sensor1.update();
            sensor2.update();
            CHECK(sensor1.value() == 20.0);
            CHECK(sensor2.value() == 20.0);

            mockSensor->setTemperature(temp_t{21.0});
            mockSensor2->setTemperature(temp_t{22.0});
            CHECK(mockSensor->getTemperature() == 21.0);
            CHECK(mockSensor2->getTemperature() == 22.0);
            sensor1.update();
            sensor2.update();
            CHECK(sensor1.value() == 21.0);
            CHECK(sensor2.value() == 22.0);
        }
    }

    WHEN("A mock DS2413 is attached")
    {
        auto addr3 = makeValidAddress(0x002222334455663A);
        auto ds1mock = std::make_shared<DS2413Mock>(addr3);
        owMock.attach(ds1mock);
        THEN("Reset returns a presence")
        {
            CHECK(ow.ptr->reset() == true);
        }

        THEN("It can be found with a bus search")
        {
            OneWireAddress addr(0);
            ow.ptr->reset();
            addr = ow.ptr->search();
            CHECK(addr == addr3);
        }

        THEN("A DS2413 class can use it as output")
        {
            using State = ActuatorDigitalBase::State;

            auto ds1 = std::make_shared<DS2413>(ow, addr3);
            auto ds1Ptr = TestControlPtr<IoArray>(ds1);
            ds1->update();

            CHECK(ds1->connected() == true);
            ActuatorDigital act1(ds1Ptr, 1);
            ActuatorDigital act2(ds1Ptr, 2);

            CHECK(act1.state() == State::Inactive);
            CHECK(act2.state() == State::Inactive);
            CHECK(ds1->readChannel(1) == IoValue::Digital{State::Inactive});
            CHECK(ds1->readChannel(2) == IoValue::Digital{State::Inactive});

            act1.state(State::Active);
            CHECK(act1.state() == State::Active);
            CHECK(ds1->readChannel(1) == IoValue::Digital{State::Active});
            CHECK(ds1->readChannel(2) == IoValue::Digital{State::Inactive});

            act2.state(State::Active);
            CHECK(act2.state() == State::Active);
            CHECK(ds1->readChannel(1) == IoValue::Digital{State::Active});
            CHECK(ds1->readChannel(2) == IoValue::Digital{State::Active});

            act1.state(State::Inactive);
            CHECK(act1.state() == State::Inactive);
            CHECK(ds1->readChannel(1) == IoValue::Digital{State::Inactive});
            CHECK(ds1->readChannel(2) == IoValue::Digital{State::Active});

            act2.state(State::Inactive);
            CHECK(act2.state() == State::Inactive);
            CHECK(ds1->readChannel(1) == IoValue::Digital{State::Inactive});
            CHECK(ds1->readChannel(2) == IoValue::Digital{State::Inactive});
        }

        THEN("A DS2413 class can use it as input")
        {
            using State = InputDigital::State;
            auto ds1 = std::make_shared<DS2413>(ow, addr3);
            auto ds1Ptr = TestControlPtr<IoArray>(ds1);
            InputDigital in1(ds1Ptr, 1);
            InputDigital in2(ds1Ptr, 2);

            ds1->update();
            CHECK(in1.state() == State::Inactive);
            CHECK(in2.state() == State::Inactive);

            ds1mock->setExternalPullDownA(true);
            ds1->update();

            CHECK(in1.state() == State::Active);
            CHECK(in2.state() == State::Inactive);

            ds1mock->setExternalPullDownA(false);
            ds1mock->setExternalPullDownB(true);

            ds1->update();
            auto v1 = ds1->readChannel(1);
            CHECK(v1 == IoValue::Digital{State::Inactive});
            auto v2 = ds1->readChannel(2);
            CHECK(v2 == IoValue::Digital{State::Active});
        }
    }

    WHEN("A mock DS2408 is attached")
    {
        auto addr4 = makeValidAddress(0x0022223344556629);
        auto ds2408mock = std::make_shared<DS2408Mock>(addr4);
        owMock.attach(ds2408mock);
        THEN("Reset returns a presence")
        {
            CHECK(ow.ptr->reset() == true);
        }

        THEN("It can be found with a bus search")
        {
            OneWireAddress addr(0);
            ow.ptr->reset();
            addr = ow.ptr->search();
            CHECK(addr == addr4);
        }

        THEN("A DS2408 class can use it as input on some pins and output on others")
        {
            using State = InputDigital::State;
            auto ds2 = std::make_shared<DS2408>(ow, addr4);
            auto ds2Ptr = TestControlPtr<IoArray>(ds2);

            InputDigital in1(ds2Ptr, 1);
            InputDigital in2(ds2Ptr, 2);
            ActuatorDigital act3(ds2Ptr, 3);
            ActuatorDigital act4(ds2Ptr, 4);
            InputDigital in5(ds2Ptr, 5);
            InputDigital in6(ds2Ptr, 6);
            ActuatorDigital act7(ds2Ptr, 7);
            ActuatorDigital act8(ds2Ptr, 8);

            ds2->update();
            CHECK(ds2->connected() == true);
            CHECK(in1.state() == State::Inactive);
            CHECK(in2.state() == State::Inactive);
            CHECK(act3.state() == State::Inactive);
            CHECK(act4.state() == State::Inactive);
            CHECK(in5.state() == State::Inactive);
            CHECK(in6.state() == State::Inactive);
            CHECK(act7.state() == State::Inactive);
            CHECK(act8.state() == State::Inactive);

            // bit index in mock starts at 0
            ds2408mock->setExternalPullDown(0, false);
            ds2408mock->setExternalPullDown(1, true);
            ds2408mock->setExternalPullDown(4, true);
            ds2408mock->setExternalPullDown(5, false);

            act3.state(State::Active);
            act4.state(State::Inactive);
            act7.state(State::Inactive);
            act8.state(State::Active);

            ds2->update();
            CHECK(in1.state() == State::Inactive);
            CHECK(in2.state() == State::Active);
            CHECK(act3.state() == State::Active);
            CHECK(act4.state() == State::Inactive);
            CHECK(in5.state() == State::Active);
            CHECK(in6.state() == State::Inactive);
            CHECK(act7.state() == State::Inactive);
            CHECK(act8.state() == State::Active);
        }
    }

    WHEN("3x DS18B20, DS2413, and DS2408 are connected")
    {
        auto addrSensor1 = OneWireAddress(0x7E11'1111'1111'1128);
        auto addrSensor2 = OneWireAddress(0xDE22'2222'2222'2228);
        auto addrSensor3 = OneWireAddress(0xBE33'3333'3333'3328);
        auto addrDS2413 = OneWireAddress(0x0644'4444'4444'443A);
        auto addrDS2408 = OneWireAddress(0xDA55'5555'5555'5529);
        owMock.attach(std::make_shared<DS18B20Mock>(addrSensor1)); // DS18B20
        owMock.attach(std::make_shared<DS18B20Mock>(addrSensor2)); // DS18B20
        owMock.attach(std::make_shared<DS18B20Mock>(addrSensor3)); // DS18B20
        owMock.attach(std::make_shared<DS2413Mock>(addrDS2413));   // DS2413
        owMock.attach(std::make_shared<DS2408Mock>(addrDS2408));   // DS2408

        THEN("A bus search finds 5 devices")
        {
            ow.ptr->reset_search();

            OneWireAddress addr(0);
            addr = ow.ptr->search();
            CHECK(addr == addrSensor2);

            addr = ow.ptr->search();
            CHECK(addr == addrSensor1);

            addr = ow.ptr->search();
            CHECK(addr == addrSensor3);

            addr = ow.ptr->search();
            CHECK(addr == addrDS2413);

            addr = ow.ptr->search();
            CHECK(addr == addrDS2408);

            addr = ow.ptr->search();
            CHECK(addr == OneWireAddress(0));
        }

        THEN("Then target search can select only one family code to be found")
        {
            ow.ptr->target_search(DS18B20Mock::family_code);

            OneWireAddress addr(0);
            addr = ow.ptr->search();
            CHECK(addr == addrSensor2);

            addr = ow.ptr->search();
            CHECK(addr == addrSensor1);

            addr = ow.ptr->search();
            CHECK(addr == addrSensor3);

            addr = ow.ptr->search();
            CHECK(addr == OneWireAddress(0));

            ow.ptr->target_search(DS2413Mock::family_code);
            addr = ow.ptr->search();
            CHECK(addr == addrDS2413);

            addr = ow.ptr->search();
            CHECK(addr == OneWireAddress(0));

            ow.ptr->target_search(DS2408Mock::family_code);
            addr = ow.ptr->search();
            CHECK(addr == addrDS2408);

            addr = ow.ptr->search();
            CHECK(addr == OneWireAddress(0));
        }
    }
}
