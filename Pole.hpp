#pragma once
#include <SFML/Graphics.hpp>


class Pole {
    public:
    char stan;
    float wielkosc;
    int posX;
    int posY;
    sf::Sprite spritePola;
    sf::Texture teksturaPola;


    Pole(char stan, float wielkosc, int posX, int posY);
    Pole();
    void zmienStan(char znak);
    bool isEmpty();
};