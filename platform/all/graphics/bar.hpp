#include "fonts/fonts.hpp"
#include "lvgl.h"
#include "network/ethernet.hpp"
#include "network/wifi.hpp"
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
        std::string networks;
        if (wifi::isConnected()) {
            networks.push_back(' ');
            auto rssi = wifi::getRssi();
            if (rssi < -80) {
                networks.append(symbols::wifi_strength1);
            } else if (rssi < -70) {
                networks.append(symbols::wifi_strength2);
            } else if (rssi < -67) {
                networks.append(symbols::wifi_strength3);
            } else {
                networks.append(symbols::wifi_strength4);
            }
            networks.push_back(' ');
            networks.append(formatIp(wifi::ip4().addr));

        } else {
            if (!ethernet::isConnected()) {
                networks.append(symbols::wifi_off);
            }
        }

        if (ethernet::isConnected()) {
            networks.push_back(' ');
            networks.append(symbols::ethernet);
            networks.push_back(' ');
            networks.append(formatIp(ethernet::ip4().addr));
        }

        lv_label_set_text(this->networksLabel, networks.c_str());
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
