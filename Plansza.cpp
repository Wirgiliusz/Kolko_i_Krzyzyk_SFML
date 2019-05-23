#include "Plansza.hpp"
#include "rang.hpp"
#include <iostream>

using namespace std;
using namespace rang;

Plansza::Plansza(int wielkosc_planszy, int warunek_wygranej) {
    this->warunek_wygranej = warunek_wygranej;
    this->wielkosc_planszy = wielkosc_planszy;
    macierzPol = new Pole** [wielkosc_planszy];     //nowa tablica na tablice
    for(int i=0; i<wielkosc_planszy; i++) {
        macierzPol[i] = new Pole* [wielkosc_planszy];   //wpisuje tablice do tablicy tworzac macierz wskaznikow na pola
    }

    int x = 500;
    int y = 150;

    for(int i=0; i<wielkosc_planszy; i++) {
        for(int j=0; j<wielkosc_planszy; j++) {
            macierzPol[i][j] = new Pole(' ',200,x,y);      //wypelnia macierz pustymi polami
            x += 200;
        }
        y += 200;
    }
}

void Plansza::wyswietlPlansze() {
    bool tylkoRaz = false;
    bool tylkoRaz2 = false;
    cout << endl;
    for(int i=0; i<wielkosc_planszy; i++) {
        for(int k=0; k<wielkosc_planszy; k++) {
            cout << fgB::yellow << "+-";
        }
        cout << "+" << fg::reset;
        if(!tylkoRaz) {
            cout << "\t Wymiar planszy: " << wielkosc_planszy << "x" << wielkosc_planszy;
            tylkoRaz = true;
        }
        cout << endl;

        for(int j=0; j<wielkosc_planszy; j++) {
            cout << fgB::yellow << "|" << fg::reset;
            if(macierzPol[i][j]->stan == 'X')
                cout << fgB::red << style::bold;
            else if(macierzPol[i][j]->stan == 'O')
                cout << fgB::green << style::bold;
            else {
                cout << fg::gray << style::dim;
            }
            cout << macierzPol[i][j]->stan;
            cout << fg::reset << style::reset;
        }
        cout << fgB::yellow << "|" << fg::reset ;
        if(!tylkoRaz2) {
            cout << "\t Warunek wygranej: " << warunek_wygranej << " z rzedu";
            tylkoRaz2 = true;
        }
        cout << endl;
    }

    for(int k=0; k<wielkosc_planszy; k++) {
        cout << fgB::yellow << "+-";
    }
    cout << "+" << endl;
    cout << fg::reset;
}

bool Plansza::wygrana(Gracz* gracz) {
    bool win = true;
    //przechodzi przez wszystkie pola
    for(int i=0; i<wielkosc_planszy; i++) {
        for(int j=0; j<wielkosc_planszy; j++) {
            if(macierzPol[i][j]->stan == gracz->znak) {  //jesli pole nie jest puste
                if(j+warunek_wygranej-1 < wielkosc_planszy) {  //jesli kolejne dwa pola w prawo nie wychodza za plansze
                    for(int k=1; k<warunek_wygranej; k++) { //przechodzi przez kolejne pola
                        if(macierzPol[i][j]->stan != macierzPol[i][j+k]->stan) {    //jesli ktores nie jest takie samo jak poprzednie
                            win = false;    //to nie ma tutaj wygranej
                            break;
                        }
                    }
                    if(win) {   //jesli nie znaleziono przeciwskazania do wygranej
                        return true;    //to wygrana
                    } 
                    else {  //w innym przypadku brak
                        win = true; //i reset
                    }
                }

                if(i+warunek_wygranej-1 < wielkosc_planszy) {  //jesli kolejne dwa pola w dol nie wychodza za plansze
                    for(int k=1; k<warunek_wygranej; k++) { //przechodzi przez kolejne pola
                        if(macierzPol[i][j]->stan != macierzPol[i+k][j]->stan) {    //jesli ktores nie jest takie samo jak poprzednie
                            win = false;    //to nie ma tutaj wygranej
                            break;
                        }
                    }
                    if(win) {   //jesli nie znaleziono przeciwskazania do wygranej
                        return true;    //to wygrana
                    } 
                    else {  //w innym przypadku brak
                        win = true; //i reset
                    }
                }

                if(i+warunek_wygranej-1 < wielkosc_planszy && j+warunek_wygranej-1 < wielkosc_planszy) {  //jesli kolejne dwa pola w prawo i w dol nie wychodza za plansze
                    for(int k=1; k<warunek_wygranej; k++) { //przechodzi przez kolejne pola
                        if(macierzPol[i][j]->stan != macierzPol[i+k][j+k]->stan) {    //jesli ktores nie jest takie samo jak poprzednie
                            win = false;    //to nie ma tutaj wygranej
                            break;
                        }
                    }
                    if(win) {   //jesli nie znaleziono przeciwskazania do wygranej
                        return true;    //to wygrana
                    } 
                    else {  //w innym przypadku brak
                        win = true; //i reset
                    }
                }

                if(i-warunek_wygranej+1 >= 0 && j+warunek_wygranej-1 < wielkosc_planszy) {  //jesli kolejne dwa pola w lewo i w dol nie wychodza za plansze
                    for(int k=1; k<warunek_wygranej; k++) { //przechodzi przez kolejne pola
                        if(macierzPol[i][j]->stan != macierzPol[i-k][j+k]->stan) {    //jesli ktores nie jest takie samo jak poprzednie
                            win = false;    //to nie ma tutaj wygranej
                            break;
                        }
                    }
                    if(win) {   //jesli nie znaleziono przeciwskazania do wygranej
                        return true;    //to wygrana
                    } 
                    else {  //w innym przypadku brak
                        win = true; //i reset
                    }
                }

            }
        }
    }
    return false;
}
