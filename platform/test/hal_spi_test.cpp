#include "MockSpiDevice.hpp"
#include "blox_hal/hal_spi_impl.hpp"
#include "blox_hal/hal_spi_types.hpp"
#include <algorithm>
#include <cassert>
#include <memory>
#include <vector>

using namespace hal_spi;

namespace platform_spi {

std::vector<std::shared_ptr<MockSpiDevice>> mockSpiDevices{};
MockSpiDevice* selected = nullptr;

error_t init(Settings& /*settings*/)
{
    return 0;
}

void deInit(Settings& /*settings*/)
{
}

void aquire_bus(Settings& settings)
{
    // error on multiple devices selected at the same time
    // when multithreaded testing is used, this can be replaced by a mutex
    assert(!selected);

    auto ssPin = settings.ssPin;
    auto device = std::find_if(mockSpiDevices.begin(), mockSpiDevices.end(), [ssPin](const std::shared_ptr<MockSpiDevice>& d) {
        return d->ssPin == ssPin;
    });
    if (device != mockSpiDevices.end()) {
        selected = device->get();
    }
}

void release_bus(Settings& settings)
{
    // error when device being released is not the same as the selected device
    assert(selected && selected->ssPin == settings.ssPin);
    selected = nullptr;
}

error_t write(Settings& settings, const uint8_t* data, size_t size)
{
    // error when device is not selected
    assert(selected && selected->ssPin == settings.ssPin);
    selected->write(data, size);
    return 0;
}

error_t read(Settings& settings, uint8_t* data, size_t size)
{
    // error when device is not selected
    assert(selected && selected->ssPin == settings.ssPin);
    selected->read(data, size);
    return 0;
}

error_t dmaWrite(Settings& /*settings*/, const uint8_t* /*data*/, size_t /*size*/, const CallbacksBase* /*callbacks*/)
{
    assert(false); // not implemented
    return 1;
}

error_t writeAndRead(Settings& settings, const uint8_t* tx, size_t txSize, uint8_t* rx, size_t rxSize)
{
    write(settings, tx, txSize);
    read(settings, rx, rxSize);

    return 0;
}

error_t hal_spi_host_init(uint8_t /*idx*/)
{
    return 0;
}
}

void addMockSpiDevice(std::shared_ptr<MockSpiDevice> device)
{
    platform_spi::mockSpiDevices.push_back(std::move(device));
}

void removeMockSpiDevice(int ssPin)
{
    // error when removing a device that is selected
    assert(!platform_spi::selected || platform_spi::selected->ssPin != ssPin);
    platform_spi::mockSpiDevices.erase(std::remove_if(
        platform_spi::mockSpiDevices.begin(), platform_spi::mockSpiDevices.end(), [ssPin](const std::shared_ptr<MockSpiDevice>& d) {
            return d->ssPin == ssPin;
        }));
}
