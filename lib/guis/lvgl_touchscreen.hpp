
template<typename Touchscreen>
class LvglTouchscreen {
    public:

    static void checkForTouches(lv_indev_drv_t* drv, lv_indev_data_t* data)
    {
        if (auto touch = touchscreen->getTouch()) {
            data->point.x = touch->x;
            data->point.y = touch->y;
            data->state = LV_INDEV_STATE_PR;
        } else {
            auto lastTouch = touchscreen->getLastTouch();
            data->point.x = lastTouch.x;
            data->point.y = lastTouch.y;
            data->state = LV_INDEV_STATE_REL;
        }
    }

    static void init()
    {
        lv_indev_drv_init(&indev_drv);
        indev_drv.type = LV_INDEV_TYPE_POINTER;
        indev_drv.read_cb = checkForTouches;
        touchscreen = std::make_unique<Touchscreen>(0x00);
        touchscreen->init();
    }
    static lv_indev_drv_t indev_drv;
    static std::unique_ptr<Touchscreen> touchscreen;

private:


};
template <typename Touchscreen>
std::unique_ptr<Touchscreen> LvglTouchscreen<Touchscreen>::touchscreen;

template <typename Touchscreen>
lv_indev_drv_t LvglTouchscreen<Touchscreen>::indev_drv;

