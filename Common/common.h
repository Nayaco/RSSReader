#ifndef GLOBAL_COMMON_H
#define GLOBAL_COMMON_H

#include <memory>
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

class PropertyChangeNotification {
public:
    virtual 
};

#endif