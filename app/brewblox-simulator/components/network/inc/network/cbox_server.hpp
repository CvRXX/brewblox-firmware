#pragma once
#include "network/cbox_connection_manager.hpp"
#include "network/cbox_stdio_connection.hpp"
#include "network/cbox_tcp_connection.hpp"

class CboxServer {
public:
    explicit CboxServer(asio::io_context& io_context_,
                        const uint16_t& port_)
        : io_context(io_context_)
        // signals_(io_context_),
        , acceptor(io_context)
        , connection_manager{}
    {
        // Register to handle the signals that indicate when the server should exit.
        // It is safe to register for the same signal multiple times in a program,
        // provided all registration for the specified signal is made through Asio.
        //   signals_.add(SIGINT);
        //   signals_.add(SIGTERM);
        // #if defined(SIGQUIT)
        //   signals_.add(SIGQUIT);
        // #endif // defined(SIGQUIT)

        do_await_stop();

        asio::ip::tcp::endpoint endpoint(asio::ip::address_v4::any(), port_);
        acceptor.open(endpoint.protocol());
        acceptor.set_option(asio::ip::tcp::acceptor::reuse_address(true));
        acceptor.bind(endpoint);
        acceptor.listen();

        do_accept();
    }

    CboxServer(const CboxServer&) = delete;
    CboxServer& operator=(const CboxServer&) = delete;

    ~CboxServer() = default;

    void attach_stdio()
    {
        connection_manager.start(
            std::make_shared<CboxStdioConnection>(io_context,
                                                  connection_manager));
    }

    void do_accept()
    {
        acceptor.async_accept(
            [this](std::error_code ec, asio::ip::tcp::socket socket) {
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
        // signals_.async_wait(
        //     [this](std::error_code /*ec*/, int /*signo*/) {
        //         // The server is stopped by cancelling all outstanding asynchronous
        //         // operations. Once all operations have finished the io_context::run()
        //         // call will exit.
        //     });
        acceptor.close();
        connection_manager.stop_all();
    }

    asio::io_context& io_context;
    asio::ip::tcp::acceptor acceptor;
    CboxConnectionManager connection_manager;
};
