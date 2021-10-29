#include "FT6236.hpp"

FT6236::FT6236(uint8_t address)
    : I2CDeviceBase(address)
{
}

FT6236::~FT6236()
{
    // Disable interupts and unregister handler
    gpio_set_intr_type(int_pin, GPIO_INTR_DISABLE);
    gpio_isr_handler_remove(int_pin);
}

void FT6236::init()
{
    //Enable interupt polling mode
    writeRegister(Register::G_MODE, 0x00);

    //Enable interupts and register handler
    gpio_set_intr_type(int_pin, GPIO_INTR_NEGEDGE);
    gpio_isr_handler_add(
        int_pin, [](void* data) {
            *reinterpret_cast<std::atomic<bool>*>(data) = true;
        },
        reinterpret_cast<void*>(&interuptFlag));
}

bool FT6236::writeRegister(Register reg, uint8_t value)
{
    return i2c_write({static_cast<uint8_t>(reg), value});
}

FT6236::Touch FT6236::getLastTouch()
{
    return lastTouch;
}

std::optional<uint8_t> FT6236::readRegister(Register reg)
{
    auto value = std::array<uint8_t, 1>{};
    i2c_write(static_cast<uint8_t>(reg));
    auto read = i2c_read(value);
    if (read) {
        return value[0];
    } else {
        return std::nullopt;
    }
}

std::optional<FT6236::Touch> FT6236::getTouch()
{
    if (interuptFlag) {
        if (hal_gpio_read(int_pin)) {
            interuptFlag = false;
        }
        auto xLow = readRegister(Register::P1_XL);
        auto xHigh = readRegister(Register::P1_XH);
        auto yLow = readRegister(Register::P1_YL);
        auto yHigh = readRegister(Register::P1_YH);

        if (xLow && xHigh && yLow && yHigh) {
            uint16_t x = *xLow + ((*xHigh & 0x0F) << 8);
            uint16_t y = *yLow + ((*yHigh & 0x0F) << 8);

            lastTouch = Touch{x, y, getGesture()};
            return lastTouch;
        } else {
            return std::nullopt;
        }
    } else {
        return std::nullopt;
    }
}

FT6236::Gesture FT6236::getGesture()
{
    if (auto rawGesture = readRegister(Register::GEST_ID)) {
        switch (*rawGesture) {
        case 0x10:
            return Gesture::moveUp;
        case 0x14:
            return Gesture::moveRight;
        case 0x18:
            return Gesture::moveDown;
        case 0x1C:
            return Gesture::moveLeft;
        case 0x48:
            return Gesture::zoomIn;
        case 0x49:
            return Gesture::zoomOut;
        default:
            return Gesture::noGesture;
        }
    } else {
        return Gesture::noGesture;
    }
}