#include "intellisense.hpp"
#include "drivers/Spark4.hpp"
#include "drivers/TFT035.hpp"
#include "Brewblox.hpp"
#include "RecurringTask.hpp"
#include "blox_hal/hal_delay.hpp"
#include "cbox/Box.hpp"
#include "control/DS248x.hpp"
#include "control/OneWire.hpp"
#include "control/TempSensor.hpp"
// #include "esp_heap_caps.h"
// #include "esp_heap_trace.h"
#include "blox_hal/hal_network.hpp"
#include "graphics/graphics.hpp"
#include "graphics/widgets.hpp"
#include "lvgl.h"
#include "ota.hpp"
#include "network/CboxConnection.hpp"
#include "network/CboxServer.hpp"
#include "HttpHandler.hpp"
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
    network::connect();

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

    Graphics::init();

    static CboxServer cboxServer(io, 8332);

    static auto adcReader = RecurringTask(io, asio::chrono::milliseconds(30),
                                          RecurringTask::IntervalType::FROM_EXPIRY,
                                          []() -> bool {
                                              static asio::chrono::steady_clock::time_point lowToHigh{asio::chrono::steady_clock::now()};
                                              static asio::chrono::steady_clock::time_point highToLow{asio::chrono::steady_clock::now()};
                                              static asio::chrono::steady_clock::time_point lastBeep{asio::chrono::steady_clock::now()};

                                              auto voltage = spark4::adcRead5V();
                                              auto now = asio::chrono::steady_clock::now();

                                              if (voltage < 2000u) {
                                                  if (lowToHigh >= highToLow) {
                                                      // high to low transition
                                                      lastBeep = now;
                                                      highToLow = now;
                                                  } else {
                                                      // low hold
                                                      auto now = asio::chrono::steady_clock::now();
                                                      auto sinceBeep = asio::chrono::duration_cast<asio::chrono::milliseconds>(now - lastBeep).count();
                                                      if (sinceBeep >= 5000) {
                                                          spark4::startup_beep();
                                                          lastBeep = now;
                                                      }
                                                  }
                                              } else if (lowToHigh <= highToLow) {
                                                  // low to high transition
                                                  lowToHigh = asio::chrono::steady_clock::now();
                                                  auto duration = asio::chrono::duration_cast<asio::chrono::milliseconds>(lowToHigh - highToLow).count();

                                                  if (duration >= 5000) {
                                                      // network::resetProvisioning();
                                                  }
                                              }
                                              return true;
                                          });
    adcReader.start();

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
