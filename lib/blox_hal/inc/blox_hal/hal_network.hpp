#pragma once
#include <cstdint>

namespace network {

enum class Mode : uint8_t {
    OFF,
    ETHERNET,
    WIFI,
    WIFI_PROVISIONING,
};

Mode mode();
void setMode(Mode mode);
uint32_t ip4();

void connect();
void disconnect();
bool isConnected();
int8_t wifiStrength();
void resetProvisioning();
}
