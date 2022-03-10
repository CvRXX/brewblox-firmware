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

#include "cbox/Application.h"
#include "cbox/CboxError.h"
#include "cbox/CboxPtr.h"
#include "cbox/Command.h"
#include "cbox/ConnectionPool.h"
#include "cbox/Connections.h"
#include "cbox/DataStream.h"
#include "cbox/DataStreamConverters.h"
#include "cbox/EepromObjectStorage.h"
#include "cbox/Object.h"
#include "cbox/ObjectContainer.h"
#include "cbox/ObjectFactory.h"
#include "cbox/ScanningFactory.hpp"

#include <memory>
#include <vector>

namespace cbox {

CboxError noop(Command& cmd);
CboxError readObject(Command& cmd);
CboxError writeObject(Command& cmd);
CboxError createObject(Command& cmd);
CboxError deleteObject(Command& cmd);
CboxError listActiveObjects(Command& cmd);
CboxError readStoredObject(Command& cmd);
CboxError listStoredObjects(Command& cmd);
CboxError clearObjects(Command& cmd);
CboxError discoverNewObjects(Command& cmd);
CboxError discoverNewObjects();

void loadObjectsFromStorage();
void unloadAllObjects();
void update(const update_t& now);
void forcedUpdate(const update_t& now);

} // end namespace cbox
