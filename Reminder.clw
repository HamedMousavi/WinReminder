; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CChangeDateDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "Reminder.h"

ClassCount=6
Class1=CReminderApp
Class2=CReminderDlg
Class3=CAboutDlg

ResourceCount=9
Resource1=IDD_ABOUTBOX
Resource2=IDR_MAINFRAME
Resource3=IDD_REMINDER_DIALOG
Resource4=IDD_SETTINGS
Resource5=IDD_REMINDER_DIALOG (Neutral)
Resource6=IDD_HISTORICAL
Class4=CSettings
Resource7=IDD_DATE_DLG
Class5=CHistoricalDateDlg
Resource8=IDD_ABOUTBOX (English (U.S.))
Class6=CChangeDateDlg
Resource9=IDR_MAIN_MENU (Neutral)

[CLS:CReminderApp]
Type=0
HeaderFile=Reminder.h
ImplementationFile=Reminder.cpp
Filter=N

[CLS:CReminderDlg]
Type=0
HeaderFile=ReminderDlg.h
ImplementationFile=ReminderDlg.cpp
Filter=W
BaseClass=CDialog
VirtualFilter=dWC
LastObject=CReminderDlg

[CLS:CAboutDlg]
Type=0
HeaderFile=ReminderDlg.h
ImplementationFile=ReminderDlg.cpp
Filter=D
LastObject=ID_ADD_HISTORICAL
BaseClass=CDialog
VirtualFilter=dWC

[DLG:IDD_ABOUTBOX]
Type=1
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308352
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889
Class=CAboutDlg


[DLG:IDD_REMINDER_DIALOG]
Type=1
ControlCount=3
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_STATIC,static,1342308352
Class=CReminderDlg

[DLG:IDD_ABOUTBOX (English (U.S.))]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_REMINDER_DIALOG (Neutral)]
Type=1
Class=CReminderDlg
ControlCount=7
Control1=IDC_STATIC,button,1342177287
Control2=IDC_DATE_TXT,static,1342308352
Control3=IDC_DATE,edit,1350568065
Control4=IDC_STATIC,static,1342308352
Control5=IDC_TIME,edit,1350568065
Control6=IDC_MESSAGE,edit,1350568064
Control7=IDC_STATIC,static,1342177294

[CLS:CSettings]
Type=0
HeaderFile=Settings.h
ImplementationFile=Settings.cpp
BaseClass=CDialog
Filter=D
LastObject=IDC_STARTUP
VirtualFilter=dWC

[DLG:IDD_SETTINGS]
Type=1
Class=CSettings
ControlCount=5
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_STARTUP,button,1342242819
Control4=IDC_STATIC,static,1342177294
Control5=IDC_STATIC,button,1342177287

[MNU:IDR_MAIN_MENU (Neutral)]
Type=1
Class=?
CommandCount=0

[DLG:IDD_HISTORICAL]
Type=1
Class=CHistoricalDateDlg
ControlCount=14
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_STATIC,static,1342177294
Control4=IDC_STATIC,button,1342177287
Control5=IDC_STATIC,static,1342308352
Control6=IDC_DATETIMEPICKER1,SysDateTimePick32,1342242848
Control7=IDC_STATIC,static,1342308352
Control8=IDC_MESSAGE,edit,1350566016
Control9=IDC_STATIC,button,1342177287
Control10=IDC_COMBO3,combobox,1344340226
Control11=IDC_STATIC,static,1342308352
Control12=IDC_EDIT6,edit,1350633600
Control13=IDC_STATIC,button,1342177287
Control14=IDC_CHANGE_DATE,button,1342242816

[CLS:CHistoricalDateDlg]
Type=0
HeaderFile=HistoricalDateDlg.h
ImplementationFile=HistoricalDateDlg.cpp
BaseClass=CDialog
Filter=D
LastObject=CHistoricalDateDlg
VirtualFilter=dWC

[DLG:IDD_DATE_DLG]
Type=1
Class=CChangeDateDlg
ControlCount=37
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_STATIC,button,1342177287
Control4=IDC_RADIO1,button,1342308361
Control5=IDC_RADIO2,button,1342177289
Control6=IDC_RADIO3,button,1342177289
Control7=IDC_STATIC,static,1342308352
Control8=IDC_EDIT5,edit,1350631552
Control9=IDC_SPIN2,msctls_updown32,1342177312
Control10=IDC_STATIC,static,1342308352
Control11=IDC_CHECK1,button,1342242819
Control12=IDC_CHECK2,button,1342242819
Control13=IDC_CHECK3,button,1342242819
Control14=IDC_CHECK4,button,1342242819
Control15=IDC_CHECK5,button,1342242819
Control16=IDC_CHECK6,button,1342242819
Control17=IDC_CHECK7,button,1342242819
Control18=IDC_STATIC,button,1342177287
Control19=IDC_STATIC,button,1342177287
Control20=IDC_STATIC,button,1342177287
Control21=IDC_RADIO4,button,1342308361
Control22=IDC_RADIO5,button,1342177289
Control23=IDC_DATETIMEPICKER3,SysDateTimePick32,1342242857
Control24=IDC_EDIT6,edit,1350631552
Control25=IDC_SPIN3,msctls_updown32,1342177312
Control26=IDC_COMBO2,combobox,1344340226
Control27=IDC_DATETIMEPICKER4,SysDateTimePick32,1342242857
Control28=IDC_DATETIMEPICKER5,SysDateTimePick32,1342242857
Control29=IDC_STATIC,static,1342308352
Control30=IDC_STATIC,static,1342308352
Control31=IDC_STATIC,button,1342177287
Control32=IDC_STATIC,static,1342308352
Control33=IDC_DATETIMEPICKER2,SysDateTimePick32,1342242848
Control34=IDC_RADIO6,button,1342308361
Control35=IDC_RADIO7,button,1342177289
Control36=IDC_DATETIMEPICKER6,SysDateTimePick32,1342242848
Control37=IDC_STATIC,static,1342177294

[CLS:CChangeDateDlg]
Type=0
HeaderFile=ChangeDateDlg.h
ImplementationFile=ChangeDateDlg.cpp
BaseClass=CDialog
Filter=D
LastObject=CChangeDateDlg

