#pragma once

#include "../lvgl_helpers.hpp"
#include "./BaseWidget.hpp"
#include "blocks/ActuatorPwmBlock.hpp"
#include "lvgl.h"

/// A widget which represents an analog actuator.
class ActuatorAnalogWidget : public BaseWidget {
public:
    /**
     * Constructs the widget
     * @param grid The grid in which the widget will be placed.
     * @param ptr A cboxPtr to the object the widget represents.
     * @param label The user set label of the object.
     * @param color The background color of the widget.
     */
    ActuatorAnalogWidget(lv_obj_t* grid, uint8_t row, uint8_t col, cbox::CboxPtr<ActuatorAnalogConstrained>&& ptr, const char* label, lv_color_t color)
        : BaseWidget(grid, row, col, label, color)
        , lookup(std::move(ptr))
    {
        value = lv_label_create(obj);
        lv_obj_add_style(value, &style::number_large, 0);
        lv_obj_align(value, LV_ALIGN_CENTER, 0, 0);

        setting = lv_label_create(obj);
        lv_obj_add_style(setting, &style::number_medium, 0);

        lv_obj_align(setting, LV_ALIGN_CENTER, 0, -40);
    }

    virtual ~ActuatorAnalogWidget()
    {
    }

    /// Updates the widget with information from the object it's representing.
    void update()
    {
        if (auto pAct = lookup.lock()) {
            if (auto val = pAct->value()) {
                setValue(temp_to_string(*val, 2, tempUnit));
            } else {
                setValue("-");
            }
            if (auto val = pAct->setting()) {
                setSetting(temp_to_string(*val, 2, tempUnit));

            } else {
                setSetting("-");
            }

            // if (auto pwmBlock = lookup.lock_as<ActuatorPwmBlock>()) {
            //     lv_obj_set_hidden(led, false);
            //     if (auto pwmTarget = pwmBlock->targetLookup().lock()) {
            //         switch (pwmTarget->state()) {
            //         case ActuatorPwm::State::Inactive:
            //             setLed(false);
            //             break;
            //         case ActuatorPwm::State::Active:
            //         case ActuatorPwm::State::Reverse:
            //             setLed(true);
            //             break;
            //         case ActuatorPwm::State::Unknown:
            //             lv_obj_set_hidden(led, true);
            //             break;
            //         }
            //     }
            // } else {
            //     lv_obj_set_hidden(led, true);
            // }
        }
    }

    /**
     * Sets the value of the widget.
     * @param txt The value text.
     */
    void setValue(const std::string& txt)
    {
        update_label(value, txt.c_str());
        lv_obj_align(value, LV_ALIGN_CENTER, 0, 0);
    }

    /**
     * Sets the setting of the widget.
     * @param txt The setting text.
     */
    void setSetting(const std::string& txt)
    {
        update_label(setting, txt.c_str());
        lv_obj_align(setting, LV_ALIGN_CENTER, 0, -40);
    }

private:
    cbox::CboxPtr<ActuatorAnalogConstrained> lookup;
    lv_obj_t* value = nullptr;
    lv_obj_t* setting = nullptr;
};
