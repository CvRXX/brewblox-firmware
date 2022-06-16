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

std::string deviceIdString;
std::vector<uint8_t> deviceIdVector;

std::string_view getDeviceId()
{
    return deviceIdString;
}

void setDeviceId(const std::string& id)
{
    deviceIdString = id;
    if (deviceIdString.size() % 2 > 0) {
        deviceIdString.push_back('0');
    }

    size_t digitSize = deviceIdString.size() / 2;
    deviceIdVector.resize(digitSize);
    for (size_t i = 0; i <= digitSize; i++) {
        deviceIdVector[i] = cbox::h2d(deviceIdString[i * 2], deviceIdString[i * 2 + 1]);
    }
}

size_t rawDeviceId(uint8_t* dest, size_t max_len)
{
    if (max_len > deviceIdVector.size()) {
        max_len = deviceIdVector.size();
    }
    std::memcpy(dest, deviceIdVector.data(), max_len);
    return max_len;
}

std::string_view versionCsv()
{
    static constexpr char version[] = GIT_VERSION "," COMPILED_PROTO_VERSION "," GIT_DATE "," COMPILED_PROTO_DATE "," stringify(SYSTEM_VERSION_STRING) "," PLATFORM_NAME;
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
    objects.add(std::shared_ptr<cbox::Object>(new SysInfoBlock(rawDeviceId)), 2);
    objects.add(std::shared_ptr<cbox::Object>(new TicksBlock<TicksClass>(ticks)), 3);
    objects.add(std::shared_ptr<cbox::Object>(new DisplaySettingsBlock()), 7);
    objects.setObjectsStartId(cbox::userStartId);
}
