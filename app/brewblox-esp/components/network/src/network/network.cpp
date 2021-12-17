#include "network.hpp"
#include "Spark4.hpp"
#include "ethernet.hpp"
#include "mdns.hpp"
#include "wifi.hpp"
#include <esp_event.h>
#include <esp_log.h>
#include <freertos/FreeRTOS.h>
#include <freertos/event_groups.h>
#include <freertos/task.h>

namespace network {
constexpr auto TAG = "NETWORK";

EventGroupHandle_t _eventGroup;
StaticEventGroup_t _eventGroupBuffer;
esp_ip4_addr _ip{0};
NetworkState _state = NetworkState::NO_CONNECTION;

EventGroupHandle_t& eventGroup()
{
    return _eventGroup;
}

const esp_ip4_addr& ip4()
{
    return _ip;
}

NetworkState state()
{
    return _state;
}

void setLed(NetworkState s)
{
    switch (s) {
    case NetworkState::NO_CONNECTION:
        // Configure Green for blinking fast
        spark4::set_led(0, 128, 0, spark4::LED_MODE::BLINK, 2);
        break;
    case NetworkState::ETHERNET_CONNECTED:
    case NetworkState::WIFI_CONNECTED:
        // Configure Green for breathing
        spark4::set_led(0, 128, 0, spark4::LED_MODE::BREATHE, 15);
        break;
    case NetworkState::WIFI_PROVISIONING:
        // Configure blue blinking
        spark4::set_led(0, 0, 128, spark4::LED_MODE::BLINK, 8);
        break;
    }
}

void networkTask(void* pvParameters)
{
    while (true) {
        auto uxBits = xEventGroupWaitBits(
            _eventGroup,                                                                                                /* The event group being tested. */
            WIFI_CONNECTED_EVENT | WIFI_DISCONNECTED_EVENT | ETH_CONNECTED_EVENT | ETH_DISCONNECTED_EVENT | PROV_EVENT, /* The bits within the event group to wait for. */
            true,                                                                                                       /* Bits should be cleared before returning. */
            false,                                                                                                      /* Don't wait for all bits, any bit will do. */
            portMAX_DELAY);                                                                                             /* Wait a maximum of 100ms for either bit to be set. */

        if (uxBits & ETH_IS_CONNECTED) {
            // set connection to ethernet
            _state = NetworkState::ETHERNET_CONNECTED;
            // set ip to ethernet ip
            _ip = ethernet::ip4();
            ESP_LOGI(TAG, "Ethernet connected with IP Address:" IPSTR, IP2STR(&_ip));
            // disable wifi
            wifi::stop();
        } else if (uxBits & WIFI_IS_CONNECTED) {
            // set connection wifi
            _state = NetworkState::WIFI_CONNECTED;
            _ip = wifi::ip4();
            ESP_LOGI(TAG, "Wifi connected with IP Address:" IPSTR, IP2STR(&_ip));
            // set ip to wifi ip
        } else {
            // set connection to none
            _state = (uxBits & WIFI_IS_PROVISIONING) ? NetworkState::WIFI_PROVISIONING : NetworkState::NO_CONNECTION;
            // clear ip
            _ip.addr = 0;
            ESP_LOGI(TAG, "Connection lost");
        }

        if (uxBits & ETH_CONNECTED_EVENT || uxBits & WIFI_CONNECTED_EVENT) {
            mdns::start();
        }

        if (_state == NetworkState::NO_CONNECTION) {
            wifi::start();
        }

        setLed(_state);
    }
}

void init()
{
    // Create the event group without dynamically allocating any memory.
    _eventGroup = xEventGroupCreateStatic(&_eventGroupBuffer);
    static uint8_t ucParameterToPass;

    ethernet::init();
    wifi::init();
    wifi::start();
    TaskHandle_t xHandle = nullptr;

    // Create the task, storing the handle.  Note that the passed parameter ucParameterToPass
    // must exist for the lifetime of the task, so in this case is declared static.  If it was just an
    // an automatic stack variable it might no longer exist, or at least have been corrupted, by the time
    // the new task attempts to access it.
    xTaskCreate(networkTask, "NETWORK", 4096, &ucParameterToPass, tskIDLE_PRIORITY, &xHandle);
}

int8_t wifiStrength()
{
    return wifi::rssi();
}

void resetProvisioning()
{
    wifi::resetProvisioning();
}
}
