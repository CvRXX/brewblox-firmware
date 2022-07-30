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

#include "blocks/PidBlock.hpp"
#include "cbox/Application.hpp"
#include "cbox/Cache.hpp"
#include "cbox/PayloadConversion.hpp"
#include "control/ProcessValue.hpp"
#include "proto/Pid.pb.h"

struct __attribute__((packed)) PidCacheLayout {
    int32_t i{0};
};

static constexpr uint16_t CACHE_INTERVAL{5000};

cbox::CboxError PidBlock::read(const cbox::PayloadCallback& callback) const
{
    blox_Pid_Block message = blox_Pid_Block_init_zero;
    std::vector<cbox::obj_field_tag_t> excluded;

    message.inputId = input.getId();
    message.outputId = output.getId();

    if (auto ptr = input.lock()) {
        if (auto val = ptr->value()) {
            message.inputValue = cnl::unwrap(*val);
        } else {
            excluded.push_back(blox_Pid_Block_inputValue_tag);
        }
        if (auto val = ptr->setting()) {
            message.inputSetting = cnl::unwrap(*val);
        } else {
            excluded.push_back(blox_Pid_Block_inputSetting_tag);
        }
    } else {
        excluded.push_back(blox_Pid_Block_inputSetting_tag);
        excluded.push_back(blox_Pid_Block_inputValue_tag);
    }

    if (auto ptr = output.lock()) {
        if (auto val = ptr->value()) {
            message.outputValue = cnl::unwrap(*val);
        } else {
            excluded.push_back(blox_Pid_Block_outputValue_tag);
        }
        if (auto val = ptr->setting()) {
            message.outputSetting = cnl::unwrap(*val);
        } else {
            excluded.push_back(blox_Pid_Block_outputSetting_tag);
        }

    } else {
        excluded.push_back(blox_Pid_Block_outputSetting_tag);
        excluded.push_back(blox_Pid_Block_outputValue_tag);
    }
    if (pid.active()) {
        message.drivenOutputId = message.outputId;
    }

    message.enabled = pid.enabler.get();
    message.active = pid.active();
    message.kp = cnl::unwrap(pid.kp());
    message.ti = pid.ti();
    message.td = pid.td();
    message.p = cnl::unwrap(pid.p());
    message.i = cnl::unwrap(pid.i());
    message.d = cnl::unwrap(pid.d());
    message.error = cnl::unwrap(pid.error());
    message.integral = cnl::unwrap(pid.integral());
    message.derivative = cnl::unwrap(pid.derivative());
    message.boilPointAdjust = cnl::unwrap(pid.boilPointAdjust());
    message.boilMinOutput = cnl::unwrap(pid.boilMinOutput());
    message.boilModeActive = pid.boilModeActive();
    message.derivativeFilter = blox_SetpointSensorPair_FilterChoice(pid.derivativeFilterNr());

    return cbox::PayloadBuilder(*this)
        .withContent(&message,
                     blox_Pid_Block_fields,
                     blox_Pid_Block_size)
        .withMask(cbox::MaskMode::EXCLUSIVE, std::move(excluded))
        .respond(callback)
        .status();
}

cbox::CboxError
PidBlock::readStored(const cbox::PayloadCallback& callback) const
{
    blox_Pid_Block message = blox_Pid_Block_init_zero;

    message.inputId = input.getId();
    message.outputId = output.getId();
    message.enabled = pid.enabler.get();
    message.kp = cnl::unwrap(pid.kp());
    message.ti = pid.ti();
    message.td = pid.td();
    message.boilPointAdjust = cnl::unwrap(pid.boilPointAdjust());
    message.boilMinOutput = cnl::unwrap(pid.boilMinOutput());

    return cbox::PayloadBuilder(*this)
        .withContent(&message,
                     blox_Pid_Block_fields,
                     blox_Pid_Block_size)
        .respond(callback)
        .status();
}

cbox::CboxError PidBlock::write(const cbox::Payload& payload)
{
    blox_Pid_Block message = blox_Pid_Block_init_zero;
    auto parser = cbox::PayloadParser(payload);

    if (parser.fillMessage(&message, blox_Pid_Block_fields)) {
        if (parser.hasField(blox_Pid_Block_enabled_tag)) {
            pid.enabler.set(message.enabled);
        }
        if (parser.hasField(blox_Pid_Block_inputId_tag)) {
            input.setId(message.inputId);
        }
        if (parser.hasField(blox_Pid_Block_outputId_tag)) {
            output.setId(message.outputId);
        }
        if (parser.hasField(blox_Pid_Block_kp_tag)) {
            pid.kp(cnl::wrap<Pid::in_t>(message.kp));
        }
        if (parser.hasField(blox_Pid_Block_ti_tag)) {
            pid.ti(message.ti);
        }
        if (parser.hasField(blox_Pid_Block_td_tag)) {
            pid.td(message.td);
        }
        if (parser.hasField(blox_Pid_Block_boilPointAdjust_tag)) {
            pid.boilPointAdjust(cnl::wrap<Pid::in_t>(message.boilPointAdjust));
        }
        if (parser.hasField(blox_Pid_Block_boilMinOutput_tag)) {
            pid.boilMinOutput(cnl::wrap<Pid::out_t>(message.boilMinOutput));
        }
        if (parser.hasField(blox_Pid_Block_integralReset_tag)
            && message.integralReset != 0) {
            pid.setIntegral(cnl::wrap<Pid::out_t>(message.integralReset));
        }
        pid.update(); // force an update that bypasses the update interval
    }

    return parser.status();
}

cbox::CboxError
PidBlock::loadFromCache()
{
    if (auto loaded = cbox::loadFromCache<PidCacheLayout>(objectId(), staticTypeId())) {
        pid.i(cnl::wrap<Pid::out_t>(loaded.value().i));
    }
    return cbox::CboxError::OK;
}

cbox::update_t
PidBlock::updateHandler(const cbox::update_t& now)
{
    bool doUpdate = false;
    auto nextUpdate = m_intervalHelper.update(now, doUpdate);

    if (doUpdate) {
        pid.update();
        auto pidActive = pid.active();
        if (previousActive != pidActive) {
            // When the pid changes whether it is active
            // ensure that the output, that has been set to invalid, is stored
            // to prevent loading older EEPROM data for it on reboot
            // in which the output is still active
            if (auto ptr = output.lock()) {
                output.store();
                previousActive = pidActive;
            }
            return now;
        }
    }

    if (now < lastCacheTime || now - lastCacheTime > CACHE_INTERVAL) {
        lastCacheTime = now; // Do not retry on cache failure
        PidCacheLayout cached = {.i = cnl::unwrap(pid.i())};
        cbox::saveToCache(objectId(), staticTypeId(), cached);
    }

    return nextUpdate;
}

void* PidBlock::implements(cbox::obj_type_t iface)
{
    if (iface == staticTypeId()) {
        return this; // me!
    }
    if (iface == cbox::interfaceIdImpl<Enabler>()) {
        Enabler* ptr = &pid.enabler;
        return ptr;
    }
    return nullptr;
}
