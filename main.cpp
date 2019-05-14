#include "GameMaster.hpp"
#include <iostream>

using namespace std;


int main() {
    GameMaster GM;  
    GM.plansza = GM.stworzPlansze(3,3);

    GM.plansza->wyswietlPlansze();

    //GM.aktualnyGracz->wykonajRuch(GM.plansza->macierzPol[0][0]);
    GM.ruch(1);
    cout << "Wygrana: " << GM.plansza->wygrana() << endl;
    GM.plansza->wyswietlPlansze();
    GM.nastepnaTura();

    //GM.aktualnyGracz->wykonajRuch(GM.plansza->macierzPol[1][2]);
    GM.ruch(5);
    cout << "Wygrana: " << GM.plansza->wygrana() << endl;
    GM.plansza->wyswietlPlansze();
    GM.nastepnaTura();

    //GM.aktualnyGracz->wykonajRuch(GM.plansza->macierzPol[3][3]);
    GM.ruch(9);
    cout << "Wygrana: " << GM.plansza->wygrana() << endl;
    GM.plansza->wyswietlPlansze();
    GM.nastepnaTura();

    //GM.aktualnyGracz->wykonajRuch(GM.plansza->macierzPol[2][1]);
    GM.ruch(2);
    cout << "Wygrana: " << GM.plansza->wygrana() << endl;
    GM.plansza->wyswietlPlansze();
    GM.nastepnaTura();

    //GM.aktualnyGracz->wykonajRuch(GM.plansza->macierzPol[0][2]);
    GM.ruch(3);
    cout << "Wygrana: " << GM.plansza->wygrana() << endl;
    GM.plansza->wyswietlPlansze();
    GM.nastepnaTura();

    //GM.aktualnyGracz->wykonajRuch(GM.plansza->macierzPol[0][2]);
    GM.ruch(8);
    cout << "Wygrana: " << GM.plansza->wygrana() << endl;
    GM.plansza->wyswietlPlansze();

    return 0;
}

/*
// - - - - - TODO - - - - - //

[x] 1. Mozliwosc zmiany wielkosci planszy
[x] 2. Sprawdzanie wygranej dla roznych warunkow wygranej
[ ] 3. Latwiejsze wybieranie pola do postawienia znaku:
        [ ] a. jako cyfra 1-9
        [ ] b. odpowiednie wyswietlenie planszy

*/