#pragma once

#include "Gracz.hpp"
#include "Plansza.hpp"

class GameMaster {
    public:
    Gracz* graczX;
    Gracz* graczO;
    Plansza* plansza;
    Gracz* aktualnyGracz;

    GameMaster();
    Plansza* stworzPlansze(int wielkosc_planszy);
    void nastepnaTura();
};