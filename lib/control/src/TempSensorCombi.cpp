/*
 * Copyright 2020 BrewPi B.V.
 *
 * This file is part of the BrewBlox Control Library.
 *
 * Brewblox is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * BrewPi is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with Brewblox.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "control/TempSensorCombi.hpp"

void TempSensorCombi::update()
{
    switch (func) {
    case CombineFunc::AVG: {
        auto sum = safe_elastic_fixed_point<18, 12>{0};
        uint16_t count = 0;
        for (auto& ref : inputs) {
            if (auto sens = ref.get().lock()) {
                if (auto v = sens->value()) {
                    ++count;
                    sum += *v;
                }
            }
        }
        if (count > 0) {
            m_value = sum / count;
        } else {
            m_value = std::nullopt;
        }
        return;
    }
    case CombineFunc::MIN: {
        m_value = std::nullopt;
        for (auto& ref : inputs) {
            if (auto sens = ref.get().lock()) {
                if (auto v = sens->value()) {
                    if (m_value) {
                        if (*v < *m_value) {
                            m_value = v;
                        }
                    } else {
                        m_value = v;
                    }
                }
            }
        }
        return;
    }
    case CombineFunc::MAX: {
        m_value = std::nullopt;
        for (auto& ref : inputs) {
            if (auto sens = ref.get().lock()) {
                if (auto v = sens->value()) {
                    if (m_value) {
                        if (*v > *m_value) {
                            m_value = v;
                        }
                    } else {
                        m_value = v;
                    }
                }
            }
        }
        return;
    }
    }
}
