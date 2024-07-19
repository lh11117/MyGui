#include "WinXGuiAll.h"

#define WINXGUI_USE_NEW_STYLE
#include "WinXGuiConfig.h"

wxg::Window* win = new wxg::Window(L"1334545", L"WinXGui");
wxg::Button* btn;
void create(HWND hWnd, UINT, WPARAM, LPARAM) {
	btn = new wxg::Button(hWnd, TEXT("按钮"), wxg::WinPos(100, 100, 20, 20), 50);
}

void command(HWND, UINT, WPARAM wParam, LPARAM) {
	switch (wParam)
	{
	case 50: {
		btn->font.SetFontWeight(18000);
		btn->setText(TEXT("按钮被点击了"));
		break;
	}
	default:
		break;
	}
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
    win->oncreate = create;
	win->oncommand = command;
	bool a=win->create(500, 500, 100, 100, TEXT("窗口"));
	if (!a) return 1;
	win->show();
	win->loop();
	delete btn;
	return 0;
}