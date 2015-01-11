#include "network_serv.h"


Networkserv::Networkserv(QObject *parent):QObject(parent),network_manager(new QNetworkAccessManager)
{

    //network_manager = new QNetworkAccessManager(this);
    QObject::connect(network_manager, SIGNAL(finished(QNetworkReply*)),this,SLOT(replyFinished(QNetworkReply*)));

}

Networkserv::~Networkserv()
{

}

void Networkserv::replyFinished(QNetworkReply *reply)
{
    QByteArray content = reply->readAll();
   // ui->textEdit->setPlainText(content.data());
    qDebug() << "testing";
    qDebug() << content.data();
   // QMessageBox::information(this,"test",QString::number(content.length()));
   // this->setWindowOpacity(0.75);
    QByteArray *contentout = new QByteArray(content);
    emit netwout(contentout);
}

QString Networkserv::Netw_reqw(QByteArray reqString,QString UAddress)
{
   // QByteArray requestString = "logn=222&prl=xml";
    QByteArray requestString = reqString;
    QString URLaddress = UAddress;
    //ui->label->setText(URLaddress);
    QNetworkRequest request(URLaddress);
    network_manager->post(request,requestString);

    return "test";
}


