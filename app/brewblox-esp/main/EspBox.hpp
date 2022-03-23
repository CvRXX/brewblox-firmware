#pragma once
#include "intellisense.hpp"

#include <string>

class ResponseWriter {
public:
    ResponseWriter() = default;
    virtual ~ResponseWriter() = default;
    ResponseWriter(const ResponseWriter&) = delete;
    ResponseWriter& operator=(const ResponseWriter&) = delete;

    virtual void commit() = 0;

    virtual bool write(const std::string& message) = 0;

    virtual bool write(char c) = 0;

    virtual bool writeLog(const std::string& message) = 0;
};

void handleCommand(ResponseWriter& out, const std::string& message);
