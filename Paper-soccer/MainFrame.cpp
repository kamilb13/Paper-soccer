#include "MainFrame.h"
#include "StartFrame.h"
#include "BoardFrame.h"
#include "wx/wx.h"
#include "BoardPanel.h"
#include "StartPanel.h"

MainFrame::MainFrame(const wxString& title) : wxFrame(nullptr, wxID_ANY, title)
{

	//wxMediaCtrl* m_mediaCtrl = new wxMediaCtrl(this, wxID_ANY, "C:/Users/Komputer/Downloads/INTRO.avi",
		//wxDefaultPosition, wxDefaultSize,0L,wxEmptyString, wxMEDIABACKEND_DIRECTSHOW,L"mediaCtrl",);

	// Wczytanie pliku wideo
	//m_mediaCtrl->Load("C:/Users/Komputer/Downloads/UEFA.mp4");

	// Ustawienie rozmiaru i pozycji wxMediaCtrl
	//m_mediaCtrl->SetSize(wxSize(400, 500));
	//m_mediaCtrl->SetPosition(wxPoint(0, 0));
	// DO MAINFRAME Przenie��
	//StartPanel* startPanel = new StartPanel(this, "StartPanel");
	CreateStatusBar();
	BoardPanel* boardPanel = new BoardPanel(this, "BoardPanel");
	



	//BoardFrame* boardFrame = new BoardFrame("Paper Soccer");
	//StartFrame* startFrame = new StartFrame("Paper Soccer");
	//boardFrame->SetClientSize(400, 500);
	//startFrame->SetClientSize(400, 500);
	//startFrame->Show();
	//boardFrame->Show();
}
