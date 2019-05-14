#include "GameMaster.hpp"
#include <iostream>

using namespace std;


int main() {
    GameMaster GM;  

    GM.plansza->wyswietlPlansze();

    GM.aktualnyGracz->wykonajRuch(GM.plansza->macierzPol[1][1]);
    cout << "Wygrana: " << GM.plansza->wygrana() << endl;
    GM.plansza->wyswietlPlansze();
    GM.nastepnaTura();

    GM.aktualnyGracz->wykonajRuch(GM.plansza->macierzPol[1][2]);
    cout << "Wygrana: " << GM.plansza->wygrana() << endl;
    GM.plansza->wyswietlPlansze();
    GM.nastepnaTura();

    GM.aktualnyGracz->wykonajRuch(GM.plansza->macierzPol[0][2]);
    cout << "Wygrana: " << GM.plansza->wygrana() << endl;
    GM.plansza->wyswietlPlansze();
    GM.nastepnaTura();

    GM.aktualnyGracz->wykonajRuch(GM.plansza->macierzPol[2][1]);
    cout << "Wygrana: " << GM.plansza->wygrana() << endl;
    GM.plansza->wyswietlPlansze();
    GM.nastepnaTura();

    GM.aktualnyGracz->wykonajRuch(GM.plansza->macierzPol[2][0]);
    cout << "Wygrana: " << GM.plansza->wygrana() << endl;
    GM.plansza->wyswietlPlansze();

    return 0;
}