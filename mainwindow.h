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
#include <QImage>
#include <QtMultimedia/QtMultimedia>
#include <QtWidgets/QtWidgets>



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
    void reportTagFound(QString tag);

    void on_pushButton_4_clicked();

private:
    Ui::MainWindow *ui;
    QNetworkAccessManager *manager;
    QZXing decoder;
    QImage QR_Sample;

    QCamera *camera;
    QCameraImageCapture *imageCapture;
    QMediaRecorder* mediaRecorder;

    QImageEncoderSettings imageSettings;
    QAudioEncoderSettings audioSettings;
    QVideoEncoderSettings videoSettings;
    QString videoContainerFormat;
    bool isCapturingImage;
    bool applicationExiting;


};

#endif // MAINWINDOW_H
