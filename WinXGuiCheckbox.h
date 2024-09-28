#pragma once
#ifndef _WINXGUICHECKBOX_H_
#define _WINXGUICHECKBOX_H_
#include "WinXGui.h"
#include "WinXGuiFont.h"

class wxg::Checkbox : public wxg::Widget {
    virtual int style();
public:
    Checkbox(HWND parent, LPCWSTR title_, wxg::WinPos pos_, int event_id);
    // �Ƿ�ѡ��
    BOOL IsChecked();
    // �����Ƿ�ѡ��
    void SetChecked(BOOL checked_);
    wxg::Font font;
};
#endif
