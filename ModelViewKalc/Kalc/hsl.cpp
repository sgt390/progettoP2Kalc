#include "hsl.h"
#include<math.h>
HSL::HSL(int h, double s, double l, double t):Colore(t) ,hue(h), saturation(s), lightness(l)
{
    if(hue<0 || hue>360 || saturation<0 || saturation>1 || lightness<0 || lightness>1){
        hue=0;
        saturation=0;
        lightness=0;
        throw eccezione_costruzione_colore();
    }
}

HSL::HSL(QString h, QString s, QString l, double t): Colore(t), hue(h.toInt(nullptr, 16)), saturation(s.toInt(nullptr, 16)), lightness(l.toInt(nullptr, 16))
{
    if(hue<0 || hue>360 || saturation<0 || saturation>1 || lightness<0 || lightness>1){
        hue=0;
        saturation=0;
        lightness=0;
        throw eccezione_costruzione_colore();
    }
}

HSL::HSL(const kRGB &rgb){
    *this = toHSL(rgb);
}


int HSL::max3int(int a, int b, int c){
    int max = a;
    if(max<b)
        max = b;
    if(max<c)
        max=c;
    return max;
}

int HSL::min3int(int a, int b, int c){
    int min = a;
    if(min>b)
        min = b;
    if(min>c)
        min=c;
    return min;
}
HSL HSL::toHSL(const kRGB &c){
    int r = c.rosso()/255;
    int g = c.verde()/255;
    int b = c.blu()/255;

    int Cmax = max3int(r,g,b);
    int Cmin = min3int(r,g,b);
    int delta = Cmax-Cmin;

    int h;
    double s,l;

    //calcolo HUE
    if(delta == 0)
        h=0;
    else{
        if(Cmax == r)
            h = 60*(((g-b)/delta)%6);
        else if(Cmax== g)
            h = 60*((b-r)/delta+2);
        else
            h = 60*((r-g)/delta+4);
    }

    //calcolo Luminosità
    l = (Cmax + Cmin)/2;

    //calcolo Saturazione
    if(delta == 0)
        s=0;
    else
        s = delta/(1-fabs(2*l-1));


    return HSL(h,s,l,c.trasparenza());
}

int HSL::getHue() const{
    return hue;
}

double HSL::getSaturation() const{
    return saturation;
}
double HSL::getLightness() const{
    return lightness;
}

HSL& HSL::grigio(){
    saturation = 0;
    return *this;

}

HSL& HSL::puro(){
    saturation = 1;
    lightness = 0.5;
    trasparenza(1);
    return *this;
}

QString HSL::toString() const{
    QString strHSL = "hue: "+ QString::number(hue) +", saturation: "+ QString::number(saturation) +",lightness: "+ QString::number(lightness);
    return strHSL;
}

HSL& HSL::negativo(bool t){
    hue = (hue + 180) % 360;
    if(t)
        trasparenza(1-trasparenza());
    return *this;

}

HSL& HSL::sfuma(const HSL &c, double p){
   if(p < 0 || p > 100)
       throw eccezione_parametro_percentuale();
   hue += ((c.hue-hue) * (p/100));
   saturation += ((c.saturation-saturation) * (p/100));
   lightness += ((c.lightness-lightness) * (p/100));


   return *this;

}

HSL& HSL::eguagliaSaturazione(const HSL &c){
    saturation = c.saturation;
    return *this;
}

HSL& HSL::eguagliaHue(const HSL &c){
    hue = c.hue;
    return *this;
}

HSL& HSL::eguagliaLuminosita(const HSL &c){
    lightness = c.lightness;
    return *this;
}

HSL& HSL::mescolaLuminosita(const HSL &c){
    lightness = (lightness + c.lightness)/2;
    return *this;
}

HSL& HSL::mescolaSaturazione(const HSL &c){
    saturation = (saturation + c.saturation)/2;
    return *this;
}

void HSL::setHue(int i){
    if(i < 0 || i > 360)
        throw eccezione_parametro_colore();
    hue = i;
}

void HSL::setLightness(double d){
    if(d < 0 || d > 1)
        throw eccezione_parametro_colore();
    lightness = d;
}

void HSL::setSaturation(double d){
    if(d < 0 || d > 1)
        throw eccezione_parametro_colore();
    saturation = d;
}

HSL& HSL::scurisci(int p){
    if(p < 0 || p > 100)
        throw eccezione_parametro_percentuale();
    lightness = lightness + lightness * p/100;
    if(lightness > 1)
        lightness = 1;
    return *this;
}

HSL& HSL::schiarisci(int p){
    if(p < 0 || p > 100)
        throw eccezione_parametro_percentuale();
    lightness = lightness - lightness * p/100;
    if(lightness < 0)
        lightness = 0;
    return *this;
}

HSL& HSL::satura(int p){
    if(p < 0 || p > 100)
        throw eccezione_parametro_percentuale();
    saturation = saturation + saturation * p/100;
    if(saturation > 0)
        saturation = 1;
    return *this;
}

HSL& HSL::desatura(int p){
    if(p < 0 || p > 100)
        throw eccezione_parametro_percentuale();
    saturation = saturation - saturation + p/100;
    if(saturation < 0)
        saturation = 0;
    return *this;
}

std::ostream& operator<< (std::ostream& os,const HSL &c){
    os<<"H:" << c.hue << ",S:" << c.saturation << ",L:" << c.lightness << ",a:"<<c.trasparenza();
    return os;
}

bool HSL::operator ==(const HSL& c) const{
    return (hue == c.hue && saturation == c.saturation && lightness == c.lightness && trasparenza() == c.trasparenza());
}

HSL& HSL::operator= (const HSL& c){
    if(*this == c)
        return *this;
    hue = c.hue;
    saturation = c.saturation;
    lightness = c.lightness;
    trasparenza(c.trasparenza());
    return *this;
}



