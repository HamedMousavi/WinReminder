// SolarDate.h: interface for the CSolarDate class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_SOLARDATE_H__1208A9F7_E26C_47B9_8178_E03119E2F959__INCLUDED_)
#define AFX_SOLARDATE_H__1208A9F7_E26C_47B9_8178_E03119E2F959__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CSolarDate  
{
public:
	CString GetCurSDate();
	void AddSDay(int days);
	void MtoS(void);
	void StoM(void);
	CString GetDate (BOOL dateType);
	BOOL SetSDate(CString date);
	BOOL SetMDate(CString date);
	CSolarDate();
	virtual ~CSolarDate();
private:
	BOOL VerifyValidity(CString date);
	void SetDefaultDate(void);
	int	m_mDay,m_mMonth,m_mYear;
	int m_sDay,m_sMonth,m_sYear;
	int m_tempDay,m_tempMonth,m_tempYear;

};

#endif // !defined(AFX_SOLARDATE_H__1208A9F7_E26C_47B9_8178_E03119E2F959__INCLUDED_)
