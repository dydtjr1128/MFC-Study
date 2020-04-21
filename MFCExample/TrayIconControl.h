#pragma once

#ifndef UI_TRAY_TRAY_ICON_CONTROL_H
#define UI_TRAY_TRAY_ICON_CONTROL_H

#include "afxdialogex.h"
#include "resource.h"
#include <string>

#define MY_TRAY_ICON WM_USER+300

class TrayIconControl
{
private:
	void notifyIconSetFlag(NOTIFYICONDATA& data, int uflags);
	void Initialize();	
public:
	TrayIconControl();
	~TrayIconControl();
	void SetTrayIcon(BOOL isUseTray);
	void SetTrayToolTip(std::string toolTipMessage);

	NOTIFYICONDATA notifyIconData_;
};

#endif // UI_TRAY_TRAY_ICON_CONTROL_H