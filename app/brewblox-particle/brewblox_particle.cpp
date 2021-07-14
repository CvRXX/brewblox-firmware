/*
 * Copyright 2018 BrewPi B.V.
 *
 * This file is part of BrewBlox.
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
#include "./reset.h"
#include "AppTicks.h"
#include "Board.h"
#include "OneWireScanningFactory.h"
#include "blox/DisplaySettingsBlock.h"
#include "blox/OneWireBusBlock.h"
#include "blox/SysInfoBlock.h"
#include "blox/TouchSettingsBlock.h"
#include "blox/WiFiSettingsBlock.h"
#include "blox/stringify.h"
#include "brewblox.hpp"
#include "cbox/Box.h"
#include "cbox/EepromObjectStorage.h"
#include "cbox/ObjectContainer.h"
#include "cbox/ObjectFactory.h"
#include "cbox/Tracing.h"
#include "cbox/spark/SparkEepromAccess.h"
#include "deviceid_hal.h"
#include "platforms.h"
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
#include "DS18B20Mock.h"
#include "DS2408Mock.h"
#include "DS2413Mock.h"
#include "OneWireMockDriver.h"
#else
#include "DS248x.hpp"
#endif
#include "OneWireScanningFactory.h"

// Include serial connection for platform
#if defined(SPARK)
#if PLATFORM_ID != 3 || defined(STDIN_SERIAL)
#include "cbox/spark/ConnectionsSerial.h"
#endif
#include "cbox/spark/ConnectionsTcp.h"
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
#include "blox/Spark2PinsBlock.h"
using PinsBlock = Spark2PinsBlock;
#else
#include "blox/Spark3PinsBlock.h"
using PinsBlock = Spark3PinsBlock;
#endif

cbox::ConnectionPool&

theConnectionPool()
{
#if defined(SPARK)
    static cbox::TcpConnectionSource tcpSource(8332);
#if PLATFORM_ID != 3 || defined(STDIN_SERIAL)
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

cbox::Box&
makeBrewBloxBox()
{
    static EepromAccessImpl eeprom;
    static cbox::EepromObjectStorage objectStore(eeprom);

    cbox::ObjectContainer systemObjects{{
                                            // groups will be at position 1
                                            cbox::ContainedObject(2, 0x80, std::make_shared<SysInfoBlock>(HAL_device_ID)),
                                            cbox::ContainedObject(3, 0x80, std::make_shared<TicksBlock<TicksClass>>(ticks)),
                                            cbox::ContainedObject(4, 0x80, std::make_shared<OneWireBusBlock>(theOneWire())),
#if defined(SPARK)
                                            cbox::ContainedObject(5, 0x80, std::make_shared<WiFiSettingsBlock>()),
                                            cbox::ContainedObject(6, 0x80, std::make_shared<TouchSettingsBlock>()),
#endif
                                            cbox::ContainedObject(7, 0x80, std::make_shared<DisplaySettingsBlock>()),
                                            cbox::ContainedObject(19, 0x80, std::make_shared<PinsBlock>()),
                                        },
                                        objectStore};

    static cbox::ConnectionPool& connections = theConnectionPool();

    auto scanners = std::vector<std::unique_ptr<cbox::ScanningFactory>>{};
    scanners.reserve(1);
    scanners.push_back(std::make_unique<OneWireScanningFactory>(theOneWire()));

    static cbox::Box& box = brewblox::make_box(
        std::move(systemObjects),
        {}, // platform factories
        objectStore,
        connections,
        std::move(scanners));

    return box;
}

cbox::Box&
brewbloxBox()
{
    static cbox::Box& box = makeBrewBloxBox();
    return box;
}

#if !defined(PLATFORM_ID) || PLATFORM_ID == 3
OneWire&
theOneWire()
{
    static auto owDriver = OneWireMockDriver();
    static auto ow = OneWire(owDriver);
    owDriver.attach(std::make_shared<DS18B20Mock>(OneWireAddress(0x7E11'1111'1111'1128))); // DS18B20
    owDriver.attach(std::make_shared<DS18B20Mock>(OneWireAddress(0xDE22'2222'2222'2228))); // DS18B20
    owDriver.attach(std::make_shared<DS18B20Mock>(OneWireAddress(0xBE33'3333'3333'3328))); // DS18B20
    owDriver.attach(std::make_shared<DS2413Mock>(OneWireAddress(0x0644'4444'4444'443A)));  // DS2413
    owDriver.attach(std::make_shared<DS2408Mock>(OneWireAddress(0xDA55'5555'5555'5529)));  // DS2408
    return ow;
}
#else
OneWire&
theOneWire()
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
                stream->write(versionCsv());
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

namespace cbox {
void connectionStarted(DataOut& out)
{
    char header[] = "<!BREWBLOX,";

    out.writeBuffer(header, strlen(header));
    out.writeBuffer(versionCsv().data(), versionCsv().length());
    out.write(',');
    cbox::EncodedDataOut hexOut(out);

#if PLATFORM_ID == 3
    int resetReason = 0;
#else
    auto resetReason = System.resetReason();
#endif
    hexOut.write(resetReason);
    out.write(',');
#if PLATFORM_ID == 3
    int resetData = 0;
#else
    auto resetData = System.resetReasonData();
#endif
    hexOut.write(resetData);
    out.write(',');

    uint8_t deviceId[12];
    HAL_device_ID(deviceId, 12);
    hexOut.writeBuffer(deviceId, 12);
    out.write('>');
}

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