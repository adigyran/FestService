#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPalette>


#include <QtWidgets>

Q_DECLARE_METATYPE(QCameraInfo)

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


    connect(videoDevicesGroup, SIGNAL(triggered(QAction*)), SLOT(updateCameraDevice(QAction*)));

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

   qDebug() <<  QR_Sample.load(":/image/qrtest2.png");

   ui->label_2->setPixmap(QPixmap::fromImage(QR_Sample));

    qDebug() << QR_Sample.size();
qDebug() << decoder.decodeImage(QR_Sample,1800,1800,false);
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


  QImage QR_Sample2(800,600,QImage::Format_RGB32);

    QR_Sample2 = ui->viewfinder->grab().toImage();

    ui->label_2->setPixmap(QPixmap::fromImage(QR_Sample2));

     qDebug() << QR_Sample2.size();
 qDebug() << decoder.decodeImage(QR_Sample2,1800,1800,false);
 qDebug() << QR_Sample2.size();

}


void MainWindow::setCamera(const QCameraInfo &cameraInfo)
{
    delete imageCapture;
    delete mediaRecorder;
    delete camera;

    camera = new QCamera(cameraInfo);

    //connect(camera, SIGNAL(stateChanged(QCamera::State)), this, SLOT(updateCameraState(QCamera::State)));
   // connect(camera, SIGNAL(error(QCamera::Error)), this, SLOT(displayCameraError()));

    mediaRecorder = new QMediaRecorder(camera);
   // connect(mediaRecorder, SIGNAL(stateChanged(QMediaRecorder::State)), this, SLOT(updateRecorderState(QMediaRecorder::State)));

    imageCapture = new QCameraImageCapture(camera);

   // connect(mediaRecorder, SIGNAL(durationChanged(qint64)), this, SLOT(updateRecordTime()));
   // connect(mediaRecorder, SIGNAL(error(QMediaRecorder::Error)), this, SLOT(displayRecorderError()));

    mediaRecorder->setMetaData(QMediaMetaData::Title, QVariant(QLatin1String("Test Title")));

    //connect(ui->exposureCompensation, SIGNAL(valueChanged(int)), SLOT(setExposureCompensation(int)));

    camera->setViewfinder(ui->viewfinder);

    //updateCameraState(camera->state());
   // updateLockStatus(camera->lockStatus(), QCamera::UserRequest);
   // updateRecorderState(mediaRecorder->state());



    //ui->captureWidget->setTabEnabled(0, (camera->isCaptureModeSupported(QCamera::CaptureStillImage)));
    //ui->captureWidget->setTabEnabled(1, (camera->isCaptureModeSupported(QCamera::CaptureVideo)));

    //updateCaptureMode();
    camera->start();
}

void MainWindow::updateCameraDevice(QAction *action)
{
    setCamera(qvariant_cast<QCameraInfo>(action->data()));
}

