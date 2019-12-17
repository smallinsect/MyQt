#include "snakedialog.h"

SnakeDialog::SnakeDialog(QWidget *parent) : QWidget(parent)
{
    snake = new SnakeNode(parent, 100, 100);
}

SnakeDialog::~SnakeDialog()
{
    SnakeNode *pnode = snake;
    while(snake != nullptr){
        snake = snake->next;
        delete pnode;
        pnode = snake;
    }
}


void SnakeDialog::move(int dir, QWidget *parent)
{
    QPoint pos = snake->getPos();
    int x = pos.x();
    int y = pos.y();

    this->insertHead(parent);
    switch(dir){
    case 1:
        y -= UNIT_SIZE;
        break;
    case 2:
        x -= UNIT_SIZE;
        break;
    case 3:
        y += UNIT_SIZE;
        break;
    case 4:
        x += UNIT_SIZE;
        break;
    }
    snake->setPos(x, y);
//    this->deleteTail();
}

void SnakeDialog::eat(int dir, QWidget *parent)
{
    QPoint pos = snake->getPos();
    int x = pos.x();
    int y = pos.y();

    this->insertHead(parent);
    switch(dir){
    case 1:
        y -= UNIT_SIZE;
        break;
    case 2:
        x -= UNIT_SIZE;
        break;
    case 3:
        y += UNIT_SIZE;
        break;
    case 4:
        x += UNIT_SIZE;
        break;
    }
    snake->setPos(x, y);
//    this->deleteTail();
}

void SnakeDialog::insertHead(QWidget *parent)
{
    SnakeNode *node = new SnakeNode(parent, snake->getPos());
    node->next = snake->next;
    snake = node;
}

void SnakeDialog::deleteTail()
{
    SnakeNode *p = snake;
    SnakeNode *q = p;
    while(p->next != nullptr){
        q = p;
        p = p->next;
    }
    q->next = nullptr;
    delete p;
    p = nullptr;
}
