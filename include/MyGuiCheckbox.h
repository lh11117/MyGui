#pragma once
#ifndef _MYGUICHECKBOX_H_
#define _MYGUICHECKBOX_H_
#include "MyGui.h"
#include "MyGuiFont.h"
#define MYG_CHECKBOX_TYPE "checkbox"
#define MYG_IS_CONTROL_A_CHECKBOX(c) strcmp(c.type,MYG_CHECKBOX_TYPE)==0

class myg::Checkbox : public myg::Widget {
    virtual int style();
public:
    Checkbox(myg::Window* parent, LPCWSTR title_, myg::WinPos pos_);
    // �Ƿ�ѡ��
    BOOL IsChecked();
    // �����Ƿ�ѡ��
    void SetChecked(BOOL checked_);
    myg::Font font;
    const char* const type = MYG_CHECKBOX_TYPE;
};
#endif
