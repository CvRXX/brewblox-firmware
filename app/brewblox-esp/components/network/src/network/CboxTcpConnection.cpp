#include "CboxTcpConnection.hpp"

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

void CboxTcpConnection::async_read_impl()
{
    asio::async_read_until(
        socket,
        buffer_in,
        '\n',
        [self{shared_from_this()}](std::error_code ec, std::size_t bytes_transferred) {
            self->finish_read(ec, bytes_transferred);
        });
}

void CboxTcpConnection::async_write_impl()
{
    asio::async_write(
        socket,
        buffer_out,
        [self{shared_from_this()}](std::error_code ec, std::size_t bytes_transferred) {
            self->finish_write(ec, bytes_transferred);
        });
}
