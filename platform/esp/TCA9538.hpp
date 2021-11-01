#pragma once
#include "I2CDevice.hpp"

class TCA9538 : public I2CDeviceBase<0x70> {
public:
    TCA9538(uint8_t lower_address)
        : I2CDeviceBase(lower_address)
    {
    }
    ~TCA9538() = default;

    bool set_outputs(uint8_t bits)
    {
        outputs = bits;
        return i2c_write(std::array<uint8_t, 2>({0x01, outputs}));
    }

    bool set_output(uint8_t pin, bool state)
    {
        uint8_t mask = uint8_t(0x1) << pin;
        if (state) {
            return set_outputs(outputs | mask);
        } else {
            return set_outputs(outputs & ~mask);
        }
    }

    // 1 for input, 0 for output
    bool set_config(uint8_t inputs_mask)
    {
        return i2c_write(std::array<uint8_t, 2>({0x03, inputs_mask}));
    }

    bool get_outputs(uint8_t& result)
    {
        if (i2c_write(uint8_t(0x1))) {
            if (i2c_read(result)) {
                return true;
            }
        }
        return false;
    }

private:
    uint8_t inputs = 0xFF;
    uint8_t outputs = 0xFF;
};