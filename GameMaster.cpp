#include "GameMaster.hpp"


GameMaster::GameMaster() {
    graczX = new Gracz('X');
    graczO = new Gracz('O');
    plansza = stworzPlansze(3, 3);
    aktualnyGracz = graczX;
}

Plansza* GameMaster::stworzPlansze(int wielkosc_planszy, int warunek_wygranej) {
    return new Plansza(wielkosc_planszy, warunek_wygranej);
}

void GameMaster::nastepnaTura() {
    if(aktualnyGracz == graczX)
        aktualnyGracz = graczO;
    else
        aktualnyGracz = graczX;
}