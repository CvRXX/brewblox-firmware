/*
 * Copyright 2021 BrewPi B.V.
 *
 * This file is part of BrewBlox
 *
 * BrewBlox is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * BrewBlox is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with BrewBlox.  If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once

#include "OneWireScanningFactory.hpp"
#include "cbox/CboxPtr.h"

class OneWireMultiScanningFactory : public cbox::ScanningFactory {
public:
    OneWireMultiScanningFactory()
    {
    }

    virtual ~OneWireMultiScanningFactory() = default;

    virtual void reset() override final
    {
        ;
    }

    virtual std::shared_ptr<cbox::Object> scan(cbox::ObjectContainer& objects) override final
    {
        for (auto obj_it = objects.cbegin(); obj_it != objects.cend(); ++obj_it) {
            OneWire* bus = const_cast<OneWire*>(cbox::asInterface<OneWire>(obj_it->object()));
            if (bus == nullptr) {
                continue; // not a OneWire bus
            }
            // use a bus scanner to find new devices on this bus
            OneWireScanningFactory factory(cbox::CboxPtr<OneWire>(objects, obj_it->id()));
            auto obj = factory.scan(objects);
            if (obj) {
                return obj; // return OneWire object if found
            }
            // go to next bus
        }
        return nullptr; // no new OneWire devices on any bus
    }
};
