#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);


}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_2_clicked()
{
     int Counts=0;
   QNetworkAccessManager *manager = new QNetworkAccessManager(this);
    ui->pushButton->setText("ttyty");
    connect(manager, SIGNAL(finished(QNetworkReply*)),
            this, SLOT(replyFinished(QNetworkReply*)));
    QString URLaddress ="http://"+ui->lineEdit->text();
    ui->label->setText(URLaddress);
    manager->get(QNetworkRequest(QUrl(URLaddress)));
    //if (Counts<500)
     // {
//          RepeatGET();

//          ui->label->setText(QString::number(Counts));

//          Counts++;

//      }

}

void MainWindow::replyFinished(QNetworkReply* reply)
{


      QByteArray content = reply->readAll();
      ui->textEdit->setPlainText(content.data());

}

void MainWindow::RepeatGET()
{
   QNetworkAccessManager *manager = new QNetworkAccessManager(this);
    connect(manager, SIGNAL(finished(QNetworkReply*)),
            this, SLOT(replyFinished(QNetworkReply*)));
    manager->get(QNetworkRequest(QUrl("http://strategium.ru")));


}

void MainWindow::on_pushButton_3_clicked()
{

}
