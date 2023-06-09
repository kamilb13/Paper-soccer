#include "BoardFrame.h"
#include "Field.h"
#include "Board.h"
#include <wx/button.h>

using namespace std;

BoardFrame::BoardFrame(const wxString& title) : wxFrame(nullptr, wxID_ANY, title)
{
	Board* board = new Board(7, 11);
	wxPen boardLine(wxPen(wxColor(255, 255, 255), 10, wxPENSTYLE_SOLID));
	board->setCurrentField(board->getFields()[5][3]);
	wxColour* disabledBtnColor = new wxColour(50, 50, 50, 0);
	bool player = true;
	
	wxClientDC line(this);
	line.SetPen(boardLine);

	wxPoint source(20, 20);
	wxPoint destiny(500, 20);

	line.DrawLine(source, destiny);
	
	for (int i = 0; i < board->getY(); i++) {
		for (int j = 0; j < board->getX(); j++) {
			wxButton* fieldButton = new wxButton(this, wxID_ANY, " ", wxPoint(20 + 30 * j, 20 + 30 * i), wxSize(10, 10));
			board->getFieldAt(j, i)->setFieldBtn(fieldButton);
			board->getFieldAt(j, i)->getFieldBtn()->Disable();	//
			board->getFieldAt(j, i)->getFieldBtn()->SetBackgroundColour(wxColour(210, 210, 210,1));	//
			auto boundDrawLine = std::bind(&BoardFrame::drawLine, this, std::placeholders::_1, &(board->current_x), &(board->current_y), j, i, board, &player);
			fieldButton->Bind(wxEVT_BUTTON, boundDrawLine);
		}

	}

	// JEZELI ISTNIEJA (PRZEROBIC)
	board->getCurrentField().getLG()->getFieldBtn()->Enable();
	board->getCurrentField().getLG()->getFieldBtn()->SetBackgroundColour(wxColour(255,0, 0, 1));

	board->getCurrentField().getG()->getFieldBtn()->Enable();
	board->getCurrentField().getG()->getFieldBtn()->SetBackgroundColour(wxColour(255, 0, 0, 1));

	board->getCurrentField().getPG()->getFieldBtn()->Enable();
	board->getCurrentField().getPG()->getFieldBtn()->SetBackgroundColour(wxColour(255, 0, 0, 1));
	
	board->getCurrentField().getL()->getFieldBtn()->Enable();
	board->getCurrentField().getL()->getFieldBtn()->SetBackgroundColour(wxColour(255, 0, 0, 1));
	
	board->getCurrentField().getP()->getFieldBtn()->Enable();
	board->getCurrentField().getP()->getFieldBtn()->SetBackgroundColour(wxColour(255, 0, 0, 1));
	
	board->getCurrentField().getLD()->getFieldBtn()->Enable();
	board->getCurrentField().getLD()->getFieldBtn()->SetBackgroundColour(wxColour(255, 0, 0, 1));
	
	board->getCurrentField().getD()->getFieldBtn()->Enable();
	board->getCurrentField().getD()->getFieldBtn()->SetBackgroundColour(wxColour(255, 0, 0, 1));
	
	board->getCurrentField().getPD()->getFieldBtn()->Enable();
	board->getCurrentField().getPD()->getFieldBtn()->SetBackgroundColour(wxColour(255, 0, 0, 1));
}



void BoardFrame::drawLine(wxCommandEvent& event, int* current_x, int* current_y, int destiny_x, int destiny_y, Board* board, bool *player) 
{
		wxClientDC dc(this);
		// ustawienie koloru linii na czerwony o grubości 1 piksela
		dc.SetPen(wxPen(wxColor(255, 0, 0), 3, wxPENSTYLE_SOLID));
		wxPoint source((*current_x * 30) + 20 + 5, (*current_y * 30) + 20 + 5);
		wxPoint destiny(destiny_x * 30 + 20 + 5, destiny_y * 30 + 20 + 5);
		dc.DrawLine(source, destiny);
		
		this->switchCurrentField(current_x, current_y, destiny_x, destiny_y, board, player);
		
}

void BoardFrame::switchCurrentField(int* current_x, int* current_y, int destiny_x, int destiny_y, Board* board, bool *player)
{
	CreateStatusBar();

	wxColour enabledButton(255, 0, 0, 1);
	wxColour disabledButton(210, 210, 210, 1);
	*current_x = destiny_x;
	*current_y = destiny_y;

	


	if (board->getCurrentField().getLG()) {
		board->getCurrentField().getLG()->getFieldBtn()->Disable();
		board->getCurrentField().getLG()->getFieldBtn()->SetBackgroundColour(disabledButton);
	}
		

	if (board->getCurrentField().getG()) {
		board->getCurrentField().getG()->getFieldBtn()->Disable();
		board->getCurrentField().getG()->getFieldBtn()->SetBackgroundColour(disabledButton);
	}
		
	
	if (board->getCurrentField().getPG()) {
		board->getCurrentField().getPG()->getFieldBtn()->Disable();
		board->getCurrentField().getPG()->getFieldBtn()->SetBackgroundColour(disabledButton);
	}
		
	
	if (board->getCurrentField().getL()) {
		board->getCurrentField().getL()->getFieldBtn()->Disable();
		board->getCurrentField().getL()->getFieldBtn()->SetBackgroundColour(disabledButton);
	}
		
	
	if (board->getCurrentField().getP()) {
		board->getCurrentField().getP()->getFieldBtn()->Disable();
		board->getCurrentField().getP()->getFieldBtn()->SetBackgroundColour(disabledButton);
	}
		
	
	if (board->getCurrentField().getLD()) {
		board->getCurrentField().getLD()->getFieldBtn()->Disable();
		board->getCurrentField().getLD()->getFieldBtn()->SetBackgroundColour(disabledButton);
	}
		
	
	if (board->getCurrentField().getD()) {
		board->getCurrentField().getD()->getFieldBtn()->Disable();
		board->getCurrentField().getD()->getFieldBtn()->SetBackgroundColour(disabledButton);
	}
		
	
	if (board->getCurrentField().getPD()) {
		board->getCurrentField().getPD()->getFieldBtn()->Disable();
		board->getCurrentField().getPD()->getFieldBtn()->SetBackgroundColour(disabledButton);
	}
		

	board->setCurrentField(*(board->getFieldAt(destiny_x, destiny_y)));

	if(!(board->getFieldAt(destiny_x, destiny_y)->getVisited())){
		*player = !(*player);
	}

	board->getFieldAt(destiny_x, destiny_y)->setVisited(1);

	wxLogStatus("%d", player);

	// JEZELI ISTNIEJA (PRZEROBIC)
	if (board->getCurrentField().getLG()) {
		board->getCurrentField().getLG()->getFieldBtn()->Enable();
		board->getCurrentField().getLG()->getFieldBtn()->SetBackgroundColour(enabledButton);
	}
		

	if (board->getCurrentField().getG()) {
		board->getCurrentField().getG()->getFieldBtn()->Enable();
		board->getCurrentField().getG()->getFieldBtn()->SetBackgroundColour(enabledButton);

	}
	
	if (board->getCurrentField().getPG()) {

		board->getCurrentField().getPG()->getFieldBtn()->Enable();
		board->getCurrentField().getPG()->getFieldBtn()->SetBackgroundColour(enabledButton);
	}

	if (board->getCurrentField().getL()) {
		board->getCurrentField().getL()->getFieldBtn()->Enable();
		board->getCurrentField().getL()->getFieldBtn()->SetBackgroundColour(enabledButton);
	}
		

	if (board->getCurrentField().getP()) {
		board->getCurrentField().getP()->getFieldBtn()->Enable();
		board->getCurrentField().getP()->getFieldBtn()->SetBackgroundColour(enabledButton);
	}
		

	if (board->getCurrentField().getLD()) {
		board->getCurrentField().getLD()->getFieldBtn()->Enable();
		board->getCurrentField().getLD()->getFieldBtn()->SetBackgroundColour(enabledButton);
	}

	if (board->getCurrentField().getD()) {
		board->getCurrentField().getD()->getFieldBtn()->Enable();
		board->getCurrentField().getD()->getFieldBtn()->SetBackgroundColour(enabledButton);
	}
		

	if (board->getCurrentField().getPD()) {
		board->getCurrentField().getPD()->getFieldBtn()->Enable();
		board->getCurrentField().getPD()->getFieldBtn()->SetBackgroundColour(enabledButton);
	}
		
}



