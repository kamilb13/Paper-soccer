#pragma once
class Field
{
private:
	int x, y;
	bool isVisited;
public:
	Field();
	Field(int x, int y);
	void setVisited(bool flag);
	bool getVisited();
	int getX();
	int getY();
};

