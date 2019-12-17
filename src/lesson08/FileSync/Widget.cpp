#include "Widget.h"
#include "ui_Widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    fileWatcher.setWatchPath("C:/Users/small/Desktop/test");
}

Widget::~Widget()
{
    delete ui;
}

