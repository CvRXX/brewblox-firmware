/*
 * Copyright 2014-2021 BrewPi B.V. / Elco Jacobs
 * based on earlier work of Matthew McGowan.
 *
 * This file is part of BrewBlox.
 *
 * Controlbox is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with Controlbox.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "DataStream.h"
#include "Crc.h"
#include "b64_utility.h"
#include "hex_utility.h"
#include <algorithm>

namespace cbox {

bool DataOut::writeBuffer(const uint8_t* data, stream_size_t len)
{
    const uint8_t* d = data;
    while (len-- > 0) {
        if (!write(*d++))
            return false;
    }
    return true;
}

bool DataIn::readBytes(uint8_t* t, stream_size_t length)
{
    uint8_t* target = t;
    while (length-- > 0) {
        auto v = read();
        if (v < 0) {
            return false;
        }
        *target++ = v;
    }
    return true;
}

CboxError DataIn::push(DataOut& out, stream_size_t length)
{
    while (length-- > 0) {
        auto v = read();
        if (v < 0) {
            return CboxError::INPUT_STREAM_READ_ERROR;
        }
        if (!out.write(v)) {
            return CboxError::OUTPUT_STREAM_WRITE_ERROR;
        }
    }
    return CboxError::OK;
}

CboxError DataIn::push(DataOut& out)
{
    while (true) {
        auto v = read();
        if (v < 0) {
            // stream is empty or error
            // we don't know the expected length, so we assume this was expected
            return CboxError::OK;
        }
        if (!out.write(v)) {
            return CboxError::OUTPUT_STREAM_WRITE_ERROR;
        }
    }
}

bool CrcDataOut::write(uint8_t data)
{
    crcValue = calc_crc(crcValue, data);
    return out.write(data);
}

bool EncodedDataOut::write(uint8_t data)
{
    crcValue = calc_crc(crcValue, data);
    bool success = out.write(d2h(uint8_t(data & 0xF0) >> 4));
    success = success && out.write(d2h(uint8_t(data & 0xF)));
    return success;
}

void EncodedDataOut::endMessage()
{
    write(crcValue);
    crcValue = 0;
    out.write('\n');
}

void EncodedDataOut::writeAnnotation(std::string&& ann)
{
    out.write('<');
    for (auto c : ann) {
        out.write(c);
    }
    out.write('>');
}

void EncodedDataOut::writeEvent(std::string&& ann)
{
    out.write('<');
    out.write('!');
    for (auto c : ann) {
        out.write(c);
    }
    out.write('>');
}

void EncodedDataOut::writeError(CboxError error)
{
    std::string msg = "CBOXERROR:  ";
    uint8_t asByte = uint8_t(error);
    msg[10] = d2h(uint8_t(asByte & 0xF0) >> 4);
    msg[11] = d2h(uint8_t(asByte & 0x0F));
    writeEvent(std::move(msg));
}

void Base64DataOut::generateEncoded()
{
    bytesEncoded[0] = (bytesDecoded[0] & 0xfc) >> 2;
    bytesEncoded[1] = ((bytesDecoded[0] & 0x03) << 4) + ((bytesDecoded[1] & 0xf0) >> 4);
    bytesEncoded[2] = ((bytesDecoded[1] & 0x0f) << 2) + ((bytesDecoded[2] & 0xc0) >> 6);
    bytesEncoded[3] = bytesDecoded[2] & 0x3f;
}

bool Base64DataOut::flush(uint8_t end)
{
    for (; writeOutIdx < end; writeOutIdx++) {
        if (!out.write(bytesEncoded[writeOutIdx])) {
            return false;
        }
    }
    writeInIdx = 0;
    writeOutIdx = 0;
    return true;
}

bool Base64DataOut::write(uint8_t data)
{
    // resume in-progress write
    if (writeOutIdx > 0) {
        if (!flush(4)) {
            return false;
        }
        writeInIdx = 0;
        writeOutIdx = 0;
        return write(data);
    }

    if (writeInIdx < 3) {
        bytesDecoded[writeInIdx] = data;
        writeInIdx++;
        if (writeInIdx == 3) {
            generateEncoded();
            return flush(4);
        }
    }

    return true;
}

bool Base64DataOut::endMessage()
{
    if (writeInIdx > 0) {
        for (auto i = writeInIdx; i < 3; i++) {
            bytesDecoded[i] = 0;
        }
        generateEncoded();
        if (!flush(writeInIdx + 1)) {
            return false;
        }
    }
    return out.write('\n');
}

} // end namespace cbox
