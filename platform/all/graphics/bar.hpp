#include "fonts/fonts.hpp"
#include "lvgl.h"
#include "styles.hpp"
#include <ctime>
#include <string>

/// A topbar for the display
class Bar {

public:
    /**
     * Constructs the bar and it's components. Also sets the bar text to it's initial values.
     * @param maincontainer the maincontainer in which the bar will be drawn.
     */
    Bar(lv_obj_t* mainContainer)
    {
        barObj = lv_obj_create(mainContainer, nullptr);
        lv_obj_set_size(barObj, 480, 25);
        lv_obj_add_style(barObj, LV_CONT_PART_MAIN, &style::bar);

        label = lv_label_create(barObj, nullptr);
        lv_label_set_align(label, LV_LABEL_ALIGN_CENTER);
        lv_obj_align(label, nullptr, LV_ALIGN_IN_LEFT_MID, 0, 0);

        timeLabel = lv_label_create(barObj, nullptr);
        lv_label_set_align(timeLabel, LV_LABEL_ALIGN_CENTER);

        lv_label_set_text(this->timeLabel, time);
        lv_obj_align(timeLabel, nullptr, LV_ALIGN_IN_RIGHT_MID, -5, 0);
        updateLabel();
    }

    Bar(){};

    /**
     * Sets the ethernet ip displayed in the top bar.
     * @param ip The ip to be shown.
     */
    void setEthernetIp(uint32_t ip)
    {
        this->ethernetIp = formatIp(ip);
        updateLabel();
    }

    /**
     * Sets the wifi ip displayed in the top bar.
     * @param ip The ip to be shown.
     */
    void setWifiIp(uint32_t ip)
    {
        this->wifiIp = formatIp(ip);
        updateLabel();
    }

    /**
     * Enables or disables the state of the wifi icon. If enabled the ip will be shown.
     * @param enabled If true the wifi will be enabled.
     */
    void setWifiEnabled(bool enabled)
    {
        this->wifiEnabled = enabled;
        updateLabel();
    }

    /**
     * Enables or disables the state of the ethernet icon. If enabled the ip will be shown.
     * @param enabled If true the ethernet will be enabled.
     */
    void setEthernetEnabled(bool enabled)
    {
        this->ethernetEnabled = enabled;
        updateLabel();
    }

    /// Updates the time shown in the bar.
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
            wifi = std::string() + symbols::wifi + " " + this->wifiIp;
        } else {
            wifi = symbols::wifi_off;
        }

        std::string ethernet;
        if (ethernetEnabled) {
            ethernet = std::string() + symbols::ethernet + " " + this->ethernetIp;
        } else {
            ethernet = symbols::ethernet_off;
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

    char time[10] = "00:00:00";
    lv_obj_t* barObj = nullptr;
    lv_obj_t* label = nullptr;
    lv_obj_t* timeLabel = nullptr;
};