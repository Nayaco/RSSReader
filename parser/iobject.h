#ifndef IOBJECT_H
#define IOBJECT_H
#include "common/common.h"

class IObject {
public:
virtual string get(const string&) = 0;
virtual void set(const string&, const string&) = 0;
};

#endif