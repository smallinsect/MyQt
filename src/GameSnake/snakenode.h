#ifndef SNAKENODE_H
#define SNAKENODE_H

#include <QSize>
#include <QLabel>
#include <QPoint>
#include <QFrame>
#include <QWidget>
#include <QPixmap>

#include "define.h"

class SnakeNode : public QWidget
{
    Q_OBJECT
public:
    explicit SnakeNode(QWidget *parent = nullptr);
    ~SnakeNode();

    SnakeNode(QWidget *parent, int x, int y);
    SnakeNode(QWidget *parent, QPoint pos);

    void init(QWidget *parent);

    void setPos(int x, int y);
    void setPos(QPoint pos);
    QPoint getPos();


    SnakeNode *next;
signals:

public slots:

private:
    QPoint pos;
    QLabel *item;
};

#endif // SNAKENODE_H
