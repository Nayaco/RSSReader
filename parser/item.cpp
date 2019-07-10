#include "item.h"

Item::Item()
    : title(""), description(""), link("") { }

Item::Item(const Item& _item)
    : title(_item.title), description(_item.description), link(_item.link) { }

void Item::DeepCopy(const Item& _item) {
    title = string(_item.title);
    description = string(_item.description);
    link = string(_item.link);
}

string Item::get(const string& key) {
    if(key == "title") return title;
    if(key == "desc") return description;
    if(key == "link") return link;
}

void Item::set(const string& key, const string& element) {
    if(key == "title") title = element;
    if(key == "desc") description = element;
    if(key == "link") link = element;
}

string Item::GetTitle() { return get("title"); }
void Item::SetTitle(const string& str) { set("title", str); }
string Item::GetDesc() { return get("desc"); }
void Item::SetDesc(const string& str) { set("desc", str); }
string Item::GetLink() { return get("link"); }
void Item::SetLink(const string& str) { set("link", str); }