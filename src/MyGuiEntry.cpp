#include "MyGuiEntry.h"


int myg::Entry::style() {
    return (MultiLine?ES_MULTILINE:0) | (Password?ES_PASSWORD:0) | (ReadOnly?ES_READONLY:0) | (ScrollBar?(MultiLine?WS_VSCROLL:0)|WS_HSCROLL:0) | (AutoScroll?(MultiLine? ES_AUTOVSCROLL:0)|ES_AUTOHSCROLL:0);
}

void myg::Entry::restyle()
{
    myg::Debug("style: MultiLine=%d, Password=%d, ReadOnly=%d, ScrollBar=%d, AutoScroll=%d, style=%d\n", MultiLine, Password, ReadOnly, ScrollBar, AutoScroll, style());
    SetWindowLong(hWnd, GWL_STYLE, WS_CHILD | WS_VISIBLE | style());
}

myg::Entry::Entry(myg::Window* parent, myg::WinPos pos_) : MyGui::Widget(L"", pos_) {
    hWnd = CreateWindow(TEXT("edit"), NULL, WS_CHILD | WS_VISIBLE | style(), pos_.x, pos_.y, pos_.w, pos_.h, parent->hwnd(), wid, GetModuleHandle(0), NULL);
    RegisterWidget(hWnd);
    font.setHWND(hWnd);
    font.font();
}

myg::Entry::Entry(myg::Window* parent, myg::WinPos pos_, BOOL valueMultiLine, BOOL valuePassword, BOOL valueReadOnly, BOOL valueScrollBar, BOOL valueAutoScroll, int valueMaxLength, LPCWSTR valueText)
    : MyGui::Widget(L"", pos_)
{
    MultiLine = valueMultiLine;
    Password = valuePassword;
    ReadOnly = valueReadOnly;
    ScrollBar = valueScrollBar;
    AutoScroll = valueAutoScroll;
    MaxLength = valueMaxLength;
    hWnd = CreateWindow(TEXT("edit"), valueText, WS_CHILD | WS_VISIBLE | style(), pos_.x, pos_.y, pos_.w, pos_.h, parent->hwnd(), wid, GetModuleHandle(0), NULL);
    RegisterWidget(hWnd);
    font.setHWND(hWnd);
    font.font();
}

void myg::Entry::SetMultiLine(BOOL value) { MultiLine = value; restyle(); }
void myg::Entry::SetPassword(BOOL value) { Password = value; restyle(); }
void myg::Entry::SetReadOnly(BOOL value) { ReadOnly = value; restyle(); SendMessage(hWnd, EM_SETREADONLY, value, 0); }
void myg::Entry::SetScrollBar(BOOL value) { ScrollBar = value; restyle(); }
void myg::Entry::SetAutoScroll(BOOL value) { AutoScroll = value; restyle(); }
void myg::Entry::SetMaxLength(int value) { MaxLength = value; restyle(); }
BOOL myg::Entry::IsMultiLine() const { return MultiLine; }
BOOL myg::Entry::IsPassword() const { return Password; }
BOOL myg::Entry::IsReadOnly() const { return ReadOnly; }
BOOL myg::Entry::IsScrollBar() const { return ScrollBar; }
BOOL myg::Entry::IsAutoScroll() const { return AutoScroll; }
int myg::Entry::GetMaxLength() const { return MaxLength; }

void myg::Entry::SetText(LPCWSTR text)
{
    title = text;
    SetWindowText(hWnd, text);
}

LPCWSTR myg::Entry::GetText()
{
    int len = GetWindowTextLength(hWnd);
    if (len > 0) {
        LPWSTR text = new WCHAR[len + 1];
        GetWindowText(hWnd, text, len + 1);
        title = text;
        return text;
    }
    return L"";
}

int myg::Entry::GetTextLength() const
{
    return GetWindowTextLength(hWnd);
}

POINT myg::Entry::GetCursorPosition() const
{
    DWORD start, end;
    SendMessage(hWnd, EM_GETSEL, (WPARAM)&start, (LPARAM)&end);
    return { (long)start, (long)end };
}

void myg::Entry::SetCursorPosition(POINT pos)
{
    SendMessage(hWnd, EM_SETSEL, (WPARAM)pos.x, (LPARAM)pos.y);
}

void myg::Entry::AppendText(LPCWSTR t)
{
    POINT cursorPos = GetCursorPosition();
    int length = GetTextLength();
    int len = wcslen(t);
    wchar_t* text = new wchar_t[length + len + 1];
    wcscpy_s(text, length + len + 1, GetText());
    wcscat_s(text, length + len + 1, t);
    SetText(text);
    delete[] text;
    SetCursorPosition(cursorPos);
}
