#include "ExpOwGpio.hpp"
#include "esp_log.h"

using ChanBits = ExpOwGpio::ChanBits;
using ChanBitsInternal = ExpOwGpio::ChanBitsInternal;
using PinDrive = ExpOwGpio::PinDrive;
using FlexChannel = ExpOwGpio::FlexChannel;

ChanBits::ChanBits(const ChanBitsInternal& internal)
{
    this->c1 = internal.c1;
    this->c2 = internal.c2;
    this->c3 = internal.c3;
    this->c4 = internal.c4;
    this->c5 = internal.c5;
    this->c6 = internal.c6;
    this->c7 = internal.c7;
    this->c8 = internal.c8;
}

ChanBitsInternal::ChanBitsInternal(const ChanBits& external)
{
    this->c1 = external.c1;
    this->c2 = external.c2;
    this->c3 = external.c3;
    this->c4 = external.c4;
    this->c5 = external.c5;
    this->c6 = external.c6;
    this->c7 = external.c7;
    this->c8 = external.c8;
}

PinDrive ChanBits::get(uint8_t chan)
{
    // numbering board pins doesn't match driver's bits
    switch (chan) {
    case 1:
        return PinDrive(c1);
    case 2:
        return PinDrive(c2);
    case 3:
        return PinDrive(c3);
    case 4:
        return PinDrive(c4);
    case 5:
        return PinDrive(c5);
    case 6:
        return PinDrive(c6);
    case 7:
        return PinDrive(c7);
    case 8:
        return PinDrive(c8);
    default:
        return PinDrive(0x00);
    }
}

void ChanBits::set(uint8_t chan, PinDrive drive)
{
    // numbering board pins doesn't match driver's bits
    switch (chan) {
    case 1:
        c1 = drive;
        return;
    case 2:
        c2 = drive;
        return;
    case 3:
        c3 = drive;
        return;
    case 4:
        c4 = drive;
        return;
    case 5:
        c5 = drive;
        return;
    case 6:
        c6 = drive;
        return;
    case 7:
        c7 = drive;
        return;
    case 8:
        c8 = drive;
        return;
    default:
        return;
    }
}

// get bits for pull-up transistors
uint8_t ChanBits::up() const
{
    uint16_t mask = 0x2;
    uint8_t bit = 0x1;
    uint8_t result = 0x0;
    for (uint8_t i = 0; i < 8; i++) {
        if (this->all & mask) {
            result |= bit;
        }
        bit = bit << 1;
        mask = mask << 2;
    }
    return result;
}

// get bits for pull-down transistors
uint8_t ChanBits::down() const
{
    uint16_t mask = 0x1;
    uint8_t bit = 0x1;
    uint8_t result = 0x0;
    for (uint8_t i = 0; i < 8; i++) {
        if (this->all & mask) {
            result |= bit;
        }
        bit = bit << 1;
        mask = mask << 2;
    }
    return result;
}

void ChanBits::setBits(uint8_t up, uint8_t down)
{
    uint16_t bitDown = 0x1;
    uint16_t bitUp = 0x2;
    uint8_t bit = 0x1;
    uint16_t result = 0;
    for (uint8_t i = 0; i < 8; i++) {
        if (down & bit) {
            result |= bitDown;
        }
        if (up & bit) {
            result |= bitUp;
        }
        bit = bit << 1;
        bitDown = bitDown << 2;
        bitUp = bitUp << 2;
    }
    this->all = result;
}

bool ExpOwGpio::senseChannelImpl(uint8_t channel, State& result) const
{
    if (!channel || channel > 8) {
        return false;
    }
    uint8_t idx = channel - 1;

    auto pins = flexChannels[idx].pins();

    if (flexChannels[idx].pwm_duty) {
        // for a non-zero pwm value, return Active regardless of pin state
        result = State::Active;
        return true;
    }

    switch (flexChannels[idx].deviceType) {
    case blox_GpioDeviceType_NONE:
        result = State::Unknown;
        break;
    case blox_GpioDeviceType_TWO_PIN_SSR:                     // gnd, pp
    case blox_GpioDeviceType_ONE_PIN_SSR:                     // pp, external ground
    case blox_GpioDeviceType_SINGLE_PIN_COIL_TO_EXTERNAL_GND: // pu, external ground
    case blox_GpioDeviceType_TWO_PIN_COIL:                    // gnd, pu
    case blox_GpioDeviceType_TWO_PIN_COIL_PUSH_PULL:          // pp,pp toggled 01 or 10
    case blox_GpioDeviceType_TWO_PIN_MOTOR_UNIDIRECTIONAL:    // gnd, pu
    case blox_GpioDeviceType_SINGLE_PIN_MOTOR_HIGH_SIDE:      // pu, external to GND
        result = pullUp() & pins ? State::Active : State::Inactive;
        break;
    case blox_GpioDeviceType_SINGLE_PIN_COIL_TO_EXTERNAL_PWR: // pd, external ground
    case blox_GpioDeviceType_SINGLE_PIN_MOTOR_LOW_SIDE:       // pd, external to PWR
        result = pullDown() & pins ? State::Active : State::Inactive;
        break;
    case blox_GpioDeviceType_TWO_PIN_MOTOR_BIDIRECTIONAL: // pp, pp, toggle 01 or 10
        if ((pullUp() & pins) > (pullDown() & pins)) {
            result = State::Reverse;
        } else if ((pullUp() & pins) < (pullDown() & pins)) {
            result = State::Active;
        } else {
            result = State::Inactive;
        }
        break;
    case blox_GpioDeviceType_TWO_PIN_SWITCH_INPUT:; // old, old
        result = State::Unknown;                    // todo
        break;
    case blox_GpioDeviceType_SWITCH_TO_EXTERNAL_GND:; // old, external GND
        result = State::Unknown;                      // todo
        break;
    case blox_GpioDeviceType_SWITCH_TO_PWR:; // old, external PWR
        result = State::Unknown;             // todo
        break;
    case blox_GpioDeviceType_POWERED_SWITCH_TO_EXTERNAL_GND:; // pwr, with load detect
        result = State::Unknown;                              // todo
        break;
    case blox_GpioDeviceType_POWERED_SWITCH_TO_EXTERNAL_PWR:; // gnd, with load detect
        result = State::Unknown;                              // todo
        break;
    }
    return true;
}

blox_DigitalState ExpOwGpio::channelState(uint8_t channel) const
{
    State s{State::Unknown};
    senseChannelImpl(channel, s);
    return blox_DigitalState(s);
}

bool ExpOwGpio::writeChannelImpl(uint8_t channel, IoArray::ChannelConfig config)
{
    if (!channel || channel > 8) {
        return false;
    }
    uint8_t idx = channel - 1;

    ChanBitsInternal drive_bits;
    switch (config) {
    case ChannelConfig::DRIVING_ON:
        drive_bits.all = when_active_mask.all;
        break;
    case ChannelConfig::DRIVING_OFF:
        drive_bits.all = when_inactive_mask.all;
        break;
    case ChannelConfig::DRIVING_REVERSE:
        drive_bits.all = ~when_inactive_mask.all;
        break;
    case ChannelConfig::DRIVING_BRAKE_LOW_SIDE:
        drive_bits.all = 0x5555;
        break;
    case ChannelConfig::DRIVING_BRAKE_HIGH_SIDE:
        drive_bits.all = 0xAAAA;
        break;
    case ChannelConfig::INPUT:
    default:
        drive_bits.all = 0x0000;
        break;
    }
    op_ctrl.apply(flexChannels[idx].pins_mask, when_active_mask);

    assert_cs();
    ESP_ERROR_CHECK_WITHOUT_ABORT(drv.writeRegister(DRV8908::RegAddr::OP_CTRL_1, op_ctrl.byte1));
    ESP_ERROR_CHECK_WITHOUT_ABORT(drv.writeRegister(DRV8908::RegAddr::OP_CTRL_2, op_ctrl.byte2));
    deassert_cs();
    return true;
}

void ExpOwGpio::update()
{
    auto drv_status = status();
    if (drv_status.reserved) {
        init();
        drv_status = status();
    }

    if (!(drv_status.reserved)) {
        // status is valid
        if (drv_status.openload) {
            // open load is detected
            uint8_t old1 = 0;
            uint8_t old2 = 0;
            assert_cs();
            ESP_ERROR_CHECK_WITHOUT_ABORT(drv.readRegister(DRV8908::RegAddr::OLD_STAT_1, old1));
            ESP_ERROR_CHECK_WITHOUT_ABORT(drv.readRegister(DRV8908::RegAddr::OLD_STAT_2, old2));
            deassert_cs();
            old_status.byte1 = old1;
            old_status.byte2 = old2;
        } else {
            old_status.all = 0;
        }
        if (drv_status.overcurrent) {
            // status is valid and overcurrent is detected
            uint8_t ocp1 = 0;
            uint8_t ocp2 = 0;
            ESP_ERROR_CHECK_WITHOUT_ABORT(drv.readRegister(DRV8908::RegAddr::OCP_STAT_1, ocp1));
            ESP_ERROR_CHECK_WITHOUT_ABORT(drv.readRegister(DRV8908::RegAddr::OCP_STAT_2, ocp2));
            ocp_status.byte1 = ocp1;
            ocp_status.byte2 = ocp2;
        } else {
            ocp_status.all = 0;
        }
    }
}

blox_ChannelStatus ExpOwGpio::channelStatus(uint8_t channel) const
{
    if (!channel || channel > 8) {
        return blox_ChannelStatus_UNKNOWN;
    }

    auto driverStatus = status();
    if (driverStatus.reserved) {
        return blox_ChannelStatus_UNKNOWN;
    }
    if (driverStatus.power_on_reset) {
        return blox_ChannelStatus_POWER_ON_RESET;
    }
    if (driverStatus.overtemperature_shutdown) {
        return blox_ChannelStatus_OVERTEMPERATURE_SHUTDOWN;
    }
    if (driverStatus.overvoltage) {
        return blox_ChannelStatus_OVERVOLTAGE;
    }
    if (driverStatus.undervoltage) {
        return blox_ChannelStatus_UNDERVOLTAGE;
    }
    // process open load and overcurrent before overtemperature, so they are not masked
    uint8_t idx = channel - 1;
    if (driverStatus.openload) {
        if (flexChannels[idx].pins_mask.all & old_status.all) {
            return blox_ChannelStatus_OPEN_LOAD;
        }
    }
    if (driverStatus.overcurrent) {
        if (flexChannels[idx].pins_mask.all & ocp_status.all) {
            return blox_ChannelStatus_OVERCURRENT;
        }
    }
    if (driverStatus.overtemperature_warning) {
        return blox_ChannelStatus_OVERTEMPERATURE_WARNING;
    }
    return blox_ChannelStatus_OPERATIONAL;
}

void ExpOwGpio::setupChannel(uint8_t channel, const FlexChannel& c)
{
    if (!channel || channel > 8) {
        return;
    }
    uint8_t idx = channel - 1;

    bool configChanged = c != flexChannels[idx];
    if (configChanged) {
        auto old_mask = flexChannels[idx].pins_mask;
        uint16_t exclude_old = ~old_mask.all;
        if (c.pins_mask.all & exclude_old & when_active_mask.all) {
            return; // refuse overlapping channels
        }
        if (c.pins_mask.all & exclude_old & when_inactive_mask.all) {
            return; // refuse overlapping channels
        }

        // zero positions for pins mask
        when_active_mask.all = when_active_mask.all & exclude_old;
        when_inactive_mask.all = when_inactive_mask.all & exclude_old;

        // count the number of pins to be driven
        uint8_t numberOfOnes = 0;
        uint8_t zerosBeforeOne = 0;
        uint8_t bit = 0x1;
        for (uint8_t i = 0; i < 16; i++) {
            if (bit & c.pins()) {
                ++numberOfOnes;
            } else {
                if (!numberOfOnes) {
                    ++zerosBeforeOne;
                }
            }
            bit = bit << 1;
        }

        switch (flexChannels[idx].deviceType) {
            // todo
        }
    }
}