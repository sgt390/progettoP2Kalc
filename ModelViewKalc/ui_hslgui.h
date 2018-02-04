/********************************************************************************
** Form generated from reading UI file 'hslgui.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HSLGUI_H
#define UI_HSLGUI_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>

QT_BEGIN_NAMESPACE

class Ui_HslGui
{
public:
    QGridLayout *gridLayout;
    QGridLayout *gridLayout_3;
    QLineEdit *lineEdit_hue;
    QLineEdit *lineEdit_lightness;
    QSlider *slider_light;
    QSlider *slider_alpha;
    QSlider *slider_hue;
    QSlider *slider_sat;
    QLineEdit *lineEdit_saturation;
    QLineEdit *lineEdit_alpha;
    QFrame *display_hsl;
    QGridLayout *gridLayout_2;
    QPushButton *btn_inverti;
    QPushButton *btn_puro;
    QPushButton *btn_mixsat;
    QPushButton *btn_grigio;
    QPushButton *btn_mixlum;
    QPushButton *btn_sfuma;
    QHBoxLayout *horizontalLayout;
    QPushButton *btn_seleziona;
    QSpacerItem *horizontalSpacer;
    QPushButton *btn_close;
    QLabel *label_errorHue;

    void setupUi(QDialog *HslGui)
    {
        if (HslGui->objectName().isEmpty())
            HslGui->setObjectName(QStringLiteral("HslGui"));
        HslGui->resize(572, 392);
        gridLayout = new QGridLayout(HslGui);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout_3 = new QGridLayout();
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        lineEdit_hue = new QLineEdit(HslGui);
        lineEdit_hue->setObjectName(QStringLiteral("lineEdit_hue"));
        lineEdit_hue->setMaximumSize(QSize(40, 16777215));
        lineEdit_hue->setAutoFillBackground(false);
        lineEdit_hue->setReadOnly(true);

        gridLayout_3->addWidget(lineEdit_hue, 0, 1, 1, 1);

        lineEdit_lightness = new QLineEdit(HslGui);
        lineEdit_lightness->setObjectName(QStringLiteral("lineEdit_lightness"));
        lineEdit_lightness->setMaximumSize(QSize(40, 16777215));
        lineEdit_lightness->setReadOnly(true);

        gridLayout_3->addWidget(lineEdit_lightness, 2, 1, 1, 1);

        slider_light = new QSlider(HslGui);
        slider_light->setObjectName(QStringLiteral("slider_light"));
        slider_light->setMaximum(255);
        slider_light->setOrientation(Qt::Horizontal);

        gridLayout_3->addWidget(slider_light, 2, 2, 1, 1);

        slider_alpha = new QSlider(HslGui);
        slider_alpha->setObjectName(QStringLiteral("slider_alpha"));
        slider_alpha->setMaximum(255);
        slider_alpha->setOrientation(Qt::Vertical);

        gridLayout_3->addWidget(slider_alpha, 0, 3, 2, 1);

        slider_hue = new QSlider(HslGui);
        slider_hue->setObjectName(QStringLiteral("slider_hue"));
        slider_hue->setMaximum(360);
        slider_hue->setOrientation(Qt::Horizontal);

        gridLayout_3->addWidget(slider_hue, 0, 2, 1, 1);

        slider_sat = new QSlider(HslGui);
        slider_sat->setObjectName(QStringLiteral("slider_sat"));
        slider_sat->setMaximum(255);
        slider_sat->setOrientation(Qt::Horizontal);

        gridLayout_3->addWidget(slider_sat, 1, 2, 1, 1);

        lineEdit_saturation = new QLineEdit(HslGui);
        lineEdit_saturation->setObjectName(QStringLiteral("lineEdit_saturation"));
        lineEdit_saturation->setMaximumSize(QSize(40, 16777215));
        lineEdit_saturation->setReadOnly(true);

        gridLayout_3->addWidget(lineEdit_saturation, 1, 1, 1, 1);

        lineEdit_alpha = new QLineEdit(HslGui);
        lineEdit_alpha->setObjectName(QStringLiteral("lineEdit_alpha"));
        lineEdit_alpha->setMinimumSize(QSize(0, 0));
        lineEdit_alpha->setMaximumSize(QSize(40, 16777215));
        lineEdit_alpha->setReadOnly(true);

        gridLayout_3->addWidget(lineEdit_alpha, 2, 3, 1, 1);

        display_hsl = new QFrame(HslGui);
        display_hsl->setObjectName(QStringLiteral("display_hsl"));
        display_hsl->setMinimumSize(QSize(190, 0));
        display_hsl->setAutoFillBackground(true);
        display_hsl->setFrameShape(QFrame::StyledPanel);
        display_hsl->setFrameShadow(QFrame::Raised);

        gridLayout_3->addWidget(display_hsl, 0, 0, 3, 1);


        gridLayout->addLayout(gridLayout_3, 0, 0, 1, 1);

        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        btn_inverti = new QPushButton(HslGui);
        btn_inverti->setObjectName(QStringLiteral("btn_inverti"));

        gridLayout_2->addWidget(btn_inverti, 1, 0, 1, 1);

        btn_puro = new QPushButton(HslGui);
        btn_puro->setObjectName(QStringLiteral("btn_puro"));

        gridLayout_2->addWidget(btn_puro, 0, 1, 1, 1);

        btn_mixsat = new QPushButton(HslGui);
        btn_mixsat->setObjectName(QStringLiteral("btn_mixsat"));

        gridLayout_2->addWidget(btn_mixsat, 1, 1, 1, 1);

        btn_grigio = new QPushButton(HslGui);
        btn_grigio->setObjectName(QStringLiteral("btn_grigio"));

        gridLayout_2->addWidget(btn_grigio, 0, 0, 1, 1);

        btn_mixlum = new QPushButton(HslGui);
        btn_mixlum->setObjectName(QStringLiteral("btn_mixlum"));

        gridLayout_2->addWidget(btn_mixlum, 0, 2, 1, 1);

        btn_sfuma = new QPushButton(HslGui);
        btn_sfuma->setObjectName(QStringLiteral("btn_sfuma"));

        gridLayout_2->addWidget(btn_sfuma, 1, 2, 1, 1);


        gridLayout->addLayout(gridLayout_2, 1, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        btn_seleziona = new QPushButton(HslGui);
        btn_seleziona->setObjectName(QStringLiteral("btn_seleziona"));

        horizontalLayout->addWidget(btn_seleziona);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        btn_close = new QPushButton(HslGui);
        btn_close->setObjectName(QStringLiteral("btn_close"));

        horizontalLayout->addWidget(btn_close);


        gridLayout->addLayout(horizontalLayout, 2, 0, 1, 1);

        label_errorHue = new QLabel(HslGui);
        label_errorHue->setObjectName(QStringLiteral("label_errorHue"));
        label_errorHue->setMaximumSize(QSize(16777215, 30));

        gridLayout->addWidget(label_errorHue, 3, 0, 1, 1);


        retranslateUi(HslGui);

        QMetaObject::connectSlotsByName(HslGui);
    } // setupUi

    void retranslateUi(QDialog *HslGui)
    {
        HslGui->setWindowTitle(QApplication::translate("HslGui", "Dialog", 0));
        btn_inverti->setText(QApplication::translate("HslGui", "Inverti", 0));
        btn_puro->setText(QApplication::translate("HslGui", "Puro", 0));
        btn_mixsat->setText(QApplication::translate("HslGui", "mescola Saturazione", 0));
        btn_grigio->setText(QApplication::translate("HslGui", "Grigio", 0));
        btn_mixlum->setText(QApplication::translate("HslGui", "mescola luminosit\303\240", 0));
        btn_sfuma->setText(QApplication::translate("HslGui", "Sfuma", 0));
        btn_seleziona->setText(QApplication::translate("HslGui", "Seleziona", 0));
        btn_close->setText(QApplication::translate("HslGui", "Chiudi", 0));
        label_errorHue->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class HslGui: public Ui_HslGui {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HSLGUI_H
