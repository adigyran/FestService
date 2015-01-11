#ifndef LOGINDIALOG_H
#define LOGINDIALOG_H

#include <QDialog>

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



private:
    Ui::logindialog *ui;
   // QWidget Passwredit;

};

#endif // LOGINDIALOG_H
