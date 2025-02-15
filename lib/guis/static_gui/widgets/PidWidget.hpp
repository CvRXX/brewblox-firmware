#pragma once
#include "./BaseWidget.hpp"
#include "blocks/PidBlock.hpp"

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
    PidWidget(lv_obj_t* grid, uint8_t row, uint8_t col, cbox::CboxPtr<PidBlock>&& ptr, const char* label, lv_color_t color)
        : BaseWidget(grid, row, col, label, color)
        , lookup(std::move(ptr))
        , inputValue(lv_label_create(obj))
        , inputSetting(lv_label_create(obj))
        , outputValue(lv_label_create(obj))
        , outputSetting(lv_label_create(obj))
        , pLabel(lv_label_create(obj))
        , pValue(lv_label_create(obj))
        , iLabel(lv_label_create(obj))
        , iValue(lv_label_create(obj))
        , dLabel(lv_label_create(obj))
        , dValue(lv_label_create(obj))
        , arrowInput(lv_label_create(obj))
        , arrowOutput(lv_label_create(obj))
        , inputLabel(lv_label_create(obj))
        , outputLabel(lv_label_create(obj))
    {
        constexpr int inputY = -40;
        constexpr int outputY = -3;
        constexpr int leftX = -40;
        constexpr int rightX = 40;
        constexpr int pidValuesY = 34;

        lv_obj_add_style(inputValue, &style::number_medium, LV_PART_MAIN);
        lv_label_set_text(inputValue, "-");
        lv_obj_align(inputValue, LV_ALIGN_CENTER, leftX, inputY);

        lv_label_set_text(inputSetting, "-");
        lv_obj_add_style(inputSetting, &style::number_medium, LV_PART_MAIN);
        lv_obj_align(inputSetting, LV_ALIGN_CENTER, rightX, inputY);

        lv_label_set_text(outputValue, "-");
        lv_obj_add_style(outputValue, &style::number_medium, LV_PART_MAIN);
        lv_obj_align(outputValue, LV_ALIGN_CENTER, leftX, outputY);

        lv_label_set_text(outputSetting, "-");
        lv_obj_add_style(outputSetting, &style::number_medium, LV_PART_MAIN);
        lv_obj_align(outputSetting, LV_ALIGN_CENTER, rightX, outputY);

        lv_label_set_text(inputLabel, "input");
        lv_label_set_text(outputLabel, "output");
        lv_obj_add_style(inputLabel, &style::field_label, LV_PART_MAIN);
        lv_obj_add_style(outputLabel, &style::field_label, LV_PART_MAIN);
        lv_obj_align(inputLabel, LV_ALIGN_CENTER, 0, inputY - 18);
        lv_obj_align(outputLabel, LV_ALIGN_CENTER, 0, outputY - 18);

        lv_label_set_text(arrowInput, symbols::arrow_thick_right);
        lv_obj_align(arrowInput, LV_ALIGN_CENTER, 0, inputY);
        lv_label_set_text(arrowOutput, symbols::arrow_thick_right);
        lv_obj_align(arrowOutput, LV_ALIGN_CENTER, 0, outputY);

        lv_label_set_text(pLabel, "P");
        lv_label_set_text(iLabel, "I");
        lv_label_set_text(dLabel, "D");
        lv_obj_add_style(pLabel, &style::field_label, LV_PART_MAIN);
        lv_obj_add_style(iLabel, &style::field_label, LV_PART_MAIN);
        lv_obj_add_style(dLabel, &style::field_label, LV_PART_MAIN);

        lv_label_set_text(pValue, "0");
        lv_label_set_text(iValue, "0");
        lv_label_set_text(dValue, "0");

        lv_obj_align(pLabel, LV_ALIGN_CENTER, -40, pidValuesY - 16);
        lv_obj_align(pValue, LV_ALIGN_CENTER, -40, pidValuesY);
        lv_obj_align(iLabel, LV_ALIGN_CENTER, 0, pidValuesY - 16);
        lv_obj_align(iValue, LV_ALIGN_CENTER, 0, pidValuesY);
        lv_obj_align(dLabel, LV_ALIGN_CENTER, 40, pidValuesY - 16);
        lv_obj_align(dValue, LV_ALIGN_CENTER, 40, pidValuesY);
    }

    virtual ~PidWidget()
    {
    }

    /// Updates the widget with iinputValuenformation from the object it's representing.
    void update()
    {
        if (auto ptr = lookup.lock()) {
            lv_obj_clear_state(obj, LV_STATE_DISABLED);
            auto& inputLookup = ptr->getInputLookup();
            auto& outputLookup = ptr->getOutputLookup();
            auto input = inputLookup.lock();
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

            auto output = outputLookup.lock();
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
            lv_obj_add_state(obj, LV_STATE_DISABLED);
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
    lv_obj_t* arrowInput;
    lv_obj_t* arrowOutput;
    lv_obj_t* inputLabel;
    lv_obj_t* outputLabel;
};
