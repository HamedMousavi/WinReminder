// HistoricalDateDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Reminder.h"
#include "HistoricalDateDlg.h"
#include "ChangeDateDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CHistoricalDateDlg dialog


CHistoricalDateDlg::CHistoricalDateDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CHistoricalDateDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CHistoricalDateDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CHistoricalDateDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CHistoricalDateDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CHistoricalDateDlg, CDialog)
	//{{AFX_MSG_MAP(CHistoricalDateDlg)
	ON_BN_CLICKED(IDC_CHANGE_DATE, OnChangeDate)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CHistoricalDateDlg message handlers

void CHistoricalDateDlg::OnChangeDate() 
{
	CChangeDateDlg dlg;
	dlg.DoModal();
}
