// ReminderDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Reminder.h"
#include "ReminderDlg.h"
#include "SolarDate.h"
#include "Settings.h"
#include "HistoricalDateDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

enum ACTIONS{ OPEN=5,CLOSE=6,FLASH=7 };
#define TRIM(str) str.TrimLeft(); str.TrimRight();
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
	virtual BOOL OnInitDialog();
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
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CReminderDlg dialog

CReminderDlg::CReminderDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CReminderDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CReminderDlg)
	m_date = _T("");
	m_time = _T("");
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CReminderDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CReminderDlg)
	DDX_Text(pDX, IDC_DATE, m_date);
	DDX_Text(pDX, IDC_TIME, m_time);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CReminderDlg, CDialog)
	//{{AFX_MSG_MAP(CReminderDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_CTLCOLOR()
	ON_WM_TIMER()
	ON_COMMAND(ID_MAINMENU_EXIT, OnMainMenuExit)
	ON_COMMAND(ID_MAINMENU_PREFRENCESS, OnMainMenuPreferences)
	ON_WM_MOUSEMOVE()
	ON_COMMAND(ID_ABOUT, OnAbout)
	ON_COMMAND(ID_ADD_HISTORICAL, OnAddHistorical)
	//}}AFX_MSG_MAP
	ON_MESSAGE (WM_TRAY_ICON_NOTIFY_MESSAGE,OnTrayNotify)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CReminderDlg message handlers

BOOL CReminderDlg::OnInitDialog()
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

	//-----------------------------------------------------------------------------------
	GetDlgItem(IDC_DATE_TXT)->SetWindowText(_T("ÊÇÑíÎ"));
	SetWindowText(_T("Reminder"));
	CSolarDate dt;
	m_date = dt.GetCurSDate();

	ModifyStyleEx(WS_EX_APPWINDOW,0);

//	OnTimer(0);
	SetTimer(0,1000,0);

	UpdateData(FALSE);
	StartTray();

	m_menu.LoadMenu(IDR_MAIN_MENU);
	m_check.LoadBitmap(IDB_SMALL_ADJ);
	m_unCheck.LoadBitmap(IDB_SMALL_ADJ);

	m_menu.GetSubMenu(0)->SetMenuItemBitmaps(ID_MAINMENU_PREFRENCESS,MF_BYCOMMAND,
		&m_check,&m_unCheck);

	vDx=5;
	cx = GetSystemMetrics(SM_CXSCREEN);
	cy = GetSystemMetrics(SM_CYSCREEN);

	SetWindowPos(&CWnd::wndTopMost,cx-5,50,0,0,SWP_NOSIZE);

	mouseWasIn = FALSE;
	GetClientRect(cr);

//	Animate(FLASH);	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CReminderDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CReminderDlg::OnPaint() 
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
HCURSOR CReminderDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CReminderDlg::OnOK() 
{
//	CDialog::OnOK();
}

void CReminderDlg::OnCancel() 
{
}

HBRUSH CReminderDlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor) 
{
	COLORREF color = RGB(255,255,255);

	switch (pWnd->GetDlgCtrlID()) {
	case IDC_DATE	: color=RGB(220,255,220); break;
	case IDC_TIME	: color=RGB(220,220,250); break;
	case IDC_MESSAGE: color=RGB(220,255,255); break;
//	default: break;
	}

	pDC->SetBkColor(color);
	pDC->SetBkMode(TRANSPARENT);
	HBRUSH hb = CreateSolidBrush(color);
	return hb;
}

void CReminderDlg::StartTray()
{
	m_nidIconData.cbSize			= sizeof(NOTIFYICONDATA);
	
	m_nidIconData.uCallbackMessage	= WM_TRAY_ICON_NOTIFY_MESSAGE;

	m_nidIconData.hIcon				= 0;
	m_nidIconData.uFlags			= NIF_MESSAGE;

	m_nidIconData.hWnd = this->m_hWnd;
	m_nidIconData.uID = 1;
	wcscpy(m_nidIconData.szTip,_T("Reminder Status :)"));
	HICON hIcon = 0;
	hIcon = AfxGetApp()->LoadIcon(IDI_TRAY);
	if(hIcon)
	{
		m_nidIconData.hIcon = hIcon;
		m_nidIconData.uFlags |= (NIF_ICON | NIF_TIP);
	}

// Setade die
// 53-4 Sarparasty

	Shell_NotifyIcon(NIM_ADD,&m_nidIconData);
}
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void CReminderDlg::OnTrayNotify(WPARAM wParam,LPARAM lParam)
{
	CPoint pt;

	switch (lParam) {
	case WM_RBUTTONDOWN:
		GetCursorPos(&pt);
			//SetMenuItemBitmaps(MF_BYPOSITION,pBmpUnchecked,

		m_menu.GetSubMenu(0)->TrackPopupMenu(TPM_BOTTOMALIGN|TPM_LEFTBUTTON|TPM_RIGHTBUTTON,
			pt.x,pt.y,this,NULL);
		break;
	case WM_LBUTTONDBLCLK:
		break;
	}
}

void CReminderDlg::OnMainMenuExit() 
{
	if(m_nidIconData.hWnd && m_nidIconData.uID>0)
	{
		Shell_NotifyIcon(NIM_DELETE,&m_nidIconData);
	}

	if (m_check.m_hObject)
		  m_check.DeleteObject();

   if (m_unCheck.m_hObject)
      m_unCheck.DeleteObject();

	CDialog::OnCancel();
}

void CReminderDlg::OnMainMenuPreferences() 
{
	CSettings dlg;
	dlg.DoModal();
}

void CReminderDlg::OnMouseMove(UINT nFlags, CPoint point) 
{
	//if mouse is comming in
	if (PtInRect(&cr,point) && !mouseWasIn) {
		SetCapture();
		mouseWasIn = TRUE;
		Animate(OPEN);
		return;
	//else if mouse is leaving
	} else if (mouseWasIn && !PtInRect(&cr,point)){
		if (mouseWasIn) {
			ReleaseCapture();
			mouseWasIn = FALSE;
			Animate(CLOSE);
		}
	//mouse is moving but, 1.ptInrect&&mousewasin || 2.!ptInrect!mousewasin
	} else {
		if (NULL==GetCapture()) {
			if (mouseWasIn) {
				ReleaseCapture();
				mouseWasIn = FALSE;
				Animate(CLOSE);
			} else {
				if (PtInRect(&cr,point)) {
					SetCapture();
					mouseWasIn = TRUE;
				} else {
					ReleaseCapture();
					mouseWasIn = FALSE;
					Animate(CLOSE);
				}
			}
		} else	{
			//mouse was in && we have capture && now mouse is in
		}
	}

	CDialog::OnMouseMove(nFlags, point);
}

void CReminderDlg::Animate(int action)
{
	SetTimer(action,5,0);
}

void CReminderDlg::OnTimer(UINT nIDEvent) 
{
	static int ind=5;
	if (nIDEvent==0) {
		CTime tm;
		tm=tm.GetCurrentTime();
		m_time.Format(_T("%d : %d : %d"),tm.GetSecond(),tm.GetMinute(),tm.GetHour());
		UpdateData(FALSE);
	} else if (nIDEvent==OPEN) {
		if (vDx <=5) ReCalcDate();
		if (vDx>=(cr.right-20)) {
			KillTimer(OPEN);
			return;
		}
		KillTimer(CLOSE);
		vDx+=20;
		SetWindowPos(0,cx-vDx,50,0,0,SWP_NOSIZE | SWP_NOZORDER);
	} else if (nIDEvent==CLOSE) {
		if (vDx<=5) {
			KillTimer(CLOSE);
			return;
		}
		KillTimer(OPEN);
		vDx-=20;
		SetWindowPos(0,cx-vDx,50,0,0,SWP_NOSIZE | SWP_NOZORDER);
	} else if (nIDEvent==FLASH) {
		KillTimer(OPEN);
		KillTimer(CLOSE);
		if (ind<=(cr.right-20)) {
			ind+=20;
			SetWindowPos(0,cx-ind,50,0,0,SWP_NOSIZE | SWP_NOZORDER);
			vDx=ind;
			return;
		} else if (vDx>5) {
			if (vDx==ind) Sleep(5000);
			vDx-=20;
			SetWindowPos(0,cx-vDx,50,0,0,SWP_NOSIZE | SWP_NOZORDER);
			return;
		} else {
			KillTimer(FLASH);
		}
	}
	
	CDialog::OnTimer(nIDEvent);
}

void CReminderDlg::OnAbout() 
{
	CAboutDlg dlg;
	dlg.DoModal();

}

BOOL CAboutDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	int cx = GetSystemMetrics(SM_CXSCREEN);
	int cy = GetSystemMetrics(SM_CYSCREEN);

	SetWindowPos(0,cx-360,cy-160,0,0,SWP_NOSIZE);
	return TRUE;
}

void CReminderDlg::ReCalcDate()
{
	CSolarDate dt;
	m_date = dt.GetCurSDate();
	UpdateData(FALSE);
}

void CReminderDlg::OnAddHistorical() 
{
	CHistoricalDateDlg dlg;
	dlg.DoModal();
	
	CString str;
	TRIM(str);

}

