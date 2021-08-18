#include "MockI2CDevice.hpp"
#include "hal/hal_i2c.h"
#include <algorithm>
#include <cassert>
#include <memory>
#include <vector>

std::vector<std::unique_ptr<MockI2CDevice>> mockI2CDevices{};

hal_i2c_err_t hal_i2c_master_init()
{
    return 0;
}

hal_i2c_err_t hal_i2c_write(uint8_t address, const uint8_t* data, size_t len, bool /*stop*/)
{
    auto device = std::find_if(mockI2CDevices.begin(), mockI2CDevices.end(), [address](const std::unique_ptr<MockI2CDevice>& d) {
        return d->address == address;
    });
    if (device != mockI2CDevices.end()) {
        (*device)->write(data, len);
        return 0;
    }
    return 1;
}

hal_i2c_err_t hal_i2c_read(uint8_t address, uint8_t* data, size_t len, bool /*stop*/)
{
    auto device = std::find_if(mockI2CDevices.begin(), mockI2CDevices.end(), [address](const std::unique_ptr<MockI2CDevice>& d) {
        return d->address == address;
    });
    if (device != mockI2CDevices.end()) {
        (*device)->read(data, len);
        return 0;
    }
    return 1;
}

hal_i2c_err_t hal_i2c_detect(uint8_t address)
{
    auto device = std::find_if(mockI2CDevices.begin(), mockI2CDevices.end(), [address](const std::unique_ptr<MockI2CDevice>& d) {
        return d->address == address;
    });
    if (device != mockI2CDevices.end()) {
        return 0;
    }
    return 1;
}

void addMockI2CDevice(std::unique_ptr<MockI2CDevice>&& device)

{
    mockI2CDevices.push_back(std::move(device));
}

void removeMockI2CDevice(uint8_t address)
{
    mockI2CDevices.erase(std::remove_if(
        mockI2CDevices.begin(), mockI2CDevices.end(), [address](const std::unique_ptr<MockI2CDevice>& d) {
            return d->address == address;
        }));
}
