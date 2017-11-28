// vListDlg.h : header file
//

#if !defined(AFX_VLISTDLG_H__2CE4BF01_74CB_4805_A5A3_15E6CD2B9A4E__INCLUDED_)
#define AFX_VLISTDLG_H__2CE4BF01_74CB_4805_A5A3_15E6CD2B9A4E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <vector>
#include "afxcmn.h"

/////////////////////////////////////////////////////////////////////////////
// CVListDlg dialog
typedef struct _LST_DATA_ 
{
		DWORD dwcolIdx;
		char chcolValue1[10];
		char chcolValue2[10];
		char chcolValue3[10];

		_LST_DATA_()
		{
				ZeroMemory(this, sizeof(*this));
		}
}LST_DATA, *LPLST_DATA;


typedef struct _LST_LOG_
{
	int id;
	int level;
	int result;
	int time;
    char content[64];

	_LST_LOG_()
	{
		ZeroMemory(this, sizeof(*this));
	}
}LST_LOG, *LPLST_LOG;
typedef std::vector<LST_DATA>	ARY_LST;
typedef std::vector<LST_LOG>	ARY_LST_LOG;


class CVListDlg : public CDialog
{
// Construction
public:
	CVListDlg(CWnd* pParent = NULL);	// standard constructor

	void InitLst();

	void AddRows(int i,const DWORD &dwRows = 0);
	void CVListDlg::AddRowsLOG(int i, const DWORD &dwRows);


private:
	ARY_LST m_aryLstData;
	ARY_LST_LOG m_aryLstLog;

// Dialog Data
	//{{AFX_DATA(CVListDlg)
	enum { 
		IDD = IDD_VLIST_DIALOG ,
	};
	CStatic	m_STC_LBL;
	CEdit	m_EDT_Rows;
	CListCtrl	m_LST_Value;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CVListDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;
	int i = 0;
	DWORD  dwAryIdx = 0;
	// Generated message map functions
	//{{AFX_MSG(CVListDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	virtual void OnOK();
	//}}AFX_MSG
	afx_msg void OnGetdispinfoLSTAnalyse(NMHDR* pNMHDR, LRESULT* pResult);
	DECLARE_MESSAGE_MAP()
public:
	CListCtrl log_list;
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_VLISTDLG_H__2CE4BF01_74CB_4805_A5A3_15E6CD2B9A4E__INCLUDED_)
