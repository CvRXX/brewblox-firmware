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

#include "OneWireLowLevelInterface.h"

class OneWireNull : public OneWireLowLevelInterface {
public:
    OneWireNull() {}
    virtual ~OneWireNull() = default;
    virtual bool init() override final { return false; }
    virtual bool reset(void) override final { return true; }
    virtual void write(uint8_t) override final {}
    virtual uint8_t read(void) override final { return 0; }
    virtual void write_bit(uint8_t) override final {}
    virtual uint8_t read_bit(void) override final { return 0; }
    virtual uint8_t search_triplet(bool) override final { return 0; }
};
