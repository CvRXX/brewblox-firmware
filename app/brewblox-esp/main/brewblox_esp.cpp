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

#include "AppTicks.h"
#include "DS248x.hpp"
#include "I2cScanningFactory.hpp"
#include "Logger.h"
#include "MockTicks.h"
#include "OneWireMultiScanningFactory.hpp"
#include "RecurringTask.hpp"
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

using namespace std::placeholders;

unsigned get_device_id(uint8_t* dest, unsigned len)
{
    uint8_t mac[6];
    esp_wifi_get_mac(WIFI_IF_STA, mac);
    for (uint8_t i = 0; i < len; i++) {
        dest[i] = i < 6 ? mac[i] : 0;
    }
    return len;
}

void handleReset(bool, uint8_t)
{
}

cbox::Box&
makeBrewBloxBox(asio::io_context& io)
{
    static cbox::FileObjectStorage objectStore{"/blocks/"};

    static Ticks<MockTicks> ticks;

    cbox::ObjectContainer systemObjects{
        {
            cbox::ContainedObject(2, 0x80, std::make_shared<SysInfoBlock>(get_device_id)),
            cbox::ContainedObject(3, 0x80, std::make_shared<TicksBlock<Ticks<MockTicks>>>(ticks)),
            cbox::ContainedObject(7, 0x80, std::make_shared<DisplaySettingsBlock>()),
        },
        objectStore};

    static cbox::ConnectionPool connections{{}}; // managed externally

    static OneWireMultiScanningFactory oneWireScanner;
    static I2cScanningFactory i2cScanner;

    static const std::vector<std::reference_wrapper<cbox::ScanningFactory>> scanners{{std::reference_wrapper<cbox::ScanningFactory>(i2cScanner), std::reference_wrapper<cbox::ScanningFactory>(oneWireScanner)}};
    static const cbox::ObjectFactory platformFactory{{ExpOwGpioBlock::staticTypeId(), std::make_shared<ExpOwGpioBlock>}};

    static cbox::Box& box = brewblox::make_box(
        std::move(systemObjects),
        platformFactory,
        objectStore, connections, scanners);

    box.loadObjectsFromStorage(); // init box and load stored objects

    static auto updater = RecurringTask(
        io, asio::chrono::milliseconds(10),
        RecurringTask::IntervalType::FROM_EXECUTION,
        []() {
            static const auto start = asio::chrono::steady_clock::now().time_since_epoch() / asio::chrono::milliseconds(1);
            const auto now = asio::chrono::steady_clock::now().time_since_epoch() / asio::chrono::milliseconds(1);
            uint32_t millisSinceBoot = now - start;
            box.update(millisSinceBoot);
        });
    updater.start();

    static auto memoryReporter = RecurringTask(
        io, asio::chrono::milliseconds(1000),
        RecurringTask::IntervalType::FROM_EXECUTION,
        []() {
            ESP_LOGI("MEM", "Free heap %u", xPortGetFreeHeapSize());
        });
    memoryReporter.start();

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
    switch (cmdId) {
    case 100: // firmware update
    {
        return true;
    }
    }
    return false;
}

} // end namespace cbox