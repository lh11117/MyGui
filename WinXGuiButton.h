#pragma once
#ifndef _WINXGUIBUTTON_H_
#define _WINXGUIBUTTON_H_
#include "WinXGui.h"
#include "WinXGuiFont.h"

class wxg::Button : public wxg::Widget {
public:
    virtual int style();
    Button(HWND parent, LPCWSTR title_, wxg::WinPos pos_, int event_id);
    wxg::Font font;
};
#endif