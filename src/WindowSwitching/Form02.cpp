#include "Form02.h"
#include "ui_Form02.h"

Form02::Form02(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form02)
{
    ui->setupUi(this);

    init();
}

Form02::~Form02()
{
    delete ui;
}

void Form02::init()
{
    count = 0;
    pForm03 = new Form03();

    connect(ui->pushButton, SIGNAL(clicked(bool)),
            this, SLOT(onClickBackForm01(bool)));
    connect(ui->pushButton_2, SIGNAL(clicked(bool)),
            this, SLOT(onClickToForm03(bool)));
    connect(pForm03, SIGNAL(signalShowForm02(QString)),
            this, SLOT(doForm03Request(QString)));
}

void Form02::onClickToForm03(bool)
{
    this->hide();
    pForm03->show();
}

void Form02::doForm03Request(QString count)
{
    qDebug() << "form02 : " << count;
    this->show();
}

void Form02::onClickBackForm01(bool)
{
    ++count;
    this->hide();

    emit signalShowForm01(QString::number(count));
}
