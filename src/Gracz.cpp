#include "Gracz.hpp"


bool Gracz::wykonajRuch(Pole* pole) {
    if(pole->isEmpty()) {
        pole->zmienStan(znak);
        return true;
    }
    else
        return false;

}