#include "Plansza.hpp"
#include <iostream>

using namespace std;


Plansza::Plansza(int wielkosc_planszy) {
    this->wielkosc_planszy = wielkosc_planszy;
    macierzPol = new Pole** [wielkosc_planszy];     //nowa tablica na tablice
    for(int i=0; i<wielkosc_planszy; i++) {
        macierzPol[i] = new Pole* [wielkosc_planszy];   //wpisuje tablice to tablicy tworzac macierz wskaznikow na pola
    }

    for(int i=0; i<wielkosc_planszy; i++) {
        for(int j=0; j<wielkosc_planszy; j++) {
            macierzPol[i][j] = new Pole();      //wypelnia macierz pustymi polami
        }
    }
}

void Plansza::wyswietlPlansze() {
    for(int i=0; i<wielkosc_planszy; i++) {
        for(int j=0; j<wielkosc_planszy; j++) {
            cout << "|" << macierzPol[i][j];
        }
        cout << endl;
        for(int k=0; k<wielkosc_planszy; k++) {
            cout << "+-";
        }
        cout << "+" << endl;
    }
}