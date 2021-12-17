#pragma once

#include <esp_netif_ip_addr.h>
#include <freertos/FreeRTOS.h>
#include <freertos/event_groups.h>

namespace network {

// xEventGroupWaitBits(wifi_event_group, WIFI_CONNECTED_EVENT, false, true, portMAX_DELAY);
constexpr int WIFI_CONNECTED_EVENT = BIT0;
constexpr int WIFI_DISCONNECTED_EVENT = BIT1;
constexpr int ETH_CONNECTED_EVENT = BIT2;
constexpr int ETH_DISCONNECTED_EVENT = BIT3;
constexpr int PROV_EVENT = BIT4;

// use these bits as flags for status without triggering events:
constexpr int ETH_IS_CONNECTED = BIT5;
constexpr int WIFI_IS_CONNECTED = BIT6;
constexpr int WIFI_IS_PROVISIONING = BIT7;

enum class NetworkState : uint8_t {
    NO_CONNECTION,
    ETHERNET_CONNECTED,
    WIFI_CONNECTED,
    WIFI_PROVISIONING,
};

NetworkState state();
EventGroupHandle_t& eventGroup();
const esp_ip4_addr& ip4();

void networkTask(void* pvParameters);
void init();
int8_t wifiStrength();
void resetProvisioning();

}
