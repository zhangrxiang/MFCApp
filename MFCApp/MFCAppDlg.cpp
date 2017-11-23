
// MFCAppDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "MFCApp.h"
#include "MFCAppDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
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


// CMFCAppDlg �Ի���



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


// CMFCAppDlg ��Ϣ�������

BOOL CMFCAppDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ��������...���˵�����ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
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

	// ���ô˶Ի����ͼ�ꡣ  ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������

	m_list_stu.InsertColumn(0, _T("ID"), LVCFMT_CENTER, 50);
	m_list_stu.InsertColumn(1, _T("name"), LVCFMT_CENTER, 100);
	m_list_stu.InsertColumn(2, _T("age"), LVCFMT_CENTER, 150);
	m_list_stu.InsertColumn(3, _T("address"), LVCFMT_CENTER, 150);
	//m_list_stu.InsertColumn(5, _T("ʱ��"), LVCFMT_CENTER, 200);
	DWORD style = m_list_stu.GetExtendedStyle();
	style |= LVS_EX_FULLROWSELECT;   //ѡ����
	style |= LVS_EX_GRIDLINES;       //����
	m_list_stu.SetExtendedStyle(style);

	int length = 10, i = 0;
	for (i = 0; i < length; i++)
	{
		student[i].id = i;
		memcpy(student[i].name, TEXT("zing"), strlen(TEXT("zing")));
		student[i].age = 10 + i;
		memcpy(student[i].address, LPCSTR("����"), strlen(LPCSTR("����")));
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

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
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

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ  ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CMFCAppDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CMFCAppDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}




void CMFCAppDlg::OnNMRclkListStu(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	//��ֹ�ڿհ�����������˵�  
	//AfxMessageBox("fuck");
	
	if (m_list_stu.GetSelectedCount() <= 0)
	{
		return;
	}
	//�������δ���, ��������Ӧ��ListCtrl  
	/*
	CMenu menu, *pPopup;
	menu.LoadMenu(IDR_R_MENU);
	pPopup = menu.GetSubMenu(0);
	CPoint myPoint;
	ClientToScreen(&myPoint);
	GetCursorPos(&myPoint); //���λ��  
	pPopup->TrackPopupMenu(TPM_LEFTALIGN | TPM_RIGHTBUTTON, myPoint.x, myPoint.y, GetParent());
	pPopup->Detach();
	*/
	
	DWORD dwPos = GetMessagePos();
	CPoint Point(LOWORD(dwPos), HIWORD(dwPos));
	CMenu menu, *Popup;
	menu.LoadMenu(IDR_R_MENU);  //��Ҫ���Ĳ˵�ID
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
	// TODO: �ڴ���������������

}
