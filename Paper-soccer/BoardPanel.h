#pragma once
#include "Field.h"
#include "Board.h"
#include "wx/wx.h"

using namespace std;

class BoardPanel : public wxPanel
{
private:
	
public:
	BoardPanel(wxFrame* parent, const wxString& title); 
	void drawLine(wxCommandEvent& event, int* current_x, int* current_y, int destiny_x, int destiny_y, Board* board);
	void switchCurrentField(int* current_x, int* current_y, int destiny_x, int destiny_y, Board* board);
	void blockField(int* current_x, int* current_y, int destiny_x, int destiny_y, Board* board);
};
