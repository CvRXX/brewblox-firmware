#pragma once

#include "./BaseWidget.hpp"
#include "blox/ActuatorPwmBlock.h"
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
    ActuatorAnalogWidget(lv_obj_t* grid, cbox::CboxPtr<ActuatorAnalogConstrained>&& ptr, const char* label, lv_color_t color)
        : BaseWidget(grid, label, color)
        , lookup(ptr)
    {
        value = lv_label_create(obj, nullptr);
        lv_obj_add_style(value, LV_LABEL_PART_MAIN, &style::number_large);
        lv_obj_align(value, nullptr, LV_ALIGN_CENTER, 0, 0);
        lv_obj_set_auto_realign(value, true);

        setting = lv_label_create(obj, nullptr);
        lv_obj_add_style(setting, LV_LABEL_PART_MAIN, &style::number_medium);

        lv_obj_align(setting, nullptr, LV_ALIGN_CENTER, 0, -40);
        lv_obj_set_auto_realign(setting, true);

        // led = lv_led_create(obj, nullptr);
        // lv_obj_set_size(led, 16, 16);
        // lv_obj_align(led, nullptr, LV_ALIGN_CENTER, 00, 30);
    }

    virtual ~ActuatorAnalogWidget()
    {
    }

    /// Updates the widget with information from the object it's representing.
    void update()
    {
        if (auto pAct = lookup.const_lock()) {
            if (pAct->valueValid()) {
                setValue(temp_to_string(pAct->value(), 2, tempUnit));
            } else {
                setValue("-");
            }
            if (pAct->settingValid()) {
                setSetting(temp_to_string(pAct->setting(), 2, tempUnit));

            } else {
                setSetting("-");
            }

            // if (auto pwmBlock = lookup.lock_as<ActuatorPwmBlock>()) {
            //     lv_obj_set_hidden(led, false);
            //     if (auto pwmTarget = pwmBlock->targetLookup().const_lock()) {
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
        lv_label_set_text(value, txt.c_str());
        lv_obj_align(value, nullptr, LV_ALIGN_CENTER, 0, 0);
    }

    /**
     * Sets the setting of the widget.
     * @param txt The setting text.
     */
    void setSetting(const std::string& txt)
    {
        lv_label_set_text(setting, txt.c_str());
        lv_obj_align(setting, nullptr, LV_ALIGN_CENTER, 0, -40);
    }

private:
    cbox::CboxPtr<ActuatorAnalogConstrained> lookup;
    lv_obj_t* value = nullptr;
    lv_obj_t* setting = nullptr;
};