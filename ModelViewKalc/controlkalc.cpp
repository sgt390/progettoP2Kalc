#include "controlkalc.h"
#include "qvector.h"
#include "eccezioni.h"
ControlKalc::ControlKalc():op1(nullptr),xi(0), xf(0), yi(0), yf(0)
{

}
ControlKalc::~ControlKalc(){
    delete op1;
}


void ControlKalc::mescolaRGB(int r, int g, int b, double a){
    if(op1) delete op1;
    op1 = new kRGB(r,g,b,a/255);
    funzione = "mescolaRGB";
}
void ControlKalc::rimuoviRGB(int r, int g, int b, double a){
    if(op1) delete op1;
    op1 = new kRGB(r,g,b,a/255);
    funzione = "rimuoviRGB";
}
void ControlKalc::distanzaRGB(int r, int g, int b, double a){
    if(op1) delete op1;
    op1 = new kRGB(r,g,b,a/255);
    funzione = "distanzaRGB";
}
void ControlKalc::sfumaHSL(int h, double s, double l, double a){
    if(op1) delete op1;
    op1 = new HSL(h,s/255,l/255,a/255);
    funzione = "sfumaHSL";
}
void ControlKalc::mixlumHSL(int h, double s, double l, double a){
    if(op1) delete op1;
    op1 = new HSL(h,s/255,l/255,a/255);
    funzione = "mixlumHSL";
}
void ControlKalc::mixsatHSL(int h, double s, double l, double a){
    if(op1) delete op1;
    op1 = new HSL(h,s/255,l/255,a/255);
    funzione = "mixsatHSL";
}
void ControlKalc::quadratoDisplay(int ix, int fx, int iy, int fy){

    try{
        if(ix>fx){
            int tmpx = ix;
            ix = fx;
            fx = tmpx;
        }
        if(iy>fy){
            int tmpy = iy;
            iy = fy;
            fy = tmpy;
        }
    ImmagineRaster* d = dynamic_cast<ImmagineRaster*>(op1);
    if(d){
        xi = ix;
        xf = fx+1;
        yi = iy;
        yf = fy+1;
        if(xf > d->getDimX()){
            d->ridimensiona(xf,yf);
            d->riempiSpaziVuoti(kRGB());
        }
        if(yf > d->getDimY()){
            d->ridimensiona(xf,yf);
            d->riempiSpaziVuoti(kRGB());
        }
    }else{
        if(op1) delete op1;

        op1 = new ImmagineRaster(fx+1,fy+1, 10);
        xi = ix;
        xf = fx+1;
        yi = iy;
        yf = fy+1;
    }
    funzione = "Quadrato";
    }catch(eccezione_parametro_dimensioneErrata){
        std::cerr<<"dimensione display errata (control)";
    }

}

void ControlKalc::rigaDisplay(int x){

    ImmagineRaster* d = dynamic_cast<ImmagineRaster*>(op1);
    if(d){
        if(x>=d->getDimX())
            throw eccezione_dimensioneDisplay();
        xi = x;
    }else{
        throw eccezione_displayNonEsistente();
    }
    funzione = "Linea";

}

void ControlKalc::colonnaDisplay(int y){

    ImmagineRaster* d = dynamic_cast<ImmagineRaster*>(op1);
    if(d){
        if(y>=d->getDimY())
            throw eccezione_dimensioneDisplay();
        yi = y;
    }else{
        throw eccezione_displayNonEsistente();
    }
    funzione = "Colonna";


}

QVector<int> ControlKalc::esegui(int c1,double c2, double c3, double a){
    try{
    QVector<int> tmp;
    if(funzione == "mescolaRGB"){
        kRGB rgb2(c1,c2,c3,a/255);
        if(dynamic_cast<kRGB*>(op1)){
            kRGB* rgb = static_cast<kRGB*>(op1);
            rgb->mescola(rgb2);
            tmp.push_back(rgb->rosso());
            tmp.push_back(rgb->verde());
            tmp.push_back(rgb->blu());
            tmp.push_back(rgb->trasparenza()*255);
        }
    }
    else if(funzione == "rimuoviRGB"){
        kRGB rgb2(c1,c2,c3,a/255);
        if(dynamic_cast<kRGB*>(op1)){
            kRGB* rgb = static_cast<kRGB*>(op1);
            rgb->rimuovi(rgb2);
            tmp.push_back(rgb->rosso());
            tmp.push_back(rgb->verde());
            tmp.push_back(rgb->blu());
            tmp.push_back(rgb->trasparenza()*255);
        }
    }
    else if(funzione == "distanzaRGB"){
        kRGB rgb2(c1,c2,c3,a/255);
        if(dynamic_cast<kRGB*>(op1)){
            kRGB* rgb = static_cast<kRGB*>(op1);
            rgb->distanza(rgb2);
            tmp.push_back(rgb->rosso());
            tmp.push_back(rgb->verde());
            tmp.push_back(rgb->blu());
            tmp.push_back(rgb->trasparenza()*255);
        }
    }
    else if(funzione == "mixlumHSL"){
        HSL hsl2(c1,c2/255,c3/255, a/255);
        if(dynamic_cast<HSL*>(op1)){
            HSL* hsl = static_cast<HSL*>(op1);
            hsl->mescolaLuminosita(hsl2);
            tmp.push_back(hsl->getHue());
            tmp.push_back((hsl->getSaturation())*255);
            tmp.push_back((hsl->getLightness())*255);
            tmp.push_back((hsl->trasparenza())*255);
        }
    }
    else if(funzione == "mixsatHSL"){
        HSL hsl2(c1,c2/255,c3/255, a/255);
        if(dynamic_cast<HSL*>(op1)){
            HSL* hsl = static_cast<HSL*>(op1);
            hsl->mescolaSaturazione(hsl2);
            tmp.push_back(hsl->getHue());
            tmp.push_back(hsl->getSaturation()*255);
            tmp.push_back(hsl->getLightness()*255);
            tmp.push_back(hsl->trasparenza()*255);
        }
    }
    else if(funzione == "sfumaHSL"){
        HSL hsl2(c1,c2/255,c3/255, a/255);
        if(dynamic_cast<HSL*>(op1)){
            HSL* hsl = static_cast<HSL*>(op1);
            hsl->sfuma(hsl2, 50);
            tmp.push_back(hsl->getHue());
            tmp.push_back(hsl->getSaturation()*255);
            tmp.push_back(hsl->getLightness()*255);
            tmp.push_back(hsl->trasparenza()*255);
        }
    }
    else if(funzione == "Quadrato"){
        kRGB *rgb = new kRGB(c1,c2,c3,a/255);
        ImmagineRaster* d = dynamic_cast<ImmagineRaster*>(op1);
        if(!d) throw eccezione_OperandoGui();
        d->coloraQuadrato(xi, yi, xf, yf,*rgb);
        delete rgb;
        for(int i = 0; i<d->getDimX(); ++i){
            for(int j=0; j<d->getDimY(); ++j){
                rgb = d->elementoInPosizione(i,j);
                tmp.push_back(rgb->rosso());
                tmp.push_back(rgb->verde());
                tmp.push_back(rgb->blu());
                tmp.push_back(rgb->trasparenza()*255);
                tmp.push_back(i);
                tmp.push_back(j);
            }
        }
        risultato = tmp;
    }
    else if(funzione == "Linea"){
        kRGB *rgb = new kRGB(c1,c2,c3,a/255);
        ImmagineRaster* d = dynamic_cast<ImmagineRaster*>(op1);
        if(!d) throw eccezione_OperandoGui();
        d->coloraLineaOrizzontale(xi,*rgb);
        delete rgb;
        for(int i = 0; i<d->getDimX(); ++i){
            for(int j=0; j<d->getDimY(); ++j){
                rgb = d->elementoInPosizione(i,j);
                tmp.push_back(rgb->rosso());
                tmp.push_back(rgb->verde());
                tmp.push_back(rgb->blu());
                tmp.push_back(rgb->trasparenza()*255);
                tmp.push_back(i);
                tmp.push_back(j);
            }
        }
        risultato = tmp;
    }
    else if(funzione == "Colonna"){
        kRGB *rgb = new kRGB(c1,c2,c3,a/255);
        ImmagineRaster* d = dynamic_cast<ImmagineRaster*>(op1);
        if(!d) throw eccezione_OperandoGui();
        d->coloraLineaVerticale(yi,*rgb);
        delete rgb;
        for(int i = 0; i<d->getDimX(); ++i){
            for(int j=0; j<d->getDimY(); ++j){
                rgb = d->elementoInPosizione(i,j);
                tmp.push_back(rgb->rosso());
                tmp.push_back(rgb->verde());
                tmp.push_back(rgb->blu());
                tmp.push_back(rgb->trasparenza()*255);
                tmp.push_back(i);
                tmp.push_back(j);
            }
        }
        risultato = tmp;
    }
    if(tmp.empty())
        throw eccezione_OperandoGui();

    return tmp;

    }catch(eccezione_parametro_colore){
        std::cerr<<"errore nel parametro colore in kalcGUI";
        return {0,0,0,255};
    }
}

QVector<int> ControlKalc::singola(int c1, double c2, double c3, double a, QString fun){
    try{
        if(op1) delete op1;
        QVector<int> tmpRis;
        if(fun == "GrigioHSL"){
            HSL *hsl = new HSL(c1,c2/255,c3/255,a/255);
            op1=hsl;
            hsl->grigio();
            tmpRis.push_back(hsl->getHue());
            tmpRis.push_back(hsl->getSaturation()*255);
            tmpRis.push_back(hsl->getLightness()*255);
            tmpRis.push_back(hsl->trasparenza()*255);
        }
        else if(fun == "InvertiHSL"){
            HSL *hsl = new HSL(c1,c2/255,c3/255,a/255);
            op1=hsl;
            hsl->negativo();
            tmpRis.push_back(hsl->getHue());
            tmpRis.push_back(hsl->getSaturation()*255);
            tmpRis.push_back(hsl->getLightness()*255);
            tmpRis.push_back(hsl->trasparenza()*255);
        }
        else if(fun == "PuroHSL"){
            HSL *hsl = new HSL(c1,c2/255,c3/255,a/255);
            op1=hsl;
            hsl->puro();
            tmpRis.push_back(hsl->getHue());
            tmpRis.push_back(hsl->getSaturation()*255);
            tmpRis.push_back(hsl->getLightness()*255);
            tmpRis.push_back(hsl->trasparenza()*255);
        }
        else if(fun == "PuroRGB"){
            kRGB *rgb = new kRGB(c1,c2,c3,a/255);
            op1=rgb;
            rgb->puro();
            tmpRis.push_back(rgb->rosso());
            tmpRis.push_back(rgb->verde());
            tmpRis.push_back(rgb->blu());
            tmpRis.push_back(rgb->trasparenza()*255);
        }
        else if(fun == "InvertiRGB"){
            kRGB *rgb = new kRGB(c1,c2,c3,a/255);
            op1=rgb;
            rgb->negativo();
            tmpRis.push_back(rgb->rosso());
            tmpRis.push_back(rgb->verde());
            tmpRis.push_back(rgb->blu());
            tmpRis.push_back(rgb->trasparenza()*255);
        }
        else if(fun == "GrigioRGB"){
            kRGB *rgb = new kRGB(c1,c2,c3,a/255);
            op1=rgb;
            rgb->grigio();
            tmpRis.push_back(rgb->rosso());
            tmpRis.push_back(rgb->verde());
            tmpRis.push_back(rgb->blu());
            tmpRis.push_back(rgb->trasparenza()*255);
        }
        if(tmpRis.empty())
            throw eccezione_OperandoGui();
        return tmpRis;
    }catch(eccezione_parametro_colore){
        std::cerr<<"errore nel parametro colore (control)"<<std::endl;
        return {0,0,0,255};
    }
    catch(eccezione_parametro_dimensioneErrata){
            std::cerr<<"dimensione del display errata (control)"<<std::endl;
            return {0,0,0,255};
    }

}

QVector<int> ControlKalc::getRisultato() const{
    return risultato;
}



