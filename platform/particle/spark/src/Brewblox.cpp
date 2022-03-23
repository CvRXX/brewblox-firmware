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

#include "spark/Brewblox.hpp"
#include "AppTicks.hpp"
#include "blocks/DisplaySettingsBlock.hpp"
#include "blocks/OneWireBusBlock.hpp"
#include "blocks/SysInfoBlock.hpp"
#include "blocks/stringify.hpp"
#include "cbox/Box.hpp"
#include "cbox/Hex.hpp"
#include "deviceid_hal.h"
#include "platforms.h"
#include "proto/proto_version.h"
#include "rgbled.h"
#include "spark/Board.hpp"
#include "spark/Connection.hpp"
#include "spark/SparkEepromAccess.hpp"
#include "spark/TouchSettingsBlock.hpp"
#include "spark/WiFiSettingsBlock.hpp"
#include <memory>

// Include OneWire implementation depending on platform
#if PLATFORM_ID == PLATFORM_GCC
#include "control/DS18B20Mock.hpp"
#include "control/DS2408Mock.hpp"
#include "control/DS2413Mock.hpp"
#include "control/OneWireMockDriver.hpp"
#else
#include "control/DS248x.hpp"
#endif
#include "blocks/OneWireScanningFactory.hpp"

// Include serial connection for platform
#if defined(SPARK)
#if PLATFORM_ID != PLATFORM_GCC
#include "spark/ConnectionSourceSerial.hpp"
#endif
#include "spark/ConnectionSourceTcp.hpp"
#else
#include "cbox/ConnectionSourceStringStream.hpp"
#endif

#if PLATFORM_ID == PLATFORM_PHOTON
#include "spark/Spark2PinsBlock.hpp"
using PinsBlock = platform::particle::Spark2PinsBlock;
#else
#include "spark/Spark3PinsBlock.hpp"
using PinsBlock = platform::particle::Spark3PinsBlock;
#endif

namespace platform::particle {

ConnectionPool& getConnectionPool()
{
#if defined(SPARK)
    static TcpConnectionSource tcpSource(8332);
#if PLATFORM_ID == PLATFORM_GCC
    static ConnectionPool pool = {tcpSource};
#else
    static auto& boxSerial = _fetch_usbserial();
    static SerialConnectionSource serialSource(boxSerial);
    static ConnectionPool pool = {tcpSource, serialSource};
#endif
#else
    static StringStreamConnectionSource stringStreamSource;
    static ConnectionPool pool = {stringStreamSource};
#endif

    return pool;
}

void powerCyclePheripheral5V()
{
// The Onewire 5V on the Spark 3 can be toggled. The Spark 2 didn't have this functionality
#if PLATFORM_ID == PLATFORM_P1
    enablePheripheral5V(false);
    ticks.delayMillis(100);
    enablePheripheral5V(true);
#endif
}

OneWire& getOneWire()
{
#if PLATFORM_ID == PLATFORM_GCC
    static auto owDriver = OneWireMockDriver();
    static auto ow = OneWire(owDriver);
    owDriver.attach(std::shared_ptr<OneWireMockDevice>(new DS18B20Mock(OneWireAddress(0x7E11'1111'1111'1128)))); // DS18B20
    owDriver.attach(std::shared_ptr<OneWireMockDevice>(new DS18B20Mock(OneWireAddress(0xDE22'2222'2222'2228)))); // DS18B20
    owDriver.attach(std::shared_ptr<OneWireMockDevice>(new DS18B20Mock(OneWireAddress(0xBE33'3333'3333'3328)))); // DS18B20
    owDriver.attach(std::shared_ptr<OneWireMockDevice>(new DS2413Mock(OneWireAddress(0x0644'4444'4444'443A))));  // DS2413
    owDriver.attach(std::shared_ptr<OneWireMockDevice>(new DS2408Mock(OneWireAddress(0xDA55'5555'5555'5529))));  // DS2408
    return ow;
#else
    static auto owDriver = DS248x(0x00);
    static auto ow = OneWire(owDriver);
    return ow;
#endif
}

BuzzerClass& getBuzzer()
{
    static BuzzerClass buzzer;
    return buzzer;
}

void setupSystemBlocks()
{
    cbox::objects.init({
        cbox::ContainedObject(2, std::shared_ptr<cbox::Object>(new SysInfoBlock(HAL_device_ID))),
            cbox::ContainedObject(3, std::shared_ptr<cbox::Object>(new TicksBlock<TicksClass>(ticks))),
            cbox::ContainedObject(4, std::shared_ptr<cbox::Object>(new OneWireBusBlock(getOneWire(), powerCyclePheripheral5V))),
#if defined(SPARK)
            cbox::ContainedObject(5, std::shared_ptr<cbox::Object>(new WiFiSettingsBlock())),
            cbox::ContainedObject(6, std::shared_ptr<cbox::Object>(new TouchSettingsBlock())),
#endif
            cbox::ContainedObject(7, std::shared_ptr<cbox::Object>(new DisplaySettingsBlock())),
            cbox::ContainedObject(19, std::shared_ptr<cbox::Object>(new PinsBlock())),
    });

    cbox::objects.setObjectsStartId(cbox::userStartId);
}

std::string deviceIdStringInit()
{
    uint8_t id[12];
    auto len = get_device_id(id, 12);
    std::string hex;
    hex.reserve(len);
    for (uint8_t i = 0; i < len; i++) {
        auto pair = cbox::d2h(id[i]);
        hex.push_back(pair.first);
        hex.push_back(pair.second);
    }
    return hex;
}

const std::string& deviceIdString()
{
    static std::string hexId;
    if (hexId.empty()) {
        // device ID can be unknown before wifi is initialized
        hexId = deviceIdStringInit();
    }
    return hexId;
}

unsigned get_device_id(uint8_t* dest, unsigned max_len)
{
    return HAL_device_ID(dest, max_len);
}

const std::string& versionCsv()
{
#ifdef __INTELLISENSE__
#define GIT_VERSION ""
#define GIT_DATE ""
#endif

    static const std::string version = GIT_VERSION "," COMPILED_PROTO_VERSION "," GIT_DATE "," COMPILED_PROTO_DATE "," stringify(SYSTEM_VERSION_STRING) "," stringify(PLATFORM_NAME);
    return version;
}

int resetReason()
{
#if PLATFORM_ID == PLATFORM_GCC
    return 0;
#else
    return System.resetReason();
#endif
}

int resetReasonData()
{
#if PLATFORM_ID == PLATFORM_GCC
    return 0;
#else
    return System.resetReasonData();
#endif
}
} // end namespace platform::particle
