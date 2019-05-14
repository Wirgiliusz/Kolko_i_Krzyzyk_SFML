#pragma once

#include "Pole.hpp"

class Plansza {
    public:
    Pole*** macierzPol;
    int wielkosc_planszy;
    
    Plansza(int wielkosc_planszy);
    void wyswietlPlansze();
};