#pragma once
#include "wx/wx.h"
#include "wx/notebook.h"
#include <wx/aui/aui.h>
class StartPanel : public wxPanel
{
private:

public:
	StartPanel(wxFrame* parent, const wxString& title, int* p1, int* p2);
	wxButton* startButton;
	wxButton* exitButton;
	int* p1;
	int* p2;
	void startOnClick(wxCommandEvent& event);
	void exitOnClick(wxCommandEvent& event);
	void PlaySound();
};

