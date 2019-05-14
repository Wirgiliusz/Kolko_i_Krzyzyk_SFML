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

bool GameMaster::ruch(int numer_pola) {
    int i,j;
    switch(numer_pola) {
        case 1:
            i = 0; j = 0;
            break;
        case 2:
            i = 0; j = 1;
            break;
        case 3:
            i = 0; j = 2;
            break;
        case 4:
            i = 1; j = 0;
            break;
        case 5:
            i = 1; j = 1;
            break;
        case 6:
            i = 1; j = 2;
            break;
        case 7:
            i = 2; j = 0;
            break;
        case 8:
            i = 2; j = 1;
            break;
        case 9:
            i = 2; j = 2;
            break;
        default:
            return false;
    }

    return aktualnyGracz->wykonajRuch(plansza->macierzPol[i][j]);
}