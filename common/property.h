#pragma once

#include "common.h"

class Property {
    virtual QString Name() = 0;
    virtual QString get(const QString&) = 0;
    virtual void set(const QString&, const QString&) = 0;
};

using PropertyInstance = shared_ptr<Property>;