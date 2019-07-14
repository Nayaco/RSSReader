#include "channel.h"
#include <QDebug>
Channel::Channel()
    : title(""), description(""), link(""), ttl(0) {
        items = std::make_shared<Items>();
    }

void Channel::DeepCopy(const Channel& chan) {
    title = chan.title;
    description = chan.description;
    link = chan.link;
    ttl  = chan.ttl;
    for (auto i : *(chan.items)) {
        if(!itemnames.contains(i->GetTitle())) {
            AddItem(i);
        }
    }
}

QString Channel::get(const QString& key) {
    if(key == "source") return csource;
    if(key == "title") return title;
    if(key == "desc") return description;
    if(key == "link") return link;
}

void Channel::set(const QString& key, const QString& element) {
    if(key == "source") csource = element;
    if(key == "title")  title = element;
    if(key == "desc")   description = element;
    if(key == "link")   link = element;
}

QString Channel::GetTitle() { return get("title"); }
void Channel::SetTitle(const QString& str) { set("title", str); }
QString Channel::GetDesc() { return get("desc"); }
void Channel::SetDesc(const QString& str) { set("desc", str); }
QString Channel::GetLink() { return get("link"); }
void Channel::SetLink(const QString& str) { set("link", str); }
int Channel::GetTTL() {return ttl;}
void Channel::setTTL(const int _ttl) { ttl = _ttl; }

QString Channel::GetSource() { return get("source"); }
void Channel::SetSource(const QString& str) { set("source", str); }


shared_ptr<Items> Channel::GetItems() { return items; }
void Channel::AddItem(const shared_ptr<Item>& _item) { items->push_back(_item); itemnames.insert(_item->GetTitle()); }
void Channel::ClearItem() { items->clear(); }


