#include "App.h"
#include <wx/wx.h>
#include "BoardFrame.h"
#include "StartFrame.h"
#include "MainFrame.h"

using namespace std;
wxIMPLEMENT_APP(App);

bool App::OnInit() {
	MainFrame* mainFrame = new MainFrame("Paper Soccer");

	mainFrame->SetClientSize(400, 500);

	mainFrame->Show();

	return true;
}