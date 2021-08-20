#pragma once
#include "I2CDevice.hpp"

class TCA9538 : public I2CDeviceBase<0x70> {
public:
    TCA9538(uint8_t lower_address)
        : I2CDeviceBase(lower_address)
    {
    }
    ~TCA9538() = default;

    void set_outputs(uint8_t bits)
    {
        outputs = bits;
        i2c_write({0x01, outputs});
    }

    void set_output(uint8_t pin, bool state)
    {
        uint8_t mask = uint8_t(0x1) << pin;
        if (state) {
            set_outputs(outputs | mask);
        } else {
            set_outputs(outputs & ~mask);
        }
    }

    // 1 for input, 0 for output
    void set_config(uint8_t inputs_mask)
    {
        i2c_write({0x03, inputs_mask});
    }

    bool get_outputs(uint8_t& result)
    {
        i2c_write({0x1});
        auto v = i2c_read(1);
        if (v.size()) {
            result = v[0];
            return true;
        }
        return false;
    }

private:
    uint8_t inputs = 0xFF;
    uint8_t outputs = 0xFF;
};