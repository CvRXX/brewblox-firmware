#pragma once

#include <memory>

template <typename T>
class ControlPtr {
public:
    // lock fetches an object and returns a shared ptr
    // drived classes might implement side effects when the object is locked
    [[nodiscard]] virtual std::shared_ptr<T> lock() = 0;
    [[nodiscard]] virtual std::shared_ptr<const T> lock() const = 0;
    // release should undo side effects of lock() implemented in derived class if necessary
    virtual void release() = 0;

protected:
    ~ControlPtr() = default;
    ControlPtr() = default;
    ControlPtr(const ControlPtr&) = default;
    ControlPtr(ControlPtr&&) noexcept = default;
    ControlPtr& operator=(const ControlPtr&) = default;
    ControlPtr& operator=(ControlPtr&&) noexcept = default;
};
