#include "NoInitRamAccess.hpp"
#include <esp_attr.h>

namespace cbox {

constexpr size_t storage_size = 2048;
constexpr size_t version_len = 8 + 1;

struct __attribute__((packed)) NoInitRamLayout {
    char firmware_version[version_len];
    uint8_t data[storage_size];
};

RTC_NOINIT_ATTR static NoInitRamLayout layout;

NoInitRamAccess::NoInitRamAccess()
{
    if (strncmp(GIT_VERSION, layout.firmware_version, version_len) != 0) {
        clear();
        strncpy(layout.firmware_version, GIT_VERSION, version_len);
    }
}

uint8_t* NoInitRamAccess::data()
{
    return layout.data;
}

uint16_t NoInitRamAccess::length() const
{
    return storage_size;
}

} // end namespace cbox
