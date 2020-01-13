#include "pch.h"
#include "RoundButton.h"

RoundButton::RoundButton() :
	radius_(15)
{	
	SetBackgroundColor(255, 64, 64, 64);
	SetBorderColor(255, 128, 128, 128);
	SetTextColor(255, 20, 20, 20);
	SetFontSize(15);
	SetText(_T("Button"));
}

RoundButton::~RoundButton()
{
}

void RoundButton::SetBackgroundColor(int a, int r, int g, int b)
{
	backgroundColor_ = Gdiplus::Color(a,r,g,b);
}

void RoundButton::SetBorderColor(int a, int r, int g, int b)
{
	borderColor_ = Gdiplus::Color(a, r, g, b);
}

void RoundButton::SetTextColor(int a, int r, int g, int b)
{
	textColor_ = Gdiplus::Color(a, r, g, b);
}

void RoundButton::SetFontSize(float size)
{
	fontSize_ = size;
}

void RoundButton::SetBorderRadius(float radius)
{
}

void RoundButton::SetText(const CString& text)
{
	text_ = text;
}

void RoundButton::DrawBackground(Gdiplus::Graphics& pG)
{
	CRect rect;
	GetClientRect(&rect);

	//Gdiplus::SolidBrush brush(backgroundColor_);
	Gdiplus::LinearGradientBrush brush(
		Gdiplus::Rect(rect.left, rect.top, rect.right, rect.bottom),
		Gdiplus::Color(128,221,236,255),
		Gdiplus::Color(255, 86, 125, 204),
		45.0f,
		FALSE
	);
	FillRoundRectangle(pG, rect, brush, radius_);

	//pG.FillRectangle(&brush, rect.left, rect.top, rect.right, rect.bottom);
}

void RoundButton::FillRoundRectangle(Gdiplus::Graphics& pG, CRect rect, Gdiplus::Brush& p, UINT8 radius)
{		
	Gdiplus::GraphicsPath path;

	path.AddLine(rect.left + radius, rect.top, rect.left + rect.Width() - (radius * 2), rect.top);
	path.AddArc(rect.left + rect.Width() - (radius * 2), rect.top, radius * 2, radius * 2, 270, 90);
	path.AddLine(rect.left + rect.Width(), rect.top + radius, rect.left + rect.Width(), rect.top + rect.Height() - (radius * 2));
	path.AddArc(rect.left + rect.Width() - (radius * 2), rect.top + rect.Height() - (radius * 2), radius * 2, radius * 2, 0, 90);
	path.AddLine(rect.left + rect.Width() - (radius * 2), rect.top + rect.Height(), rect.left + radius, rect.top + rect.Height());
	path.AddArc(rect.left, rect.top + rect.Height() - (radius * 2), radius * 2, radius * 2, 90, 90);
	path.AddLine(rect.left, rect.top + rect.Height() - (radius * 2), rect.left, rect.top + radius);
	path.AddArc(rect.left, rect.top, radius * 2, radius * 2, 180, 90);
	path.CloseFigure();

	pG.FillPath(&p, &path);
}

void RoundButton::DrawPressedBackground(Gdiplus::Graphics& pG)
{
	CRect rect;
	GetClientRect(&rect);

	Gdiplus::LinearGradientBrush brush(
		Gdiplus::Rect(rect.left, rect.top, rect.right, rect.bottom),
		Gdiplus::Color(128, 21, 236, 255),
		Gdiplus::Color(255, 66, 125, 204),
		45.0f,
		FALSE
	);
	pG.FillRectangle(&brush, rect.left, rect.top, rect.right, rect.bottom);
}

void RoundButton::DrawBorder(Gdiplus::Graphics& pG)
{
	CRect rect;
	GetClientRect(&rect);
	Gdiplus::Pen pen(borderColor_, 3);
	DrawRoundRectangle(pG, rect, pen, radius_);
	//pG.DrawRectangle(&pen, rect.left, rect.top, rect.Width(), rect.Height());
}

void RoundButton::DrawRoundRectangle(Gdiplus::Graphics& pG, CRect& rect, Gdiplus::Pen& p, UINT8 radius)
{
	Gdiplus::GraphicsPath path;
	path.AddLine(rect.left + radius, rect.top, rect.left + rect.Width() - (radius * 2), rect.top);
	path.AddArc(rect.left + rect.Width() - (radius * 2), rect.top, radius * 2, radius * 2, 270, 90);
	//path.AddLine(rect.left + rect.Width(), rect.top + radius, rect.left + rect.Width(), rect.top + rect.Height() - (radius * 2));
	path.AddArc(rect.left + rect.Width() - (radius * 2), rect.top + rect.Height() - (radius * 2), radius * 2, radius * 2, 0, 90);
	path.AddLine(rect.left + rect.Width() - (radius * 2), rect.top + rect.Height(), rect.left + radius, rect.top + rect.Height());
	path.AddArc(rect.left, rect.top + rect.Height() - (radius * 2), radius * 2, radius * 2, 90, 90);
	//path.AddLine(rect.left, rect.top + rect.Height() - (radius * 2), rect.left, rect.top + radius);
	path.AddArc(rect.left, rect.top, radius * 2, radius * 2, 180, 90);

	path.CloseFigure();
	pG.DrawPath(&p, &path);
}

void RoundButton::DrawText(Gdiplus::Graphics& pG)
{
	CRect rect;
	GetClientRect(&rect);

	Gdiplus::FontFamily fontfam(_T("D2Coding"));
	Gdiplus::Font font(&fontfam, fontSize_, Gdiplus::FontStyleRegular, Gdiplus::UnitPixel);

	Gdiplus::StringFormat stringAlign;
	stringAlign.SetAlignment(Gdiplus::StringAlignmentCenter);
	stringAlign.SetLineAlignment(Gdiplus::StringAlignmentCenter);

	Gdiplus::SolidBrush brush(textColor_);

	pG.DrawString(text_, text_.GetLength(), &font,
		Gdiplus::RectF((float)rect.left, (float)rect.top, (float)rect.Width(), (float)rect.Height()), &stringAlign, &brush);
}
BEGIN_MESSAGE_MAP(RoundButton, CButton)
	ON_WM_PAINT()
	ON_WM_LBUTTONUP()
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONDBLCLK()
	ON_WM_ERASEBKGND()
	ON_WM_CREATE()
END_MESSAGE_MAP()


void RoundButton::OnPaint()
{
	CPaintDC dc(this);
	
	CRect rect;
	GetClientRect(&rect);

	Gdiplus::Graphics mainG(dc.GetSafeHdc());

	//Gdiplus::Bitmap bmp(rect.Width(), rect.Height());

	//Gdiplus::Graphics memG(&bmp);
	mainG.SetSmoothingMode(Gdiplus::SmoothingModeHighQuality);

	mainG.Clear(Gdiplus::Color(255, 255, 255, 255));
	
	DrawBackground(mainG);
	//DrawBorder(mainG);
	DrawText(mainG);
	//mainG.DrawImage(&bmp, 0, 0);
}


void RoundButton::OnLButtonUp(UINT nFlags, CPoint point)
{
	CPaintDC dc(this);
	Gdiplus::Graphics mainG(dc.GetSafeHdc());
	
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.

	UINT id = this->GetDlgCtrlID();
	LPARAM lParam = (LPARAM)GetDlgItem(id);
	WPARAM wParam = MAKEWPARAM(id, WM_LBUTTONUP);
	::SendMessage(GetParent()->GetSafeHwnd(), WM_COMMAND,
		wParam,
		lParam);
	DrawBackground(mainG);
	//CButton::OnLButtonUp(nFlags, point);
}


void RoundButton::OnLButtonDown(UINT nFlags, CPoint point)
{
	CPaintDC dc(this);
	Gdiplus::Graphics mainG(dc.GetSafeHdc());		
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	DrawPressedBackground(mainG);

	UINT id = this->GetDlgCtrlID();
	LPARAM lParam = (LPARAM)GetDlgItem(id);
	WPARAM wParam = MAKEWPARAM(id, WM_LBUTTONDOWN);
	::SendMessage(GetParent()->GetSafeHwnd(), WM_COMMAND,
		wParam,
		lParam);
	//CButton::OnLButtonDown(nFlags, point);
}


void RoundButton::OnLButtonDblClk(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.

	//CButton::OnLButtonDblClk(nFlags, point);
}


BOOL RoundButton::OnEraseBkgnd(CDC* pDC)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	return CButton::OnEraseBkgnd(pDC);
}


int RoundButton::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CButton::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  여기에 특수화된 작성 코드를 추가합니다.
	CPaintDC dc(this);

	CRect rect;
	GetClientRect(&rect);

	Gdiplus::Graphics mainG(dc.GetSafeHdc());

	Gdiplus::Bitmap bmp(rect.Width(), rect.Height());

	Gdiplus::Graphics memG(&bmp);

	return 0;
}
