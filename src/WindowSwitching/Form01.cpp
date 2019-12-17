#include "Form01.h"
#include "ui_Form01.h"

Form01::Form01(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form01)
{
    ui->setupUi(this);

    init();
}

Form01::~Form01()
{
    delete ui;
}

void Form01::init()
{
    pForm02 = new Form02();

    connect(ui->pushButton, SIGNAL(clicked(bool)),
            this, SLOT(onClickToForm02(bool)));
    connect(pForm02, SIGNAL(signalShowForm01(QString)),
            this, SLOT(doForm02Request(QString)));
}

void Form01::onClickToForm02(bool)
{
    this->hide();
    pForm02->show();
}

void Form01::doForm02Request(QString count)
{
    qDebug() << "form01 : " << count;
    this->show();
}
