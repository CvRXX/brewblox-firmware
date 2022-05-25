/*
 * Copyright 2014-2015 Matthew McGowan.
 * Copyright 2018 Brewblox / Elco Jacobs
 * This file is part of Brewblox.
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

#include "cbox/CboxError.hpp"
#include "cbox/Object.hpp"
#include "cbox/ObjectContainer.hpp"
#include "cbox/Payload.hpp"

namespace cbox {

CboxError createBlock(const Payload& request, const PayloadCallback& callback);
CboxError writeBlock(const Payload& request, const PayloadCallback& callback);
CboxError readBlock(const Payload& request, const PayloadCallback& callback);
CboxError readAllBlocks(const PayloadCallback& callback);
CboxError deleteBlock(const Payload& request);
CboxError readStoredBlock(const Payload& request, const PayloadCallback& callback);
CboxError readAllStoredBlocks(const PayloadCallback& callback);
CboxError clearBlocks();
CboxError discoverBlocks(const PayloadCallback& callback);
CboxError discoverBlocks();

void loadBlocksFromStorage();
void unloadBlocks();
void update(const update_t& now);
void forcedUpdate(const update_t& now);

} // end namespace cbox
