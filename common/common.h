#ifndef GLOBAL_COMMON_H
#define GLOBAL_COMMON_H

#include <memory>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <cstdint>

typedef unsigned char uchar;
#if defined(_WIN32) 
typedef uint64_t uint64;
#include <windows.h>
#elif defined(__unix__) || defined(__APPLE__)
typedef uint64_t uint64;
#include <unistd.h>
#endif
#include <string>
#include <vector>
#include <queue>
#include <list>
#include <map>
#include <unordered_map>

using std::shared_ptr;
using std::vector;
using std::string;

template<typename ...Args>
class CommmandBase {
protected:
    static const int arg_size = sizeof...(Args);
public:
    virtual void Bind(const Args &...arguments) = 0;
    virtual void Exec() = 0;
};

template<typename T>
class NotificationImpl {
public:
    void AddNotification(const shared_ptr<T>&& notification) throw() {
        notifications.push_back(notification);
    }
    void Clear() throw() {
        notifications.clear();
    }

protected:
    vector<shared_ptr<T>> notifications;
};

template<typename T>
class PropertyNotification {
public:
    virtual void OnPropertiyChanged(const T& props) = 0;
};

template<typename T>
class CommandNotification {
public:
    virtual void OnCommandComplete();

};

#endif