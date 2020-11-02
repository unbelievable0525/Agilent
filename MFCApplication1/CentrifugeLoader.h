#pragma once

// 计算机生成了通过 Microsoft Visual C++ 创建的 IDispatch 包装类

// 注意: 请勿修改此文件的内容。如果此类
// 通过 Microsoft Visual C++ 重新生成，则你的修改将被覆盖。

/////////////////////////////////////////////////////////////////////////////

#include "afxwin.h"

class CentrifugeLoader : public CWnd
{
protected:
	DECLARE_DYNCREATE(CentrifugeLoader)
public:
	CLSID const& GetClsid()
	{
		static CLSID const clsid
			= { 0xA0E5DD8C, 0xEBAB, 0x414D, { 0x88, 0xC2, 0x25, 0x78, 0xFD, 0x43, 0xB6, 0xB5 } };
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
	long Initialize(LPCTSTR profile_name)
	{
		long result;
		static BYTE parms[] = VTS_BSTR;
		InvokeHelper(0x7, DISPATCH_METHOD, VT_I4, (void*)&result, parms, profile_name);
		return result;
	}
	long Close()
	{
		long result;
		InvokeHelper(0x8, DISPATCH_METHOD, VT_I4, (void*)&result, nullptr);
		return result;
	}
	void ShowDiagsDialog(BOOL modal, short security)
	{
		static BYTE parms[] = VTS_BOOL VTS_I2;
		InvokeHelper(0x9, DISPATCH_METHOD, VT_EMPTY, nullptr, parms, modal, security);
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
	CString GetFirmwareVersion()
	{
		CString result;
		InvokeHelper(0xc, DISPATCH_METHOD, VT_BSTR, (void*)&result, nullptr);
		return result;
	}
	CString GetHardwareVersion()
	{
		CString result;
		InvokeHelper(0xd, DISPATCH_METHOD, VT_BSTR, (void*)&result, nullptr);
		return result;
	}
	long Home()
	{
		long result;
		InvokeHelper(0xe, DISPATCH_METHOD, VT_I4, (void*)&result, nullptr);
		return result;
	}
	long Park()
	{
		long result;
		InvokeHelper(0xf, DISPATCH_METHOD, VT_I4, (void*)&result, nullptr);
		return result;
	}
	long OpenDoor(long bucket_num)
	{
		long result;
		static BYTE parms[] = VTS_I4;
		InvokeHelper(0x10, DISPATCH_METHOD, VT_I4, (void*)&result, parms, bucket_num);
		return result;
	}
	long LoadPlate(long bucket_num, double gripper_offset, double plate_height, long speed, long options)
	{
		long result;
		static BYTE parms[] = VTS_I4 VTS_R8 VTS_R8 VTS_I4 VTS_I4;
		InvokeHelper(0x11, DISPATCH_METHOD, VT_I4, (void*)&result, parms, bucket_num, gripper_offset, plate_height, speed, options);
		return result;
	}
	long UnloadPlate(long bucket_num, double gripper_offset, double plate_height, long speed, long options)
	{
		long result;
		static BYTE parms[] = VTS_I4 VTS_R8 VTS_R8 VTS_I4 VTS_I4;
		InvokeHelper(0x12, DISPATCH_METHOD, VT_I4, (void*)&result, parms, bucket_num, gripper_offset, plate_height, speed, options);
		return result;
	}
	long SpinCycle(double vel_percent, double accel_percent, double decel_percent, long timer_mode, long time, long bucket_num_load, long bucket_num_unload, double gripper_offset_load, double gripper_offset_unload, double plate_height_load, double plate_height_unload, long speed_load, long speed_unload, long load_options, long unload_options)
	{
		long result;
		static BYTE parms[] = VTS_R8 VTS_R8 VTS_R8 VTS_I4 VTS_I4 VTS_I4 VTS_I4 VTS_R8 VTS_R8 VTS_R8 VTS_R8 VTS_I4 VTS_I4 VTS_I4 VTS_I4;
		InvokeHelper(0x13, DISPATCH_METHOD, VT_I4, (void*)&result, parms, vel_percent, accel_percent, decel_percent, timer_mode, time, bucket_num_load, bucket_num_unload, gripper_offset_load, gripper_offset_unload, plate_height_load, plate_height_unload, speed_load, speed_unload, load_options, unload_options);
		return result;
	}
	long CloseDoor()
	{
		long result;
		InvokeHelper(0x14, DISPATCH_METHOD, VT_I4, (void*)&result, nullptr);
		return result;
	}
	CString GetCentrifugeActiveXVersion()
	{
		CString result;
		InvokeHelper(0x15, DISPATCH_METHOD, VT_BSTR, (void*)&result, nullptr);
		return result;
	}
	CString GetCentrifugeHardwareVersion()
	{
		CString result;
		InvokeHelper(0x16, DISPATCH_METHOD, VT_BSTR, (void*)&result, nullptr);
		return result;
	}
	long StopSpinCycle(long bucket_num)
	{
		long result;
		static BYTE parms[] = VTS_I4;
		InvokeHelper(0x17, DISPATCH_METHOD, VT_I4, (void*)&result, parms, bucket_num);
		return result;
	}
};
