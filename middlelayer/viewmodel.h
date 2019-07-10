#ifndef VIEWMODEL_H
#define VIEWMODEL_H

#include "common/common.h"
#include "common/middleware.h"

class ViewModel : public Middleware<ViewModel> {
public:
    ViewModel();
    ViewModel();
public
slots:
virtual void UpStreamReciever(const QString&) override;
virtual void DownStreamReciever(const QString&) override;
signals:
void SIG_PROPS_CHANGED(const QString&);
void SIG_CMD_SENT(const QString&);
};

#endif