/*
 * Copyright 2022 BrewPi B.V.
 *
 * This file is part of Brewblox.
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

#include "blocks/OneWireScanningFactory.hpp"
#include "blocks/DS2408Block.hpp"
#include "blocks/DS2413Block.hpp"
#include "blocks/TempSensorOneWireBlock.hpp"
#include "blox_hal/hal_delay.hpp"
#include "cbox/Application.hpp"
#include "cbox/Object.hpp"
#include "control/OneWireAddress.hpp"
#include "control/OneWireDevice.hpp"
#include <algorithm>
#include <memory>

std::shared_ptr<cbox::Object> OneWireScanningFactory::scan()
{
    if (auto bus = busPtr.lock()) {
        auto& objects = cbox::getObjects();
        auto busId = busPtr.getId();
        bus->reset_search();
        while (auto newAddr = bus->search()) {
            auto existing = std::find_if(objects.begin(), objects.end(), [&newAddr](const std::shared_ptr<cbox::Object>& obj) {
                if (auto devicePtr = obj->asInterface<OneWireDevice>()) {
                    return devicePtr->address() == newAddr;
                };
                return false;
            });

            if (existing == objects.cend()) {
                // create new object
                uint8_t familyCode = newAddr[0];
                switch (familyCode) {
                case DS18B20::familyCode: {
                    return std::shared_ptr<cbox::Object>(new TempSensorOneWireBlock(busId, std::move(newAddr)));
                }
                case DS2413::familyCode: {
                    return std::shared_ptr<cbox::Object>(new DS2413Block(busId, std::move(newAddr)));
                }
                case DS2408::familyCode: {
                    return std::shared_ptr<cbox::Object>(new DS2408Block(busId, std::move(newAddr)));
                }
                }
            } else {
                // device already exists
                // ensure that the bus id is correct in case it was plugged into a different module
                if (auto blockPtr = (*existing)->asInterface<OneWireDeviceBlock>()) {
                    blockPtr->setBusId(busId);
                }
            }
            hal_yield();
        }
    }
    return {};
}
