#include "intellisense.hpp"

#include "AppTicks.hpp"
#include "Brewblox.hpp"
#include "blocks/DisplaySettingsBlock.hpp"
#include "blocks/SysInfoBlock.hpp"
#include "blocks/stringify.hpp"
#include "cbox/Application.hpp"
#include "cbox/Box.hpp"
#include "cbox/Hex.hpp"
#include "proto/proto_version.h"
#include <cstring>
#include <esp_wifi.h>
#include <esp_wifi_types.h>

// platform specific implementation for prototype in brewblox.hpp
// returns actual bytes written
// must be called after wifi init to have valid mac address
size_t readDeviceId(uint8_t* dest, size_t max_len)
{
    uint8_t mac[6];
    if (esp_wifi_get_mac(WIFI_IF_STA, mac) == ESP_OK && max_len >= 6) {
        std::memcpy(dest, mac, 6);
        return 6;
    }
    return 0;
}

std::string deviceIdStringInit()
{
    uint8_t id[12];
    auto len = readDeviceId(id, 12);
    std::string hex;
    hex.reserve(len);
    for (uint8_t i = 0; i < len; i++) {
        auto pair = cbox::d2h(id[i]);
        hex.push_back(pair.first);
        hex.push_back(pair.second);
    }
    return hex;
}

const std::string& deviceIdString()
{
    static std::string hexId;
    if (hexId.empty()) {
        // device ID can be unknown before wifi is initialized
        hexId = deviceIdStringInit();
    }
    return hexId;
}

const std::string& versionCsv()
{
    static const std::string version = GIT_VERSION "," COMPILED_PROTO_VERSION "," GIT_DATE "," COMPILED_PROTO_DATE "," stringify(SYSTEM_VERSION_STRING) "," PLATFORM_NAME;
    return version;
}

int resetReason()
{
    return 0; // todo
}

int resetReasonData()
{
    return 0; // todo
}

void setupSystemBlocks()
{
    auto& objects = cbox::getObjects();

    objects.setObjectsStartId(cbox::systemStartId);
    objects.add(std::shared_ptr<cbox::Object>(new SysInfoBlock(readDeviceId)), 2);
    objects.add(std::shared_ptr<cbox::Object>(new DisplaySettingsBlock()), 7);
    objects.setObjectsStartId(cbox::userStartId);
}
