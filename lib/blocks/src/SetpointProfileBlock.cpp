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

#include "blocks/SetpointProfileBlock.hpp"
#include "AppTicks.hpp"
#include "cbox/PayloadConversion.hpp"
#include "pb_decode.h"
#include "pb_encode.h"
#include "proto/SetpointProfile.pb.h"

bool encodePoints(pb_ostream_t* stream, const pb_field_t* field, void* const* arg)
{
    auto* points = reinterpret_cast<const std::vector<SetpointProfile::Point>*>(*arg);
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

bool decodePoints(pb_istream_t* stream, const pb_field_t*, void** arg)
{
    auto* newPoints = reinterpret_cast<std::vector<SetpointProfile::Point>*>(*arg);

    if (stream->bytes_left) {
        blox_SetpointProfile_Point submsg = blox_SetpointProfile_Point_init_zero;
        if (!pb_decode(stream, blox_SetpointProfile_Point_fields, &submsg)) {
            return false;
        }
        newPoints->push_back(SetpointProfile::Point{submsg.time, cnl::wrap<decltype(SetpointProfile::Point::temp)>(submsg.temperature_oneof.temperature)});
    }
    return true;
}

cbox::CboxError
SetpointProfileBlock::read(const cbox::PayloadCallback& callback) const
{
    blox_SetpointProfile_Block message = blox_SetpointProfile_Block_init_zero;
    std::vector<cbox::obj_field_tag_t> excluded;

    message.points.funcs.encode = &encodePoints;
    message.points.arg = const_cast<std::vector<SetpointProfile::Point>*>(&profile.points());
    message.enabled = profile.enabler.get();
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

    return cbox::PayloadBuilder(*this)
        .withContent(&message,
                     blox_SetpointProfile_Block_fields,
                     blockSize)
        .withMask(cbox::MaskMode::EXCLUSIVE, std::move(excluded))
        .respond(callback)
        .status();
}

cbox::CboxError
SetpointProfileBlock::readStored(const cbox::PayloadCallback& callback) const
{
    return read(callback);
}

cbox::CboxError
SetpointProfileBlock::write(const cbox::Payload& payload)
{
    blox_SetpointProfile_Block message = blox_SetpointProfile_Block_init_zero;
    std::vector<SetpointProfile::Point> newPoints;
    message.points.funcs.decode = &decodePoints;
    message.points.arg = &newPoints;

    auto parser = cbox::PayloadParser(payload);

    if (parser.fillMessage(&message, blox_SetpointProfile_Block_fields)) {
        if (parser.hasField(blox_SetpointProfile_Block_points_tag)) {
            profile.points(std::move(newPoints));
        }
        if (parser.hasField(blox_SetpointProfile_Block_enabled_tag)) {
            profile.enabler.set(message.enabled);
        }
        if (parser.hasField(blox_SetpointProfile_Block_start_tag)) {
            profile.startTime(message.start);
        }
        if (parser.hasField(blox_SetpointProfile_Block_targetId_tag)) {
            target.setId(message.targetId);
        }
    }

    return parser.status();
}

cbox::update_t
SetpointProfileBlock::updateHandler(const cbox::update_t& now)
{
    auto time = ticks.utc();
    profile.update(time);
    return next_update_1s(now);
}

void* SetpointProfileBlock::implements(cbox::obj_type_t iface)
{
    if (iface == staticTypeId()) {
        return this; // me!
    }
    if (iface == cbox::interfaceIdImpl<Enabler>()) {
        Enabler* ptr = &profile.enabler;
        return ptr;
    }

    return nullptr;
}
