#include "StartPanel.h"
#include <wx/mediactrl.h>
#include "BoardPanel.h"
#include <wx/statbmp.h>
#include <wx/sound.h>

StartPanel::StartPanel(wxFrame* parent, const wxString& title, int* p1, int* p2) : wxPanel(parent, wxID_ANY)
{
    this->p1 = p1;
    this->p2 = p2;
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
    BoardPanel* boardPanel = new BoardPanel(this->GetParent(), "SIEMANKO", p1, p2);
    boardPanel->SetClientSize(400, 500);
    this->Destroy();
}

void StartPanel::exitOnClick(wxCommandEvent& event)
{
    this->GetParent()->Destroy();
}

void StartPanel::PlaySound()
{
    // Ścieżka do pliku dźwiękowego
    wxString soundFile = "C:/Users/kamil/Desktop/soccer-stadium.wav";  //C:\Users\kamil\Desktop\soccer-stadium.wav

    wxSound sound(soundFile);
    if (sound.IsOk()){
        // Odtwarzanie dźwięku
        sound.Play(wxSOUND_ASYNC);
    }
    else{
        wxMessageBox("Nie można odtworzyć dźwięku.", "Błąd", wxOK | wxICON_ERROR);
    }
}