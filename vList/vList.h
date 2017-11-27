// vList.h : main header file for the VLIST application
//

#if !defined(AFX_VLIST_H__04ED42B2_4897_47AF_8B85_D7DD1791BE90__INCLUDED_)
#define AFX_VLIST_H__04ED42B2_4897_47AF_8B85_D7DD1791BE90__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CVListApp:
// See vList.cpp for the implementation of this class
//

class CVListApp : public CWinApp
{
public:
	CVListApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CVListApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CVListApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_VLIST_H__04ED42B2_4897_47AF_8B85_D7DD1791BE90__INCLUDED_)
