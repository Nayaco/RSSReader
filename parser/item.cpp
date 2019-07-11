#include "item.h"

Item::Item()
    : title(""), description(""), link("") { }

void Item::DeepCopy(const Item& _item) {
    title = QString(_item.title);
    description = QString(_item.description);
    link = QString(_item.link);
}

QString Item::get(const QString& key) {
    if(key == "title") return title;
    if(key == "desc") return description;
    if(key == "link") return link;
}

void Item::set(const QString& key, const QString& element) {
    if(key == "title") title = element;
    if(key == "desc") description = element;
    if(key == "link") link = element;
}

QString Item::GetTitle() { return get("title"); }
void Item::SetTitle(const QString& str) { set("title", str); }
QString Item::GetDesc() { return get("desc"); }
void Item::SetDesc(const QString& str) { set("desc", str); }
QString Item::GetLink() { return get("link"); }
void Item::SetLink(const QString& str) { set("link", str); }