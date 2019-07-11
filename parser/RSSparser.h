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
RSSParser(const RSSParser&) = delete;
~RSSParser();

bool SetDoc(const QString& _data);
shared_ptr<Channel> Parse();

private:
void next();
bool changeName(
    const QString& _element, const QString& dir = "peer"); // peer or parent 
shared_ptr<Item> getItem();

tinyxml2::XMLDocument              doc;
tinyxml2::XMLHandle*               handle;
tinyxml2::XMLElement*              currentElement;
};

#endif 
