#ifndef NETWORK_SERV_H
#define NETWORK_SERV_H

#include <QtNetwork/QNetworkRequest>
#include <QtNetwork/QNetworkAccessManager>
#include <QtNetwork/QNetworkReply>
#include <QDebug>
#include <QObject>
class Networkserv : public QObject

{
    Q_OBJECT

signals:
    void netwout(QByteArray* replydata);
public slots:
    void replyFinished(QNetworkReply* reply);
public:
    explicit Networkserv(QObject *parent);
    QString Netw_reqw(QByteArray reqString,QString UAddress);
    ~Networkserv();
private:
    QObject *parent;
    QNetworkAccessManager *network_manager;


};



#endif // NETWORK_H
