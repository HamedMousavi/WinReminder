// Settings.cpp : implementation file
//

#include "stdafx.h"
#include "Reminder.h"
#include "Settings.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSettings dialog


CSettings::CSettings(CWnd* pParent /*=NULL*/)
	: CDialog(CSettings::IDD, pParent)
{
	//{{AFX_DATA_INIT(CSettings)
	m_startup = FALSE;
	//}}AFX_DATA_INIT
}


void CSettings::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CSettings)
	DDX_Check(pDX, IDC_STARTUP, m_startup);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CSettings, CDialog)
	//{{AFX_MSG_MAP(CSettings)
	ON_BN_CLICKED(IDC_STARTUP, OnStartup)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSettings message handlers

void CSettings::OnOK() 
{
	CDialog::OnOK();
}

void CSettings::OnCancel() 
{
	CDialog::OnCancel();
}

void CSettings::OnStartup() 
{
	CString fileName,s;
	GetModuleFileName(NULL,s.GetBuffer(512),512);
	s.ReleaseBuffer();

	HKEY hkey=NULL;
	UpdateData(TRUE);
	//Open startup key
	if (RegOpenKeyEx(HKEY_LOCAL_MACHINE,
		_T("Software\\Microsoft\\Windows\\CurrentVersion\\Run")
		,0,KEY_ALL_ACCESS,&hkey)==ERROR_SUCCESS) {

		//Registry Key opened successfully:), so fill it;)
		if (!m_startup) {
			if (RegDeleteValue(hkey,(LPCTSTR)_T("Reminder App")) !=ERROR_SUCCESS){
				AfxMessageBox(_T("Critical error:Unable to remove from startup...:("));
				m_startup=TRUE;
			}
			RegCloseKey(hkey);
			UpdateData(FALSE);
			return;
		}
		if (RegSetValueEx(hkey,(LPCTSTR)_T("Reminder App"),
			0,REG_SZ,(const unsigned char*)(LPCTSTR)s,s.GetLength()*2) !=ERROR_SUCCESS){
			AfxMessageBox(_T("Unable to set for startup...:(("));
		}
	}else {
			AfxMessageBox(_T("Unable to set for startup...:(("));
	}

	//Close registry key=cleanup
	RegCloseKey(hkey);
}
