#include "mainwindow.h"
#include "logindialog.h"
#include <QApplication>
#include <QtWidgets>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    logindialog q;
   // w.show();
    q.show();


    return a.exec();
}
