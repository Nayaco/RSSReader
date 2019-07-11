#ifndef ITEM_H
#define ITEM_H

#include "common/common.h"
#include "iobject.h"

class Item: public IObject {
public:
Item();
~Item()=default;
Item(const Item& _item) = delete;

QString GetTitle();
void SetTitle(const QString& str);
QString GetDesc();
void SetDesc(const QString& str);
QString GetLink();
void SetLink(const QString& str);

void DeepCopy(const Item& _item);

private:
QString description;
QString title;
QString link;
virtual QString get(const QString& key) override;
virtual void set(const QString& key, const QString& element) override;

};

#endif