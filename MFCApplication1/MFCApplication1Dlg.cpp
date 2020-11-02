
// MFCApplication1Dlg.cpp: 实现文件
//

#include "pch.h"
#include "framework.h"
#include "MFCApplication1.h"
#include "MFCApplication1Dlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();
	

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	


public:

};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}




// CMFCApplication1Dlg 对话框



CMFCApplication1Dlg::CMFCApplication1Dlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MFCAPPLICATION1_DIALOG, pParent)
	, m_bucketNum1(0)
	, m_centrifuge_isSpinning(0)
	, m_loader_bucket_num(0)
	, m_speed(0)
	, m_options(0)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	m_usbAccessCentrifuge = FALSE;
	m_centrifuge_velPerc = 0;
	m_centrifuge_accelPerc = 0;
	m_centrifuge_decelPerc = 0;
	m_centrifuge_timer_mode = 0;
	m_centrifuge_time = 0;
	m_centrifuge_isSpinning = FALSE;
	m_centrifuge_isOpened = FALSE;
	m_usbAccessCentrifugeLoader = FALSE;
	m_loader_doorIsOpened = FALSE;
	m_gripperOffset = 8.0;
	m_plateHeight = 15.0;
	m_loaderVel = 8.0;
	m_loaderAccel = 8.0;
	m_loaderDecel = 8.0;
	m_loaderTimeMode = 1;
	m_loaderTime = 10;
	m_loaderTime = 1;
	m_loaderBucketUnload = 1;
	m_loaderOffsetLoad = 8.0;
	m_loaderOffsetUnload = 8.0;
	m_loaderHeightLoad = 15.0;
	m_loaderHeightUnload = 15.0;
	m_loaderSpeedLoad = 2;
	m_loaderSpeedUnload = 2;
	m_loaderOptionsLoad = 1;
	m_loaderOptionsUnload = 1;

	m_loaderisSpinning = FALSE;

	
}

void CMFCApplication1Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_CENTRIFUGECTRL1, m_Centrifuge);
	DDX_CBIndex(pDX, IDC_COMBO1, m_bucketNum1);
	//DDV_MinMaxDouble(pDX, m_bucketNum1, 1, 2);
	DDX_Control(pDX, IDC_COMBO1, m_combo1);
	DDX_Text(pDX, IDC_EDIT2, m_centrifuge_velPerc);
	DDV_MinMaxDouble(pDX, m_centrifuge_velPerc, 1, 100);
	//  DDX_Text(pDX, IDC_EDIT3, m_centrifuge_accelPerc);
	//  DDX_Text(pDX, IDC_EDIT4, m_centrifuge_decelPerc);
	DDX_Text(pDX, IDC_EDIT3, m_centrifuge_accelPerc);
	DDV_MinMaxDouble(pDX, m_centrifuge_accelPerc, 1, 100);
	DDX_Text(pDX, IDC_EDIT4, m_centrifuge_decelPerc);
	DDV_MinMaxDouble(pDX, m_centrifuge_decelPerc, 1, 100);
	DDX_Control(pDX, IDC_COMBO2, m_centrifuge_combTimeMode);
	DDX_CBIndex(pDX, IDC_COMBO2, m_centrifuge_timer_mode);
	DDX_Text(pDX, IDC_EDIT5, m_centrifuge_time);
	DDV_MinMaxLong(pDX, m_centrifuge_time, 1, 86400);

	DDX_Control(pDX, IDC_VSPINACCESS2CTRL5, m_CentrifugeLoader);
	DDX_Control(pDX, IDC_COMBO3, m_bucketComboBox);
	DDX_CBIndex(pDX, IDC_COMBO3, m_loader_bucket_num);
	DDV_MinMaxInt(pDX, m_loader_bucket_num, 1, 2);
	DDX_Control(pDX, IDC_EDIT1, m_gripperOffsetEdit);
	DDX_Text(pDX, IDC_EDIT1, m_gripperOffset);
	DDV_MinMaxDouble(pDX, m_gripperOffset, 2.6, 21.1);
	DDX_Control(pDX, IDC_EDIT6, m_plateHeightEdit);
	DDX_Text(pDX, IDC_EDIT6, m_plateHeight);
	DDV_MinMaxDouble(pDX, m_plateHeight, 2.6, 48.3);
	DDX_Control(pDX, IDC_COMBO4, m_speedComboBox);
	DDX_CBIndex(pDX, IDC_COMBO4, m_speed);
	DDV_MinMaxDouble(pDX, m_gripperOffset, 0, 2);
	DDX_Control(pDX, IDC_COMBO5, m_optionsComboBox);
	DDX_CBIndex(pDX, IDC_COMBO5, m_options);
	DDV_MinMaxDouble(pDX, m_gripperOffset, 0, 7);
	DDX_Control(pDX, IDC_BUTTON17, bucket1);
	DDX_Control(pDX, IDC_BUTTON18, bucket2);
	DDX_Control(pDX, IDC_PROGRESS1, m_ProgressCtrl1);
	DDX_Control(pDX, IDC_PROGRESS2, m_ProgressCtrl2);
	DDX_Control(pDX, IDC_EDIT7, m_LoaderVelEdit);
	DDX_Text(pDX, IDC_EDIT7, m_loaderVel);
	DDV_MinMaxDouble(pDX, m_loaderVel, 1, 100);
	DDX_Control(pDX, IDC_EDIT8, m_LoaderAccelEdit);
	DDX_Text(pDX, IDC_EDIT8, m_loaderAccel);
	DDV_MinMaxDouble(pDX, m_loaderAccel, 1, 100);
	DDX_Control(pDX, IDC_EDIT9, m_LoaderDecelEdit);
	DDX_Text(pDX, IDC_EDIT9, m_loaderDecel);
	DDV_MinMaxDouble(pDX, m_loaderDecel, 1, 100);
	DDX_Control(pDX, IDC_COMBO6, m_LoaderTimeMode);
	DDX_Text(pDX, IDC_COMBO6, m_loaderTimeMode);
	DDV_MinMaxLong(pDX, m_loaderTimeMode, 0, 1);
	DDX_Control(pDX, IDC_EDIT10, m_LoaderTime);
	DDX_Text(pDX, IDC_EDIT10, m_loaderTime);
	DDV_MinMaxLong(pDX, m_loaderTime, 1, 86400);
	DDX_Control(pDX, IDC_COMBO7, m_LoaderBucketLoad);
	DDX_Text(pDX, IDC_COMBO7, m_loaderBucketLoad);
	DDV_MinMaxLong(pDX, m_loaderBucketLoad, 0, 2);
	DDX_Control(pDX, IDC_COMBO8, m_LoaderBucketUnload);
	DDX_Text(pDX, IDC_COMBO8, m_loaderBucketUnload);
	DDV_MinMaxLong(pDX,  m_loaderBucketUnload,0,2);
	DDX_Control(pDX, IDC_EDIT11, m_LoaderOffsetLoad);
	DDX_Text(pDX, IDC_EDIT11, m_loaderOffsetLoad);
	DDV_MinMaxDouble(pDX, m_loaderOffsetLoad, 2.6, 21.1);
	DDX_Control(pDX, IDC_EDIT12, m_LoaderOffsetUnload);
	DDX_Text(pDX, IDC_EDIT12, m_loaderOffsetUnload);
	DDV_MinMaxDouble(pDX, m_loaderOffsetUnload, 2.6, 21.1);
	DDX_Control(pDX, IDC_EDIT13, m_LoaderHeightLoad);
	DDX_Text(pDX, IDC_EDIT13, m_loaderHeightLoad);
	DDV_MinMaxDouble(pDX, m_loaderHeightLoad, 2.6, 48.3);
	DDX_Control(pDX, IDC_EDIT14, m_LoaderHeightUnload);
	DDX_Text(pDX, IDC_EDIT14, m_loaderHeightUnload);
	DDV_MinMaxDouble(pDX, m_loaderHeightUnload, 2.6, 48.3);
	DDX_Control(pDX, IDC_COMBO9, m_LoaderSpeedLoad);
	DDX_Text(pDX, IDC_COMBO9, m_loaderSpeedLoad);
	DDV_MinMaxInt(pDX, m_loaderSpeedLoad, 0, 2);
	DDX_Control(pDX, IDC_COMBO10, m_LoaderSpeedUnload);
	DDX_Text(pDX, IDC_COMBO10, m_loaderSpeedUnload);
	DDV_MinMaxInt(pDX, m_loaderSpeedLoad, 0, 2);
	DDX_Control(pDX, IDC_COMBO11, m_LoaderOptionsLoad);
	DDX_Text(pDX, IDC_COMBO11, m_loaderOptionsLoad);
	DDV_MinMaxInt(pDX, m_loaderOptionsLoad, 0, 2);
	DDX_Control(pDX, IDC_COMBO12, m_LoaderOptionsUnload);
	DDX_Text(pDX, IDC_COMBO12, m_loaderOptionsUnload);
	DDV_MinMaxInt(pDX, m_loaderOptionsUnload, 0, 2);
}

BEGIN_MESSAGE_MAP(CMFCApplication1Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CMFCApplication1Dlg::OnBnClickedButton1)
	
	ON_CBN_SELCHANGE(IDC_COMBO1, &CMFCApplication1Dlg::OnCbnSelchangeBucketNum)
	ON_BN_CLICKED(IDC_BUTTON3, &CMFCApplication1Dlg::OnBnClickedOpenDoor1)
	//ON_BN_CLICKED(IDC_BUTTON7, &CMFCApplication1Dlg::OnBnClickedButton7)
	ON_CBN_SELCHANGE(IDC_COMBO2, &CMFCApplication1Dlg::OnCbnSelchangeCombo2)
	ON_BN_CLICKED(IDC_BUTTON9, &CMFCApplication1Dlg::OnBnClickedButton9)
	ON_BN_CLICKED(IDC_BUTTON6, &CMFCApplication1Dlg::OnBnClickedButton6)
	ON_BN_CLICKED(IDC_BUTTON7, &CMFCApplication1Dlg::OnBnClickedButton7)
	ON_BN_CLICKED(IDC_BUTTON10, &CMFCApplication1Dlg::OnBnClickedButton10)
	ON_BN_CLICKED(IDC_BUTTON4, &CMFCApplication1Dlg::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON5, &CMFCApplication1Dlg::OnBnClickedButton5)
	ON_BN_CLICKED(IDC_BUTTON12, &CMFCApplication1Dlg::OnBnClickedButton12)
	ON_BN_CLICKED(IDC_BUTTON11, &CMFCApplication1Dlg::OnBnClickedButton11)
	ON_BN_CLICKED(IDC_BUTTON13, &CMFCApplication1Dlg::OnBnClickedCentrifugeLoaderInit)
	ON_BN_CLICKED(IDC_BUTTON14, &CMFCApplication1Dlg::OnBnClickedCentrifugeLoaderDisconnect)
	ON_BN_CLICKED(IDC_BUTTON8, &CMFCApplication1Dlg::OnBnClickedCentrifugeDisconnect)
	ON_CBN_SELCHANGE(IDC_COMBO3, &CMFCApplication1Dlg::OnCbnSelchangeCombo3)
	ON_BN_CLICKED(IDC_BUTTON2, &CMFCApplication1Dlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON16, &CMFCApplication1Dlg::OnBnClickedLoaderCloseDoor)
	ON_BN_CLICKED(IDC_BUTTON19, &CMFCApplication1Dlg::OnBnClickedButton19)
	ON_BN_CLICKED(IDC_BUTTON15, &CMFCApplication1Dlg::OnBnClickedButton15)
	ON_BN_CLICKED(IDC_BUTTON20, &CMFCApplication1Dlg::OnBnClickedCentrifugeLoaderLoadPlate)
	ON_BN_CLICKED(IDC_BUTTON24, &CMFCApplication1Dlg::OnBnClickedButton24)
	ON_BN_CLICKED(IDC_BUTTON21, &CMFCApplication1Dlg::OnBnClickedLoaderUnloadPlate)
	ON_BN_CLICKED(IDC_BUTTON25, &CMFCApplication1Dlg::OnBnClickedButton25)
	ON_BN_CLICKED(IDC_BUTTON22, &CMFCApplication1Dlg::OnCentrifugeLoaderSpinCycle)
	ON_BN_CLICKED(IDC_BUTTON23, &CMFCApplication1Dlg::OnCentrifugeLoaderStopSpinCycle)
	ON_BN_CLICKED(IDC_BUTTON26, &CMFCApplication1Dlg::OnBnClickedButton26)
	ON_BN_CLICKED(IDC_BUTTON27, &CMFCApplication1Dlg::OnBnClickedButton27)
	ON_BN_CLICKED(IDC_BUTTON28, &CMFCApplication1Dlg::OnBnClickedButton28)
	ON_BN_CLICKED(IDC_BUTTON29, &CMFCApplication1Dlg::OnBnClickedButton29)
END_MESSAGE_MAP()


// CMFCApplication1Dlg 消息处理程序

BOOL CMFCApplication1Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码
	//m_combo1.AddString(_T("请选择bucket编号"));
	bucket1.EnableWindow(FALSE);
	bucket2.EnableWindow(FALSE);
	m_combo1.AddString(_T("1"));
	m_combo1.AddString(_T("2"));
	m_centrifuge_combTimeMode.AddString(_T("0"));
	m_centrifuge_combTimeMode.AddString(_T("1"));
	m_centrifuge_combTimeMode.AddString(_T("2"));
	m_bucketComboBox.AddString(_T("1"));
	m_bucketComboBox.AddString(_T("2"));
	//m_combo1.SetCurSel(0);
	m_speedComboBox.AddString(_T("0"));
	m_speedComboBox.AddString(_T("1"));
	m_speedComboBox.AddString(_T("2"));
	m_speedComboBox.SetCurSel(0);
	m_optionsComboBox.AddString(_T("0"));
	m_optionsComboBox.AddString(_T("1"));
	m_optionsComboBox.AddString(_T("2"));
	m_optionsComboBox.AddString(_T("3"));
	m_optionsComboBox.AddString(_T("4"));
	m_optionsComboBox.AddString(_T("5"));
	m_optionsComboBox.AddString(_T("6"));
	m_optionsComboBox.AddString(_T("7"));
	m_optionsComboBox.SetCurSel(0);
	m_LoaderTimeMode.AddString(_T("0"));
	m_LoaderTimeMode.AddString(_T("1"));
	m_LoaderBucketLoad.AddString(_T("0"));
	m_LoaderBucketLoad.AddString(_T("1"));
	m_LoaderBucketLoad.AddString(_T("2"));
	m_LoaderBucketUnload.AddString(_T("0"));
	m_LoaderBucketUnload.AddString(_T("1"));
	m_LoaderBucketUnload.AddString(_T("2"));
	m_LoaderSpeedLoad.AddString(_T("0"));
	m_LoaderSpeedLoad.AddString(_T("1"));
	m_LoaderSpeedLoad.AddString(_T("2"));
	m_LoaderSpeedUnload.AddString(_T("0"));
	m_LoaderSpeedUnload.AddString(_T("1"));
	m_LoaderSpeedUnload.AddString(_T("2"));
	m_LoaderOptionsLoad.AddString(_T("0"));
	m_LoaderOptionsLoad.AddString(_T("1"));
	m_LoaderOptionsLoad.AddString(_T("2"));
	m_LoaderOptionsLoad.AddString(_T("3"));
	m_LoaderOptionsLoad.AddString(_T("4"));
	m_LoaderOptionsLoad.AddString(_T("5"));
	m_LoaderOptionsLoad.AddString(_T("6"));
	m_LoaderOptionsLoad.AddString(_T("7"));
	m_LoaderOptionsUnload.AddString(_T("0"));
	m_LoaderOptionsUnload.AddString(_T("1"));
	m_LoaderOptionsUnload.AddString(_T("2"));
	m_LoaderOptionsUnload.AddString(_T("3"));
	m_LoaderOptionsUnload.AddString(_T("4"));
	m_LoaderOptionsUnload.AddString(_T("5"));
	m_LoaderOptionsUnload.AddString(_T("6"));
	m_LoaderOptionsUnload.AddString(_T("7"));
	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CMFCApplication1Dlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
		m_Centrifuge.AboutBox();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CMFCApplication1Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CMFCApplication1Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CMFCApplication1Dlg::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	if (!m_usbAccessCentrifuge) {
		VARIANT vProfiles = m_Centrifuge.EnumerateProfiles();
		SAFEARRAY* psa = vProfiles.parray;
		BSTR* bstrArray;
		if (FAILED(SafeArrayAccessData(psa, reinterpret_cast<void**>(&bstrArray)))) {
			VariantClear(&vProfiles);
			MessageBox(_T("请先将数据线连接设备"), _T("初始化错误"));
			m_usbAccessCentrifuge = FALSE;
			return;
		}
		for (ULONG i = 0;i < psa->rgsabound[0].cElements;++i) {
			MessageBox(CString(bstrArray[i]));
		}
		SafeArrayUnaccessData(psa);
		VariantClear(&vProfiles);
		m_Centrifuge.Initialize(*(bstrArray));
	}
	else {
		MessageBox(_T("已经连接"), _T("未将上次连接关闭再次连接"));
	}
	
}
BEGIN_EVENTSINK_MAP(CMFCApplication1Dlg, CDialogEx)
	ON_EVENT(CMFCApplication1Dlg, IDC_CENTRIFUGECTRL1, DISPID_ERROREVENT, CMFCApplication1Dlg::ErrorCentrifugectrl1, VTS_I2 VTS_PBSTR VTS_I4 VTS_BSTR VTS_BSTR VTS_I4 VTS_PBOOL)
	ON_EVENT(CMFCApplication1Dlg, IDC_CENTRIFUGECTRL1, 1, CMFCApplication1Dlg::InitializeCompleteCentrifugectrl1, VTS_NONE)
	ON_EVENT(CMFCApplication1Dlg, IDC_CENTRIFUGECTRL1, 2, CMFCApplication1Dlg::CloseCompleteCentrifugectrl1, VTS_NONE)
	ON_EVENT(CMFCApplication1Dlg, IDC_CENTRIFUGECTRL1, 3, CMFCApplication1Dlg::OpenDoorCompleteCentrifugectrl1, VTS_I2)
	ON_EVENT(CMFCApplication1Dlg, IDC_CENTRIFUGECTRL1, 4, CMFCApplication1Dlg::CloseDoorCompleteCentrifugectrl1, VTS_NONE)
	ON_EVENT(CMFCApplication1Dlg, IDC_CENTRIFUGECTRL1, 5, CMFCApplication1Dlg::SpinCycleCompleteCentrifugectrl1, VTS_I2)
	ON_EVENT(CMFCApplication1Dlg, IDC_CENTRIFUGECTRL1, 6, CMFCApplication1Dlg::StopSpinCycleCompleteCentrifugectrl1, VTS_I2)
	ON_EVENT(CMFCApplication1Dlg, IDC_VSPINACCESS2CTRL5, DISPID_ERROREVENT, CMFCApplication1Dlg::ErrorVspinaccess2ctrl5, VTS_I2 VTS_PBSTR VTS_I4 VTS_BSTR VTS_BSTR VTS_I4 VTS_PBOOL)
	ON_EVENT(CMFCApplication1Dlg, IDC_VSPINACCESS2CTRL5, 1, CMFCApplication1Dlg::InitializeCompleteVspinaccess2ctrl5, VTS_NONE)
	ON_EVENT(CMFCApplication1Dlg, IDC_VSPINACCESS2CTRL5, 2, CMFCApplication1Dlg::CloseCompleteVspinaccess2ctrl5, VTS_NONE)
	ON_EVENT(CMFCApplication1Dlg, IDC_VSPINACCESS2CTRL5, 3, CMFCApplication1Dlg::ControllerMessageVspinaccess2ctrl5, VTS_I8 VTS_I4 VTS_I4 VTS_BSTR VTS_I4 VTS_I4 VTS_I4 VTS_I4)
	ON_EVENT(CMFCApplication1Dlg, IDC_VSPINACCESS2CTRL5, 4, CMFCApplication1Dlg::HomeCompleteVspinaccess2ctrl5, VTS_NONE)
	ON_EVENT(CMFCApplication1Dlg, IDC_VSPINACCESS2CTRL5, 5, CMFCApplication1Dlg::ParkCompleteVspinaccess2ctrl5, VTS_NONE)
	ON_EVENT(CMFCApplication1Dlg, IDC_VSPINACCESS2CTRL5, 6, CMFCApplication1Dlg::OpenDoorCompleteVspinaccess2ctrl5, VTS_I2)
	ON_EVENT(CMFCApplication1Dlg, IDC_VSPINACCESS2CTRL5, 7, CMFCApplication1Dlg::LoadPlateCompleteVspinaccess2ctrl5, VTS_I2)
	ON_EVENT(CMFCApplication1Dlg, IDC_VSPINACCESS2CTRL5, 8, CMFCApplication1Dlg::UnloadPlateCompleteVspinaccess2ctrl5, VTS_I2)
	ON_EVENT(CMFCApplication1Dlg, IDC_VSPINACCESS2CTRL5, 9, CMFCApplication1Dlg::SpinCycleCompleteVspinaccess2ctrl5, VTS_I2)
	ON_EVENT(CMFCApplication1Dlg, IDC_VSPINACCESS2CTRL5, 10, CMFCApplication1Dlg::CloseDoorCompleteVspinaccess2ctrl5, VTS_NONE)
	ON_EVENT(CMFCApplication1Dlg, IDC_VSPINACCESS2CTRL5, 11, CMFCApplication1Dlg::StopSpinCycleCompleteVspinaccess2ctrl5, VTS_I2)
END_EVENTSINK_MAP()


void CMFCApplication1Dlg::ErrorCentrifugectrl1(short Number, BSTR* Description, long Scode, LPCTSTR Source, LPCTSTR HelpFile, long HelpContext, BOOL* CancelDisplay)
{
	// TODO: 在此处添加消息处理程序代码
	CString str = m_Centrifuge.GetLastError();
	MessageBox(str, _T("出现错误"));
}


void CMFCApplication1Dlg::InitializeCompleteCentrifugectrl1()
{
	// TODO: 在此处添加消息处理程序代码
	m_usbAccessCentrifuge = TRUE;
	MessageBox(_T("初始化成功"));
}


void CMFCApplication1Dlg::CloseCompleteCentrifugectrl1()
{
	// TODO: 在此处添加消息处理程序代码
	m_usbAccessCentrifuge = FALSE;
	MessageBox(_T("已经断开连接"));
}


void CMFCApplication1Dlg::OpenDoorCompleteCentrifugectrl1(short bucket_num)
{
	// TODO: 在此处添加消息处理程序代码
	m_centrifuge_isOpened = TRUE;
	MessageBox(_T("已经开门"));
}


void CMFCApplication1Dlg::CloseDoorCompleteCentrifugectrl1()
{
	// TODO: 在此处添加消息处理程序代码
	m_centrifuge_isOpened = FALSE;
	MessageBox(_T("已经关门"));
}


void CMFCApplication1Dlg::SpinCycleCompleteCentrifugectrl1(short bucket_num)
{
	// TODO: 在此处添加消息处理程序代码
	m_centrifuge_isSpinning = TRUE;
	MessageBox(_T("开始搅拌"));
}


void CMFCApplication1Dlg::StopSpinCycleCompleteCentrifugectrl1(short bucket_num)
{
	// TODO: 在此处添加消息处理程序代码
	m_centrifuge_isSpinning = FALSE;
	MessageBox(_T("停止搅拌"));
}




void CMFCApplication1Dlg::OnCbnSelchangeBucketNum()
{

	// TODO: 在此添加控件通知处理程序代码

	int i = m_combo1.GetCurSel();
	CString str;
	m_combo1.GetLBText(i, str);
	m_bucketNum1 = _ttoi(str);
	

}


void CMFCApplication1Dlg::OnBnClickedOpenDoor1()
{
	// TODO: 在此添加控件通知处理程序代码
	//UpdateData();
	CString text;
	GetDlgItemText(IDC_COMBO1, text);
	m_bucketNum1 = _ttoi(text);
	if (!m_centrifuge_isOpened) {
		if (!m_usbAccessCentrifuge) {
			MessageBox(_T("未连接"));
			return;
		}
		if (m_Centrifuge.OpenDoor(m_bucketNum1)) {
			MessageBox(_T("开门失败"));
		}
	}
	
}


void CMFCApplication1Dlg::OnCbnSelchangeCombo2()
{
	// TODO: 在此添加控件通知处理程序代码
	/*
	When TIMER_MODE_TIME_TOTAL=0, the 
	entire Centrifuge cycle takes time
	seconds. 
	 When TIMER_MODE_TIME_AT_SPEED=1, 
	the Microplate Centrifuge spends 
	time seconds at full speed.
	 When TIMER_MODE_CONTINUOUS__SPIN
	=2, the Microplate Centrifuge will 
	spin continuously until 
	StopSpinCycle method is called
	*/
	int i = m_centrifuge_combTimeMode.GetCurSel();
	CString str;
	m_centrifuge_combTimeMode.GetLBText(i, str);
	m_centrifuge_timer_mode = _ttoi(str);
}

//参数设置响应函数
void CMFCApplication1Dlg::OnBnClickedButton9()
{
	// TODO: 在此添加控件通知处理程序代码
	CString text;
	GetDlgItemText(IDC_EDIT2, text);
	m_centrifuge_velPerc = _ttof(text);
	GetDlgItemText(IDC_EDIT3, text);
	m_centrifuge_accelPerc = _ttof(text);
	GetDlgItemText(IDC_EDIT4, text);
	m_centrifuge_decelPerc = _ttof(text);
	GetDlgItemText(IDC_COMBO2, text);
	m_centrifuge_timer_mode = _ttoi(text);
	GetDlgItemText(IDC_EDIT5, text);
	m_centrifuge_time = _ttoi(text);
}

//振动响应函数
void CMFCApplication1Dlg::OnBnClickedButton6()
{
	//判断是否连接
	if (!m_usbAccessCentrifuge) {
		MessageBox(_T("请先连接"));
		return;
	}
	//判断参数是否设置
	if (!m_centrifuge_velPerc) {
		MessageBox(_T("速度未设置"));
		return;
	}
	if (!m_centrifuge_accelPerc) {
		MessageBox(_T("加速度未设置"));
		return;
	}
	if (!m_centrifuge_decelPerc) {
		MessageBox(_T("减速度未设置"));
		return;
	}
	if (m_centrifuge_timer_mode == 3) {
		MessageBox(_T("定时模式未设置"));
		return;
	}
	if (!m_centrifuge_time) {
		MessageBox(_T("振动频率未设置"));
		return;
	}
	//开始转动
	//UpdateData();
	if (m_Centrifuge.SpinCycle(m_centrifuge_velPerc,
		m_centrifuge_accelPerc,
		m_centrifuge_decelPerc,
		m_centrifuge_timer_mode,
		m_centrifuge_time,
		m_bucketNum1)) {
		MessageBox(_T("申请振动失败"));
	}
}

//停止振动
void CMFCApplication1Dlg::OnBnClickedButton7()
{
	// TODO: 在此添加控件通知处理程序代码
	if (!m_usbAccessCentrifuge) {
		MessageBox(_T("请先连接"));
		return;
	}
	if (m_centrifuge_isSpinning) {
		if (m_Centrifuge.StopSpinCycle(m_bucketNum1)) {
			MessageBox(_T("申请停止振动失败"));
		}
	}
}

//关门响应函数
void CMFCApplication1Dlg::OnBnClickedButton10()
{
	// TODO: 在此添加控件通知处理程序代码
	if (!m_usbAccessCentrifuge) {
		MessageBox(_T("请先连接"));
		return;
	}
	if (m_centrifuge_isOpened) {
		if (m_Centrifuge.CloseDoor()) {
			MessageBox(_T("申请关门失败"));
		}
	}
}

//
void CMFCApplication1Dlg::OnBnClickedButton4()
{
	// Retries the last action after an error occurred.
	if (!m_usbAccessCentrifuge) {
		MessageBox(_T("请先连接"));
		return;
	}
	m_Centrifuge.Retry();

}


void CMFCApplication1Dlg::OnBnClickedButton5()
{
	// TODO: 在此添加控件通知处理程序代码
	m_Centrifuge.ShowDiagsDialog(VARIANT_TRUE, 0);
}


void CMFCApplication1Dlg::ErrorVspinaccess2ctrl5(short Number, BSTR* Description, long Scode, LPCTSTR Source, LPCTSTR HelpFile, long HelpContext, BOOL* CancelDisplay)
{
	// TODO: 在此处添加消息处理程序代码
	CString str((LPCTSTR)Description);
	MessageBox(str, _T("出现错误"));
}


void CMFCApplication1Dlg::InitializeCompleteVspinaccess2ctrl5()
{
	// TODO: 在此处添加消息处理程序代码
	m_usbAccessCentrifugeLoader = TRUE;
	MessageBox(_T("连接成功"));
}


void CMFCApplication1Dlg::CloseCompleteVspinaccess2ctrl5()
{
	// TODO: 在此处添加消息处理程序代码
	m_usbAccessCentrifugeLoader = FALSE;
	MessageBox(_T("成功断开连接"));
}


void CMFCApplication1Dlg::ControllerMessageVspinaccess2ctrl5(LONGLONG timestamp_ft, long timestamp_us, long message_type, LPCTSTR message, long info_type, long info_value1, long info_value2, long info_value3)
{
	// TODO: 在此处添加消息处理程序代码
	
}


void CMFCApplication1Dlg::HomeCompleteVspinaccess2ctrl5()
{
	// TODO: 在此处添加消息处理程序代码
	MessageBox(_T("成功安置装载机"));

}


void CMFCApplication1Dlg::ParkCompleteVspinaccess2ctrl5()
{
	// TODO: 在此处添加消息处理程序代码
	MessageBox(_T("成功停止装载机"));
}


void CMFCApplication1Dlg::OpenDoorCompleteVspinaccess2ctrl5(short bucket_num)
{
	// TODO: 在此处添加消息处理程序代码
	m_loader_doorIsOpened = TRUE;
	MessageBox(_T("开门成功"));
}


void CMFCApplication1Dlg::LoadPlateCompleteVspinaccess2ctrl5(short bucket_num)
{
	// TODO: 在此处添加消息处理程序代码
	switch (m_loader_bucket_num) {
	case 1:
		m_ProgressCtrl1.SetPos(100);
		break;
	case 2:
		m_ProgressCtrl2.SetPos(100);
		break;
	}
}


void CMFCApplication1Dlg::UnloadPlateCompleteVspinaccess2ctrl5(short bucket_num)
{
	// TODO: 在此处添加消息处理程序代码
	switch (m_loader_bucket_num) {
	case 1:
		m_ProgressCtrl1.SetPos(0);
	case 2:
		m_ProgressCtrl2.SetPos(0);
	}
}


void CMFCApplication1Dlg::SpinCycleCompleteVspinaccess2ctrl5(short bucket_num)
{
	// TODO: 在此处添加消息处理程序代码
	m_loaderisSpinning = TRUE;
	MessageBox(_T("loader成功振动"));
}


void CMFCApplication1Dlg::CloseDoorCompleteVspinaccess2ctrl5()
{
	// TODO: 在此处添加消息处理程序代码
	m_loader_doorIsOpened = FALSE;
	MessageBox(_T("关门成功"));
}


void CMFCApplication1Dlg::StopSpinCycleCompleteVspinaccess2ctrl5(short bucket_num)
{
	// TODO: 在此处添加消息处理程序代码
	m_loaderisSpinning = FALSE;
	MessageBox(_T("loader成功停止振动"));
}

//centrifugeloader 诊断窗口响应函数
void CMFCApplication1Dlg::OnBnClickedButton12()
{
	// TODO: 在此添加控件通知处理程序代码
	m_CentrifugeLoader.ShowDiagsDialog(VARIANT_TRUE, 0);
}

//centrifugeloader 重试响应函数
void CMFCApplication1Dlg::OnBnClickedButton11()
{
	// TODO: 在此添加控件通知处理程序代码
	if (!m_usbAccessCentrifuge) {
		MessageBox(_T("请先连接"));
		return;
	}
	m_CentrifugeLoader.Retry();
}



void CMFCApplication1Dlg::OnBnClickedCentrifugeLoaderInit()
{
	// TODO: 在此添加控件通知处理程序代码
	if (!m_usbAccessCentrifugeLoader) {
		VARIANT vProfiles = m_CentrifugeLoader.EnumerateProfiles();
		SAFEARRAY* psa = vProfiles.parray;
		BSTR* bstrArray;
		if (FAILED(SafeArrayAccessData(psa, reinterpret_cast<void**>(&bstrArray)))) {
			VariantClear(&vProfiles);
			MessageBox(_T("请先将数据线连接设备"), _T("初始化错误"));
			m_usbAccessCentrifugeLoader = FALSE;
			return;
		}
		for (ULONG i = 0;i < psa->rgsabound[0].cElements;++i) {
			MessageBox(CString(bstrArray[i]));
		}
		SafeArrayUnaccessData(psa);
		VariantClear(&vProfiles);
		m_CentrifugeLoader.Initialize(*(bstrArray));
	}
	else {
		MessageBox(_T("已经连接"), _T("未将上次连接关闭再次连接"));
	}
}

//centrifugeloader 断开连接
void CMFCApplication1Dlg::OnBnClickedCentrifugeLoaderDisconnect()
{
	// TODO: 在此添加控件通知处理程序代码
	if (m_usbAccessCentrifugeLoader)m_Centrifuge.Close();
}

//
void CMFCApplication1Dlg::OnBnClickedCentrifugeDisconnect()
{
	// TODO: 在此添加控件通知处理程序代码
	if (m_usbAccessCentrifuge)m_Centrifuge.Close();
}

//选择改变centrifugeloader的bucketnum
void CMFCApplication1Dlg::OnCbnSelchangeCombo3()
{
	// TODO: 在此添加控件通知处理程序代码
	CString text;
	GetDlgItemText(IDC_COMBO3, text);
	m_loader_bucket_num = _ttoi(text);
}

//centrifugeloader赤天开门
void CMFCApplication1Dlg::OnBnClickedButton2()
{
	// TODO: 在此添加控件通知处理程序代码
	if (!m_usbAccessCentrifugeLoader) {
		MessageBox(_T("请先连接"), _T("发生错误"));
		return;
	}
	if (!m_loader_bucket_num) {
		MessageBox(_T("请设置centrifugeloader"));
		return;
	}
	if (m_CentrifugeLoader.OpenDoor(m_loader_bucket_num)) {
		m_loader_doorIsOpened = FALSE;
	}
}

//centrifugeloader 关门
void CMFCApplication1Dlg::OnBnClickedLoaderCloseDoor()
{
	// TODO: 在此添加控件通知处理程序代码
	if (!m_usbAccessCentrifugeLoader) {
		MessageBox(_T("请先连接"), _T("发生错误"));
		return;
	}
	if (m_loader_doorIsOpened) {
		if (m_CentrifugeLoader.CloseDoor()) {
			m_loader_doorIsOpened = TRUE;
		}
	}

}

//home响应函数
void CMFCApplication1Dlg::OnBnClickedButton19()
{
	// TODO: 在此添加控件通知处理程序代码
	if (!m_usbAccessCentrifugeLoader) {
		MessageBox(_T("请先连接"), _T("发生错误"));
		return;
	}
	m_CentrifugeLoader.Home();
}

//park响应函数


void CMFCApplication1Dlg::OnBnClickedButton15()
{
	// TODO: 在此添加控件通知处理程序代码
	if (!m_usbAccessCentrifugeLoader) {
		MessageBox(_T("请先连接"), _T("发生错误"));
		return;
	}
	m_CentrifugeLoader.Park();
}

//加载货物
void CMFCApplication1Dlg::OnBnClickedCentrifugeLoaderLoadPlate()
{
	
	// TODO: 在此添加控件通知处理程序代码
	if (!m_usbAccessCentrifugeLoader) {
		MessageBox(_T("请先连接"), _T("发生错误"));
		return;
	}
	if (!m_loader_bucket_num) {
		MessageBox(_T("请先设置bucket"), _T("参数缺省"));
		return;
	}
	m_CentrifugeLoader.LoadPlate(m_loader_bucket_num,
		m_gripperOffset,
		m_plateHeight,
		m_speed,
		m_options);
}

//更新参数响应函数
void CMFCApplication1Dlg::OnBnClickedButton24()
{
	// TODO: 在此添加控件通知处理程序代码
	CString str;
	GetDlgItemText(IDC_EDIT1, str);
	m_gripperOffset = _ttof(str);
	GetDlgItemText(IDC_EDIT6, str);
	m_plateHeight = _ttof(str);
	GetDlgItemText(IDC_COMBO4, str);
	m_speed = _ttoi(str);
	GetDlgItemText(IDC_COMBO5, str);
	m_options = _ttoi(str);
}


void CMFCApplication1Dlg::OnBnClickedLoaderUnloadPlate()
{
	// TODO: 在此添加控件通知处理程序代码
	if (!m_usbAccessCentrifugeLoader) {
		MessageBox(_T("请先连接"), _T("发生错误"));
		return;
	}
	if (!m_loader_bucket_num) {
		MessageBox(_T("请先设置bucket"), _T("参数缺省"));
		return;
	}
	m_CentrifugeLoader.UnloadPlate(m_loader_bucket_num,
		m_gripperOffset,
		m_plateHeight,
		m_speed,
		m_options);
}

//centrifugeloader 的参数更新
void CMFCApplication1Dlg::OnBnClickedButton25()
{
	// TODO: 在此添加控件通知处理程序代码
	CString str;
	GetDlgItemText(IDC_EDIT7, str);
	m_loaderVel = _ttof(str);
	GetDlgItemText(IDC_EDIT8, str);
	m_loaderAccel = _ttof(str);
	GetDlgItemText(IDC_EDIT9, str);
	m_loaderDecel = _ttof(str);
	GetDlgItemText(IDC_COMBO6, str);
	m_loaderTimeMode = _ttol(str);
	GetDlgItemText(IDC_EDIT10, str);
	m_loaderTime = _ttol(str);
	GetDlgItemText(IDC_COMBO7, str);
	m_loaderBucketLoad = _ttol(str);
	GetDlgItemText(IDC_COMBO8, str);
	m_loaderBucketUnload = _ttol(str);
	GetDlgItemText(IDC_EDIT11, str);
	m_loaderOffsetLoad = _ttof(str);
	GetDlgItemText(IDC_EDIT12, str);
	m_loaderOffsetUnload = _ttof(str);
	GetDlgItemText(IDC_EDIT13, str);
	m_loaderHeightLoad = _ttof(str);
	GetDlgItemText(IDC_EDIT14, str);
	m_loaderHeightUnload = _ttof(str);
	GetDlgItemText(IDC_COMBO9, str);
	m_loaderSpeedLoad = _ttoi(str);
	GetDlgItemText(IDC_COMBO10, str);
	m_loaderSpeedUnload = _ttoi(str);
	GetDlgItemText(IDC_COMBO11, str);
	m_loaderOptionsLoad = _ttoi(str);
	GetDlgItemText(IDC_COMBO12, str);
	m_loaderOptionsUnload = _ttoi(str);
}




void CMFCApplication1Dlg::OnCentrifugeLoaderSpinCycle()
{
	// TODO: 在此添加控件通知处理程序代码
	if (!m_usbAccessCentrifugeLoader) {
		MessageBox(_T("请先连接"));
		return;
	}
	if (m_CentrifugeLoader.SpinCycle(m_loaderVel,
		m_loaderAccel,
		m_loaderDecel,
		m_loaderTimeMode,
		m_loaderTime,
		m_loaderBucketLoad,
		m_loaderBucketUnload,
		m_loaderOffsetLoad,
		m_loaderOffsetUnload,
		m_loaderHeightLoad,
		m_loaderHeightUnload,
		m_loaderSpeedLoad,
		m_loaderSpeedUnload,
		m_loaderOptionsLoad,
		m_loaderOptionsUnload
	)) {
		m_loaderisSpinning = FALSE;
	}
}


void CMFCApplication1Dlg::OnCentrifugeLoaderStopSpinCycle()
{
	// TODO: 在此添加控件通知处理程序代码
	if (!m_usbAccessCentrifugeLoader) {
		MessageBox(_T("请先连接"), _T("出现错误"));
		return;
	}
	if (m_loaderisSpinning) {
		if (m_CentrifugeLoader.StopSpinCycle(m_loader_bucket_num)) {
			m_loaderisSpinning = TRUE;
		}
	}
}


void CMFCApplication1Dlg::OnBnClickedButton26()
{
	// TODO: 在此添加控件通知处理程序代码
	m_Centrifuge.Ignore();
}


void CMFCApplication1Dlg::OnBnClickedButton27()
{
	// TODO: 在此添加控件通知处理程序代码
	m_Centrifuge.Abort();
}


void CMFCApplication1Dlg::OnBnClickedButton28()
{
	// TODO: 在此添加控件通知处理程序代码
	m_CentrifugeLoader.Ignore();
}


void CMFCApplication1Dlg::OnBnClickedButton29()
{
	// TODO: 在此添加控件通知处理程序代码
	m_CentrifugeLoader.Abort();
}

