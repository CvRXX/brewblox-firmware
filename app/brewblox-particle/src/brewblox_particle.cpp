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

#include "brewblox_particle.hpp"
#include "AppTicks.h"
#include "OneWireScanningFactory.hpp"
#include "SparkEepromAccess.h"
#include "TouchSettingsBlock.h"
#include "WiFiSettingsBlock.h"
#include "blocks/DisplaySettingsBlock.h"
#include "blocks/OneWireBusBlock.h"
#include "blocks/SysInfoBlock.h"
#include "blocks/stringify.h"
#include "brewblox.hpp"
#include "cbox/Box.h"
#include "cbox/EepromObjectStorage.h"
#include "cbox/ObjectContainer.h"
#include "cbox/ObjectFactory.h"
#include "cbox/Tracing.h"
#include "deviceid_hal.h"
#include "platforms.h"
#include "reset.h"
#include "spark/Board.h"
#include <memory>

using EepromAccessImpl = cbox::SparkEepromAccess;

#if defined(SPARK)
#include "rgbled.h"
void changeLedColor()
{
    LED_SetRGBColor(RGB_COLOR_MAGENTA);
}
extern void
updateFirmwareFromStream(cbox::StreamType streamType);
#else
void changeLedColor()
{
}
void updateFirmwareFromStream(cbox::StreamType)
{
}
#endif

// Include OneWire implementation depending on platform
#if !defined(PLATFORM_ID) || PLATFORM_ID == 3
#include "control/DS18B20Mock.h"
#include "control/DS2408Mock.h"
#include "control/DS2413Mock.h"
#include "control/OneWireMockDriver.h"
#else
#include "control/DS248x.hpp"
#endif
#include "OneWireScanningFactory.hpp"

// Include serial connection for platform
#if defined(SPARK)
#if PLATFORM_ID != 3
#include "ConnectionsSerial.h"
#endif
#include "ConnectionsTcp.h"
#else
#include "cbox/ConnectionsStringStream.h"

cbox::StringStreamConnectionSource&
testConnectionSource()
{
    static cbox::StringStreamConnectionSource connSource;
    return connSource;
}
#endif

#if PLATFORM_ID == 6
#include "Spark2PinsBlock.h"
using PinsBlock = Spark2PinsBlock;
#else
#include "Spark3PinsBlock.h"
using PinsBlock = Spark3PinsBlock;
#endif

cbox::ConnectionPool&

theConnectionPool()
{
#if defined(SPARK)
    static cbox::TcpConnectionSource tcpSource(8332);
#if PLATFORM_ID != 3
    static auto& boxSerial = _fetch_usbserial();
    static cbox::SerialConnectionSource serialSource(boxSerial);
    static cbox::ConnectionPool connections = {tcpSource, serialSource};
#else
    static cbox::ConnectionPool connections = {tcpSource};
#endif
#else
    static cbox::ConnectionPool connections = {testConnectionSource()};
#endif

    return connections;
}

void powerCyclePheripheral5V()
{
// The Onewire 5V on the Spark 3 can be toggled. The Spark 2 didn't have this functionality
#if PLATFORM_ID == 8
    enablePheripheral5V(false);
    ticks.delayMillis(100);
    enablePheripheral5V(true);
#endif
}

cbox::Box&
makeBrewbloxBox()
{
    static EepromAccessImpl eeprom;
    static cbox::EepromObjectStorage objectStore(eeprom);

    static cbox::ObjectContainer objects{{
                                             // groups will be at position 1
                                             cbox::ContainedObject(2, 0x80, std::shared_ptr<cbox::Object>(new SysInfoBlock(HAL_device_ID))),
                                             cbox::ContainedObject(3, 0x80, std::shared_ptr<cbox::Object>(new TicksBlock<TicksClass>(ticks))),
                                             cbox::ContainedObject(4, 0x80, std::shared_ptr<cbox::Object>(new OneWireBusBlock(setupOneWire(), powerCyclePheripheral5V))),
#if defined(SPARK)
                                             cbox::ContainedObject(5, 0x80, std::shared_ptr<cbox::Object>(new WiFiSettingsBlock())),
                                             cbox::ContainedObject(6, 0x80, std::shared_ptr<cbox::Object>(new TouchSettingsBlock())),
#endif
                                             cbox::ContainedObject(7, 0x80, std::shared_ptr<cbox::Object>(new DisplaySettingsBlock())),
                                             cbox::ContainedObject(19, 0x80, std::shared_ptr<cbox::Object>(new PinsBlock())),
                                         },
                                         objectStore};

    static cbox::ConnectionPool& connections = theConnectionPool();

    static OneWireScanningFactory oneWireScanner{cbox::CboxPtr<OneWire>(objects, 4)};

    static const std::vector<std::reference_wrapper<cbox::ScanningFactory>> scanners{{std::reference_wrapper<cbox::ScanningFactory>(oneWireScanner)}};
    static const cbox::ObjectFactory platformFactory{}; // no platform specific factories

    static cbox::Box& box = brewblox::make_box(
        objects,
        platformFactory,
        objectStore,
        connections,
        scanners);

    return box;
}

cbox::Box&
brewbloxBox()
{
    static cbox::Box& box = makeBrewbloxBox();
    return box;
}

#if !defined(PLATFORM_ID) || PLATFORM_ID == 3
OneWire&
setupOneWire()
{
    static auto owDriver = OneWireMockDriver();
    static auto ow = OneWire(owDriver);
    owDriver.attach(std::shared_ptr<OneWireMockDevice>(new DS18B20Mock(OneWireAddress(0x7E11'1111'1111'1128)))); // DS18B20
    owDriver.attach(std::shared_ptr<OneWireMockDevice>(new DS18B20Mock(OneWireAddress(0xDE22'2222'2222'2228)))); // DS18B20
    owDriver.attach(std::shared_ptr<OneWireMockDevice>(new DS18B20Mock(OneWireAddress(0xBE33'3333'3333'3328)))); // DS18B20
    owDriver.attach(std::shared_ptr<OneWireMockDevice>(new DS2413Mock(OneWireAddress(0x0644'4444'4444'443A))));  // DS2413
    owDriver.attach(std::shared_ptr<OneWireMockDevice>(new DS2408Mock(OneWireAddress(0xDA55'5555'5555'5529))));  // DS2408
    return ow;
}
#else
OneWire&
setupOneWire()
{
    static auto owDriver = DS248x(0x00);
    static auto ow = OneWire(owDriver);
    return ow;
}
#endif

Logger&
logger()
{
    static Logger logger([](Logger::LogLevel level, const std::string& log) {
        cbox::DataOut& out = theConnectionPool().logDataOut();
        out.write('<');
        const char debug[] = "DEBUG";
        const char info[] = "INFO";
        const char warn[] = "WARNING";
        const char err[] = "ERROR";

        switch (level) {
        case Logger::LogLevel::DEBUG:
            out.writeBuffer(debug, strlen(debug));
            break;
        case Logger::LogLevel::INFO:
            out.writeBuffer(info, strlen(info));
            break;
        case Logger::LogLevel::WARN:
            out.writeBuffer(warn, strlen(warn));
            break;
        case Logger::LogLevel::ERROR:
            out.writeBuffer(err, strlen(err));
            break;
        }
        out.write(':');
        for (const auto& c : log) {
            out.write(c);
        }
        out.write('>');
    });
    return logger;
}

void logEvent(const std::string& event)
{
    cbox::DataOut& out = theConnectionPool().logDataOut();
    out.write('<');
    out.write('!');
    for (const auto& c : event) {
        out.write(c);
    }
    out.write('>');
}

void updateBrewbloxBox()
{
    brewbloxBox().update(ticks.millis());
#if PLATFORM_ID == 3
    ticks.delayMillis(10); // prevent 100% cpu usage
#endif
}

#if PLATFORM_ID != PLATFORM_GCC
void updateFirmwareStreamHandler(Stream* stream)
{
    enum class DCMD : uint8_t {
        None,
        Ack,
        FlashFirmware,
    };

    auto command = DCMD::Ack;
    uint8_t invalidCommands = 0;

    while (true) {
        HAL_Delay_Milliseconds(1);
        int recv = stream->read();
        switch (recv) {
        case 'F':
            command = DCMD::FlashFirmware;
            break;
        case '\n':
            if (command == DCMD::Ack) {
                stream->write("<!FIRMWARE_UPDATER,");
                stream->write(versionCsv().c_str());
                stream->write(">\n");
                stream->flush();
                HAL_Delay_Milliseconds(10);
            } else if (command == DCMD::FlashFirmware) {
                stream->write("<!READY_FOR_FIRMWARE>\n");
                stream->flush();
                HAL_Delay_Milliseconds(10);
#if PLATFORM_ID == PLATFORM_GCC
                // just exit for sim
                HAL_Core_System_Reset_Ex(RESET_REASON_UPDATE, 0, nullptr);
#else
                bool success = system_firmwareUpdate(stream);
                System.reset(success ? RESET_USER_REASON::FIRMWARE_UPDATE_SUCCESS : RESET_USER_REASON::FIRMWARE_UPDATE_FAILED, RESET_NO_WAIT);
#endif
                break;
            } else {
                stream->write("<Invalid command received>\n");
                stream->flush();
                HAL_Delay_Milliseconds(10);
                if (++invalidCommands > 2) {
                    return;
                }
            }
            command = DCMD::Ack;
            break;
        case -1:
            continue; // empty
        default:
            command = DCMD::None;
            break;
        }
    }
}

void updateFirmwareFromStream(cbox::StreamType streamType)
{
    theConnectionPool().stopAll();
    if (streamType == cbox::StreamType::Usb) {
        updateFirmwareStreamHandler(&_fetch_usbserial());
    } else {
        TCPServer server(8332); // re-open a TCP server
        while (true) {
            HAL_Delay_Milliseconds(10); // allow thread switch so system thread can set up client
            {
                TCPClient client = server.available();
                if (client) {
                    updateFirmwareStreamHandler(&client);
                }
            }
        }
    }
}
#endif

unsigned get_device_id(uint8_t* dest, unsigned max_len)
{
    return HAL_device_ID(dest, max_len);
}

int resetReason()
{
#if PLATFORM_ID == 3
    return 0;
#else
    return System.resetReason();
#endif
}

int resetReasonData()
{
#if PLATFORM_ID == 3
    return 0;
#else
    return System.resetReasonData();
#endif
}

namespace cbox {
// handler for custom commands outside of controlbox
bool applicationCommand(uint8_t cmdId, cbox::DataIn& in, cbox::EncodedDataOut& out)
{
    switch (cmdId) {
    case 100: // firmware update
    {
        CboxError status = CboxError::OK;
        in.spool();
        if (out.crc()) {
            status = CboxError::CRC_ERROR_IN_COMMAND;
        }
        out.writeResponseSeparator();
        out.write(asUint8(status));
        out.endMessage();
        ticks.delayMillis(10);
        if (status == CboxError::OK) {
            cbox::tracing::add(AppTrace::FIRMWARE_UPDATE_STARTED);
            changeLedColor();
            brewbloxBox().disconnect();
            ticks.delayMillis(10);
#if PLATFORM_ID != PLATFORM_GCC
            updateFirmwareFromStream(in.streamType());
            // reset in case the firmware update failed
            System.reset(RESET_USER_REASON::FIRMWARE_UPDATE_FAILED, RESET_NO_WAIT);
#endif
        }
        return true;
    }
    }
    return false;
}
} // end namespace cbox
