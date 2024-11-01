#include "MyGuiButton.h"

int myg::Button::style() {
    return BS_PUSHBUTTON;
}

myg::Button::Button(myg::Window* parent, LPCWSTR title_, myg::WinPos pos_) : MyGui::Widget(title_, pos_) {
    hWnd = CreateWindow(TEXT("button"), title_, WS_CHILD | WS_VISIBLE | style(), pos_.x, pos_.y, pos_.w, pos_.h, parent->hwnd(), wid, GetModuleHandle(0), NULL);
    RegisterWidget(hWnd);
    font.setHWND(hWnd);
    font.font();
}

int myg::OkButton::style() {
    return BS_PUSHBUTTON | BS_DEFPUSHBUTTON | WS_TABSTOP;
}

myg::OkButton::OkButton(myg::Window* parent, LPCWSTR title_, myg::WinPos pos_) : MyGui::Button(parent,title_,pos_)
{
}

int myg::CancelButton::style()
{
    return BS_PUSHBUTTON | WS_TABSTOP;
}

myg::CancelButton::CancelButton(myg::Window* parent, LPCWSTR title_, myg::WinPos pos_) : MyGui::Button(parent,title_,pos_)
{
}