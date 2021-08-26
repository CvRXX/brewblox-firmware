#pragma once
#include "brewblox.hpp"
#include <esp_err.h>
#include <esp_log.h>
#include <mdns.h>

namespace mdns {

void start()
{
    auto err = mdns_init();
    if (err) {
        ESP_LOGE("MDNS", "init failed: %s", esp_err_to_name(err));
        return;
    }

    //set hostname
    std::string hostname_string = "brewblox_spark4_" + deviceIdString();
    const char* hostname = hostname_string.c_str();

    mdns_hostname_set(hostname);
    mdns_instance_name_set(hostname);

    mdns_service_add(hostname, "_http", "_tcp", 80, NULL, 0);

    mdns_txt_item_t serviceTxtData[4] = {
        {"VERSION", GIT_VERSION},
        {"ID", deviceIdString().c_str()},
        {"PLATFORM", "100"},
        {"HW", "Spark 4"}};
    mdns_service_add(hostname, "_brewblox", "_tcp", 8332, serviceTxtData, 4);
}

}
