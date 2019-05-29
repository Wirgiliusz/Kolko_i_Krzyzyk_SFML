#pragma once

#include "Pole.hpp"
#include "Gracz.hpp"

class Plansza {
    public:
    Pole*** macierzPol;
    int wielkosc_planszy;
    int warunek_wygranej;
    
    Plansza(int wielkosc_planszy, int warunek_wygranej);
    bool wygrana(Gracz* gracz);
};