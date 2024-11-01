#pragma once
#ifndef MYGUI_LABEL_H
#define MYGUI_LABEL_H
#include "MyGui.h"
#include "MyGuiFont.h"
#define MYG_LABEL_TYPE "label"
#define MYG_IS_CONTROL_A_LABEL(c) strcmp(c.type,MYG_LABEL_TYPE)==0

class myg::Label :
    public myg::Widget
{
    LPCWSTR title;
    myg::WinPos pos;
    BOOL HorizontalCenter = TRUE;
    BOOL VerticalCenter = TRUE;
    virtual int style();
public:
    myg::Font font;
    Label(myg::Window* parent, LPCWSTR title, myg::WinPos pos);
    BOOL IsHorizontalCenter() const;
    BOOL IsVerticalCenter() const;
    void SetHorizontalCenter(BOOL center);
    void SetVerticalCenter(BOOL center);
    const char* const type = MYG_LABEL_TYPE;
};


#endif