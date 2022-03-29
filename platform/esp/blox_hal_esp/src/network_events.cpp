#include "network_events.hpp"
#include "blox_hal/hal_network.hpp"
#include "drivers/Spark4.hpp"
#include "ethernet.hpp"
#include "wifi.hpp"

void updateLed()
{
    if (network::mode() == network::Mode::WIFI_PROVISIONING) {
        spark4::set_led(0, 0, 128, spark4::LED_MODE::BLINK, 5);
    } else if (network::ip4()) {
        spark4::set_led(0, 128, 128, spark4::LED_MODE::BREATHE, 15);
    } else if (network::mode() == network::Mode::WIFI) {
        spark4::set_led(0, 128, 0, spark4::LED_MODE::BLINK, 5);
    } else {
        spark4::set_led(0, 128, 0, spark4::LED_MODE::BLINK, 10);
    }
}

void onEthernetConnected()
{
}

void onEthernetDisconnected()
{
}

void onEthernetGotIp()
{
    updateLed();
    wifi::stop();
    wifi::deinit();
}

void onEthernetLostIp()
{
    updateLed();
    wifi::start();
}

void onWifiConnected()
{
}

void onWifiDisconnected()
{
}

void onWifiGotIp()
{
    updateLed();
}

void onWifiLostIp()
{
    updateLed();
}

void beforeProvision()
{
    wifi::stop(); // stop wifi as normal access point and disable custom event handlers and enable power saving
    wifi::init(); // ensure wifi is initialized, could be disabled if ethernet is connected
}

void onProvisionStarted()
{
    updateLed();
}

void onProvisionStopped()
{
    // restart wifi to re-enable our event handlers and get the ip
    wifi::stop();
    wifi::start();
    updateLed();
}
