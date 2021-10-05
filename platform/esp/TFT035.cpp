#include "TFT035.hpp"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "hal/hal_delay.h"
#include "hal/hal_spi_types.h"
#include <cstring>
#include <esp_log.h>
#include <functional>
#include <sys/time.h>

using namespace hal_spi;

auto callbackDcPinOn = StaticCallbacks{
    [](TransactionData& t) {
        hal_gpio_write(2, true);
    },
    nullptr};

auto callbackDcPinOnWithFree = StaticCallbacks{
    [](TransactionData& t) {
        hal_gpio_write(2, true);
    },
    [](TransactionData& t) {
        delete t.tx_data;
    }};

auto callbackDcPinOffWithFree = StaticCallbacks{
    [](TransactionData& t) {
        hal_gpio_write(2, false);
    },
    [](TransactionData& t) {
        delete t.tx_data;
    }};

auto callbackDcPinOff = StaticCallbacks{
    [](TransactionData& t) {
        hal_gpio_write(2, false);
    },
    nullptr};

TFT035::TFT035(void (*finishCallback)(void))
    : spiDevice(Settings{.spi_idx = 0, .speed = 20'000'000UL, .queueSize = 10, .ssPin = 4, .mode = Settings::Mode::SPI_MODE0, .bitOrder = Settings::BitOrder::MSBFIRST})
    , finishCallback(finishCallback)
    , dc(2)

{
}

error_t TFT035::writeCmd(const std::vector<uint8_t>& cmd)
{
    hal_gpio_write(2, false);
    return spiDevice.write(cmd);
}
error_t TFT035::write(const std::vector<uint8_t>& cmd)
{
    hal_gpio_write(2, true);
    return spiDevice.write(cmd);
}

error_t TFT035::writeCmd(uint8_t cmd)
{
    hal_gpio_write(2, false);
    return spiDevice.write(cmd);
}
error_t TFT035::write(uint8_t cmd)
{
    hal_gpio_write(2, true);
    return spiDevice.write(cmd);
}

void TFT035::init()
{
    writeCmd(PGAMCTRL);
    write({0x00,
           0x03,
           0x09,
           0x08,
           0x16,
           0x0A,
           0x3F,
           0x78,
           0x4C,
           0x09,
           0x0A,
           0x08,
           0x16,
           0x1A,
           0x0F});
    writeCmd(NGAMCTRL);
    write({0x00,
           0x16,
           0x19,
           0x03,
           0x0F,
           0x05,
           0x32,
           0x45,
           0x46,
           0x04,
           0x0E,
           0x0D,
           0x35,
           0x37,
           0x0F});

    writeCmd(PWCTRL1); //Power Control 1
    write(0x17);       //Vreg1out
    write(0x15);       //Verg2out

    writeCmd(PWCTRL2); //Power Control 2
    write(0x41);       //VGH,VGL

    writeCmd(PWCTRL3); //Power Control 3
    write(0x00);
    write(0x12); //Vcom
    write(0x80);

    writeCmd(MADCTL); //Memory Access

    write(0b00101000);

    writeCmd(COLMOD); // Interface Pixel Format
    write(0x66);      //18 bit

    writeCmd(IFMODE); // Interface Mode Control
    write(0x00);

    writeCmd(FRMCTR1); //Frame rate
    write(0xA0);       //60Hz

    writeCmd(INVTR); //Display Inversion Control
    write(0x02);     //2-dot

    writeCmd(DISCTRL); //Display Function Control  RGB/MCU Interface Control
    write(0x02);       //MCU
    write(0x02);       //Source,Gate scan direction

    writeCmd(SETIMAGE); // Set Image Function
    write(0x00);        // Disable 24 bit data

    writeCmd(ADJCTRL3); // Adjust Control
    write(0xA9);
    write(0x51);
    write(0x2C);
    write(0x82); // D7 stream, loose

    writeCmd(SLPOUT); //Sleep out
    hal_delay_ms(120);
    writeCmd(DISON);
}

error_t TFT035::setPos(unsigned int xs, unsigned int xe, unsigned int ys, unsigned int ye)
{
    if (auto error = dmaWrite(0x2A, 1, false))
        return error;

    auto x = (uint8_t(xs >> 8) << 24) + (uint8_t(xs & 0xFF) << 16) + (uint8_t(xe >> 8) << 8) + uint8_t(xe & 0xFF);

    if (auto error = dmaWrite(x, 4, true))
        return error;

    if (auto error = dmaWrite(0x2B, 1, false))
        return error;

    auto y = (uint8_t(ys >> 8) << 24) + (uint8_t(ys & 0xFF) << 16) + (uint8_t(ye >> 8) << 8) + uint8_t(ye & 0xFF);

    if (auto error = dmaWrite(y, 4, true))
        return error;

    return dmaWrite(0x2C, 1, false);
}

error_t TFT035::dmaWrite(uint8_t* tx_data, size_t tx_len, bool dc)
{
    if (dc) {
        return spiDevice.dmaWrite(tx_data, tx_len, callbackDcPinOn);
    } else {
        return spiDevice.dmaWrite(tx_data, tx_len, callbackDcPinOff);
    }
}

error_t TFT035::dmaWrite(uint32_t tx_val, size_t tx_len, bool dc)
{
    assert(tx_len <= 4);
    if (dc) {
        return spiDevice.dmaWrite(tx_val << (32 - 8 * tx_len), tx_len, callbackDcPinOn);
    } else {
        return spiDevice.dmaWrite(tx_val << (32 - 8 * tx_len), tx_len, callbackDcPinOff);
    }
}
bool TFT035::writePixels(unsigned int xs, unsigned int xe, unsigned int ys, unsigned int ye, uint8_t* pixels, uint16_t nPixels)
{
    if (this->setPos(xs, xe, ys, ye)){
        if (auto error = this->setPos(xs, xe, ys, ye))
            return error;
    }
        

    return spiDevice.dmaWrite(pixels, nPixels * 3,
                              Callbacks{[&](TransactionData& t) {
                                            hal_gpio_write(2, true);
                                        },
                                        [&](TransactionData& t) {
                                            this->finishCallback();
                                        }});
}

void TFT035::aquire_spi()
{
    spiDevice.aquire_bus();
}

void TFT035::release_spi()
{
    spiDevice.release_bus();
}