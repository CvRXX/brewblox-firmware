/*
 * Copyright 2018 BrewPi B.V.
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

#include "TempSensorWidget.h"
#include "brewblox_particle.hpp"

TempSensorWidget::TempSensorWidget(WidgetWrapper& myWrapper, const cbox::obj_id_t& id)
    : ProcessValueWidgetBase(myWrapper)
    , lookup(brewbloxBox().makeCboxPtr<TempSensor>(id))
{
}

void TempSensorWidget::update(const WidgetSettings& settings)
{
    if (auto ptr = lookup.const_lock()) {
        setConnected();
        char icons[2] = {0};
        if (ptr->valid()) {
            setValue(temp_to_string(ptr->value(), 1, settings.tempUnit));
            icons[0] = 0x29;
        } else {
            setValue("");
            icons[0] = 0x2B;
        }
        setIcons(icons);
        setSetting("");
        return;
    }
    setDisconnected();
}
