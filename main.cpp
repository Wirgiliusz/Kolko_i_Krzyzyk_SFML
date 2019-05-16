#include "rang.hpp"
#include "GameMaster.hpp"
#include <iostream>

using namespace std;


int main() {
    GameMaster GM;
    char input;
    bool wykonanoRuch = false;
    GM.plansza = GM.stworzPlansze(4,3);
    GM.plansza->wyswietlPlansze();

    // --- Glowna petla gry --- //
    /*
    while(true) {
        GM.nastepnaTura();
        
        cout << "Ruch gracza " << GM.aktualnyGracz->znak << ": ";
        cin >> input;
        while(wykonanoRuch != true) {
            wykonanoRuch = GM.ruch(input);
        }
        wykonanoRuch = false;

        GM.plansza->wyswietlPlansze();
        if(GM.plansza->wygrana(GM.aktualnyGracz)) {
            cout << "Wygral gracz: " << GM.aktualnyGracz->znak << endl;
            break;
        }
        else if(!GM.czyZostalyRuchy()) {
            cout << "Remis!" << endl;
            break;
        }
    }
    */
    
    while(true) {
        // ruch gracza
        GM.nastepnaTura();
        cout << "Ruch gracza " << GM.aktualnyGracz->znak << ": ";
        cin >> input;
        while(wykonanoRuch != true) {
            wykonanoRuch = GM.ruch(input);
        }
        wykonanoRuch = false;

        GM.plansza->wyswietlPlansze();
        if(GM.plansza->wygrana(GM.aktualnyGracz)) {
            cout << "Wygral gracz: " << GM.aktualnyGracz->znak << endl;
            break;
        }
        else if(!GM.czyZostalyRuchy()) {
            cout << "Remis!" << endl;
            break;
        }

        //ruch komputera
        GM.nastepnaTura();
        cout << "Ruch komputera " << GM.aktualnyGracz->znak << ".";
        GM.ruch(GM.znajdzNajlepszyRuch());

        GM.plansza->wyswietlPlansze();
        if(GM.plansza->wygrana(GM.aktualnyGracz)) {
            cout << "Wygral gracz: " << GM.aktualnyGracz->znak << endl;
            break;
        }
        else if(!GM.czyZostalyRuchy()) {
            cout << "Remis!" << endl;
            break;
        }
    }
    

    
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
    [x] a. input uzytkownika
    [ ] b. czyszczenie konsoli
    [x] c. kolory
    [ ] d. menu

[x] 5. Algorytm komputera:
    -> zbyt dlugie obliczenia dla 5x5

[ ] 6. Grafika:

    NAPRAWIC:
        [x] a. algorytm wybiera pola po kolei (nie dziala)
        [x] b. czasem zle wyswietla gracza ktory wygral
        [x] c. dlugi czas obliczen dla 4x4:
            -> dodac mape ktora przechowuje stan planszy (np string)
            -> na poczatku minimax zapisuje do mapy stan planszy
            -> porownuje czy juz taki tam jest
            -> jesli tak to bierze wynik z niego
            -> na koncu minimax zapisuje do mapy stan planszy i wynik
*/