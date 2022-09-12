#pragma once
#include <cstdint>
#include <string>

namespace network {

enum class Mode : uint8_t {
    ETHERNET,
    WIFI,
    WIFI_PROVISIONING,
};

enum class State : uint8_t {
    OFF,
    CONNECTED,
    NOT_FOUND,
    NETWORK_ERROR,
};

Mode mode();
uint32_t ip4(); // little endian
const std::string& ip4string();

void connect();
void disconnect();
bool isConnected();
int8_t wifiStrength();
void provision();
void clearProvision();
State state();
}
