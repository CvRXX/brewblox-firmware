#pragma once

#include <memory>

template <typename T>
class ControlPtr {
public:
    virtual std::shared_ptr<T> lock() = 0;
    virtual std::shared_ptr<const T> lock() const = 0;
};
