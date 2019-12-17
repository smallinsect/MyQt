#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <QTimer>
#include <QDebug>
#include <QPoint>
#include <QKeyEvent>
#include <QTime>
#include <QList>
#include <QMessageBox>
//使用vs编译中文乱码
#ifdef WIN32
#pragma execution_character_set("utf-8")
#endif

#define UNIT_SIZE 10

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void moveSnake();

    void keyPressEvent(QKeyEvent *event);
    void eat();
    void giveFood();//发放食物
private slots:
    void on_actionStart_triggered(bool checked);

    void on_actionStop_triggered(bool checked);

    void on_actionEnd_triggered(bool checked);

    void on_actionStart_triggered();

    bool isDead(int x, int y);

private:
    Ui::MainWindow *ui;

    QTimer* timerSnake;
    int dir;//移动方向 上1 右2 下3 左4
    QLabel* food;//食物

    QList<QLabel*> snake;
};

#endif // MAINWINDOW_H
