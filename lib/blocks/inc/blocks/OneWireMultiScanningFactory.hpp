/*
 * Copyright 2021 BrewPi B.V.
 *
 * This file is part of Brewblox
 *
 * Brewblox is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * Brewblox is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with Brewblox.  If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once

#include "OneWireScanningFactory.hpp"
#include "cbox/Application.hpp"
#include "cbox/CboxPtr.hpp"

class OneWireMultiScanningFactory : public cbox::ScanningFactory {
public:
    OneWireMultiScanningFactory()
    {
    }

    virtual ~OneWireMultiScanningFactory() = default;

    virtual std::shared_ptr<cbox::Object> scan() override final
    {
        for (auto obj_it = cbox::objects.cbegin(); obj_it != cbox::objects.cend(); ++obj_it) {
            if (cbox::asInterface<OneWire>(*obj_it) == nullptr) {
                continue; // not a OneWire bus
            }
            // use a bus scanner to find new devices on this bus
            OneWireScanningFactory factory(cbox::CboxPtr<OneWire>((*obj_it)->objectId()));
            auto obj = factory.scan();
            if (obj) {
                return obj; // return OneWire object if found
            }
            // go to next bus
        }
        return {}; // no new OneWire devices on any bus
    }
};
