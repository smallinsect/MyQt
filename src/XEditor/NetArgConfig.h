#pragma once
#include "afxcmn.h"
#include "resource.h"


// CNetArgConfig dialog

class CNetArgConfig : public CDialog
{
	DECLARE_DYNAMIC(CNetArgConfig)

public:
	CNetArgConfig(CWnd* pParent = NULL);   // standard constructor
	virtual ~CNetArgConfig();

// Dialog Data
	enum { IDD = IDD_NETARGCONFIG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
private:
	DWORD m_nAddress;

public:
	CString m_sAddress;
	UINT m_nPort;
	afx_msg void OnBnClickedOk();
	virtual BOOL OnInitDialog();
	VOID LoadConfig();
	VOID SaveConfig();
};
