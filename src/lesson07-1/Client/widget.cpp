#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget),
    imageIndex(0)
{
    ui->setupUi(this);

    connect(&tcpSocket, SIGNAL(readyRead()),
            this, SLOT(onReadyRead()));
    connect(&tcpSocket, SIGNAL(connected()),
            this, SLOT(onCennected()));
    connect(&tcpSocket, SIGNAL(disConnected()),
            this, SLOT(onDisConnected()));
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
    QString prefix = data.mid(0, 4);
    if(prefix == "TXT:"){
        ui->textMsg->append(data);
    }else if(prefix == "IMG:"){
        qint64 sizeNow = socket->bytesAvailable();
        if(sizeNow < sizeof(quint32)){
            return ;
        }
        QDataStream stream(socket);
        quint32 sizePack = 0;
        stream >> sizePack;
        if(sizeNow >= sizePack-4){
            qDebug() << "full pack";
            QByteArray dataFull;
            stream >> dataFull;
        }
        QString htmlTag = QString("<img src=\"%1\"></img>");
        QString index = QString::number(imageIndex);
        htmlTag = htmlTag.arg(index+".png");

        QFile file(index+".png");
        file.open(QIODevice::WriteOnly);
        file.write(data.mid(4));
        file.close();
        ++imageIndex;
        ui->textMsg->insertHtml(htmlTag);
    }
    qDebug() << "read:" << data;
}

void Widget::onConnected()
{
    qDebug() << "connected";
}

void Widget::onDisConnected()
{
    qDebug() << "disConnected";
}

void Widget::onError(QAbstractSocket::SocketError socketError)
{
    qDebug() << "error";
}

void Widget::on_btnImage_clicked()
{

}

void Widget::on_btnSend_clicked()
{

}
