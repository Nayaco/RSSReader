#include "channel.h"

Channel::Channel()
    : title(""), description(""), link(""), ttl(0), items({}) { }

Channel::Channel(const Channel& chan)
    : title(chan.title), description(chan.description), link(chan.link), ttl(0), items(chan.items) { }

void Channel::DeepCopy(const Channel& chan) {
    title = string(chan.title);
    description = string(chan.description);
    link = string(chan.link);
    ttl  = chan.ttl;
    items = chan.items;
}

string Channel::get(const string& key) {
    if(key == "title") return title;
    if(key == "desc") return description;
    if(key == "link") return link;
}

void Channel::set(const string& key, const string& element) {
    if(key == "title") title = element;
    if(key == "desc")  description = element;
    if(key == "link")  link = element;
}

string Channel::GetTitle() { return get("title"); }
void Channel::SetTitle(const string& str) { set("title", str); }
string Channel::GetDesc() { return get("desc"); }
void Channel::SetDesc(const string& str) { set("desc", str); }
string Channel::GetLink() { return get("link"); }
void Channel::SetLink(const string& str) { set("link", str); }
int Channel::GetTTL() {return ttl;}
void Channel::setTTL(const int _ttl) { ttl = _ttl; }

vector<shared_ptr<Item>>& Channel::GetItems() { return items; }
void Channel::AddItem(const shared_ptr<Item>& _item) { items.push_back(_item); }
void Channel::ClearItem() { items.clear(); }
