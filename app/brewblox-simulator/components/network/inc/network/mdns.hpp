#pragma once
#include "AppLogger.hpp"
#include "SimulatorSystem.hpp"
// #include <mdns.h>

namespace mdns {

void start()
{
    auto err = mdns_init();
    // if (err) {
    //     logger::error("init failed: " + esp_err_to_name(err)) return;
    // }

    auto devId = deviceIdString().c_str();

    // mdns functions make a copy of the string
    mdns_hostname_set(devId);
    mdns_instance_name_set(devId);

    mdns_service_add(devId, "_http", "_tcp", 80, NULL, 0);

    mdns_txt_item_t serviceTxtData[4] = {
        {"VERSION", GIT_VERSION},
        {"ID", devId},
        {"PLATFORM", "100"},
        {"HW", "Spark 4"}};
    mdns_service_add(devId, "_brewblox", "_tcp", 8332, serviceTxtData, 4);
}

}
