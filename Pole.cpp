#include "Pole.hpp"



Pole::Pole(char stan, float wielkosc, int posX, int posY) {
    this->stan = stan;
    this->wielkosc = wielkosc;
    this->posX = posX;
    this->posY = posY;

    this->teksturaPolaB.loadFromFile("sprites\\B.png");
    this->teksturaPolaX.loadFromFile("sprites\\X.png");
    this->teksturaPolaO.loadFromFile("sprites\\O.png");

    this->spritePola.setScale(float(wielkosc/200),float(wielkosc/200));
    this->spritePola.setTexture(teksturaPolaB);
    this->spritePola.setPosition(posX,posY);
}

Pole::Pole() {
    this->stan = ' ';
}

void Pole::zmienStan(char znak) {
    this->stan = znak;
    if(znak == 'X') {
        this->spritePola.setTexture(teksturaPolaX);
    } 
    else if(znak == 'O') {
        this->spritePola.setTexture(teksturaPolaO);
    }
    else if(znak == ' ') {
        this->spritePola.setTexture(teksturaPolaB);
    }
}

bool Pole::isEmpty() {
    if(stan == 'X' || stan == 'O')
        return false;
    else
        return true;
}