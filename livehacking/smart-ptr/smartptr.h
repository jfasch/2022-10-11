#ifndef SMARTPTR_H
#define SMARTPTR_H

#include "sensors.h"

class SmartPtr
{
public:
    SmartPtr() : _s(nullptr) {}
    SmartPtr(Sensor* s) : _s(s) {}
    ~SmartPtr() { delete _s; }

    SmartPtr(SmartPtr& rhs)
    {
        _s = rhs._s;
        rhs._s = nullptr;
    }
    SmartPtr& operator=(SmartPtr& rhs)
    {
        if (this != &rhs) {
            delete _s;
            _s = rhs._s;
            rhs._s = nullptr;
        }
        return *this;
    }

    Sensor* operator->() { return _s; }
    const Sensor* operator->() const { return _s; }

private:
    Sensor* _s;
};

#endif
