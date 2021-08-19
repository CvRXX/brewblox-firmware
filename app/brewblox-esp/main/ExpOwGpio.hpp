#pragma once

#include "DRV8908.hpp"
#include "DS248x.hpp"
#include "IoArray.h"
#include "IoModule.hpp"
#include "OneWire.h"
#include "TCA9538.hpp"
#include "blox/compiled_proto/src/OneWireGpioModule.pb.h"
// #include "esp_err.h"
// #include "esp_log.h"
#include "hal/hal_delay.h"
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

    void init_expander();
    void init_driver();

    virtual bool supportsFastIo()
    {
        return false;
    }

public:
    enum PinDrive : uint8_t {
        PULL_NONE = 0x0,
        PULL_DOWN = 0x01,
        PULL_UP = 0x02,
        PULL_BOTH = 0x03, // this is a short circuit and should not actually be set
    };

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

        PinDrive get(uint8_t chan);
        void set(uint8_t chan, PinDrive state);
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
            bits.all |= state.bits.all;
        }
    };

    class FlexChannel {
    public:
        FlexChannel()
            : deviceType(blox_GpioDeviceType_NONE)
        {
            pins_mask.bits.all = 0;
        }

        FlexChannel(
            blox_GpioDeviceType type,
            uint8_t pins)
            : deviceType(type)
        {
            // set mask for both pull-up and pull-down
            ChanBits external_pins_mask;
            external_pins_mask.setBits(pins, pins);
            pins_mask = ChanBitsInternal{external_pins_mask};
        }

        bool operator==(const FlexChannel& other) const
        {
            return this->pins_mask.bits.all == other.pins_mask.bits.all && this->deviceType == other.deviceType;
        }

        bool operator!=(const FlexChannel& other) const
        {
            return this->pins_mask.bits.all != other.pins_mask.bits.all || this->deviceType != other.deviceType;
        }

        blox_GpioDeviceType deviceType = blox_GpioDeviceType_NONE;
        ChannelConfig config = ChannelConfig::UNUSED;

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

    virtual bool senseChannelImpl(uint8_t channel, State& result) const override final;
    virtual bool writeChannelImpl(uint8_t channel, ChannelConfig config) override final;
    virtual bool supportsFastIo() const override final
    {
        return false;
    }

    blox_ChannelStatus channelStatus(uint8_t channel) const;
    blox_DigitalState channelState(uint8_t channel) const;

    void setupChannel(uint8_t channel, const FlexChannel& c);
    const FlexChannel& getChannel(uint8_t channel) const;

    void update();

    DRV8908::Status status(bool update = false) const
    {
        return drv.status(update);
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
    uint8_t pullUpOverCurrent() const
    {
        return ChanBits{ocp_status}.up();
    }
    uint8_t pullDownOverCurrent() const
    {
        return ChanBits{ocp_status}.down();
    }
    uint8_t pullUpOpenLoad() const
    {
        return ChanBits{old_status}.up();
    }
    uint8_t pullDownOpenLoad() const
    {
        return ChanBits{old_status}.down();
    }

    uint8_t modulePosition() const override final
    {
        auto addr = expander.address();
        if (addr == 0xFF) {
            return 0;
        }
        return (addr & uint8_t{3}) + 1;
    }

    void modulePosition(uint8_t pos) override final
    {
        if (pos && pos <= 4) {
            expander.set_address_bits(pos - 1);
            owDriver.set_address_bits(pos - 1);
        }
    }

    OneWire& oneWireBus()
    {
        return ow;
    }

private:
    void assert_cs()
    {
        spi.aquire_bus();
        expander.set_output(0, false);
        hal_delay_ms(1);
    }
    void deassert_cs()
    {
        expander.set_output(0, true);
        spi.release_bus();
    }

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
};