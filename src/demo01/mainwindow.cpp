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

void MainWindow::on_btnAdd_clicked()
{
    double dNum1 = ui->lineNum1->text().toDouble();
    double dNum2 = ui->lineNum2->text().toDouble();
    ui->lineEquip->setText(QString("%1").arg(dNum1+dNum2));
}

void MainWindow::on_btnSub_clicked()
{
    double dNum1 = ui->lineNum1->text().toDouble();
    double dNum2 = ui->lineNum2->text().toDouble();
    ui->lineEquip->setText(QString("%1").arg(dNum1-dNum2));
}
