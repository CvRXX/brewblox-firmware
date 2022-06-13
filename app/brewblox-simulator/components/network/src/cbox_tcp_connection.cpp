#include "network/cbox_tcp_connection.hpp"

CboxTcpConnection::CboxTcpConnection(
    asio::ip::tcp::socket socket_,
    CboxConnectionManager& connection_manager_)
    : CboxConnection(connection_manager_)
    , socket(std::move(socket_))
{
}

void CboxTcpConnection::stop()
{
    CboxConnection::stop();
    socket.close();
}

void CboxTcpConnection::async_read_impl(asio::streambuf& buffer_out, std::shared_ptr<CboxConnection> self)
{
    asio::async_read_until(
        socket,
        buffer_in,
        '\n',
        [self{std::move(self)}](std::error_code ec, std::size_t bytes_transferred) {
            self->finish_read(ec, bytes_transferred);
        });
}

void CboxTcpConnection::async_write_impl(asio::streambuf& buffer_out, std::shared_ptr<CboxConnection> self)
{
    asio::async_write(
        socket,
        buffer_out,
        [self{std::move(self)}](std::error_code ec, std::size_t bytes_transferred) {
            self->finish_write(ec, bytes_transferred);
        });
}
