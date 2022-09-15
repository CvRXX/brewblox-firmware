#include "blox_hal/hal_network.hpp"
#include "fonts/fonts.hpp"
#include "lvgl.h"
#include "lvgl_helpers.hpp"
#include "styles.hpp"
#include <ctime>
#include <string>

class Bar {

public:
    Bar(lv_obj_t* mainContainer)
        : barObj(lv_obj_create(mainContainer))
        , networkLabel(lv_label_create(barObj))
        , timeLabel(lv_label_create(barObj))
    {
        lv_obj_clear_flag(barObj, LV_OBJ_FLAG_SCROLLABLE);
        lv_obj_set_size(barObj, 480, 22);
        lv_obj_add_style(barObj, &style::bar, 0);
        lv_obj_align(networkLabel, LV_ALIGN_LEFT_MID, 5, 0);
        lv_obj_align(timeLabel, LV_ALIGN_RIGHT_MID, -5, 0);
    }

    ~Bar()
    {
        lv_obj_del(barObj);
    }

    void updateTime()
    {
        static char time[10] = "00:00:00";
        struct timeval tv;
        time_t nowtime;
        struct tm* nowtm;

        gettimeofday(&tv, nullptr);
        nowtime = tv.tv_sec;
        nowtm = localtime(&nowtime);
        snprintf(time, 10, "%02d:%02d:%02d", nowtm->tm_hour, nowtm->tm_min, nowtm->tm_sec);
        update_label(this->timeLabel, time);
    }

    void updateNetworks()
    {
        // TODO(elco) use flex row so icons and ip are separate labels
        // This avoids rewriting ip string when wifi strength changes
        static std::string text;
        if (network::mode() == network::Mode::WIFI_PROVISIONING) {
            text = symbols::wifi_cog;
            text.append(symbols::bluetooth);
            text.append(" provisioning");
        } else {
            if (network::mode() == network::Mode::ETHERNET) {
                text = symbols::ethernet;
            } else {
                auto signal = network::wifiStrength();
                if (signal < -80) {
                    text = symbols::wifi_strength1;
                } else if (signal < -70) {
                    text = symbols::wifi_strength2;
                } else if (signal < -67) {
                    text = symbols::wifi_strength3;
                } else if (signal < 0) {
                    text = symbols::wifi_strength4;
                } else {
                    text = symbols::wifi_off;
                }
            }
            text.push_back(' ');
            switch (network::state()) {
            case network::State::OFF:
                text.append(" wifi disconnected");
                break;
            case network::State::CONNECTED:
                text.append(network::ip4string());
                break;
            case network::State::NOT_FOUND:
                text.append(" wifi unavailable");
                break;
            case network::State::NETWORK_ERROR:
                text.append(" wifi error");
                break;
            }
        }
        update_label(networkLabel, text.c_str());
    }

    void update()
    {
        updateTime();
        updateNetworks();
    }

    lv_obj_t* barObj;
    lv_obj_t* networkLabel;
    lv_obj_t* timeLabel;
};
