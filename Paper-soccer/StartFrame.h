#pragma once
#include "wx/wx.h"



class StartFrame : public wxFrame
{
public:
	StartFrame(const wxString& title);
	void startOnClick(wxCommandEvent& event);
	void exitOnClick(wxCommandEvent& event);
};

