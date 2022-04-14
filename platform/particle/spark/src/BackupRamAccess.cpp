#include "intellisense.hpp"

#include "platforms.h"
#include "spark/BackupRamAccess.hpp"

constexpr size_t storage_size = 2048;
constexpr size_t version_len = 8 + 1;

struct __attribute__((packed)) BackupRamLayout {
    char firmware_version[version_len];
    uint8_t data[storage_size];
};

#if PLATFORM_ID == PLATFORM_GCC
static BackupRamLayout layout;
#else
#include "deepsleep_hal_impl.h"
retained static BackupRamLayout layout;
#endif

namespace platform::particle {

constexpr bool isValidRange(uint16_t offset, uint16_t size)
{
    return offset + size <= storage_size;
}

BackupRamAccess::BackupRamAccess()
{
    if (strncmp(GIT_VERSION, layout.firmware_version, version_len) != 0) {
        strncpy(layout.firmware_version, GIT_VERSION, version_len);
        clear();
    }
}

int16_t BackupRamAccess::readByte(uint16_t offset) const
{
    if (isValidRange(offset, 1)) {
        return layout.data[offset];
    }
    return -1;
}

void BackupRamAccess::writeByte(uint16_t offset, uint8_t value)
{
    if (isValidRange(offset, 1)) {
        layout.data[offset] = value;
    }
}

void BackupRamAccess::readBlock(uint8_t* target, uint16_t offset, uint16_t size) const
{
    if (isValidRange(offset, size)) {
        memcpy(target, &layout.data[offset], size);
    }
}

void BackupRamAccess::writeBlock(uint16_t offset, const uint8_t* source, uint16_t size)
{
    if (isValidRange(offset, size)) {
        memcpy(&layout.data[offset], source, size);
    }
}

void BackupRamAccess::clear()
{
    memset(layout.data, 0, sizeof(layout.data));
}

uint16_t BackupRamAccess::length() const
{
    return storage_size;
}

} // end namespace platform::particle
