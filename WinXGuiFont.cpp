#include "WinXGuiFont.h"

void wxg::Font::font() {
    DeleteObject(hFont);
    hFont = CreateFont(-fontSize, -fontSize / 2.0, 0, 0, weight, italic, underline, strikeout, DEFAULT_CHARSET, OUT_CHARACTER_PRECIS, CLIP_CHARACTER_PRECIS, DEFAULT_QUALITY, FF_DONTCARE, fontName);
    SendMessage(hWnd, WM_SETFONT, (WPARAM)hFont, NULL);
    UpdateWindow(hWnd);
}

void wxg::Font::SetFontSize(double _size) {
    this->fontSize = _size;
    font();
}

double wxg::Font::FontSize() {
    return this->fontSize;
}

void wxg::Font::SetFontWeight(int _weight) {
    this->weight = _weight;
    font();
}

int wxg::Font::FontWeight() {
    return this->weight;
}

void wxg::Font::SetFontItalic(BOOL _italic) {
    this->italic = _italic;
    font();
}

BOOL wxg::Font::FontItalic() {
    return this->italic;
}

void wxg::Font::SetFontUnderline(BOOL _underline) {
    this->underline = _underline;
    font();
}

BOOL wxg::Font::FontUnderline() {
    return this->underline;
}

void wxg::Font::SetFontStrikeout(BOOL _strikeout) {
    this->strikeout = _strikeout;
    font();
}

BOOL wxg::Font::FontStrikeout() {
    return this->strikeout;
}

void wxg::Font::SetFontName(LPCWSTR _fontName) {
    this->fontName = _fontName;
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

wxg::Font::Font(double size, int _weight, BOOL _italic, BOOL _underline, BOOL _strikeout, LPCWSTR _fontName, HWND hWnd) {
    this->fontSize = size;
    this->weight = _weight;
    this->italic = _italic;
    this->underline = _underline;
    this->strikeout = _strikeout;
    this->fontName = _fontName;
    if (hWnd != NULL) {
        this->hWnd = hWnd;
    }
    font();
}