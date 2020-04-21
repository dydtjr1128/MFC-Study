#include "pch.h"
#include "TrayIconControl.h"

void TrayIconControl::notifyIconSetFlag(NOTIFYICONDATA& data, int uflags)
{
	switch (uflags) {
		// Ʈ���̿� ���
	case NIM_ADD:
		data.uFlags = NIF_MESSAGE | NIF_ICON | NIF_TIP;
		break;
		// Ʈ���̿��� ����
	case NIM_DELETE:
		data.uFlags = 0;
		break;
		// �̹� ��ϵ� ������ ����
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
