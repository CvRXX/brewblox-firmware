#pragma once

#include <esp_err.h>
#include <esp_netif_ip_addr.h>

namespace wifi {

enum class PROVISION_METHOD {
    BLE = 0,
    SOFTAP = 1
};

void init(PROVISION_METHOD method);
void deinit();
esp_ip4_addr ip4();
bool isConnected();
};