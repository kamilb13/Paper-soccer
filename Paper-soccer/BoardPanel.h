#pragma once
#include "Field.h"
#include "Board.h"
#include "wx/wx.h"
#include "wx/notebook.h"
#include <wx/aui/aui.h>

using namespace std;

/**
 * @class BoardPanel
 * @brief Klasa wyswietlajaca boisko
 */

class BoardPanel : public wxPanel
{
private:


	bool player = true;
public:

	/// @brief Konstruktor BoardPanel()
	///
	/// @param parent - okno, w ktorym wyswietli sie obiekt klasy BoardPanel
	/// @param title - tytul panelu
	/// @param p1 - zmienna, ktora przechowuje ilosc bramek zdobytych przez gracza nr 1
	/// @param p2 - zmienna, ktora przechowuje ilosc bramek zdobytych przez gracza nr 1

	BoardPanel(wxWindow* parent, const wxString& title, int* p1, int* p2);

	/// @brief Metoda drawLine()
	///
	/// Metoda odpowiedzialna za rysowanie linii na boisku
	/// @param event - event wywolujacy funkcje
	/// @param current_x - wspolrzedna X pola z ktorego wykonywane jest podanie
	/// @param current_y - wspolrzedna Y pola z ktorego wykonywane jest podanie
	/// @param destiny_x - wspolrzedna X pola na ktore wykonywane jest podanie
	/// @param destiny_y - wspolrzedna Y pola na ktore wykonywane jest podanie
	/// @param board - wskaznik na obiekt reprezentujacy boisko
	/// @param player - wskaznik na gracza ktory w danej chwili wykonuje ruch
	void drawLine(wxCommandEvent& event, int* current_x, int* current_y, int destiny_x, int destiny_y, Board* board, bool* player);


	/// @brief Metoda switchPlayer()
	///
	/// Metoda odpowiedzialna za zmiane gracza wykonujacego ruch
	/// @param field - wskaznik na pole na ktore wykonywany jest ruch
	/// @param player - wskaznik na gracza ktory w danej chwili wykonuje ruch
	/// @param board - wskaznik na obiekt reprezentujacy boisko
	void switchPlayer(Field* field, bool* player, Board* board);


	/// @brief Metoda switchCurrentField()
	///
	/// Metoda odpowiedzialna za zmiane pola na ktorym znajduje sie obecnie pilka
	/// @param current_x - wspolrzedna X pola z ktorego wykonywane jest podanie
	/// @param current_y - wspolrzedna Y pola z ktorego wykonywane jest podanie
	/// @param destiny_x - wspolrzedna X pola na ktore wykonywane jest podanie
	/// @param destiny_y - wspolrzedna Y pola na ktore wykonywane jest podanie
	/// @param board - wskaznik na obiekt reprezentujacy boisko
	/// @param player - wskaznik na gracza ktory w danej chwili wykonuje ruch
	void switchCurrentField(int* current_x, int* current_y, int destiny_x, int destiny_y, Board* board, bool* player);


	/// @brief Metoda blockField()
	///
	/// Metoda odpowiedzialna za blokowanie wykonanego wlasnie ruchu, tak aby nigdy wiecej nie mogl byc powtorzony
	/// @param current_x - wspolrzedna X pola z ktorego wykonywane jest podanie
	/// @param current_y - wspolrzedna Y pola z ktorego wykonywane jest podanie
	/// @param destiny_x - wspolrzedna X pola na ktore wykonywane jest podanie
	/// @param destiny_y - wspolrzedna Y pola na ktore wykonywane jest podanie
	/// @param board - wskaznik na obiekt reprezentujacy boisko
	void blockField(int* current_x, int* current_y, int destiny_x, int destiny_y, Board* board);

	/// @brief Tablica wynikow gracza nr 1
	///
	/// 
	wxStaticText* player1Score;

	/// @brief Tablica wynikow gracza nr 2
	///
	/// 
	wxStaticText* player2Score;

	/// @brief Zmienna przechowujaca ilosc bramek gracza nr 1
	///
	/// 
	int* p1;


	/// @brief Zmienna przechowujaca ilosc bramek gracza nr 2
	///
	/// 
	int* p2;
};