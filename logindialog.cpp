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

    }

}







void logindialog::on_pushButton_login_clicked()
{
    asseptloginpass();
}
