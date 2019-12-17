#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QTcpServer>
#include <QTcpSocket>
#include <qDebug>
#include <QFileDialog>

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
    void onNewConnection();
    void onReadyRead();
    void onConnected();
    void onDisconnected();
    void onError(QAbstractSocket::SocketError socketError);

private slots:
    void on_btnImage_clicked();

    void on_btnSend_clicked();

private:
    Ui::Widget *ui;
    QTcpServer server;
    QList<QTcpSocket*> clients;
};

#endif // WIDGET_H
