// SolarDate.cpp: implementation of the CSolarDate class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "SolarDate.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CSolarDate::CSolarDate()
{
	m_mDay=m_mMonth=m_mYear=0;
	m_sDay=m_sMonth=m_sYear=0;

	SetDefaultDate();
}

CSolarDate::~CSolarDate()
{

}

void CSolarDate::SetDefaultDate()
{
	CTime tm;
	tm=tm.GetCurrentTime();
	m_mDay=tm.GetDay();
	m_mMonth=tm.GetMonth();
	m_mYear=tm.GetYear();
	StoM();
}
//Setting Moon date
BOOL CSolarDate::SetMDate(CString date)
{
	if (!VerifyValidity(date))	return FALSE;
	//UNDONE year more than 3000
	if (m_tempYear<1000) {
		AfxMessageBox(_T("Warning: Moon Year less than 1000 may cause later problems.\n\nCation:  YEAR AUTOMATICALLY CHANGED TO 1000"));
		m_mYear=1000;
	} else m_mYear=m_tempYear;
	if (m_tempMonth>12) {
		AfxMessageBox(_T("Warning: Month is greater than 12.\n\nMONTH AUTOMATICALLY CHANGED TO 12"));
		m_mMonth=12;
	} else m_mMonth=m_tempMonth;
	if (m_tempDay>31) {
		AfxMessageBox(_T("Warning: Day is greater than 31.\n\nDAY AUTOMATICALLY CHANGED TO 31"));
		m_mDay=31;
	} else m_mDay=m_tempDay;
	MtoS();
	return TRUE;
}
//Setting Solar date
BOOL CSolarDate::SetSDate(CString date)
{
	//1416/10/28
	if (!VerifyValidity(date))	return FALSE;
	if (m_tempYear<1348) {
		AfxMessageBox(_T("Warning: Solar Year less than 1348 may cause later problems.\nRefer to Microsoft [MSDN], CTime class supports years from 1970/01/01(=1348/10/11) to 2038/01/18(=1416/10/28).\nHowever this class is capable of buffering less date values and converting older date values FROM Moon to Solar, BUT reverse conversions witch will use CTime class may encounter certain exceptions.\n\nCation:  DATE AUTOMATICALLY CHANGED TO 1348/10/11"));
		m_sYear=1348;
		m_sMonth=10;
		m_sDay=11;
	} else if (m_tempYear>1416) {
		AfxMessageBox(_T("Warning: Solar Year less than 1348 may cause later problems.\nRefer to Microsoft [MSDN], CTime class supports years from 1970/01/01(=1348/10/11) to 2038/01/18(=1416/10/28).\nHowever this class is capable of buffering less date values and converting older date values FROM Moon to Solar, BUT reverse conversions witch will use CTime class may encounter certain exceptions.\n\nCation:  DATE AUTOMATICALLY CHANGED TO 1416/10/28"));
		m_sYear=1416;
		m_sMonth=10;
		m_sDay=28;
	} else if (m_tempYear==1348) {
		if (m_tempMonth<10) {
			AfxMessageBox(_T("Warning: Solar Month less than 10 in year 1348 may cause later problems.\nRefer to Microsoft [MSDN], CTime class supports years from 1970/01/01(=1348/10/11) to 2038/01/18(=1416/10/28).\nHowever this class is capable of buffering less date values and converting older date values FROM Moon to Solar, BUT reverse conversions witch will use CTime class may encounter certain exceptions.\n\nCation:  MONTH AUTOMATICALLY CHANGED TO 10"));
			m_sMonth=10;
		} else m_sMonth=m_tempMonth;
		if (m_sMonth==10) {
			if (m_tempDay<11) {
				AfxMessageBox(_T("Warning: Solar Day less than 11 in 1348/10 may cause later problems.\nRefer to Microsoft [MSDN], CTime class supports years from 1970/01/01(=1348/10/11) to 2038/01/18(=1416/10/28).\nHowever this class is capable of buffering less date values and converting older date values FROM Moon to Solar, BUT reverse conversions witch will use CTime class may encounter certain exceptions.\n\nCation:  DAY AUTOMATICALLY CHANGED TO 11"));
				m_sDay=11;
			} else m_sDay=m_tempDay;
		} else {
			if (m_tempDay>31) {
				AfxMessageBox(_T("Warning: Day is greater than 31.\n\nDAY AUTOMATICALLY CHANGED TO 31"));
				m_sDay=31;
			} else m_sDay=m_tempDay;
		}

	} else if (m_tempYear==1416) {
		if (m_tempMonth>10) {
			AfxMessageBox(_T("Warning: Solar Month more than 10 in year 1416 may cause later problems.\nRefer to Microsoft [MSDN], CTime class supports years from 1970/01/01(=1348/10/11) to 2038/01/18(=1416/10/28).\nHowever this class is capable of buffering less date values and converting older date values FROM Moon to Solar, BUT reverse conversions witch will use CTime class may encounter certain exceptions.\n\nCation:  MONTH AUTOMATICALLY CHANGED TO 10"));
			m_sMonth=10;
		} else m_sMonth=m_tempMonth;
		if (m_sMonth==10) {
			if (m_tempDay>28) {
				AfxMessageBox(_T("Warning: Solar Day more than 28 in 1416/10 may cause later problems.\nRefer to Microsoft [MSDN], CTime class supports years from 1970/01/01(=1348/10/11) to 2038/01/18(=1416/10/28).\nHowever this class is capable of buffering less date values and converting older date values FROM Moon to Solar, BUT reverse conversions witch will use CTime class may encounter certain exceptions.\n\nCation:  DAY AUTOMATICALLY CHANGED TO 28"));
				m_sDay=28;
			} else m_sDay=m_tempDay;
		} else {
			if (m_tempDay>31) {
				AfxMessageBox(_T("Warning: Day is greater than 31.\n\nDAY AUTOMATICALLY CHANGED TO 31"));
				m_sDay=31;
			} else m_sDay=m_tempDay;
		}
	} else {
		m_sYear=m_tempYear;
		if (m_tempMonth>12) {
			AfxMessageBox(_T("Warning: Month is greater than 12.\n\nMONTH AUTOMATICALLY CHANGED TO 12"));
			m_sMonth=12;
		} else m_sMonth=m_tempMonth;
		if (m_tempDay>31) {
			AfxMessageBox(_T("Warning: Day is greater than 31.\n\nDAY AUTOMATICALLY CHANGED TO 31"));
			m_sDay=31;
		} else m_sDay=m_tempDay;
	}
	StoM();
	return TRUE;
}
//Finds and separates date string, then check for possible errors
BOOL CSolarDate::VerifyValidity(CString date)
{
	int len=0,index=0,sepNum=0;
	CString year="",month="",day="";
	
	len=date.GetLength();
	if (len > 10) return FALSE;

	for (int i=0;i<len;i++) {

		index=date.Find(_T("/"),i);
		if (index==-1) break;
		else {
			sepNum++;
			if (sepNum==1) year=date.Mid(i,index-i);
			else if (sepNum==2) month=date.Mid(i,index-i);
			i=index;
		}
	}
	day=date.Mid(i,2);
	if (sepNum>3) return FALSE;
	
	m_tempDay=_wtoi(day);
	m_tempMonth=_wtoi(month);
	m_tempYear=_wtoi(year);

	if (m_tempDay==0) return FALSE;
	if (m_tempMonth==0) return FALSE;
	if (m_tempYear==0) return FALSE;

	if (year.GetLength()>4) return FALSE;
	if (month.GetLength()>2) return FALSE;
	if (day.GetLength()>2) return FALSE;

	return TRUE;
}
//Returns Date according to your input 0=Solar or 1=Moon
CString CSolarDate::GetDate(BOOL dateType/*Solar or Moon*/)
{
	CString tmp,y,m,d;
	if (dateType) {
		y.Format(_T("%d"),m_mYear);
		m.Format(_T("%d"),m_mMonth);
		if (m.GetLength()<2) m="0"+m;
		d.Format(_T("%d"),m_mDay);
		if (d.GetLength()<2) d="0"+d;
	} else {
		y.Format(_T("%d"),m_sYear);
		m.Format(_T("%d"),m_sMonth);
		if (m.GetLength()<2) m="0"+m;
		d.Format(_T("%d"),m_sDay);
		if (d.GetLength()<2) d="0"+d;
	}

	tmp.Format(_T("%s/%s/%s"),y,m,d);
	return (tmp);
}

void CSolarDate::StoM()
{
	int y,m,d;
	//Base Date :		1350/1/1  [Solar]
	//					1971/3/21
	d=m_sDay;
	m=m_sMonth;
	y=m_sYear;

	d--;
	m--;
	if ( m>=0 && m<=6 ) {
		d+=m*31;
	} else if ( m>=7 && m<11) {
		d+=186+((m-6)*30);
	} else {
		d+=186+150;
	}

	long t=(y-1350)*365+(y-1351)/4;
	
	if (((y-1351)%4)>0) t++;
	long diff=t+d;

	CTime tm(1971,3,21,5,1,1);
	int i=0;
	if (diff>24000) {
		while(diff>24000) {
			i++;
			diff-=24000;
		}

		for (int j=0;j<i;j++) tm+=CTimeSpan(24000,5,1,1);
		tm+=CTimeSpan(diff,5,1,1);
	} else tm+=CTimeSpan(diff,5,1,1);

	if (tm<0) return ;
	m_mDay=tm.GetDay();
	m_mMonth=tm.GetMonth();
	m_mYear=tm.GetYear();
}

void CSolarDate::MtoS()
{
	int mDay,mMonth,mYear;
	int sDay,sMonth,sYear;
	bool mKabiseh=false,mPKabiseh=false,sKabiseh=false;
	int numberOfDays=0,temp=0;

	mYear=m_mYear;
	mMonth=m_mMonth;
	mDay=m_mDay;
 //-----------------------------------------v Kabiseh! Identifying
	sYear=mYear-622;
	
	if ( (mYear-1996)%4==0) {
		mKabiseh=true;
		mPKabiseh=false;
	} else if ( ((mYear-1)-1996)%4==0) {
		mKabiseh=false;
		mPKabiseh=true;
	} else {
		mKabiseh=false;
		mPKabiseh=false;
	}

	if ( (sYear-1379)%4==0 ) sKabiseh=true;
//-----------------------------------------^ Kabiseh! Identifying
//-----------------------------------------v Counting Number of MILADI! Days from the beggining untill now
	switch (mMonth) {
	case 1: numberOfDays=mDay; break;
	case 2: numberOfDays=mDay+31;   break;
	case 3: numberOfDays=mDay+59;   break;
	case 4: numberOfDays=mDay+90;   break;
	case 5: numberOfDays=mDay+120;  break;
	case 6: numberOfDays=mDay+151;  break;
	case 7: numberOfDays=mDay+181;  break;
	case 8: numberOfDays=mDay+212;  break;
	case 9: numberOfDays=mDay+243;  break;
	case 10: numberOfDays=mDay+273; break;
	case 11: numberOfDays=mDay+304; break;
	case 12: numberOfDays=mDay+334; break;
	}
	numberOfDays++;
//-----------------------------------------^ Counting Number of MILADI! Days from the beggining untill now
	if (mKabiseh && mMonth>=3) numberOfDays++;

	if (mPKabiseh) temp= 366;
	else temp=365;

	numberOfDays+=(temp-80);

	if (numberOfDays>365 && (!sKabiseh)) {
		sYear++;
	} else if (numberOfDays>366 && (sKabiseh)) {
		sYear++;
	}

	if (numberOfDays>365) {
		if (sKabiseh && numberOfDays>366)	numberOfDays-=366;
		else if (!sKabiseh) numberOfDays-=365;
	}

	if (numberOfDays<=186) {
		sMonth=numberOfDays/31;
		sDay=numberOfDays%31;

		sMonth++;

		if (sMonth==0) {
			sMonth=1;
		}
		if (sDay==0) {
			sDay=31;
			sMonth--;
		}

	} else if (numberOfDays<=336){
		numberOfDays-=186;
		sMonth=numberOfDays/30;
		sMonth+=6;
		sDay=numberOfDays%30;

		sMonth++;

		if (sMonth==0) {
			sMonth=1;
		}
		if (sDay==0) {
			sDay=30;
			sMonth--;
		}
	} else {
		sMonth=12;
		if (!sKabiseh) sDay=29-(365-numberOfDays);
		else sDay=30-(366-numberOfDays);
	}
	m_sYear=sYear;
	m_sMonth=sMonth;
	m_sDay=sDay;
}

void CSolarDate::AddSDay(int days)
{
	if (days==0) return;
	if (days>24000) {
	};
	int y,m,d;
	//Base Date :		1350/1/1  [Solar]
	//					1971/3/21
	d=m_sDay;
	m=m_sMonth;
	y=m_sYear;

	d--;
	m--;
	if ( m>=0 && m<=6 ) {
		d+=m*31;
	} else if ( m>=7 && m<11) {
		d+=186+((m-6)*30);
	} else {
		d+=186+150;
	}

	long t=(y-1350)*365+(y-1351)/4;
	
	if (((y-1351)%4)>0) t++;
	long diff=t+d+days;

	CTime tm(1971,3,21,5,1,1);
	int i=0;
	if (diff>24000) {
		while(diff>24000) {
			i++;
			diff-=24000;
		}

		for (int j=0;j<i;j++) tm+=CTimeSpan(24000,5,1,1);
		tm+=CTimeSpan(diff,5,1,1);
	} else tm+=CTimeSpan(diff,5,1,1);

	m_mDay=tm.GetDay();
	m_mMonth=tm.GetMonth();
	m_mYear=tm.GetYear();
	MtoS();
}
CString CSolarDate::GetCurSDate()
{
	CTime tm;
	tm=tm.GetCurrentTime();
	m_mDay=tm.GetDay();
	m_mMonth=tm.GetMonth();
	m_mYear=tm.GetYear();

	MtoS();
	return GetDate(0);
}