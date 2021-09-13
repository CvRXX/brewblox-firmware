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

#include "OneWire.h"
#include "OneWireAddress.h"
#include "OneWireDevice.h"
#include "blox/DS2408Block.h"
#include "blox/DS2413Block.h"
#include "blox/TempSensorOneWireBlock.h"
#include "cbox/CboxPtr.h"
#include "cbox/Object.h"
#include "cbox/ObjectContainer.h"
#include "cbox/ScanningFactory.hpp"
#include <memory>

class OneWireScanningFactory : public cbox::ScanningFactory {
private:
    cbox::CboxPtr<OneWire> busPtr;

public:
    OneWireScanningFactory(cbox::CboxPtr<OneWire>&& busPtr)
        : busPtr(busPtr)
    {
    }

    virtual ~OneWireScanningFactory() = default;

    virtual std::shared_ptr<cbox::Object> scan(cbox::ObjectContainer& objects) override final
    {
        if (auto bus = busPtr.lock()) {
            bus->reset_search();
            while (true) {
                OneWireAddress newAddr;
                if (bus->search(newAddr)) {
                    bool found = false;
                    for (auto existing = objects.cbegin(); existing != objects.cend(); ++existing) {
                        OneWireDevice* ptrIfCorrectType = reinterpret_cast<OneWireDevice*>(existing->object()->implements(cbox::interfaceId<OneWireDevice>()));
                        if (ptrIfCorrectType == nullptr) {
                            continue; // not the right type, no match
                        }
                        if (ptrIfCorrectType->address() == newAddr) {
                            found = true; // object with value already exists

                            // check if it was on a different bus than where we just found it and correct that if needed
                            OneWireDeviceBlock* blockPtr = reinterpret_cast<OneWireDeviceBlock*>(existing->object()->implements(cbox::interfaceId<OneWireDeviceBlock>()));
                            if (blockPtr) {
                                if (blockPtr->getBusId() != busPtr.getId()) {
                                    blockPtr->setBusId(busPtr.getId());
                                }
                            }
                            break;
                        }
                    }
                    if (!found) {
                        // create new object
                        uint8_t familyCode = newAddr[0];
                        switch (familyCode) {
                        case DS18B20::familyCode: {
                            return std::shared_ptr<cbox::Object>(new TempSensorOneWireBlock(objects, busPtr.getId(), newAddr));
                        }
                        case DS2413::familyCode: {
                            return std::shared_ptr<cbox::Object>(new DS2413Block(objects, busPtr.getId(), newAddr));
                        }
                        case DS2408::familyCode: {
                            return std::shared_ptr<cbox::Object>(new DS2408Block(objects, busPtr.getId(), newAddr));
                        }
                        default:
                            break;
                        }
                    }
                } else {
                    return {};
                }
            };
        }
        return {};
    }
};
