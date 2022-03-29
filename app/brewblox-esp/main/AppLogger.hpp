#pragma once
#include "esp_log.h"
#include <string>

namespace logger {

static const char* TAG = "Brewblox";

inline void info(const std::string& message)
{
    ESP_LOGI(TAG, "%s", message.c_str());
}

inline void warn(const std::string& message)
{
    ESP_LOGW(TAG, "%s", message.c_str());
}

inline void error(const std::string& message)
{
    ESP_LOGE(TAG, "%s", message.c_str());
}

} // end namespace logger
