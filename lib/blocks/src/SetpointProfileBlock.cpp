/*
 * Copyright 2020 BrewPi B.V.
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

#include "blocks/SetpointProfileBlock.h"
#include "blocks/FieldTags.h"
#include "pb_decode.h"
#include "pb_encode.h"
#include "proto/SetpointProfile.pb.h"

bool streamPointsOut(pb_ostream_t* stream, const pb_field_t* field, void* const* arg)
{
    const std::vector<SetpointProfileBlock::Point>* points = reinterpret_cast<std::vector<SetpointProfileBlock::Point>*>(*arg);
    for (const auto& p : *points) {
        auto submsg = blox_SetpointProfile_Point();
        submsg.time = p.time;
        submsg.temperature_oneof.temperature = cnl::unwrap(p.temp);
        submsg.which_temperature_oneof = blox_SetpointProfile_Point_temperature_tag;
        if (!pb_encode_tag_for_field(stream, field)) {
            return false;
        }
        if (!pb_encode_submessage(stream, blox_SetpointProfile_Point_fields, &submsg)) {
            return false;
        }
    }
    return true;
}

bool streamPointsIn(pb_istream_t* stream, const pb_field_t*, void** arg)
{
    std::vector<SetpointProfileBlock::Point>* newPoints = reinterpret_cast<std::vector<SetpointProfileBlock::Point>*>(*arg);

    if (stream->bytes_left) {
        blox_SetpointProfile_Point submsg = blox_SetpointProfile_Point_init_zero;
        if (!pb_decode(stream, blox_SetpointProfile_Point_fields, &submsg)) {
            return false;
        }
        newPoints->push_back(SetpointProfileBlock::Point{submsg.time, cnl::wrap<decltype(SetpointProfileBlock::Point::temp)>(submsg.temperature_oneof.temperature)});
    }
    return true;
}

cbox::CboxError
SetpointProfileBlock::read(cbox::Command& cmd) const
{
    blox_SetpointProfile_Block message = blox_SetpointProfile_Block_init_zero;
    FieldTags stripped;

    message.points.funcs.encode = &streamPointsOut;
    message.points.arg = const_cast<std::vector<Point>*>(&profile.points());
    message.enabled = profile.enabled();
    message.start = profile.startTime();
    message.targetId = target.getId();
    if (profile.isDriving()) {
        message.drivenTargetId = target.getId();
    }

    size_t blockSize = (blox_SetpointProfile_Point_size + 1) * profile.points().size()
                       + 3 // enabled
                       + 4 // targetId
                       + 5 // drivenTargetId
                       + 6 // start
        ;

    return writeProtoToCommand(cmd,
                               &message,
                               blox_SetpointProfile_Block_fields,
                               blockSize,
                               objectId,
                               staticTypeId());
}

cbox::CboxError
SetpointProfileBlock::readPersisted(cbox::Command& cmd) const
{
    return read(cmd);
}

cbox::CboxError
SetpointProfileBlock::write(cbox::Command& cmd)
{
    blox_SetpointProfile_Block message = blox_SetpointProfile_Block_init_zero;
    std::vector<Point> newPoints;
    message.points.funcs.decode = &streamPointsIn;
    message.points.arg = &newPoints;

    auto res = readProtoFromCommand(cmd, &message, blox_SetpointProfile_Block_fields);

    if (res == cbox::CboxError::OK) {
        profile.points(std::move(newPoints));
        profile.enabled(message.enabled);
        profile.startTime(message.start);
        target.setId(message.targetId);
    }

    return res;
}

cbox::update_t
SetpointProfileBlock::update(const cbox::update_t& now)
{
    if (auto pTicks = ticksPtr.const_lock()) {
        auto time = pTicks->const_get().utc();
        profile.update(time);
    }
    return update_1s(now);
}

void* SetpointProfileBlock::implements(const cbox::obj_type_t& iface)
{
    if (iface == brewblox_BlockType_SetpointProfile) {
        return this; // me!
    }

    return nullptr;
}
