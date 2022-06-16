#pragma once

#include "network/cbox_connection_manager.hpp"
#include "network/cbox_tcp_connection.hpp"

class CboxServer final {
public:
    explicit CboxServer(boost::asio::io_context& io_context_,
                        const uint16_t& port_)
        : io_context(io_context_)
        , acceptor(io_context)
        , connection_manager{}
    {
        do_await_stop();

        boost::asio::ip::tcp::endpoint endpoint(boost::asio::ip::address_v4::any(), port_);
        acceptor.open(endpoint.protocol());
        acceptor.set_option(boost::asio::ip::tcp::acceptor::reuse_address(true));
        acceptor.bind(endpoint);
        acceptor.listen();

        do_accept();
    }

    CboxServer(const CboxServer&) = delete;
    CboxServer& operator=(const CboxServer&) = delete;

    CboxServer(CboxServer&&) = default;
    CboxServer& operator=(CboxServer&&) = default;

    ~CboxServer() = default;

    void do_accept()
    {
        acceptor.async_accept(
            [this](std::error_code ec, boost::asio::ip::tcp::socket socket) {
                // Check whether the server was stopped by a signal before this
                // completion handler had a chance to run.
                if (!acceptor.is_open()) {
                    return;
                }

                if (!ec) {
                    connection_manager.start(
                        std::make_shared<CboxTcpConnection>(std::move(socket),
                                                            connection_manager));
                }

                do_accept();
            });
    }

    void do_await_stop()
    {
        acceptor.close();
        connection_manager.stop_all();
    }

    boost::asio::io_context& io_context;
    boost::asio::ip::tcp::acceptor acceptor;
    CboxConnectionManager connection_manager;
};
