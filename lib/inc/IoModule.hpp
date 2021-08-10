#pragma once
#include "hal/hal_spi.hpp"
#include <cstdint>

class IoModule {
public:
    // valid positions are 1-4, lower bits of I2C address are offset by 1 to ensure 0 is invalid
    virtual uint8_t modulePosition() const = 0;
    virtual void modulePosition(uint8_t pos) = 0;

    SpiDevice& get_spi()
    {
        // initilialize shared spi device on first use
        static SpiDevice* spi = new SpiDevice(
            hal_spi::Settings{
                .spi_idx = 0,
                .speed = 100000,
                .queueSize = 1,
                .ssPin = -1,
                .mode = hal_spi::Settings::Mode::SPI_MODE1,
                .bitOrder = hal_spi::Settings::BitOrder::MSBFIRST,
            });
        return *spi;
    }

protected:
    // all IO modules use a shared SPI device, because the ESP bus master can manage only 6 devices
    // care must be taken that the bus is aquired first, then the remote CS pin has to be set over I2C before communication starts
};