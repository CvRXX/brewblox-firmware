/*
 * Copyright 2018 Elco Jacobs / Brewblox.
 *
 * This file is part of Brewblox.
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
 * along with Brewblox. If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once
#include "cbox/EepromLayout.hpp"

#include "cbox/CboxError.hpp"
#include "cbox/EepromAccess.hpp"
#include "cbox/EepromBlock.hpp"
#include "cbox/ObjectStorage.hpp"

namespace cbox {
inline bool
operator==(const uint8_t& a, const EepromBlockType& b)
{
    return a == static_cast<uint8_t>(b);
}

struct EepromFreeSpace {
    uint16_t total;
    uint16_t continuous;
};

class EepromObjectStorage : public ObjectStorage {
public:
    explicit EepromObjectStorage(EepromAccess& _eeprom);
    virtual ~EepromObjectStorage() = default;

    CboxError loadObject(obj_id_t id, const PayloadCallback& callback) final;

    CboxError saveObject(const Payload& payload) final;

    CboxError loadAllObjects(const PayloadCallback& callback) final;

    bool disposeObject(obj_id_t id) final;

    void clear() final;

    EepromFreeSpace freeSpace();

    void defrag();

protected:
    /**
     * The application supplied EEPROM storage class
     */
    EepromAccess& eeprom;

    static constexpr uint8_t magicByte = 0x69;
    static constexpr uint8_t storageVersion = 0x01;
    static constexpr uint16_t referenceHeader = uint16_t(uint16_t(magicByte) << 8U) + storageVersion;

    std::optional<EepromBlock> getExistingBlock(EepromBlockType requestedType, uint16_t minSize, uint16_t start);
    std::optional<EepromBlock> getNextObject(uint16_t start, bool limitToWrittenSize);
    std::optional<EepromBlock> getExistingObject(obj_id_t id, bool limitToWrittenSize);
    std::optional<EepromBlock> getNewObject(uint16_t minSize);

    void init();
    bool moveDisposedBackwards();
    void mergeDisposedBlocks();

    static CboxError eepromToPayload(const PayloadCallback& callback,
                                     EepromBlock& block);

    static uint16_t provisionedLength(uint16_t objectLength)
    {
        // overprovision by 12.5%, minimal 4 bytes
        return objectLength + std::max(objectLength / 8, 4) + EepromBlock::objectHeaderLength;
    }
};

} // end namespace cbox
