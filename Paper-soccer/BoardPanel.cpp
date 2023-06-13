#include "Field.h"
#include "Board.h"
#include <wx/button.h>
#include "BoardPanel.h"
#include "EndPanel.h"
#include "MainFrame.h"
#include <wx/sizer.h>

using namespace std;

BoardPanel::BoardPanel(wxWindow* parent, const wxString& title, int* p1, int* p2) : wxPanel(parent, wxID_ANY)
{
	this->p1 = p1;
	this->p2 = p2;
	this->SetBackgroundColour(wxColor(92, 178, 89, 200));
	Board* board = new Board(7, 11);
	wxPen boardLine(wxPen(wxColor(255, 255, 255), 10, wxPENSTYLE_SOLID));
	board->setCurrentField(board->getFields()[5][3]);

	wxString score1 = wxString::Format(wxString::Format("%d", *p1));
	wxString score2 = wxString::Format(wxString::Format("%d", *p2));

	player1Score = new wxStaticText(this, wxID_ANY, score1, wxPoint(10, 10));
	player2Score = new wxStaticText(this, wxID_ANY, score2, wxPoint(10, 40));

	auto boundTopGoal = std::bind(&BoardPanel::drawLine, this, std::placeholders::_1, &(board->current_x), &(board->current_y), -1, -1, board, &player);
	// WYŒWIETLANIE GÓREJ BRAMKI
	wxButton* btnTopGoal1 = new wxButton(this, wxID_ANY, " ", wxPoint(150, 20), wxSize(10, 10));
	btnTopGoal1->Disable();
	btnTopGoal1->SetBackgroundColour(wxColour(210, 210, 210, 1));
	wxButton* btnTopGoal2 = new wxButton(this, wxID_ANY, " ", wxPoint(180, 20), wxSize(10, 10));
	btnTopGoal2->Disable();
	btnTopGoal2->SetBackgroundColour(wxColour(210, 210, 210, 1));

	wxButton* btnTopGoal3 = new wxButton(this, wxID_ANY, " ", wxPoint(210, 20), wxSize(10, 10));

	btnTopGoal3->Disable();
	btnTopGoal3->SetBackgroundColour(wxColour(210, 210, 210, 1));

	btnTopGoal1->Bind(wxEVT_BUTTON, boundTopGoal);
	btnTopGoal2->Bind(wxEVT_BUTTON, boundTopGoal);
	btnTopGoal3->Bind(wxEVT_BUTTON, boundTopGoal);

	//wxButton* btnBottomGoal1 = new wxButton(this, wxID_ANY, " ", wxPoint(20 + 30 * 2, 20 + 30 * 1), wxSize(10, 10));
	board->getTopGoal1()->setFieldBtn(btnTopGoal1);
	board->getTopGoal2()->setFieldBtn(btnTopGoal2);
	board->getTopGoal3()->setFieldBtn(btnTopGoal3);

	// WYŒWIETLANIE DOLNEJ BRAMKI
	wxButton* btnBottomGoal1 = new wxButton(this, wxID_ANY, " ", wxPoint(150, 50 + 30 * board->getY()), wxSize(10, 10));
	btnBottomGoal1->Disable();
	btnBottomGoal1->SetBackgroundColour(wxColour(210, 210, 210, 1));
	wxButton* btnBottomGoal2 = new wxButton(this, wxID_ANY, " ", wxPoint(180, 50 + 30 * board->getY()), wxSize(10, 10));
	btnBottomGoal2->Disable();
	btnBottomGoal2->SetBackgroundColour(wxColour(210, 210, 210, 1));
	auto boundBottomGoal = std::bind(&BoardPanel::drawLine, this, std::placeholders::_1, &(board->current_x), &(board->current_y), -2, -1, board, &player);
	btnBottomGoal2->Bind(wxEVT_BUTTON, boundBottomGoal);

	wxButton* btnBottomGoal3 = new wxButton(this, wxID_ANY, " ", wxPoint(210, 50 + 30 * board->getY()), wxSize(10, 10));
	btnBottomGoal3->Disable();
	btnBottomGoal3->SetBackgroundColour(wxColour(210, 210, 210, 1));

	btnBottomGoal1->Bind(wxEVT_BUTTON, boundBottomGoal);
	btnBottomGoal2->Bind(wxEVT_BUTTON, boundBottomGoal);
	btnBottomGoal3->Bind(wxEVT_BUTTON, boundBottomGoal);

	//wxButton* btnBottomGoal1 = new wxButton(this, wxID_ANY, " ", wxPoint(20 + 30 * 2, 20 + 30 * 1), wxSize(10, 10));
	board->getBottomGoal1()->setFieldBtn(btnBottomGoal1);
	board->getBottomGoal2()->setFieldBtn(btnBottomGoal2);
	board->getBottomGoal3()->setFieldBtn(btnBottomGoal3);

	for (int i = 0; i < board->getY(); i++) {
		for (int j = 0; j < board->getX(); j++) {
			if (j == 0 || i == 0 || j == board->getX() - 1 || i == board->getY() - 1) {	// Nadawanie skrajnym pozycjom board setVisited na true
				board->getFieldAt(j, i)->setVisited(true);
			}

			wxButton* fieldButton = new wxButton(this, wxID_ANY, " ", wxPoint(90 + 30 * j, 50 + 30 * i), wxSize(10, 10));

			board->getFieldAt(j, i)->setFieldBtn(fieldButton);
			board->getFieldAt(j, i)->getFieldBtn()->Disable();	//
			board->getFieldAt(j, i)->getFieldBtn()->SetBackgroundColour(wxColour(210, 210, 210, 1));	//
			auto boundDrawLine = std::bind(&BoardPanel::drawLine, this, std::placeholders::_1, &(board->current_x), &(board->current_y), j, i, board, &player);
			wxLogStatus(wxString::Format("%d", board->getFieldAt(j, i)->checkMoves()));

			if (!(board->getFieldAt(j, i)->checkMoves()))	// BLOKOWANIE MO¯LIOWŒCI WEJŒCIA W NARO¯NIKI
			{
				auto boundDrawLine = std::bind(&BoardPanel::drawLine, this, std::placeholders::_1, &(board->current_x), &(board->current_y), -1, -1, board, &player);
				continue;
			}
					
			fieldButton->Bind(wxEVT_BUTTON, boundDrawLine);
		}
	}

	// JEZELI ISTNIEJA (PRZEROBIC)
	board->getCurrentField().getLG()->getFieldBtn()->Enable();
	board->getCurrentField().getLG()->getFieldBtn()->SetBackgroundColour(wxColour(255, 0, 0, 1));

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

void BoardPanel::drawLine(wxCommandEvent& event, int* current_x, int* current_y, int destiny_x, int destiny_y, Board* board, bool* player)
{
	if (destiny_x == -1) {
		*p1 = *p1 + 1;
		BoardPanel* bp = new BoardPanel(this->GetParent(), "PAPER SOCCER", p1, p2);
		bp->SetClientSize(400, 500);
		this->Destroy();
		return;
	}

	if (destiny_x == -2) {
		*p2 = *p2 + 1;
		BoardPanel* bp = new BoardPanel(this->GetParent(), "PAPER SOCCER", p1, p2);
		bp->SetClientSize(400, 500);
		this->Destroy();
		return;
	}

	wxClientDC dc(this);
	dc.SetPen(wxPen(wxColor(0, 0, 255), 3, wxPENSTYLE_SOLID));	// czerwony dla player == 0
	if (*player == 1) {											// czerwony dla player == 1
		dc.SetPen(wxPen(wxColor(255, 0, 0), 3, wxPENSTYLE_SOLID));
	}

	// ustawienie koloru linii na czerwony o gruboœci 1 piksela	
	wxPoint source((*current_x * 30) + 90 + 5, (*current_y * 30) + 50 + 5);
	wxPoint destiny(destiny_x * 30 + 90 + 5, destiny_y * 30 + 50 + 5);
	dc.DrawLine(source, destiny);

	this->blockField(current_x, current_y, destiny_x, destiny_y, board);
	this->switchCurrentField(current_x, current_y, destiny_x, destiny_y, board, player);
}

void BoardPanel::blockField(int* current_x, int* current_y, int destiny_x, int destiny_y, Board* board) {
	Field* nullField = nullptr;
	Field* current = board->getFieldAt(*current_x, *current_y);
	Field* destiny = board->getFieldAt(destiny_x, destiny_y);

	if (board->getFieldAt(*current_x, *current_y)->getLG() == destiny) {
		board->getFieldAt(*current_x, *current_y)->setLG(nullptr);
		destiny->setPD(nullptr);
	}

	if (board->getFieldAt(*current_x, *current_y)->getG() == destiny) {
		current->setG(nullptr);
		destiny->setD(nullptr);
	}

	if (current->getPG() == destiny) {
		current->setPG(nullptr);
		destiny->setLD(nullptr);
	}

	if (current->getL() == destiny) {
		current->setL(nullptr);
		destiny->setP(nullptr);
	}

	if (current->getP() == destiny) {
		current->setP(nullptr);
		destiny->setL(nullptr);
	}

	if (current->getPD() == destiny) {
		current->setPD(nullptr);
		destiny->setLG(nullptr);
	}

	if (current->getD() == destiny) {
		current->setD(nullptr);
		destiny->setG(nullptr);
	}

	if (current->getLD() == destiny) {
		current->setLD(nullptr);
		destiny->setPG(nullptr);
	}
}

void BoardPanel::switchPlayer(Field* field, bool* player, Board* board) {
	if (!field->getVisited()) {
		bool temp = !(*player);
		*player = temp;
	}
}

void BoardPanel::switchCurrentField(int* current_x, int* current_y, int destiny_x, int destiny_y, Board* board, bool* player)
{
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

	switchPlayer(board->getFieldAt(destiny_x, destiny_y), player, board);

	board->getFieldAt(destiny_x, destiny_y)->setVisited(true);

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


