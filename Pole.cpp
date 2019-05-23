#include "Pole.hpp"



Pole::Pole(char stan, int wielkosc, int posX, int posY) {
    this->stan = stan;
    this->wielkosc = wielkosc;
    this->posX = posX;
    this->posY = posY;
}

Pole::Pole() {
    this->stan = ' ';
}

void Pole::zmienStan(char znak) {
    this->stan = znak;
}

bool Pole::isEmpty() {
    if(stan == 'X' || stan == 'O')
        return false;
    else
        return true;
}