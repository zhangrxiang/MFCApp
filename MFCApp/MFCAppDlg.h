
// MFCAppDlg.h : ͷ�ļ�
//

#pragma once
#include "afxcmn.h"
#include "data.h"

// CMFCAppDlg �Ի���
class CMFCAppDlg : public CDialogEx
{
// ����
public:
	CMFCAppDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MFCAPP_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
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
