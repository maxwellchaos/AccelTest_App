#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    timer = new QTimer();
    curTime.setHMS(0,0,0);

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
}
void MainWindow::TimerUpdate()
{
    curTime = curTime.addSecs(1);
    ui->label->setText(curTime.toString());
}


void MainWindow::on_pushButton_2_clicked()
{
    timer->stop();
}

