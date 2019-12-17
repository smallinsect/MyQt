#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->btnMax, SIGNAL(clicked()),
            this,SLOT(onBtnMaxClicked()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_btnClose_clicked()
{
    qDebug() << "on_btnClose_clicked";
}

void MainWindow::on_btnMin_clicked()
{
    qDebug() << "on_btnMin_clicked";
}

void MainWindow::onBtnMaxClicked()
{
    qDebug() << "onBtnMaxClicked";
}
