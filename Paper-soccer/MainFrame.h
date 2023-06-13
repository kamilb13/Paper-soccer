#pragma once
#include "wx/wx.h"
#include <wx/notebook.h>
#include <wx/aui/aui.h>

/**
 * @brief Glowne okno aplikacji.
*/
class MainFrame : public wxFrame
{
public:
    /**
     * @brief Konstruktor glownego okna.
     * @param title Tytul okna.
    */
    MainFrame(const wxString& title);

    int scorePlayer_1 = 0; /**< Wynik gracza 1. */
    int scorePlayer_2 = 0; /**< Wynik gracza 2. */
};
