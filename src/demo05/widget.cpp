#include "widget.h"
#include "ui_widget.h"

#include <QPainter>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::paintEvent(QPaintEvent *ev)
{
    QPainter p(this);

    //设置画笔颜色
    p.setPen(QColor(255,0,0, 150));

    //设置字体
    p.setFont(QFont("黑体", 30));

    p.drawText(10, 20, QStringLiteral("设备"));


}
