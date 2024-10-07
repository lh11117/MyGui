#define WINXGUI_SHOW_DEBUG
#define WINXGUI_USE_NEW_STYLE
#include "WinXGuiAll.h"
#include "WinXGuiConfig.h"

wxg::Button *btn1, *btn2, *btn3, *btn4;
wxg::Label *lbl1, *lbl2, *lbl3;
wxg::Entry *ent1;
wxg::Checkbox *chk1, *chk2;
wxg::Window w(TEXT("Another Window"));
class MyGui : public wxg::Window
{
	static int close_msg(HWND h, UINT, WPARAM, LPARAM) {
		bool result = MessageBox(h,L"Are you sure to exit?",L"Tip",MB_YESNO)==IDNO;
		if (!result) {
			w.Close();
		}
		return result;
	}
public:
    MyGui() : wxg::Window(TEXT("MyGui")) {
		onclose = close_msg;
		if (!Create(500, 500, 100, 100)) {
		    exit(GetLastError());
		}
		btn1 = new wxg::Button(this, TEXT("Button 1"), wxg::WinPos(100, 40, 10, 10));
		btn2 = new wxg::Button(this, TEXT("Button 2"), wxg::WinPos(100, 40, 10, 60));
		btn3 = new wxg::Button(this, TEXT("Button 3"), wxg::WinPos(100, 40, 10, 110));
		lbl1 = new wxg::Label(this, TEXT("Label 1"), wxg::WinPos(150, 40, 120, 10));
		lbl2 = new wxg::Label(this, TEXT("Label 2"), wxg::WinPos(150, 40, 120, 60));
		lbl3 = new wxg::Label(this, TEXT("Label 3"), wxg::WinPos(150, 40, 120, 110));
		ent1 = new wxg::Entry(this, wxg::WinPos(200, 200, 20, 200), TRUE);
		chk1 = new wxg::Checkbox(this, TEXT("ReadOnly"), wxg::WinPos(100, 20, 250, 200));
		chk2 = new wxg::Checkbox(this, TEXT("Enabled Button"), wxg::WinPos(150, 20, 250, 250));
		btn4 = new wxg::Button(this, TEXT("Another Window"), wxg::WinPos(150, 40, 250, 300));
		btn4->SetEnabled(1);
		btn1->oncommand = btn1_click;
		btn2->oncommand = btn2_click;
		btn3->oncommand = btn3_click;
		btn4->oncommand = btn4_click;
		ent1->oncommand = ent1_inputing;
		chk1->oncommand = chk1_checked;
		chk2->oncommand = chk2_checked;
		Show();
	}

	static void btn1_click(HWND, UINT, WPARAM, LPARAM) {
		lbl1->SetText(TEXT("Button 1 clicked"));
	}
	static void btn2_click(HWND, UINT, WPARAM, LPARAM) {
		lbl2->SetText(TEXT("Button 2 clicked"));
		ent1->SetPassword(1);
	}
	static void btn3_click(HWND, UINT, WPARAM, LPARAM) {
		lbl3->SetText(TEXT("Button 3 clicked"));
		ent1->AppendText(TEXT("Hello, world! \r\n"));
	}
	static void btn4_click(HWND, UINT, WPARAM, LPARAM) {
		if (w.IsShow())
			w.Hide();
		else
			w.Show();
	}
	static void ent1_inputing(HWND, UINT, WPARAM, LPARAM) {
		lbl3->SetText(TEXT("Entry 1 input"));
		OutputDebugString(ent1->GetText());
		OutputDebugStringA("\n");
	}
	static void chk1_checked(HWND, UINT, WPARAM, LPARAM) {
		ent1->SetReadOnly(chk1->IsChecked());
	}
	static void chk2_checked(HWND, UINT, WPARAM, LPARAM) {
		btn4->SetEnabled(chk2->IsChecked());
	}
};


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
	wxg::Label(&w, TEXT("There is nothing!"), wxg::WinPos(150, 40, 120, 10));
	app.Exec();
	delete gui;
	return 0;
}