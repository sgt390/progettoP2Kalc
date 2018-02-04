#include "menukalc.h"
#include "ui_menukalc.h"
#include "qpushbutton.h"
#include "rgbgui.h"
#include "hslgui.h"
#include "rastergui.h"

MenuKalc::MenuKalc(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MenuKalc), controller(new ControlKalc())
{
    ui->setupUi(this);

    connect(ui->btn_rgb, SIGNAL(released()), this, SLOT(openRgb()));
    connect(ui->btn_hsl, SIGNAL(released()), this, SLOT(openHsl()));
    connect(ui->btn_raster, SIGNAL(released()), this, SLOT(openRaster()));
    connect(ui->btn_close, SIGNAL(released()), this, SLOT(close()));

}

MenuKalc::~MenuKalc()
{
    delete ui;
    delete controller;
}

void MenuKalc::openRgb(){
    RgbGui* window = new RgbGui(controller, this);
    connect(window, SIGNAL(finished(int)), this, SLOT(show()));
    window->setAttribute(Qt::WA_DeleteOnClose);
    window->move(width(),height());
    window->show();
    this->hide();
    move(window->width(),window->height());

}

void MenuKalc::openHsl(){
    HslGui* window = new HslGui(controller, this);
    connect(window, SIGNAL(finished(int)), this, SLOT(show()));
    window->setAttribute(Qt::WA_DeleteOnClose);
    window->move(width(),height());
    window->show();
    this->hide();
    move(window->width(),window->height());

}

void MenuKalc::openRaster(){
    RasterGui* window = new RasterGui(controller, this);
    connect(window, SIGNAL(finished(int)), this, SLOT(show()));
    window->setAttribute(Qt::WA_DeleteOnClose);
    window->move(width(),height());
    window->show();
    this->hide();
    move(window->width(),window->height());

}
