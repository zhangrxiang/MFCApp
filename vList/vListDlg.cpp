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
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CVListDlg, CDialog)
	//{{AFX_MSG_MAP(CVListDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
	ON_NOTIFY(LVN_GETDISPINFO, IDC_LST_VALUE, OnGetdispinfoLSTAnalyse)
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
		
		AddRows(atoi(strRows));
}


void CVListDlg::InitLst()
{
	int nColIdx = 0;	
	m_LST_Value.SetExtendedStyle(LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);
	m_LST_Value.InsertColumn(nColIdx++, "IDX", LVCFMT_CENTER, 100);
	m_LST_Value.InsertColumn(nColIdx++, "Val_1", LVCFMT_CENTER, 200);
	m_LST_Value.InsertColumn(nColIdx++, "Val_2", LVCFMT_CENTER, 200);
	m_LST_Value.InsertColumn(nColIdx++, "Val_3", LVCFMT_CENTER, 200);		
}

void CVListDlg::AddRows(const DWORD &dwRows)
{
		if (dwRows <= 0)
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
		if (pItem->mask & LVIF_TEXT) //字符串缓冲区有效
		{
			
				switch(pItem->iSubItem)
				{
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
				}
		}
		
		*pResult = 0;
}
