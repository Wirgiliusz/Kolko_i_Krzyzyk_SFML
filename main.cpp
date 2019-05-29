#include "GameMaster.hpp"
#include <iostream>
#include <SFML/Graphics.hpp>


int main() {
    GameMaster GM;


    GM.gra();
    
    
    return 0;
}

/*
// - - - - - TODO - - - - - //

[x] 1. Mozliwosc zmiany wielkosci planszy

[x] 2. Sprawdzanie wygranej dla roznych warunkow wygranej

[x] 3. Latwiejsze wybieranie pola do postawienia znaku:
    [x] a. jako cyfra 1-9 (jednak litery a-z)
    [x] b. odpowiednie wyswietlenie planszy

[x] 4. Interfejs:
    [x] a. input uzytkownika
    [x] b. kolory
    [x] c. menu

[x] 5. Algorytm komputera:
    -> zbyt dlugie obliczenia dla 5x5

[x] 6. Grafika:
    [x] a. konfiguracja SFML
        -> coby sie kompilowalo
    [x] b. przejscie przez menu
    [x] c. wyswietlanie planszy
    [x] d. reakcja planszy
    [x] e. informacje o grze
    [x] f. end game screen
    [x] g. restart gry
    [x] h. kursor

    NAPRAWIC:
        [x] a. algorytm wybiera pola po kolei (nie dziala)
        [x] b. czasem zle wyswietla gracza ktory wygral
        [x] c. dlugi czas obliczen dla 4x4:
            -> dodac mape ktora przechowuje stan planszy (np string)
            -> na poczatku minimax zapisuje do mapy stan planszy
            -> porownuje czy juz taki tam jest
            -> jesli tak to bierze wynik z niego
            -> na koncu minimax zapisuje do mapy stan planszy i wynik

[ ] 7. Komentarze:
    [x] a. GameMaster
    [ ] b. Plansza
    [ ] c. Pole

*/