#include "blox_hal/hal_delay.hpp"
#include "blox_hal/hal_spi_impl.hpp"
#include "blox_hal/hal_spi_types.hpp"
#include "control/SlotMemPool.hpp"
#include "control/staticAllocator.hpp"
#include "driver/gpio.h"
#include "driver/spi_master.h"
#include "esp_err.h"
#include "freertos/FreeRTOS.h"
#include <stdio.h>
#include <string.h>

#include "freertos/task.h"

using namespace hal_spi;

DMA_ATTR StaticAllocator<spi_transaction_t, 10> transactionBuffer{};

namespace platform_spi {
struct SpiHost {
    spi_host_device_t handle;
    spi_bus_config_t config;
};

SpiHost spiHosts[1] = {{
    SPI2_HOST,
    {.mosi_io_num = 13,
     .miso_io_num = 12,
     .sclk_io_num = 14,
     .quadwp_io_num = -1,
     .quadhd_io_num = -1,
     .data4_io_num = -1,
     .data5_io_num = -1,
     .data6_io_num = -1,
     .data7_io_num = -1,
     .max_transfer_sz = 0,
     .flags = SPICOMMON_BUSFLAG_MASTER,
     .intr_flags = 0},
}};

spi_device_t* get_platform_ptr(const Settings& settings)
{
    return static_cast<spi_device_t*>(settings.platform_device_ptr);
}

void pre_callback(spi_transaction_t* t)
{
    if (t->user) {
        auto transactionData = TransactionData{
            .tx_data = reinterpret_cast<const uint8_t*>(t->tx_buffer),
            .rx_data = reinterpret_cast<uint8_t*>(t->rx_buffer),
            .tx_len = t->length / 8,
            .rx_len = t->rxlength / 8};

        auto callbacks = reinterpret_cast<CallbacksBase*>(t->user);
        callbacks->callPre(transactionData);

        t->tx_buffer = transactionData.tx_data;
        t->rx_buffer = transactionData.rx_data;
        t->length = transactionData.tx_len * 8;
        t->rxlength = transactionData.rx_len * 8;
    }
}

void post_callback(spi_transaction_t* t)
{
    if (t->user) {
        auto transactionData = TransactionData{
            .tx_data = reinterpret_cast<const uint8_t*>(t->tx_buffer),
            .rx_data = reinterpret_cast<uint8_t*>(t->rx_buffer),
            .tx_len = t->length,
            .rx_len = t->rxlength};

        auto callbacks = reinterpret_cast<CallbacksBase*>(t->user);
        callbacks->callPost(transactionData);

        callBackArgsBuffer.tryFree(callbacks);
        transactionBuffer.free(t);
    }
}

error_t init(Settings& settings)
{
    auto spi_host = spiHosts[settings.spi_idx];

    spi_device_interface_config_t devcfg = {
        .command_bits = 0,
        .address_bits = 0,
        .dummy_bits = 0,
        .mode = settings.mode,
        .duty_cycle_pos = 0,
        .cs_ena_pretrans = 2,
        .cs_ena_posttrans = 0,
        .clock_speed_hz = settings.speed,
        .input_delay_ns = 0,
        .spics_io_num = settings.ssPin,
        .flags = 0,
        .queue_size = settings.queueSize,
        .pre_cb = pre_callback,
        .post_cb = post_callback};

    spi_device_t* dev_ptr = nullptr;
    auto err = spi_bus_add_device(spi_host.handle, &devcfg, &dev_ptr);
    if (err == ESP_OK && dev_ptr) {
        settings.platform_device_ptr = dev_ptr;
    } else {
        ESP_ERROR_CHECK(err);
    }
    return err;
}

void deInit(const Settings& settings)
{
    if (settings.platform_device_ptr) {
        spi_bus_remove_device(get_platform_ptr(settings));
    }
}

error_t write(const Settings& settings, const uint8_t* data, size_t size)
{
    auto trans = spi_transaction_t{};
    if (size <= 4) {
        trans = spi_transaction_t{
            .flags = uint32_t{SPI_TRANS_USE_TXDATA},
            .cmd = 0,
            .addr = 0,
            .length = size * 8, // esp platform wants size in bits
            .rxlength = 0,
            .user = nullptr,
            .tx_buffer = nullptr,
            .rx_buffer = nullptr,
        };
        memcpy(trans.tx_data, data, size);
    } else {
        trans = spi_transaction_t{
            .flags = uint32_t{0},
            .cmd = 0,
            .addr = 0,
            .length = size * 8, // esp platform wants size in bits
            .rxlength = 0,
            .user = nullptr,
            .tx_buffer = data,
            .rx_buffer = nullptr,
        };
    }

    return spi_device_transmit(get_platform_ptr(settings), &trans);
}

spi_transaction_t* allocateTransaction()
{
    // Wait until there is space for the transaction in the static buffer.
    for (uint8_t retries = 0; retries < 10; retries++) {
        auto trans = new (transactionBuffer.get()) spi_transaction_t{};
        if (trans) {
            return trans;
        }
        hal_delay_ms(1);
    };
    return nullptr;
}

error_t dmaWrite(const Settings& settings, const uint8_t* data, size_t size, const CallbacksBase* callbacks)
{
    if (auto trans = allocateTransaction()) {

        *trans = spi_transaction_t{
            .flags = uint32_t{0},
            .cmd = 0,
            .addr = 0,
            .length = size * 8, // esp platform wants size in bits
            .rxlength = 0,
            .user = const_cast<CallbacksBase*>(callbacks),
            .tx_buffer = data,
            .rx_buffer = nullptr,
        };
        auto dev = get_platform_ptr(settings);

        auto error = spi_device_queue_trans(dev, trans, portMAX_DELAY);
        if (error != ESP_OK) {
            transactionBuffer.free(trans);
        }
        return error;
    } else {
        return 1;
    }
}

error_t dmaWriteValue(const Settings& settings, const uint8_t* data, size_t size, const CallbacksBase* callbacks)
{
    if (auto trans = allocateTransaction()) {

        *trans = spi_transaction_t{
            .flags = SPI_TRANS_USE_TXDATA,
            .cmd = 0,
            .addr = 0,
            .length = size * 8, // esp platform wants size in bits
            .rxlength = 0,
            .user = const_cast<CallbacksBase*>(callbacks),
            .tx_data = {0},
            .rx_buffer = nullptr,
        };

        memcpy(trans->tx_data, data, size);
        auto dev = get_platform_ptr(settings);

        auto error = spi_device_queue_trans(dev, trans, portMAX_DELAY);
        if (error != ESP_OK) {
            transactionBuffer.free(trans);
        }
        return error;

    } else {
        return 1;
    }
}

error_t writeAndRead(const Settings& settings, const uint8_t* tx, size_t txSize, uint8_t* rx, size_t rxSize)
{
    auto trans = spi_transaction_t{
        .flags = uint32_t{0},
        .cmd = 0,
        .addr = 0,
        .length = txSize * 8, // esp platform wants size in bits
        .rxlength = rxSize * 8,
        .user = nullptr,
        .tx_buffer = tx,
        .rx_buffer = rx,
    };

    return spi_device_transmit(get_platform_ptr(settings), &trans);
}

void aquire_bus(const Settings& settings)
{
    spi_device_acquire_bus(get_platform_ptr(settings), portMAX_DELAY);
}

void release_bus(const Settings& settings)
{
    while (!transactionBuffer.isEmpty()) {
        taskYIELD();
    }
    spi_device_release_bus(get_platform_ptr(settings));
}
}

error_t hal_spi_host_init(uint8_t idx)
{
    auto spi_host = platform_spi::spiHosts[idx];
    auto err = spi_bus_initialize(spi_host.handle, &spi_host.config, SPI_DMA_CH_AUTO);
    if (err != 0) {
        ESP_ERROR_CHECK(err);
    }
    return err;
}
