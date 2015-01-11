#ifndef LOGINDIALOG_H
#define LOGINDIALOG_H

#include <QDialog>
#include <QWidget>
#include <QLineEdit>
#include <network_serv.h>

namespace Ui {
class logindialog;
}

class logindialog : public QDialog
{
    Q_OBJECT

public:
    explicit logindialog(QWidget *parent = 0);
    ~logindialog();

private slots:
    void on_lineEdit_password_returnPressed();
    void asseptloginpass();



    void on_pushButton_login_clicked();

private:
    Ui::logindialog *ui;
    bool login_check;
    bool pass_check;
    Networkserv *servicenet;
   // QWidget Passwredit;


};

#endif // LOGINDIALOG_H
