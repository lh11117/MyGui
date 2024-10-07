#pragma once
#ifndef WINXGUI_LABEL_H
#define WINXGUI_LABEL_H
#include "WinXGui.h"
#include "WinXGuiFont.h"

class wxg::Label :
    public wxg::Widget
{
    LPCWSTR title;
    wxg::WinPos pos;
    BOOL HorizontalCenter = TRUE;
    BOOL VerticalCenter = TRUE;
    virtual int style() { return (HorizontalCenter ?SS_CENTER:0) | (VerticalCenter ?SS_CENTERIMAGE:0); }
public:
    wxg::Font font;
    Label(wxg::Window* parent, LPCWSTR title, wxg::WinPos pos);
    BOOL IsHorizontalCenter() { return this->HorizontalCenter; }
    BOOL IsVerticalCenter() { return this->VerticalCenter; }
    void SetHorizontalCenter(BOOL center) { this->HorizontalCenter = center; SetWindowLong(hWnd, GWL_STYLE, WS_CHILD | WS_VISIBLE | style()); SetText(title); }
    void SetVerticalCenter(BOOL center) { this->VerticalCenter = center; SetWindowLong(hWnd, GWL_STYLE, WS_CHILD | WS_VISIBLE | style()); SetText(title); }
};


#endif