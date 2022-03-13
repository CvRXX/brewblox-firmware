#include "CboxConnection.hpp"
#include "Brewblox.hpp"
#include "CboxConnectionManager.hpp"
#include "cbox/Box.h"
#include "cbox/Connections.h"

CboxConnection::CboxConnection(
    CboxConnectionManager& connection_manager_)
    : buffer_in(32768)
    , buffer_out(32768)
    , connection_manager(connection_manager_)
{
}

void CboxConnection::start()
{
    cbox::StreamBufDataOut out_cbox(buffer_out);
    cbox::connectionStarted(out_cbox);
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
        cbox::StreamBufDataIn in_cbox(buffer_in);
        cbox::StreamBufDataOut out_cbox(buffer_out);
        cbox::RegionDataIn transferred{in_cbox, bytes_transferred};
        // box.handleCommand(transferred, out_cbox);
        // TODO(Bob) handle command

        start_write(); // send reply
        start_read();  // read next
    } else if (ec != asio::error::operation_aborted) {
        connection_manager.stop(shared_from_this());
    }
}
