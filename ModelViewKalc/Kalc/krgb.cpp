#include "krgb.h"
#include <math.h>
#include <qstring.h>
kRGB::kRGB(QString r, QString g, QString b, double a):Colore(a), red(r.toInt(nullptr,16)),green(g.toInt(nullptr,16)), blue(b.toInt(nullptr,16))
{
    if(red<0 || red>255 || green<0 || green>255 || blue<0 || blue>255){
        red=0;
        green=0;
        blue=0;
        throw eccezione_costruzione_colore();
    }
}
kRGB::kRGB(int r, int g, int b, double a):Colore::Colore(a),red(r),green(g),blue(b){
    if(r<0 || r>255 || g<0 || g>255 || b<0 || b>255){
        red=0;
        green=0;
        blue=0;
        throw eccezione_costruzione_colore();
    }
}

kRGB::kRGB(const kRGB& c): Colore(c),
    red(c.red), green(c.green), blue(c.blue){}



kRGB& kRGB::grigio(){
    double r = red;
    double g = green;
    double b = blue;
    double gray = r*0.299 + g * 0.587 +
            b * 0.114;
    red = gray;
    green = gray;
    blue = gray;
    return *this;
}

kRGB& kRGB::negativo(bool trs){
    if(trs) trasparenza(1-trasparenza());
    red = 255-red;
    green = 255-green;
    blue = 255-blue;
    return *this;
}

kRGB& kRGB::puro(){
    int pRed = 255;
    int pGreen = 255;
    int pBlue = 255;
    if(red < 128) pRed = 0;
    if(green < 128) pGreen = 0;
    if(blue < 128) pBlue = 0;
    red = pRed;
    green = pGreen;
    blue = pBlue;
    return *this;

}
QString kRGB::toString() const{
    QString strRGB = "red: "+ QString::number(red) +", green: "+ QString::number(green) +",blue: "+ QString::number(blue);
    return strRGB;
}

kRGB& kRGB::mescola(const kRGB& c){

    red = sqrt((red*red+c.red*c.red)/2);
    green = sqrt((green*green+c.green*c.green)/2);
    blue = sqrt((blue*blue+c.blue*c.blue)/2);
    trasparenza((trasparenza() + c.trasparenza()) /2);
    return *this;
}


kRGB& kRGB::rimuovi(const kRGB& c){
        double tmpRed=red-c.red;
        double tmpGreen=green-c.green;
        double tmpBlue=blue-c.blue;

        red = (tmpRed>0)? tmpRed: 0;
        green = (tmpGreen>0)? tmpGreen:0;
        blue = (tmpBlue>0)?tmpBlue:0;
        trasparenza((trasparenza() + c.trasparenza()) /2);

        return *this;

}


kRGB& kRGB::distanza(const kRGB& c){
    red = (red>c.red) ? red-c.red : c.red-red;
    green = (green>c.green) ? green-c.green : c.green-green;
    blue = (blue>c.blue) ? blue-c.blue : c.blue-blue;
    trasparenza((trasparenza() + c.trasparenza()) /2);
    return *this;
}

kRGB& kRGB::operator =(const kRGB& c){
    if(this == &c) return *this;
    trasparenza(c.trasparenza());
    red = c.red;
    green = c.green;
    blue = c.blue;
    return *this;
}

kRGB kRGB::operator +(const kRGB& c) const{
    kRGB tmpRgb(*this);
    tmpRgb.mescola(c);
    return tmpRgb;
}

kRGB kRGB::operator -(const kRGB& c) const{
    kRGB tmpRgb(*this);
    tmpRgb.rimuovi(c);
    return tmpRgb;
}

bool kRGB::operator ==(const kRGB& c) const{
    return (trasparenza() == c.trasparenza() &&
            red == c.red && green == c.green && blue == c.blue);

}

std::ostream& operator <<(std::ostream& os, const kRGB& c){
    os<<"R:"<<c.red<<",G:"<<c.green<<",B:"<<c.blue<<",a:"<<c.trasparenza();
    return os;
}


kRGB& kRGB::operator+=(const kRGB& c){
    *this = *this + c;
    return *this;
}
int kRGB::rosso() const{
    return red;
}


int kRGB::verde() const{
    return green;
}
int kRGB::blu() const{
    return blue;
}
void kRGB::rosso(int c){
    if(c < 0 || c > 255)
        throw eccezione_parametro_colore();
    red = c;
}
void kRGB::verde(int c){
    if(c < 0 || c > 255)
        throw eccezione_parametro_colore();
    green = c;
}
void kRGB::blu(int c){
    if(c < 0 || c > 255)
        throw eccezione_parametro_colore();
    blue = c;
}



kRGB kRGB::toRGB(const HSL &c){
    double C = (1-fabs(2*c.getLightness()-1)*c.getSaturation());
    double X= C*(1-fabs((c.getHue()/60)%2-1));
    double m= c.getLightness() - C/2;
    int R,G,B;
    if(c.getHue()<60){
        R=C;
        G=X;
        B=0;
    }
    else if(c.getHue()<120){
        R=X;
        G=C;
        B=0;
    }
    else if(c.getHue()<180){
        R=0;
        G=C;
        B=X;
    }
    else if(c.getHue()<240){
        R=0;
        G=X;
        B=C;
    }
    else if(c.getHue()<300){
        R=X;
        G=0;
        B=C;
    }
    else{
        R=C;
        G=0;
        B=X;
    }
    R=(R+m)*255;
    G=(G+m)*255;
    B=(B+m)*255;

    return kRGB(R,G,B,c.trasparenza());
}






























