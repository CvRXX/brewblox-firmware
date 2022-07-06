#pragma once
#include "blocks/ScreenConfig.hpp"

namespace gui::dynamic_interface {

tl::expected<Screen, DecodeError> grid()
{

    // auto& settings = ScreenConfig::settings();

    std::vector<screen_LayoutNode> layoutNodes;
    layoutNodes.push_back({0, 1, screen_LayoutNode_Type_Row, 1});
    layoutNodes.push_back({1, 2, screen_LayoutNode_Type_Column, 1});
    layoutNodes.push_back({1, 3, screen_LayoutNode_Type_Column, 1});

    layoutNodes.push_back({2, 4, screen_LayoutNode_Type_Content, 1});
    layoutNodes.push_back({2, 5, screen_LayoutNode_Type_Content, 1});
    layoutNodes.push_back({2, 6, screen_LayoutNode_Type_Content, 1});
    layoutNodes.push_back({3, 7, screen_LayoutNode_Type_Content, 1});
    layoutNodes.push_back({3, 8, screen_LayoutNode_Type_Content, 1});
    layoutNodes.push_back({3, 9, screen_LayoutNode_Type_Content, 1});

    std::vector<screen_ContentNode> contentNodes;

    // for (auto& widget : settings.widgets) {
    //     if (widget.pos != 0) {
    //         if (widget.which_WidgetType == blox_DisplaySettings_Widget_tempSensor_tag) {
    //             auto temperatureWidget = screen_TemperatureWidget{screen_Color{widget.color[0], widget.color[1], widget.color[2]}, "test", widget.WidgetType.tempSensor};
    //             strcpy(temperatureWidget.label, widget.name);
    //             screen_ContentNode node = screen_ContentNode_init_default;
    //             node.layoutNodeId = 7 - widget.pos + 3;
    //             node.which_content = screen_ContentNode_temperatureWidget_tag;
    //             node.content.temperatureWidget = temperatureWidget;
    //             contentNodes.push_back(node);
    //         }
    //     }
    // }

    return decodeNodes(std::move(layoutNodes), std::move(contentNodes));
    // return DecodeError::pbError;
}
}

// std::unique_ptr<BaseWidget> StaticGui::makeWidget(uint8_t pos)
// {
//     auto& settings = DisplaySettingsBlock::settings();
//     auto row = (pos - 1) / 3;
//     auto col = (pos - 1) % 3;

//     auto widget = std::find_if(std::begin(settings.widgets), std::end(settings.widgets), [pos](auto& widget) {
//         return widget.pos == pos;
//     });

//     if (widget != std::end(settings.widgets)) {
//         auto color = lv_color_make(widget->color[0], widget->color[1], widget->color[2]);
//         switch (widget->which_WidgetType) {
//         case blox_DisplaySettings_Widget_tempSensor_tag: {
//             auto lookup = cbox::CboxPtr<TempSensor>(cbox::obj_id_t(widget->WidgetType.tempSensor));
//             return std::unique_ptr<BaseWidget>(new TemperatureWidget(grid, row, col, std::move(lookup), widget->name, color));
//         } break;
//         case blox_DisplaySettings_Widget_setpointSensorPair_tag: {
//             auto lookup = cbox::CboxPtr<SetpointSensorPairBlock>(cbox::obj_id_t(widget->WidgetType.setpointSensorPair));
//             return std::unique_ptr<BaseWidget>(new SetpointWidget(grid, row, col, std::move(lookup), widget->name, color));
//         } break;
//         case blox_DisplaySettings_Widget_actuatorAnalog_tag: {
//             auto lookup = cbox::CboxPtr<ActuatorAnalogConstrained>(cbox::obj_id_t(widget->WidgetType.setpointSensorPair));
//             return std::unique_ptr<BaseWidget>(new ActuatorAnalogWidget(grid, row, col, std::move(lookup), widget->name, color));
//         } break;
//         case blox_DisplaySettings_Widget_pid_tag: {
//             auto lookup = cbox::CboxPtr<PidBlock>(cbox::obj_id_t(widget->WidgetType.pid));
//             return std::unique_ptr<BaseWidget>(new PidWidget(grid, row, col, std::move(lookup), widget->name, color));
//         } break;
//         }
//     }
//     return std::unique_ptr<BaseWidget>(new BaseWidget(grid, row, col, "", LV_COLOR_MAKE(0x20, 0x20, 0x20)));
// };
