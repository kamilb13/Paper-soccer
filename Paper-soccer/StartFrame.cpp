#include "StartFrame.h"
#include "wx/wx.h"

StartFrame::StartFrame(const wxString& title) : wxFrame(nullptr, wxID_ANY, title)
{
    CreateStatusBar();

    wxPanel* panel = new wxPanel(this, wxID_ANY);

    //auto startBtn = std::bind(&BoardPanel::drawLine, this, std::placeholders::_1, &(board->current_x), &(board->current_y), -1, -1, board, &player);
    //startBtn->Bind(wxEVT_BUTTON, boundCosTam);

    wxButton* startBtn = new wxButton(panel, wxID_ANY, "START", wxPoint(100, 100), wxSize(100, 50));
    wxButton* exitBtn = new wxButton(panel, wxID_ANY, "EXIT", wxPoint(250, 100), wxSize(100, 50));
    startBtn->Bind(wxEVT_BUTTON, &StartFrame::startOnClick, this);
    exitBtn->Bind(wxEVT_BUTTON, &StartFrame::exitOnClick, this);
    int starframe = 1;

}

void StartFrame::startOnClick(wxCommandEvent& event)
{
    wxLogStatus("START");
}

void StartFrame::exitOnClick(wxCommandEvent& event)
{
    wxLogStatus("EXIT");
}