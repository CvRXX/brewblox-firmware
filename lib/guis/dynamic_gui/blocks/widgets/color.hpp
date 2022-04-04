#include "dynamic_gui/blocks/core/block.hpp"
class Color : public Block {
public:
    Color(uint8_t r, uint8_t g, uint8_t b)
        : r(r)
        , g(g)
        , b(b)
    {
    }

    void update() override
    {
    }

    void draw(lv_obj_t* placeholder) override
    {
        lv_obj_set_style_bg_color(placeholder, lv_color_make(r, g, b), LV_STATE_DEFAULT);
    }

    const uint8_t r;
    const uint8_t g;
    const uint8_t b;
};
