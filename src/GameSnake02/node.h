#ifndef NODE_H
#define NODE_H

//使用vs编译中文乱码
#ifdef WIN32
#pragma execution_character_set("utf-8")
#endif

#include <QDebug>
#include <QWidget>

#define UNIT_SIZE 10

class Node : public QWidget
{
    Q_OBJECT
public:
    explicit Node(QWidget *parent = nullptr);
    Node(QWidget *parent, int x, int y);

signals:

public slots:
};

#endif // NODE_H
