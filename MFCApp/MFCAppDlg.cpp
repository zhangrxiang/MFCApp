
// MFCAppDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "MFCApp.h"
#include "MFCAppDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CMFCAppDlg 对话框



CMFCAppDlg::CMFCAppDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_MFCAPP_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFCAppDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST_STU, m_list_stu);
}

BEGIN_MESSAGE_MAP(CMFCAppDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_NOTIFY(NM_RCLICK, IDC_LIST_STU, &CMFCAppDlg::OnNMRclkListStu)
	ON_COMMAND(ID_MENU_DEL, &CMFCAppDlg::OnMenuDel)
END_MESSAGE_MAP()


// CMFCAppDlg 消息处理程序

BOOL CMFCAppDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码

	m_list_stu.InsertColumn(0, _T("ID"), LVCFMT_CENTER, 50);
	m_list_stu.InsertColumn(1, _T("name"), LVCFMT_CENTER, 100);
	m_list_stu.InsertColumn(2, _T("age"), LVCFMT_CENTER, 150);
	m_list_stu.InsertColumn(3, _T("address"), LVCFMT_CENTER, 150);
	//m_list_stu.InsertColumn(5, _T("时间"), LVCFMT_CENTER, 200);
	DWORD style = m_list_stu.GetExtendedStyle();
	style |= LVS_EX_FULLROWSELECT;   //选择条
	style |= LVS_EX_GRIDLINES;       //画线
	m_list_stu.SetExtendedStyle(style);

	int length = 10, i = 0;
	for (i = 0; i < length; i++)
	{
		student[i].id = i;
		memcpy(student[i].name, TEXT("zing"), strlen(TEXT("zing")));
		student[i].age = 10 + i;
		memcpy(student[i].address, LPCSTR("哈哈"), strlen(LPCSTR("哈哈")));
	}
	char str_id[10] = "",str_age[10];
	for ( i = 0; i < length; i++)
	{
		_itoa_s(student[i].id, str_id, 10);
		_itoa_s(student[i].age, str_age, 10);
		m_list_stu.InsertItem(i, LPCSTR("4"));
		m_list_stu.SetItemText(i, 0, LPCSTR(str_id));
		m_list_stu.SetItemText(i, 1, (LPCSTR)(student[i].name));
		m_list_stu.SetItemText(i, 2, (LPCSTR)str_age);
		m_list_stu.SetItemText(i, 3, (LPCSTR)(student[i].address));
	}

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CMFCAppDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CMFCAppDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CMFCAppDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}




void CMFCAppDlg::OnNMRclkListStu(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);
	// TODO: 在此添加控件通知处理程序代码
	//防止在空白区点击弹出菜单  
	//AfxMessageBox("fuck");
	
	if (m_list_stu.GetSelectedCount() <= 0)
	{
		return;
	}
	//下面的这段代码, 不单单适应于ListCtrl  
	/*
	CMenu menu, *pPopup;
	menu.LoadMenu(IDR_R_MENU);
	pPopup = menu.GetSubMenu(0);
	CPoint myPoint;
	ClientToScreen(&myPoint);
	GetCursorPos(&myPoint); //鼠标位置  
	pPopup->TrackPopupMenu(TPM_LEFTALIGN | TPM_RIGHTBUTTON, myPoint.x, myPoint.y, GetParent());
	pPopup->Detach();
	*/
	
	DWORD dwPos = GetMessagePos();
	CPoint Point(LOWORD(dwPos), HIWORD(dwPos));
	CMenu menu, *Popup;
	menu.LoadMenu(IDR_R_MENU);  //你要弹的菜单ID
	Popup = menu.GetSubMenu(0);
	ASSERT(Popup != NULL);
	if (-1 == pNMItemActivate->iItem)
	{
		Popup->EnableMenuItem(0, MF_BYPOSITION | MF_GRAYED);
		Popup->EnableMenuItem(2, MF_BYPOSITION | MF_GRAYED);
	}
	//CListCtrlEx* list = dynamic_cast<CListCtrlEx*>(GetDlgItem(pNMItemActivate->hdr.idFrom));
	Popup->TrackPopupMenu(TPM_CENTERALIGN | TPM_RIGHTBUTTON, Point.x, Point.y, this);
	Popup->Detach();

	*pResult = 0;
}


void CMFCAppDlg::OnMenuDel()
{
	// TODO: 在此添加命令处理程序代码

}
