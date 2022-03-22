#include "CboxConnection.hpp"
#include "Brewblox.hpp"
#include "CboxConnectionManager.hpp"
#include "EspBox.hpp"
#include "cbox/Application.hpp"
#include "cbox/Connection.hpp"

CboxConnection::CboxConnection(
    CboxConnectionManager& connection_manager_)
    : buffer_in(32768)
    , buffer_out(32768)
    , connection_manager(connection_manager_)
{
}

void CboxConnection::start()
{
    auto message = cbox::handshakeMessage();
    buffer_out.sputn(message.c_str(), message.size());
    buffer_out.pubsync();
    start_read();
}

void CboxConnection::stop()
{
}

void CboxConnection::start_read()
{
    async_read_impl(buffer_in, shared_from_this());
};

void CboxConnection::start_write()
{
    if (!writing && buffer_out.size() > 0) {
        writing = true;
        async_write_impl(buffer_out, shared_from_this());
    }
}

void CboxConnection::finish_write(std::error_code ec, std::size_t bytes_transferred)
{
    if (!ec) {
        writing = false;
        start_write(); // write more in case data if not already writing
    } else if (ec != asio::error::operation_aborted) {
        connection_manager.stop(shared_from_this());
    }
}

void CboxConnection::finish_read(std::error_code ec, std::size_t bytes_transferred)
{
    if (!ec) {
        std::string message(bytes_transferred, 0);
        buffer_in.sgetn(message.data(), bytes_transferred);
        auto out = BufferConnectionOut(buffer_out);
        handleCommand(out, message);

        start_write(); // send reply
        start_read();  // read next
    } else if (ec != asio::error::operation_aborted) {
        connection_manager.stop(shared_from_this());
    }
}
