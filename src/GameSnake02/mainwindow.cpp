#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    snake = new Snake(ui->widgetLeft);
//    timer = new QTimer(this);

//    connect(timer, &QTimer::timeout, [=](){
//        snake->move();
//    });

    connect(ui->actionStart, SIGNAL(triggered()), this, SLOT(doTriggeredStart()));
    connect(ui->actionStop, SIGNAL(triggered()), this, SLOT(doTriggeredStop()));
    connect(ui->actionEnd, SIGNAL(triggered()), this, SLOT(doTriggeredEnd()));
}



MainWindow::~MainWindow()
{
    delete ui;
    delete snake;
    delete timer;
}

void MainWindow::doTriggeredStart()
{
//    timer->start(30);
    qDebug() << "开始";
}

void MainWindow::doTriggeredStop()
{
//    timer->stop();
    qDebug() << "停止";
}

void MainWindow::doTriggeredEnd()
{
//    timer->stop();
    qDebug() << "结束";
}
