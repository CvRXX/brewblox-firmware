#include "DRV8908.hpp"
// #include "esp_err.h"
#include <array>

DRV8908::DRV8908(SpiDevice& spi)
    : spi(spi)
{
    _status = 0xFF;
}

hal_spi::error_t DRV8908::readRegister(RegAddr address, uint8_t& val) const
{
    std::array<uint8_t, 2> tx{uint8_t(static_cast<uint8_t>(address) | uint8_t(0x40)), 0};
    std::array<uint8_t, 2> rx{0, 0};
    auto ec = spi.write_and_read(tx, rx);
    if (ec == 0) {
        _status = rx[0] & 0x7F; // clear reserved bit
        val = rx[1];
    } else {
        _status = 0x80; // use reserved bit to signal SPI error
    }

    return ec;
}

hal_spi::error_t DRV8908::writeRegister(RegAddr address, uint8_t val)
{
    std::array<uint8_t, 2> tx{static_cast<uint8_t>(address), val};
    std::array<uint8_t, 2> rx{0, 0};
    auto ec = spi.write_and_read(tx, rx);
    // ESP_ERROR_CHECK_WITHOUT_ABORT(ec);
    if (ec == 0) {
        _status = rx[0] & 0x7F; // clear reserved bit
    } else {
        _status = 0x80; // use reserved bit to signal SPI error
    }
    return ec;
}