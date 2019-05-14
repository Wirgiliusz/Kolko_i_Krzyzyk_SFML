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
    if(stan == 'X' || stan == 'O')
        return false;
    else
        return true;
}