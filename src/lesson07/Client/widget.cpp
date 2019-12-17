#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    connect(&tcpSocket, SIGNAL(readyRead()),
            this, SLOT(onReadyRead()));
    connect(&tcpSocket, SIGNAL(connected()),
            this, SLOT(onConnected()));
    connect(&tcpSocket, SIGNAL(disconnected()),
            this, SLOT(onDisconnected()));
    connect(&tcpSocket, SIGNAL(error(QAbstractSocket::SocketError)),
            this, SLOT(onError(QAbstractSocket::SocketError)));

    tcpSocket.connectToHost("127.0.0.1", 8888);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::onReadyRead()
{
    QObject *obj = this->sender();
    QTcpSocket *socket = qobject_cast<QTcpSocket*>(obj);
    QByteArray data = socket->readAll();
    ui->textBrowser_2->append(data);
    qDebug() << "read:" << data;
}

void Widget::onConnected()
{
    qDebug() << "connected";
}

void Widget::onDisconnected()
{
    qDebug() << "disconnected";
}

void Widget::onError(QAbstractSocket::SocketError socketError)
{
    qDebug() << "error";
}
