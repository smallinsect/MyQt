#include "mainwindow.h"
#include <QApplication>

#include <QTime>
#include <QtGlobal>
#include <QSound>

int main(int argc, char *argv[])
{
    qsrand(QTime().msecsTo(QTime::currentTime()));
    QApplication a(argc, argv);
    MainWindow w;
    w.show();


    return a.exec();
}
