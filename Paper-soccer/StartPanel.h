#pragma once
#include "wx/wx.h"
#include "wx/notebook.h"
#include <wx/aui/aui.h>
class StartPanel : public wxPanel
{
private:

public:
	StartPanel(wxFrame* parent, const wxString& title);
	wxButton* startButton;
	wxButton* exitButton;
	void startOnClick(wxCommandEvent& event);
	void exitOnClick(wxCommandEvent& event);
};


