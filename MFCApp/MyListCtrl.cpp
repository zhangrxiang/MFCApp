// MyListCtrl.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "MFCApp.h"
#include "MyListCtrl.h"


// MyListCtrl

IMPLEMENT_DYNAMIC(MyListCtrl, CLinkCtrl)

MyListCtrl::MyListCtrl()
{

}

MyListCtrl::~MyListCtrl()
{
}


BEGIN_MESSAGE_MAP(MyListCtrl, CLinkCtrl)
	ON_WM_VSCROLL()
END_MESSAGE_MAP()



// MyListCtrl ��Ϣ�������




void MyListCtrl::OnVScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ

	CLinkCtrl::OnVScroll(nSBCode, nPos, pScrollBar);
}
