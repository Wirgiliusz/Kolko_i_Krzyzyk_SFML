#include "Gracz.hpp"


bool Gracz::wykonajRuch(Pole* pole) {
    if(pole->isEmpty())
        return false;
    else
        pole->zmienStan(znak);
}