#pragma once
#include "Field.h"
#include "Board.h"
#include "wx/wx.h"

using namespace std;

class BoardPanel : public wxPanel
{
private:
	bool player = true;
public:
	BoardPanel(wxFrame* parent, const wxString& title); 
	void drawLine(wxCommandEvent& event, int* current_x, int* current_y, int destiny_x, int destiny_y, Board* board, bool* player);
	void switchPlayer(Field* field, bool* player, Board* board);
	void switchCurrentField(int* current_x, int* current_y, int destiny_x, int destiny_y, Board* board, bool* player);
	void blockField(int* current_x, int* current_y, int destiny_x, int destiny_y, Board* board);
};
