#include "DialogConnect.h"
#include "ui_DialogConnect.h"

#define INIFILE "./config.ini"

DialogConnect::DialogConnect(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogConnect)
{
    ui->setupUi(this);
    init();
}

DialogConnect::~DialogConnect()
{
    delete ui;
    delete configInit;
}

void DialogConnect::loadConfig()
{
    m_sAddress = configInit->value(HOST).toString();
    m_nPort = configInit->value(PORT).toInt();

    ui->leditIP->setText(m_sAddress);
    ui->leditPort->setText(QString::number(m_nPort));
}


void DialogConnect::saveConfig()
{
    m_sAddress = ui->leditIP->text();
    m_nPort = ui->leditPort->text().toInt();

    configInit->setValue(HOST, m_sAddress);
    configInit->setValue(PORT, m_nPort);
}

void DialogConnect::init()
{
    connect(ui->btnConnect, SIGNAL(clicked(bool)),
            this, SLOT(onClickConnect(bool)));
    connect(ui->btnCancel, SIGNAL(clicked(bool)),
            this, SLOT(onClickCancel(bool)));

    configInit = new QSettings(INIFILE, QSettings::IniFormat);
}

void DialogConnect::onClickConnect(bool)
{
    saveConfig();
    this->hide();
}

void DialogConnect::onClickCancel(bool)
{
    this->hide();
}
