#ifndef IOBJECT_H
#define IOBJECT_H
#include "common/common.h"

class IObject {
public:
virtual QString get(const QString&) = 0;
virtual void set(const QString&, const QString&) = 0;
};

#endif