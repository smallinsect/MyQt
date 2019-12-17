// NetArgConfig.cpp : implementation file
//

#include "stdafx.h"
#include "XEditor.h"
#include "NetArgConfig.h"
#include "afxdialogex.h"

#define  INIFILE "./config.ini"


// CNetArgConfig dialog

IMPLEMENT_DYNAMIC(CNetArgConfig, CDialog)

CNetArgConfig::CNetArgConfig(CWnd* pParent /*=NULL*/)
	: CDialog(CNetArgConfig::IDD, pParent)
	, m_nAddress(0)
	, m_nPort(0)
{

}

CNetArgConfig::~CNetArgConfig()
{
}

void CNetArgConfig::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_IPAddress(pDX, IDC_SVRIPADDRESS, m_nAddress);
	DDX_Text(pDX, IDC_SVRPORT, m_nPort);
	DDV_MinMaxUInt(pDX, m_nPort, 1, 65535);
}


BEGIN_MESSAGE_MAP(CNetArgConfig, CDialog)
	ON_BN_CLICKED(IDOK, &CNetArgConfig::OnBnClickedOk)
END_MESSAGE_MAP()

// CNetArgConfig message handlers

void CNetArgConfig::OnBnClickedOk()
{
	UpdateData(TRUE);
	SaveConfig();
	CDialog::OnOK();
}

BOOL CNetArgConfig::OnInitDialog()
{
	CDialog::OnInitDialog();
	LoadConfig();
	UpdateData(FALSE);
	return TRUE;
}


VOID CNetArgConfig::LoadConfig()
{
	char host[128];
	::GetPrivateProfileString("XEditor", "Host", "127.0.0.1", host, 128, INIFILE);
	m_nPort = ::GetPrivateProfileInt("XEditor", "Port", 10001, INIFILE );
	m_nAddress = htonl(inet_addr( host )); 
	m_sAddress = host;
}

VOID CNetArgConfig::SaveConfig()
{
	struct in_addr addr;
	addr.S_un.S_addr = ntohl(m_nAddress);
	char szPort[32] = {0};
	_itoa_s(m_nPort, szPort, 10 );
	m_sAddress =  inet_ntoa( addr );
	::WritePrivateProfileString("XEditor","Host",  m_sAddress, INIFILE );
	::WritePrivateProfileString("XEditor", "Port", szPort, INIFILE );
}
