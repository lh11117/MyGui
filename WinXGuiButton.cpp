#include "WinXGuiButton.h"

int wxg::Button::style() {
    return BS_PUSHBUTTON;
}

wxg::Button::Button(HWND parent, LPCWSTR title_, wxg::WinPos pos_, int event_id) : WinXGui::Widget(title_, pos_) {
    hWnd = CreateWindow(TEXT("button"), title_, WS_CHILD | WS_VISIBLE | WS_TABSTOP | style(), pos_.x, pos_.y, pos_.w, pos_.h, parent, (HMENU)event_id, GetModuleHandle(0), NULL);
    font.setHWND(hWnd);
    font.font();
}

void wxg::Button::setText(LPCWSTR text) {
    SetWindowText(hWnd, text);
}

void wxg::Button::setText(char* text) {
    SetWindowTextA(hWnd, text);
}
