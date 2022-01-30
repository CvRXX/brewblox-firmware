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

#include "network.hpp"
#include <string>

namespace wifi {
constexpr auto TAG = "WIFI";
esp_netif_t* wifi_netif{nullptr};
esp_ip4_addr_t ip_addr{0};

void on_wifi_disconnect(void* arg, esp_event_base_t event_base,
                        int32_t event_id, void* event_data)
{
    ESP_LOGI(TAG, "Wi-Fi disconnected, trying to reconnect...");
    esp_err_t err = esp_wifi_connect();
    if (err == ESP_ERR_WIFI_NOT_STARTED) {
        return;
    }
    ESP_ERROR_CHECK(err);
}

void on_got_ip(void* arg, esp_event_base_t event_base, int32_t event_id, void* event_data)
{
    ip_event_got_ip_t* event = reinterpret_cast<ip_event_got_ip_t*>(event_data);

    ESP_LOGI(TAG, "Got IPv4 event: Interface \"%s\" address: " IPSTR, esp_netif_get_desc(event->esp_netif), IP2STR(&event->ip_info.ip));
    memcpy(&ip_addr, &event->ip_info.ip, sizeof(ip_addr));
    // xSemaphoreGive(semph_get_ip_addrs);
}

void on_lost_ip(void* arg, esp_event_base_t base, int32_t event_id, void* event_data)
{
    ip_event_got_ip_t* event = reinterpret_cast<ip_event_got_ip_t*>(event_data);
    esp_netif_set_ip4_addr(&ip_addr, 0, 0, 0, 0);

    ESP_LOGI(TAG, "Got IPv4 event: Interface \"%s\" lost ip", esp_netif_get_desc(event->esp_netif));
}

void start()
{
    wifi_init_config_t cfg = WIFI_INIT_CONFIG_DEFAULT();
    ESP_ERROR_CHECK(esp_wifi_init(&cfg));
    esp_netif_inherent_config_t esp_netif_config = ESP_NETIF_INHERENT_DEFAULT_WIFI_STA();
    esp_netif_config.route_prio = 128;
    wifi_netif = esp_netif_create_wifi(WIFI_IF_STA, &esp_netif_config);

    esp_wifi_set_default_wifi_sta_handlers();

    ESP_ERROR_CHECK(esp_event_handler_register(WIFI_EVENT, WIFI_EVENT_STA_DISCONNECTED, &on_wifi_disconnect, NULL));
    ESP_ERROR_CHECK(esp_event_handler_register(IP_EVENT, IP_EVENT_STA_GOT_IP, &on_got_ip, nullptr));
    ESP_ERROR_CHECK(esp_event_handler_register(IP_EVENT, IP_EVENT_STA_LOST_IP, &on_lost_ip, nullptr));

    // ESP_ERROR_CHECK(esp_wifi_set_mode(WIFI_MODE_STA));
    // ESP_ERROR_CHECK(esp_wifi_set_config(WIFI_IF_STA, &cfg));
    ESP_ERROR_CHECK(esp_wifi_start());
    esp_wifi_connect();
}

void stop()
{
    ESP_ERROR_CHECK(esp_event_handler_unregister(WIFI_EVENT, WIFI_EVENT_STA_DISCONNECTED, &on_wifi_disconnect));
    ESP_ERROR_CHECK(esp_event_handler_unregister(IP_EVENT, IP_EVENT_STA_GOT_IP, &on_got_ip));
    ESP_ERROR_CHECK(esp_event_handler_unregister(IP_EVENT, IP_EVENT_STA_LOST_IP, &on_lost_ip));
    esp_err_t err = esp_wifi_stop();
    if (err == ESP_ERR_WIFI_NOT_INIT) {
        return;
    }
    ESP_ERROR_CHECK(err);
    ESP_ERROR_CHECK(esp_wifi_deinit());
    ESP_ERROR_CHECK(esp_wifi_clear_default_wifi_driver_and_handlers(wifi_netif));
    esp_netif_destroy(wifi_netif);
    wifi_netif = nullptr;
}

int8_t rssi()
{
    wifi_ap_record_t wifidata;
    if (esp_wifi_sta_get_ap_info(&wifidata) == 0) {
        return wifidata.rssi;
    }
    return 0;
}

void disablePowerSaving()
{
    esp_wifi_set_ps(WIFI_PS_NONE);
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

}