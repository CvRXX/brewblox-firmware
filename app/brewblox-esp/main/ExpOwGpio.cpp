#include "ExpOwGpio.hpp"
using ChanBits = ExpOwGpio::ChanBits;
using ChanBitsInternal = ExpOwGpio::ChanBitsInternal;
using PinDrive = ExpOwGpio::PinDrive;
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

PinDrive ChanBits::get(uint8_t chan)
{
    // numbering board pins doesn't match driver's bits
    switch (chan) {
    case 1:
        return PinDrive(bits.pin.c1);
    case 2:
        return PinDrive(bits.pin.c2);
    case 3:
        return PinDrive(bits.pin.c3);
    case 4:
        return PinDrive(bits.pin.c4);
    case 5:
        return PinDrive(bits.pin.c5);
    case 6:
        return PinDrive(bits.pin.c6);
    case 7:
        return PinDrive(bits.pin.c7);
    case 8:
        return PinDrive(bits.pin.c8);
    default:
        return PinDrive(0x00);
    }
}

void ChanBits::set(uint8_t chan, PinDrive drive)
{
    // numbering board pins doesn't match driver's bits
    switch (chan) {
    case 1:
        bits.pin.c1 = drive;
        return;
    case 2:
        bits.pin.c2 = drive;
        return;
    case 3:
        bits.pin.c3 = drive;
        return;
    case 4:
        bits.pin.c4 = drive;
        return;
    case 5:
        bits.pin.c5 = drive;
        return;
    case 6:
        bits.pin.c6 = drive;
        return;
    case 7:
        bits.pin.c7 = drive;
        return;
    case 8:
        bits.pin.c8 = drive;
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

void ExpOwGpio::init_expander()
{
    expander.set_outputs(0b11111101); // 24V off, OneWire powered
    expander.set_config(0b11111000);  // 3 pins output, others input
    expander.set_outputs(0b11111111); // 24V on, OneWire powered
}

void ExpOwGpio::init_driver()
{
    // set overvoltage threshold to 33V and clear all faults
    writeDrvRegister(DRV8908::RegAddr::CONFIG_CTRL, 0b00000011);
    // disable OLD detect on all pins
    writeDrvRegister(DRV8908::RegAddr::OLD_CTRL_1, 0xFF);
    // disable shutdown on OLD globally (keep bridges operating when OLD is detected)
    writeDrvRegister(DRV8908::RegAddr::OLD_CTRL_2, 0b01000000);
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
        result = pullUpStatus() & pins ? State::Active : State::Inactive;
        break;
    case blox_GpioDeviceType_SINGLE_PIN_COIL_TO_EXTERNAL_PWR: // pd, external ground
    case blox_GpioDeviceType_SINGLE_PIN_MOTOR_LOW_SIDE:       // pd, external to PWR
        result = pullDownStatus() & pins ? State::Active : State::Inactive;
        break;
    case blox_GpioDeviceType_TWO_PIN_MOTOR_BIDIRECTIONAL: // pp, pp, toggle 01 or 10
        if ((pullUpStatus() & pins) > (pullDownStatus() & pins)) {
            result = State::Reverse;
        } else if ((pullUpStatus() & pins) < (pullDownStatus() & pins)) {
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
    case ChannelConfig::UNUSED:
    case ChannelConfig::UNKNOWN:
        break;
    case ChannelConfig::DRIVING_ON:
    case ChannelConfig::DRIVING_PWM:
        drive_bits.bits.all = when_active_mask.bits.all;
        break;
    case ChannelConfig::DRIVING_OFF:
        drive_bits.bits.all = when_inactive_mask.bits.all;
        break;
    case ChannelConfig::DRIVING_REVERSE:
    case ChannelConfig::DRIVING_PWM_REVERSE:
        drive_bits.bits.all = ~when_inactive_mask.bits.all;
        break;
    case ChannelConfig::DRIVING_BRAKE_LOW_SIDE:
        drive_bits.bits.all = 0x5555;
        break;
    case ChannelConfig::DRIVING_BRAKE_HIGH_SIDE:
        drive_bits.bits.all = 0xAAAA;
        break;
    case ChannelConfig::INPUT:
    default:
        drive_bits.bits.all = 0x0000;
        break;
    }
    op_ctrl_desired.apply(flexChannels[idx].pins_mask, when_active_mask);

    return true;
}

// writes 2 consecutive registers
void ExpOwGpio::writeDrvRegister(DRV8908::RegAddr addr, uint8_t value)
{
    // CS must be toggled for every transfer!
    // don't use drv.writeRegister directly
    assert_cs();
    drv.writeRegister(addr, value);
    deassert_cs();
}

// reads 2 consecutive registers
uint8_t ExpOwGpio::readDrvRegister(DRV8908::RegAddr addr)
{
    // CS must be toggled for every transfer!
    // don't use drv.writeRegister directly
    uint8_t value = 0xFF;
    assert_cs();
    drv.readRegister(addr, value);
    deassert_cs();
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

void ExpOwGpio::update()
{
    auto drv_status = status();

    bool updateNeeded = op_ctrl_desired.bits.all != op_ctrl_status.bits.all;
    bool initNeeded = drv_status.bits.spi_error || drv_status.bits.power_on_reset;

    init_expander();     // test/ remove
    updateNeeded = true; // test/ remove

    if (updateNeeded || initNeeded) {
        if (initNeeded) {
            init_expander();
        }
        if (initNeeded) {
            init_driver();
        }

        write2DrvRegisters(DRV8908::RegAddr::OP_CTRL_1, op_ctrl_desired.bits.all);

        op_ctrl_status.bits.all = read2DrvRegisters(DRV8908::RegAddr::OP_CTRL_1);

        drv_status = status(); // use latest status returned during read of registers

        if (!(drv_status.bits.spi_error || drv_status.bits.power_on_reset)) {
            // status is valid
            if (true || drv_status.bits.openload) {
                // open load is detected
                old_status.bits.all = read2DrvRegisters(DRV8908::RegAddr::OLD_STAT_1);
            } else {
                old_status.bits.all = 0;
            }
            if (true || drv_status.bits.overcurrent) {
                // status is valid and overcurrent is detected
                ocp_status.bits.all = read2DrvRegisters(DRV8908::RegAddr::OCP_STAT_1);
            } else {
                ocp_status.bits.all = 0;
            }
        }
    }
}

blox_ChannelStatus ExpOwGpio::channelStatus(uint8_t channel) const
{
    if (!channel || channel > 8) {
        return blox_ChannelStatus_SPI_ERROR;
    }

    auto driverStatus = status();
    if (driverStatus.bits.spi_error) {
        return blox_ChannelStatus_UNKNOWN;
    }
    if (driverStatus.bits.power_on_reset) {
        return blox_ChannelStatus_POWER_ON_RESET;
    }
    if (driverStatus.bits.overtemperature_shutdown) {
        return blox_ChannelStatus_OVERTEMPERATURE_SHUTDOWN;
    }
    if (driverStatus.bits.overvoltage) {
        return blox_ChannelStatus_OVERVOLTAGE;
    }
    if (driverStatus.bits.undervoltage) {
        return blox_ChannelStatus_UNDERVOLTAGE;
    }
    // process open load and overcurrent before overtemperature, so they are not masked
    uint8_t idx = channel - 1;
    if (driverStatus.bits.openload) {
        if (flexChannels[idx].pins_mask.bits.all & old_status.bits.all) {
            return blox_ChannelStatus_OPEN_LOAD;
        }
    }
    if (driverStatus.bits.overcurrent) {
        if (flexChannels[idx].pins_mask.bits.all & ocp_status.bits.all) {
            return blox_ChannelStatus_OVERCURRENT;
        }
    }
    if (driverStatus.bits.overtemperature_warning) {
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
        uint16_t exclude_old = ~old_mask.bits.all;
        if (c.pins_mask.bits.all & exclude_old & when_active_mask.bits.all) {
            return; // refuse overlapping channels
        }
        if (c.pins_mask.bits.all & exclude_old & when_inactive_mask.bits.all) {
            return; // refuse overlapping channels
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
        if (last1 - first1 + 1 != num1) {
            // pins are not consecutive, this is not supported
            return;
        }

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

        flexChannels[idx] = c;

        switch (c.deviceType) {
        case blox_GpioDeviceType_NONE:
            // no pullups or pull downs
            break;
        case blox_GpioDeviceType_ONE_PIN_SSR: // pp, external ground
            // all push/pull
            when_inactive_external.setBits(pins_external, 0x00);
            when_active_external.setBits(0x00, pins_external);
            break;
        case blox_GpioDeviceType_TWO_PIN_SSR:
            // first GND, second push/pull
            when_inactive_external.setBits(pins_external, 0x00);
            when_active_external.setBits(first, second);
            break;
        case blox_GpioDeviceType_TWO_PIN_COIL:                 // gnd, pu
        case blox_GpioDeviceType_TWO_PIN_MOTOR_UNIDIRECTIONAL: // gnd, pu
            // first GND, second pull-up
            when_inactive_external.setBits(first, 0x00);
            when_active_external.setBits(first, second);
            break;
        case blox_GpioDeviceType_SINGLE_PIN_COIL_TO_EXTERNAL_GND: // pu, external ground
        case blox_GpioDeviceType_SINGLE_PIN_MOTOR_HIGH_SIDE:      // pu, external to ground
            // all pull-up only
            when_inactive_external.setBits(0x00, 0x00);
            when_active_external.setBits(0x00, pins_external);
            break;
        case blox_GpioDeviceType_SINGLE_PIN_COIL_TO_EXTERNAL_PWR: // pd, external to PWR
        case blox_GpioDeviceType_SINGLE_PIN_MOTOR_LOW_SIDE:       // pd, external to PWR
            // all pull-down only
            when_inactive_external.setBits(0x00, 0x00);
            when_active_external.setBits(pins_external, 0x00);
            break;
        case blox_GpioDeviceType_TWO_PIN_COIL_PUSH_PULL:      // pp,pp toggled 01 or 10
        case blox_GpioDeviceType_TWO_PIN_MOTOR_BIDIRECTIONAL: // pp, pp, toggle 01 or 10
            when_inactive_external.setBits(first, second);
            when_active_external.setBits(second, first);
            break;
        case blox_GpioDeviceType_TWO_PIN_SWITCH_INPUT:; // old, old
            when_inactive_external.setBits(0x00, 0x00);
            when_active_external.setBits(0x00, 0x00);
            break;
        case blox_GpioDeviceType_SWITCH_TO_EXTERNAL_GND:; // old, external GND
            when_inactive_external.setBits(0x00, 0x00);
            when_active_external.setBits(0x00, 0x00);
            break;
        case blox_GpioDeviceType_SWITCH_TO_PWR:; // old, external PWR
            when_inactive_external.setBits(0x00, 0x00);
            when_active_external.setBits(0x00, 0x00);
            break;
        case blox_GpioDeviceType_POWERED_SWITCH_TO_EXTERNAL_GND:; // pwr, with load detect
            when_inactive_external.setBits(0x00, pins_external);
            when_active_external.setBits(0x00, pins_external);
            break;
        case blox_GpioDeviceType_POWERED_SWITCH_TO_EXTERNAL_PWR:; // gnd, with load detect
            when_inactive_external.setBits(pins_external, 0x00);
            when_active_external.setBits(pins_external, 0x00);
            break;
        }

        // clear old bits set by previous channel configuration
        when_active_mask.bits.all = when_active_mask.bits.all & exclude_old;
        when_inactive_mask.bits.all = when_inactive_mask.bits.all & exclude_old;

        // set mask bits in shared masks
        when_inactive_mask.apply(c.pins_mask, ChanBitsInternal{when_inactive_external});
        when_active_mask.apply(c.pins_mask, ChanBitsInternal{when_active_external});
        writeChannelImpl(channel, ChannelConfig::DRIVING_OFF);
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
