#include "Field.h"

using namespace std;

Field::Field() 
{
	this->LG = nullptr;
	this->G = nullptr;
	this->PG = nullptr;
	this->L = nullptr;
	this->P = nullptr;
	this->LD = nullptr;
	this->PD = nullptr;
	this->D = nullptr;
}

Field::Field(int x, int y)
{
	this->LG = nullptr;
	this->G = nullptr;
	this->PG = nullptr;
	this->L = nullptr;
	this->P = nullptr;
	this->LD = nullptr;
	this->PD = nullptr;
	this->D = nullptr;
	this->x = x;
	this->y = y;
}

void Field::setVisited(bool flag) 
{
	this->isVisited = flag;
}

bool Field::getVisited()
{
	return this->isVisited;
}

void Field::setX(int x)
{
	this->x = x;
}

void Field::setY(int y)
{
	this->y = y;
}

int Field::getX()
{
	return this->x;
}

int Field::getY()
{
	return this->y;
}

Field* Field::getLG()
{
	return this->LG;
}

Field* Field::getG()
{
	return this->G;
}

Field* Field::getPG()
{
	return this->PG;
}

Field* Field::getL()
{
	return this->L;
}

Field* Field::getP()
{
	return this->P;
}

Field* Field::getLD()
{
	return this->LD;
}

Field* Field::getPD()
{
	return this->PD;
}

Field* Field::getD()
{
	return this->D;
}

wxButton* Field::getFieldBtn()
{
	return this->fieldBtn;
}

void Field::setLG(Field* field)
{
	this->LG = field;
}

void Field::setG(Field* field)
{
	this->G = field;
}

void Field::setPG(Field* field)
{
	this->PG = field;
}

void Field::setL(Field* field)
{
	this->L = field;
}

void Field::setP(Field* field)
{
	this->P = field;

}

void Field::setLD(Field* field)
{
	this->LD = field;

}

void Field::setPD(Field* field)
{
	this->PD = field;

}

void Field::setD(Field* field)
{
	this->D = field;
}

void Field::setFieldBtn(wxButton* button)
{
	this->fieldBtn = button;
}

bool Field::checkMoves()
{
	bool canMove = false;
	int moves = 0;
	if (this->LG) moves++;
	if (this->G) moves++;
	if (this->PG) moves++;
	if (this->L) moves++;
	if (this->P) moves++;
	if (this->LD) moves++;
	if (this->D) moves++;
	if (this->PD) moves++;

	if (moves > 1) canMove = true;

	return canMove;
}

