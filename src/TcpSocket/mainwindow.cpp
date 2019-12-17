#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    socket = nullptr;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_btnConnect_clicked()
{
    socket = new QTcpSocket(this);
    QString IP = ui->IP->text();
    quint16 port = ui->port->text().toUShort();
    socket->connectToHost(QHostAddress(IP), port);

    connect(socket, &QTcpSocket::readyRead, [=](){
       QByteArray array = socket->readAll();
       ui->txtRecv->append(array.data());
    });
}

void MainWindow::on_btnSend_clicked()
{
    if(socket == nullptr){
        return ;
    }
    QString str = ui->txtSend->toPlainText();
    socket->write(str.toUtf8());
}
