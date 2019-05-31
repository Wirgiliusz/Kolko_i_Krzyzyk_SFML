#include "Plansza.hpp"

using namespace std;


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
            macierzPol[i][j] = new Pole(' ',600/wielkosc_planszy,x,y);      //wypelnia macierz pustymi polami
            x += 600/wielkosc_planszy;
        }
        x = 500;
        y += 600/wielkosc_planszy;
    }
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
