#include "blox_hal/hal_network.hpp"
#include "fonts/fonts.hpp"
#include "lvgl.h"
#include "styles.hpp"
#include <ctime>
#include <string>

class Bar {

public:
    Bar(lv_obj_t* mainContainer)
        : barObj(lv_obj_create(mainContainer))
        , networksLabel(lv_label_create(barObj))
        , timeLabel(lv_label_create(barObj))
    {
        lv_obj_clear_flag(barObj, LV_OBJ_FLAG_SCROLLABLE);
        lv_obj_set_size(barObj, 480, 22);
        lv_obj_add_style(barObj, &style::bar, 0);
        lv_obj_align(networksLabel, LV_ALIGN_LEFT_MID, 0, 0);

        lv_label_set_text(this->timeLabel, time);
        lv_obj_align(timeLabel, LV_ALIGN_RIGHT_MID, -5, 0);
    }

    ~Bar()
    {
        lv_obj_del(barObj);
    }

    void updateTime()
    {
        struct timeval tv;
        time_t nowtime;
        struct tm* nowtm;

        gettimeofday(&tv, nullptr);
        nowtime = tv.tv_sec;
        nowtm = localtime(&nowtime);
        strftime(time, sizeof(time), "%H:%M:%S", nowtm);
        lv_label_set_text(this->timeLabel, time);
    }

    void updateNetworks()
    {
        std::string networkState = " ";
        if (network::mode() == network::Mode::WIFI_PROVISIONING) {
            networkState.append(symbols::wifi_cog);
            networkState.append(symbols::bluetooth);
            networkState.append(" provisioning");

        } else {
            if (network::mode() == network::Mode::ETHERNET) {
                networkState.append(symbols::ethernet);
                networkState.push_back(' ');
            } else {
                auto signal = network::wifiStrength();
                if (signal < -80) {
                    networkState.append(symbols::wifi_strength1);
                } else if (signal < -70) {
                    networkState.append(symbols::wifi_strength2);
                } else if (signal < -67) {
                    networkState.append(symbols::wifi_strength3);
                } else if (signal < 0) {
                    networkState.append(symbols::wifi_strength4);
                } else {
                    networkState.append(symbols::wifi_off);
                }
            }
            networkState.push_back(' ');
            switch (network::state()) {
            case network::State::OFF:
                networkState.append("Network off");
                break;
            case network::State::CONNECTED:
                networkState.append(formatIp(network::ip4()));
                break;
            case network::State::NOT_FOUND:
                networkState.append("WiFi not found");
                break;
            case network::State::NETWORK_ERROR:
                networkState.append("WiFi error");
                break;
            }
        }

        lv_label_set_text(this->networksLabel, networkState.c_str());
    }

    void update()
    {
        updateTime();
        updateNetworks();
    }

    static std::string formatIp(uint32_t ip)
    {
        return std::to_string((ip >> (8 * 0)) & 0xff) + "." + std::to_string((ip >> (8 * 1)) & 0xff) + "." + std::to_string((ip >> (8 * 2)) & 0xff) + "." + std::to_string((ip >> (8 * 3)) & 0xff);
    }

    char time[10] = "00:00:00";
    lv_obj_t* barObj;
    lv_obj_t* networksLabel;
    lv_obj_t* timeLabel;
};
