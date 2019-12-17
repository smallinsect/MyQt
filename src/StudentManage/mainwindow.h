#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "addstudent.h"
#include "querystudent.h"

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_actionaddStu_triggered();

    void on_actionqryStu_triggered();

private:
    Ui::MainWindow *ui;

    AddStudent astu;
    QueryStudent qstu;
};

#endif // MAINWINDOW_H
