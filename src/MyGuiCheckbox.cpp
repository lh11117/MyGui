#include "MyGuiCheckbox.h"

int myg::Checkbox::style() {
    return BS_AUTOCHECKBOX;
}

myg::Checkbox::Checkbox(myg::Window* parent, LPCWSTR title_, myg::WinPos pos_) : MyGui::Widget(title_, pos_) {
    hWnd = CreateWindow(TEXT("button"), title_, WS_CHILD | WS_VISIBLE | style(), pos_.x, pos_.y, pos_.w, pos_.h, parent->hwnd(), wid, GetModuleHandle(0), NULL);
    RegisterWidget(hWnd);
    font.setHWND(hWnd);
    font.font();
}

BOOL myg::Checkbox::IsChecked()
{
    return SendMessage(hWnd, BM_GETCHECK, 0, 0) == BST_CHECKED;
}

void myg::Checkbox::SetChecked(BOOL checked_)
{
    SendMessage(hWnd, BM_SETCHECK, checked_ ? BST_CHECKED : BST_UNCHECKED, 0);
}
