#if !defined(AFX_CHANGEDATEDLG_H__984A5108_5557_47F6_9445_C170BF9DE557__INCLUDED_)
#define AFX_CHANGEDATEDLG_H__984A5108_5557_47F6_9445_C170BF9DE557__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ChangeDateDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CChangeDateDlg dialog

class CChangeDateDlg : public CDialog
{
// Construction
public:
	CChangeDateDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CChangeDateDlg)
	enum { IDD = IDD_DATE_DLG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CChangeDateDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CChangeDateDlg)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CHANGEDATEDLG_H__984A5108_5557_47F6_9445_C170BF9DE557__INCLUDED_)
