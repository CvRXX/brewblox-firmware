#pragma once
#include "intellisense.hpp"

#include "cbox/Connection.hpp"
#include <string>

void handleCommand(cbox::ConnectionOut& out, const std::string& message);
