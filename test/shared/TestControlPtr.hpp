#pragma once

#include "control/ControlPtr.hpp"

template <typename T>
class TestControlPtr final : public ControlPtr<T> {
public:
    std::shared_ptr<T> ptr;

    TestControlPtr<T>(T* arg)
        : ptr(std::shared_ptr<T>(arg))
    {
    }

    template <typename SrcT>
    TestControlPtr<T>(SrcT* arg)
        : ptr(std::shared_ptr<T>(arg))
    {
    }

    template <typename SrcT>
    TestControlPtr<T>(std::shared_ptr<SrcT> arg)
        : ptr(std::static_pointer_cast<T>(std::move(arg)))
    {
    }

    template <typename SrcT>
    TestControlPtr<T>(const TestControlPtr<SrcT>& arg)
        : ptr(std::static_pointer_cast<T>(arg.ptr))
    {
    }

    std::shared_ptr<T> lock() override
    {
        return ptr;
    }

    std::shared_ptr<const T> lock() const override
    {
        return ptr;
    }
};
