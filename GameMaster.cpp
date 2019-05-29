#include "GameMaster.hpp"
#include <algorithm>
#include <iostream>

using namespace std;

// // //
//  GameMaster.cpp + GameMaster.hpp
// Opis:
//  Plik zawierajacy definicje kontruktora klasy GameMaster
//  oraz definicje jego metod
// // //


// // //
// Opis:
//  Kontruktor klasy GameMaster
//  Tworzy graczy, okno gry, sprite'y, ustawia wartosci poczatkowe
// Argumenty:
//  -
// Zwracana wartosc:
//  -
// // //
GameMaster::GameMaster() {
    //tworzy 2 graczy (ustawia ich znaki) i przypisuje aktualnego gracza
    graczX = new Gracz('X');    
    graczO = new Gracz('O');
    aktualnyGracz = graczX;

    //tworzy okno gry, ustawia ilosc fps i chowa kursor myszy
    this->okno = Start;
    this->window.create(sf::VideoMode(1600, 900), "Kolko i Krzyzyk");
    window.setFramerateLimit(60);
    window.setMouseCursorVisible(false);

    //ustawia poczatkowy czas na 0
    this->czas = 0;

    //ustawia napisy
    czcionka.loadFromFile("fonts\\Market_Deco.ttf");
    tekstTrybGry.setFont(czcionka);
    tekstWielkoscPlanszy.setFont(czcionka);
    tekstWarunekWygranej.setFont(czcionka);
    tekstKoniecGry.setFont(czcionka);

    tekstTrybGry.setCharacterSize(50);
    tekstWielkoscPlanszy.setCharacterSize(50);
    tekstWarunekWygranej.setCharacterSize(50);
    tekstKoniecGry.setCharacterSize(50);

    tekstTrybGry.setPosition(sf::Vector2f(450+700,150));
    tekstWielkoscPlanszy.setPosition(sf::Vector2f(450+700,400));
    tekstWarunekWygranej.setPosition(sf::Vector2f(450+700,600));
    tekstKoniecGry.setPosition(sf::Vector2f(20,300)); 

    tekstTrybGry.setFillColor(sf::Color::Red);
    tekstWielkoscPlanszy.setFillColor(sf::Color::Green);
    tekstWarunekWygranej.setFillColor(sf::Color::Blue);

    teksturaKursorX.loadFromFile("sprites\\Xkursor2.png");
    teksturaKursorO.loadFromFile("sprites\\Okursor2.png");
    kursor.setTexture(teksturaKursorX);

    //ustawia przyciski
    teksturaStart.loadFromFile("sprites\\start.png");
    przyciskStart.setTexture(teksturaStart);
    przyciskStart.setPosition(450,300);

    teksturaGvsG.loadFromFile("sprites\\graczvsgracz.png");
    przyciskGvsG.setTexture(teksturaGvsG);
    przyciskGvsG.setPosition(450,100);

    teksturaGvsK.loadFromFile("sprites\\graczvskomputer.png");
    przyciskGvsK.setTexture(teksturaGvsK);
    przyciskGvsK.setPosition(450,100+300+100);

    tekstura3x3.loadFromFile("sprites\\3x3.png");
    przycisk3x3.setTexture(tekstura3x3);
    przycisk3x3.setPosition(460,75);

    tekstura4x4.loadFromFile("sprites\\4x4.png");
    przycisk4x4.setTexture(tekstura4x4);
    przycisk4x4.setPosition(460,75+200+75);

    tekstura5x5.loadFromFile("sprites\\5x5.png");
    przycisk5x5.setTexture(tekstura5x5);
    przycisk5x5.setPosition(460,75+200+75+200+75);

    tekstura1zrzedu.loadFromFile("sprites\\1zrzedu.png");
    przycisk1zrzedu.setTexture(tekstura1zrzedu);
    przycisk1zrzedu.setPosition(637,33);

    tekstura2zrzedu.loadFromFile("sprites\\2zrzedu.png");
    przycisk2zrzedu.setTexture(tekstura2zrzedu);
    przycisk2zrzedu.setPosition(637,33+140+33);

    tekstura3zrzedu.loadFromFile("sprites\\3zrzedu.png");
    przycisk3zrzedu.setTexture(tekstura3zrzedu);
    przycisk3zrzedu.setPosition(637,33+140+33+140+33);

    tekstura4zrzedu.loadFromFile("sprites\\4zrzedu.png");
    przycisk4zrzedu.setTexture(tekstura4zrzedu);
    przycisk4zrzedu.setPosition(637,33+140+33+140+33+140+33);

    tekstura5zrzedu.loadFromFile("sprites\\5zrzedu.png");
    przycisk5zrzedu.setTexture(tekstura5zrzedu);
    przycisk5zrzedu.setPosition(637,33+140+33+140+33+140+33+140+33);

    teksturaOdnowa.loadFromFile("sprites\\odnowa.png");
    przyciskOdnowa.setTexture(teksturaOdnowa);
    przyciskOdnowa.setPosition(87,500);
}

// // //
// Opis:
//  Funkcja tworzaca plansze
// Argumenty:
//  int wielkosc_planszy - wielkosc planszy postaci n x n
//  int warunek_wygranej - warunek wygranej na danej planszy postaci n pod rzad
// Zwracana wartosc:
//  Plansza* - wskaznik na stworzona plansze
// // //
Plansza* GameMaster::stworzPlansze(int wielkosc_planszy, int warunek_wygranej) {
    this->wielkosc_planszy = wielkosc_planszy;
    return new Plansza(wielkosc_planszy, warunek_wygranej);
}

// // //
// Opis:
//  Funkcja ustawiajaca kolejne ture
// Argumenty:
//  -
// Zwracana wartosc:
//  -
// // //
void GameMaster::nastepnaTura() {
    //zmienia aktualnego gracza na drugiego
    if(aktualnyGracz == graczX)
        aktualnyGracz = graczO;
    else
        aktualnyGracz = graczX;
}

// // //
// Opis:
//  Funkcja pozwalajaca na wykonanie ruchu
// Argumenty:
//  int i - indeks wiersza w ktorym ma wykonac sie ruch
//  int j - indeks kolumny w ktorej ma wykonac sie ruch
// Zwracana wartosc:
//  bool - czy udalo sie wykonac ruch
// // //
bool GameMaster::ruch(int i, int j) {
    return aktualnyGracz->wykonajRuch(plansza->macierzPol[i][j]);
}

// // //
// Opis:
//  Funkcja sprawdzajaca czy pozostaly jakies mozliwe ruchy
// Argumenty:
//  -
// Zwracana wartosc:
//  bool - czy zostaly ruchy
// // //
bool GameMaster::czyZostalyRuchy() {
    for(int i=0; i<wielkosc_planszy; i++) {
        for(int j=0; j<wielkosc_planszy; j++) {
            if(plansza->macierzPol[i][j]->isEmpty()) { //jesli ktorekolwiek pole puste
                return true;    //to true
            }
        }
    }
    return false;   //inaczej false
}

// - - - - - - - - - - MinMax - - - - - - - - - - //

// // //
// Opis:
//  Funkcja oceniajaca dla algorytmu Minimax
// Argumenty:
//  int glebokosc - glebokosc wywolan rekurencyjnych funkcji Minimax
// Zwracana wartosc:
//  int - wartosc zagrania
// // //
int GameMaster::ocen(int glebokosc) {
    if(plansza->wygrana(graczO)) {  //jesli wygral gracz O
        return +10 - glebokosc;     //to +
    }
    else if(plansza->wygrana(graczX)) { //jesli wygral komputer X
        return -10 + glebokosc;     //to -
    }
    return 0;   //inaczej 0
}

// // //
// Opis:
//  Funkcja minimax dla algorytmu sztucznej inteligencji
// Argumenty:
//  int glebokosc - glebokosc wywolan rekurencyjnych funkcji Minimax
//  bool isMax - czy oceniamy gracza czy komputer
// Zwracana wartosc:
//  int - wynik danego przebiegu rozgrywki
// // //
int GameMaster::minimax(int glebokosc, bool isMax) {
    std::string stanPlanszy = "";   //string zapamietujacy ustawienie planszy
    //zapisuje wyglad planszy do stringa
    for(int i=0; i<wielkosc_planszy; i++) {
        for(int j=0; j<wielkosc_planszy; j++) {
            stanPlanszy += plansza->macierzPol[i][j]->stan;
        }
    }
    auto szukaj = znaneWyniki.find(stanPlanszy);    //szuka czy dane ustawienie juz bylo
    if (szukaj != znaneWyniki.end()) {
        return szukaj->second;  //jesli tak to zwraca jego wczesniej wyliczona wartosc
    }
   

    int wynik = ocen(glebokosc);    //zapisuje aktualny wynik planszy

    //jesli byl koniec lub remis to go zwraca
    if(wynik == 10 - glebokosc) {
        return wynik;
    }
    if(wynik == -10 + glebokosc) {
        return wynik;
    }
    if(!czyZostalyRuchy()) {
        return 0;
    }
    if(glebokosc > 1000) {
        return 0;
    }

    if(isMax) { //jesli maksymalizujemy
        int najlepszy = -1000;  //poczatkowo najlepszy = -1000

        // wykonuje kazdy mozliwy ruch
        for(int i=0; i<wielkosc_planszy; i++) {
            for(int j=0; j<wielkosc_planszy; j++) {
                if(plansza->macierzPol[i][j]->isEmpty()) {
                    char backup;
                    backup = plansza->macierzPol[i][j]->stan;
                    graczO->wykonajRuch(plansza->macierzPol[i][j]);
                    najlepszy = std::max(najlepszy, minimax(glebokosc+1, !isMax));  //rekurencyjnie wywoluje minimax i zapisuje jego wynik
                    plansza->macierzPol[i][j]->zmienStan(backup);
                }
            }
        }
        znaneWyniki.insert({stanPlanszy, najlepszy});   //dodaje wynik do znanych wynikow
        return najlepszy;   //i go zwraca
    }
    else {  //jesli minimalizujemy
        int najlepszy = 1000; //poczatkowo najlepszy = 1000;

        // wykonuje kazdy mozliwy ruch
        for(int i=0; i<wielkosc_planszy; i++) {
            for(int j=0; j<wielkosc_planszy; j++) {
                if(plansza->macierzPol[i][j]->isEmpty()) {
                    char backup;
                    backup = plansza->macierzPol[i][j]->stan;
                    graczX->wykonajRuch(plansza->macierzPol[i][j]);
                    najlepszy = std::min(najlepszy, minimax(glebokosc+1, !isMax));  //rekurencyjnie wywoluje minimax i zapisuje jego wynik
                    plansza->macierzPol[i][j]->zmienStan(backup);
                }
            }
        }
        znaneWyniki.insert({stanPlanszy, najlepszy});   //dodaje wynik do znanych wynikow
        return najlepszy;   //i go zwraca
    }
}

// // //
// Opis:
//  Funkcja znajdujaca najlepszy ruch 
// Argumenty:
//  -
// Zwracana wartosc:
//  std::string najlepszyRuch - przechowuje indeksy najlepszego ruchu
// // //
std::string GameMaster::znajdzNajlepszyRuch() {
    int najlepszaWartosc = -1000;
    std::string najlepszyRuch;  //przechowuje indeksy najlpszego ruchu

    //wykonuje kazdy mozliwy ruch
    for(int i=0; i<wielkosc_planszy; i++) {
        for(int j=0; j<wielkosc_planszy; j++) {
            if(plansza->macierzPol[i][j]->isEmpty()) {
                char backup;
                backup = plansza->macierzPol[i][j]->stan;
                graczO->wykonajRuch(plansza->macierzPol[i][j]);
                int wartoscRuchu = minimax(0, false);   //wykonuje algorytm minimax
                plansza->macierzPol[i][j]->zmienStan(backup);

                //jesli udalo sie znalezc lepszy to go zapisuje
                if(wartoscRuchu > najlepszaWartosc) {
                    najlepszyRuch = std::to_string(i);
                    najlepszyRuch += std::to_string(j);
                    najlepszaWartosc = wartoscRuchu;
                }
            }
        }
    }
    return najlepszyRuch;   //zwraca najlepszy ruch
}

// // //
// Opis:
//  Funkcja wyswietlajaca menu i przebieg gry
// Argumenty:
//  -
// Zwracana wartosc:
//  -
// // //
void GameMaster::gra() {
    //jesli okno otwarte
    while(window.isOpen()) {
        sf::Event event;    //tworzy zdarzenia
        sf::Vector2i mousePos = sf::Mouse::getPosition(window); //zapisuje pozycje myszy

        //odlicza czas
        float elapsed = clock.restart().asSeconds();    
        czas += elapsed;

        //ustawia kursor
        kursor.setPosition(mousePos.x-15,mousePos.y-15);
        if(aktualnyGracz == graczX) {
            kursor.setTexture(teksturaKursorX);
        }
        else if (aktualnyGracz == graczO) {
            kursor.setTexture(teksturaKursorO);
        }

        //ustawia wyswietlany tryb gry
        if(tryb_gry == 0) {
            tekstTrybGry.setString("Tryb gry:\n\tGracz\n\t  vs\n\tGracz");
        } 
        else {
            tekstTrybGry.setString("Tryb gry:\n\tGracz\n\t\t  vs\n\tKomputer");
        }
        tekstWielkoscPlanszy.setString("Wielkosc\n\tplanszy:\n\t\t" + std::to_string(wielkosc_planszy) + " x " + std::to_string(wielkosc_planszy));
        tekstWarunekWygranej.setString("Warunek\n\twygranej:\n\t\t" + std::to_string(warunek_wygranej) + " z rzedu");

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
                    tryb_gry = 0;
                    czas = 0;
                    okno = WyborWielkosciPlanszy;
                }
                else if(czas > DELAY && okno == WyborTrybuGry && przyciskGvsK.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
                    std::cout << "Gracz vs Komputer" << std::endl;
                    tryb_gry = 1;
                    czas = 0;
                    okno = WyborWielkosciPlanszy;
                }
                //Wybor wielkosci planszy
                else if(czas > DELAY && okno == WyborWielkosciPlanszy && przycisk3x3.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
                    std::cout << "3x3" << std::endl;
                    wielkosc_planszy = 3;
                    czas = 0;
                    okno = WyborWarunkuWygranej;
                }
                else if(czas > DELAY && okno == WyborWielkosciPlanszy && przycisk4x4.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
                    std::cout << "4x4" << std::endl;
                    wielkosc_planszy = 4;
                    czas = 0;
                    okno = WyborWarunkuWygranej;
                }
                else if(czas > DELAY && tryb_gry == 0 && okno == WyborWielkosciPlanszy && przycisk5x5.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
                    std::cout << "5x5" << std::endl;
                    wielkosc_planszy = 5;
                    czas = 0;
                    okno = WyborWarunkuWygranej;
                }
                //Wybor warunku wygranej
                else if(czas > DELAY && okno == WyborWarunkuWygranej && przycisk1zrzedu.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
                    std::cout << "1 z rzedu" << std::endl;
                    warunek_wygranej = 1;
                    plansza = stworzPlansze(wielkosc_planszy,warunek_wygranej);
                    czas = 0;
                    okno = Gra;
                }
                else if(czas > DELAY && okno == WyborWarunkuWygranej && przycisk2zrzedu.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
                    std::cout << "2 z rzedu" << std::endl;
                    warunek_wygranej = 2;
                    plansza = stworzPlansze(wielkosc_planszy,warunek_wygranej);
                    czas = 0;
                    okno = Gra;
                }
                else if(czas > DELAY && okno == WyborWarunkuWygranej && przycisk3zrzedu.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
                    std::cout << "3 z rzedu" << std::endl;
                    warunek_wygranej = 3;
                    plansza = stworzPlansze(wielkosc_planszy,warunek_wygranej);
                    czas = 0;
                    okno = Gra;
                }
                else if(czas > DELAY && wielkosc_planszy > 3 && okno == WyborWarunkuWygranej && przycisk4zrzedu.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
                    std::cout << "4 z rzedu" << std::endl;
                    warunek_wygranej = 4;
                    plansza = stworzPlansze(wielkosc_planszy,warunek_wygranej);
                    czas = 0;
                    okno = Gra;
                }
                else if(czas > DELAY && wielkosc_planszy > 4 && okno == WyborWarunkuWygranej && przycisk5zrzedu.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
                    std::cout << "5 z rzedu" << std::endl;
                    warunek_wygranej = 5;
                    plansza = stworzPlansze(wielkosc_planszy,warunek_wygranej);
                    czas = 0;
                    okno = Gra;
                }
                else if(czas > DELAY && okno == KoniecGry && przyciskOdnowa.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
                    std::cout << "Restart" << std::endl;
                    czas = 0;
                    okno = Start;
                }

                //Gra
                if(czas > DELAY && okno == Gra) {
                    // gracz vs gracz
                    if(tryb_gry == 0 && sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                        for(int i=0; i<wielkosc_planszy; i++) {
                            for(int j=0; j<wielkosc_planszy; j++) {
                                if(plansza->macierzPol[i][j]->spritePola.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
                                    if(ruch(i, j)) {
                                        std::cout << "Ruch[" << aktualnyGracz->znak << "]: " << i << " " << j << std::endl;
                                        if (plansza->wygrana(aktualnyGracz)) {
                                            std::cout << "Koniec gry. Wygral: " << aktualnyGracz->znak << std::endl;
                                            if(aktualnyGracz->znak == 'X') {
                                                tekstKoniecGry.setString("Koniec gry.\n\tWygral gracz X");
                                                tekstKoniecGry.setFillColor(sf::Color::Red);
                                            }
                                            else if(aktualnyGracz->znak == 'O') {
                                                tekstKoniecGry.setString("Koniec gry.\n\tWygral gracz O");
                                                tekstKoniecGry.setFillColor(sf::Color::Green);
                                            }
                                            
                                            czas = 0;
                                            okno = KoniecGry;
                                        } 
                                        else if(!czyZostalyRuchy()) {
                                            std::cout << "Koniec gry. Remis!" << std::endl;
                                            tekstKoniecGry.setString("Koniec gry.\n\tRemis!");
                                            tekstKoniecGry.setFillColor(sf::Color::Yellow);
                                            czas = 0;
                                            okno = KoniecGry;
                                        }
                                        else {
                                        nastepnaTura();
                                        }
                                    }
                                }
                            }
                        }
                    }
                    // gracz vs komputer
                    if(tryb_gry == 1) {
                        if(aktualnyGracz == graczX && sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                            for(int i=0; i<wielkosc_planszy; i++) {
                                for(int j=0; j<wielkosc_planszy; j++) {
                                    if(plansza->macierzPol[i][j]->spritePola.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
                                        if(ruch(i, j)) {
                                            std::cout << "Ruch[" << aktualnyGracz->znak << "]: " << i << " " << j << std::endl;
                                            if (plansza->wygrana(aktualnyGracz)) {
                                                std::cout << "Koniec gry. Wygral: " << aktualnyGracz->znak << std::endl;
                                                if(aktualnyGracz->znak == 'X') {
                                                    tekstKoniecGry.setString("Koniec gry.\n\tWygrales!");
                                                    tekstKoniecGry.setFillColor(sf::Color::Green);
                                                }
                                                else if(aktualnyGracz->znak == 'O') {
                                                    tekstKoniecGry.setString("Koniec gry.\n\tPrzegrales..");
                                                    tekstKoniecGry.setFillColor(sf::Color::Red);
                                                }
                                                czas = 0;
                                                okno = KoniecGry;
                                            } 
                                            else if(!czyZostalyRuchy()) {
                                                std::cout << "Koniec gry. Remis!" << std::endl;
                                                tekstKoniecGry.setString("Koniec gry.\n\tRemis!");
                                                tekstKoniecGry.setFillColor(sf::Color::Yellow);
                                                czas = 0;
                                                okno = KoniecGry;
                                            }
                                            else {
                                            nastepnaTura();
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

        //wyswietlanie na ekranie
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
                for(int i=0; i<wielkosc_planszy; i++) {
                    for(int j=0; j<wielkosc_planszy; j++) {
                        window.draw(plansza->macierzPol[i][j]->spritePola);
                    }
                }
            break;

            case KoniecGry:
                window.draw(tekstTrybGry);
                window.draw(tekstWielkoscPlanszy);
                window.draw(tekstWarunekWygranej);
                window.draw(tekstKoniecGry);
                window.draw(przyciskOdnowa);
                for(int i=0; i<wielkosc_planszy; i++) {
                    for(int j=0; j<wielkosc_planszy; j++) {
                        window.draw(plansza->macierzPol[i][j]->spritePola);
                    }
                }
            break;
        }
        window.draw(kursor);
        window.display();

        if(aktualnyGracz == graczO && okno == Gra && tryb_gry == 1) {
            std::string ruchK = znajdzNajlepszyRuch();
            std::cout << "BOB: " << ruchK[0]-48 << "|" << ruchK[1]-'0' << std::endl;
            if(ruch(ruchK[0]-'0',ruchK[1]-'0')) {
                std::cout << "Ruch[" << aktualnyGracz->znak << "]: " << ruchK[0] << " " << ruchK[1] << std::endl;
                if (plansza->wygrana(aktualnyGracz)) {
                    std::cout << "Koniec gry. Wygral: " << aktualnyGracz->znak << std::endl;
                    if(aktualnyGracz->znak == 'X') {
                        tekstKoniecGry.setString("Koniec gry.\n\tWygrales!");
                        tekstKoniecGry.setFillColor(sf::Color::Green);
                    }
                    else if(aktualnyGracz->znak == 'O') {
                        tekstKoniecGry.setString("Koniec gry.\n\tPrzegrales..");
                        tekstKoniecGry.setFillColor(sf::Color::Red);
                    }
                    okno = KoniecGry;
                } 
                else if(!czyZostalyRuchy()) {
                    std::cout << "Koniec gry. Remis!" << std::endl;
                    tekstKoniecGry.setString("Koniec gry.\n\tRemis!");
                    tekstKoniecGry.setFillColor(sf::Color::Yellow);
                    okno = KoniecGry;
                }
                else {
                nastepnaTura();
                }
            }
        }
    }
}