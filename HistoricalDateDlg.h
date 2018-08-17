#if !defined(AFX_HISTORICALDATEDLG_H__8ACCAD96_FE56_4047_AAEA_B5D98E5C3B6D__INCLUDED_)
#define AFX_HISTORICALDATEDLG_H__8ACCAD96_FE56_4047_AAEA_B5D98E5C3B6D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// HistoricalDateDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CHistoricalDateDlg dialog

class CHistoricalDateDlg : public CDialog
{
// Construction
public:
	CHistoricalDateDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CHistoricalDateDlg)
	enum { IDD = IDD_HISTORICAL };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CHistoricalDateDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CHistoricalDateDlg)
	afx_msg void OnChangeDate();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_HISTORICALDATEDLG_H__8ACCAD96_FE56_4047_AAEA_B5D98E5C3B6D__INCLUDED_)
