#include "RSSparser.h"
RSSParser::RSSParser(const string& _data) {
    doc.Parse(_data.c_str());
    handle = new tinyxml2::XMLHandle(doc);
    currentElement = handle->FirstChildElement("rss").ToElement();
}

RSSParser::RSSParser(RSSParser&& parser) {
    doc.DeepCopy(&(parser.doc));
    handle = new tinyxml2::XMLHandle(doc);
    currentElement = handle->FirstChildElement("rss").ToElement();
}
RSSParser::~RSSParser() {
    delete handle;
}

void RSSParser::SetDoc(const string& _data) {
    doc.Parse(_data.c_str());
    handle = new tinyxml2::XMLHandle(doc);
    currentElement = handle->FirstChildElement("rss").ToElement();
}

bool RSSParser::expect(const string& _element) {
    if(currentElement->Name() != _element) {
        return false;
    }
    return true;
}

void RSSParser::next() {
    if(currentElement->NextSibling()) 
        currentElement = currentElement->NextSibling()->ToElement();
    else 
        currentElement = nullptr;
}


bool RSSParser::changeName(const string& _element, const char* dir) {
    auto parent = currentElement->Parent()->ToElement();
    if(strcmp(dir, "peer") == 0) {
        currentElement = parent->FirstChildElement(_element.c_str());
        return true;
    }
    else if(strcmp(dir, "child") == 0) {
        currentElement = currentElement->FirstChildElement(_element.c_str());
        return true;
    } else if(strcmp(dir, "parent") == 0) {
        currentElement = parent;
        return true;
    }
    return false;
}

shared_ptr<Item> RSSParser::getItem() {
    auto res = std::make_shared<Item>();
    changeName("title", "child");
    res->SetTitle(string(currentElement->GetText()));
    changeName("link");
    res->SetLink(string(currentElement->GetText()));
    changeName("description");
    res->SetDesc(string(currentElement->GetText()));
    changeName("", "parent");
    return res;
}



shared_ptr<Channel> RSSParser::Parse() {
    auto res = std::make_shared<Channel>();
    changeName("channel", "child");
    changeName("title", "child");
    res->SetTitle(string(currentElement->GetText()));
    changeName("link");
    res->SetLink(string(currentElement->GetText()));
    changeName("description");
    res->SetDesc(string(currentElement->GetText()));
    
    changeName("item");
    
    for(;currentElement;next())
        res->AddItem(getItem());
    return res;
}