#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include <QDebug>

#include "snake.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    void doTriggeredStart();
    void doTriggeredStop();
    void doTriggeredEnd();

private:
    Ui::MainWindow *ui;

    Snake* snake;
    QTimer* timer;
};

#endif // MAINWINDOW_H
