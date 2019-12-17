#ifndef SNAKE_H
#define SNAKE_H

#include <QWidget>
#include <QList>
#include <QLabel>

#include "node.h"

class Snake : public QWidget
{
    Q_OBJECT
public:
    explicit Snake(QWidget *parent = nullptr);

    void move();
    void eat();
    void isDead();
signals:

public:
    QList<Node*> nodes;
    Node* node;
};

#endif // SNAKE_H
