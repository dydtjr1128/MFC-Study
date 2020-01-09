
// MFCExampleDlg.cpp: 구현 파일
//

#include "pch.h"
#include "framework.h"
#include "MFCExample.h"
#include "MFCExampleDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

namespace {
	inline CString GetCrallwerStartButtonText() {
		CString btn;
		if (btn.LoadString(IDS_START_CRAWLLER)) {
			return btn;
		}
		return nullptr;
	}
}
// 응용 프로그램 정보에 사용되는 CAboutDlg 대화 상자입니다.

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

	// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

// 구현입니다.
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{

}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CMFCExampleDlg 대화 상자



CMFCExampleDlg::CMFCExampleDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MFCEXAMPLE_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFCExampleDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_START_CRAWLLER_BUTTON, CrawllerButton);
	DDX_Control(pDX, IDC_PROGRESS1, MainProgressbar);
}

BEGIN_MESSAGE_MAP(CMFCExampleDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_START_CRAWLLER_BUTTON, &CMFCExampleDlg::OnBnClickedStartCrawllerButton)
	ON_WM_GETMINMAXINFO()
	ON_WM_CTLCOLOR()
	ON_NOTIFY(NM_CUSTOMDRAW, IDC_PROGRESS1, &CMFCExampleDlg::OnNMCustomdrawProgress1)
END_MESSAGE_MAP()


// CMFCExampleDlg 메시지 처리기

BOOL CMFCExampleDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	//최소화 최대화 설정
	/*SetWindowLong(this->m_hWnd,
		GWL_STYLE,
		GetWindowLong(this->m_hWnd, GWL_STYLE) | WS_MINIMIZEBOX | WS_MAXIMIZEBOX);*/

	CString btn = GetCrallwerStartButtonText();
	CrawllerButton.SetWindowTextW(btn);
	SetWindowTextW(btn);

	progress = 0;
	/*MainProgressbar.SetBarColor(CLR_DEFAULT);
	MainProgressbar.SetBkColor(RGB(220, 255, 220));
	MainProgressbar.SetMarquee(TRUE, 1000);
	MainProgressbar.SetState(PBST_NORMAL);*/
	MainProgressbar.SetRange(0, 100); //프로그레스바의 범위를 0에서 300으로 설정
	MainProgressbar.SetPos(10);
	
//	CWnd* p_btn1 = GetDlgItem(IDC_PROGRESS1);


	// 시스템 메뉴에 "정보..." 메뉴 항목을 추가합니다.

	// IDM_ABOUTBOX는 시스템 명령 범위에 있어야 합니다.
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

	// 이 대화 상자의 아이콘을 설정합니다.  응용 프로그램의 주 창이 대화 상자가 아닐 경우에는
	//  프레임워크가 이 작업을 자동으로 수행합니다.
	SetIcon(m_hIcon, TRUE);			// 큰 아이콘을 설정합니다.
	SetIcon(m_hIcon, FALSE);		// 작은 아이콘을 설정합니다.

	// TODO: 여기에 추가 초기화 작업을 추가합니다.

	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
}

void CMFCExampleDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 대화 상자에 최소화 단추를 추가할 경우 아이콘을 그리려면
//  아래 코드가 필요합니다.  문서/뷰 모델을 사용하는 MFC 애플리케이션의 경우에는
//  프레임워크에서 이 작업을 자동으로 수행합니다.

void CMFCExampleDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 그리기를 위한 디바이스 컨텍스트입니다.

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 클라이언트 사각형에서 아이콘을 가운데에 맞춥니다.
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 아이콘을 그립니다.
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// 사용자가 최소화된 창을 끄는 동안에 커서가 표시되도록 시스템에서
//  이 함수를 호출합니다.
HCURSOR CMFCExampleDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void CALLBACK MyTimerProc(HWND hWnd, UINT nMsg, UINT_PTR nIDEvent, DWORD dwTime)
{
	CMFCExampleDlg* pWnd = (CMFCExampleDlg*)CWnd::FromHandle(hWnd);
	CRect rect;
	pWnd->GetDlgItem(IDC_PROGRESS_PERCENT)->GetWindowRect(&rect);
	pWnd->ScreenToClient(&rect);
	CString str;
	pWnd->InvalidateRect(rect);
	for (int i = 0; i < 30; i++) {	
		
		pWnd->MainProgressbar.OffsetPos(1);
		Sleep(20);
	}
	str.Format(_T("%d %%"), pWnd->MainProgressbar.GetPos());
	pWnd->GetDlgItem(IDC_PROGRESS_PERCENT)->SetWindowText(str);

	if (pWnd->MainProgressbar.GetPos() >= 100) {
		pWnd->KillTimer(pWnd->progress);
		pWnd->MainProgressbar.SetPos(0);
	}
}

void CMFCExampleDlg::OnBnClickedStartCrawllerButton()
{

	//MainProgressbar.OffsetPos(1); //프로그레스바 1씩 감소	
	SetTimer(progress, 1000, MyTimerProc);
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void CMFCExampleDlg::OnGetMinMaxInfo(MINMAXINFO* lpMMI)
{
	//min
	lpMMI->ptMinTrackSize.x = 330;
	lpMMI->ptMinTrackSize.y = 330;

	//max

	lpMMI->ptMaxTrackSize.x = 1600;
	lpMMI->ptMaxTrackSize.y = 900;

	CDialogEx::OnGetMinMaxInfo(lpMMI);
}


HBRUSH CMFCExampleDlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CDialogEx::OnCtlColor(pDC, pWnd, nCtlColor);
	UINT nID = pWnd->GetDlgCtrlID();
	

	if (nCtlColor == CTLCOLOR_STATIC) {		
		if (nID == IDC_PROGRESS_PERCENT) {			
			pDC->SetBkMode(OPAQUE);  // 바꿔준다
			//pDC->SetBkMode(TRANSPARENT); // 각 Static Text 배경 투명 변경 
										 //pDC->SetTextColor(RGB(0, 0, 0));
										 // 각 Static Text 글자 색 변경 
										 //pDC->SetBkColor(RGB(0, 128, 0)); 
										 // 각 Static Text 배경 색 변경 
			return (HBRUSH)::GetStockObject(NULL_BRUSH); 
		} 
	}



	return hbr;
}


void CMFCExampleDlg::OnNMCustomdrawProgress1(NMHDR* pNMHDR, LRESULT* pResult)
{
	LPNMCUSTOMDRAW pNMCD = reinterpret_cast<LPNMCUSTOMDRAW>(pNMHDR);
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	*pResult = 0;
}
