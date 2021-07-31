#include "DRV8908.hpp"
#include "IoArray.h"
#include "TCA9538.hpp"
#include "esp_err.h"
#include "esp_log.h"
#include "hal/hal_delay.h"
#include <vector>

class ExpansionGpio : public IoArray {
public:
    ExpansionGpio(uint8_t lower_address)
        : IoArray(8)
        , expander(lower_address)
        , drv(
              0, -1,
              [this]() {
                  expander.set_output(0, false);
                  hal_delay_ms(1);
              },
              [this]() {
                  expander.set_output(0, true);
              })
    {
        init();
    }

    void init()
    {
        expander.set_outputs(0b11111101); // 24V off
        expander.set_config(0b11111000);
        // disable OLD
        ESP_ERROR_CHECK_WITHOUT_ABORT(drv.writeRegister(DRV8908::RegAddr::OLD_CTRL_2, 0b01000000));
        // set overvoltage threshold to 33V and clear all faults
        ESP_ERROR_CHECK_WITHOUT_ABORT(drv.writeRegister(DRV8908::RegAddr::CONFIG_CTRL, 0b00000011));
        expander.set_outputs(0b11111111); // 24V aan
    }

    void test();

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
        enum class Type {
            NONE = 0,
            INPUT = 1,
            OUTPUT = 2,
            OUTPUT_PWM_80HZ = 3,
            OUTPUT_PWM_100HZ = 4,
            OUTPUT_PWM_200HZ = 4,
            OUTPUT_PWM_2KHZ = 5,
        };

        uint8_t id = 0;
        uint8_t pwm_duty = 0;
        Type type = Type::NONE;

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

        void configure(
            uint8_t new_id,
            Type new_type,
            const ChanBits& pins,
            const ChanBits& when_active_drive,
            const ChanBits& when_inactive_drive);

        void apply(ChannelConfig& config, ChanBitsInternal& op_ctrl);

    private:
        ChanBitsInternal pins_mask;          // pins controlled by this channel
        ChanBitsInternal when_active_mask;   // state when active
        ChanBitsInternal when_inactive_mask; // state when inactive
        friend class ExpansionGpio;
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
    uint8_t address() const
    {
        return expander.address();
    }

private:
    TCA9538 expander;
    DRV8908 drv;
    std::vector<FlexChannel> flexChannels;
    ChanBitsInternal op_ctrl;
};