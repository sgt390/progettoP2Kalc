/********************************************************************************
** Form generated from reading UI file 'rgbgui.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RGBGUI_H
#define UI_RGBGUI_H

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

class Ui_RgbGui
{
public:
    QGridLayout *gridLayout_4;
    QGridLayout *gridLayout_3;
    QFrame *display_rgb;
    QGridLayout *gridLayout_2;
    QLineEdit *lineEdit_green;
    QLineEdit *lineEdit_red;
    QSlider *slider_alpha;
    QSlider *slider_blue;
    QLineEdit *lineEdit_alpha;
    QSlider *slider_green;
    QLineEdit *lineEdit_blue;
    QSlider *slider_red;
    QGridLayout *gridLayout;
    QPushButton *btn_negativo;
    QPushButton *btn_grigio;
    QPushButton *btn_mescola;
    QPushButton *btn_rimuovi;
    QPushButton *btn_distanza;
    QPushButton *btn_puro;
    QHBoxLayout *horizontalLayout;
    QPushButton *btn_seleziona;
    QPushButton *btn_selezionar;
    QSpacerItem *horizontalSpacer;
    QPushButton *btn_close;
    QLabel *label_errorRgb;

    void setupUi(QDialog *RgbGui)
    {
        if (RgbGui->objectName().isEmpty())
            RgbGui->setObjectName(QStringLiteral("RgbGui"));
        RgbGui->resize(505, 320);
        gridLayout_4 = new QGridLayout(RgbGui);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        gridLayout_3 = new QGridLayout();
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        display_rgb = new QFrame(RgbGui);
        display_rgb->setObjectName(QStringLiteral("display_rgb"));
        display_rgb->setMinimumSize(QSize(140, 0));
        display_rgb->setAutoFillBackground(true);
        display_rgb->setFrameShape(QFrame::StyledPanel);
        display_rgb->setFrameShadow(QFrame::Raised);

        gridLayout_3->addWidget(display_rgb, 0, 0, 1, 1);

        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        lineEdit_green = new QLineEdit(RgbGui);
        lineEdit_green->setObjectName(QStringLiteral("lineEdit_green"));
        lineEdit_green->setMaximumSize(QSize(40, 20));
        lineEdit_green->setReadOnly(true);

        gridLayout_2->addWidget(lineEdit_green, 1, 0, 1, 1);

        lineEdit_red = new QLineEdit(RgbGui);
        lineEdit_red->setObjectName(QStringLiteral("lineEdit_red"));
        lineEdit_red->setMaximumSize(QSize(40, 20));
        lineEdit_red->setLayoutDirection(Qt::LeftToRight);
        lineEdit_red->setReadOnly(true);
        lineEdit_red->setCursorMoveStyle(Qt::LogicalMoveStyle);

        gridLayout_2->addWidget(lineEdit_red, 0, 0, 1, 1);

        slider_alpha = new QSlider(RgbGui);
        slider_alpha->setObjectName(QStringLiteral("slider_alpha"));
        slider_alpha->setMaximum(255);
        slider_alpha->setOrientation(Qt::Vertical);

        gridLayout_2->addWidget(slider_alpha, 0, 2, 2, 1);

        slider_blue = new QSlider(RgbGui);
        slider_blue->setObjectName(QStringLiteral("slider_blue"));
        slider_blue->setMaximum(255);
        slider_blue->setOrientation(Qt::Horizontal);

        gridLayout_2->addWidget(slider_blue, 2, 1, 1, 1);

        lineEdit_alpha = new QLineEdit(RgbGui);
        lineEdit_alpha->setObjectName(QStringLiteral("lineEdit_alpha"));
        lineEdit_alpha->setMaximumSize(QSize(40, 20));
        lineEdit_alpha->setReadOnly(true);

        gridLayout_2->addWidget(lineEdit_alpha, 2, 2, 1, 1);

        slider_green = new QSlider(RgbGui);
        slider_green->setObjectName(QStringLiteral("slider_green"));
        slider_green->setMaximum(255);
        slider_green->setOrientation(Qt::Horizontal);

        gridLayout_2->addWidget(slider_green, 1, 1, 1, 1);

        lineEdit_blue = new QLineEdit(RgbGui);
        lineEdit_blue->setObjectName(QStringLiteral("lineEdit_blue"));
        lineEdit_blue->setMaximumSize(QSize(40, 20));
        lineEdit_blue->setReadOnly(true);

        gridLayout_2->addWidget(lineEdit_blue, 2, 0, 1, 1);

        slider_red = new QSlider(RgbGui);
        slider_red->setObjectName(QStringLiteral("slider_red"));
        slider_red->setMaximum(255);
        slider_red->setOrientation(Qt::Horizontal);

        gridLayout_2->addWidget(slider_red, 0, 1, 1, 1);


        gridLayout_3->addLayout(gridLayout_2, 0, 1, 1, 1);


        gridLayout_4->addLayout(gridLayout_3, 0, 0, 1, 1);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        btn_negativo = new QPushButton(RgbGui);
        btn_negativo->setObjectName(QStringLiteral("btn_negativo"));

        gridLayout->addWidget(btn_negativo, 1, 0, 1, 1);

        btn_grigio = new QPushButton(RgbGui);
        btn_grigio->setObjectName(QStringLiteral("btn_grigio"));

        gridLayout->addWidget(btn_grigio, 1, 1, 1, 1);

        btn_mescola = new QPushButton(RgbGui);
        btn_mescola->setObjectName(QStringLiteral("btn_mescola"));

        gridLayout->addWidget(btn_mescola, 0, 0, 1, 1);

        btn_rimuovi = new QPushButton(RgbGui);
        btn_rimuovi->setObjectName(QStringLiteral("btn_rimuovi"));

        gridLayout->addWidget(btn_rimuovi, 0, 1, 1, 1);

        btn_distanza = new QPushButton(RgbGui);
        btn_distanza->setObjectName(QStringLiteral("btn_distanza"));

        gridLayout->addWidget(btn_distanza, 0, 2, 1, 1);

        btn_puro = new QPushButton(RgbGui);
        btn_puro->setObjectName(QStringLiteral("btn_puro"));

        gridLayout->addWidget(btn_puro, 1, 2, 1, 1);


        gridLayout_4->addLayout(gridLayout, 1, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        btn_seleziona = new QPushButton(RgbGui);
        btn_seleziona->setObjectName(QStringLiteral("btn_seleziona"));

        horizontalLayout->addWidget(btn_seleziona);

        btn_selezionar = new QPushButton(RgbGui);
        btn_selezionar->setObjectName(QStringLiteral("btn_selezionar"));

        horizontalLayout->addWidget(btn_selezionar);

        horizontalSpacer = new QSpacerItem(398, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        btn_close = new QPushButton(RgbGui);
        btn_close->setObjectName(QStringLiteral("btn_close"));

        horizontalLayout->addWidget(btn_close);


        gridLayout_4->addLayout(horizontalLayout, 2, 0, 1, 1);

        label_errorRgb = new QLabel(RgbGui);
        label_errorRgb->setObjectName(QStringLiteral("label_errorRgb"));
        label_errorRgb->setMaximumSize(QSize(16777215, 30));

        gridLayout_4->addWidget(label_errorRgb, 3, 0, 1, 1);


        retranslateUi(RgbGui);

        QMetaObject::connectSlotsByName(RgbGui);
    } // setupUi

    void retranslateUi(QDialog *RgbGui)
    {
        RgbGui->setWindowTitle(QApplication::translate("RgbGui", "Kalc RGB", 0));
        btn_negativo->setText(QApplication::translate("RgbGui", "Negativo", 0));
        btn_grigio->setText(QApplication::translate("RgbGui", "Grigio", 0));
        btn_mescola->setText(QApplication::translate("RgbGui", "Mescola", 0));
        btn_rimuovi->setText(QApplication::translate("RgbGui", "Rimuovi", 0));
        btn_distanza->setText(QApplication::translate("RgbGui", "Distanza", 0));
        btn_puro->setText(QApplication::translate("RgbGui", "Puro", 0));
        btn_seleziona->setText(QApplication::translate("RgbGui", "Seleziona", 0));
        btn_selezionar->setText(QApplication::translate("RgbGui", "Seleziona", 0));
        btn_close->setText(QApplication::translate("RgbGui", "Chiudi", 0));
        label_errorRgb->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class RgbGui: public Ui_RgbGui {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RGBGUI_H
