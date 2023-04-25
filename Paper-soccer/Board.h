#pragma once
#include "Field.h"
#include <vector>


using namespace std;

class Board
{
private:
	int x, y;
	vector<vector<Field>> fields;
	Field currentField;

public:
	int current_x, current_y;
	Board(int x, int y);
	void setCurrentField(Field field);
	vector<vector<Field>> getFields();
	Field getCurrentField();
	Field* getFieldAt(int x, int y);
	int getX();
	int getY();

};