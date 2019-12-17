#ifndef CHAT_H
#define CHAT_H

//使用vs编译中文乱码
#ifdef WIN32
#pragma execution_character_set("utf-8")
#endif


#include <QTime>
#include <QMessageBox>
#include <QDataStream>
#include <QByteArray>
#include <QWidget>
#include <QString>
#include <QUdpSocket>
#include <QNetworkDatagram>
#include <QDateTime>
#include <QFontComboBox>
#include <QColorDialog>

namespace Ui {
class Chat;
}

class Chat : public QWidget
{
    Q_OBJECT

    enum MsgType{Msg, UsrEnter, UsrLeft};//消息类型

public:
    explicit Chat(QWidget *parent, QString name);
    ~Chat();

signals:
    void closeChat();
public:
    void closeEvent(QCloseEvent *);//重写关闭窗口事件

    void sndMsg(MsgType type);//广播UDP消息
    void usrEnter(QString username);//处理新用户加入
    void usrLeft(QString username, QString time);//处理用户离开

    QString getUsrName();//获取用户名
    QString getMsg();//获取聊天信息
private:
    Ui::Chat *ui;
    QUdpSocket *udp;//udp套接字
    quint16 port;//端口
    QString name;//用户名

    void recvMsg();//接受UDP消息
};

#endif // CHAT_H
