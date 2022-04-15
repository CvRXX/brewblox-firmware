#pragma once
#include "cbox/EepromAccess.hpp"
#include "eeprom_hal.h"
#include <cstdint>

namespace platform::particle {

class SparkEepromAccess final : public cbox::EepromAccess {
public:
    SparkEepromAccess()
    {
        HAL_EEPROM_Init();
    }
    ~SparkEepromAccess() = default;

    int16_t readByte(uint16_t offset) override
    {
        if (offset < 2048) {
            return HAL_EEPROM_Read(offset);
        }
        return -1;
    }

    void writeByte(uint16_t offset, uint8_t value) override
    {
        HAL_EEPROM_Write(offset, value);
    }

    void readBlock(uint8_t* target, uint16_t offset, uint16_t size) override
    {
        HAL_EEPROM_Get(offset, target, size);
    }

    void writeBlock(uint16_t target, const uint8_t* source, uint16_t size) override
    {
        HAL_EEPROM_Put(target, source, size);
    }

    uint16_t length() const
    {
        return HAL_EEPROM_Length();
    }

    void clear() override
    {
        HAL_EEPROM_Clear();
    }
};

} // end namespace platform::particle
