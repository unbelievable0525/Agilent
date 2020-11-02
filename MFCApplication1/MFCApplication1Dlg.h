
// MFCApplication1Dlg.h: 头文件
//

#pragma once
#include "Centrifuge.h"
#include "CentrifugeLoader.h"
//#include "COCX.h"



// CMFCApplication1Dlg 对话框
class CMFCApplication1Dlg : public CDialogEx
{
// 构造
public:
	CMFCApplication1Dlg(CWnd* pParent = nullptr);	// 标准构造函数

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MFCAPPLICATION1_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;
	
	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	Centrifuge m_Centrifuge;
	afx_msg void OnBnClickedButton1();
	DECLARE_EVENTSINK_MAP()
	void ErrorCentrifugectrl1(short Number, BSTR* Description, long Scode, LPCTSTR Source, LPCTSTR HelpFile, long HelpContext, BOOL* CancelDisplay);
	void InitializeCompleteCentrifugectrl1();
	void CloseCompleteCentrifugectrl1();
	void OpenDoorCompleteCentrifugectrl1(short bucket_num);
	void CloseDoorCompleteCentrifugectrl1();
	void SpinCycleCompleteCentrifugectrl1(short bucket_num);
	void StopSpinCycleCompleteCentrifugectrl1(short bucket_num);
	bool m_usbAccessCentrifuge;
	
	int m_bucketNum1;
	CComboBox m_combo1;
	afx_msg void OnCbnSelchangeBucketNum();
	afx_msg void OnBnClickedOpenDoor1();
	
	DOUBLE m_centrifuge_velPerc;
//	DOUBLE m_centrifuge_accelPerc;
//	DOUBLE m_centrifuge_decelPerc;
	DOUBLE m_centrifuge_accelPerc;
	DOUBLE m_centrifuge_decelPerc;
	CComboBox m_centrifuge_combTimeMode;
	afx_msg void OnCbnSelchangeCombo2();
	int m_centrifuge_timer_mode;
	LONG m_centrifuge_time;
	afx_msg void OnBnClickedButton9();
	afx_msg void OnBnClickedButton6();
	afx_msg void OnBnClickedButton7();
	BOOL m_centrifuge_isSpinning;
	BOOL m_centrifuge_isOpened;
	afx_msg void OnBnClickedButton10();
	afx_msg void OnBnClickedButton4();
	afx_msg void OnBnClickedButton5();
	//------------------------------------------------------

	CentrifugeLoader m_CentrifugeLoader;
	void ErrorVspinaccess2ctrl5(short Number, BSTR* Description, long Scode, LPCTSTR Source, LPCTSTR HelpFile, long HelpContext, BOOL* CancelDisplay);
	void InitializeCompleteVspinaccess2ctrl5();
	void CloseCompleteVspinaccess2ctrl5();
	void ControllerMessageVspinaccess2ctrl5(LONGLONG timestamp_ft, long timestamp_us, long message_type, LPCTSTR message, long info_type, long info_value1, long info_value2, long info_value3);
	void HomeCompleteVspinaccess2ctrl5();
	void ParkCompleteVspinaccess2ctrl5();
	void OpenDoorCompleteVspinaccess2ctrl5(short bucket_num);
	void LoadPlateCompleteVspinaccess2ctrl5(short bucket_num);
	void UnloadPlateCompleteVspinaccess2ctrl5(short bucket_num);
	void SpinCycleCompleteVspinaccess2ctrl5(short bucket_num);
	void CloseDoorCompleteVspinaccess2ctrl5();
	void StopSpinCycleCompleteVspinaccess2ctrl5(short bucket_num);
	afx_msg void OnBnClickedButton12();
	afx_msg void OnBnClickedButton11();
	bool m_usbAccessCentrifugeLoader;
	afx_msg void OnBnClickedCentrifugeLoaderInit();
	afx_msg void OnBnClickedCentrifugeLoaderDisconnect();
	afx_msg void OnBnClickedCentrifugeDisconnect();
	CComboBox m_bucketComboBox;
	// centrifugeloader的编号
	int m_loader_bucket_num;
	afx_msg void OnCbnSelchangeCombo3();
	afx_msg void OnBnClickedButton2();
	BOOL m_loader_doorIsOpened;
	afx_msg void OnBnClickedLoaderCloseDoor();
	afx_msg void OnBnClickedButton19();
	afx_msg void OnBnClickedButton15();
	CEdit m_gripperOffsetEdit;
	DOUBLE m_gripperOffset;
	CEdit m_plateHeightEdit;
	DOUBLE m_plateHeight;
	CComboBox m_speedComboBox;
	int m_speed;
	CComboBox m_optionsComboBox;
	int m_options;
	CButton bucket1;
	CButton bucket2;
	afx_msg void OnBnClickedCentrifugeLoaderLoadPlate();
	CProgressCtrl m_ProgressCtrl1;
	CProgressCtrl m_ProgressCtrl2;
	
	afx_msg void OnBnClickedButton24();
	afx_msg void OnBnClickedLoaderUnloadPlate();
	CEdit m_LoaderVelEdit;
	DOUBLE m_loaderVel;
	CEdit m_LoaderAccelEdit;
	DOUBLE m_loaderAccel;
	CEdit m_LoaderDecelEdit;
	DOUBLE m_loaderDecel;
	CComboBox m_LoaderTimeMode;
	LONG m_loaderTimeMode;
	CEdit m_LoaderTime;
	LONG m_loaderTime;
	CComboBox m_LoaderBucketLoad;
	LONG m_loaderBucketLoad;
	CComboBox m_LoaderBucketUnload;
	LONG m_loaderBucketUnload;
	CEdit m_LoaderOffsetLoad;
	DOUBLE m_loaderOffsetLoad;
	CEdit m_LoaderOffsetUnload;
	DOUBLE m_loaderOffsetUnload;
	CEdit m_LoaderHeightLoad;
	DOUBLE m_loaderHeightLoad;
	CEdit m_LoaderHeightUnload;
	DOUBLE m_loaderHeightUnload;
	CComboBox m_LoaderSpeedLoad;
	int m_loaderSpeedLoad;
	CComboBox m_LoaderSpeedUnload;
	int m_loaderSpeedUnload;
	CComboBox m_LoaderOptionsLoad;
	int m_loaderOptionsLoad;
	CComboBox m_LoaderOptionsUnload;
	int m_loaderOptionsUnload;
	afx_msg void OnBnClickedButton25();
	afx_msg void OnCentrifugeLoaderSpinCycle();
	BOOL m_loaderisSpinning;
	afx_msg void OnCentrifugeLoaderStopSpinCycle();
	afx_msg void OnBnClickedButton26();
	afx_msg void OnBnClickedButton27();
	afx_msg void OnBnClickedButton28();
	afx_msg void OnBnClickedButton29();
};
