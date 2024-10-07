#pragma once
#ifndef _WINXGUIENTRY_H_
#define _WINXGUIENTRY_H_
#include "WinXGui.h"
#include "WinXGuiFont.h"

class wxg::Entry : public wxg::Widget {
    BOOL MultiLine = FALSE;
    BOOL Password = FALSE;
    BOOL ReadOnly = FALSE;
    BOOL ScrollBar = TRUE;
    BOOL AutoScroll = TRUE;
    int MaxLength = 0;
    HWND parent;
    int hid;
    // 样式
    virtual int style();
    // 重绘控件
    void restyle();
public:
    // 构造函数 (不推荐使用此构造函数)
    // 最好请使用 Entry(HWND parent, wxg::WinPos pos_, int event_id, BOOL valueMultiLine = FALSE, BOOL valuePassword = FALSE, BOOL valueReadOnly = FALSE, BOOL valueScrollBar = TRUE, BOOL valueAutoScroll = TRUE, int valueMaxLength = 0, LPCWSTR valueText = L"")
    // 因为一些样式在创建控件后可能就无法修改了
    // 例如：如果设置了多行显示，则无法再设置单行显示
    // 而这个构造函数是要执行创建控件的，所以某些样式就已经确定了! 
    Entry(HWND parent, wxg::WinPos pos_, int event_id);
    // 构造函数 (推荐使用此构造函数)
    Entry(HWND parent, wxg::WinPos pos_, int event_id, BOOL valueMultiLine = FALSE, BOOL valuePassword = FALSE, BOOL valueReadOnly = FALSE, BOOL valueScrollBar = TRUE, BOOL valueAutoScroll = TRUE, int valueMaxLength = 0, LPCWSTR valueText = L"");
    // 设置是否多行显示
    void SetMultiLine(BOOL value);
    // 设置是否显示密码
    // 密码显示时，输入的字符会被替换为星号
    void SetPassword(BOOL value);
    // 设置是否只读
    void SetReadOnly(BOOL value);
    // 设置是否显示滚动条
    void SetScrollBar(BOOL value);
    // 设置是否自动滚动
    void SetAutoScroll(BOOL value);
    // 设置最大长度
    void SetMaxLength(int value);
    // 获取是否多行显示
    BOOL IsMultiLine() const;
    // 获取是否显示密码
    BOOL IsPassword() const;
    // 获取是否只读
    BOOL IsReadOnly() const;
    // 获取是否显示滚动条
    BOOL IsScrollBar() const;
    // 获取是否自动滚动
    BOOL IsAutoScroll() const;
    // 获取最大长度
    int GetMaxLength() const;
    // 设置文本
    void SetText(LPCWSTR text);
    // 获取文本
    LPCWSTR GetText();
    // 获取文本长度
    int GetTextLength() const;
    // 追加文本
    void AppendText(LPCWSTR text);
    // 获取编辑框光标位置
    POINT GetCursorPosition() const;
    // 设置编辑框光标位置
    void SetCursorPosition(POINT pos);
    // 字体对象
    wxg::Font font;
};
#endif
