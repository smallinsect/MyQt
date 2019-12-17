#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_btnMax_clicked()
{
    setWindowState(Qt::WindowMaximized);
}

void MainWindow::on_btnNorm_clicked()
{
    setWindowState(Qt::WindowNoState);
}

void MainWindow::on_btnMin_clicked()
{
    setWindowState(Qt::WindowMinimized);
}

void MainWindow::on_btnClose_clicked()
{
//    hide();
    close();
}
