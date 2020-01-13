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
	Gdiplus::Color backgroundColor_; // ��� ����. 
	Gdiplus::Color borderColor_; // �ܰ��� ����. 
	Gdiplus::Color textColor_; // �ؽ�Ʈ ����. 
	float fontSize_; // �ؽ�Ʈ ũ��. 
	CString text_; // ���ڿ�. 
	UINT8 radius_;
	
	void DrawBackground(Gdiplus::Graphics& pG); // ��� �׸���.
	void FillRoundRectangle(Gdiplus::Graphics& pG, CRect rect, Gdiplus::Brush& p, UINT8 radius);
	void DrawPressedBackground(Gdiplus::Graphics& pG);
	void DrawBorder(Gdiplus::Graphics& pG); // �ܰ��� �׸���.
	void DrawRoundRectangle(Gdiplus::Graphics& pG, CRect& rect, Gdiplus::Pen& p, UINT8 radius);
	void DrawText(Gdiplus::Graphics& pG); // �ؽ�Ʈ �׸���.
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
