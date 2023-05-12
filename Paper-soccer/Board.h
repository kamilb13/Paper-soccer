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
	Field topGoal1;
	Field topGoal2;
	Field topGoal3;
	Field bottomGoal1;
	Field bottomGoal2;
	Field bottomGoal3;
	

public:
	Field* getTopGoal1();
	Field* getTopGoal2();
	Field* getTopGoal3();
	Field* getBottomGoal1();
	Field* getBottomGoal2();
	Field* getBottomGoal3();
	int current_x, current_y;
	Board(int x, int y);
	void setCurrentField(Field field);
	vector<vector<Field>> getFields();
	Field getCurrentField();
	Field* getFieldAt(int x, int y);
	int getX();
	int getY();

};
