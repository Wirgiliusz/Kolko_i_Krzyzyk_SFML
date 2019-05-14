#include "GameMaster.hpp"
#include <iostream>

using namespace std;


int main() {
    GameMaster GM;  
    GM.plansza = GM.stworzPlansze(5,3);

    GM.plansza->wyswietlPlansze();

    //GM.aktualnyGracz->wykonajRuch(GM.plansza->macierzPol[0][0]);
    GM.ruch('a');
    cout << "Wygrana: " << GM.plansza->wygrana() << endl;
    GM.plansza->wyswietlPlansze();
    GM.nastepnaTura();

    //GM.aktualnyGracz->wykonajRuch(GM.plansza->macierzPol[1][2]);
    GM.ruch('q');
    cout << "Wygrana: " << GM.plansza->wygrana() << endl;
    GM.plansza->wyswietlPlansze();
    GM.nastepnaTura();

    //GM.aktualnyGracz->wykonajRuch(GM.plansza->macierzPol[3][3]);
    GM.ruch('n');
    cout << "Wygrana: " << GM.plansza->wygrana() << endl;
    GM.plansza->wyswietlPlansze();
    GM.nastepnaTura();

    //GM.aktualnyGracz->wykonajRuch(GM.plansza->macierzPol[2][1]);
    GM.ruch('s');
    cout << "Wygrana: " << GM.plansza->wygrana() << endl;
    GM.plansza->wyswietlPlansze();
    GM.nastepnaTura();

    //GM.aktualnyGracz->wykonajRuch(GM.plansza->macierzPol[0][2]);
    GM.ruch('x');
    cout << "Wygrana: " << GM.plansza->wygrana() << endl;
    GM.plansza->wyswietlPlansze();
    GM.nastepnaTura();

    //GM.aktualnyGracz->wykonajRuch(GM.plansza->macierzPol[0][2]);
    GM.ruch('r');
    cout << "Wygrana: " << GM.plansza->wygrana() << endl;
    GM.plansza->wyswietlPlansze();

    return 0;
}

/*
// - - - - - TODO - - - - - //

[x] 1. Mozliwosc zmiany wielkosci planszy

[x] 2. Sprawdzanie wygranej dla roznych warunkow wygranej

[x] 3. Latwiejsze wybieranie pola do postawienia znaku:
        [x] a. jako cyfra 1-9 (jednak litery a-z)
        [x] b. odpowiednie wyswietlenie planszy
[ ] 4. Interfejs:
    [ ] a. input uzytkownika
    [ ] b. czyszczenie konsoli

[ ] 5. Algorytm komputera:

[ ] 6. Grafika:
*/