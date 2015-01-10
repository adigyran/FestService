#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    manager = new QNetworkAccessManager(this);
     ui->pushButton->setText("ttyty");
     connect(manager, SIGNAL(finished(QNetworkReply*)),
             this, SLOT(replyFinished(QNetworkReply*)));
     decoder.DecoderFormat_QR_CODE;

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_2_clicked()
{
     int Counts=0;

    QString URLaddress ="http://"+ui->lineEdit->text();
    ui->label->setText(URLaddress);
   // manager->get(QNetworkRequest(QUrl(URLaddress)));

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
      qDebug() << "testing";
      QMessageBox::information(this,"test",QString::number(content.length()));
      this->setWindowOpacity(0.75);

}

void MainWindow::RepeatGET()
{

    manager->get(QNetworkRequest(QUrl("http://strategium.ru")));



}

void MainWindow::on_pushButton_3_clicked()
{

}
