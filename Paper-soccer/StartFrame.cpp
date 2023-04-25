#include "StartFrame.h"
#include "wx/wx.h"


StartFrame::StartFrame(const wxString& title) : wxFrame(nullptr, wxID_ANY, title)
{
	wxPanel* panel = new wxPanel(this, wxID_ANY);

	wxButton* startBtn = new wxButton(panel, wxID_ANY, "START", wxPoint(100, 100), wxSize(100, 50));

	wxButton* exitBtn = new wxButton(panel, wxID_ANY, "EXIT", wxPoint(250, 100), wxSize(100, 50));
}
