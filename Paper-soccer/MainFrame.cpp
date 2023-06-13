#include "MainFrame.h"
#include "wx/wx.h"
#include "BoardPanel.h"
#include "StartPanel.h"
#include <wx/notebook.h>

MainFrame::MainFrame(const wxString& title) : wxFrame(nullptr, wxID_ANY, title)
{
    //Tworzenie panelu startowego
    StartPanel* startPanel = new StartPanel(this, "", &(this->scorePlayer_1), &(this->scorePlayer_2));
    startPanel->SetClientSize(550, 600);
    startPanel->PlaySound();
}
