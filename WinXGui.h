#pragma once
#ifndef _WINXGUI_H_
#define _WINXGUI_H_
#include <windows.h>
#include <map>


namespace WinXGui {
	class Window;
	class Widget;
	struct WinPos;
	typedef void(*msg)(HWND, UINT, WPARAM, LPARAM);
	class Font;
	class Button;
	class Label;
	class Entry;
	void Debug(const char* _Format, ...);
	// window map
	extern std::map<HWND, Window*> windowMap;
}
namespace wxg = WinXGui;


struct wxg::WinPos {
	int w;
	int h;
	int x;
	int y;
	WinPos() :w(CW_USEDEFAULT), h(CW_USEDEFAULT), x(CW_USEDEFAULT), y(CW_USEDEFAULT) {};
	WinPos(int w, int h, int x, int y) :w(w), h(h), x(x), y(y) {};
};

class wxg::Window {
protected:
	WNDCLASSEX wc;
	HWND hWnd;
	LPCWSTR className;
	LPCWSTR title;
	WinPos pos;
	static LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
public:
	Window();
	Window(LPCWSTR className, LPCWSTR title);
	Window(int w, int h, int x, int y, LPCWSTR title);
	~Window() {
		// delete from window map
		windowMap.erase(hWnd);
		DestroyWindow(hWnd);
		UnregisterClass(className, GetModuleHandle(0));
	}
	bool create();
	bool create(wxg::WinPos pos, LPCWSTR title = NULL, LPCWSTR className = NULL) { this->pos = pos; title = title; return create(); };
	bool create(int w, int h, int x, int y, LPCWSTR title = NULL, LPCWSTR className = NULL);
	void show() { ShowWindow(hWnd, SW_SHOW); };
	void hide() { ShowWindow(hWnd, SW_HIDE); };
	HWND hwnd() { return hWnd; };
	void setClassName(LPCWSTR className) { this->className = className; };
	void setTitle(LPCWSTR title) { this->title = title; };
	void setPos(WinPos pos) { this->pos = pos; MoveWindow(hWnd, pos.x, pos.y, pos.w, pos.h, TRUE); };
	void setPos(int w, int h, int x, int y) { setPos(WinPos(w, h, x, y)); };
	void loop();
	msg oncreate = nullptr;
	msg oncommand = nullptr;
};

class wxg::Widget {
protected:
	HWND hWnd = 0;
	LPCWSTR title;
	WinPos pos;
	BOOL visible = TRUE;
	virtual int style() = 0;
public:
	inline BOOL IsVisible() { return visible; };
	void Show() { visible = TRUE; ShowWindow(hWnd, SW_SHOW); };
	void Hide() { visible = FALSE; ShowWindow(hWnd, SW_HIDE); };
	Widget(LPCWSTR title_, WinPos pos_): title(title_), pos(pos_) {};
	virtual void SetText(LPCWSTR title);
	virtual LPCWSTR GetText() const;
};
#endif