#include "GameMaster.hpp"
#include <iostream>

using namespace std;


int main() {
    GameMaster GM;  

    GM.plansza->wyswietlPlansze();
    GM.aktualnyGracz->wykonajRuch(GM.plansza->macierzPol[1][1]);
    GM.plansza->wyswietlPlansze();
    GM.nastepnaTura();
    GM.aktualnyGracz->wykonajRuch(GM.plansza->macierzPol[1][2]);
    GM.plansza->wyswietlPlansze();



    return 0;
}