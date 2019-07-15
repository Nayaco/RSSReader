#ifndef VIEWMODEL_H
#define VIEWMODEL_H

#include "common/common.h"
#include "common/middleware.h"
#include "common/property.h"

class ViewModel : public Middleware {
    Q_OBJECT
public:
    ViewModel() = default;
    ~ViewModel() = default;

    virtual QString Name() {
		return "viewmodel";
	}

    void BindModel(shared_ptr<Middleware>);

    virtual shared_ptr<QVector<PropertyInstance>> Get(const QString&, const QVector<QString>&) override;

    virtual shared_ptr<QVector<QString>>  GetMeta(const QString&) override;
public
slots:
	virtual void UpStreamReciever(const QString& _data, const QString& msg, const QString& target) override;

	virtual void DownStreamReciever(const QString& _data, const QString& msg, const QString& target) override;

signals:
	void SIG_PROPS_CHANGED(const QString& _data, const QString& msg, const QString& target);

	void SIG_CMD_FAIL(const QString& _data, const QString& msg, const QString& target);

	void SIG_CMD(const QString& _data, const QString& msg, const QString& target);

private:
    QMap<QString, shared_ptr<Middleware>> models;
    
    // dirty table (For Virtual DOM)
    QMap<QString, bool> unsync;

    shared_ptr<QVector<QString>> meta;
    int counter;
    int global_counter;
    bool init;
};

#endif




#include "viewmodel.h"
#include <QDebug>
void ViewModel::BindModel(shared_ptr<Middleware> modelsink) {
    QString name = modelsink->Name();
    models[name] = modelsink->GetChild();
    unsync[name] = true;
    connect(
        modelsink.get(), 
        SIGNAL(SIG_TRI(const QString&, const QString&, const QString&)),
        this, 
        SLOT(UpStreamReciever(const QString&, const QString&, const QString&))
    );
    
    connect(this, 
        SIGNAL(SIG_CMD(const QString&, const QString&, const QString&)),
        modelsink.get(),
        SLOT(DownStreamReciever(const QString&, const QString&, const QString&))
    );
}

void ViewModel::UpStreamReceiver(
    const QString& _data, const QString& msg, const QString& target) {
    qDebug() << _data << msg << target;
    if(_data == "channel" && msg == "update") {
        if(target == "failed") {
            emit SIG_CMD("channel", "update", meta->value(counter));
            return;
        }
        counter++;
        global_counter++;
        if(counter < meta->size())
            emit SIG_CMD("channel", "update", meta->value(counter));
        else {
            if (init == false) {
                emit SIG_TRI("channel", "update", "ok");
            } else {
                init = false;
                emit SIG_TRI("channel", "init", "ok");
            }
        }
        return;
    }
    if(_data == "channel" && msg == "init") {
        meta = models["channel"]->GetMeta();
        counter = 0;
        global_counter++;
        init = true;
        if(meta->size() > 0)
            emit SIG_CMD("channel", "update", meta->value(counter));
        else 
            emit SIG_TRI("channel", "init", "ok");
        return;
    }
    if(target == "ok") {
        unsync[_data] = true;
        emit SIG_TRI(_data, msg, target);
    }
    else if(target == "failed") {
        unsync[_data] = false;
        emit SIG_CMD_FAIL(_data, msg, target);
    }
}
void ViewModel::DownStreamReciever(
    const QString& _data, const QString& msg, const QString& target) {
    if(_data == "channel" && msg == "update") {
        meta = models["channel"]->GetMeta();
        counter = 0;
        if(meta->size() > 0)
            emit SIG_CMD("channel", "update", meta->value(counter));
        return; 
    }
    emit SIG_CMD(_data, msg, target);
}

shared_ptr<QVector<PropertyInstance>> ViewModel::Get(
    const QString& _data, const QVector<QString>& targets) {
    unsync[_data] = false;
    if(models.find(_data) != models.end())
        return models[_data]->Get(targets);
    return nullptr;
}
shared_ptr<QVector<QString>>  ViewModel::GetMeta(const QString& _data) {
    if(models.find(_data) != models.end())
        return models[_data]->GetMeta();
    return nullptr;
}
