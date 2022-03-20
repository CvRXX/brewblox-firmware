/*
 * Copyright 2021 BrewPi B.V.
 *
 * This file is part of BrewBlox.
 *
 * Brewblox is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * Brewblox is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with Brewblox.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "gpio_handler.hpp"
#include <functional>
#include <vector>

namespace gpio_handler {

struct handler_t {
    gpio_num_t pin;
    std::function<void(bool level)> handler;
};

struct event_t {
    gpio_num_t pin;
    bool level;
};

std::vector<handler_t> handlers;

xQueueHandle gpio_evt_queue = nullptr;

void IRAM_ATTR isr_handler(void* arg)
{
    auto pin = gpio_num_t(reinterpret_cast<int32_t>(arg));
    bool level = gpio_get_level(pin);
    event_t event = {pin, level};

    xQueueSendToBackFromISR(gpio_evt_queue, &event, nullptr);
}

static void gpio_task(void* arg)
{
    event_t event;
    for (;;) {
        if (xQueueReceive(gpio_evt_queue, &event, portMAX_DELAY)) {
            printf("GPIO[%d] intr, val: %d\n", event.pin, event.level);
        }
    }
}

void init()
{

    // install gpio isr service
    gpio_install_isr_service(0);

    // create a queue to handle gpio event from isr
    gpio_evt_queue = xQueueCreate(10, sizeof(event_t));

    // start gpio task
    xTaskCreate(gpio_task, "gpio_task", 2048, nullptr, 10, nullptr);
}

void add(gpio_num_t pin, gpio_pull_mode_t pull, gpio_int_type_t edge, std::function<void()>&& handler)
{
    gpio_config_t io_conf = {
        .pin_bit_mask = 1ULL << pin,
        .mode = GPIO_MODE_INPUT,
        .pull_up_en = GPIO_PULLUP_DISABLE,
        .pull_down_en = GPIO_PULLDOWN_DISABLE,
        .intr_type = edge,
    };

    gpio_config(&io_conf);
    gpio_set_pull_mode(pin, pull);

    // hook isr handler for specific gpio pin, store pin nummber in void pointer address
    int32_t pinNr = pin;
    auto arg = reinterpret_cast<void*>(pinNr);
    gpio_isr_handler_add(pin, isr_handler, arg);
}

void remove(gpio_num_t pin)
{
    // remove isr handler for gpio number.
    gpio_isr_handler_remove(pin);
}
}
