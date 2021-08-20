#pragma once
#include <string>

void check_ota();
void start_ota(const std::string& url, bool skip_version_check);

struct OtaParameters {
    char url[256];
    bool skip_version_check;
};
