/* Wi-Fi Provisioning Manager Example
   This example code is in the Public Domain (or CC0 licensed, at your option.)
   Unless required by applicable law or agreed to in writing, this
   software is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR
   CONDITIONS OF ANY KIND, either express or implied.
*/

#include "wifi.hpp"
#include <stdio.h>
#include <string.h>

#include <esp_log.h>
#include <esp_wifi.h>
#include <nvs_flash.h>

#include "blox_hal/hal_network.hpp"
#include "network_events.hpp"
#include <string>

namespace wifi {
constexpr auto TAG = "WIFI";
esp_netif_t* wifi_netif{nullptr};
esp_ip4_addr_t ip_addr{0};

void on_wifi_disconnect(void* arg, esp_event_base_t event_base,
                        int32_t event_id, void* event_data)
{
    onWifiDisconnected();

    ESP_LOGI(TAG, "Wi-Fi disconnected, trying to reconnect...");
    esp_wifi_connect();
}

void on_got_ip(void* arg, esp_event_base_t event_base, int32_t event_id, void* event_data)
{
    onWifiConnected();
    ip_event_got_ip_t* event = reinterpret_cast<ip_event_got_ip_t*>(event_data);
    memcpy(&ip_addr, &event->ip_info.ip, sizeof(ip_addr));
    ESP_LOGI(TAG, "Got IPv4 event: Interface \"%s\" address: " IPSTR, esp_netif_get_desc(event->esp_netif), IP2STR(&event->ip_info.ip));
}

void on_lost_ip(void* arg, esp_event_base_t base, int32_t event_id, void* event_data)
{
    ip_event_got_ip_t* event = reinterpret_cast<ip_event_got_ip_t*>(event_data);
    esp_netif_set_ip4_addr(&ip_addr, 0, 0, 0, 0);
    ESP_LOGI(TAG, "Got IPv4 event: Interface \"%s\" lost ip", esp_netif_get_desc(event->esp_netif));
}

void init()
{
    if (!wifi_netif) {
        wifi_init_config_t cfg = WIFI_INIT_CONFIG_DEFAULT();
        ESP_ERROR_CHECK(esp_wifi_init(&cfg));
        esp_netif_inherent_config_t esp_netif_config = ESP_NETIF_INHERENT_DEFAULT_WIFI_STA();
        esp_netif_config.route_prio = 128;
        wifi_netif = esp_netif_create_wifi(WIFI_IF_STA, &esp_netif_config);
        esp_wifi_set_default_wifi_sta_handlers();
    }
}

void deinit()
{
    if (wifi_netif) {
        ESP_ERROR_CHECK(esp_wifi_deinit());
        ESP_ERROR_CHECK(esp_wifi_clear_default_wifi_driver_and_handlers(wifi_netif));
        esp_netif_destroy(wifi_netif);
        wifi_netif = nullptr;
    }
}

void start()
{
    init();
    ESP_ERROR_CHECK(esp_event_handler_register(WIFI_EVENT, WIFI_EVENT_STA_DISCONNECTED, &on_wifi_disconnect, NULL));
    ESP_ERROR_CHECK(esp_event_handler_register(IP_EVENT, IP_EVENT_STA_GOT_IP, &on_got_ip, nullptr));
    ESP_ERROR_CHECK(esp_event_handler_register(IP_EVENT, IP_EVENT_STA_LOST_IP, &on_lost_ip, nullptr));
    ESP_ERROR_CHECK(esp_wifi_start());
    esp_wifi_connect();
    esp_wifi_set_ps(WIFI_PS_NONE); // disable power saving, otherwise traffic can have a lot of latency
}

void stop()
{
    ESP_ERROR_CHECK(esp_event_handler_unregister(WIFI_EVENT, WIFI_EVENT_STA_DISCONNECTED, &on_wifi_disconnect));
    ESP_ERROR_CHECK(esp_event_handler_unregister(IP_EVENT, IP_EVENT_STA_GOT_IP, &on_got_ip));
    ESP_ERROR_CHECK(esp_event_handler_unregister(IP_EVENT, IP_EVENT_STA_LOST_IP, &on_lost_ip));
    esp_wifi_stop();
    esp_wifi_set_ps(WIFI_PS_MIN_MODEM);
}

int8_t rssi()
{
    wifi_ap_record_t wifidata;
    if (esp_wifi_sta_get_ap_info(&wifidata) == 0) {
        return wifidata.rssi;
    }
    return 0;
}

esp_netif_t* interface()
{
    return wifi_netif;
}

esp_ip4_addr_t ip4()
{
    return ip_addr;
}

bool isConnected()
{
    return ip_addr.addr != 0;
}

bool hasCredentials()
{
    wifi_config_t wifi_cfg;
    if (esp_wifi_get_config(WIFI_IF_STA, &wifi_cfg) != ESP_OK) {
        return false;
    }

    return wifi_cfg.sta.ssid[0] != 0;
}
}
