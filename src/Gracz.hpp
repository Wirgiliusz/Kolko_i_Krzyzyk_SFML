#pragma once

#include "Pole.hpp"

class Gracz {
    public:
    char znak;

    Gracz(char znak) { this->znak = znak; }
    bool wykonajRuch(Pole* pole);
};