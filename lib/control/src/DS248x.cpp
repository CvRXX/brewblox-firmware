/*
 * Copyright 2021 BrewPi B.V./Elco Jacobs.
 *
 * This file is part of Brewblox.
 *
 * Brewblox is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * Brewblox is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with Brewblox.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "control/DS248x.hpp"
#include "blox_hal/hal_delay.hpp"

constexpr const uint8_t PTR_STATUS = 0xf0;
constexpr const uint8_t PTR_READ = 0xe1;
constexpr const uint8_t PTR_CONFIG = 0xc3;
constexpr const uint8_t PTR_PORTCONFIG = 0xb4; // DS2484 only

bool DS248x::busyWait()
{
    if (i2c_write(std::array<uint8_t, 2>({DS248X_SRP, PTR_STATUS}))) {
        for (uint8_t retries = 0; retries < 5; retries++) {
            uint8_t result;
            if (i2c_read(result)) {
                bool ready = (result & DS248X_STATUS_BUSY) == 0;
                if (ready) {
                    mStatus = result;
                    shortDetectedFlag |= (result & 0x4);
                    failedWaits = 0;
                    return true;
                }
            }
            hal_delay_ms(1);
        }
    }
    if (failedWaits++ > 100) {
        init(); // reinitialize driver
        failedWaits = 0;
    }
    return false;
}

bool DS248x::init()
{
    if (resetMaster()) {
        return configure(DS248X_CONFIG_APU);
    }
    return false;
}

bool DS248x::resetMaster()
{
    return i2c_write(DS248X_DRST);
}

bool DS248x::configure(uint8_t config)
{
    // when writing, upper bits should be inverse of lower bits
    // when reading, upper bits read as zero
    uint8_t config_byte = config + (~config << 4U);
    if (i2c_write(std::array<uint8_t, 2>({DS248X_WCFG, config_byte}))) {
        uint8_t result;
        if (i2c_read(result)) {
            return result == config;
        }
    }
    return false;
}

bool DS248x::selectChannel(uint8_t channel)
{
    uint8_t ch, ch_read;

    switch (channel) {
    case 0:
    default:
        ch = 0xf0;
        ch_read = 0xb8;
        break;
    case 1:
        ch = 0xe1;
        ch_read = 0xb1;
        break;
    case 2:
        ch = 0xd2;
        ch_read = 0xaa;
        break;
    case 3:
        ch = 0xc3;
        ch_read = 0xa3;
        break;
    case 4:
        ch = 0xb4;
        ch_read = 0x9c;
        break;
    case 5:
        ch = 0xa5;
        ch_read = 0x95;
        break;
    case 6:
        ch = 0x96;
        ch_read = 0x8e;
        break;
    case 7:
        ch = 0x87;
        ch_read = 0x87;
        break;
    };

    if (busyWait()) {
        if (i2c_write(std::array<uint8_t, 2>({DS248X_CHSL, ch}))) {
            uint8_t result;
            if (i2c_read(result)) {
                return ch_read == result;
            }
        }
    }

    return false;
}

bool DS248x::reset()
{
    if (busyWait()) {
        if (i2c_write(DS248X_1WRS)) {
            // read status until ready
            // todo: use repeated start condition ?
            for (uint8_t retries = 0; retries < 10; retries++) {
                uint8_t result;
                if (!i2c_read(result)) {
                    // i2c error
                    return false;
                }
                if ((result & DS248X_STATUS_BUSY) == 0) {
                    mStatus = result;
                    shortDetectedFlag |= (result & 0x4);
                    return (mStatus & DS248X_STATUS_PPD) > 0;
                }
                hal_delay_ms(1);
            }
        }
    }
    return false;
}

bool DS248x::write(uint8_t b)
{
    if (busyWait()) {
        return i2c_write(std::array<uint8_t, 2>({{DS248X_1WWB, b}}));
    }
    return false;
}

bool DS248x::read(uint8_t& b)
{
    if (busyWait()) {
        if (!i2c_write(DS248X_1WRB)) {
            return false;
        }

        for (uint8_t retries = 0; retries < 5; retries++) {
            uint8_t result;
            if (!i2c_read(result)) {
                // i2c error
                return false;
            }
            bool ready = (result & DS248X_STATUS_BUSY) == 0;
            if (ready) {
                mStatus = result;
                if (i2c_write(std::array<uint8_t, 2>({DS248X_SRP, PTR_READ}))) {
                    if (i2c_read(result)) {
                        b = result;
                        return true;
                    }
                }
            }
            hal_delay_ms(1);
        }
    }
    return false;
}

bool DS248x::write_bit(bool bit)
{
    if (busyWait()) {
        return i2c_write(std::array<uint8_t, 2>({DS248X_1WSB, bit ? uint8_t{0x80} : uint8_t{0}}));
    }
    return false;
}

bool DS248x::read_bit(bool& bit)
{
    if (write_bit(1)) {
        bit = (mStatus & DS248X_STATUS_SBR) > 0;
        return true;
    }
    return false;
}

uint8_t
DS248x::search_triplet(bool search_direction)
{
    // 1-Wire Triplet (Case B)
    //   S AD,0 [A] 1WT [A] SS [A] Sr AD,1 [A] [Status] A [Status] A\ P
    //                                         \--------/
    //                           Repeat until 1WB bit has changed to 0
    //  [] indicates from slave
    //  SS indicates byte containing search direction bit value in msbit
    if (busyWait()) {
        if (i2c_write(std::array<uint8_t, 2>({DS248X_1WT, search_direction ? uint8_t{0x80} : uint8_t{0x00}}))) {
            // success, TODO handle fail?
        };
    }

    busyWait(); // this updates mStatus
    return mStatus;
}
