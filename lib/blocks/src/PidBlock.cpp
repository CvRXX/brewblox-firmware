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
#include "blocks/FieldTags.hpp"
#include "cbox/Application.hpp"
#include "cbox/Serialization.hpp"
#include "control/ProcessValue.hpp"
#include "proto/Pid.pb.h"

PidBlock::PidBlock()
    : pid(input.lockFunctor(), [this]() {
        // convert ActuatorConstrained to base ProcessValue
        return std::shared_ptr<ProcessValue<Pid::out_t>>(this->output.lock());
    })
{
}

cbox::CboxError PidBlock::read(const cbox::PayloadCallback& callback) const
{
    blox_Pid_Block message = blox_Pid_Block_init_zero;
    FieldTags stripped;

    message.inputId = input.getId();
    message.outputId = output.getId();

    if (auto ptr = input.const_lock()) {
        if (ptr->valueValid()) {
            message.inputValue = cnl::unwrap(ptr->value());
        } else {
            stripped.add(blox_Pid_Block_inputValue_tag);
        }
        if (ptr->settingValid()) {
            message.inputSetting = cnl::unwrap(ptr->setting());
        } else {
            stripped.add(blox_Pid_Block_inputSetting_tag);
        }
    } else {
        stripped.add(blox_Pid_Block_inputSetting_tag);
        stripped.add(blox_Pid_Block_inputValue_tag);
    }

    if (auto ptr = output.const_lock()) {
        if (ptr->valueValid()) {
            message.outputValue = cnl::unwrap(ptr->value());
        } else {
            stripped.add(blox_Pid_Block_outputValue_tag);
        }
        if (ptr->settingValid()) {
            message.outputSetting = cnl::unwrap(ptr->setting());
        } else {
            stripped.add(blox_Pid_Block_outputSetting_tag);
        }

    } else {
        stripped.add(blox_Pid_Block_outputSetting_tag);
        stripped.add(blox_Pid_Block_outputValue_tag);
    }
    if (pid.active()) {
        message.drivenOutputId = message.outputId;
    }

    message.enabled = pid.enabled();
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

    stripped.copyToMessage(message.strippedFields, message.strippedFields_count, 4);

    return callWithMessage(callback,
                           objectId(),
                           staticTypeId(),
                           0,
                           &message,
                           blox_Pid_Block_fields,
                           blox_Pid_Block_size);
}

cbox::CboxError
PidBlock::readStored(const cbox::PayloadCallback& callback) const
{
    blox_Pid_Block message = blox_Pid_Block_init_zero;

    message.inputId = input.getId();
    message.outputId = output.getId();
    message.enabled = pid.enabled();
    message.kp = cnl::unwrap(pid.kp());
    message.ti = pid.ti();
    message.td = pid.td();
    message.boilPointAdjust = cnl::unwrap(pid.boilPointAdjust());
    message.boilMinOutput = cnl::unwrap(pid.boilMinOutput());

    return callWithMessage(callback,
                           objectId(),
                           staticTypeId(),
                           0,
                           &message,
                           blox_Pid_Block_fields,
                           blox_Pid_Block_size);
}

cbox::CboxError PidBlock::write(const cbox::Payload& payload)
{
    blox_Pid_Block message = blox_Pid_Block_init_zero;
    auto res = payloadToMessage(payload, &message, blox_Pid_Block_fields);

    if (res == cbox::CboxError::OK) {
        pid.enabled(message.enabled);
        input.setId(message.inputId);
        output.setId(message.outputId);
        pid.kp(cnl::wrap<Pid::in_t>(message.kp));
        pid.ti(message.ti);
        pid.td(message.td);
        if (message.integralReset != 0) {
            pid.setIntegral(cnl::wrap<Pid::out_t>(message.integralReset));
        }
        pid.boilPointAdjust(cnl::wrap<Pid::in_t>(message.boilPointAdjust));
        pid.boilMinOutput(cnl::wrap<Pid::out_t>(message.boilMinOutput));
        pid.update(); // force an update that bypasses the update interval
    }

    return res;
}

cbox::CboxError
PidBlock::loadFromCache()
{
    cbox::getCacheStorage().loadObject(objectId(), [this](const cbox::Payload& payload) {
        if (payload.blockType == staticTypeId()) {
            uint32_t rawI{0};
            if (cbox::readFromByteVector(payload.content, rawI, 0)) {
                pid.i(cnl::wrap<Pid::out_t>(rawI));
            }
        }
        return cbox::CboxError::OK;
    });
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
            // ensure that the output object setting in EEPROM is zero
            // to prevent loading older EEPROM data for it on reboot
            // in which the output is still active
            if (auto ptr = output.lock()) {
                ptr->setting(0);
                output.store();
                previousActive = pidActive;
            }
            return now;
        }
    }

    if (now < lastCacheTime || now - lastCacheTime > cacheInterval) {
        lastCacheTime = now; // Do not retry on cache failure
        auto cached = cbox::Payload(objectId(), staticTypeId(), 0);
        cbox::writeToByteVector(cached.content, cnl::unwrap(pid.i()), 0);
        cbox::getCacheStorage().saveObject(cached);
    }

    return nextUpdate;
}

void* PidBlock::implements(cbox::obj_type_t iface)
{
    if (iface == brewblox_BlockType_Pid) {
        return this; // me!
    }
    return nullptr;
}
