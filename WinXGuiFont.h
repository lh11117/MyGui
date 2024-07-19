#pragma once
#ifndef __WINX_GUI_FONT_H__
#define __WINX_GUI_FONT_H__
#include "WinXGui.h"


class wxg::Font {
    double fontSize = 15;         //�����С
    int weight = 400;             //�����ϸ
    BOOL italic = FALSE;          //б��
    BOOL underline = FALSE;       //�»���
    BOOL strikeout = FALSE;       //ɾ����
    LPCWSTR fontName = L"΢���ź�";  //������
    HFONT hFont;
    HWND hWnd = 0;
public:
    Font() { font(); };
    Font(double size/* ��Ϊ��Ҫ�ṩ����Ĭ��ֵ, �������һ�����غ�����ͻ */, int weight = 400, BOOL italic = FALSE, BOOL underline = FALSE, BOOL strikeout = FALSE, LPCWSTR fontName = L"΢���ź�", HWND hWnd = NULL);
    ~Font();
    void setHWND(HWND hWnd);
    void font();
    void SetFontSize(double size);
    double FontSize();
    void SetFontWeight(int weight);
    int FontWeight();
    void SetFontItalic(BOOL italic);
    BOOL FontItalic();
    void SetFontUnderline(BOOL underline);
    BOOL FontUnderline();
    void SetFontStrikeout(BOOL strikeout);
    BOOL FontStrikeout();
    void SetFontName(LPCWSTR fontName);
    LPCWSTR SetFontName();
};

#endif