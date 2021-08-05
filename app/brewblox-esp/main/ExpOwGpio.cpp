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

void FlexChannel::apply(ChannelConfig& config, ChanBitsInternal& op_ctrl)
{
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
    op_ctrl.apply(pins_mask, drive_bits);
}

bool ExpOwGpio::senseChannelImpl(uint8_t channel, State& result) const
{
    return false;
}
bool ExpOwGpio::writeChannelImpl(uint8_t channel, IoArray::ChannelConfig config)
{
    if (!channel || channel > 8) {
        return false;
    }
    uint8_t idx = channel - 1;

    flexChannels[idx].apply(config, op_ctrl);
    ESP_ERROR_CHECK_WITHOUT_ABORT(drv.writeRegister(DRV8908::RegAddr::OP_CTRL_1, op_ctrl.byte1));
    ESP_ERROR_CHECK_WITHOUT_ABORT(drv.writeRegister(DRV8908::RegAddr::OP_CTRL_2, op_ctrl.byte2));
    return true;
}

ChanBits ExpOwGpio::openload() const
{
    auto status = drv.status();
    ChanBitsInternal old;
    if (!(status & 0x80) && (status & 0x10)) {
        // status is valid and open load is detected
        uint8_t old1 = 0;
        uint8_t old2 = 0;
        ESP_ERROR_CHECK_WITHOUT_ABORT(drv.readRegister(DRV8908::RegAddr::OLD_STAT_1, old1));
        ESP_ERROR_CHECK_WITHOUT_ABORT(drv.readRegister(DRV8908::RegAddr::OLD_STAT_2, old2));
        old.byte1 = old1;
        old.byte2 = old2;
    }

    return ChanBits{old};
}

ChanBits ExpOwGpio::overcurrent() const
{
    auto status = drv.status();
    ChanBitsInternal ocp;
    if (!(status & 0x80) && (status & 0x10)) {
        // status is valid and overcurrent is detected
        uint8_t ocp1 = 0;
        uint8_t ocp2 = 0;
        ESP_ERROR_CHECK_WITHOUT_ABORT(drv.readRegister(DRV8908::RegAddr::OCP_STAT_1, ocp1));
        ESP_ERROR_CHECK_WITHOUT_ABORT(drv.readRegister(DRV8908::RegAddr::OCP_STAT_2, ocp2));
        ocp.byte1 = ocp1;
        ocp.byte2 = ocp2;
    }

    return ChanBits{ocp};
}