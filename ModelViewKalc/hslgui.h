#ifndef HSLGUI_H
#define HSLGUI_H

#include <QDialog>
#include "controlkalc.h"

namespace Ui {
class HslGui;
}

class HslGui : public QDialog
{
    Q_OBJECT

public:
    explicit HslGui(ControlKalc*, QWidget *parent = 0);
    ~HslGui();

private:
    Ui::HslGui *ui;
    ControlKalc* controller;

private slots:
    void set_alphaText(int);
    void set_hueText(int);
    void set_saturationText(int);
    void set_lightnessText(int);
    void update_display();
    void on_btn_seleziona_clicked();
    void on_btn_mixsat_clicked();
    void on_btn_mixlum_clicked();
    void on_btn_sfuma_clicked();
    void on_btn_puro_clicked();
    void on_btn_inverti_clicked();
    void on_btn_grigio_clicked();
};

#endif // HSLGUI_H
