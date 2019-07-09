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
RSSParser() = default;
explicit RSSParser(const string& _data);
RSSParser(const RSSParser&) = delete;
RSSParser(RSSParser&& parser);
~RSSParser();

void SetDoc(const string& _data);
shared_ptr<Channel> Parse();

private:
bool expect(const string& _element);
void next();
bool changeName(
    const string& _element, const char* dir = "peer"); // peer or parent 
shared_ptr<Item> getItem();

tinyxml2::XMLDocument              doc;
tinyxml2::XMLHandle*               handle;
tinyxml2::XMLElement*              currentElement;
};

#endif 
