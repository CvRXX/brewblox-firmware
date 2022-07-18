#pragma once

#include <memory>

template <typename T>
class ControlPtr {
public:
    [[nodiscard]] virtual std::shared_ptr<T> lock() = 0;
    [[nodiscard]] virtual std::shared_ptr<const T> lock() const = 0;

protected:
    ~ControlPtr() = default;
    ControlPtr() = default;
    ControlPtr(const ControlPtr&) = default;
    ControlPtr(ControlPtr&&) noexcept = default;
    ControlPtr& operator=(const ControlPtr&) = default;
    ControlPtr& operator=(ControlPtr&&) noexcept = default;
};
