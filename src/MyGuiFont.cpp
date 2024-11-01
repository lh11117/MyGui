#include "MyGuiFont.h"

myg::Font::Font() { 
    font(); 
};

void myg::Font::font() {
    DeleteObject(hFont);
    hFont = CreateFont(-fontSize, -fontSize / 2.0, 0, 0, weight, italic, underline, strikeout, DEFAULT_CHARSET, OUT_CHARACTER_PRECIS, CLIP_CHARACTER_PRECIS, DEFAULT_QUALITY, FF_DONTCARE, fontName);
    SendMessage(hWnd, WM_SETFONT, (WPARAM)hFont, NULL);
    UpdateWindow(hWnd);
}

void myg::Font::SetFontSize(double _size) {
    this->fontSize = _size;
    font();
}

double myg::Font::FontSize() {
    return this->fontSize;
}

void myg::Font::SetFontWeight(int _weight) {
    this->weight = _weight;
    font();
}

int myg::Font::FontWeight() {
    return this->weight;
}

void myg::Font::SetFontItalic(BOOL _italic) {
    this->italic = _italic;
    font();
}

BOOL myg::Font::FontItalic() {
    return this->italic;
}

void myg::Font::SetFontUnderline(BOOL _underline) {
    this->underline = _underline;
    font();
}

BOOL myg::Font::FontUnderline() {
    return this->underline;
}

void myg::Font::SetFontStrikeout(BOOL _strikeout) {
    this->strikeout = _strikeout;
    font();
}

BOOL myg::Font::FontStrikeout() {
    return this->strikeout;
}

void myg::Font::SetFontName(LPCWSTR _fontName) {
    this->fontName = _fontName;
    font();
}

LPCWSTR myg::Font::SetFontName() {
    return this->fontName;
}

void myg::Font::setHWND(HWND hWnd) {
    this->hWnd = hWnd;
}

myg::Font::~Font() {
    DeleteObject(hFont);
}

myg::Font::Font(double size, int _weight, BOOL _italic, BOOL _underline, BOOL _strikeout, LPCWSTR _fontName, HWND hWnd) {
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