#ifndef COLORE_H
#define COLORE_H
#include <qstring.h>
#include "kalcerrors.h"
#include "operando.h"
class Colore: public Operando
{
private:
    double alpha;
public:
    Colore(double =1);

    virtual Colore& grigio() =0;
    virtual Colore& puro() =0;
    virtual Colore& negativo(bool=false) =0;
    virtual QString toString() const=0;

    double trasparenza() const;
    virtual Colore& trasparenza(double);


};


#endif // COLORE_H
