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

BackupRamAccess::BackupRamAccess()
{
    if (strncmp(GIT_VERSION, layout.firmware_version, version_len) != 0) {
        clear();
        strncpy(layout.firmware_version, GIT_VERSION, version_len);
    }
}

uint8_t* BackupRamAccess::data()
{
    return layout.data;
}

uint16_t BackupRamAccess::length() const
{
    return storage_size;
}

} // end namespace platform::particle
