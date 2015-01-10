#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtNetwork/QNetworkRequest>
#include <QtNetwork/QNetworkAccessManager>
#include <QtNetwork/QNetworkReply>
#include <QMessageBox>
#include <QDebug>
#include <QPixmap>
#include <qzxing.h>


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);

    ~MainWindow();

private slots:
    void on_pushButton_2_clicked();
    void replyFinished(QNetworkReply* reply);
    void RepeatGET();

    void on_pushButton_3_clicked();

private:
    Ui::MainWindow *ui;
    QNetworkAccessManager *manager;
    QZXing decoder;


};

#endif // MAINWINDOW_H
