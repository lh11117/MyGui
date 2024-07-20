#include "WinXGuiLabel.h"


wxg::Label::Label(HWND parent, LPCWSTR title_, wxg::WinPos pos_) : WinXGui::Widget(title_, pos_) {
	this->title = title_;
	this->pos = pos_;
	hWnd = CreateWindowEx(0, L"STATIC", title, WS_CHILD | WS_VISIBLE | style(), pos.x, pos.y, pos.w, pos.h, parent, NULL, GetModuleHandle(NULL), NULL);
	font.setHWND(hWnd);
	font.font();
}