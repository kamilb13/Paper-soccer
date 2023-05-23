#include "Board.h"
#include <vector>



using namespace std;

Board::Board(int x, int y) {
	this->x = x;
	this->y = y;

	this->current_x = x / 2;
	this->current_y = y / 2;

	for (int i = 0; i < y; i++) {
		vector<Field> row;
		for (int j = 0; j < x; j++) {
			Field f;
			f.setX(i);
			f.setY(j);
			row.push_back(f);
		}
		this->fields.push_back(row);
	}

	//this->currentField = this->fields[y / 2][x / 2]);

	for (int i = 0; i < y; i++)
	{
		for (int j = 0; j < x; j++) {

			// Tworzenie przycisków
			this->fields[i][j].setVisited(false);

			

			if (i == 0) {          // USTAWIAM WSKAZNIKI W PIERWSZYM WIERSZU
				if (j == 0) {
					this->fields[i][j].setPD(&(this->fields[i + 1][j + 1]));
					continue;
				}


				if (j == x - 1) {
					this->fields[i][j].setLD(&(this->fields[i + 1][j - 1]));
					continue;
				}

				if (j > 0 && j < x - 1) {
					this->fields[i][j].setLD(&(this->fields[i + 1][j - 1]));
					this->fields[i][j].setD(&(this->fields[i + 1][j]));
					this->fields[i][j].setPD(&(this->fields[i + 1][j + 1]));
					continue;
				}
			}
			else if (i == y - 1) {  // USTAWIAM WSKAZNIKI W OSTATNIM WIERSZU
				if (j == 0) {
					this->fields[i][j].setPG(&(this->fields[i - 1][j + 1]));
					continue;
				}


				if (j == x - 1) {
					this->fields[i][j].setLG(&(this->fields[i - 1][j - 1]));
					continue;
				}

				if (j > 0 && j < x - 1) {
					this->fields[i][j].setLG(&(this->fields[i - 1][j - 1]));
					this->fields[i][j].setG(&(this->fields[i - 1][j]));
					this->fields[i][j].setPG(&(this->fields[i - 1][j + 1]));
					continue;
				}
			}
			else if (i > 0 && i < y - 1) {    // USTAWIAM WSKAZNIKI W KAZDYM INNYM WIERSZU
				if (j == 0) {
					this->fields[i][j].setPG(&(this->fields[i - 1][j + 1]));
					this->fields[i][j].setP(&(this->fields[i][j + 1]));
					this->fields[i][j].setPD(&(this->fields[i + 1][j + 1]));
					continue;
				}

				if (j == x - 1) {
					this->fields[i][j].setLG(&(this->fields[i - 1][j - 1]));
					this->fields[i][j].setL(&(this->fields[i][j - 1]));
					this->fields[i][j].setLD(&(this->fields[i + 1][j - 1]));
					continue;
				}

				if (j > 0 && j < x - 1) {
					this->fields[i][j].setLG(&(this->fields[i - 1][j - 1]));
					this->fields[i][j].setG(&(this->fields[i - 1][j]));
					this->fields[i][j].setPG(&(this->fields[i - 1][j + 1]));
					this->fields[i][j].setL(&(this->fields[i][j - 1]));
					this->fields[i][j].setP(&(this->fields[i][j + 1]));
					this->fields[i][j].setLD(&(this->fields[i + 1][j - 1]));
					this->fields[i][j].setD(&(this->fields[i + 1][j]));
					this->fields[i][j].setPD(&(this->fields[i + 1][j + 1]));
					continue;
				}
			}
		}
	}

	this->fields[y/2][x/2].setVisited(1);

	this->fields[0][x / 2].setL(&(this->fields[0][x / 2 - 1]));
	this->fields[0][x / 2].setP(&(this->fields[0][x / 2 + 1]));
	this->fields[0][x / 2 - 1].setP(&(this->fields[0][x / 2]));
	this->fields[0][x / 2 + 1].setL(&(this->fields[0][x / 2]));

	// PRZYPISYWANIE WSKAŹNIKÓW DLA BRAMEK 

	//BRAMKA TOP
	
	this->fields[0][x / 2].setG(&topGoal2);
	this->fields[0][x / 2].setLG(&topGoal1);
	this->fields[0][x / 2].setPG(&topGoal3);

	this->fields[0][(x / 2) - 1].setPG(&topGoal2);
	this->fields[0][(x / 2) + 1].setLG(&topGoal2);

	//BRAMKA BOTTOM
	this->fields[y - 1][x / 2].setD(&bottomGoal2);
	this->fields[y - 1][x / 2].setLD(&bottomGoal1);
	this->fields[y - 1][x / 2].setPD(&bottomGoal3);

	this->fields[y - 1][(x / 2) - 1].setPD(&bottomGoal2);
	this->fields[y - 1][(x / 2) + 1].setLD(&bottomGoal2);
	
}


Field* Board::getTopGoal1() {
	return &(this->topGoal1);
}

Field* Board::getTopGoal2() {
	return &(this->topGoal2);
}

Field* Board::getTopGoal3() {
	return &(this->topGoal3);
}

Field* Board::getBottomGoal1() {
	return &(this->bottomGoal1);
}

Field* Board::getBottomGoal2() {
	return &(this->bottomGoal2);
}

Field* Board::getBottomGoal3(){
	return &(this->bottomGoal3);
}

void Board::setCurrentField(Field field)
{	
	this->currentField = field;
}

vector<vector<Field>> Board::getFields()
{
	return this->fields;
}

Field Board::getCurrentField()
{
	return this->currentField;
}

int Board::getX()
{
	return this->x;
}

int Board::getY()
{
	return this->y;
}

Field* Board::getFieldAt(int x, int y) {
	return &(this->fields[y][x]);
}