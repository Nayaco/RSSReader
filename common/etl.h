#pragma once
#include "common.h"

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
    void AddNotification(const shared_ptr<T>& notification) throw() {
        notifications.push_back(notification);
    }
    void Clear() throw() {
        notifications.clear();
    }

protected:
    vector<shared_ptr<T>> notifications;
};

class PropertyNotification {
public:
    virtual void OnPropertiyChanged(const string& prop) = 0;
};

class CommandNotification {
public:
    virtual void OnCommandComplete(const string& cmd, bool okay) = 0;
};

template<typename T = int>
class ProxyPropertyNotification: public NotificationImpl<PropertyNotification> {
public:
    void AddPropertyNotification(const shared_ptr<PropertyNotification>& p) {
        AddNotification(p);
    } 
    void TriggerNotification(const string& str) {
        for(auto iter : notifications) {
            iter->OnPropertiyChanged(str);
        }
    } 
};

template<typename T = int>
class ProxyCommandNotification: public NotificationImpl<CommandNotification> {
public:
    void AddCommandNotification(const shared_ptr<CommandNotification>& p) {
        AddNotification(p);
    } 
    void TriggerNotification(const string& str, bool okay) {
        for(auto iter : notifications) {
            iter->OnCommandComplete(str, okay);
        }
    } 
};