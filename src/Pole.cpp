#include "Pole.hpp"

// // //
//  Pole.cpp + Pole.hpp
// Opis:
//  Plik zawierajacy definicje kontruktora klasy Pole
//  i jego metod.
// // //


// // //
// Opis:
//  Kontruktor klasy Pole
//  Tworzy pole o zadanym stanie, wielkosci i polozeniu.
// Argumenty:
//  char stan - stan pola (puste, X, O)
//  float wielkosc - wielkosc pola
//  int posX - polozenie x pola
//  intposY - polozenie y pola
// Zwracana wartosc:
//  -
// // //
Pole::Pole(char stan, float wielkosc, int posX, int posY) {
    this->stan = stan;
    this->wielkosc = wielkosc;
    this->posX = posX;
    this->posY = posY;

    this->teksturaPolaB.loadFromFile("sprites\\B.png");
    this->teksturaPolaX.loadFromFile("sprites\\X2.png");
    this->teksturaPolaO.loadFromFile("sprites\\O2.png");

    this->spritePola.setScale(float(wielkosc/200),float(wielkosc/200));
    this->spritePola.setTexture(teksturaPolaB);
    this->spritePola.setPosition(posX,posY);
}

// // //
// Opis:
//  Funkcja zmieniajaca stan pola
// Argumenty:
//  char znak - znak na ktory ma ustawic sie pole (pusty, X, O)
// Zwracana wartosc:
//  -
// // //
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

// // //
// Opis:
//  Funkcja sprawdzajaca czy pole jest puste
// Argumenty:
//  -
// Zwracana wartosc:
//  bool - true jesli jest puste; false jesli nie
// // //
bool Pole::isEmpty() {
    if(stan == 'X' || stan == 'O')
        return false;
    else
        return true;
}