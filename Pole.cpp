#include "Pole.hpp"



Pole::Pole(char stan) {
    this->stan = stan;
}

Pole::Pole() {
    this->stan = ' ';
}

void Pole::zmienStan(char znak) {
    this->stan = znak;
}

bool Pole::isEmpty() {
    if(stan == ' ')
        return true;
    else
        return false;
}