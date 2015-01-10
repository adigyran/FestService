#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPalette>


#include <QtWidgets>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent), decoder(QZXing::DecoderFormat_QR_CODE),
    camera(0),
    imageCapture(0),
    mediaRecorder(0),
    isCapturingImage(false),
    applicationExiting(false),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QActionGroup *videoDevicesGroup = new QActionGroup(this);
    videoDevicesGroup->setExclusive(true);
    foreach (const QCameraInfo &cameraInfo, QCameraInfo::availableCameras()) {
        QAction *videoDeviceAction = new QAction(cameraInfo.description(), videoDevicesGroup);
        videoDeviceAction->setCheckable(true);
        videoDeviceAction->setData(QVariant::fromValue(cameraInfo));
        if (cameraInfo == QCameraInfo::defaultCamera())
            videoDeviceAction->setChecked(true);

        ui->menuBar->addAction(videoDeviceAction);
    }
    manager = new QNetworkAccessManager(this);

     ui->pushButton->setText("ttyty");
     connect(manager, SIGNAL(finished(QNetworkReply*)),
             this, SLOT(replyFinished(QNetworkReply*)));
    // decoder.DecoderFormat_QR_CODE;
     connect(&decoder, SIGNAL(tagFound(QString)), this, SLOT(reportTagFound(QString)));


    // connect(videoDevicesGroup, SIGNAL(triggered(QAction*)), SLOT(updateCameraDevice(QAction*)));
     //connect(ui->captureWidget, SIGNAL(currentChanged(int)), SLOT(updateCaptureMode()));

     //setCamera(QCameraInfo::defaultCamera());
}

MainWindow::~MainWindow()
{
    delete ui;
    delete mediaRecorder;
    delete imageCapture;
    delete camera;

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

   qDebug() <<  QR_Sample.load(":/image/qr-code3.gif");
   ui->label_2->setPixmap(QPixmap::fromImage(QR_Sample));

    qDebug() << QR_Sample.size();
qDebug() << decoder.decodeImage(QR_Sample,180,180,false);
qDebug() << QR_Sample.size();

}
void MainWindow::reportTagFound(QString tag)
{
    QMessageBox::information(this, QString("Decoding result") ,tag);
    qDebug() << tag;

}

void MainWindow::on_pushButton_4_clicked()
{
   // QList<QByteArray> cams = QCamera::availableDevices();


               // m_defaultDevice = cams.at(2);


       // m_camera = new QCamera( m_defaultDevice );


}
