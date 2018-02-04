/********************************************************************************
** Form generated from reading UI file 'rastergui.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RASTERGUI_H
#define UI_RASTERGUI_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_RasterGui
{
public:
    QGridLayout *gridLayout_4;
    QGridLayout *gridLayout;
    QLabel *label_2;
    QLineEdit *lineEdit_yf;
    QPushButton *pushButton_quadrato;
    QLineEdit *lineEdit_xf;
    QLineEdit *lineEdit_xi;
    QLineEdit *lineEdit_yi;
    QLabel *label_3;
    QLabel *label;
    QLabel *label_4;
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout_3;
    QLabel *label_6;
    QLineEdit *lineEdit_colonna;
    QPushButton *pushButton_colonna;
    QGridLayout *gridLayout_2;
    QLabel *label_5;
    QLineEdit *lineEdit_linea;
    QPushButton *pushButton_linea;
    QPushButton *btn_svuota;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout;
    QPushButton *btn_openDisplay;
    QSpacerItem *horizontalSpacer;
    QPushButton *btn_close;
    QLabel *label_errorDisplay;

    void setupUi(QDialog *RasterGui)
    {
        if (RasterGui->objectName().isEmpty())
            RasterGui->setObjectName(QStringLiteral("RasterGui"));
        RasterGui->resize(471, 251);
        gridLayout_4 = new QGridLayout(RasterGui);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        label_2 = new QLabel(RasterGui);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        lineEdit_yf = new QLineEdit(RasterGui);
        lineEdit_yf->setObjectName(QStringLiteral("lineEdit_yf"));
        lineEdit_yf->setMaximumSize(QSize(50, 16777215));

        gridLayout->addWidget(lineEdit_yf, 2, 2, 1, 1);

        pushButton_quadrato = new QPushButton(RasterGui);
        pushButton_quadrato->setObjectName(QStringLiteral("pushButton_quadrato"));

        gridLayout->addWidget(pushButton_quadrato, 3, 0, 1, 3);

        lineEdit_xf = new QLineEdit(RasterGui);
        lineEdit_xf->setObjectName(QStringLiteral("lineEdit_xf"));
        lineEdit_xf->setMaximumSize(QSize(50, 16777215));

        gridLayout->addWidget(lineEdit_xf, 2, 1, 1, 1);

        lineEdit_xi = new QLineEdit(RasterGui);
        lineEdit_xi->setObjectName(QStringLiteral("lineEdit_xi"));
        lineEdit_xi->setMaximumSize(QSize(50, 16777215));

        gridLayout->addWidget(lineEdit_xi, 1, 1, 1, 1);

        lineEdit_yi = new QLineEdit(RasterGui);
        lineEdit_yi->setObjectName(QStringLiteral("lineEdit_yi"));
        lineEdit_yi->setMaximumSize(QSize(50, 16777215));

        gridLayout->addWidget(lineEdit_yi, 1, 2, 1, 1);

        label_3 = new QLabel(RasterGui);
        label_3->setObjectName(QStringLiteral("label_3"));

        gridLayout->addWidget(label_3, 2, 0, 1, 1);

        label = new QLabel(RasterGui);
        label->setObjectName(QStringLiteral("label"));

        gridLayout->addWidget(label, 0, 1, 1, 1);

        label_4 = new QLabel(RasterGui);
        label_4->setObjectName(QStringLiteral("label_4"));

        gridLayout->addWidget(label_4, 0, 2, 1, 1);


        gridLayout_4->addLayout(gridLayout, 0, 0, 1, 1);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        gridLayout_3 = new QGridLayout();
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        label_6 = new QLabel(RasterGui);
        label_6->setObjectName(QStringLiteral("label_6"));

        gridLayout_3->addWidget(label_6, 0, 0, 1, 1);

        lineEdit_colonna = new QLineEdit(RasterGui);
        lineEdit_colonna->setObjectName(QStringLiteral("lineEdit_colonna"));
        lineEdit_colonna->setMaximumSize(QSize(50, 16777215));

        gridLayout_3->addWidget(lineEdit_colonna, 0, 1, 1, 1);

        pushButton_colonna = new QPushButton(RasterGui);
        pushButton_colonna->setObjectName(QStringLiteral("pushButton_colonna"));

        gridLayout_3->addWidget(pushButton_colonna, 1, 0, 1, 2);


        verticalLayout->addLayout(gridLayout_3);

        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        label_5 = new QLabel(RasterGui);
        label_5->setObjectName(QStringLiteral("label_5"));

        gridLayout_2->addWidget(label_5, 0, 0, 1, 1);

        lineEdit_linea = new QLineEdit(RasterGui);
        lineEdit_linea->setObjectName(QStringLiteral("lineEdit_linea"));
        lineEdit_linea->setMaximumSize(QSize(50, 16777215));

        gridLayout_2->addWidget(lineEdit_linea, 0, 1, 1, 1);

        pushButton_linea = new QPushButton(RasterGui);
        pushButton_linea->setObjectName(QStringLiteral("pushButton_linea"));

        gridLayout_2->addWidget(pushButton_linea, 1, 0, 1, 2);


        verticalLayout->addLayout(gridLayout_2);


        gridLayout_4->addLayout(verticalLayout, 0, 1, 1, 1);

        btn_svuota = new QPushButton(RasterGui);
        btn_svuota->setObjectName(QStringLiteral("btn_svuota"));

        gridLayout_4->addWidget(btn_svuota, 0, 2, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_4->addItem(verticalSpacer, 1, 1, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        btn_openDisplay = new QPushButton(RasterGui);
        btn_openDisplay->setObjectName(QStringLiteral("btn_openDisplay"));

        horizontalLayout->addWidget(btn_openDisplay);

        horizontalSpacer = new QSpacerItem(198, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        btn_close = new QPushButton(RasterGui);
        btn_close->setObjectName(QStringLiteral("btn_close"));

        horizontalLayout->addWidget(btn_close);


        gridLayout_4->addLayout(horizontalLayout, 2, 0, 1, 3);

        label_errorDisplay = new QLabel(RasterGui);
        label_errorDisplay->setObjectName(QStringLiteral("label_errorDisplay"));
        label_errorDisplay->setMaximumSize(QSize(16777215, 30));

        gridLayout_4->addWidget(label_errorDisplay, 3, 0, 1, 3);


        retranslateUi(RasterGui);

        QMetaObject::connectSlotsByName(RasterGui);
    } // setupUi

    void retranslateUi(QDialog *RasterGui)
    {
        RasterGui->setWindowTitle(QApplication::translate("RasterGui", "Dialog", 0));
        label_2->setText(QApplication::translate("RasterGui", "Inizio:", 0));
        pushButton_quadrato->setText(QApplication::translate("RasterGui", "ColoraQuadrato", 0));
        label_3->setText(QApplication::translate("RasterGui", "Fine:", 0));
        label->setText(QApplication::translate("RasterGui", "x", 0));
        label_4->setText(QApplication::translate("RasterGui", "y", 0));
        label_6->setText(QApplication::translate("RasterGui", "Colonna:", 0));
        pushButton_colonna->setText(QApplication::translate("RasterGui", "Colora Colonna", 0));
        label_5->setText(QApplication::translate("RasterGui", "Riga:", 0));
        pushButton_linea->setText(QApplication::translate("RasterGui", "Colora Riga", 0));
        btn_svuota->setText(QApplication::translate("RasterGui", "Svuota", 0));
        btn_openDisplay->setText(QApplication::translate("RasterGui", "Display", 0));
        btn_close->setText(QApplication::translate("RasterGui", "Chiudi", 0));
        label_errorDisplay->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class RasterGui: public Ui_RasterGui {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RASTERGUI_H
