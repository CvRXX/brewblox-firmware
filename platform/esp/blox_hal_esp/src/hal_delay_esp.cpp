#include "blox_hal/hal_delay.hpp"
#include "esp32/rom/ets_sys.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include <sys/time.h>

void hal_delay_us(uint32_t duration)
{
    ets_delay_us(duration);
}

void hal_delay_ms(uint32_t duration)
{
    vTaskDelay(duration / portTICK_PERIOD_MS);
}

void hal_yield()
{
    taskYIELD();
}
