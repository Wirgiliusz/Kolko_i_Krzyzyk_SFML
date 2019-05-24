#include "GameMaster.hpp"
#include <algorithm>
#include <iostream>

using namespace std;

GameMaster::GameMaster() {
    //this->wielkosc_planszy = 3;
    graczX = new Gracz('X');
    graczO = new Gracz('O');
    //plansza = stworzPlansze(3, 3);
    aktualnyGracz = graczO;
}

Plansza* GameMaster::stworzPlansze(int wielkosc_planszy, int warunek_wygranej) {
    this->wielkosc_planszy = wielkosc_planszy;
    return new Plansza(wielkosc_planszy, warunek_wygranej);
}

void GameMaster::nastepnaTura() {
    if(aktualnyGracz == graczX)
        aktualnyGracz = graczO;
    else
        aktualnyGracz = graczX;
}

bool GameMaster::ruch(int i, int j) {
    return aktualnyGracz->wykonajRuch(plansza->macierzPol[i][j]);
}

bool GameMaster::czyZostalyRuchy() {
    for(int i=0; i<wielkosc_planszy; i++) {
        for(int j=0; j<wielkosc_planszy; j++) {
            if(plansza->macierzPol[i][j]->isEmpty()) {
                return true;
            }
        }
    }
    return false;
}

int GameMaster::ocen(int glebokosc) {
    if(plansza->wygrana(graczO)) {
        return +10 - glebokosc;
    }
    else if(plansza->wygrana(graczX)) {
        return -10 + glebokosc;
    }
    return 0;
}

int GameMaster::minimax(int glebokosc, bool isMax) {
    std::string stanPlanszy = "";
    for(int i=0; i<wielkosc_planszy; i++) {
        for(int j=0; j<wielkosc_planszy; j++) {
            stanPlanszy += plansza->macierzPol[i][j]->stan;
        }
    }
    auto szukaj = znaneWyniki.find(stanPlanszy);
    if (szukaj != znaneWyniki.end()) {
        return szukaj->second;
    }
   

    int wynik = ocen(glebokosc);

    if(wynik == 10 - glebokosc) {
        return wynik;
    }
    if(wynik == -10 + glebokosc) {
        return wynik;
    }
    if(!czyZostalyRuchy()) {
        return 0;
    }
    if(glebokosc > 1000) {
        return 0;
    }

    if(isMax) {
        int najlepszy = -1000;

        for(int i=0; i<wielkosc_planszy; i++) {
            for(int j=0; j<wielkosc_planszy; j++) {
                if(plansza->macierzPol[i][j]->isEmpty()) {
                    char backup;
                    backup = plansza->macierzPol[i][j]->stan;
                    graczO->wykonajRuch(plansza->macierzPol[i][j]);
                    najlepszy = std::max(najlepszy, minimax(glebokosc+1, !isMax));
                    plansza->macierzPol[i][j]->stan = backup;
                }
            }
        }
        znaneWyniki.insert({stanPlanszy, najlepszy});
        return najlepszy;
    }
    else {
        int najlepszy = 1000;

        for(int i=0; i<wielkosc_planszy; i++) {
            for(int j=0; j<wielkosc_planszy; j++) {
                if(plansza->macierzPol[i][j]->isEmpty()) {
                    char backup;
                    backup = plansza->macierzPol[i][j]->stan;
                    graczX->wykonajRuch(plansza->macierzPol[i][j]);
                    najlepszy = std::min(najlepszy, minimax(glebokosc+1, !isMax));
                    plansza->macierzPol[i][j]->stan = backup;
                }
            }
        }
        znaneWyniki.insert({stanPlanszy, najlepszy});
        return najlepszy;
    }
}

char GameMaster::znajdzNajlepszyRuch() {
    int najlepszaWartosc = -1000;
    char najlepszyRuch;

    for(int i=0; i<wielkosc_planszy; i++) {
        for(int j=0; j<wielkosc_planszy; j++) {
            if(plansza->macierzPol[i][j]->isEmpty()) {
                char backup;
                backup = plansza->macierzPol[i][j]->stan;
                graczO->wykonajRuch(plansza->macierzPol[i][j]);
                int wartoscRuchu = minimax(0, false);
                plansza->macierzPol[i][j]->stan = backup;

                if(wartoscRuchu > najlepszaWartosc) {
                    najlepszyRuch = plansza->macierzPol[i][j]->stan;
                    najlepszaWartosc = wartoscRuchu;
                }
            }
        }
    }
    return najlepszyRuch;
}

int GameMaster::menu() {
    int wyborTrybuGry;
    int wyborWielkosciPlanszy;
    int wyborWarunkuWygranej;
    cout << endl << " _____________________" << endl;
    cout << "| ~ KOLKO I KRZYZYK ~ |" << endl << endl;
    cout << "1. Gracz vs Gracz" << endl;
    cout << "2. Gracz vs Komputer" << endl;
    cout << "3. Wyjscie" << endl;
    cout << "Wybor: ";
    cin >> wyborTrybuGry;

    switch(wyborTrybuGry) {
        case 1:
        cout << "Rozmiar planszy: " << endl;
        cout << "1. 3x3" << endl;
        cout << "2. 4x4" << endl;
        cout << "3. 5x5" << endl;
        cin >> wyborWielkosciPlanszy;
        break;

        case 2:
        cout << "Rozmiar planszy:" << endl;
        cout << "1. 3x3" << endl;
        cout << "2. 4x4" << endl;
        cout << "Wybor: " ;
        cin >> wyborWielkosciPlanszy;
        break;

        case 3:
        cout << "Pa pa" << endl;
        wyjscie = true;
        break;

        default:
        cout << "Brak wybranej opcji!" << endl;
    }

    if(!wyjscie) {
        switch(wyborWielkosciPlanszy) {
        case 1:
        wielkosc_planszy = 3;
        break;
        case 2:
        wielkosc_planszy = 4;
        break;
        case 3:
        wielkosc_planszy = 5;
        break;
        default:
        cout << "Nie wybrano wielkosci planszy!" << endl;
        }

        cout << "Warunek wygranej:" << endl;
        cout << "1. Jeden z rzedu (serio?)" << endl;
        cout << "2. Dwa z rzedu" << endl;
        cout << "3. Trzy z rzedu" << endl;
        if(wielkosc_planszy>3)
        cout << "4. Cztery z rzedu" << endl;
        if(wielkosc_planszy>4)
        cout << "5. Piec z rzedu" << endl;
        cin >> wyborWarunkuWygranej;

        switch(wyborWarunkuWygranej) {
            case 1:
            warunek_wygranej = 1;
            break;
            case 2:
            warunek_wygranej = 2;
            break;
            case 3:
            warunek_wygranej = 3;
            break;
            case 4:
            warunek_wygranej = 4;
            break;
            case 5:
            warunek_wygranej = 5;
            break;
            default:
            cout << "Nie wybrano warunku wygranej!" << endl;
        }

        plansza = stworzPlansze(wielkosc_planszy, warunek_wygranej);
        plansza->wyswietlPlansze();

        if(wyborTrybuGry == 1) {
            return 0;
        } else {
            return 1;
        }
    }
    
    return -1;
}