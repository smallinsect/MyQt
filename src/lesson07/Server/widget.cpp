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
    //ʹ�����socket�ͻ��˽���ͨ�š�
    QTcpSocket *socket = server.nextPendingConnection();
    clients.append(socket);

    //�����źźͲ�
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

void Widget::onConnected()//���ӳɹ�
{
    qDebug() << "connected";
}

void Widget::onDisconnected()//�Ͽ���
{
    QObject *obj = this->sender();
    QTcpSocket *socket = qobject_cast<QTcpSocket*>(obj);
    clients.removeAll(socket);
    socket->deleteLater();
    qDebug() << "disconneted";
}

void Widget::onError(QAbstractSocket::SocketError socketError)//����
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
