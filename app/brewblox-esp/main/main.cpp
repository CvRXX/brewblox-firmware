#include "Brewblox.hpp"
#include "RecurringTask.hpp"
#include "blocks/ScreenConfig.hpp"
#include "blox_hal/hal_delay.hpp"
#include "cbox/Box.hpp"
#include "control/DS248x.hpp"
#include "control/OneWire.hpp"
#include "control/TempSensor.hpp"
// #include "esp_heap_caps.h"
// #include "esp_heap_trace.h"
#include "drivers/FT6236.hpp"
#include "drivers/Spark4.hpp"
#include "drivers/TFT035.hpp"
#include "gui.hpp"
#include "intellisense.hpp"
// #include "esp_heap_caps.h"
// #include "esp_heap_trace.h"
#include "BeepTask.hpp"
// #include "HttpHandler.hpp"
#include "OkButtonMonitor.hpp"
#include "blox_hal/hal_network.hpp"
// #include "dynamic_gui/dynamicGui.hpp"
// #include "dynamic_gui/util/test_screen.hpp"
#include "lvgl.h"
#include "network/CboxConnection.hpp"
#include "network/CboxServer.hpp"
#include "network/mdns.hpp"
#include "ota.hpp"
#include "sntp.hpp"
#include "static_gui/staticGui.hpp"
#include "task_stats.hpp"
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
void app_main();
}

void app_main()
{
    // ESP_ERROR_CHECK(heap_trace_init_standalone(trace_record, MEMORY_DEBUG_RECORDS));

    // using screen = Gui<TFT035, FT6236, StaticGui>;
    using screen = Gui<TFT035, FT6236, gui::dynamic_interface::DynamicGui>;

    spark4::hw_init();
    check_ota();
    spark4::startup_beep();
    mount_blocks_spiff();
    spark4::adc_init();
    setupSystemBlocks();
    screen::init();
    screen::update();

    // auto testScreen = gui::dynamic_interface::testScreen();
    // if (testScreen) {
    //     screen::interface->setNewScreen(std::move(*testScreen));
    // }
    network::connect();
    initialize_sntp();

    static asio::io_context io;
    static auto displayTicker = RecurringTask(io, asio::chrono::milliseconds(100),
                                              RecurringTask::IntervalType::FROM_EXPIRY,
                                              []() -> bool {
                                                  screen::update();
                                                  screen::updateWidgets();
                                                  screen::tick(100);
                                                  return true;
                                              });

    static auto systemCheck = RecurringTask(io, asio::chrono::milliseconds(2000),
                                            RecurringTask::IntervalType::FROM_EXPIRY,
                                            []() -> bool {
                                                spark4::expander_check();
                                                // heap_caps_print_heap_info(MALLOC_CAP_8BIT);
                                                // vTaskPrintRunTimeStats();
                                                return true;
                                            });

    static OkButtonMonitor buttonMonitor(
        io,
        {
            []() {},                 // no action on single press
            network::provision,      // hold 5s to start provision to set WiFi credentials
            network::clearProvision, // hold 10s to clear WiFi credentials
        });

    static auto updater = RecurringTask(
        io, asio::chrono::milliseconds(2),
        RecurringTask::IntervalType::FROM_EXECUTION,
        []() {
            static const auto start = asio::chrono::steady_clock::now().time_since_epoch() / asio::chrono::milliseconds(1);
            static uint32_t lastDisplayTick = 0;
            const auto now = asio::chrono::steady_clock::now().time_since_epoch() / asio::chrono::milliseconds(1);
            uint32_t millisSinceBoot = now - start;
            uint32_t millisSinceDisplayTick = now - lastDisplayTick;
            cbox::update(millisSinceBoot);
            if (millisSinceDisplayTick >= 100) {
                screen::update();
                screen::tick(millisSinceDisplayTick);
                lastDisplayTick = now;
            }
            return true;
        });

    static auto configupdate = RecurringTask(
        io, asio::chrono::seconds(1),
        RecurringTask::IntervalType::FROM_EXECUTION,
        []() {
            if (ScreenConfig::newSettingsReceived()) {
                auto& settings = ScreenConfig::settings();
                auto layoutNodes = settings.pages[0].first;
                auto contentNodes = settings.pages[0].second;
                auto screen = gui::dynamic_interface::decodeNodes(std::move(layoutNodes), std::move(contentNodes));
                if (screen) {
                    screen::interface->setNewScreen(std::move(*screen));
                }
            }
            return true;
        });

    static CboxServer cboxServer(io, 8332);
    // static HttpHandler http(io, 80, cboxServer);

    buttonMonitor.start();
    systemCheck.start();
    cbox::loadBlocksFromStorage();
    updater.start(true);
    configupdate.start();
    cbox::discoverBlocks();
    mdns::start();
    io.run();
}
