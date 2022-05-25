/*
 * Copyright 2018 BrewPi B.V.
 *
 * This file is part of the BrewBlox Control Library.
 *
 * BrewPi is free software: you can redistribute it and/or modify
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
 * along with BrewPi.  If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once

#include "control/OneWireLowLevelInterface.hpp"

class OneWireNull : public OneWireLowLevelInterface {
public:
    OneWireNull() {}
    virtual ~OneWireNull() = default;
    bool init() final { return false; }
    bool reset(void) final { return true; }
    bool write(uint8_t) final { return true; }
    bool read(uint8_t& v) final { return true; }
    bool write_bit(bool) final { return true; }
    bool read_bit(bool&) final { return true; }
    uint8_t search_triplet(bool) final { return 0; }
};
