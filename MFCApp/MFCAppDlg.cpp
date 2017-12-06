
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
	//ON_NOTIFY(ON_WM_VSCROLL, IDC_LIST_STU, &CMFCAppDlg::OnNMRclkListStu)
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

	int length = 200, i = 0;
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
	//设置扩展风格  

	//m_list_stu.SetExtendedStyle(LVS_SHOWSELALWAYS | LVS_EX_CHECKBOXES | LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);
	//设置背景颜色  
	m_list_stu.SetBkColor(RGB(200, 200, 255));
	//设置第一行为选中状态  
	m_list_stu.SetItemState(0, LVIS_SELECTED | LVIS_FOCUSED, LVIS_SELECTED | LVIS_FOCUSED);
#pragma   comment(lib, "Version.lib ")
	GetVerInfo();
	//CString modFilename;
	//if (GetModuleFileName(AfxGetInstanceHandle(), modFilename.GetBuffer(MAX_PATH), MAX_PATH) > 0)
	//{
	//	modFilename.ReleaseBuffer(MAX_PATH);
	//	DWORD dwHandle = 0;
	//	DWORD dwSize = GetFileVersionInfoSize(modFilename.GetBuffer(MAX_PATH), &dwHandle);
	//	if (dwSize > 0)
	//	{
	//		LPBYTE lpInfo = new BYTE[dwSize];
	//		ZeroMemory(lpInfo, dwSize);
	//		if (GetFileVersionInfo(modFilename.GetBuffer(MAX_PATH), 0, dwSize, lpInfo))
	//		{
	//			//// This will extract so called FIXED portion of the version info   
	//			UINT valLen = MAX_PATH;
	//			LPVOID valPtr = NULL;
	//			if (VerQueryValue(lpInfo, TEXT("\\"), &valPtr, &valLen))
	//			{
	//				VS_FIXEDFILEINFO* pFinfo = (VS_FIXEDFILEINFO*)valPtr;
	//				// convert to text   
	//				CString valStr;
	//				valStr.Format(_T("%d.%d.%d.%d"),
	//					(pFinfo->dwFileVersionMS >> 16) & 0xFF,
	//					(pFinfo->dwFileVersionMS) & 0xFF,
	//					(pFinfo->dwFileVersionLS >> 16) & 0xFF,
	//					(pFinfo->dwFileVersionLS) & 0xFF
	//				);
	//				AfxMessageBox(valStr);
	//			}
	//		}
	//		delete[] lpInfo;
	//	}
	//}
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
	while (m_list_stu.GetNextItem(-1, LVNI_ALL | LVNI_SELECTED) != -1)
	{
		int nItem = m_list_stu.GetNextItem(-1, LVNI_ALL | LVNI_SELECTED);
		m_list_stu.DeleteItem(nItem);
	}
}

BOOL CMFCAppDlg::GetVerInfo()
{
	//取得版本信息
#pragma   comment(lib, "Version.lib ")

	char FileVerInfo[4096];
	char string[200];
	DWORD dwVerLen = 0;
	CString szExeName;
	GetModuleFileName(NULL, szExeName.GetBufferSetLength(MAX_PATH + 1), MAX_PATH);
	szExeName.ReleaseBuffer();
	int m_len = GetFileVersionInfoSize(szExeName, &dwVerLen);
	if (!m_len)//找指定文件的版本信息这里是"Server.exe"，也可以是应用程序自己的名字
	{
		MessageBox(NULL, "无法找到指定文件", MB_OK | MB_ICONSTOP);
		return FALSE;
	}
	BOOL m_bFile = GetFileVersionInfo(szExeName, NULL, m_len, FileVerInfo);
	// Read the list of languages and code pages.
	//	LPTSTR lpSubBlock;   // value to retrieve
	//	LPVOID *lplpBuffer;  // buffer for version value pointer
	//	PUINT puLen ;  // version length
	UINT cbTranslate;
	char SubBlock[4096];
	UINT dwBytes;
	struct LANGANDCODEPAGE {
		WORD wLanguage;
		WORD wCodePage;
	} *lpTranslate;
	struct version {
		char * strProductName;
		char * strProductVersion;
		char * strLegalCopyright;
		char * strCompanyName;
		char * strSpecialBuild;
	} ver;
	VerQueryValue(FileVerInfo,
		TEXT("\\VarFileInfo\\Translation"),
		(LPVOID*)&lpTranslate,
		&cbTranslate);
	// Read the file description for each language and code page.
	for (int i = 0; i < (cbTranslate / sizeof(struct LANGANDCODEPAGE)); i++)
	{
		wsprintf(SubBlock,
			TEXT("\\StringFileInfo\\%04x%04x\\ProductName"),
			lpTranslate[i].wLanguage,
			lpTranslate[i].wCodePage);
		// Retrieve file description for language and code page "i". 
		VerQueryValue(string,
			SubBlock,
			(void **)&ver.strProductName,
			&dwBytes);

		wsprintf(SubBlock,
			TEXT("\\StringFileInfo\\%04x%04x\\ProductVersion"),
			lpTranslate[i].wLanguage,
			lpTranslate[i].wCodePage);

		// Retrieve file description for language and code page "i". 
		VerQueryValue(FileVerInfo,
			SubBlock,
			(void **)&ver.strProductVersion,
			&dwBytes);
		wsprintf(SubBlock,
			TEXT("\\StringFileInfo\\%04x%04x\\LegalCopyright"),
			lpTranslate[i].wLanguage,
			lpTranslate[i].wCodePage);

		// Retrieve file description for language and code page "i". 
		VerQueryValue(FileVerInfo,
			SubBlock,
			(void **)&ver.strLegalCopyright,
			&dwBytes);
		wsprintf(SubBlock,
			TEXT("\\StringFileInfo\\%04x%04x\\CompanyName"),
			lpTranslate[i].wLanguage,
			lpTranslate[i].wCodePage);

		// Retrieve file description for language and code page "i". 
		VerQueryValue(FileVerInfo,
			SubBlock,
			(void **)&ver.strCompanyName,
			&dwBytes);
		wsprintf(SubBlock,
			TEXT("\\StringFileInfo\\%04x%04x\\SpecialBuild"),
			lpTranslate[i].wLanguage,
			lpTranslate[i].wCodePage);

		// Retrieve file description for language and code page "i". 
		VerQueryValue(FileVerInfo,
			SubBlock,
			(void **)&ver.strSpecialBuild,
			&dwBytes);
	}
	AfxMessageBox(ver.strCompanyName);
	return TRUE;
}