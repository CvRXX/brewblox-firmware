/*
 * Copyright 2018 BrewPi B.V.
 *
 * This file is part of Brewblox
 *
 * Brewblox is free software: you can redistribute it and/or modify
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
 * along with Brewblox.  If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once

#include "blocks/Block.hpp"

namespace platform::particle {

// provides a protobuf interface to the read only system info
class TouchSettingsBlock final : public cbox::ObjectBase<brewblox_BlockType_TouchSettings> {
public:
    TouchSettingsBlock() = default;
    ~TouchSettingsBlock() = default;

    cbox::CboxError read(const cbox::PayloadCallback& callback) const final;
    cbox::CboxError readStored(const cbox::PayloadCallback& callback) const final;
    cbox::CboxError write(const cbox::Payload& payload) final;
};

} // end namespace platform::particle
