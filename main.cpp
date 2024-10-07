#define WINXGUI_SHOW_DEBUG
#define WINXGUI_USE_NEW_STYLE
#include "WinXGuiAll.h"
#include "WinXGuiConfig.h"

wxg::Button *btn1, *btn2, *btn3, *btn4;
wxg::Label *lbl1, *lbl2, *lbl3;
wxg::Entry *ent1;
wxg::Checkbox *chk1;
wxg::Window w(TEXT("Another Window"));
class MyGui : public wxg::Window
{
	static void create_msg(HWND, UINT, WPARAM, LPARAM);
	static void command_msg(HWND, UINT, WPARAM, LPARAM);
	static int close_msg(HWND h, UINT, WPARAM, LPARAM) {
		bool result = MessageBox(h,L"Are you sure to exit?",L"Tip",MB_YESNO)==IDNO;
		if (!result) {
			w.Close();
		}
		return result;
	}
public:
    MyGui() : wxg::Window(TEXT("MyGui")) {
		oncreate = create_msg;
		oncommand = command_msg;
		onclose = close_msg;
		if (!Create(500, 500, 100, 100)) {
		    exit(GetLastError());
		}
		Show();
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
	ent1 = new wxg::Entry(hwnd, wxg::WinPos(200, 200, 20, 200), 4, TRUE);
	chk1 = new wxg::Checkbox(hwnd, TEXT("ReadOnly"), wxg::WinPos(100, 20, 250, 200), 5);
	btn4 = new wxg::Button(hwnd, TEXT("Another Window"), wxg::WinPos(150, 40, 250, 250), 6);
	btn4->SetEnabled(0);
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
		ent1->SetPassword(1);
		break;
	case 3: {
		lbl3->SetText(TEXT("Button 3 clicked"));
		ent1->AppendText(TEXT("Hello, world! \r\n"));
		break;
	}
	case 4:
		break;
	case 5:
		ent1->SetReadOnly(chk1->IsChecked());
		break;
	case 6: {
		if (w.IsShow())
			w.Hide();
		else
		    w.Show();
	}
	}
}

int OnAnotherWindowClose(HWND, UINT, WPARAM, LPARAM) {
	w.Hide();
	return 1;
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	wxg::App app(L"MyGui");
    MyGui* gui = new MyGui();
	w.Create(500, 500, 600, 600);
	w.onclose = OnAnotherWindowClose;
	wxg::Label(w.hwnd(), TEXT("There is nothing!"), wxg::WinPos(150, 40, 120, 10));
	app.Exec();
	delete gui;
	return 0;
}