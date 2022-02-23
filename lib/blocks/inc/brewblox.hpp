/*
 * Copyright 2021 BrewPi B.V.
 *
 * This file is part of Brewblox.
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

#include "cbox/Box.h"
#include "cbox/ObjectContainer.h"
#include "cbox/ObjectFactory.h"

namespace brewblox {

const cbox::ObjectFactory make_blocks_factory();

}

const std::string& versionCsv();

// write device id as raw bytes to destination buffer
// must be implemented by platform specific source file
// returns actual bytes written
unsigned get_device_id(uint8_t* dest, unsigned max_len);

// unsigned get_device_id(uint8_t* dest, unsigned len);
const std::string& deviceIdString();

int resetReason();
int resetReasonData();
