#include "logindialog.h"
#include "ui_logindialog.h"
#include <QKeyEvent>
#include <QDebug>
#include <QMessageBox>



logindialog::logindialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::logindialog)
{
    ui->setupUi(this);
    ui->lineEdit_password->setEchoMode(QLineEdit::PasswordEchoOnEdit);
    servicenet = new Networkserv(this);
    connect(servicenet,SIGNAL(netwout(QByteArray*)),this,SLOT(Netwrkinput(QByteArray*)));



}

logindialog::~logindialog()
{
    delete ui;
}

void logindialog::on_lineEdit_password_returnPressed()
{

    asseptloginpass();

}

void logindialog::asseptloginpass()
{
    if(ui->lineEdit_login->text().size()==0)
    {
       QMessageBox::warning(this,"Ошибка",QString("Вы не ввели логин"));
       login_check = false;
    }
    else
    {
        login_check = true;
    }
    if(ui->lineEdit_password->text().size()==0)
    {
        QMessageBox::warning(this,"Ошибка",QString("Вы не ввели пароль"));
        pass_check = false;
    }
    else
    {
        pass_check = true;
    }
    if (pass_check && login_check)
    {
        qDebug() << "Проверка пароля";
        ui->lineEdit_login->setReadOnly(true);
        ui->lineEdit_password->setReadOnly(true);
        QByteArray Reqw = "login="+ui->lineEdit_login->text().toUtf8()+"&password="+ui->lineEdit_password->text().toUtf8();
        QString TRT =  servicenet->Netw_reqw(Reqw,QString("http://qt.adigyran.net.ru"));

    }

}


void logindialog::Netwrkinput(QByteArray* replydata)
{
    qDebug() << replydata->data();
    if (replydata->data()=="'adigyran'correct")
    {
        qDebug() << "corrected";
        ui->lineEdit_login->setReadOnly(false);
        ui->lineEdit_password->setReadOnly(false);

    }
}



void logindialog::on_pushButton_login_clicked()
{
    asseptloginpass();
}

void logindialog::on_pushButton_cancel_clicked()
{

QWidgetList widg = qApp->allWidgets();
foreach(QWidget* w,widg)
{
   qDebug() << w->objectName();
  //  w->show();
}




}
