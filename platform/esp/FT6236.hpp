#pragma once
#include "blox_hal/hal_gpio.h"
#include "control/I2CDevice.hpp"
#include "driver/gpio.h"
#include <atomic>
#include <optional>

/**
 * A driver for the FT6236 touchscreen controller
 */
class FT6236 : public I2CDeviceBase<0x38> {
public:
    /**
     * Constructs the driver
     *
     * @param address The lower address of the i2c device
     */
    FT6236(uint8_t address);
    ~FT6236();

    /// The different gestures the FT6236 supports
    enum class Gesture : std::uint8_t {
        moveUp,
        moveRight,
        moveDown,
        moveLeft,
        zoomIn,
        zoomOut,
        noGesture
    };

    /// A structure to represent a touch event
    struct Touch {
        uint16_t x;      // The x position of where the touch happened on the screen
        uint16_t y;      // The y position of where the touch happened on the screen
        Gesture gesture; // A possible gesture that occurred during the touch
    };

    /// Initialises the driver, needs to be called before other functions
    void init();

    /** Returns the lastTouch that occurred.
     *  If no touch has happened it will return a touch at {0,0} with no gesture.
     */
    Touch getLastTouch();

    /**
     * Checks if a touch is happening or happened.
     * @returns If a touch happened the touch otherwise std::nullopt
     */
    std::optional<Touch> getTouch();

private:
    enum class Register : uint8_t {
        P1_XH = 0x03,
        P1_XL = 0x04,
        P1_YH = 0x05,
        P1_YL = 0x06,
        GEST_ID = 0x01,
        G_MODE = 0xA4
    };

    bool writeRegister(Register reg, uint8_t value);
    std::optional<uint8_t> readRegister(Register reg);

    Gesture getGesture();

    Touch lastTouch = Touch{0, 0, Gesture::noGesture};
    const gpio_num_t int_pin = GPIO_NUM_35;
    std::atomic_bool interuptFlag = false;
};
