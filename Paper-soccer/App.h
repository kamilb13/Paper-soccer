#pragma once
#include <wx/app.h>

/**
 * @class App
 * @brief Glowna klasa uruchomieniowa aplikacji.
*/
class App : public wxApp
{
public:
    /**
     * @brief Glowna funkcja inicjalizacji aplikacji
     * @return Wartosc logiczna informujaca, czy inicjalizacja powiodla sie
    */
    bool OnInit();
};
