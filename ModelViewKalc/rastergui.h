#ifndef RASTERGUI_H
#define RASTERGUI_H

#include <QDialog>
#include "displaykalc.h"
#include <qvector.h>
#include "controlkalc.h"

namespace Ui {
class RasterGui;
}

class RasterGui : public QDialog
{
    Q_OBJECT

public:
    explicit RasterGui(ControlKalc*, QWidget *parent = 0);
    ~RasterGui();
    void inserisciPixel(int,int,int,int,int,int);


private slots:
    void openDisplay();
    void aggiornaRaster();
    void on_pushButton_quadrato_clicked();

    void on_pushButton_linea_clicked();

    void on_pushButton_colonna_clicked();

    void on_btn_svuota_clicked();

private:
    Ui::RasterGui *ui;
    displayKalc* display;
    class pixelDisplay{
      public:
        int x;
        int y;
        int r;
        int g;
        int b;
        int a;
        pixelDisplay(int,int,int,int,int,int);
    };
    QVector<pixelDisplay*> pixelVector;
    ControlKalc* controller;


};



#endif // RASTERGUI_H
