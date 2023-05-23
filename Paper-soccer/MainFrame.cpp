#include "MainFrame.h"
#include "BoardFrame.h"
#include "wx/wx.h"
#include "BoardPanel.h"
#include "StartPanel.h"
#include <wx/notebook.h>

MainFrame::MainFrame(const wxString& title) : wxFrame(nullptr, wxID_ANY, title)
{
    CreateStatusBar();

    StartPanel* startPanel = new StartPanel(this, "");
    startPanel->SetClientSize(550, 800);

}

void MainFrame::startOnClick(wxCommandEvent& event)
{
    wxLogStatus("KLIKAM");
    
}

void MainFrame::exitOnClick(wxCommandEvent& event)
{
    this->Destroy();
}