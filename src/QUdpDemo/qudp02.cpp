#include "qudp02.h"
#include "ui_qudp02.h"

QUdp02::QUdp02(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::QUdp02)
{
    ui->setupUi(this);

    ui->myPort->setText("8880");
    ui->toIP->setText("127.0.0.1");
    ui->toPort->setText("8888");

    udp = new QUdpSocket(this);
    udp->bind(ui->myPort->text().toUShort());
    connect(ui->btnSend, &QPushButton::clicked, [=](){
        //发送数据
        udp->writeDatagram(ui->sendMsg->toPlainText().toLocal8Bit(),
                           QHostAddress(ui->toIP->text()),
                           ui->toPort->text().toUShort());
        //自己的接受区，添加自己发送的数据
        ui->recvMsg->append("my msg:"+ui->sendMsg->toPlainText());
        //清除发送文本区的数据
        ui->sendMsg->clear();
    });

    //接受数据
    connect(udp, &QUdpSocket::readyRead, [=](){
        //获取报文大小
        qint64 size = udp->pendingDatagramSize();
        QByteArray array(size, 0);
        udp->readDatagram(array.data(), size);
        ui->recvMsg->append(array.data());
    });
}

QUdp02::~QUdp02()
{
    delete ui;
    delete udp;
}
