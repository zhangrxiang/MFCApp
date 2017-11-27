; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CVListDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "vList.h"

ClassCount=3
Class1=CVListApp
Class2=CVListDlg
Class3=CAboutDlg

ResourceCount=3
Resource1=IDD_ABOUTBOX
Resource2=IDR_MAINFRAME
Resource3=IDD_VLIST_DIALOG

[CLS:CVListApp]
Type=0
HeaderFile=vList.h
ImplementationFile=vList.cpp
Filter=N

[CLS:CVListDlg]
Type=0
HeaderFile=vListDlg.h
ImplementationFile=vListDlg.cpp
Filter=D
BaseClass=CDialog
VirtualFilter=dWC
LastObject=CVListDlg

[CLS:CAboutDlg]
Type=0
HeaderFile=vListDlg.h
ImplementationFile=vListDlg.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_VLIST_DIALOG]
Type=1
Class=CVListDlg
ControlCount=4
Control1=IDOK,button,1342242817
Control2=IDC_LST_VALUE,SysListView32,1350635521
Control3=IDC_Edt_Rows,edit,1350631552
Control4=IDC_STC_LBL,static,1342308352

