#include "WinXGuiFont.h"

void wxg::Font::font() {
    hFont = CreateFont(-fontSize, -fontSize / 2, 0, 0, weight, italic, underline, strikeout, DEFAULT_CHARSET, OUT_CHARACTER_PRECIS, CLIP_CHARACTER_PRECIS, DEFAULT_QUALITY, FF_DONTCARE, fontName);
    SendMessage(hWnd, WM_SETFONT, (WPARAM)hFont, NULL);
    UpdateWindow(hWnd);
}

void wxg::Font::SetFontSize(double size) {
    this->fontSize = size;
    font();
}

double wxg::Font::FontSize() {
    return this->fontSize;
}

void wxg::Font::SetFontWeight(int weight) {
    this->weight = weight;
    font();
}

int wxg::Font::FontWeight() {
    return this->weight;
}

void wxg::Font::SetFontItalic(BOOL italic) {
    this->italic = italic;
    font();
}

BOOL wxg::Font::FontItalic() {
    return this->italic;
}

void wxg::Font::SetFontUnderline(BOOL underline) {
    this->underline = underline;
    font();
}

BOOL wxg::Font::FontUnderline() {
    return this->underline;
}

void wxg::Font::SetFontStrikeout(BOOL strikeout) {
    this->strikeout = strikeout;
    font();
}

BOOL wxg::Font::FontStrikeout() {
    return this->strikeout;
}

void wxg::Font::SetFontName(LPCWSTR fontName) {
    this->fontName = fontName;
    font();
}

LPCWSTR wxg::Font::SetFontName() {
    return this->fontName;
}

void wxg::Font::setHWND(HWND hWnd) {
    this->hWnd = hWnd;
}

wxg::Font::~Font() {
    DeleteObject(hFont);
}

wxg::Font::Font(double size, int weight, BOOL italic, BOOL underline, BOOL strikeout, LPCWSTR fontName, HWND hWnd) {
    this->fontSize = size;
    this->weight = weight;
    this->italic = italic;
    this->underline = underline;
    this->strikeout = strikeout;
    this->fontName = fontName;
    if (hWnd != NULL) {
        this->hWnd = hWnd;
    }
    font();
}