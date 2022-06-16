#include "network/cbox_connection_manager.hpp"

void CboxConnectionManager::start(const std::shared_ptr<CboxConnection>& c)
{
    connections.insert(c);
    c->start();
}

void CboxConnectionManager::stop(const std::shared_ptr<CboxConnection>& c)
{
    c->stop();
    connections.erase(c);
}

void CboxConnectionManager::stop_all()
{
    for (const auto& c : connections) {
        c->stop();
    }
    connections.clear();
}
