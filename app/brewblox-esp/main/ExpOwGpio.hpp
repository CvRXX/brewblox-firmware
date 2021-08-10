#pragma once
#include "DRV8908.hpp"
#include "DS248x.hpp"
#include "IoArray.h"
#include "IoModule.hpp"
#include "OneWire.h"
#include "TCA9538.hpp"
#include "esp_err.h"
#include "esp_log.h"
#include "hal/hal_delay.h"
#include <esp_heap_trace.h>
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

    void init()
    {
        expander.set_outputs(0b11111101); // 24V off
        expander.set_config(0b11111000);
        // disable OLD
        assert_cs();
        ESP_ERROR_CHECK_WITHOUT_ABORT(drv.writeRegister(DRV8908::RegAddr::OLD_CTRL_2, 0b01000000));
        // set overvoltage threshold to 33V and clear all faults
        ESP_ERROR_CHECK_WITHOUT_ABORT(drv.writeRegister(DRV8908::RegAddr::CONFIG_CTRL, 0b00000011));
        deassert_cs();
        expander.set_outputs(0b11111111); // 24V on
        hal_delay_ms(1000);
    }

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
            this->all = 0;
        }

        ChanBits(const ChanBitsInternal& internal);

        union {
            struct {
                uint8_t c1 : 2;
                uint8_t c2 : 2;
                uint8_t c3 : 2;
                uint8_t c4 : 2;
                uint8_t c5 : 2;
                uint8_t c6 : 2;
                uint8_t c7 : 2;
                uint8_t c8 : 2;
            };

            uint16_t all;
        };

        PinDrive get(uint8_t chan);
        void set(uint8_t chan, PinDrive state);
    };

    struct ChanBitsInternal {
        ChanBitsInternal()
        {
            this->all = 0;
        }

        ChanBitsInternal(const ChanBits& external);

        union {
            struct {
                uint8_t c1 : 2;
                uint8_t c4 : 2;
                uint8_t c8 : 2;
                uint8_t c7 : 2;
                uint8_t c2 : 2;
                uint8_t c6 : 2;
                uint8_t c3 : 2;
                uint8_t c5 : 2;
            };
            struct {
                uint8_t byte1 : 8;
                uint8_t byte2 : 8;
            };
            uint16_t all;
        };

        void apply(const ChanBitsInternal& mask, const ChanBitsInternal& state)
        {
            this->all &= ~mask.all;
            this->all |= state.all;
        }
    };

    class FlexChannel {
    public:
        FlexChannel(
            uint8_t id,
            ChannelConfig config,
            const ChanBits& pins,
            const ChanBits& when_active_drive,
            const ChanBits& when_inactive_drive)
            : id(id)
            , config(config)
            , pins_mask(pins)
            , when_active_mask(when_active_drive)
            , when_inactive_mask(when_inactive_drive)
        {
        }

        uint8_t id = 0;
        ChannelConfig config = ChannelConfig::UNUSED;
        uint8_t pwm_duty = 0;

        ChanBits pins() const
        {
            ChanBits converted = pins_mask;
            return converted;
        }

        ChanBits when_active() const
        {
            ChanBits converted = when_active_mask;
            return converted;
        }

        ChanBits when_inactive() const
        {
            ChanBits converted = when_inactive_mask;
            return converted; // convert to external order
        }

        // void configure(
        //     uint8_t new_id,
        //     ChannelConfig config,
        //     const ChanBits& pins,
        //     const ChanBits& when_active_drive,
        //     const ChanBits& when_inactive_drive);

        void apply(ChannelConfig& config, ChanBitsInternal& op_ctrl);

    private:
        ChanBitsInternal pins_mask;          // pins controlled by this channel
        ChanBitsInternal when_active_mask;   // state when active
        ChanBitsInternal when_inactive_mask; // state when inactive
        friend class ExpOwGpio;
    };

    virtual bool senseChannelImpl(uint8_t channel, State& result) const override final;
    virtual bool writeChannelImpl(uint8_t channel, ChannelConfig config) override final;
    virtual bool supportsFastIo() const override final
    {
        return false;
    }

    auto cbegin() const
    {
        return flexChannels.cbegin();
    }

    auto cend() const
    {
        return flexChannels.cend();
    }

    void clearChannels()
    {
        flexChannels.clear();
    }

    void addChannel(FlexChannel&& c)
    {
        flexChannels.push_back(c);
    }

    void update();

    uint8_t status() const
    {
        return drv.status();
    }

    ChanBits drive() const
    {
        return ChanBits{op_ctrl};
    }

    ChanBits openload() const;
    ChanBits overcurrent() const;

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
    std::vector<FlexChannel> flexChannels;
    ChanBitsInternal op_ctrl;
    ChanBitsInternal old_status;
    ChanBitsInternal ocp_status;
};