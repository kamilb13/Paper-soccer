#include "Field.h"

using namespace std;

Field::Field(){
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

void Field::setVisited(bool flag){
	this->isVisited = flag;
}

bool Field::getVisited()
{
	return false;
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
	return nullptr;
}

Field* Field::getG()
{
	return nullptr;
}

Field* Field::getPG()
{
	return nullptr;
}

Field* Field::getL()
{
	return nullptr;
}

Field* Field::getLD()
{
	return nullptr;
}

Field* Field::getPD()
{
	return nullptr;
}

Field* Field::getD()
{
	return nullptr;
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




