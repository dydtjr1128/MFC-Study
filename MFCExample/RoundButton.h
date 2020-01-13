#pragma once
#ifndef UI_ROUND_BUTTON_H
#define UI_ROUND_BUTTON_H

class RoundButton : public CButton {
public:
	RoundButton();
	virtual ~RoundButton();
	void SetBackgroundColor(int a, int r, int g, int b);
	void SetBorderColor(int a, int r, int g, int b);
	void SetTextColor(int a, int r, int g, int b);
	void SetFontSize(float size);
	void SetBorderRadius(float radius);
	void SetText(const CString& text);
private:
	Gdiplus::Color backgroundColor_; // 배경 색상. 
	Gdiplus::Color borderColor_; // 외곽선 색상. 
	Gdiplus::Color textColor_; // 텍스트 색상. 
	float fontSize_; // 텍스트 크기. 
	CString text_; // 문자열. 
	UINT8 radius_;
	
	void DrawBackground(Gdiplus::Graphics& pG); // 배경 그리기.
	void FillRoundRectangle(Gdiplus::Graphics& pG, CRect rect, Gdiplus::Brush& p, UINT8 radius);
	void DrawPressedBackground(Gdiplus::Graphics& pG);
	void DrawBorder(Gdiplus::Graphics& pG); // 외곽선 그리기.
	void DrawRoundRectangle(Gdiplus::Graphics& pG, CRect& rect, Gdiplus::Pen& p, UINT8 radius);
	void DrawText(Gdiplus::Graphics& pG); // 텍스트 그리기.
public:
	DECLARE_MESSAGE_MAP()
	afx_msg void OnPaint() ;
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonDblClk(UINT nFlags, CPoint point);
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
};

#endif // !UI_ROUND_BUTTON_H
