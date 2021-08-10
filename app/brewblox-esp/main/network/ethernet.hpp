#pragma once
#include <esp_err.h>
#include <esp_netif_ip_addr.h>

namespace ethernet {
void init();
void deinit();
esp_ip4_addr ip4();
bool isConnected();
}