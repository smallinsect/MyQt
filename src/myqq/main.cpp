﻿#include "widget.h"
#include <QApplication>

#include "listdialog.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
//    Widget w;
//    w.show();
    ListDialog w;
    w.show();
    return a.exec();
}
