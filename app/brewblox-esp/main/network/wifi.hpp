#pragma once

#include <esp_err.h>
#include <esp_netif_ip_addr.h>
#include <string>

namespace wifi {

enum class PROVISION_METHOD {
    BLE = 0,
    SOFTAP = 1
};

void init(PROVISION_METHOD method, bool forceProvision);
void deinit();
esp_ip4_addr ip4();
bool isConnected();

/**
 * Returns the rssi of the current ap's signal.
 * @return The rssi in dBm
 */
int8_t getRssi();

void append_qr_url(std::string& s);
};