#include "ethernet.hpp"
#include <cstring>
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wconversion"
#pragma GCC diagnostic ignored "-Wsign-conversion"
#include <esp_eth.h>
#include <esp_eth_netif_glue.h>
#include <esp_event.h>
//#include <esp_event_base.h>
#include <esp_netif.h>
#pragma GCC diagnostic pop

extern "C" {
esp_eth_phy_t* esp_eth_phy_new_lan8742(const eth_phy_config_t* config);
}

namespace ethernet {
esp_event_handler_instance_t instance_eth_event{};
esp_event_handler_instance_t instance_ip_event{};
esp_netif_t* interface{nullptr};
bool connected{false};
esp_eth_mac_t* mac{nullptr};
esp_eth_phy_t* phy{nullptr};
esp_eth_handle_t eth_handle{nullptr};
esp_ip4_addr ip{0};

void eth_event_handler(void* event_handler_arg,
                       esp_event_base_t event_base,
                       int32_t event_id,
                       void* event_data);

void init()
{
    esp_netif_config_t cfg = ESP_NETIF_DEFAULT_ETH();
    interface = esp_netif_new(&cfg);
    esp_eth_set_default_handlers(interface);

    esp_event_handler_instance_register(ETH_EVENT,
                                        ESP_EVENT_ANY_ID,
                                        &eth_event_handler,
                                        nullptr,
                                        &instance_eth_event);

    esp_event_handler_instance_register(IP_EVENT,
                                        ESP_EVENT_ANY_ID,
                                        &eth_event_handler,
                                        nullptr,
                                        &instance_ip_event);

    eth_mac_config_t mac_config = ETH_MAC_DEFAULT_CONFIG();
    eth_phy_config_t phy_config = ETH_PHY_DEFAULT_CONFIG();
    phy_config.phy_addr = 0;
    phy_config.reset_gpio_num = -1;
    phy_config.reset_timeout_ms = 2000;
    mac_config.smi_mdc_gpio_num = 23;
    mac_config.smi_mdio_gpio_num = 18;
    mac = esp_eth_mac_new_esp32(&mac_config);
#if CONFIG_SMOOTH_ETH_PHY_MOCK
    phy = esp_eth_phy_new_mock(&phy_config);
#else
    phy = esp_eth_phy_new_lan8742(&phy_config);
#endif
    esp_eth_config_t config = ETH_DEFAULT_CONFIG(mac, phy);
    esp_eth_driver_install(&config, &eth_handle);

    auto err = esp_netif_attach(interface, esp_eth_new_netif_glue(eth_handle));

    if (err == ESP_OK) {
        /* start Ethernet driver state machine */
        err = esp_eth_start(eth_handle);
    }
}

void deinit()
{
    esp_event_handler_instance_unregister(IP_EVENT, ESP_EVENT_ANY_ID, instance_ip_event);
    esp_event_handler_instance_unregister(ETH_EVENT, ESP_EVENT_ANY_ID, instance_eth_event);

    if (eth_handle) {
        esp_eth_stop(eth_handle);
    }
}

void eth_event_handler(void* event_handler_arg,
                       esp_event_base_t event_base,
                       int32_t event_id,
                       void* event_data)
{
    if (event_base == ETH_EVENT) {
        switch (event_id) {
        case ETHERNET_EVENT_START: {
        } break;
        case ETHERNET_EVENT_STOP: {
            ip.addr = 0;
        } break;
        case ETHERNET_EVENT_CONNECTED: {
            connected = true;
        } break;
        case ETHERNET_EVENT_DISCONNECTED: {
            ip.addr = 0;
            connected = false;
        } break;
        }
    } else if (event_base == IP_EVENT) {
        if (event_id == IP_EVENT_ETH_GOT_IP) {
            ip.addr = reinterpret_cast<ip_event_got_ip_t*>(event_data)->ip_info.ip.addr;
        }
    }
}

esp_ip4_addr ip4()
{
    return ip;
}

bool isConnected()
{
    return connected;
}
}