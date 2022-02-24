#include "blox_hal/hal_network.hpp"
#include "driver/gpio.h"
#include "esp_eth.h"
#include "esp_log.h"
#include "esp_netif.h"
#include "esp_wifi.h"
#include "esp_wifi_default.h"
#include "ethernet.hpp"
#include "freertos/FreeRTOS.h"
#include "freertos/event_groups.h"
#include "freertos/task.h"
#include "lwip/err.h"
#include "lwip/sys.h"
#include "wifi.hpp"
#include <string.h>

namespace network {
constexpr auto TAG = "NETWORK";
Mode current_mode;

void start(void)
{
    ethernet::start();
    wifi::start();
}

void stop(void)
{
    wifi::stop();
    ethernet::stop();
}

void connect(void)
{
    start();
    ESP_ERROR_CHECK(esp_register_shutdown_handler(&stop));
}

void disconnect(void)
{
    stop();
    ESP_ERROR_CHECK(esp_unregister_shutdown_handler(&stop));
}

Mode mode()
{
    return current_mode;
}

void setMode(Mode mode)
{
    current_mode = mode;
}

uint32_t ip4()
{
    if (ethernet::isConnected()) {
        return ethernet::ip4().addr;
    }
    if (wifi::isConnected()) {
        return wifi::ip4().addr;
    }
    return 0;
}

int8_t wifiStrength()
{
    return wifi::rssi();
}

void resetProvisioning()
{
    wifi::resetProvisioning();
}

}; // end namespace network
