/**
 * @class EndPanel
 * @brief Panel wyswietlajacy ekran z informacja o zakonczeniu gry
 */
#pragma once
#include "wx/wx.h"

class EndPanel : public wxPanel
{

public:
    /**
     * @brief Konstruktor klasy EndPanel.
     * @param parent Wskaznik na obiekt rodzica.
     * @param title Tytul panelu.
    */
    EndPanel(wxWindow* parent, const wxString& title);


	/// @brief Przycisk do zamykania aplikacji
	///
	/// 
    wxButton* exitButton; /**< Przycisk do zamykania aplikacji. */

    /**
     * @brief Obsluga zdarzenia klikniecia przycisku exitButton.
     * @param event Obiekt zdarzenia.
    */
    void exitOnClick(wxCommandEvent& event);
};
