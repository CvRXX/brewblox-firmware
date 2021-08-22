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
        : BaseWidget(grid, label, color)
        , lookup(ptr)
    {
        inputValue = lv_label_create(obj, nullptr);
        setInputValue("-");
        lv_obj_set_style_local_text_font(inputValue, LV_OBJ_PART_MAIN, LV_STATE_DEFAULT, &fonts::numbers_medium);
        lv_label_set_align(inputValue, LV_LABEL_ALIGN_CENTER);

        inputSetting = lv_label_create(obj, nullptr);
        setInputSetting("-");
        lv_obj_set_style_local_text_font(inputSetting, LV_OBJ_PART_MAIN, LV_STATE_DEFAULT, &fonts::numbers_medium);
        lv_label_set_align(inputSetting, LV_LABEL_ALIGN_CENTER);

        outputValue = lv_label_create(obj, nullptr);
        setOutputValue("-");
        lv_obj_set_style_local_text_font(outputValue, LV_OBJ_PART_MAIN, LV_STATE_DEFAULT, &fonts::numbers_medium);
        lv_label_set_align(outputValue, LV_LABEL_ALIGN_CENTER);

        outputSetting = lv_label_create(obj, nullptr);
        setOutputSetting("-");
        lv_obj_set_style_local_text_font(outputSetting, LV_OBJ_PART_MAIN, LV_STATE_DEFAULT, &fonts::numbers_medium);
        lv_label_set_align(outputSetting, LV_LABEL_ALIGN_CENTER);

        pidValues = lv_cont_create(obj, nullptr);
        pLabel = lv_label_create(pidValues, nullptr);
        lv_label_set_text(pLabel, "P ");
        pValue = lv_label_create(pidValues, nullptr);
        lv_label_set_text(pValue, "100");
        iLabel = lv_label_create(pidValues, nullptr);
        lv_label_set_text(iLabel, "I");
        iValue = lv_label_create(pidValues, nullptr);
        lv_label_set_text(iValue, "80");
        dLabel = lv_label_create(pidValues, nullptr);
        lv_label_set_text(dLabel, "D");
        dValue = lv_label_create(pidValues, nullptr);
        lv_label_set_text(dValue, "-10");

        lv_obj_set_auto_realign(pidValues, true);
        lv_obj_align_origo(pidValues, nullptr, LV_ALIGN_CENTER, 0, 0);
        lv_cont_set_fit(pidValues, LV_FIT_TIGHT);
        lv_cont_set_layout(pidValues, LV_LAYOUT_ROW_MID);

        // lv_obj_add_style(pidValues, LV_OBJ_PART_MAIN, LV_STATE_DEFAULT, &fonts::main);
        // lv_label_set_align(pidValues, LV_LABEL_ALIGN_CENTER);
    }

    virtual ~PidWidget()
    {
    }

    /// Updates the widget with information from the object it's representing.
    void update()
    {
        if (auto ptr = lookup.const_lock()) {

            // setPBar(int32_t(ptr->get().p()));
            // setIBar(int32_t(ptr->get().i()));
            // setDBar(int32_t(ptr->get().d()));

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

            updatePidValues(to_string_dec(ptr->get().p(), 0), to_string_dec(ptr->get().i(), 0), to_string_dec(ptr->get().d(), 0));

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

    void updatePidValues(const std::string& p, const std::string& i, const std::string& d)
    {
        std::string v = "P: ";
        v.append(p);
        v.append("  I: ");
        v.append(i);
        v.append("  D: ");
        v.append(d);
        lv_label_set_text(pidValues, v.c_str());
        lv_obj_align(pidValues, nullptr, LV_ALIGN_CENTER, 0, 30);
    }

private:
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

    cbox::CboxPtr<PidBlock> lookup;
};
