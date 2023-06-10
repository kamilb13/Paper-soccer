#pragma once
#include "wx/wx.h"
#include <wx/notebook.h>
#include <wx/aui/aui.h>

class MainFrame : public wxFrame
{
public:
    MainFrame(const wxString& title);
    int scorePlayer_1 = 0;
    int scorePlayer_2 = 0;
};