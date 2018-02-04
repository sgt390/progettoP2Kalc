#ifndef IMMAGINERASTER_H
#define IMMAGINERASTER_H
#include "matrice.h"
#include "krgb.h"
#include "operando.h"

class ImmagineRaster : public Matrice<kRGB>, public virtual Operando
{
private:
    QString nome;
    double dimensionePixel;
    static float versione;
public:
    ImmagineRaster(int=1, int=1, double = 1, QString="");
    ImmagineRaster(const ImmagineRaster&);
    ~ImmagineRaster();

    /* informazioni */
    void nomeImmagine(const QString& = "");
    QString nomeImmagine() const;
    static float versioneRaster();
    /* operazioni sulla dimensione dell'immagine */
    void scala(double);
    /* operazioni sul colore dell'immagine */
    int leggi(int,int,int) const;
    kRGB& leggi(int,int) const;
    void coloraLineaOrizzontale(int, const kRGB&);
    void coloraLineaVerticale(int, const kRGB&);
    void coloraQuadrato(int,int,int,int, const kRGB&);
    void svuota();
    void inverti();
    void coloraPixel(int, int, const kRGB &);
    /* operazioni tra due ImmaginiRaster */
    ImmagineRaster operator+ (const ImmagineRaster&) const;
    ImmagineRaster& operator+= (const ImmagineRaster&);
    ImmagineRaster operator- (const ImmagineRaster&) const;
    ImmagineRaster& operator-= (const ImmagineRaster&);
};

#endif // IMMAGINERASTER_H
