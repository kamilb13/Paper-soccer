#include "App.h"
#include <wx/wx.h>
#include "MainFrame.h"

using namespace std;
wxIMPLEMENT_APP(App);

bool App::OnInit() 
{
	// Deklaracja i inicjacja g³ównego okna gry
	MainFrame* mainFrame = new MainFrame("Paper Soccer");

	// Inicjacja rozmiaru okna
	mainFrame->SetClientSize(400, 410);

	// Wyœwietlenie okna 
	mainFrame->Show();
	return true;
}