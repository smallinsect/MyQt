
#include "stdafx.h"
#include "ViewTree.h"
#include "MainFrm.h"
#include "XEditorDoc.h"
#include <regex>

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif


/////////////////////////////////////////////////////////////////////////////
// CViewTree

CViewTree::CViewTree()
{
	m_mapDeviceTable["CAnalyzerRoot"] = 1;
	m_mapDeviceTable["CNetworkCard"] = 2;
	m_mapDeviceTable["CSerialGroup"] = 3;
	m_mapDeviceTable["CFrontEndNIC"] = 4;
	m_mapDeviceTable["CCPGroup"] = 6;
	m_mapDeviceTable["CCAGroup"] = 6;
	m_mapDeviceTable["CCPChannel"] = 8;

	m_mapDeviceTable["C1014DevDef"] = 9;
	m_mapDeviceTable["CCDTDDevDef"] = 9; 
	m_mapDeviceTable["C1014SDevDef"] = 10;
	m_mapDeviceTable["CYCDefGrp"] = 11;
	m_mapDeviceTable["CYXDefGrp"] = 11;
	m_mapDeviceTable["CYTDefGrp"] = 11;
	m_mapDeviceTable["CYKDefGrp"] = 11;
	m_mapDeviceTable["CYCDef"] = 12;
	m_mapDeviceTable["CSerialChannel"] = 8;

	m_mapDeviceTable["CMoxa2510Group"] = 6;
	m_mapDeviceTable["CIEC104Group"] = 6;
	m_mapDeviceTable["CIEC102Group"] = 6;
	m_mapDeviceTable["CTASE2Group"] = 6;
	m_mapDeviceTable["CCAGroup"] = 6;
	m_mapDeviceTable["CCPGroup"] = 6;
	m_itSearchReslut = m_lstSearchResult.end();
}

CViewTree::~CViewTree()
{
}

BEGIN_MESSAGE_MAP(CViewTree, CTreeCtrl)
	ON_NOTIFY_REFLECT(TVN_GETDISPINFO, OnTvnGetdispinfo)
	ON_NOTIFY_REFLECT(TVN_SELCHANGING, OnTvnSelchanging)
	ON_NOTIFY_REFLECT(NM_SETFOCUS, &CViewTree::OnNMSetfocus)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CViewTree 消息处理程序

void CViewTree::SetCurrentElement(std::tr1::shared_ptr<CElement> pElement)
{
	std::map<std::tr1::shared_ptr<CElement> ,HTREEITEM>::iterator it = m_mapItemToNode.find(pElement);
	if  (it != m_mapItemToNode.end())
	{
		if (!pElement->GetLoadChildern())
			CElementMgr::LoadChildern(pElement);
		SelectItem(it->second);
	}
}

BOOL CViewTree::OnNotify(WPARAM wParam, LPARAM lParam, LRESULT* pResult)
{
	BOOL bRes = CTreeCtrl::OnNotify(wParam, lParam, pResult);

	NMHDR* pNMHDR = (NMHDR*)lParam;
	ASSERT(pNMHDR != NULL);

	if (pNMHDR && pNMHDR->code == TTN_SHOW && GetToolTips() != NULL)
	{
		GetToolTips()->SetWindowPos(&wndTop, -1, -1, -1, -1, SWP_NOMOVE | SWP_NOACTIVATE | SWP_NOSIZE);
	}

	return bRes;
}

void CViewTree::Add(std::tr1::shared_ptr<CElement> pParent)
{
	if (pParent)
	{
		InsertChildren(pParent);
		Modify(pParent);
	}
}

void CViewTree::Delete(std::tr1::shared_ptr<CElement> pElement)
{
	if (!pElement->GetChildType().empty())
	{
		std::map<std::tr1::shared_ptr<CElement> ,HTREEITEM>::iterator it = m_mapItemToNode.find(pElement);
		if  (it != m_mapItemToNode.end())
		{
			for (size_t i=0; i< pElement->GetChildSize(); i++)
				Delete(pElement->LocateChildNode(i));

			std::map<HTREEITEM,std::tr1::shared_ptr<CElement>>::const_iterator it1 = m_mapNodeToItem.find(it->second);
			if  (it1 != m_mapNodeToItem.end())
				m_mapNodeToItem.erase(it1);
		
			DeleteItem(it->second);
			m_mapItemToNode.erase(it);
		}
	}
}

void CViewTree::Modify(std::tr1::shared_ptr<CElement> pNew)
{
	if (pNew && !pNew->GetChildType().empty())
	{
		std::map<std::tr1::shared_ptr<CElement> ,HTREEITEM>::iterator it = m_mapItemToNode.find(pNew);
		if  (it != m_mapItemToNode.end())
		{
			EnsureVisible(it->second);
			SetItemState(it->second, TVIS_BOLD, TVIS_BOLD);
			SetItemState(it->second, ~TVIS_BOLD, TVIS_BOLD);
		}
	}
}

HTREEITEM CViewTree::AddChild(std::tr1::shared_ptr<CElement> pElement,HTREEITEM  hParent,HTREEITEM hInsertAfter)
{
	HTREEITEM hItem = NULL;
	std::map<std::tr1::shared_ptr<CElement> ,HTREEITEM>::iterator it = m_mapItemToNode.find(pElement);
	if  (it == m_mapItemToNode.end())
	{
		hItem = InsertItem(LPSTR_TEXTCALLBACK,hParent,hInsertAfter);
		if (hItem != NULL)
		{
//			SetItemData(hItem,(DWORD)pElement.get());
//			EnsureVisible(hItem);
			std::pair<std::tr1::shared_ptr<CElement>,HTREEITEM> p;
			std::pair<HTREEITEM,std::tr1::shared_ptr<CElement>> p1;
			p1.second = p.first = pElement;
			p1.first = p.second = hItem;
			m_mapItemToNode.insert(p);
			m_mapNodeToItem.insert(p1);

			std::map<std::string, UINT>::iterator ifnd = m_mapDeviceTable.find(pElement->GetType());
			if( ifnd != m_mapDeviceTable.end() )
				SetItemImage( hItem, ifnd->second, ifnd->second );
			else
				SetItemImage( hItem, 0, 0 );
		}
	}
	else
		hItem = it->second;
	return hItem;
}

void CViewTree::OnTvnGetdispinfo(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMTVDISPINFO pTVDispInfo = reinterpret_cast<LPNMTVDISPINFO>(pNMHDR);
	std::tr1::shared_ptr<CElement> pElement = GetNodeFromItem(pTVDispInfo->item.hItem);
	if (pElement)
	{
		lstrcpy(pTVDispInfo->item.pszText,(LPSTR)pElement->GetName().c_str());
	}
	*pResult = 0;
}

void CViewTree::OnTvnSelchanging(NMHDR *pNMHDR, LRESULT *pResult)
{
	*pResult = 1;
	LPNMTREEVIEW pNMTreeView = reinterpret_cast<LPNMTREEVIEW>(pNMHDR);
	std::tr1::shared_ptr<CElement> pElement = GetNodeFromItem(pNMTreeView->itemNew.hItem);
	if (pElement)
	{
		if (!pElement->GetLoadChildern())
			CElementMgr::LoadChildern(pElement);
		bool bExpand = true;
		if (bExpand)
		{
			CMainFrame *pMF = (CMainFrame *)::AfxGetMainWnd();
			pMF->SetCurrentBranch(pElement);
			*pResult = 0;
		}
	}
}

void CViewTree::OnNMSetfocus(NMHDR *pNMHDR, LRESULT *pResult)
{
	// TODO: 在此添加控件通知处理程序代码
	HTREEITEM h = GetSelectedItem();
	if (h != NULL)
	{
		std::tr1::shared_ptr<CElement> pElement = GetNodeFromItem(h);
		if (pElement != CElementMgr::GetCurrent())
		{
			CMainFrame *pMF = (CMainFrame *)::AfxGetMainWnd();
			pMF->SetCurrentBranch(pElement);
		}
	}
	*pResult = 0;
}

void CViewTree::InsertChildren(std::tr1::shared_ptr<CElement> pElement, HTREEITEM hParent )
{
	if(pElement && !pElement->GetChildType().empty())
	{
		HTREEITEM item = AddChild(pElement, hParent);
		for (size_t i=0; i< pElement->GetChildSize(); i++)
			InsertChildren(pElement->LocateChildNode(i), item);//InsertChildren
	}
}

//突出指到下一个搜索结果
void CViewTree::SearchPointToNext()
{
	if( m_lstSearchResult.end() != m_itSearchReslut ){	
		SelectItem( *m_itSearchReslut );
		m_itSearchReslut++;
	}else
		SelectItem( GetRootItem());
}

//格式化关键字搜索(暂时只处理三种方式)
// 1:  *key
// 2:  key*
// 3:  key
void CViewTree::SearchByKey( CString strKey )
{
	//重置
	for(std::map<HTREEITEM,std::tr1::shared_ptr<CElement>>::iterator it =m_mapNodeToItem.begin(); it!=m_mapNodeToItem.end();it++)
		SetItemState(it->first, 0,TVIS_BOLD );

	if( strKey.GetLength()<1 )
		return;

	CString strPatten;
	int nFind = strKey.Find('*');
	strKey.Replace("*","");
	strKey.MakeLower();
	if( nFind == 0 )
		strPatten.Format("(.*?)(%s)", strKey);
	else if ( nFind > 0 ) 
		strPatten.Format("^%s.*", strKey);
	else
		strPatten.Format("(.*?)(%s)(.*?)",strKey);

	m_lstSearchResult.clear();
	bool bResult = false;
	const std::regex pattern( strPatten.GetBuffer());
	for(std::map<HTREEITEM,std::tr1::shared_ptr<CElement>>::iterator it =m_mapNodeToItem.begin(); it!=m_mapNodeToItem.end();it++)
	{
		std::string sName = it->second->GetName();
		std::transform(sName.begin(),sName.end(),sName.begin(),tolower);
		if(regex_match( sName, pattern)){
			m_lstSearchResult.push_back( it->first );
			ExpandReverItem( GetParentItem(it->first) );
			SetItemState(it->first, TVIS_BOLD, TVIS_BOLD);
			bResult = true;
		}
	}
	if( bResult ){
		m_itSearchReslut = m_lstSearchResult.begin();
		SelectItem( *m_itSearchReslut );
		m_itSearchReslut++;
	}
}

//从子往父节点展开
void CViewTree::ExpandReverItem( HTREEITEM hItem )
{
	if( Expand( hItem, TVE_EXPAND ) ){
		HTREEITEM hParent = this->GetParentItem(hItem);
		if( hParent )
			ExpandReverItem( hParent);
	}
}

//同类展开合并操作
void CViewTree::ExpandOnSameLevel( HTREEITEM hItem,int nCode )
{
	std::map<HTREEITEM,std::tr1::shared_ptr<CElement>>::const_iterator ifnd = m_mapNodeToItem.find(hItem);
	if (ifnd == m_mapNodeToItem.end())
		return;
	string sType = ifnd->second->GetType();
	for( std::map<HTREEITEM,std::tr1::shared_ptr<CElement>>::const_iterator it = m_mapNodeToItem.begin(); it!=m_mapNodeToItem.end(); it++)
	{
		if( sType.compare( it->second->GetType()) == 0)
			Expand( it->first,nCode  );
	}
}