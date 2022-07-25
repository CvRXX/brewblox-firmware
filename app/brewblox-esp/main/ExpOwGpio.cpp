#include "ExpOwGpio.hpp"

using ChanBits = ExpOwGpio::ChanBits;
using ChanBitsInternal = ExpOwGpio::ChanBitsInternal;
using FlexChannel = ExpOwGpio::FlexChannel;

ChanBits::ChanBits(const ChanBitsInternal& internal)
{
    bits.pin.c1 = internal.bits.pin.c1;
    bits.pin.c2 = internal.bits.pin.c2;
    bits.pin.c3 = internal.bits.pin.c3;
    bits.pin.c4 = internal.bits.pin.c4;
    bits.pin.c5 = internal.bits.pin.c5;
    bits.pin.c6 = internal.bits.pin.c6;
    bits.pin.c7 = internal.bits.pin.c7;
    bits.pin.c8 = internal.bits.pin.c8;
}

ChanBitsInternal::ChanBitsInternal(const ChanBits& external)
{
    bits.pin.c1 = external.bits.pin.c1;
    bits.pin.c2 = external.bits.pin.c2;
    bits.pin.c3 = external.bits.pin.c3;
    bits.pin.c4 = external.bits.pin.c4;
    bits.pin.c5 = external.bits.pin.c5;
    bits.pin.c6 = external.bits.pin.c6;
    bits.pin.c7 = external.bits.pin.c7;
    bits.pin.c8 = external.bits.pin.c8;
}

// get bits for pull-up transistors
uint8_t ChanBits::up() const
{
    uint16_t mask = 0x2;
    uint8_t bit = 0x1;
    uint8_t result = 0x0;
    for (uint8_t i = 0; i < 8; i++) {
        if (bits.all & mask) {
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
        if (bits.all & mask) {
            result |= bit;
        }
        bit = bit << 1;
        mask = mask << 2;
    }
    return result;
}

void ChanBits::setBits(uint8_t down, uint8_t up)
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
    bits.all = result;
}

void ExpOwGpio::init_driver()
{
    // set overvoltage threshold to 33V and clear all faults
    writeDrvRegister(DRV8908::RegAddr::CONFIG_CTRL, 0b00000011);

    // disable OLD detect on all pins
    writeDrvRegister(DRV8908::RegAddr::OLD_CTRL_1, 0xFF);

    // disable shutdown on OLD globally (keep bridges operating when OLD is detected)
    writeDrvRegister(DRV8908::RegAddr::OLD_CTRL_2, 0b01000000);

    // use 2.5 V/us slew rate for lower emissions
    writeDrvRegister(DRV8908::RegAddr::SR_CTRL_1, 0xFF);

    //  // enable PWM mode for all half bridges, 100Hz
    // writeDrvRegister(DRV8908::RegAddr::PWM_FREQ_CTRL_1, 0b01010101);
    // writeDrvRegister(DRV8908::RegAddr::PWM_FREQ_CTRL_2, 0b01010101);
    // writeDrvRegister(DRV8908::RegAddr::PWM_CTRL_1, 0xFF);
}

IoValue::variant ExpOwGpio::readChannelImpl(uint8_t channel) const
{
    if (!connected) {
        return IoValue::Error::DISCONNECTED;
    }
    if (!channel || channel > 8) {
        return IoValue::Error::INVALID_CHANNEL;
    }

    uint8_t idx = channel - 1;

    auto pins = flexChannels[idx].pins();

    if (pins == 0) {
        return IoValue::Error::CHANNEL_PINS_NOT_SET;
    }

    auto setting = desired(channel);
    if (std::holds_alternative<IoValue::PWM>(setting)) {
        return setting;
    }

    switch (flexChannels[idx].deviceType) {
    case blox_OneWireGpioModule_GpioDeviceType_GPIO_DEV_NONE:
        return IoValue::Error::CHANNEL_TYPE_NOT_SET;
    case blox_OneWireGpioModule_GpioDeviceType_GPIO_DEV_SSR_2P:                        // gnd, pp
    case blox_OneWireGpioModule_GpioDeviceType_GPIO_DEV_SSR_1P:                        // pp, external ground
    case blox_OneWireGpioModule_GpioDeviceType_GPIO_DEV_COIL_1P_HIGH_SIDE:             // pu, external ground
    case blox_OneWireGpioModule_GpioDeviceType_GPIO_DEV_COIL_2P:                       // gnd, pu
    case blox_OneWireGpioModule_GpioDeviceType_GPIO_DEV_MECHANICAL_RELAY_1P_HIGH_SIDE: // pu, external ground
    case blox_OneWireGpioModule_GpioDeviceType_GPIO_DEV_MECHANICAL_RELAY_2P:           // gnd, pu
    case blox_OneWireGpioModule_GpioDeviceType_GPIO_DEV_COIL_2P_BIDIRECTIONAL:         // pp,pp toggled 01 or 10
    case blox_OneWireGpioModule_GpioDeviceType_GPIO_DEV_MOTOR_2P:                      // gnd, pu
    case blox_OneWireGpioModule_GpioDeviceType_GPIO_DEV_MOTOR_1P_HIGH_SIDE:            // pu, external to GND
        return pullUpStatus() & pins ? IoValue::Digital{State::Active} : IoValue::Digital{State::Inactive};
    case blox_OneWireGpioModule_GpioDeviceType_GPIO_DEV_COIL_1P_LOW_SIDE:             // pd, external ground
    case blox_OneWireGpioModule_GpioDeviceType_GPIO_DEV_MECHANICAL_RELAY_1P_LOW_SIDE: // pd, external ground
    case blox_OneWireGpioModule_GpioDeviceType_GPIO_DEV_MOTOR_1P_LOW_SIDE:            // pd, external to PWR
        return pullDownStatus() & pins ? IoValue::Digital{State::Active} : IoValue::Digital{State::Inactive};
    case blox_OneWireGpioModule_GpioDeviceType_GPIO_DEV_MOTOR_2P_BIDIRECTIONAL: // pp, pp, toggle 01 or 10
        if ((pullUpStatus() & pins) < (pullDownStatus() & pins)) {
            // result = State::Reverse;
            // return Inactive for the reverse state to be compatible with digital actuator
            // until we expand processing of reversed state in rest of blocks
            return IoValue::Digital{State::Inactive};
        } else if ((pullUpStatus() & pins) > (pullDownStatus() & pins)) {
            return IoValue::Digital{State::Active};
        }
        return IoValue::Digital{State::Unknown};
    case blox_OneWireGpioModule_GpioDeviceType_GPIO_DEV_LOAD_DETECT_2P:           // old, old
        return IoValue::Error::NOT_IMPLEMENTED;                                   // todo
    case blox_OneWireGpioModule_GpioDeviceType_GPIO_DEV_GND_1P_LOAD_DETECT:       // old, external GND
    case blox_OneWireGpioModule_GpioDeviceType_GPIO_DEV_LOAD_DETECT_1P_PULL_DOWN: // old only
        return IoValue::Error::NOT_IMPLEMENTED;                                   // todo
    case blox_OneWireGpioModule_GpioDeviceType_GPIO_DEV_POWER_1P_LOAD_DETECT:     // old, external PWR
    case blox_OneWireGpioModule_GpioDeviceType_GPIO_DEV_LOAD_DETECT_1P_PULL_UP:   // old only
        return IoValue::Error::NOT_IMPLEMENTED;                                   // todo
    case blox_OneWireGpioModule_GpioDeviceType_GPIO_DEV_POWER_1P:                 // pwr, no load detect
        return IoValue::Error::NOT_IMPLEMENTED;                                   // todo
    case blox_OneWireGpioModule_GpioDeviceType_GPIO_DEV_GND_1P:                   // gnd, no load detect
        return IoValue::Error::NOT_IMPLEMENTED;                                   // todo
    }
    return IoValue::Error::CHANNEL_TYPE_NOT_SET;
}

IoValue::variant ExpOwGpio::writeChannelImpl(uint8_t channel, IoValue::variant val)
{
    if (!connected) {
        return IoValue::Error::DISCONNECTED;
    }
    if (!channel || channel > 8) {
        return IoValue::Error::INVALID_CHANNEL;
    }

    auto& chan = flexChannels[channel - 1];

    ChanBitsInternal drive_bits;

    if (auto* v = std::get_if<IoValue::Digital>(&val)) {
        if (v->state() == IoValue::State::Active) {
            writeDrvRegister(DRV8908::RegAddr::SR_CTRL_2, 0x0F);
            drive_bits.bits.all = when_active_mask.bits.all;
        } else if (v->state() == IoValue::State::Inactive) {
            drive_bits.bits.all = when_inactive_mask.bits.all;
        } else if (v->state() == IoValue::State::Reverse) {
            drive_bits.bits.all = ~when_active_mask.bits.all;
        } else {
            return IoValue::Error::UNSUPPORTED_VALUE;
        }
    } else if (auto* v = std::get_if<IoValue::PWM>(&val)) {
        if (v->duty() >= 0) {
            drive_bits.bits.all = when_active_mask.bits.all;
        } else {
            drive_bits.bits.all = ~when_active_mask.bits.all;
        }
    }

    op_ctrl_desired.apply(chan.pins_mask, drive_bits);
    update();

    return val;
}

IoValue::Setup::variant ExpOwGpio::setupChannelImpl(uint8_t channel, IoValue::Setup::variant setup)
{
    if (!channel || channel > 8) {
        return IoValue::Error::INVALID_CHANNEL;
    }

    auto& chan = flexChannels[channel - 1];

    if (std::holds_alternative<IoValue::Setup::OutputDigital>(setup)) {
        writeChannelImpl(channel, IoValue::Digital{State::Inactive});
        return IoValue::Setup::OutputDigital{
            .softTransitions = IoValue::Setup::SoftTransitions::OFF};
    }
    if (auto* v = std::get_if<IoValue::Setup::OutputPwm>(&setup)) {
        writeChannelImpl(channel, IoValue::PWM{0});
        // TODO configure driver
        // chan.freq = setup->frequency;
        // chan.soft = setup->soft;
        return IoValue::Setup::OutputPwm{
            .softTransitions = IoValue::Setup::SoftTransitions::OFF};
    }
    if (std::holds_alternative<IoValue::Setup::InputDigital>(setup)) {
        ChanBitsInternal bits{};
        op_ctrl_desired.apply(chan.pins_mask, bits);
        return IoValue::Setup::InputDigital{};
    }
    return IoValue::Error::UNSUPPORTED_SETUP;
}

// writes 2 consecutive registers
void ExpOwGpio::writeDrvRegister(DRV8908::RegAddr addr, uint8_t value)
{
    // CS must be toggled for every transfer!
    // don't use drv.writeRegister directly
    if (assert_cs()) {
        drv.writeRegister(addr, value);
        deassert_cs();
    }
}

// reads 2 consecutive registers
uint8_t ExpOwGpio::readDrvRegister(DRV8908::RegAddr addr)
{
    // CS must be toggled for every transfer!
    // don't use drv.writeRegister directly
    uint8_t value = 0xFF;
    if (assert_cs()) {
        drv.readRegister(addr, value);
        deassert_cs();
    }
    return value;
}

// writes 2 consecutive registers
void ExpOwGpio::write2DrvRegisters(DRV8908::RegAddr addr, uint16_t value)
{
    uint8_t lower = value & 0xFF;
    uint8_t upper = (value >> 8) & 0xFF;

    writeDrvRegister(addr, lower);
    writeDrvRegister(DRV8908::RegAddr(uint8_t(addr) + 1), upper);
}

// reads 2 consecutive registers
uint16_t ExpOwGpio::read2DrvRegisters(DRV8908::RegAddr addr)
{
    uint8_t lower = readDrvRegister(addr);
    uint8_t upper = readDrvRegister(DRV8908::RegAddr(uint8_t(addr) + 1));
    return (uint16_t(upper) << 8) + lower;
}

void ExpOwGpio::init()
{
    // try to reconnect
    connected = hal_i2c_detect(expander.address()) == 0;
    if (connected) {
        init_driver(); // init io driver
        ow.init();     // init OneWire bus
    }
}

void ExpOwGpio::update(bool forceRefresh)
{
    if (!connected) {
        init();
    }
    if (!connected) {
        return;
    }

    auto drv_status = status();

    bool ctrlChanged = op_ctrl_desired.bits.all != op_ctrl_status.bits.all;
    bool initNeeded = drv_status.bits.spi_error || drv_status.bits.power_on_reset;

    if (forceRefresh || ctrlChanged || initNeeded) {
        if (initNeeded) {
            init_driver();
        }

        // for (uint8_t i = 0; i < flexChannels.size(); ++i) {
        //     auto desired = desired(i + 1);
        // }

        // from the datasheet:
        // The PWM generators are disabled to ensure that all the half-bridges are turned-on at same time to avoid
        // false OCP conditions for supporting higher current operation.The false OCP condition can arise due to
        // the minimum time required for the SPI delay to switch on various half-bridges available in different registers.
        // This can cause higher current (OCP condition) in one of the paralleled half-bridge while other half-bridge turning ON
        // is delayed to the SPI register write delay and the propagation delay. Therefore, this sequence includes disabling
        // the PWM generators initially,then enabling half-bridges and followed by enabling the PWM generators to avoid such issue.

        uint8_t changedPins = 0;
        uint8_t pwmChannels = 0;
        for (uint8_t i = 0; i < flexChannels.size(); ++i) {
            uint8_t bit = uint8_t(uint8_t{0x1} << i);
            auto& chan = flexChannels[i];
            if (chan.freq != IoValue::Setup::Frequency::FREQ_NONE) {
                pwmChannels |= bit;
                if (chan.pins_mask.bits.all ^ op_ctrl_desired.bits.all) {
                    changedPins |= bit;
                }
            }
        }
        if (changedPins) {
            writeDrvRegister(DRV8908::RegAddr::PWM_CTRL_2, (~pwmChannels) | changedPins);
        }
        write2DrvRegisters(DRV8908::RegAddr::OP_CTRL_1, op_ctrl_desired.bits.all);
        if (changedPins) {
            writeDrvRegister(DRV8908::RegAddr::PWM_CTRL_2, ~pwmChannels);
        }
        op_ctrl_status.bits.all = read2DrvRegisters(DRV8908::RegAddr::OP_CTRL_1);
        drv_status = status(); // use latest status returned during read of registers

        if (!(drv_status.bits.spi_error || drv_status.bits.power_on_reset)) {
            // status is valid
            if (drv_status.bits.openload) {
                // open load is detected
                old_status.bits.all = read2DrvRegisters(DRV8908::RegAddr::OLD_STAT_1);
            } else {
                old_status.bits.all = 0;
            }
            if (drv_status.bits.overcurrent) {
                // status is valid and overcurrent is detected
                ocp_status.bits.all = read2DrvRegisters(DRV8908::RegAddr::OCP_STAT_1);
            } else {
                ocp_status.bits.all = 0;
            }
        }
    }

    if (owDriver.shortDetected()) {
        expander.set_output(ExpanderPins::oneWirePowerEnable, false);
        hal_delay_ms(200);
        expander.set_output(ExpanderPins::oneWirePowerEnable, true);
        ow.init();
    }
}

void ExpOwGpio::setupChannel(uint8_t channel, FlexChannel c)
{
    if (!channel || channel > 8) {
        return;
    }
    uint8_t idx = channel - 1;

    bool configChanged = c != flexChannels[idx];
    if (configChanged) {
        auto old_mask = flexChannels[idx].pins_mask;
        uint16_t exclude_old = ~old_mask.bits.all;
        if (c.pins_mask.bits.all & exclude_old & when_active_mask.bits.all) {
            // refuse overlapping channels
            c.pins_mask.bits.all = 0;
        }
        if (c.pins_mask.bits.all & exclude_old & when_inactive_mask.bits.all) {
            // refuse overlapping channels
            c.pins_mask.bits.all = 0;
        }

        uint8_t pins_external = c.pins();

        int8_t first1 = -1;
        int8_t last1 = -1;
        uint8_t num1 = 0;
        for (uint8_t i = 0; i < 8; i++) {
            if (pins_external & (uint8_t{1} << i)) {
                if (first1 < 0) {
                    first1 = i;
                }
                last1 = i;
                ++num1;
            }
        }
        if (c.width != num1) {
            // refuse channels with mismatch between width en number of ones
            c.pins_mask.bits.all = 0;
        }

        if (last1 - first1 + 1 != num1) {
            // pins are not consecutive, this is not supported
            c.pins_mask.bits.all = 0;
        }

        // clear old bits set by previous channel configuration
        when_active_mask.bits.all = when_active_mask.bits.all & exclude_old;
        when_inactive_mask.bits.all = when_inactive_mask.bits.all & exclude_old;
        op_ctrl_desired.bits.all = op_ctrl_desired.bits.all & exclude_old;

        flexChannels[idx] = c;

        if (c.pins_mask.bits.all) {
            // for device with 2/4/6/8 pins (multiple pins per terminal to higher current)
            // we need to figure out where to split them if needed
            uint8_t middle = (last1 + first1) / 2;
            uint8_t first = 0;
            uint8_t second = 0;
            for (uint8_t i = 0; i < 8; i++) {
                uint8_t pin = (pins_external & (uint8_t{1} << i));
                if (i <= middle) {
                    first |= pin;
                } else {
                    second |= pin;
                }
            }

            ChanBits when_active_external{when_active_mask};
            ChanBits when_inactive_external{when_inactive_mask};

            switch (c.deviceType) {
            case blox_OneWireGpioModule_GpioDeviceType_GPIO_DEV_NONE:
                // no pullups or pull downs
                break;
            case blox_OneWireGpioModule_GpioDeviceType_GPIO_DEV_SSR_1P: // pp, external ground
                // all push/pull
                when_inactive_external.setBits(pins_external, 0x00);
                when_active_external.setBits(0x00, pins_external);
                break;
            case blox_OneWireGpioModule_GpioDeviceType_GPIO_DEV_SSR_2P:
                // first GND, second push/pull
                when_inactive_external.setBits(pins_external, 0x00);
                when_active_external.setBits(first, second);
                break;
            case blox_OneWireGpioModule_GpioDeviceType_GPIO_DEV_COIL_2P:             // gnd, pu
            case blox_OneWireGpioModule_GpioDeviceType_GPIO_DEV_MECHANICAL_RELAY_2P: // gnd, pu
            case blox_OneWireGpioModule_GpioDeviceType_GPIO_DEV_MOTOR_2P:            // gnd, pu
                // first GND, second pull-up
                when_inactive_external.setBits(first, 0x00);
                when_active_external.setBits(first, second);
                break;
            case blox_OneWireGpioModule_GpioDeviceType_GPIO_DEV_COIL_1P_HIGH_SIDE:             // pu, external ground
            case blox_OneWireGpioModule_GpioDeviceType_GPIO_DEV_MECHANICAL_RELAY_1P_HIGH_SIDE: // pu, external ground
            case blox_OneWireGpioModule_GpioDeviceType_GPIO_DEV_MOTOR_1P_HIGH_SIDE:            // pu, external to ground
                // all pull-up only
                when_inactive_external.setBits(0x00, 0x00);
                when_active_external.setBits(0x00, pins_external);
                break;
            case blox_OneWireGpioModule_GpioDeviceType_GPIO_DEV_COIL_1P_LOW_SIDE:             // pd, external to PWR
            case blox_OneWireGpioModule_GpioDeviceType_GPIO_DEV_MECHANICAL_RELAY_1P_LOW_SIDE: // pd, external to PWR
            case blox_OneWireGpioModule_GpioDeviceType_GPIO_DEV_MOTOR_1P_LOW_SIDE:            // pd, external to PWR
                // all pull-down only
                when_inactive_external.setBits(0x00, 0x00);
                when_active_external.setBits(pins_external, 0x00);
                break;
            case blox_OneWireGpioModule_GpioDeviceType_GPIO_DEV_COIL_2P_BIDIRECTIONAL:  // pp,pp toggled 01 or 10
            case blox_OneWireGpioModule_GpioDeviceType_GPIO_DEV_MOTOR_2P_BIDIRECTIONAL: // pp, pp, toggle 01 or 10
                when_inactive_external.setBits(second, first);
                when_active_external.setBits(first, second);
                break;
            case blox_OneWireGpioModule_GpioDeviceType_GPIO_DEV_LOAD_DETECT_2P:; // old, old
                when_inactive_external.setBits(0x00, 0x00);
                when_active_external.setBits(0x00, 0x00);
                break;
            case blox_OneWireGpioModule_GpioDeviceType_GPIO_DEV_LOAD_DETECT_1P_PULL_DOWN:; // old, external GND
                when_inactive_external.setBits(0x00, 0x00);
                when_active_external.setBits(0x00, 0x00);
                break;
            case blox_OneWireGpioModule_GpioDeviceType_GPIO_DEV_LOAD_DETECT_1P_PULL_UP:; // old, external PWR
                when_inactive_external.setBits(0x00, 0x00);
                when_active_external.setBits(0x00, 0x00);
                break;
            case blox_OneWireGpioModule_GpioDeviceType_GPIO_DEV_POWER_1P_LOAD_DETECT:; // pwr, with load detect
            case blox_OneWireGpioModule_GpioDeviceType_GPIO_DEV_POWER_1P:;             // pwr, without load detect
                when_inactive_external.setBits(0x00, pins_external);
                when_active_external.setBits(0x00, pins_external);
                break;
            case blox_OneWireGpioModule_GpioDeviceType_GPIO_DEV_GND_1P_LOAD_DETECT:; // gnd, with load detect
            case blox_OneWireGpioModule_GpioDeviceType_GPIO_DEV_GND_1P:
                when_inactive_external.setBits(pins_external, 0x00);
                when_active_external.setBits(pins_external, 0x00);
                break;
            }

            // set mask bits in shared masks
            when_inactive_mask.apply(c.pins_mask, ChanBitsInternal{when_inactive_external});
            when_active_mask.apply(c.pins_mask, ChanBitsInternal{when_active_external});
            writeChannelImpl(channel, IoValue::Digital{State::Inactive});
        }
    }
}

const FlexChannel& ExpOwGpio::getChannel(uint8_t channel) const
{
    static FlexChannel invalid{};
    if (!channel || channel > 8) {
        return invalid;
    }
    return flexChannels[channel - 1];
}
