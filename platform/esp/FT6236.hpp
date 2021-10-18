#pragma once
#include "I2CDevice.hpp"
#include "driver/gpio.h"
#include "hal/hal_gpio.h"
#include <atomic>
#include <esp_log.h>
#include <optional>

class FT6236 : public I2CDeviceBase<0x38> {
public:
    FT6236(uint8_t address)
        : I2CDeviceBase(address)
    {
    }
    ~FT6236()
    {
        // Disable interupts and unregister handler
        gpio_set_intr_type(int_pin, GPIO_INTR_DISABLE);
        gpio_isr_handler_remove(int_pin);
    }

    struct touch {
        uint8_t x;
        uint8_t y;
    };

    void init()
    {
        //Enable interupt polling mode
        writeRegister(0xA4, 0x00);

        //Enable interupts and register handler
        gpio_set_intr_type(int_pin, GPIO_INTR_NEGEDGE);
        gpio_isr_handler_add(
            int_pin, [](void* data) {
                *reinterpret_cast<std::atomic<bool>*>(data) = true;
            },
            reinterpret_cast<void*>(&interuptFlag));
    }

    bool writeRegister(uint8_t reg, uint8_t value)
    {
        return i2c_write({reg, value});
    }

    std::optional<uint8_t> readRegister(uint8_t reg)
    {
        auto value = std::array<uint8_t, 1>{};
        i2c_write(reg);
        auto read = i2c_read(value);
        if (read) {
            return value[0];
        } else {
            return std::nullopt;
        }
    }
    std::optional<touch> getTouch()
    {
        if (interuptFlag.exchange(false)) {
            auto x = readRegister(0x06);
            auto y = readRegister(0x04);
            if (x && y) {
                return touch{*x, *y};
            } else {
                return std::nullopt;
            }
        } else {
            return std::nullopt;
        }
    }
    uint8_t getGesture() // Make this with the new read and make it optional.
    {
        i2c_write(0x01);
        return i2c_read(1)[0]; // TODO: handle empty vector
    }

private:
    const gpio_num_t int_pin = GPIO_NUM_35;
    std::atomic_bool interuptFlag = false;
};