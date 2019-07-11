#ifndef VIEWMODEL_H
#define VIEWMODEL_H

#include "common/common.h"
#include "common/middleware.h"
#include "model/model.h"

class ViewModel : public Middleware<ViewModel> {
public:
    ViewModel();
    ~ViewModel();
    void BindModel(shared_ptr<Model>);
public
slots:
virtual void ChannelUpStreamFailureHandler(const QString&);
virtual void UpStreamReciever(const QString&) override;

virtual void ChannelDownStreamReciever(const QString&, const QString&);
virtual void DownStreamReciever(const QString&) override;
signals:
void SIG_PROPS_CHANGED(const QString&);
void SIG_CMD_CADD(const QString&);
void SIG_CMD_CUPDATE(const QString&);
void SIG_CMD_CDELETE(const QString&);
void SIG_CMD_FAIL(const QString&);
};

#endif