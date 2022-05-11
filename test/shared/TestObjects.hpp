#pragma once

#include "cbox/CboxPtr.hpp"
#include "cbox/ObjectBase.hpp"
#include "cbox/Serialization.hpp"
#include <vector>

/**
 * A mixin class to make objects nameable. To test detecting supported interfaces of objects
 */
class Nameable {
private:
    std::string name;

public:
    void setName(std::string&& rhs)
    {
        name = std::move(rhs);
    }

    std::string getName()
    {
        return name;
    }

    void* implements(cbox::obj_type_t iface)
    {
        if (iface == cbox::interfaceId<Nameable>()) {
            return this;
        }
        return nullptr;
    }

protected:
    Nameable()
        : name("name-not-set")
    {
    }
    virtual ~Nameable() = default;
};

class LongIntObject : public cbox::ObjectBase<1000> {
private:
    uint32_t obj;

public:
    LongIntObject()
        : obj(0)
    {
    }

    LongIntObject(uint32_t rhs)
        : obj(std::move(rhs))
    {
    }

    virtual ~LongIntObject() = default;

    bool operator==(const LongIntObject& rhs) const
    {
        return obj == rhs.obj;
    }

    virtual cbox::CboxError read(const cbox::PayloadCallback& callback) const override final
    {
        cbox::Payload payload(objectId(), typeId(), 0);
        cbox::appendToByteVector(payload.content, obj);
        return callback(payload);
    }

    virtual cbox::CboxError readStored(const cbox::PayloadCallback& callback) const override final
    {
        return read(callback);
    }

    virtual cbox::CboxError write(const cbox::Payload& payload) override final
    {
        uint32_t newValue = 0;
        if (cbox::readFromByteVector(payload.content, newValue, 0)) {
            obj = newValue;
            return cbox::CboxError::OK;
        }
        return cbox::CboxError::NETWORK_READ_ERROR;
    }

    operator uint32_t() const
    {
        uint32_t copy = obj;
        return copy;
    }

    uint32_t value() const
    {
        return obj;
    }

    void value(uint32_t v)
    {
        obj = v;
    }
};

// variable size object of multiple long ints
class LongIntVectorObject final : public cbox::ObjectBase<1001> {
public:
    LongIntVectorObject()
        : values()
    {
    }
    LongIntVectorObject(std::initializer_list<LongIntObject> l)
        : values(l)
    {
    }

    cbox::CboxError read(const cbox::PayloadCallback& callback) const override
    {
        cbox::Payload payload(objectId(), typeId(), 0);

        // first write number of elements as uint16_t
        cbox::appendToByteVector(payload.content, uint16_t(values.size()));

        // write value for all elements
        for (auto& value : values) {
            cbox::appendToByteVector(payload.content, value.value());
        }

        return callback(payload);
    }

    cbox::CboxError readStored(const cbox::PayloadCallback& callback) const override
    {
        return read(callback);
    }

    cbox::CboxError write(const cbox::Payload& payload) override
    {
        uint16_t newSize = 0;
        if (!cbox::readFromByteVector(payload.content, newSize, 0)) {
            return cbox::CboxError::INVALID_BLOCK;
        }

        size_t pos = sizeof(newSize);
        values.resize(newSize);
        for (auto& value : values) {
            uint32_t content = 0;
            if (!cbox::readFromByteVector(payload.content, content, pos)) {
                return cbox::CboxError::NETWORK_READ_ERROR;
            }
            pos += sizeof(content);
            value.value(content);
        }
        return cbox::CboxError::OK;
    }

    bool operator==(const LongIntVectorObject& rhs) const
    {
        return values == rhs.values;
    }

    std::vector<LongIntObject> values;
};

/**
 * A simple class to test:
 * - updating objects at the interval they request
 * - different output, input and persisted streams
 */
class UpdateCounter final : public cbox::ObjectBase<1002> {
private:
    uint16_t _interval; // writable and persisted
    uint16_t _count;    // not writable

public:
    UpdateCounter()
        : _interval(1000)
        , _count(0)
    {
    }
    ~UpdateCounter() = default;

    uint16_t count()
    {
        return _count;
    }

    uint16_t interval()
    {
        return _interval;
    }

    cbox::CboxError read(const cbox::PayloadCallback& callback) const override
    {
        cbox::Payload payload(objectId(), typeId(), 0);

        // stream out all values
        if (!cbox::appendToByteVector(payload.content, _interval)) {
            return cbox::CboxError::NETWORK_WRITE_ERROR;
        }
        if (!cbox::appendToByteVector(payload.content, _count)) {
            return cbox::CboxError::NETWORK_WRITE_ERROR;
        }

        return callback(payload);
    }

    cbox::CboxError readStored(const cbox::PayloadCallback& callback) const override
    {
        cbox::Payload payload(objectId(), typeId(), 0);
        cbox::appendToByteVector(payload.content, _interval);

        return callback(payload);
    }

    cbox::CboxError write(const cbox::Payload& payload) override
    {
        uint16_t newInterval{0};
        if (!cbox::readFromByteVector(payload.content, newInterval, 0)) {
            return cbox::CboxError::NETWORK_READ_ERROR;
        }
        if (newInterval < 10) {
            return cbox::CboxError::INVALID_BLOCK;
        }

        _interval = newInterval;
        return cbox::CboxError::OK;
    }

    cbox::update_t updateHandler(const cbox::update_t& now) override
    {
        ++_count;
        return now + _interval;
    }
};

class NameableLongIntObject final : public LongIntObject, public Nameable {
public:
    NameableLongIntObject(uint32_t rhs = 0)
        : LongIntObject(rhs)
    {
    }
    ~NameableLongIntObject() = default;

    static cbox::obj_type_t staticTypeId()
    {
        return 1003;
    }

    // need to override typeId, otherwise it would inherit from LongIntObject
    cbox::obj_type_t typeId() const override
    {
        return staticTypeId();
    }

    // needs special handling due to multiple inheritance
    void* implements(cbox::obj_type_t iface) override
    {
        if (iface == staticTypeId()) {
            return this; // me!
        }
        if (auto ptr = LongIntObject::implements(iface)) {
            return ptr; // this pointer with LongIntOjbect offset
        }
        if (auto ptr = Nameable::implements(iface)) {
            return ptr; // this pointer with nameable offset
        }
        return nullptr;
    }
};

class PtrLongIntObject final : public cbox::ObjectBase<1005> {
private:
    cbox::CboxPtr<LongIntObject> ptr1;
    cbox::CboxPtr<LongIntObject> ptr2;

public:
    PtrLongIntObject()
    {
    }
    ~PtrLongIntObject() = default;

    cbox::CboxError read(const cbox::PayloadCallback& callback) const override
    {
        cbox::Payload payload(objectId(), typeId(), 0);

        if (!cbox::appendToByteVector(payload.content, ptr1.getId())) {
            return cbox::CboxError::NETWORK_WRITE_ERROR;
        }
        if (!cbox::appendToByteVector(payload.content, ptr2.getId())) {
            return cbox::CboxError::NETWORK_WRITE_ERROR;
        }

        auto sptr1 = ptr1.lock();
        auto sptr2 = ptr2.lock();
        bool valid1 = bool(sptr1);
        bool valid2 = bool(sptr2);
        uint32_t value1 = 0;
        uint32_t value2 = 0;
        if (sptr1) {
            value1 = sptr1->value();
        }
        if (sptr2) {
            value2 = sptr2->value();
        }
        bool success = true
                       && cbox::appendToByteVector(payload.content, valid1)
                       && cbox::appendToByteVector(payload.content, valid2)
                       && cbox::appendToByteVector(payload.content, value1)
                       && cbox::appendToByteVector(payload.content, value2);

        if (!success) {
            return cbox::CboxError::NETWORK_WRITE_ERROR;
        }

        return callback(payload);
    }

    cbox::CboxError readStored(const cbox::PayloadCallback& callback) const override
    {
        cbox::Payload payload(objectId(), typeId(), 0);

        if (!cbox::appendToByteVector(payload.content, ptr1.getId())) {
            return cbox::CboxError::NETWORK_WRITE_ERROR;
        }
        if (!cbox::appendToByteVector(payload.content, ptr2.getId())) {
            return cbox::CboxError::NETWORK_WRITE_ERROR;
        }
        return callback(payload);
    }

    cbox::CboxError write(const cbox::Payload& payload) override
    {
        auto newId1 = cbox::obj_id_t{0};
        auto newId2 = cbox::obj_id_t{0};
        if (!cbox::readFromByteVector(payload.content, newId1, 0)) {
            return cbox::CboxError::NETWORK_READ_ERROR;
        }
        if (!cbox::readFromByteVector(payload.content, newId2, 0 + sizeof(cbox::obj_id_t))) {
            return cbox::CboxError::NETWORK_READ_ERROR;
        }

        ptr1.setId(newId1);
        ptr2.setId(newId2);
        return cbox::CboxError::OK;
    }
};

class MockStreamObject final : public cbox::ObjectBase<1006> {
public:
    MockStreamObject() = default;
    ~MockStreamObject() = default;

    std::function<cbox::CboxError(const cbox::PayloadCallback&)> readFunc = [](const cbox::PayloadCallback&) { return cbox::CboxError::OK; };
    std::function<cbox::CboxError(const cbox::PayloadCallback&)> readStoredFunc = [](const cbox::PayloadCallback&) { return cbox::CboxError::OK; };
    std::function<cbox::CboxError(const cbox::Payload&)> writeFunc = [](const cbox::Payload&) { return cbox::CboxError::OK; };

    cbox::CboxError read(const cbox::PayloadCallback& callback) const override
    {
        return readFunc(callback);
    }

    cbox::CboxError readStored(const cbox::PayloadCallback& callback) const override
    {
        return readStoredFunc(callback);
    }

    cbox::CboxError write(const cbox::Payload& payload) override
    {
        return writeFunc(payload);
    }

    cbox::update_t updateHandler(const cbox::update_t& now) override
    {
        return cbox::Object::next_update_never(now);
    }
};
