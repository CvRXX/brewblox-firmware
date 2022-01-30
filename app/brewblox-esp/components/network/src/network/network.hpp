#pragma once

#include "esp_event.h"
#include <esp_netif_ip_addr.h>
#include <freertos/FreeRTOS.h>

namespace network {

enum class Mode : uint8_t {
    OFF,
    ETHERNET,
    WIFI,
    WIFI_PROVISIONING,
};

Mode mode();
void setMode(Mode mode);
esp_ip4_addr_t ip4();

void connect();
void disconnect();
bool isConnected();
int8_t wifiStrength();
void resetProvisioning();

}
