#ifndef CHANNEL_H
#define CHANNEL_H

#include "common/common.h"
#include "iobject.h"
#include "item.h"

using Items = vector<shared_ptr<Item>>;

class Channel: public IObject {
public:
Channel();
~Channel()=default;
Channel(const Channel& chan) = delete;

QString GetTitle();
void SetTitle(const QString& str);
QString GetDesc();
void SetDesc(const QString& str);
QString GetLink();
void SetLink(const QString& str);
int GetTTL();
void setTTL(const int _ttl);


shared_ptr<Items> GetItems();
void AddItem(const shared_ptr<Item>& _item);
void ClearItem();

void DeepCopy(const Channel& chan);

private:
QString description;
QString title;
QString link;
int     ttl;
shared_ptr<Items> items;

virtual QString get(const QString& key) override;
virtual void set(const QString& key, const QString& element) override;

};

#endif