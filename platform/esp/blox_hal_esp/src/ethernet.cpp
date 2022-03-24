#include "ethernet.hpp"
#include "blox_hal/hal_network.hpp"
#include "network_events.hpp"
#include <cstring>
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wconversion"
#pragma GCC diagnostic ignored "-Wsign-conversion"
#include <esp_eth.h>
#include <esp_eth_netif_glue.h>
#include <esp_event.h>
//#include <esp_event_base.h>
#include <esp_log.h>
#include <esp_netif.h>
#pragma GCC diagnostic pop

extern "C" {
esp_eth_phy_t* esp_eth_phy_new_lan87xx(const eth_phy_config_t* config);
}

namespace ethernet {
constexpr auto TAG = "ETH";

esp_netif_t* eth_netif{nullptr};
esp_eth_mac_t* mac{nullptr};
esp_eth_phy_t* phy{nullptr};
esp_eth_handle_t eth_handle{nullptr};
esp_eth_netif_glue_handle_t eth_glue{nullptr};
esp_ip4_addr_t ip_addr{0};

void on_got_ip(void* arg, esp_event_base_t event_base, int32_t event_id, void* event_data)
{
    ip_event_got_ip_t* event = reinterpret_cast<ip_event_got_ip_t*>(event_data);

    ESP_LOGI(TAG, "Got IPv4 event: Interface \"%s\" address: " IPSTR, esp_netif_get_desc(event->esp_netif), IP2STR(&event->ip_info.ip));
    memcpy(&ip_addr, &event->ip_info.ip, sizeof(ip_addr));
    onEthernetGotIp();
}

void on_lost_ip(void* arg, esp_event_base_t base, int32_t event_id, void* event_data)
{
    ip_event_got_ip_t* event = reinterpret_cast<ip_event_got_ip_t*>(event_data);
    esp_netif_set_ip4_addr(&ip_addr, 0, 0, 0, 0);
    onEthernetLostIp();

    ESP_LOGI(TAG, "Got IPv4 event: Interface \"%s\" lost ip", esp_netif_get_desc(event->esp_netif));
}

void on_disconnected(void* arg, esp_event_base_t base, int32_t event_id, void* event_data)
{
    onEthernetDisconnected();
    ESP_LOGI(TAG, "Ethernet disconnected");
}

void on_connected(void* arg, esp_event_base_t base, int32_t event_id, void* event_data)
{
    onEthernetConnected();
    ESP_LOGI(TAG, "Ethernet connected");
}

void start()
{
    esp_netif_config_t cfg = ESP_NETIF_DEFAULT_ETH();
    eth_netif = esp_netif_new(&cfg);

    eth_mac_config_t mac_config = ETH_MAC_DEFAULT_CONFIG();
    eth_phy_config_t phy_config = ETH_PHY_DEFAULT_CONFIG();
    phy_config.phy_addr = 0;
    phy_config.reset_gpio_num = -1;
    phy_config.reset_timeout_ms = 2000;
    mac_config.smi_mdc_gpio_num = 23;
    mac_config.smi_mdio_gpio_num = 18;
    mac = esp_eth_mac_new_esp32(&mac_config);
    phy = esp_eth_phy_new_lan87xx(&phy_config);
    esp_eth_config_t config = ETH_DEFAULT_CONFIG(mac, phy);
    esp_eth_driver_install(&config, &eth_handle);
    eth_glue = esp_eth_new_netif_glue(eth_handle);
    auto err = esp_netif_attach(eth_netif, eth_glue);

    ESP_ERROR_CHECK(esp_event_handler_register(IP_EVENT, IP_EVENT_ETH_GOT_IP, &on_got_ip, nullptr));
    ESP_ERROR_CHECK(esp_event_handler_register(IP_EVENT, IP_EVENT_ETH_LOST_IP, &on_lost_ip, nullptr));
    ESP_ERROR_CHECK(esp_event_handler_register(ETH_EVENT, ETHERNET_EVENT_DISCONNECTED, &on_disconnected, nullptr));
    ESP_ERROR_CHECK(esp_event_handler_register(ETH_EVENT, ETHERNET_EVENT_CONNECTED, &on_connected, nullptr));

    if (err == ESP_OK) {
        /* start Ethernet driver state machine */
        err = esp_eth_start(eth_handle);
    }
}

void stop()
{
    ESP_ERROR_CHECK(esp_event_handler_unregister(IP_EVENT, IP_EVENT_ETH_GOT_IP, &on_got_ip));
    ESP_ERROR_CHECK(esp_event_handler_unregister(IP_EVENT, IP_EVENT_ETH_LOST_IP, &on_lost_ip));
    ESP_ERROR_CHECK(esp_event_handler_unregister(ETH_EVENT, ETHERNET_EVENT_DISCONNECTED, &on_disconnected));
    ESP_ERROR_CHECK(esp_event_handler_unregister(ETH_EVENT, ETHERNET_EVENT_CONNECTED, &on_connected));

    if (eth_handle) {
        ESP_ERROR_CHECK(esp_eth_stop(eth_handle));
        ESP_ERROR_CHECK(esp_eth_del_netif_glue(eth_glue));
        ESP_ERROR_CHECK(esp_eth_driver_uninstall(eth_handle));
        ESP_ERROR_CHECK(phy->del(phy));
        ESP_ERROR_CHECK(mac->del(mac));

        esp_netif_destroy(eth_netif);
        eth_netif = nullptr;
    }
}

esp_netif_t* interface()
{
    return eth_netif;
}

esp_ip4_addr_t ip4()
{
    return ip_addr;
}

bool isConnected()
{
    return ip_addr.addr != 0;
}

} // end namespace ethernet
