#include "network/cbox_connection.hpp"
#include "SimulatorSystem.hpp"
#include "cbox/Application.hpp"
#include "network/cbox_connection_manager.hpp"

static constexpr size_t BUFFER_SIZE = 32768;

CboxConnection::CboxConnection(CboxConnectionManager& connectionManager_)
    : _bufferIn(BUFFER_SIZE)
    , _bufferOut(BUFFER_SIZE)
    , _connectionManager(connectionManager_)
{
}

void CboxConnection::start()
{
    auto message = cbox::handshakeMessage();
    _bufferOut.sputc('<');
    _bufferOut.sputn(message.c_str(), static_cast<std::streamsize>(message.size()));
    _bufferOut.sputc('>');
    _bufferOut.pubsync();
    start_read();
}

void CboxConnection::stop()
{
}

void CboxConnection::start_read()
{
    async_read_impl(_bufferIn, shared_from_this());
};

void CboxConnection::start_write()
{
    if (!_writing && _bufferOut.size() > 0) {
        _writing = true;
        async_write_impl(_bufferOut, shared_from_this());
    }
}

void CboxConnection::finish_write(std::error_code ec, std::size_t bytes_transferred)
{
    if (!ec) {
        _writing = false;
        start_write(); // write more in case data if not already writing
    } else if (ec.value() != boost::asio::error::operation_aborted) {
        _connectionManager.stop(shared_from_this());
    }
}

void CboxConnection::finish_read(std::error_code ec, std::size_t bytes_transferred)
{
    if (!ec) {
        std::string message(bytes_transferred, 0);
        _bufferIn.sgetn(message.data(), static_cast<std::streamsize>(bytes_transferred));
        auto out = BufferResponseWriter(_bufferOut);
        handleCommand(out, message);

        start_write(); // send reply
        start_read();  // read next
    } else if (ec.value() != boost::asio::error::operation_aborted) {
        _connectionManager.stop(shared_from_this());
    }
}
