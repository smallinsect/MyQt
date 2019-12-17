#include "Form03.h"
#include "ui_Form03.h"

Form03::Form03(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form03)
{
    ui->setupUi(this);

    init();
}

Form03::~Form03()
{
    delete ui;
}

void Form03::init()
{
    count = 0;

    connect(ui->pushButton, SIGNAL(clicked(bool)),
            this, SLOT(onClickBackForm02(bool)));
}

void Form03::onClickBackForm02(bool)
{
    count++;
    this->hide();

    emit signalShowForm02(QString::number(count));
}
