#pragma once

#include "blox_hal/hal_network.hpp"
#include <esp_netif.h>
#include <esp_netif_ip_addr.h>

namespace wifi {

void init();
void deinit();
void start();
void start_provision();
void stop();
esp_ip4_addr_t ip4();
esp_netif_t* interface();
network::State state();
bool hasCredentials();

/**
 * Returns the rssi of the current ap's signal.
 * @return The rssi in dBm
 */
int8_t rssi();
void resetProvisioning();
void disablePowerSaving();

};
