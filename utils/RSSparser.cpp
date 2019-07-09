#include "RSSparser.h"

RSSParser::RSSParser(const string& _data) {
    doc.Parse(_data.c_str());
    handle = std::make_shared<tinyxml2::XMLHandle>(doc);
    currentElement = handle->FirstChildElement().ToElement();
}

RSSParser::RSSParser(RSSParser&& parser) {
    doc.DeepCopy(&(parser.doc));
    handle = std::make_shared<tinyxml2::XMLHandle>(doc);
    currentElement = handle->FirstChildElement().ToElement();
}

bool RSSParser::expect(const string& _element) {
    if(currentElement->Name() != _element) {
        return false;
    }
    return true;
}

bool RSSParser::next() {
    if(currentElement->NextSibling()){
        currentElement = currentElement->NextSibling()->ToElement();
        return true;
    }
    return false;
}


bool RSSParser::changeName(const string& _element, const char* dir = "peer") {
    auto parent = currentElement->Parent()->ToElement();
    if(strcmp(dir, "child") == 0) {
        currentElement = currentElement->FirstChildElement(_element.c_str());
    } else if(strcmp(dir, "peer") == 0) {
        currentElement = parent->FirstChildElement(_element.c_str());
        return true;
    } else if(strcmp(dir, "parent") == 0) {
        parent = parent->Parent()->ToElement();
        currentElement = parent->FirstChildElement(_element.c_str());
        return true;
    }
    return false;
}

string RSSParser::current() {
    return string(currentElement->GetText());
}

shared_ptr<Channel> RSSParser::Parse() {
    auto res = std::make_shared<Channel>();
    
}