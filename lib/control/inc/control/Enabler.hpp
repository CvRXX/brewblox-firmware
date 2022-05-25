#pragma once
#include <functional>

class Enabler {
private:
    bool _enabled;
    std::function<bool(bool arg)> _sideEffect;

public:
    Enabler(bool initialValue_ = false,
            std::function<bool(bool arg)>&& sideEffect_ = nullptr)
        : _enabled(initialValue_)
        , _sideEffect(std::move(sideEffect_))
    {
    }

    ~Enabler() = default;

    Enabler(const Enabler&) = delete;
    Enabler(Enabler&&) = delete;
    Enabler& operator=(const Enabler&) = delete;

    bool get() const
    {
        return _enabled;
    }

    void set(bool arg)
    {
        if (_sideEffect) {
            _enabled = _sideEffect(arg);
        } else {
            _enabled = arg;
        }
    }
};
