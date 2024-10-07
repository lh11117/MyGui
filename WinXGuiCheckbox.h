#pragma once
#ifndef _WINXGUICHECKBOX_H_
#define _WINXGUICHECKBOX_H_
#include "WinXGui.h"
#include "WinXGuiFont.h"

class wxg::Checkbox : public wxg::Widget {
    virtual int style();
public:
    Checkbox(wxg::Window* parent, LPCWSTR title_, wxg::WinPos pos_);
    // 是否选中
    BOOL IsChecked();
    // 设置是否选中
    void SetChecked(BOOL checked_);
    wxg::Font font;
};
#endif
