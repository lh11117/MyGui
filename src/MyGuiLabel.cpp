#include "MyGuiLabel.h"


myg::Label::Label(myg::Window* parent, LPCWSTR title_, myg::WinPos pos_) : MyGui::Widget(title_, pos_) {
	this->title = title_;
	this->pos = pos_;
	hWnd = CreateWindowEx(0, L"STATIC", title, WS_CHILD | WS_VISIBLE | style(), pos.x, pos.y, pos.w, pos.h, parent->hwnd(), NULL, GetModuleHandle(NULL), NULL);
	RegisterWidget(hWnd);
	font.setHWND(hWnd);
	font.font();
}

BOOL myg::Label::IsHorizontalCenter() const 
{ 
	return this->HorizontalCenter; 
}
BOOL myg::Label::IsVerticalCenter() const 
{ 
	return this->VerticalCenter; 
}
void myg::Label::SetHorizontalCenter(BOOL center) 
{ 
	this->HorizontalCenter = center; 
	SetWindowLong(hWnd, GWL_STYLE, WS_CHILD | WS_VISIBLE | style()); 
	SetText(title); 
}
void myg::Label::SetVerticalCenter(BOOL center) 
{ 
	this->VerticalCenter = center; 
	SetWindowLong(hWnd, GWL_STYLE, WS_CHILD | WS_VISIBLE | style()); 
	SetText(title); 
}
int myg::Label::style() 
{ 
	return (HorizontalCenter ? SS_CENTER : 0) | (VerticalCenter ? SS_CENTERIMAGE : 0); 
}