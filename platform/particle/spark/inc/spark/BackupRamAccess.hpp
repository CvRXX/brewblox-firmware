#pragma once

#include "cbox/EepromAccess.hpp"
#include <cstdint>
#include <cstring>

namespace platform::particle {

/**
 * Eeprom-like storage, backed by no-init RAM
 */
class BackupRamAccess final : public cbox::EepromMemoryAccess {
public:
    BackupRamAccess();
    ~BackupRamAccess() = default;

protected:
    uint8_t* data() override;
    uint16_t length() const override;
};

} // end namespace platform::particle
