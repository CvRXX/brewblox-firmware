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

#include "ActuatorAnalogConstrained.h"
#include "ActuatorDigitalConstrained.h"
#include "AppTicks.h"
#include "Balancer.h"
#include "DS2408.h"
#include "FixedPoint.h"
#include "IoArray.h"
#include "IoModule.hpp"
#include "OneWireDevice.h"
#include "OneWireDeviceBlock.h"
#include "ProcessValue.h"
#include "SetpointSensorPair.h"
#include "TempSensor.h"
#include "blox/compiled_proto/src/Constraints.pb.h"
#include "blox/compiled_proto/src/brewblox.pb.h"
#include "cbox/ObjectBase.h"

namespace cbox {

template <>
const obj_type_t
interfaceIdImpl<ProcessValue<fp12_t>>()
{
    return BlockType_ProcessValueInterface;
}

template <>
const obj_type_t
interfaceIdImpl<TempSensor>()
{
    return BlockType_TempSensorInterface;
}

template <>
const obj_type_t
interfaceIdImpl<SetpointSensorPair>()
{
    return BlockType_SetpointSensorPairInterface;
}

template <>
const obj_type_t
interfaceIdImpl<ActuatorAnalogConstrained>()
{
    return BlockType_ActuatorAnalogInterface;
}

template <>
const obj_type_t
interfaceIdImpl<ActuatorDigitalConstrained>()
{
    return BlockType_ActuatorDigitalInterface;
}

template <>
const obj_type_t
interfaceIdImpl<MutexTarget>()
{
    return BlockType_MutexInterface;
}

template <>
const obj_type_t
interfaceIdImpl<Balancer<blox_DigitalConstraint_mutex_tag>>()
{
    return BlockType_BalancerInterface;
}

template <>
const obj_type_t
interfaceIdImpl<OneWireDevice>()
{
    return BlockType_OneWireDeviceInterface;
}

template <>
const obj_type_t
interfaceIdImpl<IoArray>()
{
    return BlockType_IoArrayInterface;
}

template <>
const obj_type_t
interfaceIdImpl<DS2408>()
{
    return BlockType_DS2408Interface;
}

template <>
const obj_type_t
interfaceIdImpl<OneWire>()
{
    return BlockType_OneWireBusInterface;
}

template <>
const obj_type_t
interfaceIdImpl<IoModule>()
{
    return BlockType_IoModuleInterface;
}

template <>
const obj_type_t
interfaceIdImpl<OneWireDeviceBlock>()
{
    return BlockType_OneWireDeviceBlockInterface;
}

} // end namespace cbox
