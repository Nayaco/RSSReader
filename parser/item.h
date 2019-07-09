#ifndef ITEM_H
#define ITEM_H

#include "common/common.h"
#include "iobject.h"

class Item: public IObject {
public:
Item();
Item(const Item& _item) = delete;
Item(const Item&& _item);
~Item()=default;

string GetTitle();
void SetTitle(const string& str);
string GetDesc();
void SetDesc(const string& str);
string GetLink();
void SetLink(const string& str);

void DeepCopy(const Item& _item);

private:
string description;
string title;
string link;
virtual string get(const string& key) override;
virtual void set(const string& key, const string& element) override;

};

#endif