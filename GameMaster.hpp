#pragma once

#include "Gracz.hpp"
#include "Plansza.hpp"
#include <unordered_map>
#include <string>

class GameMaster {
    public:
    Gracz* graczX;
    Gracz* graczO;
    Plansza* plansza;
    Gracz* aktualnyGracz;
    int tryb_gry;
    int wielkosc_planszy;
    int warunek_wygranej;
    bool wyjscie = false;

    GameMaster();
    Plansza* stworzPlansze(int wielkosc_planszy, int warunek_wygranej);
    void nastepnaTura();
    bool ruch(int i, int j);
    
    std::unordered_map<std::string,int> znaneWyniki;
    std::string najlepszyRuch[2];
    bool czyZostalyRuchy();
    int ocen(int glebokosc);
    int minimax(int glebokosc, bool isMax);
    std::string znajdzNajlepszyRuch();

    int menu();
};