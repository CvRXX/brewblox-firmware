#pragma once
#include "./BaseWidget.hpp"
#include "blox/PidBlock.h"

/// A widget which represents a pid.
class PidWidget : public BaseWidget {
public:
    /**
     * Constructs the widget
     * @param grid The grid placeholder in which the widget will be placed.
     * @param ptr A cboxPtr to the object the widget represents.
     * @param label The user set label of the object.
     * @param color The background color of the widget.
     */
    PidWidget(lv_obj_t* grid, cbox::CboxPtr<PidBlock>&& ptr, const char* label, lv_color_t color)
        : BaseWidget(grid, color)
        , lookup(ptr)
    {
        makeObj(label);
    }

    PidWidget(const PidWidget&) = delete;
    PidWidget& operator=(const PidWidget&) = delete;

    ~PidWidget()
    {
        lv_obj_del(obj);
    }

    /// Updates the widget with information from the object it's representing.
    void update()
    {
        if (auto ptr = lookup.const_lock()) {

            setPBar(int32_t(ptr->get().p()));
            setIBar(int32_t(ptr->get().i()));
            setDBar(int32_t(ptr->get().d()));

            auto& inputLookup = ptr->getInputLookup();
            auto& outputLookup = ptr->getOutputLookup();
            auto input = inputLookup.const_lock();
            if (input && input->valueValid()) {
                setInputValue(temp_to_string(input->value(), 1, tempUnit));
            } else {
                setInputValue("-");
            }
            if (input && input->settingValid()) {
                setInputSetting(temp_to_string(input->setting(), 1, tempUnit));
            } else {
                setInputSetting("-");
            }

            auto output = outputLookup.const_lock();
            if (output && output->valueValid()) {
                setOutputValue(temp_to_string(output->value(), 1, tempUnit));
            } else {
                setOutputValue("-");
            }
            if (output && output->settingValid()) {
                setOutputSetting(temp_to_string(output->setting(), 1, tempUnit));
            } else {
                setOutputSetting("-");
            }

            setLed(ptr->get().active());

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
    }

    /**
     * Sets the input value of the widget.
     * @param txt The input value text.
     */
    void setInputValue(const std::string& txt)
    {
        lv_label_set_text(inputValue, txt.c_str());
        lv_obj_align(inputValue, nullptr, LV_ALIGN_CENTER, -40, -30);
    }

    /**
     * Sets the input setting of the widget.
     * @param txt The input setting text.
     */
    void setInputSetting(const std::string& txt)
    {
        lv_label_set_text(inputSetting, txt.c_str());
        lv_obj_align(inputSetting, nullptr, LV_ALIGN_CENTER, -40, -52);
    }

    /**
     * Sets the output value of the widget.
     * @param txt The output value text.
     */
    void setOutputValue(const std::string& txt)
    {
        lv_label_set_text(outputValue, txt.c_str());
        lv_obj_align(outputValue, nullptr, LV_ALIGN_CENTER, 40, -30);
    }

    /**
     * Sets the output setting of the widget.
     * @param txt The output setting text.
     */
    void setOutputSetting(const std::string& txt)
    {
        lv_label_set_text(outputSetting, txt.c_str());
        lv_obj_align(outputSetting, nullptr, LV_ALIGN_CENTER, 40, -52);
    }

    /**
     * Sets the proportional value bar of the widget.
     * @param fillWidth The fill width of the bar. 
     * Positive values will cause the bar to go right, negative values will cause it to go left.
     */
    void setPBar(int32_t fillWidth)
    {
        lv_bar_set_value(pBar, fillWidth, LV_ANIM_ON);
    }

    /**
     * Sets the integral value bar of the widget.
     * @param fillWidth The fill width of the bar. 
     * Positive values will cause the bar to go right, negative values will cause it to go left.
     */
    void setIBar(int32_t fillWidth)
    {
        lv_bar_set_value(iBar, fillWidth, LV_ANIM_ON);
    }

    /**
     * Sets the derivative value bar of the widget.
     * @param fillWidth The fill width of the bar. 
     * Positive values will cause the bar to go right, negative values will cause it to go left.
     */
    void setDBar(int32_t fillWidth)
    {
        lv_bar_set_value(dBar, fillWidth, LV_ANIM_ON);
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
    void makeObj(const char* labelTxt)
    {
        label = lv_label_create(obj, nullptr);
        lv_label_set_text(label, labelTxt);
        lv_obj_align(label, nullptr, LV_ALIGN_CENTER, 0, 47);
        lv_label_set_align(label, LV_LABEL_ALIGN_CENTER);
        lv_obj_add_style(label, LV_LABEL_PART_MAIN, &style::block_text);

        inputValue = lv_label_create(obj, nullptr);
        setInputValue("-");
        lv_obj_set_style_local_text_font(inputValue, LV_OBJ_PART_MAIN, LV_STATE_DEFAULT, &fonts::main_20);
        lv_label_set_align(inputValue, LV_LABEL_ALIGN_CENTER);

        inputSetting = lv_label_create(obj, nullptr);
        setInputSetting("-");
        lv_obj_set_style_local_text_font(inputSetting, LV_OBJ_PART_MAIN, LV_STATE_DEFAULT, &fonts::main_20);
        lv_label_set_align(inputSetting, LV_LABEL_ALIGN_CENTER);

        outputValue = lv_label_create(obj, nullptr);
        setOutputValue("-");
        lv_obj_set_style_local_text_font(outputValue, LV_OBJ_PART_MAIN, LV_STATE_DEFAULT, &fonts::main_20);
        lv_label_set_align(outputValue, LV_LABEL_ALIGN_CENTER);

        outputSetting = lv_label_create(obj, nullptr);
        setOutputSetting("-");
        lv_obj_set_style_local_text_font(outputSetting, LV_OBJ_PART_MAIN, LV_STATE_DEFAULT, &fonts::main_20);
        lv_label_set_align(outputSetting, LV_LABEL_ALIGN_CENTER);

        pBar = lv_bar_create(obj, nullptr);
        lv_obj_set_size(pBar, 100, 10);
        lv_bar_set_type(pBar, LV_BAR_TYPE_SYMMETRICAL);
        lv_bar_set_range(pBar, -100, 100);
        lv_obj_align(pBar, nullptr, LV_ALIGN_CENTER, 0, -5);
        lv_bar_set_anim_time(pBar, 2000);
        lv_bar_set_value(pBar, 0, LV_ANIM_OFF);

        iBar = lv_bar_create(obj, nullptr);
        lv_obj_set_size(iBar, 100, 10);
        lv_bar_set_type(iBar, LV_BAR_TYPE_SYMMETRICAL);
        lv_bar_set_range(iBar, -100, 100);
        lv_obj_align(iBar, nullptr, LV_ALIGN_CENTER, 0, 10);
        lv_bar_set_anim_time(iBar, 2000);
        lv_bar_set_value(iBar, 0, LV_ANIM_OFF);

        dBar = lv_bar_create(obj, nullptr);
        lv_obj_set_size(dBar, 100, 10);
        lv_bar_set_type(dBar, LV_BAR_TYPE_SYMMETRICAL);
        lv_bar_set_range(dBar, -100, 100);
        lv_obj_align(dBar, nullptr, LV_ALIGN_CENTER, 0, 25);
        lv_bar_set_anim_time(dBar, 2000);
        lv_bar_set_value(dBar, 0, LV_ANIM_OFF);

        led = lv_led_create(obj, nullptr);
        lv_obj_set_size(led, 16, 16);
        lv_obj_align(led, nullptr, LV_ALIGN_CENTER, 0, -41);

        if (this->getRed() > (255 / 2)) {
            lv_obj_set_style_local_bg_color(pBar, LV_BAR_PART_INDIC, LV_STATE_DEFAULT, LV_COLOR_BLACK);
            lv_obj_set_style_local_bg_color(iBar, LV_BAR_PART_INDIC, LV_STATE_DEFAULT, LV_COLOR_BLACK);
            lv_obj_set_style_local_bg_color(dBar, LV_BAR_PART_INDIC, LV_STATE_DEFAULT, LV_COLOR_BLACK);
        }

        lv_obj_set_style_local_text_color(label, LV_LABEL_PART_MAIN, LV_STATE_DEFAULT, textColor);
        lv_obj_set_style_local_text_color(inputValue, LV_LABEL_PART_MAIN, LV_STATE_DEFAULT, textColor);
        lv_obj_set_style_local_text_color(inputSetting, LV_LABEL_PART_MAIN, LV_STATE_DEFAULT, textColor);
        lv_obj_set_style_local_text_color(outputValue, LV_LABEL_PART_MAIN, LV_STATE_DEFAULT, textColor);
        lv_obj_set_style_local_text_color(outputSetting, LV_LABEL_PART_MAIN, LV_STATE_DEFAULT, textColor);
    }
    lv_obj_t* label;
    lv_obj_t* inputValue;
    lv_obj_t* inputSetting;
    lv_obj_t* outputValue;
    lv_obj_t* outputSetting;
    lv_obj_t* pBar;
    lv_obj_t* iBar;
    lv_obj_t* dBar;
    lv_obj_t* led;

    cbox::CboxPtr<PidBlock> lookup;
};