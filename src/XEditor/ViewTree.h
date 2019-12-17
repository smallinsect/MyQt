
#pragma once

/////////////////////////////////////////////////////////////////////////////
// CViewTree 窗口
#include "element.h"

class CViewTree : public CTreeCtrl
{
// 构造
public:
	CViewTree();
	HTREEITEM AddChild(std::tr1::shared_ptr<CElement> pElement,HTREEITEM  hParent,HTREEITEM hInsertAfter = TVI_LAST);
	void Add(std::tr1::shared_ptr<CElement> pNew);
	void Delete(std::tr1::shared_ptr<CElement> pNew);
	void Modify(std::tr1::shared_ptr<CElement> pNew);
// 重写
protected:
	virtual BOOL OnNotify(WPARAM wParam, LPARAM lParam, LRESULT* pResult);

protected:
	std::map<std::tr1::shared_ptr<CElement>,HTREEITEM> m_mapItemToNode;
	std::map<HTREEITEM,std::tr1::shared_ptr<CElement>> m_mapNodeToItem;
	std::map<std::string, UINT> m_mapDeviceTable;
	std::list<HTREEITEM> m_lstSearchResult;
	std::list<HTREEITEM>::iterator m_itSearchReslut;
	std::tr1::shared_ptr<CElement> GetNodeFromItem(HTREEITEM hItem) {
		std::tr1::shared_ptr<CElement> pRet;
		std::map<HTREEITEM,std::tr1::shared_ptr<CElement>>::const_iterator it = m_mapNodeToItem.find(hItem);
		if  (it != m_mapNodeToItem.end())
			pRet = it->second;
		return pRet;
	}

// 实现
public:
	void SetCurrentElement(std::tr1::shared_ptr<CElement> pElement);
	void InsertChildren(std::tr1::shared_ptr<CElement> pElement, HTREEITEM hParent=TVI_ROOT);

	virtual ~CViewTree();
public:
	afx_msg void OnTvnGetdispinfo(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnTvnSelchanging(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnNMSetfocus(NMHDR *pNMHDR, LRESULT *pResult);
protected:
	DECLARE_MESSAGE_MAP()
public:
	void SearchByKey(CString strKey );
	void ExpandReverItem(HTREEITEM hItem);
	void SearchPointToNext();
	void ExpandOnSameLevel( HTREEITEM hItem, int nCode );
};
