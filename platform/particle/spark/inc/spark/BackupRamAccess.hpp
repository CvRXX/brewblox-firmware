#pragma once

#include "cbox/EepromAccess.hpp"
#include <cstdint>
#include <cstring>

namespace platform::particle {

/**
 * Eeprom-like storage, backed by no-init RAM
 */
class BackupRamAccess final : public cbox::EepromAccess {
public:
    BackupRamAccess();
    ~BackupRamAccess() = default;

    int16_t readByte(uint16_t offset) const override;
    void writeByte(uint16_t offset, uint8_t value) override;
    void readBlock(uint8_t* target, uint16_t offset, uint16_t size) const override;
    void writeBlock(uint16_t offset, const uint8_t* source, uint16_t size) override;
    void clear() override;
    uint16_t length() const override;
};

} // end namespace platform::particle
