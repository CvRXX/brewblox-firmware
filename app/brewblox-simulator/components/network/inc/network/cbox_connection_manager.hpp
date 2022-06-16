#pragma once

#include "network/cbox_connection.hpp"
#include <set>

/// Manages open connections so that they may be cleanly stopped when the server
/// needs to shut down.
class CboxConnectionManager final {
public:
    CboxConnectionManager() = default;
    CboxConnectionManager(const CboxConnectionManager&) = delete;
    CboxConnectionManager& operator=(const CboxConnectionManager&) = delete;
    CboxConnectionManager(CboxConnectionManager&&) = default;
    CboxConnectionManager& operator=(CboxConnectionManager&&) = default;
    ~CboxConnectionManager() = default;

    void start(const std::shared_ptr<CboxConnection>& c);

    void stop(const std::shared_ptr<CboxConnection>& c);

    void stop_all();

private:
    std::set<std::shared_ptr<CboxConnection>> connections;
};
