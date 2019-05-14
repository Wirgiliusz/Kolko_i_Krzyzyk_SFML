#pragma once

#include "Pole.hpp"

class Plansza {
    public:
    Pole*** macierzPol;
    int wielkosc_planszy;
    int warunek_wygranej;
    
    Plansza(int wielkosc_planszy, int warunek_wygranej);
    void wyswietlPlansze();
    bool wygrana();
};