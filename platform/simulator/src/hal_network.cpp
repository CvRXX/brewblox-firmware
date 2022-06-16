#include "blox_hal/hal_network.hpp"

namespace network {

Mode mode()
{
    return Mode::ETHERNET;
}

uint32_t ip4()
{
    return 0;
}

void connect()
{
}

void disconnect()
{
}

bool isConnected()
{
    return true;
}

int8_t wifiStrength()
{
    return 0;
}

void provision()
{
}

void clearProvision()
{
}

State state()
{
    return State::CONNECTED;
}

} // end namespace network
