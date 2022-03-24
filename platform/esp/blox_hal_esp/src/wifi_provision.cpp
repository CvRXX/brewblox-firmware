/* Wi-Fi Provisioning Manager Example
   This example code is in the Public Domain (or CC0 licensed, at your option.)
   Unless required by applicable law or agreed to in writing, this
   software is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR
   CONDITIONS OF ANY KIND, either express or implied.
*/

#include <stdio.h>
#include <string.h>

#include <esp_log.h>
#include <esp_wifi.h>
#include <nvs_flash.h>

#include "blox_hal/hal_delay.hpp"
#include "blox_hal/hal_network.hpp"
#include "wifi.hpp"
#include "wifi_provision.hpp"
#include <string>
#include <wifi_provisioning/manager.h>
#include <wifi_provisioning/scheme_ble.h>
// #include <wifi_provisioning/scheme_softap.h>

namespace wifi_provision {
constexpr auto TAG = "PROVISION";

esp_event_handler_instance_t instance_wifi_prov_event = nullptr;
bool isRunning = false;

void get_device_service_name(char* service_name, size_t max)
{
    uint8_t eth_mac[6];
    const char* ssid_prefix = "PROV_BREWBLOX_";
    esp_wifi_get_mac(WIFI_IF_STA, eth_mac);
    snprintf(service_name, max, "%s%02X%02X%02X",
             ssid_prefix, eth_mac[3], eth_mac[4], eth_mac[5]);
}

/* Event handler for provisioning events */
static void event_handler(void* arg, esp_event_base_t event_base,
                          int32_t event_id, void* event_data)
{
    if (event_base == WIFI_PROV_EVENT) {
        switch (event_id) {
        case WIFI_PROV_INIT:
            break;
        case WIFI_PROV_START:
            ESP_LOGI(TAG, "Provisioning started");
            break;
        case WIFI_PROV_CRED_RECV: {
            wifi_sta_config_t* wifi_sta_cfg = (wifi_sta_config_t*)event_data;
            ESP_LOGI(TAG,
                     "Received Wi-Fi credentials for SSID: %s\n",
                     wifi_sta_cfg->ssid);
            break;
        }
        case WIFI_PROV_CRED_FAIL: {
            wifi_prov_sta_fail_reason_t* reason = (wifi_prov_sta_fail_reason_t*)event_data;
            ESP_LOGE(TAG,
                     "Provisioning failed!\n\tReason : %s"
                     "\n\tPlease reset to factory and retry provisioning",
                     (*reason == WIFI_PROV_STA_AUTH_ERROR) ? "Wi-Fi station authentication failed" : "Wi-Fi access-point not found");
            if (*reason == WIFI_PROV_STA_AUTH_ERROR) {
                clear();
            }
            wifi_prov_mgr_stop_provisioning();
            break;
        }
        case WIFI_PROV_CRED_SUCCESS:
            ESP_LOGI(TAG, "Provisioning successful");
            wifi_prov_mgr_stop_provisioning();
            break;
        case WIFI_PROV_END:
            ESP_LOGI(TAG, "PROV END");
            wifi_prov_mgr_deinit();
            isRunning = false;
            break;
        case WIFI_PROV_DEINIT:
            ESP_LOGI(TAG, "PROV DEINIT");
            // restart wifi with app event handlers
            wifi::stop();
            wifi::start();
        default:
            break;
        }
    }
}

void start()
{
    /* Configuration for the provisioning manager */
    static const wifi_prov_mgr_config_t ble_config{
        .scheme = wifi_prov_scheme_ble,
        .scheme_event_handler = WIFI_PROV_SCHEME_BLE_EVENT_HANDLER_FREE_BTDM,
        .app_event_handler = WIFI_PROV_EVENT_HANDLER_NONE};

    isRunning = true;

    wifi::stop(); // stop wifi as normal access point and disable custom event handlers and enable power saving
    wifi::init(); // ensure wifi is initialized, could be disabled if ethernet is connected

    if (!instance_wifi_prov_event) {
        /* Register our event handler for provisioning related events */
        ESP_ERROR_CHECK(esp_event_handler_instance_register(WIFI_PROV_EVENT, ESP_EVENT_ANY_ID, &event_handler, nullptr, &instance_wifi_prov_event));
    }

    if (wifi_prov_mgr_init(ble_config) != ESP_OK) {
        return;
    }

    /* disable auto stop and handle it manually to ensure that bluetooth doesn't clash with disabling wifi power saving
     * gives bluetooth 10 seconds to close communications and deinit
     */
    wifi_prov_mgr_disable_auto_stop(10000);

    /* What is the Device Service Name that we want
     * This translates to :
     *     - Wi-Fi SSID when scheme is wifi_prov_scheme_softap
     *     - device name when scheme is wifi_prov_scheme_ble
     */
    char service_name[22];
    get_device_service_name(service_name, sizeof(service_name));

    /* What is the security level that we want (0 or 1):
     *      - WIFI_PROV_SECURITY_0 is simply plain text communication.
     *      - WIFI_PROV_SECURITY_1 is secure communication which consists of secure handshake
     *          using X25519 key exchange and proof of possession (pop) and AES-CTR
     *          for encryption/decryption of messages.
     */
    wifi_prov_security_t security = WIFI_PROV_SECURITY_1;

    /* Do we want a proof-of-possession (ignored if Security 0 is selected):
     *      - this should be a string with length > 0
     *      - nullptr if not used
     */
    const char* pop = nullptr;

    /* What is the service key (could be nullptr)
     * This translates to :
     *     - Wi-Fi password when scheme is wifi_prov_scheme_softap
     *     - simply ignored when scheme is wifi_prov_scheme_ble
     */
    const char* service_key = nullptr;

    /* This step is only useful when scheme is wifi_prov_scheme_ble. This will
     * set a custom 128 bit UUID which will be included in the BLE advertisement
     * and will correspond to the primary GATT service that provides provisioning
     * endpoints as GATT characteristics. Each GATT characteristic will be
     * formed using the primary service UUID as base, with different auto assigned
     * 12th and 13th bytes (assume counting starts from 0th byte). The client side
     * applications must identify the endpoints by reading the User Characteristic
     * Description descriptor (0x2901) for each characteristic, which contains the
     * endpoint name of the characteristic */
    uint8_t custom_service_uuid[] = {
        /* LSB <---------------------------------------
         * ---------------------------------------> MSB */
        0xb4,
        0xdf,
        0x5a,
        0x1c,
        0x3f,
        0x6b,
        0xf4,
        0xbf,
        0xea,
        0x4a,
        0x82,
        0x03,
        0x04,
        0x90,
        0x1a,
        0x02,
    };
    wifi_prov_scheme_ble_set_service_uuid(custom_service_uuid);

    /* An optional endpoint that applications can create if they expect to
     * get some additional custom data during provisioning workflow.
     * The endpoint name can be anything of your choice.
     * This call must be made before starting the provisioning.
     */
    // wifi_prov_mgr_endpoint_create("custom-data");

    /* Start provisioning service */
    ESP_ERROR_CHECK(wifi_prov_mgr_start_provisioning(security, pop, service_name, service_key));

    /* The handler for the optional endpoint created above.
     * This call must be made after starting the provisioning, and only if the endpoint
     * has already been created above.
     */
    // wifi_prov_mgr_endpoint_register("custom-data", custom_prov_data_handler, nullptr);

    /* Uncomment the following to wait for the provisioning to finish and then release
     * the resources of the manager. Since in this case de-initialization is triggered
     * by the default event loop handler, we don't need to call the following */
    // wifi_prov_mgr_wait();
    // wifi_prov_mgr_deinit();
}

void stop()
{
    wifi_prov_mgr_stop_provisioning();
}

void clear()
{
    // wipe credentials
    wifi_prov_mgr_reset_provisioning();
}

bool isActive()
{
    return isRunning;
}

}
