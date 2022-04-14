#include "intellisense.hpp"

#include "deepsleep_hal_impl.h"
#include "platforms.h"
#include "spark/BackupRamAccess.hpp"

namespace platform::particle {

#if PLATFORM_ID == PLATFORM_GCC
static BackupRamLayout layout;
#else
retained static BackupRamLayout layout;
#endif

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

} // end namespace platform::particle
