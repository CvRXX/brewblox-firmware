#include "AppLogger.hpp"
#include "esp_log.h"

namespace logger {

static const char* TAG = "Brewblox";

void info(const std::string& message)
{
    ESP_LOGI(TAG, "%s", message.c_str());
}

void warn(const std::string& message)
{
    ESP_LOGW(TAG, "%s", message.c_str());
}

void error(const std::string& message)
{
    ESP_LOGE(TAG, "%s", message.c_str());
}

} // end namespace logger
