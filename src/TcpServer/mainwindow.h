#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTcpServer>
#include <QTcpSocket>

//使用vs编译中文乱码
#ifdef WIN32
#pragma execution_character_set("utf-8")
#endif

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
    void on_btnSend_clicked();

private:
    Ui::MainWindow *ui;

    QTcpServer *server;
    QTcpSocket *socket;
};

#endif // MAINWINDOW_H
