#include "drivers/DRV8908.hpp"
#include <array>

DRV8908::DRV8908(SpiDevice& spi)
    : spi(spi)
{
    // last bit (power on reset) as an inverted fault status. 0 = reset detected
    _status = 0xFE;
}

hal_spi::error_t DRV8908::readRegister(RegAddr address, uint8_t& val) const
{
    std::array<uint8_t, 2> tx{uint8_t(static_cast<uint8_t>(address) + uint8_t(0x40)), 0};
    std::array<uint8_t, 2> rx{0, 0};
    auto ec = spi.write_and_read(tx, rx);
    if (ec == 0 && rx[0] != 0xFF) {
        // note that the datasheet is a bit confusing. IC_STAT has bit 5 and 6 as OTW and OTSD
        // however, in the status returned during a read or write, bit 5 is OT and 6 as always one
        _status = rx[0] & 0x3F; // clear reserved bit
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
    if (ec == 0 && rx[0] != 0xFF) {
        _status = rx[0] & 0x3F;
    } else {
        _status = 0x80; // use reserved bit to signal SPI error
    }
    return ec;
}
