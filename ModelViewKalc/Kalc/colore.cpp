#include "colore.h"

Colore::Colore(double a): alpha(a){ //eccezione alpha <0 || >1

}

double Colore::trasparenza() const{
    return alpha;
}

Colore& Colore::trasparenza(double a){
    if(a < 0 || a > 1)
        throw eccezione_parametro_colore();
    alpha = a;
    return *this;
}
