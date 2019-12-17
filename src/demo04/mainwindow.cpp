#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDebug>
#include <QMovie>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->pushButton->setShortcut(tr("X"));
    QMovie *mov = new QMovie(":/new/prefix1/image/timg.gif");
    ui->label->setMovie(mov);
    mov->start();

    //输入提示
    ui->lineEdit->setPlaceholderText("输入汉字");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    qDebug() << "qqqq";
    QString str = ui->lineEdit->text();
    ui->label_2->setText(str);
}
