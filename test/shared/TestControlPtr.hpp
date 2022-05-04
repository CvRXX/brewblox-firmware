#pragma once

#include "control/ControlPtr.hpp"

/**
 * Simple implementation of ControlPtr that allows for easy initialization
 * and access to the backing shared_ptr.
 *
 * TestControlPtr is constructed using the make() factory function.
 * make() accepts one of three overloads:
 * - A raw pointer. TestControlPtr will take ownership, and wrap it in a shared_ptr.
 * - A shared pointer. This will be statically cast to shared_ptr<T> and copied.
 * - Another TestControlPtr. The ptr member will be statically cast to shared_ptr<T> and copied.
 *
 * With this approach, new objects are created from raw pointers,
 * and previously shared pointers can be mirrored with a different (but compatible) type.
 *
 *     TestControlPtr<Derived> derived = TestControlPtr<Derived>::make(new Derived());
 *     TestControlPtr<Base> base = TestControlPtr<Base>::make(derived);
 *
 * In the above snippet, we now have one unique `Derived` object,
 * tracked by a shared_ptr<Derived>, and a shared_ptr<Base>.
 *
 */
template <typename T>
class TestControlPtr final : public ControlPtr<T> {
public:
    std::shared_ptr<T> ptr;

protected:
    TestControlPtr(std::shared_ptr<T>&& ptr_)
        : ptr(ptr_)
    {
    }

public:
    std::shared_ptr<T> lock() override
    {
        return ptr;
    }

    std::shared_ptr<const T> lock() const override
    {
        return ptr;
    }

    template <typename SrcT>
    static TestControlPtr<T> make(SrcT* arg)
    {
        return TestControlPtr<T>(std::shared_ptr<T>(arg));
    }

    template <typename SrcT>
    static TestControlPtr<T> make(std::shared_ptr<SrcT>& arg)
    {
        return TestControlPtr<T>(std::static_pointer_cast<T>(arg));
    }

    template <typename SrcT>
    static TestControlPtr<T> make(TestControlPtr<SrcT>& arg)
    {
        return TestControlPtr<T>(std::static_pointer_cast<T>(arg.ptr));
    }
};
