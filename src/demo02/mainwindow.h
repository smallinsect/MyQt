#ifndef MAINWINDOW_H
#define MAINWINDOW_H

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

    void init();
public slots:
    void onClickNum();
private:
    Ui::MainWindow *ui;

    int num;
};

#endif // MAINWINDOW_H
