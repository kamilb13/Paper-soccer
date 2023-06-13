/**
 * @brief Klasa reprezentujaca panel poczatkowy
 */
#pragma once
#include "wx/wx.h"
#include "wx/notebook.h"
#include <wx/aui/aui.h>

/// Klasa wyswietlajaca start panel
///
/// Klasa dziedziczaca z klasy wxPanel.
class StartPanel : public wxPanel
{

public:
	/// @brief Konstruktor StartPanel()
	///
	/// @param parent - okno, w ktorym wyswietli sie obiekt klasy StartPanel
	/// @param title - tytul panelu
	/// @param p1 - zmienna, ktora przechowuje ilosc bramek zdobytych przez gracza nr 1
	/// @param p2 - zmienna, ktora przechowuje ilosc bramek zdobytych przez gracza nr 1
	StartPanel(wxFrame* parent, const wxString& title, int* p1, int* p2);
	
	/// startButton button odpowidajacy za rozpoczecie rozgrywki 
	wxButton* startButton;

	/// @brief exitButton button odpowidajacy za zakonczenie rozgrywki 
	///
	/// 
	wxButton* exitButton;

	/// @brief Zmienna przechowujaca ilosc bramek gracza nr 1
	///
	/// 
	int* p1;

	/// @brief Zmienna przechowujaca ilosc bramek gracza nr 2
	///
	/// 
	int* p2;

	/// @brief Metoda StartPanel()
	///
	/// Metoda odpowiedzialna za rozpoczecie rozgrywki
	/// @param parent - okno, w ktorym wyswietli sie obiekt klasy StartPanel
	/// @param title - tytul panelu
	/// @param p1 - zmienna, ktora przechowuje ilosc bramek zdobytych przez gracza nr 1
	/// @param p2 - zmienna, ktora przechowuje ilosc bramek zdobytych przez gracza nr 1
	void startOnClick(wxCommandEvent& event);

	/// @brief Metoda StartPanel()
	///
	/// Metoda odpowiedzialna za zakonczenie rozgrywki
	/// @param parent - okno, w ktorym wyswietli sie obiekt klasy StartPanel
	/// @param title - tytul panelu
	/// @param p1 - zmienna, ktora przechowuje ilosc bramek zdobytych przez gracza nr 1
	/// @param p2 - zmienna, ktora przechowuje ilosc bramek zdobytych przez gracza nr 1
	void exitOnClick(wxCommandEvent& event);

	/// @brief Metoda StartPanel()
	///
	/// Metoda odpowiedzialna za odtwarzanie dzwieku
	void PlaySound();
};

