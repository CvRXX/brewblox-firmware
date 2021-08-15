#pragma once

#include "./BaseWidget.hpp"
#include "blox/ActuatorPwmBlock.h"
#include "lvgl.h"

/// A widget which represents an analog actuator.
class ActuatorAnalogWidget : public BaseWidget {
public:
    /**
     * Constructs the widget
     * @param grid The grid placeholder in which the widget will be placed.
     * @param ptr A cboxPtr to the object the widget represents.
     * @param label The user set label of the object.
     * @param color The background color of the widget.
     */
    ActuatorAnalogWidget(lv_obj_t* grid, cbox::CboxPtr<ActuatorAnalogConstrained>&& ptr, const char* label, lv_color_t color)
        : BaseWidget(grid, color)
        , lookup(ptr)
    {
        makeObj(grid, label, "-", "-");
    }

    ActuatorAnalogWidget(const ActuatorAnalogWidget&) = delete;
    ActuatorAnalogWidget& operator=(const ActuatorAnalogWidget&) = delete;

    ~ActuatorAnalogWidget()
    {
        lv_obj_del(obj);
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

            if (auto pwmBlock = lookup.lock_as<ActuatorPwmBlock>()) {
                lv_obj_set_hidden(led, false);
                if (auto pwmTarget = pwmBlock->targetLookup().const_lock()) {
                    switch (pwmTarget->state()) {
                    case ActuatorPwm::State::Inactive:
                        setLed(false);
                        break;
                    case ActuatorPwm::State::Active:
                        setLed(true);
                        break;
                    case ActuatorPwm::State::Unknown:
                        lv_obj_set_hidden(led, true);
                        break;
                    }
                }
            } else {
                lv_obj_set_hidden(led, true);
            }

            return;
        }
    }

    /**
     * Sets the label of the widget.
     * @param txt The label text.
     */
    void setLabel(const std::string& txt)
    {
        lv_label_set_text(label, txt.c_str());
        lv_obj_align(label, nullptr, LV_ALIGN_CENTER, 0, 50);
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

    /**
     * Sets the led of the widget. This will turn the led on or off.
     * @param state If the led should be on or off.
     */
    void setLed(bool state)
    {
        state ? lv_led_on(led) : lv_led_off(led);
    }

private:
    void makeObj(lv_obj_t* grid, const char* labelTxt, const char* valueTxt, const char* settingTxt)
    {
        label = lv_label_create(obj, nullptr);
        lv_obj_reset_style_list(label, LV_LABEL_PART_MAIN);
        lv_obj_add_style(label, LV_LABEL_PART_MAIN, &style::block_text);
        lv_label_set_align(label, LV_LABEL_ALIGN_CENTER);
        setLabel(labelTxt);

        value = lv_label_create(obj, nullptr);
        setValue(valueTxt);
        lv_obj_reset_style_list(value, LV_LABEL_PART_MAIN);
        lv_obj_add_style(value, LV_LABEL_PART_MAIN, &style::bigNumber_text);
        lv_label_set_align(value, LV_LABEL_ALIGN_CENTER);

        setting = lv_label_create(obj, nullptr);
        setSetting(settingTxt);
        lv_obj_reset_style_list(setting, LV_LABEL_PART_MAIN);
        lv_obj_add_style(setting, LV_LABEL_PART_MAIN, &style::block_text);
        lv_label_set_align(setting, LV_LABEL_ALIGN_CENTER);

        led = lv_led_create(obj, nullptr);
        lv_obj_set_size(led, 16, 16);
        lv_obj_align(led, nullptr, LV_ALIGN_CENTER, 00, 30);

        lv_obj_set_style_local_text_color(label, LV_LABEL_PART_MAIN, LV_STATE_DEFAULT, textColor);
        lv_obj_set_style_local_text_color(value, LV_LABEL_PART_MAIN, LV_STATE_DEFAULT, textColor);
        lv_obj_set_style_local_text_color(setting, LV_LABEL_PART_MAIN, LV_STATE_DEFAULT, textColor);
    }

    cbox::CboxPtr<ActuatorAnalogConstrained> lookup;
    lv_obj_t* led;
    lv_obj_t* label;
    lv_obj_t* value;
    lv_obj_t* setting;
};