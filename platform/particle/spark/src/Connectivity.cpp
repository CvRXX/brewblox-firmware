/*
 * Copyright 2018 BrewPi B.V.
 *
 * This file is part of Brewblox.
 *
 * BrewPi is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * BrewPi is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with BrewPi.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "spark/Connectivity.h"
#include "blocks/stringify.h"
#include "blox_hal/hal_delay.h"
#include "deviceid_hal.h"
#include "mdns/MDNS.h"
#include "spark/Board.h"
#include "spark/Brewblox.h"
#include "spark_wiring_tcpclient.h"
#include "spark_wiring_tcpserver.h"
#include "spark_wiring_usbserial.h"
#include "spark_wiring_wifi.h"
#include <cstdio>

constexpr uint16_t webPort = PLATFORM_ID == PLATFORM_GCC ? 8380 : 80;
static TCPServer httpserver(webPort); // Serve a simple page with instructions
// these values are only set on initial connect to avoid thread unsafe calls into the wifi stack
uint32_t localIp = 0;
int8_t wifiSignalRssi = 2;
char currentSsid[32] = "";

void printWiFiIp(char dest[16])
{
    IPAddress ip = localIp;
    snprintf(dest, 16, "%d.%d.%d.%d", ip[0], ip[1], ip[2], ip[3]);
}

// only update signal strength periodically to reduce number of calls into wifi driver
void updateWifiSignal()
{
    if (!spark::WiFi.ready()) {
        localIp = 0;
        wifiSignalRssi = 2;
        currentSsid[0] = 0;
        return;
    }

    // From a particle issue #1967:
    // avtolstoy: As a workaround for now I might suggest trying to make sure that WiFi.ready() is true
    // before any WiFi.xxx() calls that rely on wifi_config(), so localIP, macAddress, subnetMask, gatewayIP,
    // dnsServerIP, dhcpServerIP, BSSID, SSID.

    // store ip, only once.
    // we cannot do this on the network_connected event, because sometimes, it seems, it does not have an IP immediately
    if (!localIp) {
        localIp = spark::WiFi.localIP().raw().ipv4;
    }

    auto rssi = wlan_connected_rssi();
    if (rssi != 0) {
        // 0 means caller should retry and we will wait until next update for the retry
        wifiSignalRssi = rssi;
    }
}

int8_t
wifiSignal()
{
    return wifiSignalRssi;
}

bool wifiConnected()
{
    if (PLATFORM_ID == PLATFORM_GCC) {
        return true;
    }
    // WiFi.ready() ensures underlying wifi driver has been initialized correctly
    // wifiSignalRssi is set above an ensures an IP address is assigned and we have signal
    // checking ready() too ensures that a disconnect is detected immediately
    return wifiSignalRssi < 0 && spark::WiFi.ready();
}

bool serialConnected()
{
    return HAL_USB_USART_Is_Connected(HAL_USB_USART_SERIAL);
}

bool setWifiCredentials(const char* ssid, const char* password, uint8_t security, uint8_t cipher)
{
    return spark::WiFi.setCredentials(ssid, password, security, cipher);
};

void printWifiSSID(char* dest, const uint8_t& maxLen)
{
    strncpy(dest, currentSsid, maxLen);
}

bool listeningModeEnabled()
{
    return spark::WiFi.listening();
}

MDNS* initMdns()
{
    MDNS* mdns = new MDNS(deviceIdString());
    mdns->addService(MDNS::Protocol::TCP, "_http", deviceIdString(), 80, {}, {});

    std::string hwEntry("HW=Spark ");
    switch (getSparkVersion()) {
    case SparkVersion::V1:
        hwEntry.push_back('1');
        break;
    case SparkVersion::V2:
        hwEntry.push_back('2');
        break;
    case SparkVersion::V3:
        hwEntry.push_back('3');
        break;
    }

    mdns->addService(MDNS::Protocol::TCP, "_brewblox", deviceIdString(), 8332,
                     {std::string("VERSION=" GIT_VERSION),
                      std::string("ID=") + deviceIdString(),
                      std::string("PLATFORM=" stringify(PLATFORM_ID)),
                      std::move(hwEntry)},
                     {});
    return mdns;
}

MDNS& theMdns()
{
    static MDNS* theStaticMDNS = initMdns();
    return *theStaticMDNS;
}

void manageConnections(uint32_t now)
{
    static uint32_t lastChecked = 0;
    if (now - lastChecked >= 1000) {
        updateWifiSignal();
        lastChecked = now;
    }

    if (wifiConnected()) {
        theMdns().process();
    } else {
        theMdns().stop();
    }

    while (auto client = httpserver.available()) {
        const uint8_t start[] =
            "HTTP/1.1 200 Ok\n\n<html><body>"
            "<p>Your Brewblox Spark is online but it does not run its own web server. "
            "Please install a Brewblox server to connect to it using the Brewblox protocol.</p>"
            "<p>Device ID = ";
        const uint8_t end[] = "</p></body></html>\n\n";

        client.write(start, sizeof(start), 10);
        if (!client.getWriteError() && client.status()) {
            client.write(reinterpret_cast<const uint8_t*>(deviceIdString().data()), 24, 10);
        }
        if (!client.getWriteError() && client.status()) {
            client.write(end, sizeof(end), 10);
        }
        client.stop();
        hal_yield();
    }
}

void handleNetworkEvent(system_event_t event, int param)
{
    switch (param) {
    case network_status_connected:
        // store ssid
        strncpy(currentSsid, spark::WiFi.SSID(), sizeof(currentSsid));
        break;
    case network_status_disconnected:
    case network_status_off:
        localIp = 0;
        wifiSignalRssi = 2;
        currentSsid[0] = 0;
        // explicit reconnect. WiFi channel switch would otherwise not reconnect
        spark::WiFi.connect(WIFI_CONNECT_SKIP_LISTEN);
        break;
    default:
        break;
    }
}

void wifiInit()
{
    System.disable(SYSTEM_FLAG_RESET_NETWORK_ON_CLOUD_ERRORS);
    System.on(network_status, handleNetworkEvent);
    spark::WiFi.setListenTimeout(45);
    spark::WiFi.connect(WIFI_CONNECT_SKIP_LISTEN);
}
