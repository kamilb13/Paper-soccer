#pragma once
#include "wx/wx.h"

class EndPanel : public wxPanel
{
private:

public:
	EndPanel(wxWindow* parent, const wxString& title);
	wxButton* exitButton;
	void exitOnClick(wxCommandEvent& event);
};

