#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QThread>
#include <QDebug>
#include <QKeyEvent>
#include <QMainWindow>
#include <QAction>
#include <QStyle>
//#include <QtTest/QTest>
#include <QTest>

#include "snakenode.h"
#include "snakedialog.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void keyPressEvent(QKeyEvent *key);

    void moveSnake();
public slots:
    void doTriggered(bool);

    void Triggering(QAction *ac);
private:
    Ui::MainWindow *ui;

    SnakeDialog *snake;
    int dir;//蛇移动的方向
    QLabel *label;
    int x, y;
};

#endif // MAINWINDOW_H
