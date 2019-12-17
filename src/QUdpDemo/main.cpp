#include "qudp01.h"
#include "qudp02.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QUdp01 w1;
    w1.show();

    QUdp02 w2;
    w2.show();

    return a.exec();
}
