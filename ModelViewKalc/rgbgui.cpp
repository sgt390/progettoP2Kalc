#include "rgbgui.h"
#include "ui_rgbgui.h"
#include "qvector.h"

RgbGui::RgbGui(ControlKalc* ctr, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::RgbGui), controller(ctr)
{
    ui->setupUi(this);
    ui->slider_alpha->setValue(255);
    ui->lineEdit_alpha->setText(QString::number(ui->slider_alpha->value()));
    ui->lineEdit_red->setText(QString::number(ui->slider_red->value()));
    ui->lineEdit_green->setText(QString::number(ui->slider_green->value()));
    ui->lineEdit_blue->setText(QString::number(ui->slider_blue->value()));
    update_display();

    ui->btn_selezionar->setEnabled(false);
    ui->btn_selezionar->setVisible(false);
    connect(ui->slider_alpha, SIGNAL(valueChanged(int)), this, SLOT(set_alphaText(int)));
    connect(ui->slider_red, SIGNAL(valueChanged(int)), this, SLOT(set_redText(int)));
    connect(ui->slider_green, SIGNAL(valueChanged(int)), this, SLOT(set_greenText(int)));
    connect(ui->slider_blue, SIGNAL(valueChanged(int)), this, SLOT(set_blueText(int)));

    connect(ui->slider_alpha, SIGNAL(valueChanged(int)), this, SLOT(update_display()));
    connect(ui->slider_red, SIGNAL(valueChanged(int)), this, SLOT(update_display()));
    connect(ui->slider_green, SIGNAL(valueChanged(int)), this, SLOT(update_display()));
    connect(ui->slider_blue, SIGNAL(valueChanged(int)), this, SLOT(update_display()));


    connect(ui->btn_close, SIGNAL(released()), this, SLOT(close()));


}

RgbGui::~RgbGui()
{
    delete ui;
}

void RgbGui::set_alphaText(int t){
    ui->lineEdit_alpha->setText(QString::number(t));

}
void RgbGui::set_redText(int t){
    ui->lineEdit_red->setText(QString::number(t));

}
void RgbGui::set_greenText(int t){
    ui->lineEdit_green->setText(QString::number(t));

}
void RgbGui::set_blueText(int t){
    ui->lineEdit_blue->setText(QString::number(t));

}

void RgbGui::update_display(){
    QPalette pal = ui->display_rgb->palette();
    pal.setColor(QPalette::Background, QColor::fromRgb(
                     ui->slider_red->value(), ui->slider_green->value(), ui->slider_blue->value(), ui->slider_alpha->value()
                     ));
    ui->display_rgb->setPalette(pal);
}

void RgbGui::on_btn_seleziona_clicked()
{
    try{
    QVector<int> tmpV(controller->esegui(ui->slider_red->value(),
                       ui->slider_green->value(),
                       ui->slider_blue->value(),
                       ui->slider_alpha->value()));
        if(tmpV.size()<4)
            throw eccezione_OperandoGui();
        ui->slider_red->setValue(tmpV[0]);
        ui->slider_green->setValue(tmpV[1]);
        ui->slider_blue->setValue(tmpV[2]);
        ui->slider_alpha->setValue(tmpV[3]);
    }catch(eccezione_OperandoGui){
        std::cerr<<"operando sbagliato nella rgbGUI";
        ui->label_errorRgb->setText("operando sbagliato nella rgbGUI");
    }

}

void RgbGui::on_btn_mescola_clicked()
{
    controller->mescolaRGB(ui->slider_red->value(),
                           ui->slider_green->value(),
                           ui->slider_blue->value(),
                           ui->slider_alpha->value());
}
void RgbGui::on_btn_rimuovi_clicked()
{
    controller->rimuoviRGB(ui->slider_red->value(),
                           ui->slider_green->value(),
                           ui->slider_blue->value(),
                           ui->slider_alpha->value());
}



void RgbGui::on_btn_distanza_clicked()
{
    controller->distanzaRGB(ui->slider_red->value(),
                           ui->slider_green->value(),
                           ui->slider_blue->value(),
                           ui->slider_alpha->value());
}

void RgbGui::on_btn_grigio_clicked()
{
    try{
    QVector<int> tmpV(controller->singola(ui->slider_red->value(),
                       ui->slider_green->value(),
                       ui->slider_blue->value(),
                       ui->slider_alpha->value(), "GrigioRGB"));
        if(tmpV.size()<4)
            throw eccezione_OperandoGui();
        ui->slider_red->setValue(tmpV[0]);
        ui->slider_green->setValue(tmpV[1]);
        ui->slider_blue->setValue(tmpV[2]);
        ui->slider_alpha->setValue(tmpV[3]);
    }catch(eccezione_OperandoGui){
        std::cerr<<"operando sbagliato nella rgbGUI";
        ui->label_errorRgb->setText("operando sbagliato nella rgbGUI");
    }
}

void RgbGui::on_btn_negativo_clicked()
{

    try{
    QVector<int> tmpV(controller->singola(ui->slider_red->value(),
                       ui->slider_green->value(),
                       ui->slider_blue->value(),
                       ui->slider_alpha->value(), "InvertiRGB"));
        if(tmpV.size()<4)
            throw eccezione_OperandoGui();
        ui->slider_red->setValue(tmpV[0]);
        ui->slider_green->setValue(tmpV[1]);
        ui->slider_blue->setValue(tmpV[2]);
        ui->slider_alpha->setValue(tmpV[3]);
    }catch(eccezione_OperandoGui){
        std::cerr<<"operando sbagliato nella rgbGUI";
        ui->label_errorRgb->setText("operando sbagliato nella rgbGUI");
    }
}

void RgbGui::on_btn_puro_clicked()
{
    try{
    QVector<int> tmpV(controller->singola(ui->slider_red->value(),
                       ui->slider_green->value(),
                       ui->slider_blue->value(),
                       ui->slider_alpha->value(), "PuroRGB"));
        if(tmpV.size()<4)
            throw eccezione_OperandoGui();
        ui->slider_red->setValue(tmpV[0]);
        ui->slider_green->setValue(tmpV[1]);
        ui->slider_blue->setValue(tmpV[2]);
        ui->slider_alpha->setValue(tmpV[3]);
    }catch(eccezione_OperandoGui){
        std::cerr<<"operando sbagliato nella rgbGUI"<<std::endl;
        ui->label_errorRgb->setText("operando sbagliato nella rgbGUI");
    }
}
void RgbGui::disabilitaBtn(){
    ui->btn_distanza->setEnabled(false);
    ui->btn_rimuovi->setEnabled(false);
    ui->btn_grigio->setEnabled(false);
    ui->btn_mescola->setEnabled(false);
    ui->btn_negativo->setEnabled(false);
    ui->btn_puro->setEnabled(false);
    ui->btn_seleziona->setEnabled(false);
    ui->btn_seleziona->setVisible(false);
    ui->btn_selezionar->setEnabled(true);
    ui->btn_selezionar->setVisible(true);
}



void RgbGui::on_btn_selezionar_clicked()
{
    try{
        controller->esegui(ui->slider_red->value(),
                           ui->slider_green->value(),
                           ui->slider_blue->value(),
                           ui->slider_alpha->value());
        close();
    }catch(eccezione_parametro_dimensioneErrata){
        std::cerr<<"errore nel parametro dimensione (rgbGUI)";
        ui->label_errorRgb->setText("errore nel parametro dimensione (rgbGUI)");
    }
}
