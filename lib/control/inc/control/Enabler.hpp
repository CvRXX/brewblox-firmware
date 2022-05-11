#pragma once

class Enabler {
private:
    bool _enabled = true;

public:
    bool get() const
    {
        return _enabled;
    }

    void set(bool arg)
    {
        _enabled = arg;
    }
};
