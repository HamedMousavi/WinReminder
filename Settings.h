#if !defined(AFX_SETTINGS_H__22000C19_7A92_4A84_853B_E8BE5A81A378__INCLUDED_)
#define AFX_SETTINGS_H__22000C19_7A92_4A84_853B_E8BE5A81A378__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Settings.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CSettings dialog

class CSettings : public CDialog
{
// Construction
public:
	CSettings(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CSettings)
	enum { IDD = IDD_SETTINGS };
	BOOL	m_startup;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSettings)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CSettings)
	virtual void OnOK();
	virtual void OnCancel();
	afx_msg void OnStartup();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SETTINGS_H__22000C19_7A92_4A84_853B_E8BE5A81A378__INCLUDED_)
