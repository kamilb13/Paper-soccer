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
	wxButton* fieldBtn;
	bool isVisited;

public:
	Field();		// konstruktor 
	Field(int x, int y);
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
	wxButton* getFieldBtn();
	bool getVisited();
	void setX(int x);
	void setY(int y);
	void setLG(Field* field);
	void setG(Field* field);
	void setPG(Field* field);
	void setL(Field* field);
	void setP(Field* field);
	void setLD(Field* field);
	void setPD(Field* field);
	void setD(Field* field);
	void setFieldBtn(wxButton* button);
	void setVisited(bool flag);
	bool checkMoves();
};