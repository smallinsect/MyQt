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
}

void DialogConnect::loadConfig()
{
    char host[128];
    ::GetPrivateProfileString("XEditor", "Host", "127.0.0.1", host, 128, INIFILE);
    m_nPort = ::GetPrivateProfileInt("XEditor", "Port", 10001, INIFILE );
    m_nAddress = htonl(inet_addr( host ));
    m_sAddress = host;
}

void DialogConnect::DoDataExchange(CDataExchange* pDX)
{
    CDialog::DoDataExchange(pDX);
    DDX_IPAddress(pDX, IDC_SVRIPADDRESS, m_nAddress);
    DDX_Text(pDX, IDC_SVRPORT, m_nPort);
    DDV_MinMaxUInt(pDX, m_nPort, 1, 65535);
}
void DialogConnect::OnBnClickedOk()
{
    UpdateData(TRUE);
    saveConfig();
    CDialog::OnOK();
}

BOOL CNetArgConfig::OnInitDialog()
{
    CDialog::OnInitDialog();
    LoadConfig();
    UpdateData(FALSE);
    return TRUE;
}

void DialogConnect::saveConfig()
{
    struct in_addr addr;
    addr.S_un.S_addr = ntohl(m_nAddress);
    char szPort[32] = {0};
    //_itoa_s(m_nPort, szPort, 10 );
    m_sAddress = inet_ntoa( addr );
    ::WritePrivateProfileString("XEditor","Host",  m_sAddress, INIFILE );
    ::WritePrivateProfileString("XEditor", "Port", szPort, INIFILE );
}

void DialogConnect::init()
{
    loadConfig();
    UpdateData(FALSE);

    connect(ui->btnConnect, SIGNAL(clicked(bool)),
            this, SLOT(onClickConnect(bool)));
    connect(ui->btnCancel, SIGNAL(clicked(bool)),
            this, SLOT(onClickCancel(bool)));
}

void DialogConnect::onClickConnect(bool)
{
//    QString strIp = ui->leditIP->text();
//    QString strPort = ui->leditPort->text();
//    emit signalDialogBackData(strIp, strPort);
//    this->hide();
    UpdateData(true);
    saveConfig();
}

void DialogConnect::onClickCancel(bool)
{
    this->hide();
}
