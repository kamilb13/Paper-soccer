#include "MainFrame.h"
#include "StartFrame.h"
#include "BoardFrame.h"
#include "wx/wx.h"
#include "BoardPanel.h"

MainFrame::MainFrame(const wxString& title) : wxFrame(nullptr, wxID_ANY, title)
{
	// DO MAINFRAME Przenieœæ
	BoardPanel* boardPanel = new BoardPanel(this, "BoardPanel");
	
	
	//BoardFrame* boardFrame = new BoardFrame("Paper Soccer");
	//StartFrame* startFrame = new StartFrame("Paper Soccer");
	//boardFrame->SetClientSize(400, 500);
	//startFrame->SetClientSize(400, 500);
	//startFrame->Show();
	//boardFrame->Show();
}

