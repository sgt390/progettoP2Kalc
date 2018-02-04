#ifndef HSL_H
#define HSL_H
#include<qstring.h>
#include<iostream>
#include "colore.h"
#include "krgb.h"

class kRGB;

class HSL : public Colore
{
    friend std::ostream& operator<< (std::ostream&,const HSL&);
private:
    int hue;            //0-360
    double saturation;     //0-1
    double lightness;      //0-1

    //metodi statici per la classe
    static HSL toHSL(const kRGB&);
    static int max3int(int ,int ,int );
    static int min3int(int,int,int);
public:
    explicit HSL(int=0, double=0, double=0, double=1);
    explicit HSL(QString, QString, QString, double=1);
    HSL(const kRGB&);

    HSL& grigio();
    HSL& puro();
    HSL& negativo(bool=false);
    QString toString() const;

    virtual HSL& scurisci(int);
    virtual HSL& schiarisci(int);
    virtual HSL& satura(int);
    virtual HSL& desatura(int);
    HSL& sfuma(const HSL&, double);

    HSL& eguagliaSaturazione(const HSL&);
    HSL& eguagliaLuminosita(const HSL&);
    HSL& eguagliaHue(const HSL&);
    HSL& mescolaSaturazione(const HSL&);
    HSL& mescolaLuminosita(const HSL&);

    bool operator== (const HSL&) const;
    HSL& operator= (const HSL&);

    int getHue() const;
    double getSaturation() const;
    double getLightness() const;
    void setHue(int);
    void setSaturation(double);
    void setLightness(double);


};
std::ostream& operator<< (std::ostream&,const HSL&);

#endif // HSL_H
