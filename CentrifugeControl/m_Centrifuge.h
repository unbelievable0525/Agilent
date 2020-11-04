#pragma once

// 计算机生成了通过 Microsoft Visual C++ 创建的 IDispatch 包装类

// 注意: 请勿修改此文件的内容。如果此类
// 通过 Microsoft Visual C++ 重新生成，则你的修改将被覆盖。

/////////////////////////////////////////////////////////////////////////////

#include "afxwin.h"

class m_Centrifuge : public CWnd
{
protected:
	DECLARE_DYNCREATE(m_Centrifuge)
public:
public:
	CLSID const& GetClsid()
	{
		static CLSID const clsid
			= { 0x411ea0d8,0xd1a5,0x4183,{0xb7,0xce,0x41,0xc8,0x95,0x1c,0x99,0x0a} };
		return clsid;
	}
	virtual BOOL Create(LPCTSTR lpszClassName, LPCTSTR lpszWindowName, DWORD dwStyle,
		const RECT& rect, CWnd* pParentWnd, UINT nID,
		CCreateContext* pContext = nullptr)
	{
		return CreateControl(GetClsid(), lpszWindowName, dwStyle, rect, pParentWnd, nID);
	}

	BOOL Create(LPCTSTR lpszWindowName, DWORD dwStyle, const RECT& rect, CWnd* pParentWnd,
		UINT nID, CFile* pPersist = nullptr, BOOL bStorage = FALSE,
		BSTR bstrLicKey = nullptr)
	{
		return CreateControl(GetClsid(), lpszWindowName, dwStyle, rect, pParentWnd, nID,
			pPersist, bStorage, bstrLicKey);
	}

	// 特性
public:


	// 操作
public:
	void AboutBox()
	{
		InvokeHelper(DISPID_ABOUTBOX, DISPATCH_METHOD, VT_EMPTY, nullptr, nullptr);
	}
	long Abort()
	{
		long result;
		InvokeHelper(0x3, DISPATCH_METHOD, VT_I4, (void*)&result, nullptr);
		return result;
	}
	long Ignore()
	{
		long result;
		InvokeHelper(0x4, DISPATCH_METHOD, VT_I4, (void*)&result, nullptr);
		return result;
	}
	long Retry()
	{
		long result;
		InvokeHelper(0x5, DISPATCH_METHOD, VT_I4, (void*)&result, nullptr);
		return result;
	}
	CString GetLastError()
	{
		CString result;
		InvokeHelper(0x6, DISPATCH_METHOD, VT_BSTR, (void*)&result, nullptr);
		return result;
	}
	long Initialize(LPCTSTR profileName)
	{
		long result;
		static BYTE parms[] = VTS_BSTR;
		InvokeHelper(0x7, DISPATCH_METHOD, VT_I4, (void*)&result, parms, profileName);
		return result;
	}
	long Close()
	{
		long result;
		InvokeHelper(0x8, DISPATCH_METHOD, VT_I4, (void*)&result, nullptr);
		return result;
	}
	void ShowDiagsDialog(BOOL modal, short securityLevel)
	{
		static BYTE parms[] = VTS_BOOL VTS_I2;
		InvokeHelper(0x9, DISPATCH_METHOD, VT_EMPTY, nullptr, parms, modal, securityLevel);
	}
	VARIANT EnumerateProfiles()
	{
		VARIANT result;
		InvokeHelper(0xa, DISPATCH_METHOD, VT_VARIANT, (void*)&result, nullptr);
		return result;
	}
	CString GetActiveXVersion()
	{
		CString result;
		InvokeHelper(0xb, DISPATCH_METHOD, VT_BSTR, (void*)&result, nullptr);
		return result;
	}
	CString GetHardwareVersion()
	{
		CString result;
		InvokeHelper(0xc, DISPATCH_METHOD, VT_BSTR, (void*)&result, nullptr);
		return result;
	}
	long OpenDoor(short bucket_num)
	{
		long result;
		static BYTE parms[] = VTS_I2;
		InvokeHelper(0xd, DISPATCH_METHOD, VT_I4, (void*)&result, parms, bucket_num);
		return result;
	}
	long CloseDoor()
	{
		long result;
		InvokeHelper(0xe, DISPATCH_METHOD, VT_I4, (void*)&result, nullptr);
		return result;
	}
	long SpinCycle(double vel_percent, double accel_percent, double decel_percent, short timer_mode, long time, short bucket_num)
	{
		long result;
		static BYTE parms[] = VTS_R8 VTS_R8 VTS_R8 VTS_I2 VTS_I4 VTS_I2;
		InvokeHelper(0xf, DISPATCH_METHOD, VT_I4, (void*)&result, parms, vel_percent, accel_percent, decel_percent, timer_mode, time, bucket_num);
		return result;
	}
	long StopSpinCycle(short bucket_num)
	{
		long result;
		static BYTE parms[] = VTS_I2;
		InvokeHelper(0x10, DISPATCH_METHOD, VT_I4, (void*)&result, parms, bucket_num);
		return result;
	}


};
