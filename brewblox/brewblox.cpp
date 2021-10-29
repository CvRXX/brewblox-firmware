/*
 * Copyright 2021 BrewPi B.V.
 *
 * This file is part of Brewblox.
 *
 * BrewPi is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * BrewPi is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with BrewPi.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "brewblox.hpp"
#include "blox/ActuatorAnalogMockBlock.h"
#include "blox/ActuatorLogicBlock.h"
#include "blox/ActuatorOffsetBlock.h"
#include "blox/ActuatorPwmBlock.h"
#include "blox/BalancerBlock.h"
#include "blox/DS2408Block.h"
#include "blox/DS2413Block.h"
#include "blox/DigitalActuatorBlock.h"
#include "blox/MockPinsBlock.h"
#include "blox/MotorValveBlock.h"
#include "blox/MutexBlock.h"
#include "blox/PidBlock.h"
#include "blox/SetpointProfileBlock.h"
#include "blox/SetpointSensorPairBlock.h"
#include "blox/TempSensorCombiBlock.h"
#include "blox/TempSensorMockBlock.h"
#include "blox/TempSensorOneWireBlock.h"
#include "blox/compiled_proto/src/proto_version.h"
#include "blox/stringify.h"
#include "cbox/ScanningFactory.hpp"
#include <memory>

namespace brewblox {

cbox::Box& make_box(cbox::ObjectContainer& objects,
                    const cbox::ObjectFactory& platformFactory,
                    cbox::ObjectStorage& storage,
                    cbox::ConnectionPool& connectionPool,
                    const std::vector<std::reference_wrapper<cbox::ScanningFactory>>& scanners)
{
    static const cbox::ObjectFactory factory({
        cbox::makeFactoryEntry<TempSensorOneWireBlock>(),
        cbox::makeFactoryEntry<SetpointSensorPairBlock>(),
        cbox::makeFactoryEntry<TempSensorMockBlock>(),
        cbox::makeFactoryEntry<ActuatorAnalogMockBlock>(),
        cbox::makeFactoryEntry<PidBlock>(),
        cbox::makeFactoryEntry<ActuatorPwmBlock>(),
        cbox::makeFactoryEntry<ActuatorOffsetBlock>(),
        cbox::makeFactoryEntry<BalancerBlock>(),
        cbox::makeFactoryEntry<MutexBlock>(),
        cbox::makeFactoryEntry<SetpointProfileBlock>(),
        cbox::makeFactoryEntry<DS2413Block>(),
        cbox::makeFactoryEntry<DigitalActuatorBlock>(),
        cbox::makeFactoryEntry<DS2408Block>(),
        cbox::makeFactoryEntry<MotorValveBlock>(),
        cbox::makeFactoryEntry<ActuatorLogicBlock>(),
        cbox::makeFactoryEntry<MockPinsBlock>(),
        cbox::makeFactoryEntry<TempSensorCombiBlock>(),
    });

    static const std::vector<std::reference_wrapper<const cbox::ObjectFactory>> factories{{std::cref(factory), std::cref(platformFactory)}};

    static cbox::Box box(factories, objects, storage, connectionPool, scanners);

    return box;
}

} // end namespace brewlbox

const std::string&
versionCsv()
{
#if PLATFORM_ID == 3
#define PLATFORM_STRING "gcc"
#elif PLATFORM_ID == 6
#define PLATFORM_STRING "photon"
#elif PLATFORM_ID == 8
#define PLATFORM_STRING "p1"
#elif PLATFORM_ID == 100
#define PLATFORM_STRING "esp32"
#else
#define PLATFORM_STRING "unkown"
#endif

    static const std::string version = GIT_VERSION "," COMPILED_PROTO_VERSION "," GIT_DATE "," COMPILED_PROTO_DATE "," stringify(SYSTEM_VERSION_STRING) "," PLATFORM_STRING;
    return version;
}

constexpr bool equal(char const* lhs, char const* rhs)
{
    while (*lhs || *rhs)
        if (*lhs++ != *rhs++)
            return false;
    return true;
}

static_assert(equal(PROTO_VERSION, COMPILED_PROTO_VERSION));

std::string
deviceIdStringInit()
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

const std::string&
deviceIdString()
{
    static std::string hexId;
    if (hexId.empty()) {
        // device ID can be unknown before wifi is initialized
        hexId = deviceIdStringInit();
    }
    return hexId;
}

namespace cbox {
void connectionStarted(DataOut& out)
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
}