#pragma once

#include "intellisense.hpp"

#include "cbox/EepromAccess.hpp"
#include <cstdint>
#include <cstring>

namespace cbox {

/**
 * Eeprom-like storage, backed by no-init RAM
 */
class NoInitRamAccess final : public EepromMemoryAccess {
public:
    NoInitRamAccess();
    ~NoInitRamAccess() = default;

protected:
    uint8_t* data() override;
    uint16_t length() const override;
};

} // end namespace cbox
