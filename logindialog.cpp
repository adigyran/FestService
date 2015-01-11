#include "logindialog.h"
#include "ui_logindialog.h"

logindialog::logindialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::logindialog)
{
    ui->setupUi(this);
   // QWidget *Passwredit = new QWidget(ui->label_password);
}

logindialog::~logindialog()
{
    delete ui;
}

void logindialog::on_lineEdit_password_returnPressed()
{

}


