#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    timer = new QTimer();
    curTime.setHMS(0,0,0);
    accel.setAccelerationMode(QAccelerometer::AccelerationMode::User);
    connect(timer,SIGNAL(timeout()),this,SLOT(TimerUpdate()));
}

MainWindow::~MainWindow()
{
    delete ui;
    delete timer;
}


void MainWindow::on_pushButton_clicked()
{

    timer->setInterval(1000);
    timer->setSingleShot(false);
    timer->start();
    accel.start();
}
void MainWindow::TimerUpdate()
{
    QAccelerometerReading* accelData;
    ui->label_3->setText(QString::number((long)accelData));
    accelData = accel.reading();

    ui->label_2->setText(QString::number((long)accelData));
    ui->label_2->setText(QString("x:")+QString::number(accelData->x(),'f',2)+
                         QString("y:")+QString::number(accelData->y(),'f',2)+
                         QString("z:")+QString::number(accelData->z(),'f',2) );

    //и без фильтра все ясно. возможно, фильтр нужен для точных жестов или на плохих акселерометрах
    if(qFabs(accelData->x())+qFabs(accelData->y())+qFabs(accelData->z())>1)
    {
        curTime = curTime.addSecs(1);
        ui->label->setText(curTime.toString());
    }
}


void MainWindow::on_pushButton_2_clicked()
{
    timer->stop();
}

