/*
 * Copyright 2019 BrewPi B.V.
 *
 * This file is part of BrewPi.
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

#include "blocks/Block.hpp"
#include "spark/SparkIoBase.hpp"

namespace platform::particle {

class Spark2PinsBlock final : public SparkIoBase, public Block<brewblox_BlockType_Spark2Pins> {
private:
    static const uint8_t numPins = 4;
    pin_t channelToPin(uint8_t channel) const override;

public:
    Spark2PinsBlock();
    ~Spark2PinsBlock() = default;

    cbox::CboxError read(const cbox::PayloadCallback& callback) const override;
    cbox::CboxError readStored(const cbox::PayloadCallback& callback) const override;
    cbox::CboxError write(const cbox::Payload& payload) override;
    void* implements(cbox::obj_type_t iface) override;
};

} // end namespace platform::particle
