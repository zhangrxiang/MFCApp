// MyListCtrl.cpp : 实现文件
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



// MyListCtrl 消息处理程序




void MyListCtrl::OnVScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值

	CLinkCtrl::OnVScroll(nSBCode, nPos, pScrollBar);
}
