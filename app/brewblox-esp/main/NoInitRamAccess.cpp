#include "NoInitRamAccess.hpp"
#include <esp_attr.h>
#include <esp_log.h>

namespace cbox {

static const char* TAG = "NoInitRamAccess";
RTC_NOINIT_ATTR static NoInitRamLayout layout;

NoInitRamAccess::NoInitRamAccess()
{
    ESP_LOGI(TAG, "%s - %.8s", GIT_VERSION, layout.firmware_version);
    if (strncmp(GIT_VERSION, layout.firmware_version, version_len) != 0) {
        strncpy(layout.firmware_version, GIT_VERSION, version_len);
        clear();
        ESP_LOGI(TAG, "writing firmware %s -> %.8s", GIT_VERSION, layout.firmware_version);
    }
}

int16_t NoInitRamAccess::readByte(uint16_t offset) const
{
    if (isValidRange(offset, 1)) {
        return layout.data[offset];
    }
    return -1;
}

void NoInitRamAccess::writeByte(uint16_t offset, uint8_t value)
{
    if (isValidRange(offset, 1)) {
        layout.data[offset] = value;
    }
}

void NoInitRamAccess::readBlock(uint8_t* target, uint16_t offset, uint16_t size) const
{
    if (isValidRange(offset, size)) {
        memcpy(target, &layout.data[offset], size);
    }
}

void NoInitRamAccess::writeBlock(uint16_t offset, const uint8_t* source, uint16_t size)
{
    if (isValidRange(offset, size)) {
        memcpy(&layout.data[offset], source, size);
    }
}

void NoInitRamAccess::clear()
{
    memset(layout.data, 0, sizeof(layout.data));
}

} // end namespace cbox
