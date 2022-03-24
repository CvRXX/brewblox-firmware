#pragma once

#include "ethernet.hpp"
#include "wifi.hpp"

inline void onEthernetConnected()
{
    wifi::stop();
    wifi::deinit();
}

inline void onEthernetDisconnected()
{
    if (wifi::hasCredentials()) {
        wifi::start();
    }
}

inline void onWifiConnected()
{
}

inline void onWifiDisconnected()
{
}
