#pragma once

#include <esp_netif_ip_addr.h>

namespace wifi {

void init();
void start();
void stop();
esp_ip4_addr ip4();

/**
 * Returns the rssi of the current ap's signal.
 * @return The rssi in dBm
 */
int8_t rssi();
void resetProvisioning();
void disablePowerSaving();

};