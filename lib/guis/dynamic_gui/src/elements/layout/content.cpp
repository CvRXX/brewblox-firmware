#include "dynamic_gui/elements/layout/content.hpp"
namespace gui::dynamic_interface {

Content::Content(uint16_t weight, uint8_t layOutNodeId, std::unique_ptr<Widget> widget)
    : weight(weight)
    , layOutNodeId(layOutNodeId)
    , widget(std::move(widget))
{
}

void Content::update()
{
    widget->update();
}

uint16_t Content::getWeight() const
{
    return weight;
}

void Content::serialize(std::vector<screen_LayoutNode>& layoutNodes, std::vector<screen_ContentNode>& contentNodes, uint8_t parentId)
{
    layoutNodes.push_back({parentId, layOutNodeId, screen_LayoutNode_Type_Content, weight});
    widget->serialize(contentNodes, layOutNodeId);
}

void Content::draw(lv_obj_t* placeholder, uint16_t width, uint16_t height)
{
    widget->draw(placeholder, width, height);
}
}
