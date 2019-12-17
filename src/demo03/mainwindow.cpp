#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QMovie>
#include <QDebug>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QString con = QStringLiteral("爱白菜的小昆虫");
    ui->label->setText(con);

    //显示动画
//    QMovie *mov = new QMovie("E:/smallinsect/QT5.13/src/demo03/timg.gif");
//    ui->label_4->setMovie(mov);
//    mov->start();
    ui->label_4->setText("<a href='//www.bilibili.com/audio/home/?type=10' >fda</a>");

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_label_4_linkActivated(const QString &link)
{
    qDebug() << link << "activated";
}

void MainWindow::on_label_4_linkHovered(const QString &link)
{
    qDebug() << link << "hovered";
}
