#include "dynamic_gui/decode.hpp"

namespace gui::dynamic_interface {

tl::expected<Screen, DecodeError> testScreen()
{
    std::vector<blox_ScreenConfig_LayoutNode> layoutNodes;
    layoutNodes.push_back({1, 2, blox_ScreenConfig_Type_Content, 1});
    layoutNodes.push_back({0, 1, blox_ScreenConfig_Type_Row, 1});
    layoutNodes.push_back({1, 3, blox_ScreenConfig_Type_Column, 1});
    layoutNodes.push_back({3, 4, blox_ScreenConfig_Type_Content, 1});
    layoutNodes.push_back({3, 5, blox_ScreenConfig_Type_Content, 1});

    std::vector<blox_ScreenConfig_ContentNode> contentNodes;
    auto numericValueWidget1 = blox_ScreenConfig_NumericValueWidget{blox_ScreenConfig_Color{0, 255, 0}, 99, "proto"};
    auto node1 = blox_ScreenConfig_ContentNode{2, blox_ScreenConfig_ContentNode_numericValueWidget_tag, numericValueWidget1};
    contentNodes.push_back(node1);

    auto numericValueWidget2 = blox_ScreenConfig_NumericValueWidget{blox_ScreenConfig_Color{0, 255, 0}, 99, "proto"};
    auto node2 = blox_ScreenConfig_ContentNode{5, blox_ScreenConfig_ContentNode_numericValueWidget_tag, numericValueWidget2};
    contentNodes.push_back(node2);

    return decodeNodes(layoutNodes, contentNodes);
}
}
