#pragma once
#include <wx/button.h>
class Field
{
private:
	int x, y;
	Field* LG;
	Field* G;
	Field* PG;
	Field* L;
	Field* P;
	Field* LD;
	Field* PD;
	Field* D;
	
	bool isVisited;

public:
	wxButton* fieldBtn;
	Field();
	Field(int x, int y);
	void setVisited(bool flag);
	bool getVisited();
	int getX();
	int getY();
	Field* getLG();
	Field* getG();
	Field* getPG();
	Field* getL();
	Field* getP();
	Field* getLD();
	Field* getPD();
	Field* getD();


	void setLG(Field* field);
	void setG(Field* field);
	void setPG(Field* field);
	void setL(Field* field);
	void setP(Field* field);
	void setLD(Field* field);
	void setPD(Field* field);
	void setD(Field* field);
};

