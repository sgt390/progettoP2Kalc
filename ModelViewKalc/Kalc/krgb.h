#ifndef RGB_H
#define RGB_H
#include "colore.h"
#include<qstring.h>
#include<iostream>
#include "hsl.h"

class HSL;
class kRGB: public Colore{
    friend std::ostream& operator <<(std::ostream&,const kRGB&);
private:
    int red;
    int green;
    int blue;

    static kRGB toRGB(const HSL&);

public:
    explicit kRGB(QString,QString,QString, double=1);
    explicit kRGB(int=0, int=0, int=0, double=1);
    kRGB(const kRGB&);


    kRGB& grigio();
    kRGB& puro();
    kRGB& negativo(bool=false);
    QString toString() const;

    kRGB& mescola(const kRGB&);
    kRGB& rimuovi(const kRGB&);
    kRGB& distanza(const kRGB&);

    kRGB operator+ (const kRGB&) const;
    kRGB& operator+= (const kRGB&);
    kRGB operator- (const kRGB&) const;
    kRGB& operator-= (const kRGB&);
    bool operator== (const kRGB&) const;
    virtual kRGB& operator =(const kRGB&);

    int rosso() const;
    int verde() const;
    int blu() const;
    void rosso(int);
    void verde(int);
    void blu(int);


};

std::ostream& operator <<(std::ostream&,const kRGB&);

#endif // RGB_H
