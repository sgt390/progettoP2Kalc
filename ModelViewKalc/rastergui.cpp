#include "rastergui.h"
#include "ui_rastergui.h"
#include<iostream>
#include "eccezioni.h"
#include "rgbgui.h"

RasterGui::RasterGui(ControlKalc *ctr, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::RasterGui),
    display(new displayKalc(1,1,10,10,this)), controller(ctr)

{
    ui->setupUi(this);

    connect(ui->btn_close, SIGNAL(clicked(bool)), this, SLOT(close()));
    connect(ui->btn_openDisplay, SIGNAL(clicked(bool)), this, SLOT(openDisplay()));

}

RasterGui::~RasterGui()
{
    delete ui;
    for(QVector<pixelDisplay*>::iterator it = pixelVector.begin(); it != pixelVector.end(); ++it){
        delete *it;
    }
}

void RasterGui::openDisplay(){
    int maxX = 1;
    int maxY = 1;
    for(QVector<pixelDisplay*>::const_iterator it = pixelVector.begin(); it != pixelVector.end(); ++it){
        if(((*it)->x) +1 > maxX) maxX = ((*it)->x)+1;
        if(((*it)->y) +1 > maxY) maxY = ((*it)->y)+1;
    }

    displayKalc* display= new displayKalc(maxX,maxY,10,10,this);
    display->setAttribute(Qt::WA_DeleteOnClose);
    for(QVector<pixelDisplay*>::const_iterator it = pixelVector.begin(); it != pixelVector.end(); ++it){
        display->setColore((*it)->x, (*it)->y, (*it)->r, (*it)->g, (*it)->b, (*it)->a);
    }

    display->show();
}

RasterGui::pixelDisplay::pixelDisplay(int _x, int _y, int _r, int _g, int _b, int _a):x(_x), y(_y), r(_r), g(_g), b(_b), a(_a){}

void RasterGui::inserisciPixel(int _x, int _y, int _r, int _g, int _b,int _a){
    for(QVector<pixelDisplay*>::iterator it = pixelVector.begin(); it != pixelVector.end(); ++it)
        if((*it)->x == _x && (*it)->y == _y){
            delete *it;
            it=pixelVector.erase(it);
            it--;
        }
    pixelVector.push_back(new pixelDisplay(_x,_y,_r,_g,_b,_a));
}

void RasterGui::on_pushButton_quadrato_clicked()
{
    try{
    int xi = ui->lineEdit_xi->text().toInt();
    int xf = ui->lineEdit_xf->text().toInt();
    int yi = ui->lineEdit_yi->text().toInt();
    int yf = ui->lineEdit_yf->text().toInt();
    if(xi<0 || xi>999 || yi<0 || yi>999 || xf<0 || xf>999 || yf<0 || yf>999)
        throw eccezione_dimensioneDisplay();
    controller->quadratoDisplay(xi,xf,yi,yf);
    RgbGui* wrgb = new RgbGui(controller, this);
    connect(wrgb, SIGNAL(finished(int)), this, SLOT(show()));
    display->setAttribute(Qt::WA_DeleteOnClose);
    wrgb->disabilitaBtn();
    connect(wrgb, SIGNAL(finished(int)), this, SLOT(aggiornaRaster()));
    wrgb->show();
    this->hide();

    }catch(eccezione_dimensioneDisplay){
        std::cerr<<"dimensione del display non corretta [0,999]"<<std::endl;
        ui->label_errorDisplay->setText("dimensione del display non corretta [0,999");
    }
}
void RasterGui::aggiornaRaster(){
    try{
        ui->label_errorDisplay->setText("");
    QVector<int> dv = controller->getRisultato();
    if(dv.size()%6 != 0)
        throw eccezione_OperandoGui();
    for(auto it = dv.begin(); it!=dv.end(); it=it+6){
        inserisciPixel((*(it+4)),*(it+5),*it,*(it+1),*(it+2),*(it+3));
    }
    }catch(eccezione_OperandoGui){
        std::cerr<<"operando display non corretto"<<std::endl;
        ui->label_errorDisplay->setText("operando display non corretto");
    }

}

void RasterGui::on_pushButton_linea_clicked()
{
    try{
        int x = ui->lineEdit_linea->text().toInt();
        if(x<0 || x>999)
            throw eccezione_dimensioneDisplay();
        controller->rigaDisplay(x);
        RgbGui* wrgb = new RgbGui(controller, this);
        connect(wrgb, SIGNAL(finished(int)), this, SLOT(show()));
        display->setAttribute(Qt::WA_DeleteOnClose);
        wrgb->disabilitaBtn();
        connect(wrgb, SIGNAL(finished(int)), this, SLOT(aggiornaRaster()));
        wrgb->show();
        this->hide();
    }catch(eccezione_dimensioneDisplay){
        std::cerr<<"riga non corretta [0,999]"<<std::endl;
        ui->label_errorDisplay->setText("origa non corretta [0,999]");
    }
    catch(eccezione_displayNonEsistente){
        std::cerr<<"la riga non esiste nel display"<<std::endl;
        ui->label_errorDisplay->setText("la riga non esiste nel display");
    }
    catch(eccezione_parametro_dimensioneErrata){
        std::cerr<<"dimensione del display errata (gui)"<<std::endl;
        ui->label_errorDisplay->setText("la riga non esiste nel display");
    }
}

void RasterGui::on_pushButton_colonna_clicked()
{
    try{
        int y = ui->lineEdit_colonna->text().toInt();
        if(y<0 || y>999)
            throw eccezione_dimensioneDisplay();
        controller->colonnaDisplay(y);
        RgbGui* wrgb = new RgbGui(controller, this);
        connect(wrgb, SIGNAL(finished(int)), this, SLOT(show()));
        display->setAttribute(Qt::WA_DeleteOnClose);
        wrgb->disabilitaBtn();
        connect(wrgb, SIGNAL(finished(int)), this, SLOT(aggiornaRaster()));
        wrgb->show();
        this->hide();
    }catch(eccezione_dimensioneDisplay){
        std::cerr<<"riga non corretta [0,999]"<<std::endl;
        ui->label_errorDisplay->setText("origa non corretta [0,999]");
    }
    catch(eccezione_displayNonEsistente){
        std::cerr<<"la riga non esiste nel display"<<std::endl;
        ui->label_errorDisplay->setText("la riga non esiste nel display");
    }
    catch(eccezione_parametro_dimensioneErrata){
        std::cerr<<"dimensione del display errata (gui)"<<std::endl;
        ui->label_errorDisplay->setText("la riga non esiste nel display");
    }
}

void RasterGui::on_btn_svuota_clicked()
{
    if(controller) delete controller;
    controller = new ControlKalc();
    pixelVector.erase(pixelVector.begin(), pixelVector.end());
}
