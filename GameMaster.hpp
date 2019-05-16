#pragma once

#include "Gracz.hpp"
#include "Plansza.hpp"
#include <map>
#include <string>

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
    
    //std::map<std::string,int[]>* oldAnswers = new map<std::string,int[]>();  
    bool czyZostalyRuchy();
    int ocen(int glebokosc);
    int minimax(int glebokosc, bool isMax);
    char znajdzNajlepszyRuch();
};