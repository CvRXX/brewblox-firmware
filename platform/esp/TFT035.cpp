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

DMA_ATTR auto callbacksData = StaticCallbacks{
    [](TransactionData& t) {
        hal_gpio_write(2, true);
    },
    [](TransactionData& t) {
    }};

DMA_ATTR auto callbacksDataWithFree = StaticCallbacks{
    [](TransactionData& t) {
        hal_gpio_write(2, true);
    },
    [](TransactionData& t) {
        delete t.tx_data;
    }};

DMA_ATTR auto callbacksCommand = StaticCallbacks{
    [](TransactionData& t) {
        hal_gpio_write(2, false);
    },
    nullptr};

DMA_ATTR auto callbacksCommandWithFree = StaticCallbacks{
    [](TransactionData& t) {
        hal_gpio_write(2, false);
    },
    [](TransactionData& t) {
        delete t.tx_data;
    }};

TFT035::TFT035(void (*finishCallback)(void))
    : spiDevice(Settings{.spi_idx = 0, .speed = 16'000'000UL, .queueSize = 10, .ssPin = 4, .mode = Settings::Mode::SPI_MODE3, .bitOrder = Settings::BitOrder::MSBFIRST})
    , finishCallback(finishCallback)
    , dc(2)
{
}

error_t TFT035::writeCommand(const std::vector<uint8_t>& cmd)
{
    hal_gpio_write(2, false);
    return spiDevice.write(cmd);
}

error_t TFT035::writeData(const std::vector<uint8_t>& cmd)
{
    hal_gpio_write(2, true);
    return spiDevice.write(cmd);
}

error_t TFT035::writeCommand(uint8_t cmd)
{
    hal_gpio_write(2, false);
    return spiDevice.write(cmd);
}
error_t TFT035::writeData(uint8_t cmd)
{
    hal_gpio_write(2, true);
    return spiDevice.write(cmd);
}

void TFT035::init()
{
    writeCommand(PGAMCTRL);
    writeData({0x00,
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
    writeCommand(NGAMCTRL);
    writeData({0x00,
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

    writeCommand(PWCTRL1); //Power Control 1
    writeData(0x17);       //Vreg1out
    writeData(0x15);       //Verg2out

    writeCommand(PWCTRL2); //Power Control 2
    writeData(0x41);       //VGH,VGL

    writeCommand(PWCTRL3); //Power Control 3
    writeData(0x00);
    writeData(0x12); //Vcom
    writeData(0x80);

    writeCommand(MADCTL); //Memory Access

    writeData(0b00101000);

    writeCommand(COLMOD); // Interface Pixel Format
    writeData(0x66);      //18 bit

    writeCommand(IFMODE); // Interface Mode Control
    writeData(0x00);

    writeCommand(FRMCTR1); //Frame rate
    writeData(0xA0);       //60Hz

    writeCommand(INVTR); //Display Inversion Control
    writeData(0x02);     //2-dot

    writeCommand(DISCTRL); //Display Function Control  RGB/MCU Interface Control
    writeData(0x02);       //MCU
    writeData(0x02);       //Source,Gate scan direction

    writeCommand(SETIMAGE); // Set Image Function
    writeData(0x00);        // Disable 24 bit data

    writeCommand(ADJCTRL3); // Adjust Control
    writeData(0xA9);
    writeData(0x51);
    writeData(0x2C);
    writeData(0x82); // D7 stream, loose

    writeCommand(SLPOUT); //Sleep out
    hal_delay_ms(120);
    writeCommand(DISON);
}

error_t TFT035::setPos(unsigned int xs, unsigned int xe, unsigned int ys, unsigned int ye)
{
    if (auto error = dmaWriteCommand(0x2A))
        return error;

    auto x = std::array<uint8_t, 4>{uint8_t(xs >> 8), uint8_t(xs & 0xFF), uint8_t(xe >> 8), uint8_t(xe & 0xFF)};

    if (auto error = dmaWriteData(std::move(x)))
        return error;

    if (auto error = dmaWriteCommand(0x2B))
        return error;

    auto y = std::array<uint8_t, 4>{uint8_t(ys >> 8), uint8_t(ys & 0xFF), uint8_t(ye >> 8), uint8_t(ye & 0xFF)};

    if (auto error = dmaWriteData(std::move(y)))
        return error;

    return dmaWriteCommand(0x2C);
}

error_t TFT035::dmaWriteCommand(const uint8_t* tx_data, size_t tx_len)
{
    return spiDevice.dmaWrite(tx_data, tx_len, callbacksCommand);
}

error_t TFT035::dmaWriteData(const uint8_t* tx_data, size_t tx_len)
{
    return spiDevice.dmaWrite(tx_data, tx_len, callbacksData);
}

template <std::size_t n>
error_t TFT035::dmaWriteCommand(std::array<uint8_t, n>&& tx_val)
{
    return spiDevice.dmaWrite(std::move(tx_val), callbacksCommand);
}
template <std::size_t n>
error_t TFT035::dmaWriteData(std::array<uint8_t, n>&& tx_val)
{
    return spiDevice.dmaWrite(std::move(tx_val), callbacksData);
}

error_t TFT035::dmaWriteCommand(uint8_t tx_val)
{
    return dmaWriteCommand(std::array<uint8_t, 1>{tx_val});
}

error_t TFT035::dmaWriteData(uint8_t tx_val)
{
    return dmaWriteData(std::array<uint8_t, 1>{tx_val});
}

bool TFT035::writePixels(unsigned int xs, unsigned int xe, unsigned int ys, unsigned int ye, const uint8_t* pixels, uint16_t nPixels)
{
    if (this->setPos(xs, xe, ys, ye)) {
        ESP_LOGE("Display", "Set pos failed, retrying....");
        if (auto error = this->setPos(xs, xe, ys, ye)) {
            ESP_LOGE("Display", "Set pos failed.");
            return error;
        }
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