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

#if PLATFORM_ID == 8 || PLATFORM_ID == 3

#include "spark/Spark3PinsBlock.hpp"
#include "proto/Spark3Pins.pb.h"
#include "spark/Board.hpp"

#if PLATFORM_ID != 3
#include "spark/BrewPiTouch.hpp"
extern platform::particle::BrewPiTouch touch;
#endif

namespace platform::particle {

pin_t Spark3PinsBlock::channelToPin(uint8_t channel) const
{
    auto pins = std::array<pin_t, numPins>{
#ifdef PIN_V3_TOP1
        PIN_V3_TOP1,
#else
        pin_t(-1),
#endif
        PIN_V3_TOP2,
        PIN_V3_TOP3,
        PIN_V3_BOTTOM1,
        PIN_V3_BOTTOM2,
    };

    if (validChannel(channel)) {
        return pins[channel - 1];
    }
    return -1;
}

cbox::CboxError Spark3PinsBlock::read(const cbox::PayloadCallback& callback) const
{
    blox_Spark3Pins_Block message = blox_Spark3Pins_Block_init_zero;

    message.channels_count = 5;
    message.channels[0].id = blox_Spark3Pins_ChannelId_SPARK3_CHAN_TOP1;
    message.channels[1].id = blox_Spark3Pins_ChannelId_SPARK3_CHAN_TOP2;
    message.channels[2].id = blox_Spark3Pins_ChannelId_SPARK3_CHAN_TOP3;
    message.channels[3].id = blox_Spark3Pins_ChannelId_SPARK3_CHAN_BOTTOM1;
    message.channels[4].id = blox_Spark3Pins_ChannelId_SPARK3_CHAN_BOTTOM2;

    message.soundAlarm = HAL_GPIO_Read(PIN_ALARM);
#if defined(PIN_5V_ENABLE)
    message.enableIoSupply5V = HAL_GPIO_Read(PIN_5V_ENABLE);
#endif
#if defined(PIN_12V_ENABLE)
    message.enableIoSupply12V = HAL_GPIO_Read(PIN_12V_ENABLE);
#endif

#if PLATFORM_ID != 3
    message.voltage5 = touch.read5V();
    message.voltage12 = touch.read12V();
#else
    message.voltage5 = 5 * 410;
    message.voltage12 = 12 * 149;
#endif

    return callWithMessage(callback,
                           objectId,
                           staticTypeId(),
                           0,
                           &message,
                           blox_Spark3Pins_Block_fields,
                           blox_Spark3Pins_Block_size);
}

cbox::CboxError Spark3PinsBlock::readStored(const cbox::PayloadCallback& callback) const
{
    blox_Spark3Pins_Block message = blox_Spark3Pins_Block_init_zero;

    message.soundAlarm = HAL_GPIO_Read(PIN_ALARM);
#if defined(PIN_5V_ENABLE)
    message.enableIoSupply5V = HAL_GPIO_Read(PIN_5V_ENABLE);
#endif
#if defined(PIN_12V_ENABLE)
    message.enableIoSupply12V = HAL_GPIO_Read(PIN_12V_ENABLE);
#endif

    return callWithMessage(callback,
                           objectId,
                           staticTypeId(),
                           0,
                           &message,
                           blox_Spark3Pins_Block_fields,
                           blox_Spark3Pins_Block_size);
}

cbox::CboxError Spark3PinsBlock::write(const cbox::Payload& payload)
{
    blox_Spark3Pins_Block message = blox_Spark3Pins_Block_init_zero;
    auto res = payloadToMessage(payload, &message, blox_Spark3Pins_Block_fields);

    if (res == cbox::CboxError::OK) {
        // io pins are not writable through this block. They are configured by creating Digital Actuators
        digitalWriteFast(PIN_ALARM, message.soundAlarm);
#if defined(PIN_5V_ENABLE)
        digitalWriteFast(PIN_5V_ENABLE, message.enableIoSupply5V);
#endif
#if defined(PIN_12V_ENABLE)
        digitalWriteFast(PIN_12V_ENABLE, message.enableIoSupply12V);
#endif
    }

    return res;
}

void* Spark3PinsBlock::implements(cbox::obj_type_t iface)
{
    if (iface == brewblox_BlockType_Spark3Pins) {
        return this; // me!
    }
    if (iface == cbox::interfaceId<IoArray>()) {
        // return the member that implements the interface in this case
        IoArray* ptr = this;
        return ptr;
    }
    return nullptr;
}

} // end namespace platform::particle

#endif
