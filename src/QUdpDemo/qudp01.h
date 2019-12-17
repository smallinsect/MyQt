#ifndef QUDP01_H
#define QUDP01_H

//使用vs编译中文乱码
#ifdef WIN32
#pragma execution_character_set("utf-8")
#endif

#include <QWidget>
#include <QUdpSocket>

namespace Ui {
class QUdp01;
}

class QUdp01 : public QWidget
{
    Q_OBJECT

public:
    explicit QUdp01(QWidget *parent = nullptr);
    ~QUdp01();

private:
    Ui::QUdp01 *ui;
    QUdpSocket *udp;
};

#endif // QUDP01_H
