#include "widget.h"
#include "ui_widget.h"
#include <QDebug>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    connect(&server, SIGNAL(newConnection()),
            this,SLOT(onNewConnection()));
    bool ok = server.listen(QHostAddress::AnyIPv4, 8888);
    qDebug() << "listen:" << ok;
}

Widget::~Widget()
{
    delete ui;
}

void Widget::onNewConnection()
{
    //使用这个socket客户端进行通信。
    QTcpSocket *socket = server.nextPendingConnection();
    clients.append(socket);

    //连接信号和槽
    connect(socket, SIGNAL(readyRead()),
            this, SLOT(onReadyRead()));
    connect(socket, SIGNAL(connected()),
            this, SLOT(onConnected()));
    connect(socket, SIGNAL(disconnected()),
            this, SLOT(onDisconnected()));
    connect(socket, SIGNAL(error(QAbstractSocket::SocketError)),
            this, SLOT(onError(QAbstractSocket::SocketError)));
}

void Widget::onReadyRead()
{
    QObject *obj = this->sender();
    QTcpSocket *socket = qobject_cast<QTcpSocket*>(obj);
    QByteArray data = socket->readAll();
    ui->textBrowser_2->append(data);
    qDebug() << data;
}

void Widget::onConnected()//连接成功
{
    qDebug() << "connected";
}

void Widget::onDisconnected()//断开了
{
    QObject *obj = this->sender();
    QTcpSocket *socket = qobject_cast<QTcpSocket*>(obj);
    clients.removeAll(socket);
    socket->deleteLater();
    qDebug() << "disconneted";
}

void Widget::onError(QAbstractSocket::SocketError socketError)//出错
{
    qDebug() << "error:" << socketError;
}

void Widget::on_btnSend_clicked()
{
    for(QList<QTcpSocket*>::iterator itr = clients.begin(); itr != clients.end(); ++itr){
        QTcpSocket *client = *itr;
        QString msgInput = ui->textBrowser->toPlainText();
        client->write(msgInput.toLocal8Bit());
    }
}
