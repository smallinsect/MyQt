#ifndef QUDP02_H
#define QUDP02_H

//使用vs编译中文乱码
#ifdef WIN32
#pragma execution_character_set("utf-8")
#endif

#include <QWidget>
#include <QUdpSocket>

namespace Ui {
class QUdp02;
}

class QUdp02 : public QWidget
{
    Q_OBJECT

public:
    explicit QUdp02(QWidget *parent = nullptr);
    ~QUdp02();

private:
    Ui::QUdp02 *ui;
    QUdpSocket *udp;
};

#endif // QUDP02_H
