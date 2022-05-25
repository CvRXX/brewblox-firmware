#pragma once
#include "cbox/Application.hpp"
#include "cbox/CboxError.hpp"
#include "cbox/Object.hpp"
#include "cbox/Payload.hpp"
#include "cbox/Serialization.hpp"

namespace cbox {

template <typename T>
CboxExpected<T> loadFromCache(obj_id_t blockId, obj_type_t blockType)
{
    auto content = T();
    auto status = getCacheStorage().loadObject(blockId, [&blockType, &content](const Payload& payload) {
        if (blockType != payload.blockType) {
            return CboxError::INVALID_BLOCK_TYPE;
        }
        if (!readFromByteVector(payload.content, content, 0)) {
            return CboxError::INVALID_BLOCK_CONTENT;
        }
        return CboxError::OK;
    });
    if (status != CboxError::OK) {
        return tl::make_unexpected(status);
    }
    return content;
}

template <typename T>
CboxError saveToCache(obj_id_t blockId, obj_type_t blockType, const T& content)
{
    auto payload = Payload(blockId, blockType, 0);
    appendToByteVector(payload.content, 0);
    return getCacheStorage().saveObject(payload);
}

} // end namespace cbox
