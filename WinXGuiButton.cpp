#include "WinXGuiButton.h"

int wxg::Button::style() {
    return BS_PUSHBUTTON;
}

wxg::Button::Button(wxg::Window* parent, LPCWSTR title_, wxg::WinPos pos_) : WinXGui::Widget(title_, pos_) {
    hWnd = CreateWindow(TEXT("button"), title_, WS_CHILD | WS_VISIBLE | WS_TABSTOP | style(), pos_.x, pos_.y, pos_.w, pos_.h, parent->hwnd(), wid, GetModuleHandle(0), NULL);
    RegisterWidget(hWnd);
    font.setHWND(hWnd);
    font.font();
}

