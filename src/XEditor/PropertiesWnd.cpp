
#include "stdafx.h"
#include "PropertiesWnd.h"
#include "xEditor.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

/////////////////////////////////////////////////////////////////////////////
// CResourceViewBar
void CStructsCountProperty::OnPropertyChanged()
{
	if(m_pPropertiesWnd) 
		m_pPropertiesWnd->OnStructsPropChanged(this,GetValue().lVal,m_nItemCount,m_pAttr);
}

void CPropertyGridProperty::OnPropertyChanged()
{
	//回写值
	if(m_bUnion && m_pPropertiesWnd) 
	{
		m_pPropertiesWnd->OnUnionPropChanged(this);
		return;
	}
	if(!m_bChange) return;
	COleVariant varNewValue = GetValue();
	boost::any anyValue;
	if(!m_OrgType->HasEnum())
	{
	/*	if (this->m_p!CheckValue(varNewValue))
		{			
			SetValue(GetOriginalValue());
			AfxMessageBox("请输入区间内数值，不能大于最大值  或  小于最小值!");
			return;
		}
		else*/
		COleVariant varNewValue1 = GetOriginalValue();
		if(varNewValue1.vt == VT_INT && varNewValue.vt==VT_I4)
		{
			//varNewValue1.iVal = (int) varNewValue.lVal;
			//varNewValue = varNewValue1;
		}
			//SetOriginalValue(varNewValue);

		if(VarConverToAnyValue(varNewValue, anyValue, m_OrgType->GetBaseType()))
			*m_pAnyValue = anyValue;
		else
			TRACE("回写值失败");
	}
	else
	{
		char* p=_com_util::ConvertBSTRToString(varNewValue.bstrVal); 
		std::string value = p;
		delete p;
		boost::any anyVal;
		if (m_OrgType->GetEnumValueFrmDesc(value, anyVal))
			*m_pAnyValue = anyVal;
	}
}
bool CPropertyGridProperty::CheckValue(COleVariant& varCurrVal)
{
	bool bRet = true;
	//COleVariant m_varValUp,m_varValLow;
	if (m_pAttr)
	{
		std::tr1::shared_ptr<const CAttrDef> pAttrDef = m_pAttr->GetAttrDef();
		if (pAttrDef)
		{
			std::tr1::shared_ptr<CBaseType> pType = std::dynamic_pointer_cast<CBaseType>(pAttrDef->GetTypeDef());
			if (!pType->HasLimit())
				return bRet;
		}
	}
	if ( (varCurrVal.vt != m_varValLow.vt) || (varCurrVal.vt != m_varValUp.vt) )
		return false;
	switch (varCurrVal.vt)
	{
	case VT_UI1:
		{
			if( (varCurrVal.bVal < m_varValLow.bVal) || (varCurrVal.bVal > m_varValUp.bVal) )
				return false;
		}
		break;
	case VT_UI2:
		{
			if( (varCurrVal.uiVal < m_varValLow.uiVal) || (varCurrVal.uiVal > m_varValUp.uiVal) )
				return false;
		}
		break;
	case VT_UI4:
		{
			if( (varCurrVal.ulVal < m_varValLow.ulVal) || (varCurrVal.uiVal > m_varValUp.uiVal) )
				return false;
		}
		break;
	case VT_UI8:
		{
			if( (varCurrVal.ullVal < m_varValLow.ullVal) || (varCurrVal.ullVal > m_varValUp.ullVal) )
				return false;
		}
		break;
	case VT_I1:
		{
			if( (varCurrVal.cVal < m_varValLow.cVal) || (varCurrVal.cVal > m_varValUp.cVal) )
				return false;
		}
		break;
	case VT_I2:
		{
			if( (varCurrVal.iVal < m_varValLow.iVal) || (varCurrVal.iVal > m_varValUp.iVal) )
				return false;
		}
		break;
	case VT_I4:
		{
			if( (varCurrVal.lVal < m_varValLow.lVal) || (varCurrVal.lVal > m_varValUp.lVal) )
				return false;
		}
		break;
	case VT_I8:
		{
			if( (varCurrVal.llVal < m_varValLow.llVal) || (varCurrVal.llVal > m_varValUp.llVal) )
				return false;
		}
		break;		
	case VT_R4:
		{
			if( (varCurrVal.fltVal < m_varValLow.fltVal) || (varCurrVal.fltVal > m_varValUp.fltVal) )
				return false;
		}
		break;
	case VT_BOOL:
		break;
	case VT_INT:
		{
			if( (varCurrVal.intVal < m_varValLow.intVal) || (varCurrVal.intVal > m_varValUp.intVal) )
				return false;
		}
		break;	
	case VT_UINT:
		{
			if( (varCurrVal.intVal < m_varValLow.intVal) || (varCurrVal.intVal > m_varValUp.intVal) )
				return false;
		}
		break;	
	case VT_BSTR:
		break;
	default:
		bRet = false;
		break;
	}
	return bRet;
}

BEGIN_MESSAGE_MAP(CPropertiesWnd, CDockablePane)
	ON_WM_CREATE()
	ON_WM_SIZE()
	ON_COMMAND(ID_ELEMENTTYPE, OnExpandAllProperties)
	ON_UPDATE_COMMAND_UI(ID_ELEMENTTYPE, OnUpdateExpandAllProperties)
//	ON_COMMAND(ID_SORTPROPERTIES, OnSortProperties)
//	ON_UPDATE_COMMAND_UI(ID_SORTPROPERTIES, OnUpdateSortProperties)
	ON_COMMAND(ID_OPT_DEVADD, OnAdd)
	ON_UPDATE_COMMAND_UI(ID_OPT_DEVADD, OnUpdateAdd)
	ON_COMMAND(ID_OPT_DEVMODIFY, OnModify)
	ON_UPDATE_COMMAND_UI(ID_OPT_DEVMODIFY, OnUpdateModify)
	ON_WM_SETFOCUS()
	ON_WM_SETTINGCHANGE()
	ON_CBN_SELCHANGE(ID_ELEMENTTYPE, OnTypeChanged)
	
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CResourceViewBar 消息处理程序

void CPropertiesWnd::AdjustLayout()
{
	if (GetSafeHwnd() == NULL)
	{
		return;
	}

	CRect rectClient;
	GetClientRect(rectClient);
	int cyTlb = m_wndToolBar.CalcFixedLayout(FALSE, TRUE).cy;

	m_wndToolBar.SetWindowPos(NULL, rectClient.left, rectClient.top, rectClient.Width(), cyTlb, SWP_NOACTIVATE | SWP_NOZORDER);
	m_wndPropList.SetWindowPos(NULL, rectClient.left, rectClient.top + cyTlb, rectClient.Width(), rectClient.Height() -cyTlb, SWP_NOACTIVATE | SWP_NOZORDER);
}

int CPropertiesWnd::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CDockablePane::OnCreate(lpCreateStruct) == -1)
		return -1;

	CRect rectDummy;
	rectDummy.SetRectEmpty();

	if (!m_wndPropList.Create(WS_VISIBLE | WS_CHILD, rectDummy, this, 2))
	{
		TRACE0("未能创建属性网格\n");
		return -1;      // 未能创建
	}

	SetPropListFont();
	m_wndPropList.EnableHeaderCtrl(FALSE);
	m_wndPropList.EnableDescriptionArea();
	m_wndPropList.SetVSDotNetLook();
	m_wndPropList.MarkModifiedProperties();

	m_wndToolBar.Create(this, AFX_DEFAULT_TOOLBAR_STYLE, IDR_PROPERTIES);
	m_wndToolBar.LoadToolBar(IDR_PROPERTIES, 0, 0, TRUE /* 已锁定*/);
	m_wndToolBar.CleanUpLockedImages();
	m_wndToolBar.LoadBitmap(theApp.m_bHiColorIcons ? IDB_PROPERTIES_HC : IDR_PROPERTIES, 0, 0, TRUE /* 锁定*/);

	m_wndToolBar.SetPaneStyle(m_wndToolBar.GetPaneStyle() | CBRS_TOOLTIPS | CBRS_FLYBY);
	m_wndToolBar.SetPaneStyle(m_wndToolBar.GetPaneStyle() & ~(CBRS_GRIPPER | CBRS_SIZE_DYNAMIC | CBRS_BORDER_TOP | CBRS_BORDER_BOTTOM | CBRS_BORDER_LEFT | CBRS_BORDER_RIGHT));
	m_wndToolBar.SetOwner(this);

	// 所有命令将通过此控件路由，而不是通过主框架路由:
	m_wndToolBar.SetRouteCommandsViaFrame(FALSE);

	CMFCToolBarComboBoxButton comboButton(ID_ELEMENTTYPE, GetCmdMgr ()->GetCmdImage (ID_ELEMENTTYPE),CBS_DROPDOWNLIST,100);

	m_wndToolBar.ReplaceButton(ID_ELEMENTTYPE,comboButton);
//	InitPropList(m_pAttrs);
	AdjustLayout();
	return 0;
}

void CPropertiesWnd::OnSize(UINT nType, int cx, int cy)
{
	m_nType = nType;
	m_cx = cx;
	m_cy = cy;
	CDockablePane::OnSize(nType, cx, cy);
	AdjustLayout();
}

void CPropertiesWnd::OnExpandAllProperties()
{
//	m_wndPropList.ExpandAll(!m_bExpan);
//	m_bExpan = !m_bExpan;
}

void CPropertiesWnd::OnUpdateExpandAllProperties(CCmdUI*  pCmdUI )
{
	pCmdUI->Enable(!m_bIsBranch);
}

void CPropertiesWnd::OnSortProperties()
{
	m_wndPropList.SetAlphabeticMode(!m_wndPropList.IsAlphabeticMode());
}

void CPropertiesWnd::OnUpdateSortProperties(CCmdUI* pCmdUI)
{
	pCmdUI->SetCheck(m_wndPropList.IsAlphabeticMode());
}

void CPropertiesWnd::OnAdd()
{
	CElementMgr::New((m_bIsParent?m_pElement:m_pElement->GetParent().lock()),m_attrs);
}

void CPropertiesWnd::OnUpdateAdd(CCmdUI* pCmdUI)
{
	pCmdUI->Enable(m_pElement && !m_bIsBranch);
}

void CPropertiesWnd::OnModify()
{
	CElementMgr::Modify(m_pElement,m_attrs,m_bIsBranch);
}

void CPropertiesWnd::OnUpdateModify(CCmdUI* pCmdUI)
{
	pCmdUI->Enable(m_pElement && !m_bIsParent);
}

void CPropertiesWnd::OnSetFocus(CWnd* pOldWnd)
{
	CDockablePane::OnSetFocus(pOldWnd);
	m_wndPropList.SetFocus();
}

void CPropertiesWnd::OnSettingChange(UINT uFlags, LPCTSTR lpszSection)
{
	CDockablePane::OnSettingChange(uFlags, lpszSection);
	SetPropListFont();
}

void CPropertiesWnd::SetPropListFont()
{
	::DeleteObject(m_fntPropList.Detach());
	LOGFONT lf;
	afxGlobalData.fontRegular.GetLogFont(&lf);
	NONCLIENTMETRICS info;
	info.cbSize = sizeof(info);
	afxGlobalData.GetNonClientMetrics(info);
	lf.lfHeight = info.lfMenuFont.lfHeight;
	lf.lfWeight = info.lfMenuFont.lfWeight;
	lf.lfItalic = info.lfMenuFont.lfItalic;
	m_fntPropList.CreateFontIndirect(&lf);
	m_wndPropList.SetFont(&m_fntPropList);
}

//****************************************************************************************
void CPropertiesWnd::OnTypeChanged() 
{
	CMFCToolBarComboBoxButton* pSrcCombo = 
		CMFCToolBarComboBoxButton::GetByCmd (ID_ELEMENTTYPE, TRUE);
	if (pSrcCombo)
	{
		int nIdx = pSrcCombo->GetCurSel();
		if (nIdx != -1)
		{
			std::string strType(pSrcCombo->GetItem(nIdx));
			if (m_attrs.GetType() != strType)
			{
				if (!m_bIsParent)
				{
					m_pElement = m_pElement->GetParent().lock();
					m_bIsParent = true;
				}
				std::tr1::shared_ptr<const CAttrsDef> pAttrsDef = CAttrsDef::GetAttrsDef(strType);
				m_attrs.SetDef(pAttrsDef);
				InitPropList(pAttrsDef);
			}
		}
	}

}

void CPropertiesWnd::SetElement(std::tr1::shared_ptr<CElement> pElement,bool bIsParent,bool bIsBranch)
{	
	m_pElement = pElement;
	m_bIsParent = bIsParent;
	m_bIsBranch = bIsBranch;
	CMFCToolBarComboBoxButton* pSrcCombo = CMFCToolBarComboBoxButton::GetByCmd (ID_ELEMENTTYPE);
	if (pSrcCombo)
	{
		pSrcCombo->RemoveAllItems();
		if (!m_bIsBranch)
		{
			std::vector<std::string> vecTypes =	m_bIsParent ? m_pElement->GetChildTypes(): (m_pElement->GetParent().lock()->GetChildTypes());
			std::vector<std::string>::iterator it = vecTypes.begin();
			for ( ; it!=vecTypes.end(); it++)
				pSrcCombo->AddItem(it->c_str());
			if (m_bIsParent)
				pSrcCombo->SelectItem(0);
			else 
				pSrcCombo->SelectItem(pElement->GetType().c_str());
		}
		else
		{
			pSrcCombo->AddItem(m_pElement->GetType().c_str());
			pSrcCombo->SelectItem(0);
		}
//		pSrcCombo->GetComboBox()->Invalidate();
		m_wndToolBar.Invalidate();
//		pSrcCombo->SetVisible(FALSE);
//		pSrcCombo->SetVisible(TRUE);
//		pSrcCombo->Show(TRUE);
//		pSrcCombo->EnableWindow(m_bIsBranch?FALSE:TRUE);
	}

	std::tr1::shared_ptr<const CAttrsDef> pAttrsDef = CAttrsDef::GetAttrsDef(m_bIsParent ? m_pElement->GetChildType() : m_pElement->GetType());
	
	if (m_bIsParent)
		m_attrs.SetDef(pAttrsDef);
	else //if (m_attrs != m_pElement->GetAttrs())
		m_attrs.Clone(m_pElement->GetAttrs());
//	else
//		return;
	InitPropList(pAttrsDef);
}

void CPropertiesWnd::InitPropList(std::tr1::shared_ptr<const CAttrsDef> pAttrsDef)
{
	m_wndPropList.RemoveAll();

	CMFCPropertyGridProperty* pGroupSum = new CMFCPropertyGridProperty(_T(pAttrsDef->GetName().c_str()));
	m_wndPropList.AddProperty(pGroupSum);


	for (size_t i=0; i<m_attrs.GetFieldCount(); i++)
	{
		std::tr1::shared_ptr<CAttr> pAttr = m_attrs.GetFieldValuePtr(i);
		if(pAttr != NULL)
		{
			switch(pAttr->GetType())
			{
			case eBaseType:
				InitPropListType(pGroupSum, std::dynamic_pointer_cast<CBaseType>(pAttr->GetAttrDef()->GetTypeDef()), std::dynamic_pointer_cast<CBaseAttr>(pAttr)->GetValue());
				break;
			case  eStructType:
				InitPropListType(pGroupSum, std::dynamic_pointer_cast<CStructType>(pAttr->GetAttrDef()->GetTypeDef()), std::dynamic_pointer_cast<CStructAttr>(pAttr)->GetValue());
				break;
			case eUnionType:
				InitPropListType(pGroupSum, pAttr);
				break;
			case eComplexType:
				InitPropListType(pGroupSum, std::dynamic_pointer_cast<CStructsAttr>(pAttr));
				break;
			case eXLinkType:
				InitPropListType(pGroupSum, std::dynamic_pointer_cast<CXLinkAttr>(pAttr));
				break;
			default:
				break;
			}
		}
	}
	pGroupSum->Expand(FALSE);
	pGroupSum->Expand();
}

void CPropertiesWnd::OnStructsPropChanged(CStructsCountProperty* pProp, long iNewValue, long& iOldValue, std::tr1::shared_ptr<CStructsAttr> pAttr)
{
	int iLastCount = iOldValue;
	pAttr->SetItemCount (iNewValue);
	CMFCPropertyGridProperty* pParentProp = pProp->GetParent();
	if( pParentProp == NULL ) return;
	int iDelSubCount = iOldValue - iNewValue;
	if(iDelSubCount > 0)
	{
		for (int i=iOldValue; i>iNewValue; i--)
		{
			CMFCPropertyGridProperty* pp = pParentProp->GetSubItem(i);
			if(pp) pParentProp->RemoveSubItem (pp);
		}
	}
	else
	{
		std::tr1::shared_ptr<CStructType> pOrgType = std::dynamic_pointer_cast<CStructType>(pAttr->GetAttrDef()->GetTypeDef());
		for (int i=iLastCount; i<pAttr->GetItemCount(); i++)
		{
			CString strMsg;
			strMsg.Format (" %d", i+1);
			InitPropListType(pParentProp, pOrgType,  pAttr->GetValue(i), strMsg);
		}		
	}
	
	pParentProp->Expand(FALSE);
	pParentProp->Expand(TRUE);
	iOldValue = iNewValue;
}

void CPropertiesWnd::OnUnionPropChanged(CPropertyGridProperty* pProp)
{
	CMFCPropertyGridProperty* pParentProp = pProp->GetParent();
	if( pParentProp == NULL ) return;
	int iSubCount = pParentProp->GetSubItemsCount();
	bool bFind = false;
	for (int i=0; i<iSubCount; i++)
	{
		CPropertyGridProperty* p = (CPropertyGridProperty*)(pParentProp->GetSubItem(i));
		if(pProp == p)
		{
			if((i+1)<iSubCount)
			{
				i++;
				bFind = true;
			}
			else
				break;
		}
		if(bFind)
		{
			//删除元素
			while(i<pParentProp->GetSubItemsCount())
			{
				CMFCPropertyGridProperty* pp = pParentProp->GetSubItem(i);
				pParentProp->RemoveSubItem(pp, TRUE);
			}
			//插入新元素
			int iSelectCount = pProp->GetOptionCount();
			char* p=_com_util::ConvertBSTRToString(pProp->GetValue().bstrVal); 
			std::string SelValue = p;
			delete p;
			size_t stSelectIdx = 0;
			for (int nn=0; nn<iSelectCount; nn++)
			{
				std::string strOption = pProp->GetOption(nn);
				if(SelValue == strOption)
				{
					stSelectIdx = nn;
					break;
				}
			}
			std::tr1::shared_ptr<CStructType> st;
			if( (std::dynamic_pointer_cast<CUnionType>(pProp->GetAttrPtr()->GetAttrDef()->GetTypeDef()))->GetStructTypeDef(stSelectIdx, st))
			{
	//			std::tr1::shared_ptr<CAttrDef> def;
	//			st->GetBaseTypeDef(pProp->GetAttrPtr()->GetAttrDef()->GetIdx(), def);
				InitPropListType(pParentProp, st, (std::dynamic_pointer_cast<CUnionAttr>(pProp->GetAttrPtr()))->GetValue());
			}
			break;
		}
	}
	pParentProp->Expand(FALSE);
	pParentProp->Expand(TRUE);
}

void CPropertiesWnd::InitPropListType(CMFCPropertyGridProperty* pParentWnd,std::tr1::shared_ptr<CAttr> pAttr)
{	
	std::vector<boost::any>&  CurVal = std::dynamic_pointer_cast<CUnionAttr>(pAttr)->GetValue();
	int iSelect = std::dynamic_pointer_cast<CUnionAttr>(pAttr)->GetSelect();

	if((pParentWnd == NULL)|| (pAttr == NULL)) return;

	std::tr1::shared_ptr<const CAttrDef> pAttrDef = pAttr->GetAttrDef();
	if(pAttrDef == NULL) return;
	std::tr1::shared_ptr<const CUnionType> pOrgType = std::dynamic_pointer_cast<CUnionType>(pAttrDef->GetTypeDef());
	if(pOrgType == NULL) return;
	if(pOrgType->Size() != CurVal.size()) return;

	CString strName = pAttrDef->GetName().c_str();
	CPropertyGridProperty* pGroup = new CPropertyGridProperty(_T(strName.GetBuffer()));
	pParentWnd->AddSubItem(pGroup);

	CPropertyGridProperty* pSel = new CPropertyGridProperty(this, pGroup, _T("当前配置"), _T("配置"), pAttr, iSelect);
	pGroup->AddSubItem(pSel);
	for (size_t i=0; i<pOrgType->Size(); i++)
	{		
		std::tr1::shared_ptr<CStructType> st;
		if( pOrgType->GetStructTypeDef(i, st) )
			pSel->AddOption(_T(st->GetName().c_str()));
		if(i == iSelect)
		{
			pSel->SetValue((_variant_t)(st->GetName().c_str()));
			InitPropListType(pGroup, st,  CurVal);
		}
	}
}

void CPropertiesWnd::InitPropListType(CMFCPropertyGridProperty* pParentWnd, std::tr1::shared_ptr<CStructType> pOrgType, std::vector<boost::any>& CurVal,CString strName1)
{
	if((pParentWnd == NULL)|| (pOrgType == NULL)) return;
	if(pOrgType->Size() != CurVal.size()) return;
	CString strName = strName1;
	if (strName.IsEmpty())
		strName = pOrgType->GetName().c_str();
	CMFCPropertyGridProperty* pGroup = new CMFCPropertyGridProperty(_T(strName.GetBuffer()));
	pParentWnd->AddSubItem(pGroup);

	for (size_t i=0; i<pOrgType->Size(); i++)
	{		
		std::tr1::shared_ptr<CTypeDef> td;

		if( pOrgType->GetBaseTypeDef(i, td) )
		{
			std::tr1::shared_ptr<CBaseType> bt = std::dynamic_pointer_cast<CBaseType>(td);
			InitPropListType(pGroup, bt, CurVal[i]);
		}
	}
}

void CPropertiesWnd::InitPropListType(CMFCPropertyGridProperty* pParentWnd, std::tr1::shared_ptr<CBaseType> pOrgType, boost::any& CurVal)
{
	if((pParentWnd == NULL)|| (pOrgType == NULL)) return;

	CString strName = pOrgType->GetName().c_str();
	
	_variant_t varValue;
	boost::any anyValUp, anyValLow;
	pOrgType->GetPropertyLimit(anyValLow, anyValUp);
	if (!pOrgType->HasEnum())
	{
		varValue.Clear();
		if( GetVarValueFromAny(CurVal, pOrgType->GetBaseType(), varValue) )
		{
			CPropertyGridProperty *pVal = new CPropertyGridProperty(_T(strName.GetBuffer()), varValue,&CurVal, pOrgType, anyValUp, anyValLow);
			pParentWnd->AddSubItem(pVal);
		}
	}	
	else
	{
		std::string strCurVal = "枚举值不可用";
		pOrgType->GetDescFrmEnumValue(strCurVal, CurVal);		
		CPropertyGridProperty *pVal = new CPropertyGridProperty(_T(strName.GetBuffer()), (_variant_t)(strCurVal.c_str()), &CurVal, pOrgType, anyValUp, anyValLow);
		pParentWnd->AddSubItem(pVal);
		std::vector<std::string> vecEnum = pOrgType->GetEnumDesc();
		for (std::vector<std::string>::iterator iter = vecEnum.begin(); iter != vecEnum.end(); iter++)
			pVal->AddOption(_T((*iter).c_str()));
		pVal->AllowEdit(FALSE);
	}
}
/*
void CPropertiesWnd::InitPropListType(CMFCPropertyGridProperty* pParentWnd, std::tr1::shared_ptr<CXLinkAttr> pAttr)
{
	if((pParentWnd == NULL)|| (pAttr == NULL)) return;
	std::tr1::shared_ptr<CAttrDef> pAttrDef = pAttr->GetAttrDef();
	if(pAttrDef == NULL) return;
	CUnionType* m_pOrgType = (CUnionType*)(pAttrDef->GetTypeDef());
	if(m_pOrgType == NULL) return;	
	CPropertyGridProperty* pSel = new CPropertyGridProperty(this, _T("目标数"), _variant_t(int(0)), pAttr->GetItemCountValue(), pAttr);
	pParentWnd->AddSubItem(pSel);
	for (int i=0; i<pAttr->GetItemCount (); i++)
	{		
		CString strMsg;
		strMsg.Format ("目标 %d", i+1);
		CPropertyGridProperty* pGroup = new CPropertyGridProperty(this, _T(strMsg.GetBuffer()));
		pParentWnd->AddSubItem(pGroup);
		CPropertyGridProperty* pGroup1 = new CPropertyGridProperty(this,_T("名称"), _variant_t("值"), &(pAttr->GetValue(i).strName), pAttr);
		pGroup->AddSubItem(pGroup1);
		CPropertyGridProperty* pGroup2 = new CPropertyGridProperty(this,_T("目标"), _variant_t("值"), &(pAttr->GetValue(i).strTargetName), pAttr);
		pGroup->AddSubItem(pGroup2);
	}
}
*/

void CPropertiesWnd::InitPropListType(CMFCPropertyGridProperty* pParentWnd, std::tr1::shared_ptr<CStructsAttr> pAttr)
{
	if((pParentWnd == NULL)|| (pAttr == NULL)) return;
	std::tr1::shared_ptr<const CAttrDef> pAttrDef = pAttr->GetAttrDef();
	if(pAttrDef == NULL) return;
	std::tr1::shared_ptr<CStructType> pOrgType = std::dynamic_pointer_cast<CStructType>(pAttrDef->GetTypeDef());
	if(pOrgType == NULL) return;
	long nItemCount = pAttr->GetItemCount();
//	if (nItemCount == 0)
//		nItemCount = 1;
	CStructsCountProperty* pSel = new CStructsCountProperty(this,(CPropertyGridProperty*)pParentWnd, _T("配置数量"), nItemCount, pAttr);
	pSel->EnableSpinControl(TRUE,0,10);
	pParentWnd->AddSubItem(pSel);
	for (int i=0; i<pAttr->GetItemCount(); i++)
	{		
		CString strMsg;
		strMsg.Format (" %d", i+1);
		InitPropListType(pParentWnd,pOrgType,  pAttr->GetValue(i), strMsg);
	}
}
