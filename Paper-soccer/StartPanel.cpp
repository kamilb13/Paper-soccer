#include "StartPanel.h"
#include <wx/mediactrl.h>
#include "BoardPanel.h"
#include <wx/statbmp.h>

StartPanel::StartPanel(wxFrame* parent, const wxString& title) : wxPanel(parent, wxID_ANY)
{
    /*

    wxImage image(wxT("C:/Users/Komputer/Desktop/PNGsy/ufo.png"), wxBITMAP_TYPE_PNG);
    wxBitmap bitmap(image);

    if (!image.IsOk())
    {
        wxMessageBox("Nie mo¿na wczytaæ obrazka.", "B³¹d", wxICON_ERROR | wxOK);
        return;
    }  

    wxStaticBitmap* backgroundBitmap = new wxStaticBitmap(this, wxID_ANY, bitmap);
    backgroundBitmap->SetSize(GetClientSize());
    SetSizer(new wxBoxSizer(wxVERTICAL));

    */
    //wxPanel* panel = new wxPanel(this, wxID_ANY);
    wxBoxSizer* mainSizer = new wxBoxSizer(wxVERTICAL);
    wxBoxSizer* buttonSizer = new wxBoxSizer(wxVERTICAL);

    wxStaticText* titleLabel = new wxStaticText(this, wxID_ANY, "Paper Soccer!", wxPoint(-1, -1), wxDefaultSize, wxALIGN_CENTER);
    titleLabel->SetFont(wxFont(24, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD));
    mainSizer->Add(titleLabel, 0, wxALL | wxALIGN_CENTER, 20);

    startButton = new wxButton(this, wxID_ANY, "START", wxDefaultPosition, wxSize(100, 60));
    startButton->Bind(wxEVT_BUTTON, &StartPanel::startOnClick, this);
     
    exitButton = new wxButton(this, wxID_ANY, "EXIT", wxDefaultPosition, wxSize(100, 60));
    exitButton->Bind(wxEVT_BUTTON, &StartPanel::exitOnClick, this);

    buttonSizer->Add(startButton, 0, wxALL, 10);
    buttonSizer->Add(exitButton, 0, wxALL, 10);

    mainSizer->AddStretchSpacer();
    mainSizer->Add(buttonSizer, 0, wxALIGN_CENTER);
    mainSizer->AddStretchSpacer();

    SetSizer(mainSizer);
}

void StartPanel::startOnClick(wxCommandEvent& event)
{
    BoardPanel* boardPanel = new BoardPanel(this->GetParent(), "SIEMANKO");
    boardPanel->SetClientSize(400, 500);
    this->Destroy();
}

void StartPanel::exitOnClick(wxCommandEvent& event)
{
    this->GetParent()->Destroy();
}