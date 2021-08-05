#pragma once
#include <cstdint>

class IoModule {
public:
    // valid positions are 1-4, lower bits of I2C address are offset by 1 to ensure 0 is invalid
    virtual uint8_t modulePosition() const = 0;
    virtual void modulePosition(uint8_t pos) = 0;
};