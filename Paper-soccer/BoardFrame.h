#pragma once
#include "Field.h"
#include "Board.h"
#include "wx/wx.h"



using namespace std;

class BoardFrame : public wxFrame
{
private:
	
public:
	BoardFrame(const wxString& title);
	void drawLine(wxCommandEvent& event, int* current_x, int* current_y, int destiny_x, int destiny_y, Board* board, bool* player);
	void switchCurrentField(int* current_x, int* current_y, int destiny_x, int destiny_y, Board* board, bool* player);
};