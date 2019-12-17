#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    server = nullptr;
    socket = nullptr;

    ui->setupUi(this);
    server = new QTcpServer();
    server->listen(QHostAddress::Any, 8888);

    connect(server, &QTcpServer::newConnection, [=](){
        //取得新建好的套接字
        socket = server->nextPendingConnection();
        //获取对方IP
        QString IP = socket->peerAddress().toString();
        //获取端口
        quint16 port = socket->peerPort();
        QString temp = QString("[%1:%2]:连接成功").arg(IP).arg(port);
        ui->textEditRecv->append(temp);
        //接受数据
        connect(socket, &QTcpSocket::readyRead, [=](){
            QByteArray array = socket->readAll();
            ui->textEditRecv->append(array.data());
        });
    });
}

MainWindow::~MainWindow()
{
    delete ui;
    delete server;
}

void MainWindow::on_btnSend_clicked()
{
    if(socket == nullptr){
        return ;
    }
    QString str = ui->textEditSend->toPlainText();
    socket->write(str.toUtf8());
}
