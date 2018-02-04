#include "immagineraster.h"
ImmagineRaster::ImmagineRaster(int _x, int _y, double pixel, QString n): Matrice(_x,_y), nome(n), dimensionePixel(pixel)
{
    if(getDimX()<0 || getDimY()<0)
        throw eccezione_costruzione_raster();
}

ImmagineRaster::ImmagineRaster(const ImmagineRaster & r): Matrice(r), nome(r.nome)
{}
ImmagineRaster::~ImmagineRaster()
{}

float ImmagineRaster::versione = 1.0;

void ImmagineRaster::nomeImmagine(const QString& n){
    nome = n;
}
QString ImmagineRaster::nomeImmagine() const{
    return nome;
}

float ImmagineRaster::versioneRaster(){
    return versione;
}

void ImmagineRaster::scala(double percentuale){
    if(percentuale <=0)
        throw eccezione_parametro_percentuale();
    dimensionePixel = dimensionePixel*(percentuale);
}

int ImmagineRaster::leggi(int _x, int _y, int colore) const{
    if(_x<0 || _y<0 || _x>=getDimX() || _y>=getDimY())
        throw eccezione_parametro_dimensioneErrata();
    int tmpColore=0;
    switch(colore){
    case 0:tmpColore = elementoInPosizione(_x,_y)->rosso();
        break;
    case 1:tmpColore = elementoInPosizione(_x,_y)->verde();
        break;
    case 2:tmpColore = elementoInPosizione(_x,_y)->blu();
        break;
    default: tmpColore = -1; //eccezione!!
    }
    return tmpColore;

}
kRGB& ImmagineRaster::leggi(int _x,int _y) const{
    if(_x<0 || _y<0 || _x>=getDimX() || _y>=getDimY())
        throw eccezione_parametro_dimensioneErrata();
    return *elementoInPosizione(_x, _y);
}

void ImmagineRaster::coloraLineaOrizzontale(int x, const kRGB& c){
    if(x<0 || x>= getDimX())
        throw eccezione_parametro_dimensioneErrata();
    for(int i=0; i<getDimY(); ++i){
        *elementoInPosizione(x,i) = c;
    }
}

void ImmagineRaster::coloraLineaVerticale(int y, const kRGB& c){
    if(y<0 || y>= getDimY())
        throw eccezione_parametro_dimensioneErrata();
    for(int i=0; i<getDimX(); ++i){
        *elementoInPosizione(i,y) = c;
    }
}

void ImmagineRaster::svuota(){
    int _x = getDimX();
    int _y = getDimY();
    Matrice::svuota();
    Matrice::ridimensiona(_x,_y);
}

void ImmagineRaster::inverti(){
    for(int i=0; i<getDimX(); ++i)
        for(int j=0; j<getDimY(); ++j)
            elementoInPosizione(i,j)->negativo();
}
void ImmagineRaster::coloraQuadrato(int x0,int y0, int x1, int y1, const kRGB& c){
    if(x0<0 || y0<0 || x1<0 || y1<0 || x0>getDimX() || x1>getDimX() || y0>getDimY() || y1>getDimY())
        throw eccezione_parametro_dimensioneErrata();
    if(x0 > x1){
        int i;
        i = x0;
        x0 = x1;
        x1 = i;
    }
    if(y0 > y1){
        int i;
        i = y0;
        y0 = y1;
        y1 = i;
    }
    for(int i=x0; i<x1; ++i)
        for(int j=y0; j<y1; ++j)
            inserisci(c,i,j);
}

ImmagineRaster ImmagineRaster::operator+ (const ImmagineRaster& r) const{
    if(getDimX() != r.getDimX() || getDimY() != r.getDimY())
        throw 1;
    ImmagineRaster tmp_img;
    tmp_img.ridimensiona(getDimX(), getDimY());
    for(int i=0; i<getDimX(); ++i)
        for(int j=0; j<getDimY(); ++j)
            tmp_img.inserisci(leggi(i,j)+r.leggi(i,j), i, j);
    return tmp_img;
}

ImmagineRaster& ImmagineRaster::operator+= (const ImmagineRaster& r){
    if(getDimX() != r.getDimX() || getDimY() != r.getDimY())
        throw 1;
    for(int i=0; i<getDimX(); ++i)
        for(int j=0; j<getDimY(); ++j)
            inserisci(leggi(i,j)+r.leggi(i,j), i, j);
    return *this;
}
ImmagineRaster ImmagineRaster::operator- (const ImmagineRaster& r) const{
    if(getDimX() != r.getDimX() || getDimY() != r.getDimY())
        throw 1;
    ImmagineRaster tmp_img;
    tmp_img.ridimensiona(getDimX(), getDimY());
    for(int i=0; i<getDimX(); ++i)
        for(int j=0; j<getDimY(); ++j)
            tmp_img.inserisci(leggi(i,j)-r.leggi(i,j), i, j);
    return tmp_img;
}
ImmagineRaster& ImmagineRaster::operator-= (const ImmagineRaster& r){
    if(getDimX() != r.getDimX() || getDimY() != r.getDimY())
        throw 1;
    for(int i=0; i<getDimX(); ++i)
        for(int j=0; j<getDimY(); ++j)
            inserisci(leggi(i,j)-r.leggi(i,j), i, j);
    return *this;
}
