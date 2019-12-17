#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //无边框的窗口
//    this->setWindowFlags(Qt::FramelessWindowHint);
    //最小化置灰
    this->setWindowFlag(Qt::WindowMinimizeButtonHint, false);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_btnClose_clicked()
{
    close();
}
