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

#include "spark/Spark2PinsBlock.hpp"
#include "cbox/PayloadConversion.hpp"
#include "proto/Spark2Pins.pb.h"
#include "spark/Board.hpp"
#include <array>

namespace platform::particle {

struct SparkChannel {
    pin_t pin;
    int8_t duty;
};

static std::array<SparkChannel, 4> spark2Channels{{
    {PIN_ACTUATOR0, -1},
    {PIN_ACTUATOR1, -1},
    {PIN_ACTUATOR2, -1},
    {PIN_ACTUATOR3, -1},
}};

void Spark2PinsBlock::timerTask()
{
    // timer clock is 10 kHz, 100 steps at 100Hz
    static int8_t count = 0;
    for (auto chan : spark2Channels) {
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

cbox::CboxError Spark2PinsBlock::read(const cbox::PayloadCallback& callback) const
{
    blox_Spark2Pins_Block message = blox_Spark2Pins_Block_init_zero;

    if (getSparkVersion() != SparkVersion::V1) {
        message.channels[0].id = blox_Spark2Pins_ChannelId_SPARK2_CHAN_BOTTOM0;
        message.channels[1].id = blox_Spark2Pins_ChannelId_SPARK2_CHAN_BOTTOM1;
        message.channels[2].id = blox_Spark2Pins_ChannelId_SPARK2_CHAN_BOTTOM2;
        message.channels[3].id = blox_Spark2Pins_ChannelId_SPARK2_CHAN_BOTTOM3;
        message.channels[3].capabilities = getChannelCapabilities(4).all;
        message.channels[3].claimedBy = getChannelClaimerId(4);
        message.channels_count = 4;
    } else {
        message.channels[0].id = blox_Spark2Pins_ChannelId_SPARK2_CHAN_BOTTOM1;
        message.channels[1].id = blox_Spark2Pins_ChannelId_SPARK2_CHAN_BOTTOM2;
        message.channels[2].id = blox_Spark2Pins_ChannelId_SPARK2_CHAN_BOTTOM3;
        message.channels_count = 3;
    }
    message.channels[0].capabilities = getChannelCapabilities(1).all;
    message.channels[1].capabilities = getChannelCapabilities(2).all;
    message.channels[2].capabilities = getChannelCapabilities(3).all;
    message.channels[0].claimedBy = getChannelClaimerId(1);
    message.channels[1].claimedBy = getChannelClaimerId(2);
    message.channels[2].claimedBy = getChannelClaimerId(3);

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

    return cbox::PayloadBuilder(*this)
        .withContent(&message,
                     blox_Spark2Pins_Block_fields,
                     blox_Spark2Pins_Block_size)
        .respond(callback)
        .status();
}

cbox::CboxError Spark2PinsBlock::readStored(const cbox::PayloadCallback& callback) const
{
    blox_Spark2Pins_Block message = blox_Spark2Pins_Block_init_zero;

    message.soundAlarm = HAL_GPIO_Read(PIN_ALARM);

    return cbox::PayloadBuilder(*this)
        .withContent(&message,
                     blox_Spark2Pins_Block_fields,
                     blox_Spark2Pins_Block_size)
        .respond(callback)
        .status();
}

cbox::CboxError Spark2PinsBlock::write(const cbox::Payload& payload)
{
    blox_Spark2Pins_Block message = blox_Spark2Pins_Block_init_zero;
    auto parser = cbox::PayloadParser(payload);

    if (parser.fillMessage(&message, blox_Spark2Pins_Block_fields)) {
        if (parser.hasField(blox_Spark2Pins_Block_soundAlarm_tag)) {
            digitalWriteFast(PIN_ALARM, message.soundAlarm);
        }
    }

    return parser.status();
}

void* Spark2PinsBlock::implements(cbox::obj_type_t iface)
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

IoValue::variant Spark2PinsBlock::writeChannelImpl(uint8_t channel, IoValue::variant val)
{
    if (channel > spark2Channels.size()) {
        return IoValue::Error::INVALID_CHANNEL;
    }

    if (getSparkVersion() == SparkVersion::V1 && channel == spark2Channels.size()) {
    }

    auto& chan = spark2Channels[channel - 1];

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

IoValue::Setup::variant Spark2PinsBlock::setupChannelImpl(uint8_t channel, IoValue::Setup::variant setup)
{
    if (channel > spark2Channels.size()) {
        return IoValue::Error::INVALID_CHANNEL;
    }

    if (getSparkVersion() == SparkVersion::V1 && channel == spark2Channels.size()) {
    }

    auto& chan = spark2Channels[channel - 1];
    if (chan.pin == pin_t{1}) {
        return IoValue::Error::UNSUPPORTED_SETUP;
    }

    chan.duty = std::holds_alternative<IoValue::Setup::OutputPwm>(setup) ? 0 : -1;

    if (std::holds_alternative<IoValue::Setup::OutputDigital>(setup)
        || std::holds_alternative<IoValue::Setup::OutputPwm>(setup)) {
        setPinMode(chan.pin, OUTPUT);
        return setup;
    }
    if (std::holds_alternative<IoValue::Setup::InputDigital>(setup)) {
        return IoValue::Error::UNSUPPORTED_SETUP;
    }
    if (std::holds_alternative<IoValue::Setup::Unused>(setup)) {
        setPinMode(chan.pin, INPUT_PULLDOWN);
        return setup;
    }
    return IoValue::Error::UNSUPPORTED_SETUP;
}

IoValue::variant Spark2PinsBlock::readChannelImpl(uint8_t channel) const
{
    if (channel > spark2Channels.size()) {
        return IoValue::Error::INVALID_CHANNEL;
    }
    if (getSparkVersion() == SparkVersion::V1 && channel == spark2Channels.size()) {
    }

    const auto setup = channelSetup(channel);
    auto& chan = spark2Channels[channel - 1];

    if (std::holds_alternative<IoValue::Setup::OutputDigital>(setup)) {
        return pinReadFast(chan.pin) != 0 ? IoValue::Digital{State::Active} : IoValue::Digital{State::Inactive};
    } else if (std::holds_alternative<IoValue::Setup::OutputPwm>(setup)) {
        return IoValue::PWM{chan.duty};
    }
    return IoValue::Error::UNSUPPORTED_VALUE;
}

int16_t Spark2PinsBlock::myInterrupt = 0;

} // end namespace platform::particle

#endif
