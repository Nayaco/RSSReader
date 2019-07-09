#ifndef RSS_PARSER_H
#define RSS_PARSER_H

#include "common/common.h"
#include "common/commonstream.h"
#include "externalLib/tinyxml2.h"
#include "channel.h"
#include "item.h"

enum class ParserException {
    WrongElement,
    SyntaxError,
    Unknow
};

class RSSParser {
public:
RSSParser() = delete;
explicit RSSParser(const string& _data);
RSSParser(const RSSParser&) = delete;
RSSParser(RSSParser&& parser);
~RSSParser() = default;

shared_ptr<Channel> Parse();

private:
bool expect(const string& _element);
bool next();
bool changeName(
    const string& _element, const char* dir = "peer"); // peer or parent 
string current();

tinyxml2::XMLDocument              doc;
shared_ptr<tinyxml2::XMLHandle>    handle;
tinyxml2::XMLElement*              currentElement;
};

#endif 
