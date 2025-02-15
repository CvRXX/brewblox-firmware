/*
 * Copyright 2021 Elco Jacobs / Brewblox
 *
 * This file is part of Brewblox
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
 * along with Brewblox. If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once

#include <cstdint>
#include <vector>

namespace cbox {

uint8_t calc_crc_8(uint8_t crc, uint8_t data);

uint8_t calc_crc_16(uint8_t crc, uint16_t data);

uint8_t calc_crc_vector(uint8_t crc, const std::vector<uint8_t>& data);
}
