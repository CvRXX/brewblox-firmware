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
#include "Logger.h"
#include "blox/SysInfoBlock.h"
#include "blox/stringify.h"
#include "brewblox.hpp"
#include "cbox/Box.h"
#include "cbox/ObjectContainer.h"
#include "cbox/ObjectFactory.h"
#include "cbox/ObjectStorage.h"
#include "cbox/Tracing.h"
#include <esp_wifi.h>
#include <esp_wifi_types.h>
#include <memory>

#include "network/CboxConnectionSource.hpp"

void get_device_id(uint8_t* dest, size_t len)
{
    uint8_t mac[6];
    esp_wifi_get_mac(WIFI_IF_STA, mac);
    for (uint8_t i = 0; i < len; i++) {
        dest[i] = i < 6 ? mac[i] : 0;
    }
}

void everySecond(const asio::error_code& e, std::shared_ptr<asio::steady_timer> t, uint32_t count)
{
    if (e) {
        return;
    }
    ESP_LOGI("Tick", "%u", count);
    t->expires_at(t->expiry() + asio::chrono::seconds(1));
    t->async_wait(std::bind(everySecond, _1, std::move(t), ++count));
};

void boxUpdate(const asio::error_code& e, std::shared_ptr<asio::steady_timer> t, cbox::Box* box)
{
    const auto start = asio::chrono::steady_clock::now().time_since_epoch() / asio::chrono::milliseconds(1);
    if (e) {
        ESP_LOGE("boxupdate", "%s", e.message().c_str());
    }
    const auto now = asio::chrono::steady_clock::now().time_since_epoch() / asio::chrono::milliseconds(1);
    uint32_t millisSinceBoot = now - start;
    box->hexCommunicate();
    box->update(millisSinceBoot);
    t->expires_from_now(asio::chrono::milliseconds(1));
    t->async_wait(std::bind(boxUpdate, _1, std::move(t), box));
};

void handleReset(bool, uint8_t)
{
}

cbox::Box&
makeBrewBloxBox(asio::io_context& io)
{
    static cbox::ObjectStorageStub objectStore;

    cbox::ObjectContainer systemObjects{
        {
            cbox::ContainedObject(2, 0x80, std::make_shared<SysInfoBlock>(get_device_id)),
        },
        objectStore};

    static CboxConnectionSource tcpSource(io, 8332);
    static cbox::ConnectionPool connections{{tcpSource}};

    static cbox::Box& box = brewblox::make_box(
        std::move(systemObjects),
        {}, // platform factories
        objectStore,
        connections,
        {});

    auto timer = std::make_shared<asio::steady_timer>(io, asio::chrono::seconds(1));
    timer->async_wait(std::bind(everySecond, _1,
                                timer,
                                0));

    auto update_timer = std::make_shared<asio::steady_timer>(io, asio::chrono::milliseconds(1));
    update_timer->async_wait(std::bind(boxUpdate, _1,
                                       update_timer,
                                       &box));

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

const char*
versionCsv()
{
    static const char version[] = "esp32";
    return version;
}

namespace cbox {
void connectionStarted(DataOut& out)
{
    char header[] = "<!BREWBLOX,";

    out.writeBuffer(header, strlen(header));
    out.writeBuffer(versionCsv(), strlen(versionCsv()));
    out.write(',');
    cbox::EncodedDataOut hexOut(out);

#if PLATFORM_ID == 3
    int resetReason = 0;
#else
    auto resetReason = uint8_t(0);
#endif
    hexOut.write(resetReason);
    out.write(',');
#if PLATFORM_ID == 3
    int resetData = 0;
#else
    auto resetData = uint8_t(0);
#endif
    hexOut.write(resetData);
    out.write(',');

    uint8_t deviceId[12] = {0};
    hexOut.writeBuffer(deviceId, 12);
    out.write('>');
    out.write('\n');
}

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