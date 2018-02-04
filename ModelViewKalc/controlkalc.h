#ifndef CONTROLKALC_H
#define CONTROLKALC_H
#include "Kalc/colore.h"
#include "Kalc/immagineraster.h"
#include "Kalc/operando.h"
#include "qvector.h"
class ControlKalc
{
private:
    Operando* op1;
    QString funzione;
    int xi,xf,yi,yf;
    QVector<int> risultato;

public:
    ControlKalc();
    ~ControlKalc();
    void mescolaRGB(int,int,int,double);
    void rimuoviRGB(int,int,int,double);
    void distanzaRGB(int,int,int,double);
    void sfumaHSL(int,double,double,double);
    void mixsatHSL(int,double,double,double);
    void mixlumHSL(int,double,double,double);
    void quadratoDisplay(int,int,int,int);
    void rigaDisplay(int);
    void colonnaDisplay(int);
    QVector<int> esegui(int,double,double,double);
    QVector<int> singola(int,double,double,double, QString);
    QVector<int> getRisultato() const;

};

#endif // CONTROLKALC_H
