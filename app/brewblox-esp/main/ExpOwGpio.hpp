#pragma once

#include "control/DS248x.hpp"
#include "control/IoArray.hpp"
#include "control/IoModule.hpp"
#include "control/OneWire.hpp"
#include "drivers/DRV8908.hpp"
#include "drivers/TCA9538.hpp"
#include "proto/OneWireGpioModule.pb.h"
// #include "esp_err.h"
// #include "esp_log.h"
#include "blox_hal/hal_delay.hpp"
#include <vector>

class ExpOwGpio : public IoArray, public IoModule {
public:
    ExpOwGpio(uint8_t lower_address)
        : IoArray(8)
        , spi(get_spi())
        , expander(lower_address)
        , drv(spi)
        , owDriver(lower_address)
        , ow(owDriver)
        , flexChannels{}
    {
    }
    virtual ~ExpOwGpio()
    {
    }

    ExpOwGpio(const ExpOwGpio&) = delete;
    ExpOwGpio& operator=(const ExpOwGpio&) = delete;

    static bool detect_presence(uint8_t lower_address)
    {
        return hal_i2c_detect(TCA9538::base_address() + lower_address) == 0
               && hal_i2c_detect(DS248x::base_address() + lower_address) == 0;
    }

    void init();
    void init_expander();
    void init_driver();

    virtual bool supportsFastIo()
    {
        return false;
    }

public:
    struct ChanBitsInternal;
    struct ChanBits {
        ChanBits()
        {
            bits.all = 0;
        }

        ChanBits(const ChanBitsInternal& internal);

        typedef union {
            struct {
                uint8_t c1 : 2;
                uint8_t c2 : 2;
                uint8_t c3 : 2;
                uint8_t c4 : 2;
                uint8_t c5 : 2;
                uint8_t c6 : 2;
                uint8_t c7 : 2;
                uint8_t c8 : 2;
            } pin;

            uint16_t all;
        } Bits;

        Bits bits;

        // get bits for pull-down transistors
        uint8_t down() const;

        // get bits for pull-up transistors
        uint8_t up() const;

        // sets all up and down bits by interweaving them into a 16-bit value
        void setBits(uint8_t up, uint8_t down);
    };

    struct ChanBitsInternal {
        ChanBitsInternal()
        {
            bits.all = 0;
        }

        ChanBitsInternal(const ChanBits& external);

        typedef union {
            struct {
                uint8_t c1 : 2;
                uint8_t c4 : 2;
                uint8_t c8 : 2;
                uint8_t c7 : 2;
                uint8_t c2 : 2;
                uint8_t c6 : 2;
                uint8_t c3 : 2;
                uint8_t c5 : 2;
            } pin;
            struct {
                uint8_t byte1 : 8;
                uint8_t byte2 : 8;
            } byte;
            uint16_t all;
        } Bits;

        Bits bits;

        void apply(const ChanBitsInternal& mask, const ChanBitsInternal& state)
        {
            bits.all &= ~mask.bits.all;
            bits.all |= (mask.bits.all & state.bits.all);
        }
    };

    class FlexChannel {
    public:
        FlexChannel()
            : deviceType(blox_OneWireGpioModule_GpioDeviceType_GPIO_DEV_NONE)
            , width(0)
        {
            pins_mask.bits.all = 0;
        }

        FlexChannel(
            blox_OneWireGpioModule_GpioDeviceType type,
            uint8_t width,
            uint8_t pins)
            : deviceType(type)
            , width(width)
        {
            // set mask for both pull-up and pull-down
            ChanBits external_pins_mask;
            external_pins_mask.setBits(pins, pins);
            pins_mask = ChanBitsInternal{external_pins_mask};
        }

        bool operator==(const FlexChannel& other) const
        {
            return this->pins_mask.bits.all == other.pins_mask.bits.all
                   && this->deviceType == other.deviceType
                   && this->width == other.width;
        }

        bool operator!=(const FlexChannel& other) const
        {
            return this->pins_mask.bits.all != other.pins_mask.bits.all
                   || this->deviceType != other.deviceType
                   || this->width == other.width;
        }

        blox_OneWireGpioModule_GpioDeviceType deviceType = blox_OneWireGpioModule_GpioDeviceType_GPIO_DEV_NONE;
        ChannelConfig config = ChannelConfig::UNUSED;
        uint8_t width;
        uint8_t pwm_duty = 0;

        uint8_t pins() const
        {
            // convert to external order
            ChanBits converted = pins_mask;
            // return only 1 bit per pin
            return converted.up();
        }
        void apply(ChannelConfig& config, ChanBitsInternal& op_ctrl);

    private:
        ChanBitsInternal pins_mask; // pins controlled by this channel
        friend class ExpOwGpio;
    };

    bool senseChannelImpl(uint8_t channel, State& result) const final;
    bool writeChannelImpl(uint8_t channel, ChannelConfig config) final;
    bool supportsFastIo() const final
    {
        return false;
    }

    void setupChannel(uint8_t channel, FlexChannel c);
    const FlexChannel& getChannel(uint8_t channel) const;

    void update(bool forceRefresh = false);

    DRV8908::Status status() const
    {
        return drv.status();
    }

    uint8_t pullUpDesired() const
    {
        return ChanBits{op_ctrl_desired}.up();
    }
    uint8_t pullUpStatus() const
    {
        return ChanBits{op_ctrl_status}.up();
    }
    uint8_t pullUpWhenActive() const
    {
        return ChanBits{when_active_mask}.up();
    }
    uint8_t pullUpWhenInactive() const
    {
        return ChanBits{when_inactive_mask}.up();
    }
    uint8_t pullDownDesired() const
    {
        return ChanBits{op_ctrl_desired}.down();
    }
    uint8_t pullDownStatus() const
    {
        return ChanBits{op_ctrl_status}.down();
    }
    uint8_t pullDownWhenActive() const
    {
        return ChanBits{when_active_mask}.down();
    }
    uint8_t pullDownWhenInactive() const
    {
        return ChanBits{when_inactive_mask}.down();
    }
    uint8_t overCurrent() const
    {
        auto external = ChanBits{ocp_status};
        return external.up() | external.down();
    }

    uint8_t openLoad() const
    {
        auto external = ChanBits{old_status};
        return external.up() | external.down();
    }

    uint8_t modulePosition() const final
    {
        auto addr = expander.address();
        if (addr == 0xFF) {
            return 0;
        }
        return (addr & uint8_t{3}) + 1;
    }

    void modulePosition(uint8_t pos) final
    {
        if (pos && pos <= 4) {
            expander.set_address_bits(pos - 1);
            owDriver.set_address_bits(pos - 1);
        }
    }

    OneWire* oneWireBus()
    {
        if (connected) {
            return &ow;
        }
        return nullptr;
    }

    void externalPowerEnabled(bool isEnabled)
    {
        externalPower = isEnabled;
    }

    bool externalPowerEnabled() const
    {
        return externalPower;
    }

private:
    bool assert_cs()
    {
        if (connected) {
            // if not connected, wait until device is re-discovered in update to reduce communication
            spi.aquire_bus();
            // always set both configuration registers of the expander
            // in case the IC has reset, this will ensure a correct state.
            // pin 4, 2, 1, 0 output, others input
            connected = expander.set_outputs(externalPower ? 0xFE : 0xFC) && expander.set_config(0b11101000);
            return true;
        }
        return false;
    }

    void deassert_cs()
    {
        if (connected) {
            // if device couldn't be found, there is no point in trying to communicate with the expander
            expander.set_outputs(externalPower ? 0xFF : 0xFD);
        }
        // the spi bus lock still has to be freed
        spi.release_bus();
    }

    void writeDrvRegister(DRV8908::RegAddr addr, uint8_t value);
    uint8_t readDrvRegister(DRV8908::RegAddr addr);
    void write2DrvRegisters(DRV8908::RegAddr addr, uint16_t value);
    uint16_t read2DrvRegisters(DRV8908::RegAddr addr);

    SpiDevice& spi;
    TCA9538 expander;
    DRV8908 drv;
    DS248x owDriver;
    OneWire ow;
    std::array<FlexChannel, 8> flexChannels;

    ChanBitsInternal op_ctrl_desired;
    ChanBitsInternal op_ctrl_status;
    ChanBitsInternal old_status;
    ChanBitsInternal ocp_status;
    ChanBitsInternal when_active_mask;   // state when active
    ChanBitsInternal when_inactive_mask; // state when inactive
    bool externalPower = false;
    bool connected = false;

    enum ExpanderPins : uint8_t {
        spiCsPin = 0,
        exernalVoltageEnable = 1,
        driverSleep = 2,
        driverFault = 3,
        oneWirePowerEnable = 4,
    };
};
