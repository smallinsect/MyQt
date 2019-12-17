#include "snakenode.h"

SnakeNode::SnakeNode(QWidget *parent) : QWidget(parent)
{

}

SnakeNode::~SnakeNode()
{
    delete item;
    item = nullptr;
}

SnakeNode::SnakeNode(QWidget *parent, int x, int y) : QWidget(parent)
{
//    init(parent);
//    setPos(x, y);
}

SnakeNode::SnakeNode(QWidget *parent, QPoint pos) : QWidget(parent)
{
//    init(parent);
//    setPos(pos);
}

void SnakeNode::init(QWidget *parent)
{
    item = new QLabel(parent);
    item->resize(UNIT_SIZE, UNIT_SIZE);
    QPixmap pixmap(":/image/snakenode.png");
    QSize size(UNIT_SIZE, UNIT_SIZE);
    pixmap = pixmap.scaled(size, Qt::KeepAspectRatio);
    item->setPixmap(pixmap);

    next = nullptr;
}

void SnakeNode::setPos(int x, int y)
{
    pos.setX(x);
    pos.setY(y);
    item->move(pos);
}

void SnakeNode::setPos(QPoint pos)
{
    this->pos = pos;
    item->move(pos);
}

QPoint SnakeNode::getPos()
{
    return pos;
}
