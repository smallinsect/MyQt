#include "snake.h"

Snake::Snake(QWidget *parent) : QWidget(parent)
{
    node = new Node(this, 200, 200);
//    node->show();
//    nodes.push_back(node);
//    QWidget* n = new QWidget(this);
//    n->move(0, 0);
//    n->setStyleSheet(QString("background-color: rgb(255, 255, 255);"));
//    n->show();
//    n->resize(10, 10);
}

void Snake::move()
{

}

void Snake::eat()
{

}

void Snake::isDead()
{

}
