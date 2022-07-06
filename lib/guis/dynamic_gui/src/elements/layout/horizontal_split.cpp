#include "dynamic_gui/elements/layout/horizontal_split.hpp"
namespace gui::dynamic_interface {

HorizontalSplit::HorizontalSplit(std::vector<std::unique_ptr<LayoutNode>>&& children, uint16_t weight, uint8_t layOutNodeId)
    : children(std::move(children))
    , weight(weight)
    , layOutNodeId(layOutNodeId)
{
}

void HorizontalSplit::serialize(std::vector<screen_LayoutNode>& layoutNodes, std::vector<screen_ContentNode>& contentNodes, uint8_t parentId)
{
    layoutNodes.push_back({parentId, layOutNodeId, screen_LayoutNode_Type_Row, weight});
    for (auto& child : children) {
        child->serialize(layoutNodes, contentNodes, layOutNodeId);
    }
}

void HorizontalSplit::update()
{
    for (auto& child : children) {
        child->update();
    }
}

uint16_t HorizontalSplit::getWeight() const
{
    return weight;
}

void HorizontalSplit::draw(lv_obj_t* placeholder, uint16_t width, uint16_t height)
{
    lv_obj_set_style_pad_gap(placeholder, 0, 0);
    lv_obj_set_style_pad_all(placeholder, 0, 0);
    lv_obj_set_style_border_width(placeholder, 0, 0);

    const auto weightTotal = std::accumulate(children.begin(), children.end(), uint16_t(0), [](uint16_t sum, const auto& child) -> uint16_t {
        return sum + child->getWeight();
    });

    uint32_t startingY = 0;
    for (auto& child : children) {
        const auto elementHeight = (height / weightTotal) * child->getWeight();

        auto newPlaceholder = LvglObjectWrapper(lv_obj_create(placeholder));
        lv_obj_set_size(newPlaceholder.get(), width, elementHeight);
        lv_obj_set_style_pad_all(newPlaceholder.get(), 2, 0);
        lv_obj_set_style_border_width(newPlaceholder.get(), 0, 0);
        lv_obj_set_style_radius(newPlaceholder.get(), 0, 0);
        lv_obj_set_pos(newPlaceholder.get(), 0, startingY);
        startingY += elementHeight;
        child->draw(newPlaceholder.get(), width, elementHeight);
        placeholders.push_back(std::move(newPlaceholder));
    }
}
}
