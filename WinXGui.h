#pragma once
#ifndef _WINXGUI_H_
#define _WINXGUI_H_
#include <windows.h>
#include <map>
#include <string>
#include <exception>
#include <stdexcept>


namespace WinXGui {
	class App;
	class Window;
	class Widget;
	struct WinPos;
	typedef void(*Msg)(HWND, UINT, WPARAM, LPARAM);
	typedef int(*Event)(HWND, UINT, WPARAM, LPARAM);
	class Font;
	class Button;
	class Label;
	class Entry;
	class Checkbox;
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

class wxg::App {
	LPCWSTR AppClassName;
public:
	App();
	// The name will be the window class name of thw windows created by WinXGui and the window class name could not be changed after app has created and this function will init app and if you would not to init the app immediately you can the overloaded function: App() then when your app has been ready to init you can use your_app_class.Init(your_class_name)
	App(LPCWSTR name);
	~App();
	void Init(LPCWSTR ClassName);
	LPCWSTR GetClassName();
	void Exec();
};

class wxg::Window {
protected:
	WNDCLASSEX wc;
	HWND hWnd;
	LPCWSTR title;
	WinPos pos;
	static LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
public:
	Window();
	Window(LPCWSTR title);
	Window(int w, int h, int x, int y, LPCWSTR title);
	~Window();
	bool Create();
	bool Create(wxg::WinPos pos, LPCWSTR title = NULL) { this->pos = pos; title = title; return Create(); };
	bool Create(int w, int h, int x, int y, LPCWSTR title = NULL);
	void Show() { ShowWindow(hWnd, SW_SHOW); UpdateWindow(hWnd);};
	void Hide() { ShowWindow(hWnd, SW_HIDE); };
	bool IsShow() { return IsWindowVisible(hWnd); }
	HWND hwnd() { return hWnd; };
	void SetTitle(LPCWSTR title) { this->title = title; };
	void SetPos(WinPos pos) { this->pos = pos; MoveWindow(hWnd, pos.x, pos.y, pos.w, pos.h, TRUE); };
	void SetPos(int w, int h, int x, int y) { SetPos(WinPos(w, h, x, y)); };
	void Close();
	Msg oncreate = nullptr;
	Msg oncommand = nullptr;
	Event onclose = nullptr;
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