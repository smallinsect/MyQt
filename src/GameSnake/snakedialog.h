#ifndef SNAKEDIALOG_H
#define SNAKEDIALOG_H

#include <QPoint>
#include <QWidget>

#include "snakenode.h"

class SnakeDialog : public QWidget
{
    Q_OBJECT
public:
    explicit SnakeDialog(QWidget *parent = nullptr);
    ~SnakeDialog();

    void move(int dir, QWidget *parent);
    void eat(int dir, QWidget *parent);

    void insertHead(QWidget *parent);
    void deleteTail();

signals:

public slots:

private:
    SnakeNode *snake;
};

#endif // SNAKEDIALOG_H
