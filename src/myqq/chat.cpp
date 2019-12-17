#include "chat.h"
#include "ui_chat.h"

Chat::Chat(QWidget *parent, QString name) :
    QWidget(parent),
    ui(new Ui::Chat)
{
    ui->setupUi(this);
    port = 9999;
    this->name = name;
    udp = new QUdpSocket(this);
    udp->bind(port,QUdpSocket::ShareAddress|QUdpSocket::ReuseAddressHint);

    //接受消息
    connect(udp, &QUdpSocket::readyRead, this, &Chat::recvMsg);

    //发送消息 新用户加入
    sndMsg(UsrEnter);
    //发送消息按钮
    connect(ui->sendBtn, &QPushButton::clicked, [=](){
        sndMsg(Msg);
    });
    //字体样式
    connect(ui->fontCbx, &QFontComboBox::currentFontChanged, [=](const QFont &font){
        ui->msgTextEdit->setFontFamily(font.family());
    });
    //字体大小
    connect(ui->sizeCbx, &QComboBox::currentTextChanged, [=](const QString &text){
        //改变输入的字体大小
        ui->msgTextEdit->setFontPointSize(text.toDouble());
    });
    //字体加粗
    connect(ui->boldTBtn, &QToolButton::clicked, [=](){
//        qDebug() << ui->msgTextEdit->fontWeight();

//        ui->msgTextEdit->setFontWeight(10);
        QFont font = ui->msgTextEdit->font();
        bool b = font.bold();
        font.setBold(!b);
        ui->msgTextEdit->setFont(font);
    });
    //字体斜体
    connect(ui->italicTBtn, &QToolButton::clicked, [=](){
        bool b = ui->msgTextEdit->fontItalic();
        ui->msgTextEdit->setFontItalic(!b);
    });

    //字体下划线
    connect(ui->underlineTBtn, &QToolButton::clicked, [=](){
        bool b = ui->msgTextEdit->fontUnderline();
        ui->msgTextEdit->setFontUnderline(!b);
    });
    //字体颜色
    connect(ui->colorTBtn, &QToolButton::clicked, [=](){
        QColor color = QColorDialog::getColor();

        QFont font = ui->msgTextEdit->font();

    });
    //保存聊天记录
    //清除聊天记录

}

Chat::~Chat()
{
    delete ui;
    delete udp;
}

void Chat::closeEvent(QCloseEvent *)
{
    sndMsg(UsrLeft);
    emit closeChat();
}
//发送消息
void Chat::sndMsg(Chat::MsgType type)
{
    //获取当前时间
    QString time = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss");
    QByteArray array;
    QDataStream stream(&array, QIODevice::WriteOnly);

    switch(type){
    case Msg:{
        QString msg = getMsg();
        if(msg == ""){
            QMessageBox::warning(this, "提示", "输入为空");
            return ;
        }
        stream << type << "["+getUsrName()+"]" + time;
        stream << msg;
        break;
    }
    case UsrEnter:{//新用户加入
        stream << type << getUsrName();
        break;
    }
    case UsrLeft:{//用户退出
        stream << type << getUsrName() << time;
        break;
    }
    }
    //广播发送
    udp->writeDatagram(array, QHostAddress::Broadcast, port);
}
//新用户加入
void Chat::usrEnter(QString username)
{
    bool isEmpty = ui->usrTblWidget->findItems(username, Qt::MatchExactly).isEmpty();
    if(isEmpty){
        ui->msgBrowser->setTextColor(Qt::gray);
        ui->msgBrowser->append(QString("%1 新用户加入").arg(username));
        //将新加入的用户添加到右边列表
        QTableWidgetItem *item = new QTableWidgetItem(username);
        ui->usrTblWidget->insertRow(0);
        ui->usrTblWidget->setItem(0,0, item);
        //修改在线人数
        ui->usrNumLbl->setText(QString("在线人数：%1人").arg(ui->usrTblWidget->rowCount()));
        //发送这条消息 就是自己添加自己到列表中
        sndMsg(UsrEnter);
    }
}
//用户退出
void Chat::usrLeft(QString username, QString time)
{
    bool isEmpty = ui->usrTblWidget->findItems(username, Qt::MatchExactly).isEmpty();
    if(!isEmpty){
        //查找用户所在行
        int row = ui->usrTblWidget->findItems(username, Qt::MatchExactly).at(0)->row();
        //删除用户
        ui->usrTblWidget->removeRow(row);
        //修改在线人数
        ui->usrNumLbl->setText(QString("在线人数：%1人").arg(ui->usrTblWidget->rowCount()));
        //退出用户信息用灰色显示
        ui->msgBrowser->setTextColor(Qt::gray);
        //添加退出的用户信息
        ui->msgBrowser->append(QString("%1 %2 退出").arg(username).arg(time));
    }
}

QString Chat::getUsrName()
{
    return name;
}

QString Chat::getMsg()
{
    QString msg = ui->msgTextEdit->toPlainText();
    ui->msgTextEdit->clear();//清除输入框
    return msg;
}
//接受数据
void Chat::recvMsg()
{
    qint64 size = udp->pendingDatagramSize();//获取缓冲区缓冲的数据大小
    QByteArray array(size, 0);
    int type;
    udp->readDatagram(array.data(), size);
    QDataStream stream(&array, QIODevice::ReadOnly);
    stream >> type;
    QString usrName;
    QString msg;
    QString time;
    switch(type){
    case Msg:
        stream >> usrName >> msg;
        ui->msgBrowser->setTextColor(Qt::blue);
        ui->msgBrowser->append(usrName);
        ui->msgBrowser->append(msg);
        break;
    case UsrEnter:{//新用户加入
        stream >> usrName;
        usrEnter(usrName);
        break;
    }
    case UsrLeft:
        stream >> usrName >> time;
        usrLeft(usrName, time);
        break;
    }
}
