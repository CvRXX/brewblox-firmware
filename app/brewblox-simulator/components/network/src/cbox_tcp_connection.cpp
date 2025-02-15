#include "network/cbox_tcp_connection.hpp"

CboxTcpConnection::CboxTcpConnection(
    boost::asio::ip::tcp::socket socket_,
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

void CboxTcpConnection::async_read_impl(boost::asio::streambuf& buffer_out, std::shared_ptr<CboxConnection> self)
{
    boost::asio::async_read_until(
        socket,
        bufferIn(),
        '\n',
        [self{std::move(self)}](std::error_code ec, std::size_t bytes_transferred) {
            self->finish_read(ec, bytes_transferred);
        });
}

void CboxTcpConnection::async_write_impl(boost::asio::streambuf& buffer_out, std::shared_ptr<CboxConnection> self)
{
    boost::asio::async_write(
        socket,
        bufferOut(),
        [self{std::move(self)}](std::error_code ec, std::size_t bytes_transferred) {
            self->finish_write(ec, bytes_transferred);
        });
}
