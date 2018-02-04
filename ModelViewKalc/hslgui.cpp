#include "hslgui.h"
#include "ui_hslgui.h"
#include "controlkalc.h"
#include "eccezioni.h"

HslGui::HslGui(ControlKalc* ctr, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::HslGui), controller(ctr)
{
    ui->setupUi(this);

    ui->lineEdit_alpha->setText("255");
    ui->slider_alpha->setValue(255);
    ui->lineEdit_hue->setText("0");
    ui->lineEdit_saturation->setText("0");
    ui->lineEdit_lightness->setText("0");
    update_display();

    connect(ui->slider_alpha, SIGNAL(valueChanged(int)), this, SLOT(set_alphaText(int)));
    connect(ui->slider_hue, SIGNAL(valueChanged(int)), this, SLOT(set_hueText(int)));
    connect(ui->slider_sat, SIGNAL(valueChanged(int)), this, SLOT(set_saturationText(int)));
    connect(ui->slider_light, SIGNAL(valueChanged(int)), this, SLOT(set_lightnessText(int)));

    connect(ui->slider_alpha, SIGNAL(valueChanged(int)), this, SLOT(update_display()));
    connect(ui->slider_hue, SIGNAL(valueChanged(int)), this, SLOT(update_display()));
    connect(ui->slider_sat, SIGNAL(valueChanged(int)), this, SLOT(update_display()));
    connect(ui->slider_light, SIGNAL(valueChanged(int)), this, SLOT(update_display()));

    connect(ui->btn_close, SIGNAL(clicked(bool)), this, SLOT(close()));
}

HslGui::~HslGui()
{
    delete ui;
}

void HslGui::set_alphaText(int t){
    ui->lineEdit_alpha->setText(QString::number(t));
}

void HslGui::set_hueText(int t){
    ui->lineEdit_hue->setText(QString::number(t));
}

void HslGui::set_saturationText(int t){
    ui->lineEdit_saturation->setText(QString::number(t));
}

void HslGui::set_lightnessText(int t){
    ui->lineEdit_lightness->setText(QString::number(t));
}

void HslGui::update_display(){

    QPalette pal;
    pal.setColor(QPalette::Background, QColor::fromHsl(
                     ui->slider_hue->value()%360, ui->slider_sat->value(), ui->slider_light->value(), ui->slider_alpha->value()
                     ));
    ui->display_hsl->setPalette(pal);
}


void HslGui::on_btn_seleziona_clicked()
{
    try{
        QVector<int> tmpV(controller->esegui(ui->slider_hue->value(),
                           ui->slider_sat->value(),
                           ui->slider_light->value(),
                           ui->slider_alpha->value()));
        if(tmpV.size()<4)
            throw eccezione_OperandoGui();
        ui->slider_hue->setValue(tmpV[0]);
        ui->slider_sat->setValue(tmpV[1]);
        ui->slider_light->setValue(tmpV[2]);
        ui->slider_alpha->setValue(tmpV[3]);
    }catch(eccezione_OperandoGui){
        std::cerr<<"operando sbagliato nella hslGUI";
        ui->label_errorHue->setText("operando sbagliato nella hslGUI");
    }
}

void HslGui::on_btn_mixsat_clicked()
{
    controller->mixsatHSL(
                ui->slider_hue->value(),
                ui->slider_sat->value(),
                ui->slider_light->value(),
                ui->slider_alpha->value()
                );
}


void HslGui::on_btn_mixlum_clicked()
{
    controller->mixlumHSL(
                ui->slider_hue->value(),
                ui->slider_sat->value(),
                ui->slider_light->value(),
                ui->slider_alpha->value()
                );
}

void HslGui::on_btn_sfuma_clicked()
{
    controller->sfumaHSL(
                ui->slider_hue->value(),
                ui->slider_sat->value(),
                ui->slider_light->value(),
                ui->slider_alpha->value()
                );
}

void HslGui::on_btn_puro_clicked()
{
    try{
        QVector<int> tmpV(controller->singola(ui->slider_hue->value(),
                           ui->slider_sat->value(),
                           ui->slider_light->value(),
                           ui->slider_alpha->value(), "PuroHSL"));
        if(tmpV.size()<4)
            throw eccezione_OperandoGui();
        ui->slider_hue->setValue(tmpV[0]);
        ui->slider_sat->setValue(tmpV[1]);
        ui->slider_light->setValue(tmpV[2]);
        ui->slider_alpha->setValue(tmpV[3]);
    }catch(eccezione_OperandoGui){
        std::cerr<<"operando sbagliato nella hslGUI";
        ui->label_errorHue->setText("operando sbagliato nella hslGUI");
    }
}

void HslGui::on_btn_inverti_clicked()
{
    try{
        QVector<int> tmpV(controller->singola(ui->slider_hue->value(),
                           ui->slider_sat->value(),
                           ui->slider_light->value(),
                           ui->slider_alpha->value(), "InvertiHSL"));
        if(tmpV.size()<4)
            throw eccezione_OperandoGui();
        ui->slider_hue->setValue(tmpV[0]);
        ui->slider_sat->setValue(tmpV[1]);
        ui->slider_light->setValue(tmpV[2]);
        ui->slider_alpha->setValue(tmpV[3]);
    }catch(eccezione_OperandoGui){
        std::cerr<<"operando sbagliato nella hslGUI";
        ui->label_errorHue->setText("operando sbagliato nella hslGUI");
    }
}

void HslGui::on_btn_grigio_clicked()
{
    try{
        QVector<int> tmpV(controller->singola(ui->slider_hue->value(),
                           ui->slider_sat->value(),
                           ui->slider_light->value(),
                           ui->slider_alpha->value(), "GrigioHSL"));
        if(tmpV.size()<4)
            throw eccezione_OperandoGui();
        ui->slider_hue->setValue(tmpV[0]);
        ui->slider_sat->setValue(tmpV[1]);
        ui->slider_light->setValue(tmpV[2]);
        ui->slider_alpha->setValue(tmpV[3]);
    }catch(eccezione_OperandoGui){
        std::cerr<<"operando sbagliato nella hslGUI";
        ui->label_errorHue->setText("operando sbagliato nella hslGUI");
    }
}
