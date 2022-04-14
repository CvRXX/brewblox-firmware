#pragma once

#include "cbox/EepromAccess.hpp"
#include <cstdint>
#include <cstring>

namespace platform::particle {

constexpr size_t storage_size = 2048;
constexpr size_t version_len = 8 + 1;

struct __attribute__((packed)) BackupRamLayout {
    char firmware_version[version_len];
    uint8_t data[storage_size];
};

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

    uint16_t length() const override
    {
        return storage_size;
    }

protected:
    bool isValidRange(uint16_t offset, uint16_t size) const
    {
        return offset + size <= storage_size;
    }
};

} // end namespace platform::particle
