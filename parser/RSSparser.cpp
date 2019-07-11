#include "RSSparser.h"

RSSParser::~RSSParser() {
    delete handle;
}

bool RSSParser::SetDoc(const QString& _data) {
    string stdString = _data.toStdString();
    doc.Parse(stdString.c_str());
    handle = new tinyxml2::XMLHandle(doc);
    currentElement = handle->FirstChildElement("rss").ToElement();
    if(!currentElement) return false;
    return true;
}

void RSSParser::next() {
    if(currentElement->NextSibling()) 
        currentElement = currentElement->NextSibling()->ToElement();
    else
        currentElement = nullptr;
}


bool RSSParser::changeName(const QString& _element, const QString& dir) {
    if(!currentElement->Parent()) return false;
    auto parent = currentElement->Parent()->ToElement();
    if(dir == "peer") {
        string stdString = _element.toStdString();
        currentElement = parent->FirstChildElement(stdString.c_str());
        return true;
    }
    else if(dir == "child") {
        string stdString = _element.toStdString();
        currentElement = currentElement->FirstChildElement(stdString.c_str());
        return true;
    } 
    else if("parent") {
        currentElement = parent;
        return true;
    }
    return false;
}

shared_ptr<Item> RSSParser::getItem() {
    auto res = std::make_shared<Item>();
    changeName("title", "child");
    res->SetTitle(QString(currentElement->GetText()));
    changeName("link");
    res->SetLink(QString(currentElement->GetText()));
    changeName("description");
    res->SetDesc(QString(currentElement->GetText()));
    changeName("", "parent");
    return res;
}



shared_ptr<Channel> RSSParser::Parse() {
    auto res = std::make_shared<Channel>();
    changeName("channel", "child");
    changeName("title", "child");
    res->SetTitle(QString(currentElement->GetText()));
    changeName("link");
    res->SetLink(QString(currentElement->GetText()));
    changeName("description");
    res->SetDesc(QString(currentElement->GetText()));
    auto oldElement = currentElement;
    changeName("ttl");
    if(currentElement) {
        QString ttl = QString(currentElement->GetText());
        res->setTTL(ttl.toInt());
    } else {
        res->setTTL(30);
        currentElement = oldElement;
    }
    
    changeName("item");
    for(;currentElement;next())
        res->AddItem(getItem());
    return res;
}