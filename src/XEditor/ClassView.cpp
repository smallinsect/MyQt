
#include "stdafx.h"
#include "MainFrm.h"
#include "ClassView.h"
#include "Resource.h"
#include "XEditor.h"

class CClassViewMenuButton : public CMFCToolBarMenuButton
{
	friend class CClassView;

	DECLARE_SERIAL(CClassViewMenuButton)

public:
	CClassViewMenuButton(HMENU hMenu = NULL) : CMFCToolBarMenuButton((UINT)-1, hMenu, -1)
	{
	}

	virtual void OnDraw(CDC* pDC, const CRect& rect, CMFCToolBarImages* pImages, BOOL bHorz = TRUE,
		BOOL bCustomizeMode = FALSE, BOOL bHighlight = FALSE, BOOL bDrawBorder = TRUE, BOOL bGrayDisabledButtons = TRUE)
	{
		pImages = CMFCToolBar::GetImages();

		CAfxDrawState ds;
		pImages->PrepareDrawImage(ds);

		CMFCToolBarMenuButton::OnDraw(pDC, rect, pImages, bHorz, bCustomizeMode, bHighlight, bDrawBorder, bGrayDisabledButtons);

		pImages->EndDrawImage(ds);
	}
};

IMPLEMENT_SERIAL(CClassViewMenuButton, CMFCToolBarMenuButton, 1)

//键盘HOOK用于入下载查找输入回车
HHOOK g_HookKeyPad = NULL;
HWND  g_hClassEdit= NULL;
HWND  g_hClassWnd = NULL;
LRESULT CALLBACK KeyPadProc( INT nCode, WPARAM wParam, LPARAM lParam ){
	if( g_hClassEdit == ::GetFocus() && lParam & 0x80000000 ){
		if( VK_RETURN == wParam )::SendMessage(g_hClassWnd,WM_COMMAND,ID_CLASS_RESEARCH,0 );
		if( VK_DOWN  == wParam ) ::SendMessage(g_hClassWnd,WM_COMMAND,ID_CLASS_NEXT, 0 );
	}
	return CallNextHookEx(g_HookKeyPad,nCode,wParam,lParam);
}

//////////////////////////////////////////////////////////////////////
// 构造/析构
//////////////////////////////////////////////////////////////////////

CClassView::CClassView()
{
	m_nCurrSort = ID_SORTING_GROUPBYTYPE;
}

CClassView::~CClassView()
{
	if(g_HookKeyPad)
		UnhookWindowsHookEx(g_HookKeyPad); 
}

void CClassView::SetCurrentElement(std::tr1::shared_ptr<CElement> pElement)
{
	if (pElement->GetChildType() != "")
		m_wndClassView.SetCurrentElement(pElement);
}

BEGIN_MESSAGE_MAP(CClassView, CDockablePane)
	ON_WM_CREATE()
	ON_WM_SIZE()
	ON_WM_CONTEXTMENU()
	ON_COMMAND(ID_CLASS_ADD_MEMBER_FUNCTION, OnClassAddMemberFunction)
	ON_COMMAND(ID_CLASS_ADD_MEMBER_VARIABLE, OnClassAddMemberVariable)
	ON_COMMAND(ID_CLASS_DEFINITION, OnClassDefinition)
	ON_COMMAND(ID_CLASS_PROPERTIES, OnClassProperties)
	ON_COMMAND(ID_NEW_FOLDER, OnNewFolder)
	ON_WM_PAINT()
	ON_WM_SETFOCUS()
	ON_COMMAND_RANGE(ID_SORTING_GROUPBYTYPE, ID_SORTING_SORTBYACCESS, OnSort)
	ON_UPDATE_COMMAND_UI_RANGE(ID_SORTING_GROUPBYTYPE, ID_SORTING_SORTBYACCESS, OnUpdateSort)
	ON_WM_LBUTTONUP()
	ON_COMMAND(ID_CLASS_EXPAND, &CClassView::OnClassExpand)
	ON_COMMAND(ID_CLASS_COLLAPSE, &CClassView::OnClassCollapse)
	ON_COMMAND(ID_CLASS_RESEARCH, &CClassView::OnClassSearch)
	ON_COMMAND(ID_CLASS_NEXT, &CClassView::OnClassNext)
	ON_COMMAND(ID_EXPAND_SAMELEVEL, &CClassView::OnExpandSameLevel)
	ON_COMMAND(ID_COLLAPSE_SAMELEVEL, &CClassView::OnCollapseSameLevel)
	ON_COMMAND(ID_EXPAND_CHILD,&CClassView::OnExpandChild)
	ON_COMMAND(ID_COLLAPSE_CHILD,&CClassView::OnExpandChild)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CClassView 消息处理程序

int CClassView::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CDockablePane::OnCreate(lpCreateStruct) == -1)
		return -1;

	CRect rectDummy;
	rectDummy.SetRectEmpty();

	// 创建视图:
	const DWORD dwViewStyle = WS_CHILD|WS_VISIBLE|TVS_LINESATROOT|TVS_HASBUTTONS|TVS_SHOWSELALWAYS|TVS_TRACKSELECT|TVS_FULLROWSELECT| TVS_HASLINES;
		//WS_CHILD | WS_VISIBLE | TVS_HASLINES | TVS_LINESATROOT | TVS_HASBUTTONS | WS_CLIPSIBLINGS | WS_CLIPCHILDREN;

	if (!m_wndClassView.Create(dwViewStyle, rectDummy, this, 2))
	{
		TRACE0("未能创建类视图\n");
		return -1;      // 未能创建
	}

	// 加载图像:
	m_wndToolBar.Create(this, AFX_DEFAULT_TOOLBAR_STYLE, IDR_SORT);
	m_wndToolBar.LoadToolBar(IDR_SORT, 0, 0, TRUE /* 已锁定*/);

	OnChangeVisualStyle();

	m_wndToolBar.SetPaneStyle(m_wndToolBar.GetPaneStyle() | CBRS_TOOLTIPS | CBRS_FLYBY);
	m_wndToolBar.SetPaneStyle(m_wndToolBar.GetPaneStyle() & ~(CBRS_GRIPPER | CBRS_SIZE_DYNAMIC | CBRS_BORDER_TOP | CBRS_BORDER_BOTTOM | CBRS_BORDER_LEFT | CBRS_BORDER_RIGHT));

	m_wndToolBar.SetOwner(this);

	// 所有命令将通过此控件路由，而不是通过主框架路由:
	m_wndToolBar.SetRouteCommandsViaFrame(FALSE);

	//CMFCToolBarEditBoxButton boxButton;//这里我用默认构造函数
	//boxButton.m_bText=TRUE;
	//boxButton.CanBeStretched();
	//boxButton.SetRect(CRect(1, 1, 100, 24));//这里设置了Rect,但大小并没有改变
	//boxButton.SetFlatMode(true);
	//boxButton.SetStyle(TBBS_PRESSED);
	////m_wndToolBar.InsertButton(boxButton, 0);
	//m_wndToolBar.ReplaceButton(ID_SORT_MENU,boxButton);

	//RECT rect;
	//SetRect( &rect,0,2,50,20);
	//if(m_static.Create(_T("关键字:"),WS_CHILD|WS_VISIBLE,rect,&m_wndToolBar,ID_SORT_MENU))	{
	//	static CFont font;
	//	font.CreateFont(12, 0, 0, 0, 100, FALSE, FALSE,	0,
	//		GB2312_CHARSET , 
	//		OUT_DEFAULT_PRECIS,
	//		CLIP_DEFAULT_PRECIS,
	//		DEFAULT_QUALITY,	               
	//		VARIABLE_PITCH | FF_SCRIPT, "楷体_GB2312");	
	//	m_static.SetFont( &font );
	//	m_static.ShowWindow(SW_SHOW);
	//}

	//添加查找文本输入框
	CMFCToolBarButton txtButton(ID_SORT_MENU,-1,_T("关键字:"));
	m_wndToolBar.ReplaceButton(ID_SORT_MENU,txtButton);

	//添加查找文本输入框
	CMFCToolBarEditBoxButton editButton(ID_CLASS_EDIT,0, ES_WANTRETURN,120);
	editButton.m_bText = TRUE;
	editButton.SetStyle(TBBS_DISABLED|TBBS_AUTOSIZE);
	int nIndex = m_wndToolBar.ReplaceButton(ID_CLASS_EDIT, editButton);

	//用HOOK来处理
	g_HookKeyPad = SetWindowsHook(WH_KEYBOARD,KeyPadProc);
	g_hClassEdit = m_wndToolBar.GetButton(nIndex)->GetHwnd();
	g_hClassWnd  = this->GetSafeHwnd();

	//CMenu menuSort;
	//menuSort.LoadMenu(IDR_POPUP_SORT);
	//m_wndToolBar.ReplaceButton(ID_SORT_MENU, CClassViewMenuButton(menuSort.GetSubMenu(0)->GetSafeHmenu()));
	//CClassViewMenuButton* pButton =  DYNAMIC_DOWNCAST(CClassViewMenuButton, m_wndToolBar.GetButton(0));
	//if (pButton != NULL)
	//{
	//	pButton->m_bText = FALSE;
	//	pButton->m_bImage = TRUE;
	//	pButton->SetImage(GetCmdMgr()->GetCmdImage(m_nCurrSort));
	//	pButton->SetMessageWnd(this);
	//}
	// 填入一些静态树视图数据(此处只需填入虚拟代码，而不是复杂的数据)
	FillClassView();

	return 0;
}

void CClassView::OnSize(UINT nType, int cx, int cy)
{
	CDockablePane::OnSize(nType, cx, cy);
	AdjustLayout();
}


void CClassView::FillClassView()
{
	if (std::tr1::shared_ptr<CElement> pElement = CElementMgr::GetRoot())
		m_wndClassView.InsertChildren(pElement, TVI_ROOT);
}

void CClassView::UpdateRootText( CString str )
{
	HTREEITEM hRoot = m_wndClassView.GetRootItem();
	CString strCaption = m_wndClassView.GetItemText( hRoot );
	strCaption.Format("%s - %s", strCaption, str);
	m_wndClassView.SetItemText(hRoot, strCaption );
}

void CClassView::ClearClassView()
{
	if( std::tr1::shared_ptr<CElement> pElement = CElementMgr::GetRoot() )
		m_wndClassView.Delete( pElement );
	m_wndClassView.DeleteAllItems();
	//m_wndClassView.DeleteItem(TVI_ROOT);
}

void CClassView::OnContextMenu(CWnd* pWnd, CPoint point)
{
	CTreeCtrl* pWndTree = (CTreeCtrl*)&m_wndClassView;
	ASSERT_VALID(pWndTree);

	if (pWnd != pWndTree)
	{
		CDockablePane::OnContextMenu(pWnd, point);
		return;
	}

	//if (point != CPoint(-1, -1))
	//{
	//	// 选择已单击的项:
	//	CPoint ptTree = point;
	//	pWndTree->ScreenToClient(&ptTree);

	//	UINT flags = 0;
	//	HTREEITEM hTreeItem = pWndTree->HitTest(ptTree, &flags);
	//	if (hTreeItem != NULL)
	//	{
	//		pWndTree->SelectItem(hTreeItem);
	//	}
	//}

	pWndTree->SetFocus();
	//CMenu menu;
	//menu.LoadMenu(IDR_POPUP_EDIT);

	//CMenu* pSumMenu = menu.GetSubMenu(0);

	////if (AfxGetMainWnd()->IsKindOf(RUNTIME_CLASS(CMDIFrameWndEx)))
	//{
	//	CMFCPopupMenu* pPopupMenu = new CMFCPopupMenu;

	//	if (!pPopupMenu->Create(this, point.x, point.y, (HMENU)pSumMenu->m_hMenu, FALSE, TRUE))
	//		return;

	//	((CMDIFrameWndEx*)AfxGetMainWnd())->OnShowPopupMenu(pPopupMenu);
	//	UpdateDialogControls(this, FALSE);
	//}

	CPoint pt(point);
	pWndTree->ScreenToClient(&pt);
	UINT flags = 0;
	HTREEITEM hItem = pWndTree->HitTest(pt, &flags);
	if( hItem == NULL)
		return;
	pWndTree->SelectItem(hItem);
	if(pWndTree->GetParentItem (hItem) == NULL)
		return;
	UINT nState = pWndTree->GetItemState( hItem, TVIS_STATEIMAGEMASK );
	BOOL bChild = pWndTree->ItemHasChildren(hItem);
	CMenu m_menu;
	m_menu.LoadMenu(IDR_POPU_CLASS);
	m_menu.EnableMenuItem(ID_EXPAND_CHILD,MF_BYCOMMAND | (nState&TVIS_EXPANDED || !bChild)?MF_DISABLED:MF_ENABLED);
	m_menu.EnableMenuItem(ID_COLLAPSE_CHILD,MF_BYCOMMAND | (nState&TVIS_EXPANDED)?MF_ENABLED:MF_DISABLED);
	m_menu.GetSubMenu(0)->TrackPopupMenu( TPM_LEFTBUTTON|TPM_RIGHTBUTTON,point.x, point.y, this);
}

void CClassView::AdjustLayout()
{
	if (GetSafeHwnd() == NULL)
	{
		return;
	}

	CRect rectClient;
	GetClientRect(rectClient);

	int cyTlb = m_wndToolBar.CalcFixedLayout(FALSE, TRUE).cy;

	m_wndToolBar.SetWindowPos(NULL, rectClient.left, rectClient.top, rectClient.Width(), cyTlb, SWP_NOACTIVATE | SWP_NOZORDER);
	m_wndClassView.SetWindowPos(NULL, rectClient.left + 1, rectClient.top + cyTlb + 1, rectClient.Width() - 2, rectClient.Height() - cyTlb - 2, SWP_NOACTIVATE | SWP_NOZORDER);
}

BOOL CClassView::PreTranslateMessage(MSG* pMsg)
{
	return CDockablePane::PreTranslateMessage(pMsg);
}

void CClassView::OnSort(UINT id)
{
	if (m_nCurrSort == id)
	{
		return;
	}
	m_nCurrSort = id;

	CClassViewMenuButton* pButton =  DYNAMIC_DOWNCAST(CClassViewMenuButton, m_wndToolBar.GetButton(0));

	if (pButton != NULL)
	{
		pButton->SetImage(GetCmdMgr()->GetCmdImage(id));
		m_wndToolBar.Invalidate();
		m_wndToolBar.UpdateWindow();
	}
}

void CClassView::OnUpdateSort(CCmdUI* pCmdUI)
{
	pCmdUI->SetCheck(pCmdUI->m_nID == m_nCurrSort);
}

void CClassView::OnClassAddMemberFunction()
{
	AfxMessageBox(_T("添加成员函数..."));
}

void CClassView::OnClassAddMemberVariable()
{
	// TODO: 在此处添加命令处理程序代码
}

void CClassView::OnClassDefinition()
{
	// TODO: 在此处添加命令处理程序代码
}

void CClassView::OnClassProperties()
{
	// TODO: 在此处添加命令处理程序代码
}

void CClassView::OnNewFolder()
{
	AfxMessageBox(_T("新建文件夹..."));
}

void CClassView::OnPaint()
{
	CPaintDC dc(this); // 用于绘制的设备上下文

	CRect rectTree;
	m_wndClassView.GetWindowRect(rectTree);
	ScreenToClient(rectTree);

	rectTree.InflateRect(1, 1);
	dc.Draw3dRect(rectTree, ::GetSysColor(COLOR_3DSHADOW), ::GetSysColor(COLOR_3DSHADOW));
}

void CClassView::OnSetFocus(CWnd* pOldWnd)
{
	CDockablePane::OnSetFocus(pOldWnd);

	m_wndClassView.SetFocus();
}

void CClassView::OnChangeVisualStyle()
{
	m_ClassViewImages.DeleteImageList();

	UINT uiBmpId = theApp.m_bHiColorIcons ? IDB_CLASS_VIEW_24 : IDB_CLASS_VIEW;

	CBitmap bmp;
	if (!bmp.LoadBitmap(uiBmpId))
	{
		TRACE(_T("无法加载位图: %x\n"), uiBmpId);
		ASSERT(FALSE);
		return;
	}

	BITMAP bmpObj;
	bmp.GetBitmap(&bmpObj);

	UINT nFlags = ILC_MASK;

	nFlags |= (theApp.m_bHiColorIcons) ? ILC_COLOR24 : ILC_COLOR4;

	m_ClassViewImages.Create(16, bmpObj.bmHeight, nFlags, 0, 0);
	m_ClassViewImages.Add(&bmp, RGB(255, 0, 0));

	m_wndClassView.SetImageList(&m_ClassViewImages, TVSIL_NORMAL);

	m_wndToolBar.CleanUpLockedImages();
	m_wndToolBar.LoadBitmap(theApp.m_bHiColorIcons ? IDB_SORT_24 : IDR_SORT, 0, 0, TRUE /* 锁定*/);
}


void CClassView::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值

	CDockablePane::OnLButtonUp(nFlags, point);
}


void CClassView::OnClassExpand()
{
	HTREEITEM hRoot = m_wndClassView.GetRootItem();
	m_wndClassView.Expand( hRoot, TVE_EXPAND);
	HTREEITEM h = m_wndClassView.GetChildItem( hRoot );
	ExpandItem( h,TVE_EXPAND );
}

void CClassView::ExpandItem( HTREEITEM hItem, UINT nCode )
{
	if( m_wndClassView.Expand( hItem, nCode ) ){
		HTREEITEM hChild = m_wndClassView.GetChildItem(hItem);
		if( hChild )
			ExpandItem( hChild , nCode);
	}
	HTREEITEM hI = m_wndClassView.GetNextSiblingItem( hItem );
	if ( hI ) ExpandItem( hI , nCode);
}
void CClassView::OnClassCollapse()
{
	HTREEITEM hRoot = m_wndClassView.GetRootItem();
	m_wndClassView.Expand( hRoot, TVE_EXPAND);
	HTREEITEM h = m_wndClassView.GetChildItem( hRoot );
	ExpandItem( h, TVE_COLLAPSE );
	m_wndClassView.SelectItem(hRoot);
}

//查找操作
void CClassView::OnClassSearch()
{
	CMFCToolBarEditBoxButton * pSrcCombo = (CMFCToolBarEditBoxButton*)m_wndToolBar.GetButton( 2 );
	CString strText = pSrcCombo->GetContentsAll(ID_CLASS_EDIT);
	if( strText.GetLength() > 0 )
		OnClassCollapse();
	m_wndClassView.SearchByKey( strText );
}
//
void CClassView::OnClassNext()
{
	m_wndClassView.SearchPointToNext();
}

void CClassView::OnExpandSameLevel()
{
	HTREEITEM hItem = m_wndClassView.GetSelectedItem();
	if( hItem==NULL )
		return;
	m_wndClassView.ExpandOnSameLevel( hItem,TVE_EXPAND );
}

void CClassView::OnCollapseSameLevel()
{
	HTREEITEM hItem = m_wndClassView.GetSelectedItem();
	if( hItem==NULL )
		return;
	m_wndClassView.ExpandOnSameLevel( hItem, TVE_COLLAPSE );
}

void CClassView::OnExpandChild()
{
	HTREEITEM hItem = m_wndClassView.GetSelectedItem();
	if( hItem==NULL )
		return;
	m_wndClassView.Expand( hItem,(m_wndClassView.GetItemState( hItem, TVIS_STATEIMAGEMASK )& TVIS_EXPANDED)?TVE_COLLAPSE:TVE_EXPAND );
}

