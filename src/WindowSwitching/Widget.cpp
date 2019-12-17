#include "Widget.h"
#include "ui_Widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    init();
}

Widget::~Widget()
{
    delete ui;
}

void Widget::init()
{
    pForm01 = new Form01();

    connect(ui->pushButton, SIGNAL(clicked(bool)),
            this, SLOT(onClick(bool)));
}

void Widget::onClick(bool)
{
    pForm01->show();
}
