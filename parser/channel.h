#ifndef CHANNEL_H
#define CHANNEL_H

#include "common/common.h"
#include "common/property.h"
#include "item.h"

using Items = QVector<shared_ptr<Item>>;

class Channel: public Property {
public:
    Channel();
    Channel(const Channel& chan) = delete;
    ~Channel()=default;

    virtual QString Name() override { return "channel"; }

    QString GetTitle();
    void SetTitle(const QString& str);

    QString GetDesc();
    void SetDesc(const QString& str);

    QString GetLink();
    void SetLink(const QString& str);

    int GetTTL();
    void setTTL(const int _ttl);

    QString GetSource();
    void SetSource(const QString& str);

    shared_ptr<Items> GetItems();
    void AddItem(const shared_ptr<Item>& _item);
    void ClearItem();

    void DeepCopy(const Channel& chan);

private:
    virtual QString get(const QString& key) override;
    virtual void set(const QString& key, const QString& element) override;
    
private:
    QString description;
    QString title;
    QString link;
    QString csource;
    int     ttl;
    shared_ptr<Items> items;
    QSet<QString> itemnames;
};

#endif