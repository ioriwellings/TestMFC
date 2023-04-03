// TestMFC.cpp : Defines the class behaviors for the application.
//

#include "stdafx.h"
#include "TestMFC.h"

#include "MainFrm.h"
#include "ChildFrm.h"
#include "TestMFCDoc.h"
#include "TestMFCView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

//#pragma execution_character_set("gb2312")
#pragma setlocale(".936")

typedef struct _LISTROWINFO
{
	CPtrArray*		paryRowData;		//	与ListCtrl上显示的内容相一致
	CStringArray	straryExtRowData;	//	附加的内容，不在ListCtrl上显示出来
	CString			strOldCode;			//	旧代码，供代码可以修改的情况用
	int				iFormStatus;		//	FormChecked，FormCarriedOut等表单状态及其组合；
	BYTE			iOprStatus;			//	操作状态：ROW_INTACT,ROW_ADDED,ROW_UPDATED,ROW_DELETED
	int				iSumRow;			//	标示合计行,可以有小计和合计行，目前保留未用。
	double			nConvRate;			//  计量单位转换率 ADD BY CHENKD 2005-02-15
	CString         cBaseUnit;
	CString         strOldText;
	long double			dOldValue;
	COleDateTime	dtOldDate;
	long double			dPurchPriceButTax;
	long double			dPurchPirceTax;
	int				nOrderID;			//	2019-02-19
	CString			strWarehouseCode;	// 附加的仓库代码
	virtual ~_LISTROWINFO()
	{
		TRACE0("=========~LISTROWINFO=========\r\n");
	}
	public:
		virtual void TestMethod()
		{
		};
}LISTROWINFO;

/////////////////////////////////////////////////////////////////////////////
// CTestMFCApp

BEGIN_MESSAGE_MAP(CTestMFCApp, CWinApp)
	//{{AFX_MSG_MAP(CTestMFCApp)
	ON_COMMAND(ID_APP_ABOUT, OnAppAbout)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
	// Standard file based document commands
	ON_COMMAND(ID_FILE_NEW, CWinApp::OnFileNew)
	ON_COMMAND(ID_FILE_OPEN, CWinApp::OnFileOpen)
	// Standard print setup command
	ON_COMMAND(ID_FILE_PRINT_SETUP, CWinApp::OnFilePrintSetup)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTestMFCApp construction

CTestMFCApp::CTestMFCApp()
{
	// TODO: add construction code here,
	// Place all significant initialization in InitInstance
	for(int i=0;i<9999;i++)
	{
		LISTROWINFO *list = new LISTROWINFO;
		list->nOrderID = 100;
		list->strOldText = "中文abc";
	}
	printf("1111111");
	printf("中文ABC");
}

/////////////////////////////////////////////////////////////////////////////
// The one and only CTestMFCApp object

CTestMFCApp theApp;

/////////////////////////////////////////////////////////////////////////////
// CTestMFCApp initialization

BOOL CTestMFCApp::InitInstance()
{
	AfxEnableControlContainer();

	// Standard initialization
	// If you are not using these features and wish to reduce the size
	//  of your final executable, you should remove from the following
	//  the specific initialization routines you do not need.

#ifdef _AFXDLL
	Enable3dControls();			// Call this when using MFC in a shared DLL
#else
	Enable3dControlsStatic();	// Call this when linking to MFC statically
#endif

	// Change the registry key under which our settings are stored.
	// TODO: You should modify this string to be something appropriate
	// such as the name of your company or organization.
	SetRegistryKey(_T("Local AppWizard-Generated Applications"));

	LoadStdProfileSettings();  // Load standard INI file options (including MRU)

	// Register the application's document templates.  Document templates
	//  serve as the connection between documents, frame windows and views.

	CMultiDocTemplate* pDocTemplate;
	pDocTemplate = new CMultiDocTemplate(
		IDR_TESTMFTYPE,
		RUNTIME_CLASS(CTestMFCDoc),
		RUNTIME_CLASS(CChildFrame), // custom MDI child frame
		RUNTIME_CLASS(CTestMFCView));
	AddDocTemplate(pDocTemplate);

	// create main MDI Frame window
	CMainFrame* pMainFrame = new CMainFrame;
	if (!pMainFrame->LoadFrame(IDR_MAINFRAME))
		return FALSE;
	m_pMainWnd = pMainFrame;

	// Parse command line for standard shell commands, DDE, file open
	CCommandLineInfo cmdInfo;
	ParseCommandLine(cmdInfo);

	// Dispatch commands specified on the command line
	if (!ProcessShellCommand(cmdInfo))
		return FALSE;

	// The main window has been initialized, so show and update it.
	pMainFrame->ShowWindow(m_nCmdShow);
	pMainFrame->UpdateWindow();

	return TRUE;
}


/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
		// No message handlers
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
		// No message handlers
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

// App command to run the dialog
void CTestMFCApp::OnAppAbout()
{
	CAboutDlg aboutDlg;
	aboutDlg.DoModal();
}

/////////////////////////////////////////////////////////////////////////////
// CTestMFCApp message handlers

