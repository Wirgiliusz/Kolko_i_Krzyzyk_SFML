#include "Pole.hpp"



Pole::Pole(char stan, float wielkosc, int posX, int posY) {
    this->stan = stan;
    this->wielkosc = wielkosc;
    this->posX = posX;
    this->posY = posY;

    this->teksturaPola.loadFromFile("sprites\\B.png");
    this->spritePola.setScale(float(wielkosc/200),float(wielkosc/200));
    this->spritePola.setTexture(teksturaPola);
    this->spritePola.setPosition(posX,posY);
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