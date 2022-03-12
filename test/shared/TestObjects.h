#pragma once

#include "cbox/CboxPtr.h"
#include "cbox/DataStream.h"
#include "cbox/ObjectBase.h"
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

    void* implements(const cbox::obj_type_t& iface)
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
    ~Nameable() = default;
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

    virtual cbox::CboxError toResponse(cbox::Command& cmd) const override final
    {
        cbox::Payload payload(objectId, typeId(), 0);
        payload.content.resize(sizeof(uint32_t));
        cbox::BufferDataOut out(payload.content.data(), payload.content.size());
        out.put(obj);
        return cmd.respond(payload);
    }

    virtual cbox::CboxError toStoredResponse(cbox::Command& cmd) const override final
    {
        return toResponse(cmd);
    }

    virtual cbox::CboxError fromRequest(cbox::Command& cmd) override final
    {
        if (!cmd.request()) {
            return cbox::CboxError::OBJECT_DATA_NOT_ACCEPTED;
        }

        uint32_t newValue = 0;
        cbox::BufferDataIn in(cmd.request()->content.data(), cmd.request()->content.size());
        if (in.get(newValue)) {
            obj = newValue;
            return cbox::CboxError::OK;
        }
        return cbox::CboxError::INPUT_STREAM_READ_ERROR;
    }

    virtual cbox::update_t update(const cbox::update_t& now) override
    {
        return cbox::Object::update_never(now);
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
class LongIntVectorObject : public cbox::ObjectBase<1001> {
public:
    LongIntVectorObject()
        : values()
    {
    }
    LongIntVectorObject(std::initializer_list<LongIntObject> l)
        : values(l)
    {
    }

    virtual cbox::CboxError toResponse(cbox::Command& cmd) const override final
    {
        cbox::Payload payload(objectId, typeId(), 0);
        payload.content.resize(sizeof(uint16_t) + values.size() * sizeof(uint32_t));
        cbox::BufferDataOut out(payload.content.data(), payload.content.size());

        // first write number of elements as uint16_t
        uint16_t size = values.size();
        if (!out.put(size)) {
            return cbox::CboxError::OUTPUT_STREAM_WRITE_ERROR;
        }

        // write value for all elements
        for (auto& value : values) {
            out.put(value.value());
        }
        return cmd.respond(payload);
    }

    virtual cbox::CboxError toStoredResponse(cbox::Command& cmd) const override final
    {
        return toResponse(cmd);
    }

    virtual cbox::CboxError fromRequest(cbox::Command& cmd) override final
    {
        if (!cmd.request()) {
            return cbox::CboxError::INPUT_STREAM_READ_ERROR;
        }

        cbox::BufferDataIn in(cmd.request()->content.data(), cmd.request()->content.size());

        uint16_t newSize = 0;
        if (!in.get(newSize)) {
            return cbox::CboxError::OBJECT_DATA_NOT_ACCEPTED;
        }
        values.resize(newSize);
        for (auto& value : values) {
            uint32_t content = 0;
            if (!in.get(content)) {
                return cbox::CboxError::INPUT_STREAM_READ_ERROR;
            }
            value.value(content);
        }
        return cbox::CboxError::OK;
    }

    virtual cbox::update_t update(const cbox::update_t& now) override final
    {
        return cbox::Object::update_never(now);
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
class UpdateCounter : public cbox::ObjectBase<1002> {
private:
    uint16_t _interval; // writable and persisted
    uint16_t _count;    // not writable

public:
    UpdateCounter()
        : _interval(1000)
        , _count(0)
    {
    }
    virtual ~UpdateCounter() = default;

    uint16_t count()
    {
        return _count;
    }

    uint16_t interval()
    {
        return _interval;
    }

    virtual cbox::CboxError toResponse(cbox::Command& cmd) const override final
    {
        cbox::Payload payload(objectId, typeId(), 0);
        payload.content.resize(sizeof(_interval) + sizeof(_count));
        cbox::BufferDataOut out(payload.content.data(), payload.content.size());

        // stream out all values
        if (!out.put(_interval)) {
            return cbox::CboxError::OUTPUT_STREAM_WRITE_ERROR;
        }
        if (!out.put(_count)) {
            return cbox::CboxError::OUTPUT_STREAM_WRITE_ERROR;
        }

        return cmd.respond(payload);
    }

    virtual cbox::CboxError toStoredResponse(cbox::Command& cmd) const override final
    {
        cbox::Payload payload(objectId, typeId(), 0);
        payload.content.resize(sizeof(_interval));
        cbox::BufferDataOut out(payload.content.data(), payload.content.size());

        if (!out.put(_interval)) {
            return cbox::CboxError::PERSISTED_STORAGE_WRITE_ERROR;
        }

        return cmd.respond(payload);
    }

    virtual cbox::CboxError fromRequest(cbox::Command& cmd) override final
    {
        if (!cmd.request()) {
            return cbox::CboxError::OBJECT_DATA_NOT_ACCEPTED;
        }

        cbox::BufferDataIn in(cmd.request()->content.data(), cmd.request()->content.size());

        uint16_t newInterval;

        if (!in.get(newInterval)) {
            return cbox::CboxError::INPUT_STREAM_READ_ERROR;
        }
        if (newInterval < 10) {
            return cbox::CboxError::OBJECT_DATA_NOT_ACCEPTED;
        }

        _interval = newInterval;
        return cbox::CboxError::OK;
    }

    virtual cbox::update_t update(const cbox::update_t& now) override final
    {
        ++_count;
        return now + _interval;
    }
};

class NameableLongIntObject : public LongIntObject, public Nameable {
public:
    NameableLongIntObject(uint32_t rhs = 0)
        : LongIntObject(rhs)
    {
    }
    virtual ~NameableLongIntObject() = default;

    static cbox::obj_type_t staticTypeId()
    {
        return 1003;
    }

    // need to override typeId, otherwise it would inherit from LongIntObject
    virtual cbox::obj_type_t typeId() const override
    {
        return staticTypeId();
    }

    // needs special handling due to multiple inheritance
    virtual void* implements(const cbox::obj_type_t& iface) override final
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

class PtrLongIntObject : public cbox::ObjectBase<1005> {
private:
    cbox::CboxPtr<LongIntObject> ptr1;
    cbox::CboxPtr<LongIntObject> ptr2;

public:
    PtrLongIntObject()
    {
    }
    virtual ~PtrLongIntObject() = default;

    virtual cbox::CboxError toResponse(cbox::Command& cmd) const override final
    {
        cbox::Payload payload(objectId, typeId(), 0);
        payload.content.resize((sizeof(cbox::obj_id_t) + sizeof(bool) + sizeof(uint32_t)) * 2);
        cbox::BufferDataOut out(payload.content.data(), payload.content.size());

        if (!out.put(ptr1.getId())) {
            return cbox::CboxError::OUTPUT_STREAM_WRITE_ERROR;
        }
        if (!out.put(ptr2.getId())) {
            return cbox::CboxError::OUTPUT_STREAM_WRITE_ERROR;
        }

        auto sptr1 = ptr1.const_lock();
        auto sptr2 = ptr2.const_lock();
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
        bool success = out.put(valid1);
        success &= out.put(valid2);
        success &= out.put(value1);
        success &= out.put(value2);

        if (!success) {
            return cbox::CboxError::OUTPUT_STREAM_WRITE_ERROR;
        }

        return cmd.respond(payload);
    }

    virtual cbox::CboxError toStoredResponse(cbox::Command& cmd) const override final
    {
        cbox::Payload payload(objectId, typeId(), 0);
        payload.content.resize(sizeof(cbox::obj_id_t) * 2);
        cbox::BufferDataOut out(payload.content.data(), payload.content.size());

        if (!out.put(ptr1.getId())) {
            return cbox::CboxError::OUTPUT_STREAM_WRITE_ERROR;
        }
        if (!out.put(ptr2.getId())) {
            return cbox::CboxError::OUTPUT_STREAM_WRITE_ERROR;
        }
        return cmd.respond(payload);
    }

    virtual cbox::CboxError fromRequest(cbox::Command& cmd) override final
    {
        if (!cmd.request()) {
            return cbox::CboxError::OBJECT_DATA_NOT_ACCEPTED;
        }

        cbox::BufferDataIn in(cmd.request()->content.data(), cmd.request()->content.size());

        cbox::obj_id_t newId1, newId2;
        if (!in.get(newId1)) {
            return cbox::CboxError::INPUT_STREAM_READ_ERROR;
        }
        if (!in.get(newId2)) {
            return cbox::CboxError::INPUT_STREAM_READ_ERROR;
        }

        ptr1.setId(newId1);
        ptr2.setId(newId2);
        return cbox::CboxError::OK;
    }

    virtual cbox::update_t update(const cbox::update_t& now) override
    {
        return cbox::Object::update_never(now);
    }
};

class MockStreamObject : public cbox::ObjectBase<1006> {
public:
    MockStreamObject() = default;
    virtual ~MockStreamObject() = default;

    std::function<cbox::CboxError(cbox::Command&)> readFunc = [](cbox::Command& /*out*/) { return cbox::CboxError::OK; };
    std::function<cbox::CboxError(cbox::Command&)> readPersistedFunc = [](cbox::Command& /*in*/) { return cbox::CboxError::OK; };
    std::function<cbox::CboxError(cbox::Command&)> writeFunc = [](cbox::Command& /*out*/) { return cbox::CboxError::OK; };

    virtual cbox::CboxError toResponse(cbox::Command& cmd) const override final
    {
        return readFunc(cmd);
    }

    virtual cbox::CboxError toStoredResponse(cbox::Command& cmd) const override final
    {
        return readPersistedFunc(cmd);
    }

    virtual cbox::CboxError fromRequest(cbox::Command& cmd) override final
    {
        return writeFunc(cmd);
    }

    virtual cbox::update_t update(const cbox::update_t& now) override
    {
        return cbox::Object::update_never(now);
    }
};
