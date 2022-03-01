#include "Spark4.hpp"
#include "TFT035.hpp"

// #include "SDCard.hpp"
#include "ExpOwGpio.hpp"
#include "HttpHandler.hpp"
#include "I2cScanningFactory.hpp"
#include "RecurringTask.hpp"
#include "brewblox_esp.hpp"
#include "control/DS248x.hpp"
#include "control/OneWire.h"
#include "control/TempSensor.h"
// #include "esp_heap_caps.h"
// #include "esp_heap_trace.h"
#include "blox_hal/hal_delay.h"
#include "graphics/graphics.hpp"
#include "graphics/widgets.hpp"
#include "lvgl.h"
#include "network/CboxConnection.hpp"
#include "network/CboxServer.hpp"
#include "network/ethernet.hpp"
#include "network/mdns.hpp"
#include "network/wifi.hpp"
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
    static auto& box = makeBrewbloxBox(io);

    Graphics::init();

    static CboxServer cboxServer(io, 8332, box);

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
                                              []() -> bool {
                                                  Graphics::update();
                                                  Graphics::tick(100);
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
