#ifndef RGBGUI_H
#define RGBGUI_H

#include <QDialog>
#include "controlkalc.h"
#include "eccezioni.h"

namespace Ui {
class RgbGui;
}

class RgbGui : public QDialog
{
    Q_OBJECT

public:
    explicit RgbGui(ControlKalc*, QWidget *parent = 0);
    ~RgbGui();
    void disabilitaBtn();
    QVector<int> getRisultato() const;

private:
    Ui::RgbGui *ui;
    ControlKalc* controller;

private slots:
    void set_alphaText(int);
    void set_redText(int);
    void set_greenText(int);
    void set_blueText(int);

    void update_display();

    void on_btn_mescola_clicked();
    void on_btn_seleziona_clicked();
    void on_btn_rimuovi_clicked();
    void on_btn_distanza_clicked();
    void on_btn_grigio_clicked();
    void on_btn_negativo_clicked();
    void on_btn_puro_clicked();
    void on_btn_selezionar_clicked();

};

#endif // RGBGUI_H
