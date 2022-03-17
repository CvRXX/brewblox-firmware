/*
 * Copyright 2019 BrewPi B.V.
 *
 * This file is part of BrewPi.
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

#if PLATFORM_ID == 6

#include "spark/Spark2PinsBlock.h"
#include "pinmap_defines.h"
#include "proto/Spark2Pins.pb.h"
#include "spark/Board.h"

pin_t Spark2PinsBlock::channelToPin(uint8_t channel) const
{
    auto pins = std::array<pin_t, numPins>{
        PIN_ACTUATOR1,
        PIN_ACTUATOR2,
        PIN_ACTUATOR3,
        PIN_ACTUATOR0,
    };

    if (validChannel(channel)) {
        return pins[channel - 1];
    }
    return -1;
}

Spark2PinsBlock::Spark2PinsBlock()
    : SparkIoBase(getSparkVersion() == SparkVersion::V2 ? numPins : numPins - 1)
{
}

cbox::CboxError Spark2PinsBlock::read(const cbox::PayloadCallback& callback) const
{
    blox_Spark2Pins_Block message = blox_Spark2Pins_Block_init_zero;

    if (getSparkVersion() != SparkVersion::V1) {
        message.channels[0].id = blox_Spark2Pins_ChannelId_SPARK2_CHAN_BOTTOM0;
        message.channels[1].id = blox_Spark2Pins_ChannelId_SPARK2_CHAN_BOTTOM1;
        message.channels[2].id = blox_Spark2Pins_ChannelId_SPARK2_CHAN_BOTTOM2;
        message.channels[3].id = blox_Spark2Pins_ChannelId_SPARK2_CHAN_BOTTOM3;
        message.channels_count = 4;
    } else {
        message.channels[0].id = blox_Spark2Pins_ChannelId_SPARK2_CHAN_BOTTOM1;
        message.channels[1].id = blox_Spark2Pins_ChannelId_SPARK2_CHAN_BOTTOM2;
        message.channels[2].id = blox_Spark2Pins_ChannelId_SPARK2_CHAN_BOTTOM3;
        message.channels_count = 3;
    }

    message.soundAlarm = HAL_GPIO_Read(PIN_ALARM);

    auto hw = blox_Spark2Pins_Hardware_HW_UNKNOWN;
    switch (getSparkVersion()) {
    case SparkVersion::V1:
        hw = blox_Spark2Pins_Hardware_HW_SPARK1;
        break;
    case SparkVersion::V2:
        hw = blox_Spark2Pins_Hardware_HW_SPARK2;
        break;
    }
    message.hardware = hw;

    return callWithMessage(callback,
                           objectId,
                           staticTypeId(),
                           0,
                           &message,
                           blox_Spark2Pins_Block_fields,
                           blox_Spark2Pins_Block_size);
}

cbox::CboxError Spark2PinsBlock::readStored(const cbox::PayloadCallback& callback) const
{
    blox_Spark2Pins_Block message = blox_Spark2Pins_Block_init_zero;

    message.soundAlarm = HAL_GPIO_Read(PIN_ALARM);

    return callWithMessage(callback,
                           objectId,
                           staticTypeId(),
                           0,
                           &message,
                           blox_Spark2Pins_Block_fields,
                           blox_Spark2Pins_Block_size);
}

cbox::CboxError Spark2PinsBlock::write(const cbox::Payload& payload)
{
    blox_Spark2Pins_Block message = blox_Spark2Pins_Block_init_zero;
    auto res = payloadToMessage(payload, &message, blox_Spark2Pins_Block_fields);

    if (res == cbox::CboxError::OK) {
        // io pins are not writable through this block. They are configured by creating Digital Actuators
        digitalWriteFast(PIN_ALARM, message.soundAlarm);
    }

    return res;
}

void* Spark2PinsBlock::implements(const cbox::obj_type_t& iface)
{
    if (iface == brewblox_BlockType_Spark2Pins) {
        return this; // me!
    }
    if (iface == cbox::interfaceId<IoArray>()) {
        // return the member that implements the interface in this case
        IoArray* ptr = this;
        return ptr;
    }
    return nullptr;
}

#endif
