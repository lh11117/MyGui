#pragma once
#ifndef _MYGUIBUTTON_H_
#define _MYGUIBUTTON_H_
#include "MyGui.h"
#include "MyGuiFont.h"
#define MYG_BUTTON_TYPE "button"
#define MYG_IS_CONTROL_A_BUTTON(c) strcmp(c.type,MYG_BUTTON_TYPE)==0

class myg::Button : public myg::Widget {
    virtual int style();
public:
    Button(myg::Window* parent, LPCWSTR title_, myg::WinPos pos_);
    myg::Font font;
    const char* const type = MYG_BUTTON_TYPE;
};

class myg::OkButton : public myg::Button {
    virtual int style();
    HMENU __HMENU_ = (HMENU)IDOK;
public:
    OkButton(myg::Window* parent, LPCWSTR title_, myg::WinPos pos_);
};

class myg::CancelButton : public myg::Button {
    virtual int style();
    HMENU __HMENU_ = (HMENU)IDCANCEL;
public:
    CancelButton(myg::Window* parent, LPCWSTR title_, myg::WinPos pos_);
};
#endif
