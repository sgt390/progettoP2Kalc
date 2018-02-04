#ifndef MENUKALC_H
#define MENUKALC_H

#include <QMainWindow>
#include "controlkalc.h"

namespace Ui {
class MenuKalc;
}

class MenuKalc : public QMainWindow
{
    Q_OBJECT

public:
    explicit MenuKalc(QWidget *parent = 0);
    ~MenuKalc();

private:
    Ui::MenuKalc *ui;
    ControlKalc* controller;

public slots:
    void openRgb();
    void openHsl();
    void openRaster();

};

#endif // MENUKALC_H
