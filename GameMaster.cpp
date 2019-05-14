#include "GameMaster.hpp"


GameMaster::GameMaster() {
    graczX = new Gracz('X');
    graczO = new Gracz('O');
    plansza = stworzPlansze(3);
    aktualnyGracz = graczX;
}

Plansza* GameMaster::stworzPlansze(int wielkosc_planszy) {
    return new Plansza(wielkosc_planszy);
}

void GameMaster::nastepnaTura() {
    if(aktualnyGracz == graczX)
        aktualnyGracz = graczO;
    else
        aktualnyGracz = graczX;
}