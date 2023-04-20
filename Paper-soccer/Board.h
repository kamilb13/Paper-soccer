#pragma once
#include "Field.h"
#include <vector>

using namespace std;
class Board
{
private:
	int x, y;
	vector<vector<Field>> fields;
	Field* currentField;

public:
	Board(int x, int y);
	void setCurerntField(Field* field);
	vector<vector<Field>> getFields();
	Field* getCurrentField();
	int getX();
	int getY();
};