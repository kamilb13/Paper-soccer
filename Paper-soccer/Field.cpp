#include "Field.h"

using namespace std;

Field::Field(){
}

Field::Field(int x, int y)
{
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