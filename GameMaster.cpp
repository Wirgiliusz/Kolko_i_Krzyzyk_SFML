#include "GameMaster.hpp"


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
            if(plansza->macierzPol[i][j]->isEmpty) {
                return true;
            }
        }
    }
    return false;
}

int GameMaster::ocen() {}