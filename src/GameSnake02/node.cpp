#include "node.h"

Node::Node(QWidget *parent) : QWidget(parent)
{

}

Node::Node(QWidget *parent, int x, int y): QWidget(parent)
{
//    resize(UNIT_SIZE, UNIT_SIZE);
//    setStyleSheet(QString("background-color: rgb(217, 24, 255);"));
//    show();
//    move(x, y);

    qDebug() << x << y;
    setStyleSheet(QString("background-color: rgb(255, 255, 255);"));
    resize(10, 10);
    move(0, 0);
    show();
}
