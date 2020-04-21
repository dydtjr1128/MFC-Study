#include "pch.h"
#include "TrayIconControl.h"

void TrayIconControl::notifyIconSetFlag(NOTIFYICONDATA& data, int uflags)
{
	switch (uflags) {
		// 트레이에 등록
	case NIM_ADD:
		data.uFlags = NIF_MESSAGE | NIF_ICON | NIF_TIP;
		break;
		// 트레이에서 해제
	case NIM_DELETE:
		data.uFlags = 0;
		break;
		// 이미 등록된 정보를 변경
	case NIM_MODIFY:
		data.uFlags = NIF_TIP | NIF_ICON;
		break;
	}
}

void TrayIconControl::Initialize()
{
	notifyIconData_.cbSize = sizeof(notifyIconData_);
	notifyIconData_.hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	//notifyIconData_.hWnd = AfxGetApp()->hwnd
	notifyIconSetFlag(notifyIconData_, NIM_ADD);;;;;
	
}

TrayIconControl::TrayIconControl()
{
	Initialize();
}

TrayIconControl::~TrayIconControl()
{
}

void TrayIconControl::SetTrayIcon(BOOL isUseTray)
{
}

void TrayIconControl::SetTrayToolTip(std::string toolTipMessage)
{
}
