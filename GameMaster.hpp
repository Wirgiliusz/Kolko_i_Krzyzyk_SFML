#pragma once

#include "Gracz.hpp"
#include "Plansza.hpp"
#include <unordered_map>
#include <string>

class GameMaster {
    public:
    Gracz* graczX;
    Gracz* graczO;
    Plansza* plansza;
    Gracz* aktualnyGracz;
    int tryb_gry;
    int wielkosc_planszy;
    int warunek_wygranej;

    enum Okno {Start, WyborTrybuGry, WyborWielkosciPlanszy, WyborWarunkuWygranej, Gra, KoniecGry};
    Okno okno;
    float czas;
    const float DELAY = 0.1;

    sf::Clock clock;
    sf::RenderWindow window;

    sf::Text tekstTrybGry, tekstWielkoscPlanszy, tekstWarunekWygranej, tekstKoniecGry;
    sf::Font czcionka;

    sf::Sprite kursor;
    sf::Texture teksturaKursorX, teksturaKursorO;

    sf::Sprite przyciskStart, przyciskGvsG, przyciskGvsK;
    sf::Texture teksturaStart, teksturaGvsG, teksturaGvsK;

    sf::Sprite przycisk3x3, przycisk4x4, przycisk5x5;
    sf::Texture tekstura3x3, tekstura4x4, tekstura5x5;

    sf::Sprite przycisk1zrzedu, przycisk2zrzedu, przycisk3zrzedu, przycisk4zrzedu, przycisk5zrzedu;
    sf::Texture tekstura1zrzedu, tekstura2zrzedu, tekstura3zrzedu, tekstura4zrzedu, tekstura5zrzedu;

    sf::Sprite przyciskOdnowa;
    sf::Texture teksturaOdnowa;

    GameMaster();
    Plansza* stworzPlansze(int wielkosc_planszy, int warunek_wygranej);
    void nastepnaTura();
    bool ruch(int i, int j);
    
    std::unordered_map<std::string,int> znaneWyniki;
    std::string najlepszyRuch[2];
    bool czyZostalyRuchy();
    int ocen(int glebokosc);
    int minimax(int glebokosc, bool isMax);
    std::string znajdzNajlepszyRuch();

    void menu();
};