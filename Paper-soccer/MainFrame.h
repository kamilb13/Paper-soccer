#pragma once
#include "wx/wx.h"
#include <wx/notebook.h>
#include <wx/aui/aui.h>

class MainFrame : public wxFrame
{
public:
    int page = 1;
    MainFrame(const wxString& title);
    void startOnClick(wxCommandEvent& event);
    void exitOnClick(wxCommandEvent& event);
};