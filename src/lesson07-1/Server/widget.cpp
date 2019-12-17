#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    connect(&server, SIGNAL(newConnection()),
            this, SLOT(onNewConnection()));
    bool ok = server.listen(QHostAddress::AnyIPv4, 8888);
    qDebug() << "listen:" << ok;
}

Widget::~Widget()
{
    delete ui;
}

void Widget::onNewConnection()
{
    //使用这个socket客户端进行通信
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
    qDebug() << "readyread";
}

void Widget::onConnected()//连接成功
{
    qDebug() << "connected";
}

void Widget::onDisconnected()//断开连接
{
    QObject *obj = this->sender();
    QTcpSocket *socket = qobject_cast<QTcpSocket*>(obj);
    clients.removeAll(socket);
    socket->deleteLater();
    qDebug() << "disconnected";
}

void Widget::onError(QAbstractSocket::SocketError socketError)//出错
{
    qDebug() << "error";
}

void Widget::on_btnImage_clicked()
{
    QString image = QFileDialog::getOpenFileName(this, "title", ".", "Image Files(*.png *.jpg *.bmp)");
    QFile file(image);
    file.open(QIODevice::ReadOnly);
    QByteArray data = "IMG:"+file.readAll();
    file.close();
    //封装包头
    QByteArray dataSend;//封装的数据包
    QDataStream stream(&dataSend, QIODevice::WriteOnly);
    stream << (quint32)0 << data;
    stream.device()->seek(0);
    stream << dataSend.size();
    for(QList<QTcpSocket*>::iterator itr = clients.begin(); itr != clients.end(); ++itr){
        QTcpSocket *client = *itr;

        client->write(dataSend);
    }
}

void Widget::on_btnSend_clicked()
{
    qDebug() << "send";
    for(QList<QTcpSocket*>::iterator itr = clients.begin(); itr != clients.end(); ++itr){
        QTcpSocket *client = *itr;
        QString msgInput = "TXT:"+ui->textInput->toPlainText();
        client->write(msgInput.toLocal8Bit());
    }
}
