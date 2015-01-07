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
   QNetworkAccessManager *manager = new QNetworkAccessManager(this);
    ui->pushButton->setText("ttyty");
    connect(manager, SIGNAL(finished(QNetworkReply*)),
            this, SLOT(replyFinished(QNetworkReply*)));
    manager->get(QNetworkRequest(QUrl("http://www.cyberforum.ru")));

}
void MainWindow::replyFinished(QNetworkReply* reply)
{

      QByteArray content = reply->readAll();
      ui->textEdit->setPlainText(content.data());
}
