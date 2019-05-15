#pragma once

#include "Gracz.hpp"
#include "Plansza.hpp"

class GameMaster {
    public:
    Gracz* graczX;
    Gracz* graczO;
    Plansza* plansza;
    Gracz* aktualnyGracz;
    int wielkosc_planszy;

    GameMaster();
    Plansza* stworzPlansze(int wielkosc_planszy, int warunek_wygranej);
    void nastepnaTura();
    bool ruch(char numer_pola);

    bool czyZostalyRuchy();
    int ocen();
};