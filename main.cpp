#include "rang.hpp"
#include "GameMaster.hpp"
#include <iostream>
#include <SFML/Graphics.hpp>


int main() {
    GameMaster GM;

    enum Okno {Start, WyborTrybuGry, WyborWielkosciPlanszy, WyborWarunkuWygranej, Gra, KoniecGry};
    Okno okno = Start;

    sf::Clock clock;
    sf::RenderWindow window(sf::VideoMode(1600, 900), "Kolko i Krzyzyk");
    window.setFramerateLimit(60);
    float czas = 0;
    const float DELAY = 0.1;
    
    sf::Text tekstTrybGry, tekstWielkoscPlanszy, tekstWarunekWygranej;
    sf::Font czcionka;
    czcionka.loadFromFile("fonts\\Market_Deco.ttf");
    tekstTrybGry.setFont(czcionka);
    tekstWielkoscPlanszy.setFont(czcionka);
    tekstWarunekWygranej.setFont(czcionka);

    tekstTrybGry.setCharacterSize(50);
    tekstWielkoscPlanszy.setCharacterSize(50);
    tekstWarunekWygranej.setCharacterSize(50);

    tekstTrybGry.setPosition(sf::Vector2f(450+700,150));
    tekstWielkoscPlanszy.setPosition(sf::Vector2f(450+700,300));
    tekstWarunekWygranej.setPosition(sf::Vector2f(450+700,500));

    tekstTrybGry.setFillColor(sf::Color::White);
    tekstWielkoscPlanszy.setFillColor(sf::Color::White);
    tekstWarunekWygranej.setFillColor(sf::Color::White);

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

    sf::Sprite przycisk1zrzedu;
    sf::Texture tekstura1zrzedu;
    tekstura1zrzedu.loadFromFile("sprites\\1zrzedu.png");
    przycisk1zrzedu.setTexture(tekstura1zrzedu);
    przycisk1zrzedu.setPosition(637,33);

    sf::Sprite przycisk2zrzedu;
    sf::Texture tekstura2zrzedu;
    tekstura2zrzedu.loadFromFile("sprites\\2zrzedu.png");
    przycisk2zrzedu.setTexture(tekstura2zrzedu);
    przycisk2zrzedu.setPosition(637,33+140+33);

    sf::Sprite przycisk3zrzedu;
    sf::Texture tekstura3zrzedu;
    tekstura3zrzedu.loadFromFile("sprites\\3zrzedu.png");
    przycisk3zrzedu.setTexture(tekstura3zrzedu);
    przycisk3zrzedu.setPosition(637,33+140+33+140+33);

    sf::Sprite przycisk4zrzedu;
    sf::Texture tekstura4zrzedu;
    tekstura4zrzedu.loadFromFile("sprites\\4zrzedu.png");
    przycisk4zrzedu.setTexture(tekstura4zrzedu);
    przycisk4zrzedu.setPosition(637,33+140+33+140+33+140+33);

    sf::Sprite przycisk5zrzedu;
    sf::Texture tekstura5zrzedu;
    tekstura5zrzedu.loadFromFile("sprites\\5zrzedu.png");
    przycisk5zrzedu.setTexture(tekstura5zrzedu);
    przycisk5zrzedu.setPosition(637,33+140+33+140+33+140+33+140+33);


    while(window.isOpen()) {
        sf::Event event;
        sf::Vector2i mousePos = sf::Mouse::getPosition(window);
        float elapsed = clock.restart().asSeconds();
        czas += elapsed;
        //std::cout << czas << std::endl;
        tekstTrybGry.setString("Tryb gry:\n\t" + std::to_string(GM.tryb_gry));
        tekstWielkoscPlanszy.setString("Wielkosc\n\tplanszy:\n\t\t" + std::to_string(GM.wielkosc_planszy) + " x " + std::to_string(GM.wielkosc_planszy));
        tekstWarunekWygranej.setString("Warunek\n\twygranej:\n\t\t" + std::to_string(GM.warunek_wygranej) + " z rzedu");

        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();

            if(sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                // Start
                if(czas > DELAY && okno == Start && przyciskStart.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
                    std::cout << "Start" << std::endl;
                    czas = 0;
                    okno = WyborTrybuGry;
                }
                //Wybor trybu gry
                else if(czas > DELAY && okno == WyborTrybuGry && przyciskGvsG.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
                    std::cout << "Gracz vs Gracz" << std::endl;
                    GM.tryb_gry = 0;
                    czas = 0;
                    okno = WyborWielkosciPlanszy;
                }
                else if(czas > DELAY && okno == WyborTrybuGry && przyciskGvsK.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
                    std::cout << "Gracz vs Komputer" << std::endl;
                    GM.tryb_gry = 1;
                    czas = 0;
                    okno = WyborWielkosciPlanszy;
                }
                //Wybor wielkosci planszy
                else if(czas > DELAY && okno == WyborWielkosciPlanszy && przycisk3x3.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
                    std::cout << "3x3" << std::endl;
                    GM.wielkosc_planszy = 3;
                    czas = 0;
                    okno = WyborWarunkuWygranej;
                }
                else if(czas > DELAY && okno == WyborWielkosciPlanszy && przycisk4x4.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
                    std::cout << "4x4" << std::endl;
                    GM.wielkosc_planszy = 4;
                    czas = 0;
                    okno = WyborWarunkuWygranej;
                }
                else if(czas > DELAY && GM.tryb_gry == 0 && okno == WyborWielkosciPlanszy && przycisk5x5.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
                    std::cout << "5x5" << std::endl;
                    GM.wielkosc_planszy = 5;
                    czas = 0;
                    okno = WyborWarunkuWygranej;
                }
                //Wybor warunku wygranej
                else if(czas > DELAY && okno == WyborWarunkuWygranej && przycisk1zrzedu.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
                    std::cout << "1 z rzedu" << std::endl;
                    GM.warunek_wygranej = 1;
                    GM.plansza = GM.stworzPlansze(GM.wielkosc_planszy,GM.warunek_wygranej);
                    czas = 0;
                    okno = Gra;
                }
                else if(czas > DELAY && okno == WyborWarunkuWygranej && przycisk2zrzedu.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
                    std::cout << "2 z rzedu" << std::endl;
                    GM.warunek_wygranej = 2;
                    GM.plansza = GM.stworzPlansze(GM.wielkosc_planszy,GM.warunek_wygranej);
                    czas = 0;
                    okno = Gra;
                }
                else if(czas > DELAY && okno == WyborWarunkuWygranej && przycisk3zrzedu.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
                    std::cout << "3 z rzedu" << std::endl;
                    GM.warunek_wygranej = 3;
                    GM.plansza = GM.stworzPlansze(GM.wielkosc_planszy,GM.warunek_wygranej);
                    czas = 0;
                    okno = Gra;
                }
                else if(czas > DELAY && GM.wielkosc_planszy > 3 && okno == WyborWarunkuWygranej && przycisk4zrzedu.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
                    std::cout << "4 z rzedu" << std::endl;
                    GM.warunek_wygranej = 4;
                    GM.plansza = GM.stworzPlansze(GM.wielkosc_planszy,GM.warunek_wygranej);
                    czas = 0;
                    okno = Gra;
                }
                else if(czas > DELAY && GM.wielkosc_planszy > 4 && okno == WyborWarunkuWygranej && przycisk5zrzedu.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
                    std::cout << "5 z rzedu" << std::endl;
                    GM.warunek_wygranej = 5;
                    GM.plansza = GM.stworzPlansze(GM.wielkosc_planszy,GM.warunek_wygranej);
                    czas = 0;
                    okno = Gra;
                }

                //Gra
                if(czas > DELAY && okno == Gra) {
                    if(GM.tryb_gry == 0 && sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                        for(int i=0; i<GM.wielkosc_planszy; i++) {
                            for(int j=0; j<GM.wielkosc_planszy; j++) {
                                if(GM.plansza->macierzPol[i][j]->spritePola.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
                                    if(GM.ruch(i, j)) {
                                        std::cout << "Ruch[" << GM.aktualnyGracz->znak << "]: " << i << " " << j << std::endl;
                                        if (GM.plansza->wygrana(GM.aktualnyGracz)) {
                                            std::cout << "Koniec gry. Wygral: " << GM.aktualnyGracz->znak << std::endl;
                                            czas = 0;
                                            okno = KoniecGry;
                                        } 
                                        else if(!GM.czyZostalyRuchy()) {
                                            std::cout << "Koniec gry. Remis!" << std::endl;
                                            czas = 0;
                                            okno = KoniecGry;
                                        }
                                        else {
                                        GM.nastepnaTura();
                                        }
                                    }
                                }
                            }
                        }
                    }
                    if(GM.tryb_gry == 1) {
                        if(GM.aktualnyGracz == GM.graczX && sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                            for(int i=0; i<GM.wielkosc_planszy; i++) {
                                for(int j=0; j<GM.wielkosc_planszy; j++) {
                                    if(GM.plansza->macierzPol[i][j]->spritePola.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
                                        if(GM.ruch(i, j)) {
                                            std::cout << "Ruch[" << GM.aktualnyGracz->znak << "]: " << i << " " << j << std::endl;
                                            if (GM.plansza->wygrana(GM.aktualnyGracz)) {
                                                std::cout << "Koniec gry. Wygral: " << GM.aktualnyGracz->znak << std::endl;
                                                czas = 0;
                                                okno = KoniecGry;
                                            } 
                                            else if(!GM.czyZostalyRuchy()) {
                                                std::cout << "Koniec gry. Remis!" << std::endl;
                                                czas = 0;
                                                okno = KoniecGry;
                                            }
                                            else {
                                            GM.nastepnaTura();
                                            }
                                        }
                                    }
                                }
                            }
                        }
                        
                    }       
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
                window.draw(tekstTrybGry);
                window.draw(przycisk3x3);
                window.draw(przycisk4x4);
                window.draw(przycisk5x5);

            break;

            case WyborWarunkuWygranej:
                window.draw(tekstTrybGry);
                window.draw(tekstWielkoscPlanszy);
                window.draw(przycisk1zrzedu);
                window.draw(przycisk2zrzedu);
                window.draw(przycisk3zrzedu);
                window.draw(przycisk4zrzedu);
                window.draw(przycisk5zrzedu);
            break;

            case Gra:
                window.draw(tekstTrybGry);
                window.draw(tekstWielkoscPlanszy);
                window.draw(tekstWarunekWygranej);
                for(int i=0; i<GM.wielkosc_planszy; i++) {
                    for(int j=0; j<GM.wielkosc_planszy; j++) {
                        window.draw(GM.plansza->macierzPol[i][j]->spritePola);
                    }
                }
            break;

            case KoniecGry:
                window.draw(tekstTrybGry);
                window.draw(tekstWielkoscPlanszy);
                window.draw(tekstWarunekWygranej);
                for(int i=0; i<GM.wielkosc_planszy; i++) {
                    for(int j=0; j<GM.wielkosc_planszy; j++) {
                        window.draw(GM.plansza->macierzPol[i][j]->spritePola);
                    }
                }
            break;
        }
        window.display();

        if(GM.aktualnyGracz == GM.graczO && okno == Gra && GM.tryb_gry == 1) {
            std::string ruchK = GM.znajdzNajlepszyRuch();
            std::cout << "BOB: " << ruchK[0]-48 << "|" << ruchK[1]-'0' << std::endl;
            if(GM.ruch(ruchK[0]-'0',ruchK[1]-'0')) {
                std::cout << "Ruch[" << GM.aktualnyGracz->znak << "]: " << ruchK[0] << " " << ruchK[1] << std::endl;
                if (GM.plansza->wygrana(GM.aktualnyGracz)) {
                    std::cout << "Koniec gry. Wygral: " << GM.aktualnyGracz->znak << std::endl;
                    okno = KoniecGry;
                } 
                else if(!GM.czyZostalyRuchy()) {
                    std::cout << "Koniec gry. Remis!" << std::endl;
                    okno = KoniecGry;
                }
                else {
                GM.nastepnaTura();
                }
            }
        }
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
    [x] b. przejscie przez menu
    [x] c. wyswietlanie planszy
    [x] d. reakcja planszy
    [ ] e. informacje o grze

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