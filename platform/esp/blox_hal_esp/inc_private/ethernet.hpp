#pragma once
#include "blox_hal/hal_network.hpp"
#include <esp_netif.h>
#include <esp_netif_ip_addr.h>

namespace ethernet {
void start();
void stop();
esp_ip4_addr_t ip4();
esp_netif_t* interface();
network::State state();
}
