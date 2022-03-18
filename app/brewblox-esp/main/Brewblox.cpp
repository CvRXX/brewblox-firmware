#include "intellisense.hpp"

#include "AppTicks.hpp"
#include "Brewblox.hpp"
#include "blocks/DisplaySettingsBlock.hpp"
#include "blocks/SysInfoBlock.hpp"
#include "blocks/TicksBlock.hpp"
#include "blocks/stringify.hpp"
#include "cbox/Box.hpp"
#include "cbox/Connections.hpp"
#include "proto/proto_version.h"
#include <esp_wifi.h>
#include <esp_wifi_types.h>

Logger& getLogger()
{
    static Logger logger([](Logger::LogLevel level, const std::string& log) {
        // TODO
    });
    return logger;
}

void setupSystemBlocks()
{
    cbox::objects.init({
        cbox::ContainedObject(2, std::shared_ptr<cbox::Object>(new SysInfoBlock(get_device_id))),
        cbox::ContainedObject(3, std::shared_ptr<cbox::Object>(new TicksBlock<Ticks<TicksEsp>>(ticks))),
        cbox::ContainedObject(7, std::shared_ptr<cbox::Object>(new DisplaySettingsBlock())),
    });

    cbox::objects.setObjectsStartId(cbox::userStartId);
}

// platform specific implementation for prototype in brewblox.hpp
// returns actual bytes written
// must be called after wifi init to have valid mac address
unsigned get_device_id(uint8_t* dest, unsigned max_len)
{
    uint8_t mac[6];
    if (esp_wifi_get_mac(WIFI_IF_STA, mac) == ESP_OK) {
        uint8_t i;
        for (i = 0; i < max_len && i < 6; i++) {
            dest[i] = mac[i];
        }
        return i;
    }
    return 0;
}

std::string deviceIdStringInit()
{
    uint8_t id[12];
    auto len = get_device_id(id, 12);
    std::string hex;
    hex.reserve(len);
    for (uint8_t i = 0; i < len; i++) {
        hex.push_back(cbox::d2h(uint8_t(id[i] & 0xF0) >> 4));
        hex.push_back(cbox::d2h(uint8_t(id[i] & 0xF)));
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

// Implements extern function in cbox/Connections.h
void cbox::connectionStarted(DataOut& out)
{
    char header[] = "<!BREWBLOX,";

    out.writeBuffer(header, strlen(header));
    out.writeBuffer(versionCsv().data(), versionCsv().length());
    out.write(',');
    cbox::EncodedDataOut hexOut(out);

    hexOut.write(resetReason());
    out.write(',');
    hexOut.write(resetReasonData());
    out.write(',');

    out.writeBuffer(deviceIdString().data(), deviceIdString().size());
    out.write('>');
}
