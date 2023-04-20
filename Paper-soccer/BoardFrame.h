#pragma once
#include <wx/wx.h>
using namespace std;
class BoardFrame : public wxFrame
{
private:
	int x = 7;
	int y = 11;

public:
	int current_x = 110;
	int current_y = 170;
	BoardFrame(const wxString& title);
	void drawLine(wxCommandEvent& event, int* x1, int* y1, int x2, int y2);
};
