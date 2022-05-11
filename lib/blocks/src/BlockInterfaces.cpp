/*
 * Copyright 2018 BrewPi B.V.
 *
 * This file is part of Brewblox
 *
 * Brewblox is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with Brewblox.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "AppTicks.hpp"
#include "blocks/OneWireDeviceBlock.hpp"
#include "cbox/ObjectBase.hpp"
#include "control/ActuatorAnalogConstrained.hpp"
#include "control/ActuatorDigitalConstrained.hpp"
#include "control/Balancer.hpp"
#include "control/DS2408.hpp"
#include "control/Enabler.hpp"
#include "control/FixedPoint.hpp"
#include "control/IoArray.hpp"
#include "control/IoModule.hpp"
#include "control/OneWireDevice.hpp"
#include "control/ProcessValue.hpp"
#include "control/SetpointSensorPair.hpp"
#include "control/TempSensor.hpp"
#include "proto/Constraints.pb.h"
#include "proto/brewblox.pb.h"

namespace cbox {

template <>
obj_type_t
interfaceIdImpl<ProcessValue<fp12_t>>()
{
    return brewblox_BlockType_ProcessValueInterface;
}

template <>
obj_type_t
interfaceIdImpl<TempSensor>()
{
    return brewblox_BlockType_TempSensorInterface;
}

template <>
obj_type_t
interfaceIdImpl<SetpointSensorPair>()
{
    return brewblox_BlockType_SetpointSensorPairInterface;
}

template <>
obj_type_t
interfaceIdImpl<ActuatorAnalogConstrained>()
{
    return brewblox_BlockType_ActuatorAnalogInterface;
}

template <>
obj_type_t
interfaceIdImpl<ActuatorDigitalConstrained>()
{
    return brewblox_BlockType_ActuatorDigitalInterface;
}

template <>
obj_type_t
interfaceIdImpl<MutexTarget>()
{
    return brewblox_BlockType_MutexInterface;
}

template <>
obj_type_t
interfaceIdImpl<Balancer<blox_Constraints_DigitalConstraint_mutex_tag>>()
{
    return brewblox_BlockType_BalancerInterface;
}

template <>
obj_type_t
interfaceIdImpl<OneWireDevice>()
{
    return brewblox_BlockType_OneWireDeviceInterface;
}

template <>
obj_type_t
interfaceIdImpl<IoArray>()
{
    return brewblox_BlockType_IoArrayInterface;
}

template <>
obj_type_t
interfaceIdImpl<DS2408>()
{
    return brewblox_BlockType_DS2408Interface;
}

template <>
obj_type_t
interfaceIdImpl<OneWire>()
{
    return brewblox_BlockType_OneWireBusInterface;
}

template <>
obj_type_t
interfaceIdImpl<IoModule>()
{
    return brewblox_BlockType_IoModuleInterface;
}

template <>
obj_type_t
interfaceIdImpl<OneWireDeviceBlock>()
{
    return brewblox_BlockType_OneWireDeviceBlockInterface;
}

template <>
obj_type_t
interfaceIdImpl<Enabler>()
{
    return brewblox_BlockType_EnablerInterface;
}

} // end namespace cbox
