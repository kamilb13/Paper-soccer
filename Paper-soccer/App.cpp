#include "App.h"
#include <wx/wx.h>
#include "BoardFrame.h"

using namespace std;
wxIMPLEMENT_APP(App);

bool App::OnInit() {
	BoardFrame* boardFrame = new BoardFrame("Paper Soccer");
	boardFrame->SetClientSize(400, 500);
	boardFrame->Show();
	return true;
}
