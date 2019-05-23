#pragma once


class Pole {
    public:
    char stan;
    int wielkosc;
    int posX;
    int posY;

    Pole(char stan, int wielkosc, int posX, int posY);
    Pole();
    void zmienStan(char znak);
    bool isEmpty();
};