#pragma once

#include <memory>

template <typename T>
class ControlPtr {
public:
    virtual std::shared_ptr<T> lock() = 0;
    virtual std::shared_ptr<const T> lock() const = 0;
};

template <typename SrcT, typename T>
class ControlPtrAdapter final : public ControlPtr<T> {
private:
    ControlPtr<SrcT>& src;

public:
    ControlPtrAdapter(ControlPtr<SrcT>& src_)
        : src(src_)
    {
    }
    ~ControlPtrAdapter() = default;

    std::shared_ptr<T> lock()
    {
        return src.lock();
    }

    std::shared_ptr<const T> lock() const
    {
        return src.lock();
    }
};
