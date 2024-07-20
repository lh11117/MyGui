#include "WinXGuiAll.h"

#define WINXGUI_USE_NEW_STYLE
#include "WinXGuiConfig.h"

wxg::Button *btn1, *btn2, *btn3;
wxg::Label *lbl1, *lbl2, *lbl3;
class MyGui : public wxg::Window
{
	static void create_msg(HWND, UINT, WPARAM, LPARAM);
	static void command_msg(HWND, UINT, WPARAM, LPARAM);
public:
    MyGui() : wxg::Window(TEXT("MyGui"), TEXT("MyGui")) {
		oncreate = create_msg;
		oncommand = command_msg;
		if (!create(500, 500, 100, 100)) {
		    exit(GetLastError());
		}
		show();
		loop();
	}
};

void MyGui::create_msg(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	// Create controls
	btn1 = new wxg::Button(hwnd, TEXT("Button 1"), wxg::WinPos(100, 40, 10, 10), 1);
	btn2 = new wxg::Button(hwnd, TEXT("Button 2"), wxg::WinPos(100, 40, 10, 60), 2);
	btn3 = new wxg::Button(hwnd, TEXT("Button 3"), wxg::WinPos(100, 40, 10, 110), 3);
	lbl1 = new wxg::Label(hwnd, TEXT("Label 1"), wxg::WinPos(150, 40, 120, 10));
	lbl2 = new wxg::Label(hwnd, TEXT("Label 2"), wxg::WinPos(150, 40, 120, 60));
	lbl3 = new wxg::Label(hwnd, TEXT("Label 3"), wxg::WinPos(150, 40, 120, 110));
}

void MyGui::command_msg(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	// Handle button clicks
	switch (LOWORD(wParam)) {
	case 1:
		lbl1->SetText(TEXT("Button 1 clicked"));
		break;
	case 2:
		lbl2->SetText(TEXT("Button 2 clicked"));
		break;
	case 3:
		lbl3->SetText(TEXT("Button 3 clicked"));
		break;
	}
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
    MyGui* gui = new MyGui();
	delete gui;
	return 0;
}