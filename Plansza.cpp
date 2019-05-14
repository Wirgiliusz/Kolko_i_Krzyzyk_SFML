#include "Plansza.hpp"
#include <iostream>

using namespace std;


Plansza::Plansza(int wielkosc_planszy, int warunek_wygranej) {
    this->warunek_wygranej = warunek_wygranej;
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
        for(int k=0; k<wielkosc_planszy; k++) {
            cout << "+-";
        }
        cout << "+" << endl;

        for(int j=0; j<wielkosc_planszy; j++) {
            cout << "|" << macierzPol[i][j]->stan;
        }
        cout << "|" << endl;
    }

    for(int k=0; k<wielkosc_planszy; k++) {
        cout << "+-";
    }
    cout << "+" << endl << endl;
}

bool Plansza::wygrana() {
    //przechodzi przez wszystkie pola
    for(int i=0; i<wielkosc_planszy; i++) {
        for(int j=0; j<wielkosc_planszy; j++) {
            if(!macierzPol[i][j]->isEmpty()) {  //jesli pole nie jest puste
                if(j+1 < wielkosc_planszy && j+2 < wielkosc_planszy) {  //jesli kolejne dwa pola w prawo nie wychodza za plansze
                    if(macierzPol[i][j]->stan == macierzPol[i][j+1]->stan && macierzPol[i][j]->stan == macierzPol[i][j+2]->stan) {  //jesli dwa kolejne pola w prawo maja taki sam stan
                        return true; //to wygrana
                    }
                }

                if(i+1 < wielkosc_planszy && i+2 < wielkosc_planszy) {  //jesli kolejne dwa pola w dol nie wychodza za plansze
                    if(macierzPol[i][j]->stan == macierzPol[i+1][j]->stan && macierzPol[i][j]->stan == macierzPol[i+2][j]->stan) {  //jesli dwa kolejne pola w dol maja taki sam stan
                        return true; //to wygrana
                    }
                }

                if(i+1 < wielkosc_planszy && i+2 < wielkosc_planszy && j+1 < wielkosc_planszy && j+2 < wielkosc_planszy) {  //jesli kolejne dwa pola w prawo i w dol nie wychodza za plansze
                    if(macierzPol[i][j]->stan == macierzPol[i+1][j+1]->stan && macierzPol[i][j]->stan == macierzPol[i+2][j+2]->stan) {  //jesli dwa kolejne pola w prawo i w dol maja taki sam stan
                        return true; //to wygrana
                    }
                }

                if(i-1 >= 0 && i-2 >= 0 && j+1 < wielkosc_planszy && j+2 < wielkosc_planszy) {  //jesli kolejne dwa pola w lewo i w dol nie wychodza za plansze
                    if(macierzPol[i][j]->stan == macierzPol[i-1][j+1]->stan && macierzPol[i][j]->stan == macierzPol[i-2][j+2]->stan) {  //jesli dwa kolejne pola w lewo i w dol maja taki sam stan
                        return true; //to wygrana
                    }
                }

            }
        }
    }
    return false;
}