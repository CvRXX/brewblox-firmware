#pragma once
#include "./BaseWidget.hpp"
#include "blox/PidBlock.h"

/// A widget which represents a pid.
class PidWidget : public BaseWidget {
public:
    /**
     * Constructs the widget
     * @param grid The grid in which the widget will be placed.
     * @param ptr A cboxPtr to the object the widget represents.
     * @param label The user set label of the object.
     * @param color The background color of the widget.
     */
    PidWidget(lv_obj_t* grid, cbox::CboxPtr<PidBlock>&& ptr, const char* label, lv_color_t color)
        : BaseWidget(grid, label, color)
        , lookup(ptr)
        , inputValue(lv_label_create(obj, nullptr))
        , inputSetting(lv_label_create(obj, nullptr))
        , outputValue(lv_label_create(obj, nullptr))
        , outputSetting(lv_label_create(obj, nullptr))
        , pLabel(lv_label_create(obj, nullptr))
        , pValue(lv_label_create(obj, nullptr))
        , iLabel(lv_label_create(obj, nullptr))
        , iValue(lv_label_create(obj, nullptr))
        , dLabel(lv_label_create(obj, nullptr))
        , dValue(lv_label_create(obj, nullptr))
    {
        lv_obj_set_style_local_text_font(inputValue, LV_OBJ_PART_MAIN, LV_STATE_DEFAULT, &fonts::numbers_medium);
        lv_label_set_text(inputValue, "-");
        lv_obj_align(inputValue, nullptr, LV_ALIGN_CENTER, -30, -30);

        lv_label_set_text(inputSetting, "-");
        lv_obj_set_style_local_text_font(inputSetting, LV_OBJ_PART_MAIN, LV_STATE_DEFAULT, &fonts::numbers_medium);
        lv_obj_align(inputSetting, nullptr, LV_ALIGN_CENTER, -30, -52);

        lv_label_set_text(outputValue, "-");
        lv_obj_set_style_local_text_font(outputValue, LV_OBJ_PART_MAIN, LV_STATE_DEFAULT, &fonts::numbers_medium);
        lv_obj_align(outputValue, nullptr, LV_ALIGN_CENTER, 30, -30);

        lv_label_set_text(outputSetting, "-");
        lv_obj_set_style_local_text_font(outputSetting, LV_OBJ_PART_MAIN, LV_STATE_DEFAULT, &fonts::numbers_medium);
        lv_obj_align(outputSetting, nullptr, LV_ALIGN_CENTER, 30, -52);

        lv_label_set_text(pLabel, "P ");
        lv_label_set_text(iLabel, "I");
        lv_label_set_text(dLabel, "D");
        lv_label_set_text(pValue, "0");
        lv_label_set_text(iValue, "0");
        lv_label_set_text(dValue, "0");

        lv_obj_align(pLabel, nullptr, LV_ALIGN_CENTER, -40, 5);
        lv_obj_align(pValue, nullptr, LV_ALIGN_CENTER, -40, 20);
        lv_obj_align(iLabel, nullptr, LV_ALIGN_CENTER, 0, 5);
        lv_obj_align(iValue, nullptr, LV_ALIGN_CENTER, 0, 20);
        lv_obj_align(dLabel, nullptr, LV_ALIGN_CENTER, 40, 5);
        lv_obj_align(dValue, nullptr, LV_ALIGN_CENTER, 40, 20);

        lv_obj_set_auto_realign(inputValue, true);
        lv_obj_set_auto_realign(inputSetting, true);
        lv_obj_set_auto_realign(outputValue, true);
        lv_obj_set_auto_realign(outputSetting, true);
        //lv_obj_set_auto_realign(pLabel, true);
        lv_obj_set_auto_realign(pValue, true);
        //lv_obj_set_auto_realign(iLabel, true);
        lv_obj_set_auto_realign(iValue, true);
        //lv_obj_set_auto_realign(dLabel, true);
        lv_obj_set_auto_realign(dValue, true);
    }

    virtual ~PidWidget()
    {
    }

    /// Updates the widget with information from the object it's representing.
    void update()
    {
        if (auto ptr = lookup.const_lock()) {
            lv_obj_set_state(obj, LV_STATE_DEFAULT);
            auto& inputLookup = ptr->getInputLookup();
            auto& outputLookup = ptr->getOutputLookup();
            auto input = inputLookup.const_lock();
            if (input && input->valueValid()) {
                lv_label_set_text(inputValue, temp_to_string(input->value(), 1, tempUnit).c_str());
            } else {
                lv_label_set_text(inputValue, "-");
            }
            if (input && input->settingValid()) {
                lv_label_set_text(inputSetting, temp_to_string(input->setting(), 1, tempUnit).c_str());
            } else {
                lv_label_set_text(inputSetting, "-");
            }

            auto output = outputLookup.const_lock();
            if (output && output->valueValid()) {
                lv_label_set_text(outputValue, to_string_dec(output->value(), 1).c_str());
            } else {
                lv_label_set_text(outputValue, "-");
            }
            if (output && output->settingValid()) {
                lv_label_set_text(outputSetting, to_string_dec(output->setting(), 1).c_str());
            } else {
                lv_label_set_text(outputSetting, "-");
            }

            lv_label_set_text(pValue, to_string_dec(ptr->get().p(), 0).c_str());
            lv_label_set_text(iValue, to_string_dec(ptr->get().i(), 0).c_str());
            lv_label_set_text(dValue, to_string_dec(ptr->get().d(), 0).c_str());
        } else {
            lv_obj_set_state(obj, LV_STATE_DISABLED);
        }
    }

private:
    cbox::CboxPtr<PidBlock> lookup;
    lv_obj_t* inputValue;
    lv_obj_t* inputSetting;
    lv_obj_t* outputValue;
    lv_obj_t* outputSetting;
    lv_obj_t* pidValues;
    lv_obj_t* pLabel;
    lv_obj_t* pValue;
    lv_obj_t* iLabel;
    lv_obj_t* iValue;
    lv_obj_t* dLabel;
    lv_obj_t* dValue;
};
