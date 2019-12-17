//#include "mainwindow.h"
#include <QApplication>
#include <QWidget>
#include "xthread.h"
#include "xwidget.h"
//static QWidget *w = nullptr;



int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
//    MainWindow w;
//    w.show();
//    QWidget w;
//    w.setWindowTitle("my widget");
//    w.show();
//    QRect re = w.geometry();
//    w.move(100,100);
//    w.setGeometry(100, 100, 400, 300);
//    w = new QWidget();
//    w->show();
//    XThread xt;
//    xt.start();
    XWidget w;
    w.show();
    XThread xt;
    QObject::connect(&xt, SIGNAL(Move(int,int)), &w, SLOT(runMove(int, int)));
    xt.run();
    return a.exec();
}
