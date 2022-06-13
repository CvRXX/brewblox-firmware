#include "network/cbox_connection_manager.hpp"

CboxConnectionManager::CboxConnectionManager()
{
}

void CboxConnectionManager::start(CboxConnectionPtr c)
{
    connections.insert(c);
    c->start();
}

void CboxConnectionManager::stop(CboxConnectionPtr c)
{
    connections.erase(c);
    c->stop();
}

void CboxConnectionManager::stop_all()
{
    for (auto c : connections)
        c->stop();
    connections.clear();
}
