#include "blox_hal/hal_network.hpp"

namespace network {

Mode mode()
{
    return Mode::ETHERNET;
}

uint32_t ip4()
{
    return 2130706433; // 127.0.0.1
}

void connect() {}

void disconnect() {}

bool isConnected()
{
    return true;
}

int8_t wifiStrength()
{
    return 100;
}

void provision() {}

void clearProvision() {}

State state()
{
    return State::CONNECTED;
}

} // end namespace network
