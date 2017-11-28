
// MFCAppDlg.h : 头文件
//

#pragma once
#include "afxcmn.h"
#include "data.h"

// CMFCAppDlg 对话框
class CMFCAppDlg : public CDialogEx
{
// 构造
public:
	CMFCAppDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MFCAPP_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	CListCtrl m_list_stu;
    Student student[200];
	afx_msg void OnNMRclkListStu(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnMenuDel();
//	afx_msg void OnLvnEndScrollListStu(NMHDR *pNMHDR, LRESULT *pResult);
};
