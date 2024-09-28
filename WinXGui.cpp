#include "WinXGui.h"

namespace WinXGui {
	std::map<HWND, Window*> windowMap;
};
static bool IsRegisteredWindowClass = false;
static wxg::App *app = nullptr;
#define IsAppCreated app


wxg::App::App() {
}

wxg::App::App(LPCWSTR ClassName) {
	Init(ClassName);
}

wxg::App::~App() {
	UnregisterClass(AppClassName, GetModuleHandle(0));
}

void wxg::App::Init(LPCWSTR ClassName){
	if (IsAppCreated) {
		throw std::runtime_error("App class only can be created once!");
	}
	app = this;
	AppClassName = ClassName;
}

LPCWSTR wxg::App::GetClassName() {
	return AppClassName;
}

void wxg::App::Exec() {
	MSG msg;
	while (GetMessage(&msg, NULL, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
}

wxg::Window *window_temp;
bool wxg::Window::Create() {
	if (!IsAppCreated) {
		throw std::runtime_error("You did not init app!");
	}
	window_temp = this;
	if (!IsRegisteredWindowClass) {
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
		wc.lpszClassName = app->GetClassName();
		if (!RegisterClassEx(&wc))
		{
			return false;
		}
	}
	IsRegisteredWindowClass = true;
	hWnd = CreateWindow(app->GetClassName(), title, WS_OVERLAPPEDWINDOW, pos.x, pos.y, pos.w, pos.h, NULL, NULL, GetModuleHandle(0), NULL);
	return (int)hWnd!=0;
}

bool wxg::Window::Create(int w, int h, int x, int y, LPCWSTR Title) {
	if (Title) this->title = Title;
	pos = WinPos(w, h, x, y);
	return Create();
}

wxg::Window::Window(LPCWSTR Title)
{
	if (Title) this->title = Title;
}

wxg::Window::Window(int w, int h, int x, int y, LPCWSTR title)
{
    this->title = title; pos = WinPos(w, h, x, y);
}

wxg::Window::Window()
{
}

wxg::Window::~Window() {
	Close();
}

void wxg::Window::Close() {
    windowMap.erase(hWnd);
	DestroyWindow(hWnd);
}

static wxg::Window* FindByHWND(HWND hWnd) {
	auto it = WinXGui::windowMap.find(hWnd);
	if (it != WinXGui::windowMap.end()) {
		return it->second;
	}
	else {
		return nullptr;
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
		//Debug("Window Map Size: %d\n", windowMap.size());
		if(windowMap.size()==0)
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
		wxg::Window* window = FindByHWND(hwnd);
		if (window && window->oncommand) {
			window->oncommand(hwnd, message, wParam, lParam);
		}
		break;
	}
	case WM_CLOSE: {
		wxg::Window* window = FindByHWND(hwnd);
		if (window && window->onclose) {
			int result = window->onclose(hwnd, message, wParam, lParam);
			if (result == 0) {
				// agree to close window
				window->Close();
			}
			else {
				// disargee to close window
				// do nothing here
			}
		} else {
			window->Close();
		}
		break;
	}
	case WM_ERASEBKGND:
		hdc = (HDC)wParam;
		GetClientRect(hwnd, &rect);
		hBrush = CreateSolidBrush(RGB(240, 240, 240));
		FillRect(hdc, &rect, hBrush);
		DeleteObject(hBrush);
		return 1; // 返回非零值表示已处理背景擦除

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

LPCWSTR wxg::Widget::GetText() const
{
	return title;
}


void wxg::Debug(const char* _Format, ...) {
	const size_t bufferSize = 1024;
	char buffer[bufferSize];

	va_list args;
	va_start(args, _Format);

	// Use vsnprintf instead of vsnprintf_s
	int length = vsnprintf(buffer, bufferSize, _Format, args);

	va_end(args);

	// Check if buffer overflow occurred
	if (length < 0 || length >= bufferSize) {
		OutputDebugStringA("wxg_error: Debug message truncated due to overflow.\n");
	}
	else {
		OutputDebugStringA(buffer);
	}
}