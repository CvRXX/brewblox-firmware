#include "intellisense.hpp"

#include "Brewblox.hpp"
#include "ExpOwGpio.hpp"
#include "HttpHandler.hpp"
#include "I2cScanningFactory.hpp"
#include "RecurringTask.hpp"
#include "Spark4.hpp"
#include "TFT035.hpp"
#include "blox_hal/hal_delay.hpp"
#include "cbox/Box.hpp"
#include "control/DS248x.hpp"
#include "control/OneWire.hpp"
#include "control/TempSensor.hpp"
// #include "esp_heap_caps.h"
// #include "esp_heap_trace.h"
#include "FT6236.hpp"
#include "TFT035.hpp"
#include "TicksEsp.h"
#include "blox_hal/hal_delay.hpp"
#include "dynamic_gui/dynamicGui.hpp"
#include "gui.hpp"
#include "lvgl.h"
#include "network/CboxConnection.hpp"
#include "network/CboxServer.hpp"
#include "network/ethernet.hpp"
#include "network/mdns.hpp"
#include "network/wifi.hpp"
#include "static_gui/staticGui.hpp"
#include <algorithm>
#include <asio.hpp>
#include <esp_log.h>
#include <esp_spiffs.h>
#include <functional>
#include <iomanip>
#include <memory>
#include <sstream>

void mount_blocks_spiff()
{
    esp_vfs_spiffs_conf_t conf = {
        .base_path = "/blocks",
        .partition_label = "blocks",
        .max_files = 1,
        .format_if_mount_failed = true};

    // Use settings defined above to initialize and mount SPIFFS filesystem.
    // Note: esp_vfs_spiffs_register is an all-in-one convenience function.
    esp_err_t ret = esp_vfs_spiffs_register(&conf);

    const char* TAG = "BLOCKS";

    if (ret != ESP_OK) {
        if (ret == ESP_FAIL) {
            ESP_LOGE(TAG, "Failed to mount or format filesystem");
        } else if (ret == ESP_ERR_NOT_FOUND) {
            ESP_LOGE(TAG, "Failed to find SPIFFS partition");
        } else {
            ESP_LOGE(TAG, "Failed to initialize SPIFFS (%s)", esp_err_to_name(ret));
        }
        return;
    }
}

// #define MEMORY_DEBUG_RECORDS 100
// static heap_trace_record_t trace_record[MEMORY_DEBUG_RECORDS]; // This buffer must be in internal RAM

extern "C" {
#ifdef ESP_PLATFORM
void app_main();
}
#else
int main(int /*argc*/, char** /*argv*/);
#endif

#ifdef ESP_PLATFORM
void app_main()
#else
int main(int /*argc*/, char** /*argv*/)
#endif
{
    // ESP_ERROR_CHECK(heap_trace_init_standalone(trace_record, MEMORY_DEBUG_RECORDS));

    spark4::hw_init();
    check_ota();

    spark4::adc_init();

    hal_delay_ms(100);

    mount_blocks_spiff();
    ethernet::init();

    asio::io_context io;

    setupSystemBlocks();
    cbox::loadBlocksFromStorage();
    cbox::discoverBlocks();

    static auto updater = RecurringTask(
        io, asio::chrono::milliseconds(10),
        RecurringTask::IntervalType::FROM_EXECUTION,
        []() {
            static const auto start = asio::chrono::steady_clock::now().time_since_epoch() / asio::chrono::milliseconds(1);
            const auto now = asio::chrono::steady_clock::now().time_since_epoch() / asio::chrono::milliseconds(1);
            uint32_t millisSinceBoot = now - start;
            cbox::update(millisSinceBoot);
            return true;
        });

    updater.start();
    auto ticks = TicksEsp();

    using gui = Gui<TFT035, FT6236, StaticGui>;

    auto startInit = ticks.micros();
    gui::init();
    auto endInit = ticks.micros();
    auto initDuration = endInit - startInit;

    ESP_LOGE("measurments", "Init duration (%d)", initDuration);

    static CboxServer cboxServer(io, 8332);

    static auto provisionTimeout = RecurringTask(io, asio::chrono::milliseconds(1000),
                                                 RecurringTask::IntervalType::FROM_EXPIRY,
                                                 []() -> bool {
                                                     static uint8_t count = 0;
                                                     if (spark4::adcRead5V() < 2000u) {
                                                         ++count;
                                                         if (count < 5) {
                                                             // still pressed
                                                             return true;
                                                         }
                                                     }
                                                     bool resetProvision = count >= 5;
                                                     wifi::init(wifi::PROVISION_METHOD::BLE, resetProvision);
                                                     mdns::start();
                                                     return false;
                                                 });

    provisionTimeout.start();

    static auto displayTicker = RecurringTask(io, asio::chrono::milliseconds(100),
                                              RecurringTask::IntervalType::FROM_EXPIRY,
                                              [ticks]() -> bool {
                                                  static uint8_t counter = 0;
                                                  static uint32_t maxTime = 0;
                                                  static uint32_t timeSum = 0;
                                                  auto startUpdate = ticks.micros();
                                                  gui::update();
                                                  gui::tick(100);
                                                  auto endUpdate = ticks.micros();
                                                  auto updateDuration = endUpdate - startUpdate;
                                                  if (updateDuration > maxTime) {
                                                      maxTime = updateDuration;
                                                  }
                                                  timeSum += updateDuration;
                                                  if (counter >= 60) {
                                                      counter = 0;
                                                      auto averageUpdateDuration = timeSum / 60;
                                                      ESP_LOGE("measurments", "Average update duration 60 updates (%d)", averageUpdateDuration);
                                                      ESP_LOGE("measurments", "Max update duration 60 updates (%d)", maxTime);
                                                      timeSum = 0;
                                                      maxTime = 0;
                                                  } else {
                                                      counter++;
                                                  }
                                                  return true;
                                              });

    displayTicker.start();

    static auto systemCheck = RecurringTask(io, asio::chrono::milliseconds(2000),
                                            RecurringTask::IntervalType::FROM_EXPIRY,
                                            []() -> bool {
                                                spark4::expander_check();
                                                // heap_caps_print_heap_info(MALLOC_CAP_8BIT);
                                                return true;
                                            });

    systemCheck.start();

    HttpHandler http(io, 80, cboxServer);

    io.run();

#ifndef ESP_PLATFORM
    return 0;
#endif
}
