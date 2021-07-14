#pragma once
#include "../EepromAccess.h"
#include "eeprom_hal.h"
#include <cstdint>

namespace cbox {

class SparkEepromAccess : public EepromAccess {
public:
    SparkEepromAccess()
    {
        HAL_EEPROM_Init();
    }
    virtual ~SparkEepromAccess() = default;

    virtual int16_t readByte(uint16_t offset) const override final
    {
        if (offset < 2048) {
            return HAL_EEPROM_Read(offset);
        }
        return -1;
    }
    virtual void writeByte(uint16_t offset, uint8_t value) override final
    {
        HAL_EEPROM_Write(offset, value);
    }

    virtual void readBlock(uint8_t* target, uint16_t offset, uint16_t size) const override final
    {
        HAL_EEPROM_Get(offset, target, size);
    }
    virtual void writeBlock(uint16_t target, const uint8_t* source, uint16_t size) override final
    {
        HAL_EEPROM_Put(target, source, size);
    }
    virtual uint16_t length() const override final
    {
        return HAL_EEPROM_Length();
    }

    virtual void clear() override final
    {
        HAL_EEPROM_Clear();
    }
};

} // end namespace cbox
