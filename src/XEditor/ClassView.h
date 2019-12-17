
#pragma once

#include "ViewTree.h"

class CClassToolBar : public CMFCToolBar
{
	virtual void OnUpdateCmdUI(CFrameWnd* /*pTarget*/, BOOL bDisableIfNoHndler)
	{
		CMFCToolBar::OnUpdateCmdUI((CFrameWnd*) GetOwner(), bDisableIfNoHndler);
	}

	virtual BOOL AllowShowOnList() const { return FALSE; }
};

class CClassView : public CDockablePane
{
public:
	CClassView();
	virtual ~CClassView();

	void AdjustLayout();
	void OnChangeVisualStyle();
	void SetCurrentElement(std::tr1::shared_ptr<CElement> pElement);

protected:
	CClassToolBar m_wndToolBar;
	CViewTree m_wndClassView;
	CImageList m_ClassViewImages;
	UINT m_nCurrSort;

public:
	void FillClassView();
	void ClearClassView();

public:
	void AddChild(std::tr1::shared_ptr<CElement> pParent)
	{
		m_wndClassView.Add(pParent);
	}
	void DeleteChild(std::tr1::shared_ptr<CElement> pNew)
	{
		m_wndClassView.Delete(pNew);
	}
	void ModifyChild(std::tr1::shared_ptr<CElement> pNew)
	{
		m_wndClassView.Modify(pNew);
	}

// 重写
public:
	virtual BOOL PreTranslateMessage(MSG* pMsg);

protected:
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	afx_msg void OnClassAddMemberFunction();
	afx_msg void OnClassAddMemberVariable();
	afx_msg void OnClassDefinition();
	afx_msg void OnClassProperties();
	afx_msg void OnNewFolder();
	afx_msg void OnPaint();
	afx_msg void OnSetFocus(CWnd* pOldWnd);
	afx_msg LRESULT OnChangeActiveTab(WPARAM, LPARAM);
	afx_msg void OnSort(UINT id);
	afx_msg void OnUpdateSort(CCmdUI* pCmdUI);

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnClassExpand();
	void ExpandItem( HTREEITEM hItem,UINT nCode);
	void UpdateRootText(CString str);
	afx_msg void OnClassCollapse();
	afx_msg void OnClassSearch();
	afx_msg void OnClassNext();
	afx_msg void OnExpandSameLevel();
	afx_msg void OnExpandChild();
	afx_msg void OnCollapseSameLevel();
};

