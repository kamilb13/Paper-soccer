#include "EndPanel.h"

EndPanel::EndPanel(wxWindow* parent, const wxString& title) : wxPanel(parent, wxID_ANY)
{
    wxBoxSizer* mainSizer = new wxBoxSizer(wxVERTICAL);
    wxBoxSizer* buttonSizer = new wxBoxSizer(wxVERTICAL);

    wxStaticText* titleLabel = new wxStaticText(this, wxID_ANY, "Koniec!", wxPoint(-1, -1), wxDefaultSize, wxALIGN_CENTER);
    titleLabel->SetFont(wxFont(24, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD));
    mainSizer->Add(titleLabel, 0, wxALL | wxALIGN_CENTER, 20);

    exitButton = new wxButton(this, wxID_ANY, "EXIT", wxPoint(100, 100), wxSize(100, 100));
    exitButton->Bind(wxEVT_BUTTON, &EndPanel::exitOnClick, this);

    buttonSizer->Add(exitButton, 0, wxALL, 10);

    mainSizer->AddStretchSpacer();
    mainSizer->Add(buttonSizer, 0, wxALIGN_CENTER);
    mainSizer->AddStretchSpacer();

    SetSizer(mainSizer);
}

void EndPanel::exitOnClick(wxCommandEvent& event)
{
    this->GetParent()->Destroy();
}