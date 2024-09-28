#include "WinXGuiCheckbox.h"

int wxg::Checkbox::style() {
    return BS_AUTOCHECKBOX;
}

wxg::Checkbox::Checkbox(HWND parent, LPCWSTR title_, wxg::WinPos pos_, int event_id) : WinXGui::Widget(title_, pos_) {
    hWnd = CreateWindow(TEXT("button"), title_, WS_CHILD | WS_VISIBLE | WS_TABSTOP | style(), pos_.x, pos_.y, pos_.w, pos_.h, parent, (HMENU)event_id, GetModuleHandle(0), NULL);
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
