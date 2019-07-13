#ifndef REQUEST_H
#define REQUEST_H
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QNetworkAccessManager>
class Request : public QObject
{
    Q_OBJECT
public:
    Request();
    ~Request();

    void get(const QString url);

    void post(const QString url, const QByteArray &data);
    
protected:
    virtual void OnFinished(QNetworkReply *reply, const QByteArray data, const int statusCode) = 0;

public slots:
    void RequestFinished(QNetworkReply *reply); 

private:
    QNetworkRequest httpRequest;
    QNetworkAccessManager networkAccessManager;
};
#endif