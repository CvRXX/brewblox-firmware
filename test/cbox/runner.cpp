#define CATCH_CONFIG_MAIN
#define CATCH_CONFIG_CONSOLE_WIDTH 300 // workaround for compatiblity with vscode Test Explorer

#include "cbox/CboxError.h"
#include "cbox/Connections.h"
#include "cbox/DataStream.h"
#include <catch.hpp>

namespace cbox {
void connectionStarted(DataOut& out)
{
}

bool applicationCommand(uint8_t cmdId, DataIn& in, EncodedDataOut& out)
{

    switch (cmdId) {
    case 100: {
        CboxError status = CboxError::OK;
        in.spool();
        if (out.crc()) {
            status = CboxError::CRC_ERROR_IN_COMMAND;
        }

        out.writeResponseSeparator();
        out.write(asUint8(status));
        if (status == CboxError::OK) {
            out.write(100);
        }
        return true;
    }
    default:
        return false;
    }
}

} // end namespace cbox
