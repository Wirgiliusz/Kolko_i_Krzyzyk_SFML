#include "GameMaster.hpp"
#include "rang.hpp"
#include <iostream>

using namespace std;


int main() {
    GameMaster GM;
    char input;
    bool wykonanoRuch = false;
    GM.plansza = GM.stworzPlansze(5,3);
    GM.plansza->wyswietlPlansze();

    // --- Glowna petla gry --- //
    while(!GM.plansza->wygrana()) {
        cin >> input;
        while(wykonanoRuch != true) {
            wykonanoRuch = GM.ruch(input);
        }
        cout << "Wygrana: " << GM.plansza->wygrana() << endl;

        GM.plansza->wyswietlPlansze();
        GM.nastepnaTura();
        wykonanoRuch = false;
    }
    cout << "Wygral gracz: " << GM.aktualnyGracz->znak << endl;


    cout << rang::style::reset << rang::fg::reset << rang::bg::reset;
    system("pause");
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
    [x] c. kolory

[ ] 5. Algorytm komputera:

[ ] 6. Grafika:
*/