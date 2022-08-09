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
#include "cbox/PayloadConversion.hpp"
#include "proto/Spark3Pins.pb.h"
#include "spark/Board.hpp"
#include <array>

#if PLATFORM_ID != 3
#include "spark/BrewPiTouch.hpp"
extern platform::particle::BrewPiTouch touch;
#endif

namespace platform::particle {

struct SparkChannel {
    pin_t pin;
    int8_t duty;
};

static std::array<SparkChannel, 5> spark3Channels{{
#ifdef PIN_V3_TOP1
    {PIN_V3_TOP1, -1},
#else
    {pin_t(-1), -1},
#endif
    {PIN_V3_TOP2, -1},
    {PIN_V3_TOP3, -1},
    {PIN_V3_BOTTOM1, -1},
    {PIN_V3_BOTTOM2, -1},
}};

void Spark3PinsBlock::timerTask()
{
    // timer clock is 10 kHz, 100 steps at 100Hz
    static int8_t count = 0;
    for (auto chan : spark3Channels) {
        auto pin = chan.pin;
        if (pin == -1) {
            continue;
        }
        auto duty = chan.duty;
        if (duty == -1) {
            continue;
        }
        if (count == 0 && duty > 0) {
            pinSetFast(pin);
        }
        if (count == duty) {
            pinResetFast(pin);
        }
    }
    count = count >= 99 ? 0 : count + 1;
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
    message.channels[0].capabilities = getChannelCapabilities(1).all;
    message.channels[1].capabilities = getChannelCapabilities(2).all;
    message.channels[2].capabilities = getChannelCapabilities(3).all;
    message.channels[3].capabilities = getChannelCapabilities(4).all;
    message.channels[4].capabilities = getChannelCapabilities(5).all;

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

    return cbox::PayloadBuilder(*this)
        .withContent(&message,
                     blox_Spark3Pins_Block_fields,
                     blox_Spark3Pins_Block_size)
        .respond(callback)
        .status();
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

    return cbox::PayloadBuilder(*this)
        .withContent(&message,
                     blox_Spark3Pins_Block_fields,
                     blox_Spark3Pins_Block_size)
        .respond(callback)
        .status();
}

cbox::CboxError Spark3PinsBlock::write(const cbox::Payload& payload)
{
    blox_Spark3Pins_Block message = blox_Spark3Pins_Block_init_zero;
    auto parser = cbox::PayloadParser(payload);

    if (parser.fillMessage(&message, blox_Spark3Pins_Block_fields)) {
        if (parser.hasField(blox_Spark3Pins_Block_soundAlarm_tag)) {
            digitalWriteFast(PIN_ALARM, message.soundAlarm);
        }
#if defined(PIN_5V_ENABLE)
        if (parser.hasField(blox_Spark3Pins_Block_enableIoSupply5V_tag)) {
            digitalWriteFast(PIN_5V_ENABLE, message.enableIoSupply5V);
        }
#endif
#if defined(PIN_12V_ENABLE)
        if (parser.hasField(blox_Spark3Pins_Block_enableIoSupply12V_tag)) {
            digitalWriteFast(PIN_12V_ENABLE, message.enableIoSupply12V);
        }
#endif
    }

    return parser.status();
}

void* Spark3PinsBlock::implements(cbox::obj_type_t iface)
{
    if (iface == staticTypeId()) {
        return this; // me!
    }
    if (iface == cbox::interfaceId<IoArray>()) {
        // return the member that implements the interface in this case
        IoArray* ptr = this;
        return ptr;
    }
    return nullptr;
}

IoValue::variant Spark3PinsBlock::writeChannelImpl(uint8_t channel, IoValue::variant val)
{
    if (channel > spark3Channels.size()) {
        return IoValue::Error::INVALID_CHANNEL;
    }

    auto& chan = spark3Channels[channel - 1];

    if (auto* v = std::get_if<IoValue::Digital>(&val)) {
        chan.duty = -1; // disables pwm updates
        auto state = v->state();
        if (state == IoValue::State::Active) {
            pinSetFast(chan.pin);
            return IoValue::Digital{state};
        } else if (state == IoValue::State::Inactive) {
            pinResetFast(chan.pin);
            return IoValue::Digital{state};
        }
    } else if (auto pwmVal = std::get_if<IoValue::PWM>(&val)) {
        chan.duty = static_cast<int8_t>(pwmVal->duty() + IoValue::PWM::duty_t{0.5});
        return *pwmVal;
    }
    return IoValue::Error::UNSUPPORTED_VALUE;
};

// prevent inlining of hal function to save code size
inline void setPinMode(pin_t pin, PinMode setMode)
{
    HAL_Pin_Mode(pin, setMode);
}

IoValue::Setup::variant Spark3PinsBlock::setupChannelImpl(uint8_t channel, IoValue::Setup::variant setup)
{
    if (channel > spark3Channels.size()) {
        return IoValue::Error::INVALID_CHANNEL;
    }

    auto& chan = spark3Channels[channel - 1];
    if (chan.pin == pin_t{1}) {
        return IoValue::Error::UNSUPPORTED_SETUP;
    }

    chan.duty = std::holds_alternative<IoValue::Setup::OutputPwm>(setup) ? 0 : -1;

    if (std::holds_alternative<IoValue::Setup::OutputDigital>(setup)
        || std::holds_alternative<IoValue::Setup::OutputPwm>(setup)) {
#if defined(PIN_V3_TOP1_DIR)
        if (chan.pin == PIN_V3_TOP1) {
            // will also set pin mode, smaller code size than HAL_Pin_Mode and pinSetFast due to inlining
            HAL_GPIO_Write(PIN_V3_TOP1_DIR, LOW);
        }
#endif
#if defined(PIN_V3_TOP2_DIR)
        if (chan.pin == PIN_V3_TOP2) {
            HAL_GPIO_Write(PIN_V3_TOP2_DIR, LOW);
        }
#endif
        setPinMode(chan.pin, OUTPUT);
        return setup;
    }
    if (std::holds_alternative<IoValue::Setup::InputDigital>(setup)) {
        // support inputs on top 1 and top 2 of spark 3
#if defined(PIN_V3_TOP1_DIR)
        if (chan.pin == PIN_V3_TOP1) {
            setPinMode(chan.pin, INPUT_PULLDOWN);
            return setup;
        }
#endif
#if defined(PIN_V3_TOP2_DIR)
        if (chan.pin == PIN_V3_TOP2) {
            setPinMode(chan.pin, INPUT_PULLDOWN);
            return setup;
        }
#endif
        return IoValue::Error::UNSUPPORTED_SETUP;
    }
    if (std::holds_alternative<IoValue::Setup::Unused>(setup)) {
        setPinMode(chan.pin, INPUT_PULLDOWN);
        return setup;
    }
    return IoValue::Error::UNSUPPORTED_SETUP;
}

// generic ArrayIO interface
IoValue::variant Spark3PinsBlock::readChannelImpl(uint8_t channel) const
{
    if (channel > spark3Channels.size()) {
        return IoValue::Error::INVALID_CHANNEL;
    }

    const auto setup = channelSetup(channel);
    auto& chan = spark3Channels[channel - 1];

    if (std::holds_alternative<IoValue::Setup::OutputDigital>(setup)) {
        return pinReadFast(chan.pin) != 0 ? IoValue::Digital{State::Active} : IoValue::Digital{State::Inactive};
    } else if (std::holds_alternative<IoValue::Setup::OutputPwm>(setup)) {
        return IoValue::PWM{chan.duty};
    }
    return IoValue::Error::UNSUPPORTED_VALUE;
}

int16_t Spark3PinsBlock::myInterrupt = 0;

} // end namespace platform::particle

#endif
