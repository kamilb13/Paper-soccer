#pragma once
#include <wx/button.h>

/**
 * @brief Klasa reprezentujaca pole gry.
 */
class Field
{
private:
    /// Miejsce pola na boisku
    int x, y; 	
    /// Lewy Gorny sasiad
    Field* LG; 		
    /// Górny sasiad
    Field* G; 			
    /// Prawy Górny sasiad
    Field* PG; 				
    /// Lewy sasiad
    Field* L; 		
    /// Prawy sasiad
    Field* P; 	
    /// Lewy Dolny sasiad
    Field* LD; 			
    /// Prawy Dolny sasiad
    Field* PD; 			
    /// Dolny sasiad
    Field* D; 				
    /// Przycisk przypisany do pola
    wxButton* fieldBtn; 	
    /// Flaga przechowywujaca informacje czy pole bylo odwiedzone w przeszlosci
    bool isVisited; 		

public:
    /**
     * @brief Konstruktor domyslny
     */
    Field();

    /**
     * @brief Konstruktor inicjalizujacy pole gry
     * @param x Wspolrzedna x pola
     * @param y Wspolrzedna y pola
     */
    Field(int x, int y);


	/// Metody pobierajace wlasciwosci pola
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


	/// Metody ustawiajace wlasciwosci pola
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

    /**
     * @brief Sprawdza czy mozna wykonac ruch na tym polu
     * @return Wartosc logiczna informujaca, czy mozna wykonac ruch
     */
    bool checkMoves();
};
