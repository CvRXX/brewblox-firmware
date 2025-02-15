#pragma once

#include "intellisense.hpp"

#include "network/cbox_connection.hpp"
#include <boost/asio.hpp>

class CboxTcpConnection final : public CboxConnection {
public:
    explicit CboxTcpConnection(boost::asio::ip::tcp::socket socket_,
                               CboxConnectionManager& connection_manager_);

    void stop() override;

    void async_read_impl(boost::asio::streambuf& buffer_out, std::shared_ptr<CboxConnection> self) override;
    void async_write_impl(boost::asio::streambuf& buffer_out, std::shared_ptr<CboxConnection> self) override;

private:
    boost::asio::ip::tcp::socket socket;
};
