/**
 * @class Board
 * @brief Klasa odpowiadajaca za plansze gry
*/

#pragma once
#include "Field.h"
#include <vector>

using namespace std;


class Board
{
private:
    /// Wymiary boiska
    int x, y;

    /// Wektor przechowujacy wszystkie pola na boisku
    vector<vector<Field>> fields;

    /// Pole na ktorym aktualnie znajduje sie pilka
    Field currentField;

    /// Pola reprezentujace gorna bramke
    Field topGoal1, topGoal2, topGoal3;

    /// Pola reprezentujace dolna bramke
    Field bottomGoal1, bottomGoal2, bottomGoal3;


public:
    /**
     * @brief Konstruktor klasy Board
     * @param wartosc x odpowiadajaca za szerokosc boiska
     * @param wartosc y odpowiadajaca za wysokosc boiska
    */
    Board(int x, int y);               
    /// Zwraca wskaznik do gornej bramki
    Field* getTopGoal1();             
    /// Zwraca wskaznik do gornej bramki
    Field* getTopGoal2();      
    /// Zwraca wskaznik do gornej bramki
    Field* getTopGoal3();             
    /// Zwraca wskaznik do dolnej bramki
    Field* getBottomGoal1();  
    /// Zwraca wskaznik do dolnej bramki
    Field* getBottomGoal2();     
    /// Zwraca wskaznik do dolnej bramki
    Field* getBottomGoal3();    
    /// Zmienne przechowujace wspolrzedne pola na ktorym znajduje sie pilka
    int current_x, current_y;           
    /// Ustawia bie¿¹ce pole
    void setCurrentField(Field field);  
    /// Zwraca wektor pól planszy
    vector<vector<Field>> getFields();  
    /// Zwraca bie¿¹ce pole
    Field getCurrentField();            
    /// Zwraca wskaŸnik do pola na podanej pozycji (x, y)
    Field* getFieldAt(int x, int y);    
    /// Zwraca wartoœæ x planszy
    int getX();                         
    /// Zwraca wartoœæ y planszy
    int getY();                         
};
