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

#pragma once
#include "ProcessValue.h"
#include "WidgetBase.h"
#include "cbox/CboxPtr.h"
#include "d4d.hpp"

class ProcessValueWidgetBase : public WidgetBase {
protected:
    char value_buf[12] = {0};
    char setting_buf[12] = {0};
    char icons_buf[6] = {0};

    const D4D_OBJECT* lbl_relations[2];

    D4D_STR_PROPERTIES value_strPrties = {D4D_LBL_FNT_PRTY_DEFAULT, (D4D_ALIGN_H_CENTER_MASK | D4D_ALIGN_V_CENTER_MASK)};
    D4D_STR_PROPERTIES setting_strPrties = {D4D_LBL_FNT_PRTY_DEFAULT, (D4D_ALIGN_H_CENTER_MASK | D4D_ALIGN_V_CENTER_MASK)};
    D4D_STR_PROPERTIES icons_strPrties = {D4D_LBL_FNT_PRTY_DEFAULT, (D4D_ALIGN_H_CENTER_MASK | D4D_ALIGN_V_CENTER_MASK)};

    D4D_LABEL value_lbl = {{value_buf, D4D_TEXT_LEN(value_buf), FONT_NUMBER_LARGE, &value_strPrties, 12, 0}};
    D4D_LABEL setting_lbl = {{setting_buf, D4D_TEXT_LEN(setting_buf), FONT_NUMBER_MEDIUM, &setting_strPrties, 12, 0}};
    D4D_LABEL icons_lbl = {{icons_buf, D4D_TEXT_LEN(icons_buf), FONT_ICON, &icons_strPrties, 6, 0}};

    D4D_OBJECT_DATA valueData = {((D4D_OBJECT_F_VISIBLE | D4D_OBJECT_F_NOTINIT) & D4D_OBJECT_F_SYSTEM_MASK), NULL};
    D4D_OBJECT_DATA settingData = {((D4D_OBJECT_F_VISIBLE | D4D_OBJECT_F_NOTINIT) & D4D_OBJECT_F_SYSTEM_MASK), NULL};
    D4D_OBJECT_DATA iconsData = {((D4D_OBJECT_F_VISIBLE | D4D_OBJECT_F_NOTINIT) & D4D_OBJECT_F_SYSTEM_MASK), NULL};

    D4D_OBJECT value;
    D4D_OBJECT setting;
    D4D_OBJECT icons;

public:
    ProcessValueWidgetBase(WidgetWrapper& myWrapper);
    virtual ~ProcessValueWidgetBase() = default;

    void
    setValue(std::string&& buf)
    {
        setAndEnable(&value, std::move(buf));
    }

    void
    setSetting(std::string&& buf)
    {
        setAndEnable(&setting, std::move(buf));
    }

    void
    setIcons(std::string&& buf)
    {
        setAndEnable(&icons, std::move(buf));
    }

    void
    setDisconnected()
    {
        setIcons("\0x20f");
        D4D_EnableObject(&setting, false);
        D4D_EnableObject(&icons, false);
        D4D_EnableObject(&value, false);
        enableBackground(false);
    }

    void
    setConnected()
    {
        D4D_EnableObject(&setting, true);
        D4D_EnableObject(&icons, true);
        D4D_EnableObject(&value, true);
        enableBackground(true);
        wrapper.colorScheme.bckgDis = wrapper.colorScheme.bckg;
    }
};