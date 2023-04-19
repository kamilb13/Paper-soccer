#include "Board.h"

using namespace std;

Board::Board(vector<vector<Field>> fields, int x, int y){
	this->fields = fields;
	this->x = x;
	this->y = y;
}

void Board::setCurerntField(Field field)
{
	this->currentField = field;
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