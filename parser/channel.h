#ifndef CHANNEL_H
#define CHANNEL_H

#include "common/common.h"
#include "iobject.h"
#include "item.h"

class Channel: public IObject {
public:
Channel();
Channel(const Channel& chan);
~Channel()=default;

string GetTitle();
void SetTitle(const string& str);
string GetDesc();
void SetDesc(const string& str);
string GetLink();
void SetLink(const string& str);
int GetTTL();
void setTTL(const int _ttl);


vector<shared_ptr<Item>>& GetItems();
void AddItem(const shared_ptr<Item>& _item);
void ClearItem();

void DeepCopy(const Channel& chan);

private:
string description;
string title;
string link;
int    ttl;
vector<shared_ptr<Item>> items;

virtual string get(const string& key) override;
virtual void set(const string& key, const string& element) override;

};

#endif