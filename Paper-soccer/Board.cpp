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