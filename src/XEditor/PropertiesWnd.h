
#pragma once
//#include "Attribute.h"
#include "element.h"
#include "CPropertyGridCtrl.h"
class CPropertiesToolBar : public CMFCToolBar
{
public:
	virtual void OnUpdateCmdUI(CFrameWnd* /*pTarget*/, BOOL bDisableIfNoHndler)
	{
		CMFCToolBar::OnUpdateCmdUI((CFrameWnd*) GetOwner(), bDisableIfNoHndler);
	}

	virtual BOOL AllowShowOnList() const { return FALSE; }
};
static bool GetVarValueFromAny(boost::any anyValue, unsigned char type, _variant_t& value)
{
	switch (type)
	{
	case byBaseTypeBool:
		{
			try
			{
				bool val = boost::any_cast<bool>(anyValue);
				value = val;
			}
			catch (boost::bad_any_cast&)
			{
				return false;
			}			
		}
		break;
	case byBaseTypeWord:
		{
			try
			{
				unsigned short val = boost::any_cast<unsigned short>(anyValue);
				value = val;
			}
			catch (boost::bad_any_cast&)
			{
				return false;
			}			
		}
		break;
	case byBaseTypeShort:
		{
			try
			{
				short val = boost::any_cast<short>(anyValue);
				value = val;
			}
			catch (boost::bad_any_cast&)
			{
				return false;
			}			
		}
		break;
	case byBaseTypeDword:
		{
			try
			{
				unsigned int val = boost::any_cast<unsigned int>(anyValue);
				value = val;
			}
			catch (boost::bad_any_cast&)
			{
				return false;
			}			
		}
		break;
	case byBaseTypeLong:
		{
			try
			{
				long val = boost::any_cast<long>(anyValue);
				value = val;
			}
			catch (boost::bad_any_cast&)
			{
				return false;
			}			
		}
		break;
	case byBaseTypeLonglong:
		{
			try
			{
				long long val = boost::any_cast<long long>(anyValue);
				value = val;
			}
			catch (boost::bad_any_cast&)
			{
				return false;
			}			
		}
		break;
	case byBaseTypeFloat:
		{
			try
			{
				float val = boost::any_cast<float>(anyValue);
				value = val;
			}
			catch (boost::bad_any_cast&)
			{
				return false;
			}			
		}
		break;
	case byBaseTypeDouble:
		{
			try
			{
				double val = boost::any_cast<double>(anyValue);
				value = val;
			}
			catch (boost::bad_any_cast&)
			{
				return false;
			}			
		}
		break;
	case byBaseTypeString:
		{
			try
			{
				std::string val = boost::any_cast<std::string>(anyValue);
				value = val.c_str();
			}
			catch (boost::bad_any_cast&)
			{
				return false;
			}			
		}
		break;
	case byBaseTypeInt:
		{
			try
			{
				int val = boost::any_cast<int>(anyValue);
				value = val;
			}
			catch (boost::bad_any_cast&)
			{
				return false;
			}			
		}
		break;
	default:
		TRACE("Unknown Data Type %d\n", type);
		return false;
		break;
	}
	return true;
}
static bool VarConverToAnyValue(COleVariant var, boost::any& anyValue, unsigned char type)
{
	bool bRet = true;
	switch (var.vt)
	{
	case VT_UI1:
		{
			unsigned char value = var.bVal;
			anyValue = value;
		}
		break;
	case VT_UI2:
		{
			unsigned short value = var.uiVal;
			anyValue = value;
		}
		break;
	case VT_UI4:
		{
			unsigned int value = var.ulVal;
			anyValue = value;
		}
		break;
	case VT_I1:
		{
			char value = var.cVal;
			anyValue = value;
		}
		break;
	case VT_I2:
		{
			short value = var.iVal;
			anyValue = value;
		}
		break;
	case VT_I4:
		{
			long value = var.lVal;
			int nValue = (int)value;
			if(type == 0x0a )
				anyValue = nValue;
			else
				anyValue = value;
		}
		break;
	case VT_I8:
		{
			long long value = var.llVal;
			anyValue = value;
		}
		break;		
	case VT_R4:
		{
			float value = var.fltVal;
			anyValue = value;
		}
		break;
	case VT_R8:
		{
			double value = var.dblVal;
			anyValue = value;
		}
		break;
	case VT_BOOL:
		{
			anyValue = bool(var.boolVal?true:false);
		}
		break;
	case VT_INT:
		{
			int value = var.intVal;
			anyValue = value;
		}
		break;	
	case VT_UINT:
		{
			unsigned int value = var.intVal;
			anyValue = value;
		}
		break;	
	case VT_BSTR:
		{
			char   *p=_com_util::ConvertBSTRToString(var.bstrVal); 
			std::string value = p;
			delete p;
			if (type == byBaseTypeString)
				anyValue = value;
		}
		break;
	default:
		bRet = false;
		break;
	}
	return bRet;
}
class CPropertiesWnd;
class CPropertyGrid  : public CMFCPropertyGridProperty
{
public:
	CPropertyGrid(const CString& strGroupName, DWORD_PTR dwData = 0, BOOL bIsValueList = FALSE) : CMFCPropertyGridProperty(strGroupName, dwData, bIsValueList)
	{
	}

	// Simple property
	CPropertyGrid(const CString& strName, const COleVariant& varValue, LPCTSTR lpszDescr = NULL, DWORD_PTR dwData = 0,
		LPCTSTR lpszEditMask = NULL, LPCTSTR lpszEditTemplate = NULL, LPCTSTR lpszValidChars = NULL) : CMFCPropertyGridProperty(
		strName, varValue, lpszDescr, dwData, lpszEditMask, lpszEditTemplate, lpszValidChars)
	{
	}
	virtual void OnPropertyChanged()=0;
};

class CPropertyGridProperty : public CPropertyGrid
{
public:	
	CPropertyGridProperty(const CString& strGroupName, DWORD_PTR dwData = 0, BOOL bIsValueList = FALSE):CPropertyGrid(strGroupName,
		dwData, bIsValueList),m_pAnyValue(NULL),m_bChange(false),m_bUnion(false)
	{
	}
	CPropertyGridProperty(const CString& strName, const COleVariant& varValue, LPCTSTR lpszDescr = NULL, DWORD_PTR dwData = 0,
		LPCTSTR lpszEditMask = NULL, LPCTSTR lpszEditTemplate = NULL, LPCTSTR lpszValidChars = NULL):CPropertyGrid(
		strName, varValue, lpszDescr, dwData, lpszEditMask, lpszEditTemplate, lpszValidChars),m_pAnyValue(NULL),m_bChange(false),m_bUnion(false)
	{
	}
	CPropertyGridProperty(const CString& strName, const COleVariant& varValue, boost::any* pAnyValue, std::tr1::shared_ptr<CBaseType> pOrgType, boost::any AnyValUp, boost::any AnyValLow):CPropertyGrid(
		strName, varValue, NULL, 0, NULL, NULL, NULL),m_OrgType(pOrgType),m_pAnyValue(pAnyValue),m_bChange(true),m_bUnion(false)
	{
		if(m_OrgType->HasLimit())
		{
			_variant_t valueUp, valueLow;
			GetVarValueFromAny(AnyValUp, m_OrgType->GetBaseType(), valueUp);
			m_varValUp = valueUp;
			GetVarValueFromAny(AnyValLow, m_OrgType->GetBaseType(), valueLow);
			m_varValLow = valueLow;
		}
		if(!m_OrgType->HasEnum())
		{
			_variant_t value;
			if (m_pAnyValue && GetVarValueFromAny(*m_pAnyValue,m_OrgType->GetBaseType(), value))
			{
				SetOriginalValue(value);
				SetValue(value);			
			}
		}		
	}
	CPropertyGridProperty(CPropertiesWnd* pPropertiesWnd, CPropertyGridProperty* pParentWnd, const CString& strName, const COleVariant& varValue, std::tr1::shared_ptr<CAttr> pAttr, int& iSelect):CPropertyGrid(
		strName, varValue, NULL, 0, NULL, NULL, NULL),m_pPropertiesWnd(pPropertiesWnd),m_pParentWnd(pParentWnd),m_pAttr(pAttr),m_pAnyValue(NULL),m_bChange(true),m_bUnion(true)
	{
	}
	virtual ~CPropertyGridProperty()
	{

	}
	void Reflash()
	{
	}
	virtual void OnPropertyChanged();
	bool CheckValue(COleVariant& varCurrVal);
	std::tr1::shared_ptr<CAttr> GetAttrPtr(){return m_pAttr;}
private:
	bool	m_bChange;
	std::tr1::shared_ptr<CBaseType> m_OrgType;
	boost::any* m_pAnyValue;
	COleVariant m_varValUp,m_varValLow;
private:
	bool m_bUnion;
	std::tr1::shared_ptr<CAttr> m_pAttr;
	CPropertyGridProperty* m_pParentWnd;
	CPropertiesWnd* m_pPropertiesWnd;
};

class CStructsCountProperty : public CPropertyGrid
{
public:	
	CStructsCountProperty(CPropertiesWnd* pPropertiesWnd, CPropertyGridProperty* pParentWnd, const CString& strName, long nItemCount, std::tr1::shared_ptr<CStructsAttr> pAttr)
		:CPropertyGrid(strName, COleVariant(nItemCount), NULL, 0, NULL, NULL, NULL)
		,m_pPropertiesWnd(pPropertiesWnd),m_pParentWnd(pParentWnd),m_pAttr(pAttr),m_bChange(true),m_nItemCount(nItemCount)
	{
	}
	virtual ~CStructsCountProperty()
	{

	}
	virtual void OnPropertyChanged();
	std::tr1::shared_ptr<CAttr> GetAttrPtr(){return m_pAttr;}
private:
	bool	m_bChange;
//	std::tr1::shared_ptr<CStructType> m_OrgType;
	long m_nItemCount;
//	boost::any* m_pAnyValue;
private:
	std::tr1::shared_ptr<CStructsAttr> m_pAttr;
	CPropertyGridProperty* m_pParentWnd;
	CPropertiesWnd* m_pPropertiesWnd;
};

class CPropertiesWnd : public CDockablePane
{
// 构造
public:
	CPropertiesWnd() : m_bExpan(TRUE){}

	void AdjustLayout();

// 特性
public:
	void SetVSDotNetLook(BOOL bSet)
	{
		m_wndPropList.SetVSDotNetLook(bSet);
		m_wndPropList.SetGroupNameFullWidth(bSet);
	}

protected:
	CFont m_fntPropList;
	CPropertiesToolBar m_wndToolBar;
	CPropertyGridCtrl m_wndPropList;

// 实现
public:
	virtual ~CPropertiesWnd(){};

protected:
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnExpandAllProperties();
	afx_msg void OnUpdateExpandAllProperties(CCmdUI* pCmdUI);
	afx_msg void OnSortProperties();
	afx_msg void OnUpdateSortProperties(CCmdUI* pCmdUI);
	afx_msg void OnAdd();
	afx_msg void OnUpdateAdd(CCmdUI* pCmdUI);
	afx_msg void OnModify();
	afx_msg void OnUpdateModify(CCmdUI* pCmdUI);
	afx_msg void OnSetFocus(CWnd* pOldWnd);
	afx_msg void OnSettingChange(UINT uFlags, LPCTSTR lpszSection);
	afx_msg void OnTypeChanged();

	DECLARE_MESSAGE_MAP()

	void SetPropListFont();	
public:
	void SetElement(std::tr1::shared_ptr<CElement> pElement,bool bIsParent,bool bIsBranch);
	void InitPropList(std::tr1::shared_ptr<const CAttrsDef> pAttrsDef);
	void InitPropListType(CMFCPropertyGridProperty* pParentWnd, std::tr1::shared_ptr<CAttr> pAttr);
	void InitPropListType(CMFCPropertyGridProperty* pParentWnd, std::tr1::shared_ptr<CStructType> , std::vector<boost::any>& CurVal,CString strName=(""));
	void InitPropListType(CMFCPropertyGridProperty* pParentWnd, std::tr1::shared_ptr<CBaseType> , boost::any& CurVal);
	void InitPropListType(CMFCPropertyGridProperty* pParentWnd, std::tr1::shared_ptr<CStructsAttr> pAttr);
//	void InitPropListType(CMFCPropertyGridProperty* pParentWnd, std::tr1::shared_ptr<CXLinkAttr> pAttr);
	void OnUnionPropChanged(CPropertyGridProperty* pProp);
	void OnStructsPropChanged(CStructsCountProperty* pProp, long iNewValue, long& iOldValue, std::tr1::shared_ptr<CStructsAttr> pAttr);
public:
	std::tr1::shared_ptr<CElement> m_pElement;
	bool m_bIsBranch,m_bIsParent;

private:
	CAttrs m_attrs;
	BOOL m_bExpan;
	UINT m_nType;
	int m_cx;
	int m_cy;
};

