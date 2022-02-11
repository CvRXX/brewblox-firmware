/*
 * Copyright 2020 Elco Jacobs / Brewblox
 *
 * This file is part of ControlBox
 *
 * Controlbox is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with Controlbox.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "Tracing.h"
#include "ObjectIds.h"
#include <algorithm>
#include <array>
#include <cstdint>

#ifdef ESP_PLATFORM
// retained memory not yet working on ESP, commented out for now.
// ESP has application level tracing support that's better than this for an alternative implementation
// #include <esp_attr.h>
// __NOINIT_ATTR
#define __RETAINED__
#else
#define __RETAINED__ __attribute__((section(".retained_user")))
#endif

namespace cbox {

namespace tracing {

    namespace detail {
        __RETAINED__ std::array<TraceEvent, 10> historyRetained;
        __RETAINED__ uint8_t lastIdx;
        bool writeEnabled = false;
    }

    void add(uint8_t a, obj_id_t i, obj_type_t t)
    {
#ifndef ESP_PLATFORM
        using namespace detail;
        if (writeEnabled) {
            if (historyRetained[lastIdx].action == uint8_t(Action::PERSIST_OBJECT) && historyRetained[lastIdx].id == i) {
                return; // persisting a block can take a retry if a new block needs to be allocated, don't log twice.
            }
            lastIdx = (lastIdx < 9) ? lastIdx + 1 : 0;

            historyRetained[lastIdx] = TraceEvent{a, i, t};
        }
#endif
    }

    const std::array<TraceEvent, 10>& history()
    {
        using namespace detail;
#ifndef ESP_PLATFORM
        // history is kept as a circular buffer,
        // rotate array so oldest element is the first element before returning

        if (lastIdx != 9) {
            std::rotate(historyRetained.begin(), historyRetained.begin() + lastIdx + 1, historyRetained.end());
            lastIdx = 9;
        }
#endif
        return historyRetained;
    }

    void unpause()
    {
#ifndef ESP_PLATFORM
        detail::writeEnabled = true;
#endif
    }

    void pause()
    {
#ifndef ESP_PLATFORM
        detail::writeEnabled = false;
#endif
    }
}
}