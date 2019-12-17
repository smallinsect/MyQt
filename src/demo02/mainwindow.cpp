#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QTime>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
//    ui->textEdit->setHtml("<font style='color:red;'></font>");
    init();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::init()
{
    qsrand(QTime(0,0,0).secsTo(QTime::currentTime()));
//    for(int i = 0; i < 10; ++i){
//        qDebug() << qrand()%100;
//    }
    num = qrand()%100;

    connect(ui->btnNum0, SIGNAL(click()), this, SLOT(onClickNum()));
    connect(ui->btnNum1, SIGNAL(click()), this, SLOT(onClickNum()));
    connect(ui->btnNum2, SIGNAL(click()), this, SLOT(onClickNum()));
    connect(ui->btnNum3, SIGNAL(click()), this, SLOT(onClickNum()));
    connect(ui->btnNum4, SIGNAL(click()), this, SLOT(onClickNum()));
    connect(ui->btnNum5, SIGNAL(click()), this, SLOT(onClickNum()));
    connect(ui->btnNum6, SIGNAL(click()), this, SLOT(onClickNum()));
    connect(ui->btnNum7, SIGNAL(click()), this, SLOT(onClickNum()));
    connect(ui->btnNum8, SIGNAL(click()), this, SLOT(onClickNum()));
    connect(ui->btnNum9, SIGNAL(click()), this, SLOT(onClickNum()));
}

void MainWindow::onClickNum()
{

}
