#include "WinXGuiCheckbox.h"

int wxg::Checkbox::style() {
    return BS_AUTOCHECKBOX;
}

wxg::Checkbox::Checkbox(wxg::Window* parent, LPCWSTR title_, wxg::WinPos pos_) : WinXGui::Widget(title_, pos_) {
    hWnd = CreateWindow(TEXT("button"), title_, WS_CHILD | WS_VISIBLE | WS_TABSTOP | style(), pos_.x, pos_.y, pos_.w, pos_.h, parent->hwnd(), wid, GetModuleHandle(0), NULL);
    RegisterWidget(hWnd);
    font.setHWND(hWnd);
    font.font();
}

BOOL wxg::Checkbox::IsChecked()
{
    return SendMessage(hWnd, BM_GETCHECK, 0, 0) == BST_CHECKED;
}

void wxg::Checkbox::SetChecked(BOOL checked_)
{
    SendMessage(hWnd, BM_SETCHECK, checked_ ? BST_CHECKED : BST_UNCHECKED, 0);
}
