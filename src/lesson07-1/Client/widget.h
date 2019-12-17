#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QTcpSocket>
#include <QTcpServer>
#include <QDebug>
#include <QFile>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();
public slots:
    void onReadyRead();
    void onConnected();
    void onDisConnected();
    void onError(QAbstractSocket::SocketError socketError);

private slots:
    void on_btnImage_clicked();

    void on_btnSend_clicked();

private:
    Ui::Widget *ui;
    QTcpSocket tcpSocket;
    int imageIndex;
};

#endif // WIDGET_H
