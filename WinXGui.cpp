#include "WinXGui.h"

namespace WinXGui {
	std::map<HWND, Window*> windowMap;
}

wxg::Window *window_temp;
bool wxg::Window::create() {
	window_temp = this;
	wc.cbSize = sizeof(WNDCLASSEX);
	wc.style = CS_HREDRAW | CS_VREDRAW;
	wc.lpfnWndProc = (WNDPROC)this->WndProc;
	wc.cbClsExtra = 0;
	wc.cbWndExtra = 0;
	wc.hInstance = GetModuleHandle(0);
	wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);
	wc.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	wc.lpszMenuName = NULL;
	wc.lpszClassName = className;
	if (!RegisterClassEx(&wc))
	{
		return false;
	}
	hWnd = CreateWindow(className, title, WS_OVERLAPPEDWINDOW, pos.x, pos.y, pos.w, pos.h, NULL, NULL, GetModuleHandle(0), NULL);
	return (int)hWnd!=0;
}

bool wxg::Window::create(int w, int h, int x, int y, LPCWSTR Title, LPCWSTR ClassName) {
	if (ClassName) this->className = ClassName;
	if (Title) this->title = Title;
	pos = WinPos(w, h, x, y);
	return create();
}

wxg::Window::Window(LPCWSTR ClassName, LPCWSTR Title)
{
	if (ClassName) this->className = ClassName;
	if (Title) this->title = Title;
}

wxg::Window::Window(int w, int h, int x, int y, LPCWSTR title)
{
    this->className = TEXT("WinXGui"); this->title = title; pos = WinPos(w, h, x, y);
}

wxg::Window::Window()
{
}


void wxg::Window::loop() {
	UpdateWindow(hWnd);
	MSG msg;
	while (GetMessage(&msg, NULL, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
}

LRESULT CALLBACK wxg::Window::WndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam) {
	PAINTSTRUCT ps;
	HDC hdc;
	RECT rect;
	HBRUSH hBrush;
	switch (message)
	{
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	case WM_CREATE: {
		// add to window map
		windowMap[hwnd] = window_temp;
		if (window_temp->oncreate) {
			window_temp->oncreate(hwnd, message, wParam, lParam);
		}
		window_temp = nullptr;
		break;
	}
	case WM_COMMAND: {
		auto it = WinXGui::windowMap.find(hwnd);
		if (it != WinXGui::windowMap.end()) {
			wxg::Window* window = it->second;
			if (window->oncommand) {
				window->oncommand(hwnd, message, wParam, lParam);
			}
		}
		break;
	}
	case WM_ERASEBKGND:
		hdc = (HDC)wParam;
		GetClientRect(hwnd, &rect);
		hBrush = CreateSolidBrush(RGB(240, 240, 240));
		FillRect(hdc, &rect, hBrush);
		DeleteObject(hBrush);
		return 1; // ���ط���ֵ��ʾ�Ѵ�����������

	default:
		return DefWindowProc(hwnd, message, wParam, lParam);
	}
	return 0;
}

void wxg::Widget::SetText(LPCWSTR title)
{
	this->title = title;
	SetWindowText(hWnd, title);
}

LPCWSTR wxg::Widget::GetText()
{
	return title;
}