// vListDlg.cpp : implementation file
//

#include "stdafx.h"
#include "vList.h"
#include "vListDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
		// No message handlers
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CVListDlg dialog

CVListDlg::CVListDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CVListDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CVListDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CVListDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CVListDlg)
	DDX_Control(pDX, IDC_STC_LBL, m_STC_LBL);
	DDX_Control(pDX, IDC_Edt_Rows, m_EDT_Rows);
	DDX_Control(pDX, IDC_LST_VALUE, m_LST_Value);
	DDX_Control(pDX, IDC_LIST_LOG, log_list);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CVListDlg, CDialog)
	//{{AFX_MSG_MAP(CVListDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
	ON_NOTIFY(LVN_GETDISPINFO, IDC_LST_VALUE, OnGetdispinfoLSTAnalyse)
	ON_NOTIFY(LVN_GETDISPINFO, IDC_LIST_LOG, OnGetdispinfoLSTAnalyse)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CVListDlg message handlers

BOOL CVListDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	m_EDT_Rows.SetWindowText("5");
	memset(arr, 0x00,sizeof(arr));
	InitLst();
	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CVListDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CVListDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CVListDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CVListDlg::OnOK() 
{
		CString strRows = "";
		m_EDT_Rows.GetWindowText(strRows);
		//AddRows(i++ ,atoi(strRows));
		AddRowsLOG(atoi(strRows));
}


void CVListDlg::InitLst()
{
	int nColIdx = 0;	
	m_LST_Value.SetExtendedStyle(LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);
	m_LST_Value.InsertColumn(nColIdx++, "IDX", LVCFMT_CENTER, 100);
	m_LST_Value.InsertColumn(nColIdx++, "Val_1", LVCFMT_CENTER, 200);
	m_LST_Value.InsertColumn(nColIdx++, "Val_2", LVCFMT_CENTER, 200);
	m_LST_Value.InsertColumn(nColIdx++, "Val_3", LVCFMT_CENTER, 200);	

	nColIdx = 0;
	log_list.SetExtendedStyle(LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);
	log_list.InsertColumn(nColIdx++, "id", LVCFMT_CENTER, 50);
	log_list.InsertColumn(nColIdx++, "内容", LVCFMT_CENTER, 250);
	log_list.InsertColumn(nColIdx++, "级别", LVCFMT_CENTER, 50);
	log_list.InsertColumn(nColIdx++, "结果", LVCFMT_CENTER, 50);
	log_list.InsertColumn(nColIdx++, "时间", LVCFMT_CENTER, 250);
}

void CVListDlg::AddRowsLOG(const DWORD &dwRows)
{
	if (dwRows <= 0)
		return;
	m_aryLstLog.clear();
	//m_aryLstLog.empty();
	//m_aryLstLog.;
	DWORD dwAryTotalCount = 0, dwAryIdx = now;
	dwAryTotalCount = dwRows + dwAryIdx;
	for (; now < dwAryTotalCount; now++)
	{
		MSG msg;
		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
		LST_LOG lstLog;
		lstLog.id = now;
		lstLog.level = 2;
		lstLog.result = now;
		lstLog.time = 1111;
		lstrcpy(lstLog.content, "zing");

		arr[now].id = now;
		arr[now].level = 2;
		arr[now].result = now;
		arr[now].time = 1111;
		lstrcpy(arr[now].content, "zing");
		m_aryLstLog.push_back(lstLog);
	}
	//log_list.SetItemCount(m_aryLstLog.size());
	log_list.SetItemCount(5);
	//log_list.RedrawItems(dwAryIdx, now);
}
void CVListDlg::AddRows(int i,const DWORD &dwRows)
{	   if (dwRows <= 0)
 			return;
 
 		m_STC_LBL.SetWindowText("正在组织数据...");
 		m_aryLstData.clear();
 		DWORD dwAryTotalCount = 0;		
 		DWORD dwAryIdx = 0;
 		for (; dwAryIdx < dwRows; dwAryIdx++)
 		{
 				MSG msg;
 				if(PeekMessage(&msg,NULL,0,0,PM_REMOVE))
 				{
 						TranslateMessage(&msg);
 						DispatchMessage(&msg); 
 				}
 
 				LST_DATA lstData;
 				lstData.dwcolIdx = dwAryIdx;
 				sprintf_s(lstData.chcolValue1, "%d", dwAryIdx);
 				sprintf_s(lstData.chcolValue2, "%d", dwAryIdx);
 				sprintf_s(lstData.chcolValue3, "%d", dwAryIdx);
 
 				m_aryLstData.push_back(lstData);				
 		}
 
 		m_STC_LBL.SetWindowText("组织数据结束");
 		m_LST_Value.SetItemCount(m_aryLstData.size());
 		m_LST_Value.RedrawItems(dwAryIdx, dwAryIdx);
}


void CVListDlg::OnGetdispinfoLSTAnalyse(NMHDR* pNMHDR, LRESULT* pResult) 
{
		LV_DISPINFO* pDispInfo = (LV_DISPINFO*)pNMHDR;	
		LV_ITEM* pItem= &(pDispInfo)->item;
		
		
		if (pItem == NULL)
			return;
		
		CString strTmp = "";
		int iItemIndx= pItem->iItem;
		CString strRows = "";
		m_EDT_Rows.GetWindowText(strRows);
		//if (iItemIndx + 1 >= atoi(strRows) && iItemIndx % atoi(strRows) == atoi(strRows) - 1)
		//log_list.EnsureVisible(iItemIndx,FALSE);
		if (pItem->mask & LVIF_TEXT) //字符串缓冲区有效
		{
				switch(pItem->iSubItem)
				{
				case 0:
				{
					//strTmp.Format("%d", m_aryLstLog[iItemIndx].id);
					strTmp.Format("%d", arr[iItemIndx].id);
					lstrcpy(pItem->pszText, strTmp);
					strTmp = "";
				}
				break;
				case 1:
				{
					strTmp.Format("%s", arr[iItemIndx].content);
					lstrcpy(pItem->pszText, strTmp);
					strTmp = "";
				}
				break;
				case 2:
				{
					strTmp.Format("%d", arr[iItemIndx].level);
					lstrcpy(pItem->pszText, strTmp);
					strTmp = "";
				}
				break;
				case 3:
				{
					strTmp.Format("%d", arr[iItemIndx].result);
					lstrcpy(pItem->pszText, strTmp);
					strTmp = "";
				}
				break; 
				case 4:
				{
					strTmp.Format("%d", arr[iItemIndx].time);
					lstrcpy(pItem->pszText, strTmp);
					strTmp = "";
				}
				break;
					/*
				case 0:
					{
							strTmp.Format("%d", m_aryLstData[iItemIndx].dwcolIdx);
							lstrcpy(pItem->pszText, strTmp);
							strTmp = "";
					}					
					break;
				case 1:
					{
							strTmp.Format("%s", m_aryLstData[iItemIndx].chcolValue1);
							lstrcpy(pItem->pszText, strTmp);
							strTmp = "";
					}					
					break;
				case 2:
					{
							strTmp.Format("%s", m_aryLstData[iItemIndx].chcolValue2);
							lstrcpy(pItem->pszText, strTmp);
							strTmp = "";
					}					
					break;
				case 3:
					{
							strTmp.Format("%s", m_aryLstData[iItemIndx].chcolValue3);
							lstrcpy(pItem->pszText, strTmp);
							strTmp = "";
					}					
					break;
					*/
				}
			
		}
		if (now - 1 == iItemIndx && now % atoi(strRows) == 0)
		{
			AddRowsLOG(atoi(strRows));
		}
		*pResult = 0;
}
