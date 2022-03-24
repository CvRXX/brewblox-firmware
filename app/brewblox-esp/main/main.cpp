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

    using gui = Gui<TFT035, FT6236, DynamicGui>;

    gui::init();
    auto ticks = TicksEsp();
    auto start = ticks.micros();
    for (int i = 0; i < 60; i++) {
        gui::update();
        gui::tick(100);
    }
    auto end = ticks.micros();
    auto difference = end - start;

    ESP_LOGE("tesr", "Time for 60 rewrites (%d)", difference);

#ifndef ESP_PLATFORM
    return 0;
#endif
}
