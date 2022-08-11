#include "blocks/TempSensorExternalBlock.hpp"
#include "AppTicks.hpp"
#include "cbox/Cache.hpp"
#include "cbox/PayloadConversion.hpp"
#include "proto/TempSensorExternal.pb.h"

struct __attribute__((packed)) TempSensorExternalCacheLayout {
    int32_t setting{0};
    utc_seconds_t lastUpdated{0};
};

blox_TempSensorExternal_Block TempSensorExternalBlock::baseMessage() const
{
    blox_TempSensorExternal_Block message = blox_TempSensorExternal_Block_init_zero;

    message.enabled = _enabler.get();
    message.timeout = _timeout;
    message.lastUpdated = _lastUpdated;
    message.setting = cnl::unwrap(_setting);

    return message;
}

cbox::CboxError
TempSensorExternalBlock::read(const cbox::PayloadCallback& callback) const
{
    auto message = baseMessage();
    std::vector<cbox::obj_field_tag_t> excluded;

    if (auto val = value()) {
        message.value = cnl::unwrap(*val);
    } else {
        excluded.push_back(blox_TempSensorExternal_Block_value_tag);
    }

    return cbox::PayloadBuilder(*this)
        .withContent(&message,
                     blox_TempSensorExternal_Block_fields,
                     blox_TempSensorExternal_Block_size)
        .withMask(cbox::MaskMode::EXCLUSIVE, std::move(excluded))
        .respond(callback)
        .status();
}

cbox::CboxError
TempSensorExternalBlock::readStored(const cbox::PayloadCallback& callback) const
{
    auto message = baseMessage();

    return cbox::PayloadBuilder(*this)
        .withContent(&message,
                     blox_TempSensorExternal_Block_fields,
                     blox_TempSensorExternal_Block_size)
        .respond(callback)
        .status();
}

cbox::CboxError
TempSensorExternalBlock::write(const cbox::Payload& payload)
{
    blox_TempSensorExternal_Block message = blox_TempSensorExternal_Block_init_zero;

    auto parser = cbox::PayloadParser(payload);

    if (parser.fillMessage(&message, blox_TempSensorExternal_Block_fields)) {
        if (parser.hasField(blox_TempSensorExternal_Block_enabled_tag)) {
            _enabler.set(message.enabled);
        }
        if (parser.hasField(blox_TempSensorExternal_Block_timeout_tag)) {
            _timeout = message.timeout;
        }
        if (parser.hasField(blox_TempSensorExternal_Block_setting_tag)) {
            _setting = cnl::wrap<temp_t>(message.setting);

            auto utc = ticks.utc();
            if (utc > MIN_VALID_UTC) {
                _lastUpdated = utc;
            }
        }

        TempSensorExternalCacheLayout cached = {
            .setting = cnl::unwrap(_setting),
            .lastUpdated = _lastUpdated,
        };
        cbox::saveToCache(objectId(), staticTypeId(), cached);
    }

    return parser.status();
}

cbox::CboxError
TempSensorExternalBlock::loadFromCache()
{
    if (auto loaded = cbox::loadFromCache<TempSensorExternalCacheLayout>(objectId(), staticTypeId())) {
        auto cached = loaded.value();
        _setting = cnl::wrap<temp_t>(cached.setting);
        _lastUpdated = cached.lastUpdated;
    }
    return cbox::CboxError::OK;
}

cbox::update_t TempSensorExternalBlock::updateHandler(cbox::update_t now)
{
    auto utc = ticks.utc();
    _settingValid = _timeout == 0
                    || (utc > MIN_VALID_UTC && utc - _lastUpdated < _timeout);
    return next_update_1s(now);
}

void* TempSensorExternalBlock::implements(cbox::obj_type_t iface)
{
    if (iface == staticTypeId()) {
        return this; // me!
    }
    if (iface == cbox::interfaceId<TempSensor>()) {
        TempSensor* ptr = this;
        return ptr;
    }
    if (iface == cbox::interfaceId<Enabler>()) {
        Enabler* ptr = &_enabler;
        return ptr;
    }
    return nullptr;
}
