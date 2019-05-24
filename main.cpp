#include "rang.hpp"
#include "GameMaster.hpp"
#include <iostream>
#include <SFML/Graphics.hpp>


int main() {
    GameMaster GM;
    //char input;
    //int vsComputer;
    //bool wykonanoRuch = false;

    enum Okno {Start, WyborTrybuGry, WyborWielkosciPlanszy, WyborWarunkuWygranej, Gra};
    Okno okno = Start;

    sf::RenderWindow window(sf::VideoMode(1600, 900), "Kolko i Krzyzyk");
    
    sf::Sprite przyciskStart;
    sf::Texture teksturaStart;
    teksturaStart.loadFromFile("sprites\\start.png");
    przyciskStart.setTexture(teksturaStart);
    przyciskStart.setPosition(450,300);

    sf::Sprite przyciskGvsG;
    sf::Texture teksturaGvsG;
    teksturaGvsG.loadFromFile("sprites\\graczvsgracz.png");
    przyciskGvsG.setTexture(teksturaGvsG);
    przyciskGvsG.setPosition(450,100);

    sf::Sprite przyciskGvsK;
    sf::Texture teksturaGvsK;
    teksturaGvsK.loadFromFile("sprites\\graczvskomputer.png");
    przyciskGvsK.setTexture(teksturaGvsK);
    przyciskGvsK.setPosition(450,100+300+100);

    sf::Sprite przycisk3x3;
    sf::Texture tekstura3x3;
    tekstura3x3.loadFromFile("sprites\\3x3.png");
    przycisk3x3.setTexture(tekstura3x3);
    przycisk3x3.setPosition(460,75);

    sf::Sprite przycisk4x4;
    sf::Texture tekstura4x4;
    tekstura4x4.loadFromFile("sprites\\4x4.png");
    przycisk4x4.setTexture(tekstura4x4);
    przycisk4x4.setPosition(460,75+200+75);

    sf::Sprite przycisk5x5;
    sf::Texture tekstura5x5;
    tekstura5x5.loadFromFile("sprites\\5x5.png");
    przycisk5x5.setTexture(tekstura5x5);
    przycisk5x5.setPosition(460,75+200+75+200+75);


    while(window.isOpen()) {
        sf::Event event;
        sf::Vector2i mousePos = sf::Mouse::getPosition(window);
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();

            if(sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                // Start
                if(okno == Start && przyciskStart.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
                    std::cout << "Start ";
                    okno = WyborTrybuGry;
                }
                //Wybor trybu gry
                else if(okno == WyborTrybuGry && przyciskGvsG.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
                    std::cout << "Gracz vs Gracz ";
                    GM.tryb_gry = 0;
                    okno = WyborWielkosciPlanszy;
                }
                else if(okno == WyborTrybuGry && przyciskGvsK.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
                    std::cout << "Gracz vs Komputer ";
                    GM.tryb_gry = 1;
                    okno = WyborWielkosciPlanszy;
                }
                //Wybor wielkosci planszy
                else if(okno == WyborWielkosciPlanszy && przycisk3x3.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
                    std::cout << "3x3 ";
                    GM.wielkosc_planszy = 3;
                    GM.plansza = GM.stworzPlansze(GM.wielkosc_planszy,3);
                    okno = Gra;
                }
                else if(okno == WyborWielkosciPlanszy && przycisk4x4.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
                    std::cout << "4x4 ";
                    GM.wielkosc_planszy = 4;
                    GM.plansza = GM.stworzPlansze(GM.wielkosc_planszy,3);
                    okno = Gra;
                }
                else if(okno == WyborWielkosciPlanszy && przycisk5x5.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
                    std::cout << "5x5 ";
                    GM.wielkosc_planszy = 5;
                    GM.plansza = GM.stworzPlansze(GM.wielkosc_planszy,3);
                    okno = Gra;
                }
            }  
        }

        window.clear();
        switch(okno) {
            case Start:
            window.draw(przyciskStart);
            break;

            case WyborTrybuGry:
            window.draw(przyciskGvsG);
            window.draw(przyciskGvsK);
            break;

            case WyborWielkosciPlanszy:
            window.draw(przycisk3x3);
            window.draw(przycisk4x4);
            window.draw(przycisk5x5);
            break;

            case Gra:
            //std::cout << "Gra";
            for(int i=0; i<GM.wielkosc_planszy; i++) {
                for(int j=0; j<GM.wielkosc_planszy; j++) {
                    window.draw(GM.plansza->macierzPol[i][j]->spritePola);
                }
            }
            break;
        }
        window.display();
    }
    
 
    std::cout << rang::style::reset << rang::fg::reset << rang::bg::reset;
    //system("pause");
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
    [x] d. menu

[x] 5. Algorytm komputera:
    -> zbyt dlugie obliczenia dla 5x5

[ ] 6. Grafika:
    [x] a. konfiguracja SFML
        -> coby sie kompilowalo
    [ ] b. przejscie przez menu
    [ ] c. wyswietlanie planszy
    [ ] d. reakcja planszy

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