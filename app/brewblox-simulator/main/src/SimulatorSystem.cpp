#include "intellisense.hpp"

#include "AppTicks.hpp"
#include "SimulatorSystem.hpp"
#include "blocks/DisplaySettingsBlock.hpp"
#include "blocks/SysInfoBlock.hpp"
#include "blocks/TicksBlock.hpp"
#include "blocks/stringify.hpp"
#include "cbox/Box.hpp"
#include "cbox/Hex.hpp"
#include "proto/proto_version.h"

void setupSystemBlocks()
{
    auto& objects = cbox::getObjects();

    objects.setObjectsStartId(cbox::systemStartId);
    objects.add(std::shared_ptr<cbox::Object>(new SysInfoBlock(get_device_id)), 2);
    objects.add(std::shared_ptr<cbox::Object>(new TicksBlock<TicksClass>(ticks)), 3);
    objects.add(std::shared_ptr<cbox::Object>(new DisplaySettingsBlock()), 7);
    objects.setObjectsStartId(cbox::userStartId);
}

unsigned get_device_id(uint8_t* dest, unsigned max_len)
{
    uint8_t mac[6]{0, 1, 2, 3, 4, 5};
    std::memcpy(dest, mac, 6);
    return 6;
}

std::string deviceIdStringInit()
{
    uint8_t id[12];
    auto len = get_device_id(id, 12);
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
