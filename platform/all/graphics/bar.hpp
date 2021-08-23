#include "fonts/fonts.hpp"
#include "lvgl.h"
#include "styles.hpp"
#include <ctime>
#include <string>

class Bar {

public:
    Bar(lv_obj_t* mainContainer)
        : barObj(lv_obj_create(mainContainer, nullptr))
        , label(lv_label_create(barObj, nullptr))
        , timeLabel(lv_label_create(barObj, nullptr))
    {
        lv_obj_set_size(barObj, 480, 22);
        lv_obj_add_style(barObj, LV_CONT_PART_MAIN, &style::bar);

        lv_obj_align(label, nullptr, LV_ALIGN_IN_LEFT_MID, 0, 0);

        lv_label_set_text(this->timeLabel, time);
        lv_obj_align(timeLabel, nullptr, LV_ALIGN_IN_RIGHT_MID, -5, 0);
        updateLabel();
    }

    ~Bar()
    {
        lv_obj_del(barObj);
    }

    void setEthernetIp(uint32_t ip)
    {
        this->ethernetIp = formatIp(ip);
        updateLabel();
    }

    void setWifiIp(uint32_t ip)
    {
        this->wifiIp = formatIp(ip);
        updateLabel();
    }
    void setWifiEnabled(bool enabled)
    {
        this->wifiEnabled = enabled;
        updateLabel();
    }

    void setWifiRssi(int8_t rssi)
    {
        this->rssi = rssi;
        updateLabel();
    }
    void setEthernetEnabled(bool enabled)
    {
        this->ethernetEnabled = enabled;
        updateLabel();
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

        updateLabel();
    }

private:
    void updateLabel()
    {
        std::string wifi;
        if (wifiEnabled) {
            if (rssi < -80) {
                wifi = std::string() + symbols::wifi_strength1 + " " + this->wifiIp;
            } else if (rssi < -70) {
                wifi = std::string() + symbols::wifi_strength2 + " " + this->wifiIp;
            } else if (rssi < -67) {
                wifi = std::string() + symbols::wifi_strength3 + " " + this->wifiIp;
            } else {
                wifi = std::string() + symbols::wifi_strength4 + " " + this->wifiIp;
            }

        } else {
            if (!ethernetEnabled) {
                wifi = symbols::wifi_off;
            } else {
                wifi = "";
            }
        }

        std::string ethernet;
        if (ethernetEnabled) {
            ethernet = std::string() + symbols::ethernet + " " + this->ethernetIp;
        } else {
            if (!wifiEnabled) {
                ethernet = symbols::ethernet_off;
            } else {
                ethernet = "";
            }
        }
        std::string t = std::string() + " " + ethernet + "  " + wifi;
        lv_label_set_text(this->label, t.c_str());
        lv_obj_align(label, nullptr, LV_ALIGN_IN_LEFT_MID, 0, 0);
        lv_label_set_text(this->timeLabel, time);
    }

    std::string formatIp(uint32_t ip)
    {
        return std::to_string((ip >> (8 * 0)) & 0xff) + "." + std::to_string((ip >> (8 * 1)) & 0xff) + "." + std::to_string((ip >> (8 * 2)) & 0xff) + "." + std::to_string((ip >> (8 * 3)) & 0xff);
    }

    std::string ethernetIp = "xx.xx.xx.xx";
    std::string wifiIp = "xx.xx.xx.xx";
    bool wifiEnabled = false;
    bool ethernetEnabled = false;

    int8_t rssi = 0;
    char time[10] = "00:00:00";
    lv_obj_t* barObj;
    lv_obj_t* label;
    lv_obj_t* timeLabel;
};