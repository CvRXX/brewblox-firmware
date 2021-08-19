#include "DRV8908.hpp"
#include <array>
#include <esp_log.h>

DRV8908::DRV8908(SpiDevice& spi)
    : spi(spi)
{
    _status = 0xFF;
}

hal_spi::error_t DRV8908::readRegister(RegAddr address, uint8_t& val) const
{
    std::array<uint8_t, 2> tx{uint8_t(static_cast<uint8_t>(address) | uint8_t(0x40)), 0};
    std::array<uint8_t, 2> rx{0, 0};
    ESP_LOGI("DRV RD before", "%u %u,%u,%u", tx[0], tx[1], rx[0], rx[1]);
    auto ec = spi.write_and_read(tx, rx);
    ESP_LOGI("DRV RD after", "%u %u, %u %u", tx[0], tx[1], rx[0], rx[1]);
    if (ec == 0 && rx[0] != 0xFF) {
        // clear first 2 bits, which are always read as 1
        // note that the datasheet is unclear and IC_STAT has bit 5 and 6 as OTW and OTSD
        // the status in the first byte has bit 6 as always 1 and bit 5 as OT
        // _status = rx[0] & 0x3F; // doesn't seem reliable
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
    ESP_LOGI("DRV WR before", "%u %u,%u,%u", tx[0], tx[1], rx[0], rx[1]);
    auto ec = spi.write_and_read(tx, rx);
    ESP_LOGI("DRV WR after", "%u %u, %u %u", tx[0], tx[1], rx[0], rx[1]);
    if (ec == 0 && rx[0] != 0xFF) {
        // _status = rx[0] & 0x3F; // doesn't seem reliable
    } else {
        _status = 0x80; // use reserved bit to signal SPI error
    }
    return ec;
}