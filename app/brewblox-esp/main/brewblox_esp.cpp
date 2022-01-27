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

#include "AppTicks.h"
#include "DS248x.hpp"
#include "I2cScanningFactory.hpp"
#include "Logger.h"
#include "MockTicks.h"
#include "OneWireMultiScanningFactory.hpp"
#include "RecurringTask.hpp"
#include "TicksEsp.h"
#include "blox/DisplaySettingsBlock.h"
#include "blox/ExpOwGpioBlock.hpp"
#include "blox/SysInfoBlock.h"
#include "blox/TicksBlock.h"
#include "blox/stringify.h"
#include "brewblox.hpp"
#include "cbox/Box.h"
#include "cbox/FileObjectStorage.h"
#include "cbox/ObjectContainer.h"
#include "cbox/ObjectFactory.h"
#include "cbox/Tracing.h"
#include <asio.hpp>
#include <esp_log.h>
#include <esp_wifi.h>
#include <esp_wifi_types.h>
#include <functional>
#include <memory>

// platform specific implementation for prototype in brewblox.hpp
// returns actual bytes written
// must be called after wifi init to have valid mac address
unsigned get_device_id(uint8_t* dest, unsigned max_len)
{
    uint8_t mac[6];
    if (esp_wifi_get_mac(WIFI_IF_STA, mac) == ESP_OK) {
        uint8_t i;
        for (i = 0; i < max_len && i < 6; i++) {
            dest[i] = mac[i];
        }
        return i;
    }
    return 0;
}

int resetReason()
{
    return 0; // todo
}

int resetReasonData()
{
    return 0; // todo
}

void handleReset(bool, uint8_t)
{
}

cbox::Box&
makeBrewbloxBox(asio::io_context& io)
{
    static cbox::FileObjectStorage objectStore{"/blocks/"};

    static Ticks<TicksEsp> ticks;

    static cbox::ObjectContainer objects{
        {
            cbox::ContainedObject(2, 0x80, std::shared_ptr<cbox::Object>(new SysInfoBlock(get_device_id))),
            cbox::ContainedObject(3, 0x80, std::shared_ptr<cbox::Object>(new TicksBlock<Ticks<TicksEsp>>(ticks))),
            cbox::ContainedObject(7, 0x80, std::shared_ptr<cbox::Object>(new DisplaySettingsBlock())),
        },
        objectStore};

    static cbox::ConnectionPool connections{{}}; // managed externally

    static OneWireMultiScanningFactory oneWireScanner;
    static I2cScanningFactory i2cScanner;

    static const std::vector<std::reference_wrapper<cbox::ScanningFactory>> scanners{{std::reference_wrapper<cbox::ScanningFactory>(i2cScanner), std::reference_wrapper<cbox::ScanningFactory>(oneWireScanner)}};
    static const cbox::ObjectFactory platformFactory{cbox::makeFactoryEntry<ExpOwGpioBlock>()};

    static cbox::Box& box = brewblox::make_box(
        objects,
        platformFactory,
        objectStore, connections, scanners);

    box.loadObjectsFromStorage(); // init box and load stored objects

    box.discoverNewObjects(); // discover new/moved devices

    static auto updater = RecurringTask(
        io, asio::chrono::milliseconds(10),
        RecurringTask::IntervalType::FROM_EXECUTION,
        []() {
            static const auto start = asio::chrono::steady_clock::now().time_since_epoch() / asio::chrono::milliseconds(1);
            const auto now = asio::chrono::steady_clock::now().time_since_epoch() / asio::chrono::milliseconds(1);
            uint32_t millisSinceBoot = now - start;
            box.update(millisSinceBoot);
            return true;
        });
    updater.start();

    // static auto memoryReporter = RecurringTask(
    //     io, asio::chrono::milliseconds(1000),
    //     RecurringTask::IntervalType::FROM_EXECUTION,
    //     []() {
    //         ESP_LOGI("MEM", "Free heap %u", xPortGetFreeHeapSize());
    //     });
    // memoryReporter.start();

    return box;
}

Logger&
logger()
{
    static Logger logger([](Logger::LogLevel level, const std::string& log) {
        // cbox::DataOut& out = theConnectionPool().logDataOut();
        // out.write('<');
        // const char debug[] = "DEBUG";
        // const char info[] = "INFO";
        // const char warn[] = "WARNING";
        // const char err[] = "ERROR";

        // switch (level) {
        // case Logger::LogLevel::DEBUG:
        //     out.writeBuffer(debug, strlen(debug));
        //     break;
        // case Logger::LogLevel::INFO:
        //     out.writeBuffer(info, strlen(info));
        //     break;
        // case Logger::LogLevel::WARN:
        //     out.writeBuffer(warn, strlen(warn));
        //     break;
        // case Logger::LogLevel::ERROR:
        //     out.writeBuffer(err, strlen(err));
        //     break;
        // }
        // out.write(':');
        // for (const auto& c : log) {
        //     out.write(c);
        // }
        // out.write('>');
    });
    return logger;
}

void logEvent(const std::string& event)
{
    // cbox::DataOut& out = theConnectionPool().logDataOut();
    // out.write('<');
    // out.write('!');
    // for (const auto& c : event) {
    //     out.write(c);
    // }
    // out.write('>');
}

namespace cbox {
// handler for custom commands outside of controlbox
bool applicationCommand(uint8_t cmdId, cbox::DataIn& in, cbox::EncodedDataOut& out)
{
    // no custom commands
    return false;
}

} // end namespace cbox