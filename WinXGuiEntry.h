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
    // ��ʽ
    virtual int style();
    // �ػ�ؼ�
    void restyle();
public:
    // ���캯�� (���Ƽ�ʹ�ô˹��캯��)
    // �����ʹ�� Entry(HWND parent, wxg::WinPos pos_, int event_id, BOOL valueMultiLine = FALSE, BOOL valuePassword = FALSE, BOOL valueReadOnly = FALSE, BOOL valueScrollBar = TRUE, BOOL valueAutoScroll = TRUE, int valueMaxLength = 0, LPCWSTR valueText = L"")
    // ��ΪһЩ��ʽ�ڴ����ؼ�����ܾ��޷��޸���
    // ���磺��������˶�����ʾ�����޷������õ�����ʾ
    // ��������캯����Ҫִ�д����ؼ��ģ�����ĳЩ��ʽ���Ѿ�ȷ����! 
    Entry(HWND parent, wxg::WinPos pos_, int event_id);
    // ���캯�� (�Ƽ�ʹ�ô˹��캯��)
    Entry(HWND parent, wxg::WinPos pos_, int event_id, BOOL valueMultiLine = FALSE, BOOL valuePassword = FALSE, BOOL valueReadOnly = FALSE, BOOL valueScrollBar = TRUE, BOOL valueAutoScroll = TRUE, int valueMaxLength = 0, LPCWSTR valueText = L"");
    // �����Ƿ������ʾ
    void SetMultiLine(BOOL value);
    // �����Ƿ���ʾ����
    // ������ʾʱ��������ַ��ᱻ�滻Ϊ�Ǻ�
    void SetPassword(BOOL value);
    // �����Ƿ�ֻ��
    void SetReadOnly(BOOL value);
    // �����Ƿ���ʾ������
    void SetScrollBar(BOOL value);
    // �����Ƿ��Զ�����
    void SetAutoScroll(BOOL value);
    // ������󳤶�
    void SetMaxLength(int value);
    // ��ȡ�Ƿ������ʾ
    BOOL IsMultiLine() const;
    // ��ȡ�Ƿ���ʾ����
    BOOL IsPassword() const;
    // ��ȡ�Ƿ�ֻ��
    BOOL IsReadOnly() const;
    // ��ȡ�Ƿ���ʾ������
    BOOL IsScrollBar() const;
    // ��ȡ�Ƿ��Զ�����
    BOOL IsAutoScroll() const;
    // ��ȡ��󳤶�
    int GetMaxLength() const;
    // �����ı�
    void SetText(LPCWSTR text);
    // ��ȡ�ı�
    LPCWSTR GetText();
    // ��ȡ�ı�����
    int GetTextLength() const;
    // ׷���ı�
    void AppendText(LPCWSTR text);
    // ��ȡ�༭����λ��
    POINT GetCursorPosition() const;
    // ���ñ༭����λ��
    void SetCursorPosition(POINT pos);
    // �������
    wxg::Font font;
};
#endif
