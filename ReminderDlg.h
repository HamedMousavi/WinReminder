// ReminderDlg.h : header file
//

#if !defined(AFX_REMINDERDLG_H__E14ACBBE_0C0E_4507_87AC_E875C6CFEB56__INCLUDED_)
#define AFX_REMINDERDLG_H__E14ACBBE_0C0E_4507_87AC_E875C6CFEB56__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CReminderDlg dialog
#define WM_TRAY_ICON_NOTIFY_MESSAGE (WM_USER + 100)

class CReminderDlg : public CDialog
{
private:
	void ReCalcDate();
	void Animate(int action);
	CRect			cr;
	int				cx,cy;
	int				vDx;
	BOOL			mouseWasIn;
	NOTIFYICONDATA	m_nidIconData;
	CMenu			m_menu;
	CBitmap			m_unCheck,m_check;
// Construction
public:
	void StartTray();
	CReminderDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CReminderDlg)
	enum { IDD = IDD_REMINDER_DIALOG };
	CString	m_date;
	CString	m_time;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CReminderDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CReminderDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	virtual void OnOK();
	virtual void OnCancel();
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	afx_msg void OnTimer(UINT nIDEvent);
	afx_msg void OnMainMenuExit();
	afx_msg void OnMainMenuPreferences();
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnAbout();
	afx_msg void OnAddHistorical();
	//}}AFX_MSG
	afx_msg void OnTrayNotify(WPARAM wParam,LPARAM lParam);
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_REMINDERDLG_H__E14ACBBE_0C0E_4507_87AC_E875C6CFEB56__INCLUDED_)
