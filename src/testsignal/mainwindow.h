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

private slots:
    void on_btnClose_clicked();
    void on_btnMin_clicked();
    void onBtnMaxClicked();

signals:
    void onBtnMaxClicked1();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
