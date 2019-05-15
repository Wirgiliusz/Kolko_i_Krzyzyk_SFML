#include "GameMaster.hpp"
#include <algorithm>
#include <iostream>

GameMaster::GameMaster() {
    this->wielkosc_planszy = 3;
    graczX = new Gracz('X');
    graczO = new Gracz('O');
    plansza = stworzPlansze(3, 3);
    aktualnyGracz = graczO;
}

Plansza* GameMaster::stworzPlansze(int wielkosc_planszy, int warunek_wygranej) {
    this->wielkosc_planszy = wielkosc_planszy;
    return new Plansza(wielkosc_planszy, warunek_wygranej);
}

void GameMaster::nastepnaTura() {
    if(aktualnyGracz == graczX)
        aktualnyGracz = graczO;
    else
        aktualnyGracz = graczX;
}

bool GameMaster::ruch(char numer_pola) {
    for(int i=0; i<wielkosc_planszy; i++) {
        for(int j=0; j<wielkosc_planszy; j++) {
            if(plansza->macierzPol[i][j]->stan == numer_pola) {
                return aktualnyGracz->wykonajRuch(plansza->macierzPol[i][j]);
            }
        }
    }
    return false;
}

bool GameMaster::czyZostalyRuchy() {
    for(int i=0; i<wielkosc_planszy; i++) {
        for(int j=0; j<wielkosc_planszy; j++) {
            if(plansza->macierzPol[i][j]->isEmpty()) {
                return true;
            }
        }
    }
    return false;
}

int GameMaster::ocen() {
    if(plansza->wygrana()) {
        if(aktualnyGracz == graczO) {
            return +10;
        } 
        else if(aktualnyGracz == graczX) {
            return -10;
        }
    }
    return 0;
}

int GameMaster::minimax(int glebokosc, bool isMax) {
    int wynik = ocen();

    if(wynik == 10) {
        return wynik;
    }
    if(wynik == -10) {
        return wynik;
    }
    if(!czyZostalyRuchy()) {
        return 0;
    }

    if(isMax) {
        int najlepszy = -1000;

        for(int i=0; i<wielkosc_planszy; i++) {
            for(int j=0; j<wielkosc_planszy; j++) {
                if(plansza->macierzPol[i][j]->isEmpty()) {
                    char backup;
                    backup = plansza->macierzPol[i][j]->stan;
                    graczO->wykonajRuch(plansza->macierzPol[i][j]);
                    najlepszy = std::max(najlepszy, minimax(glebokosc-1, !isMax));
                    plansza->macierzPol[i][j]->stan = backup;
                }
            }
        }
        return najlepszy;
    }
    else {
        int najlepszy = 1000;

        for(int i=0; i<wielkosc_planszy; i++) {
            for(int j=0; j<wielkosc_planszy; j++) {
                if(plansza->macierzPol[i][j]->isEmpty()) {
                    char backup;
                    backup = plansza->macierzPol[i][j]->stan;
                    graczX->wykonajRuch(plansza->macierzPol[i][j]);
                    najlepszy = std::min(najlepszy, minimax(glebokosc-1, !isMax));
                    plansza->macierzPol[i][j]->stan = backup;
                }
            }
        }
        return najlepszy;
    }
}

char GameMaster::znajdzNajlepszyRuch() {
    int najlepszaWartosc = -1000;
    char najlepszyRuch;

    for(int i=0; i<wielkosc_planszy; i++) {
        for(int j=0; j<wielkosc_planszy; j++) {
            if(plansza->macierzPol[i][j]->isEmpty()) {
                char backup;
                backup = plansza->macierzPol[i][j]->stan;
                graczO->wykonajRuch(plansza->macierzPol[i][j]);
                std::cout <<"raz ";
                int wartoscRuchu = minimax(0, false);
                plansza->macierzPol[i][j]->stan = backup;

                if(wartoscRuchu > najlepszaWartosc) {
                    najlepszyRuch = plansza->macierzPol[i][j]->stan;
                    najlepszaWartosc = wartoscRuchu;
                }
            }
        }
    }
    return najlepszyRuch;
}
