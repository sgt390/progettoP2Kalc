/********************************************************************************
** Form generated from reading UI file 'menukalc.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MENUKALC_H
#define UI_MENUKALC_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MenuKalc
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *btn_close;
    QVBoxLayout *verticalLayout_3;
    QPushButton *btn_rgb;
    QPushButton *btn_hsl;
    QPushButton *btn_raster;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MenuKalc)
    {
        if (MenuKalc->objectName().isEmpty())
            MenuKalc->setObjectName(QStringLiteral("MenuKalc"));
        MenuKalc->resize(400, 300);
        centralWidget = new QWidget(MenuKalc);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        horizontalSpacer = new QSpacerItem(298, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 1, 0, 1, 1);

        btn_close = new QPushButton(centralWidget);
        btn_close->setObjectName(QStringLiteral("btn_close"));

        gridLayout->addWidget(btn_close, 1, 1, 1, 1);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        btn_rgb = new QPushButton(centralWidget);
        btn_rgb->setObjectName(QStringLiteral("btn_rgb"));

        verticalLayout_3->addWidget(btn_rgb);

        btn_hsl = new QPushButton(centralWidget);
        btn_hsl->setObjectName(QStringLiteral("btn_hsl"));

        verticalLayout_3->addWidget(btn_hsl);

        btn_raster = new QPushButton(centralWidget);
        btn_raster->setObjectName(QStringLiteral("btn_raster"));

        verticalLayout_3->addWidget(btn_raster);


        gridLayout->addLayout(verticalLayout_3, 0, 0, 1, 2);

        MenuKalc->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MenuKalc);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 400, 21));
        MenuKalc->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MenuKalc);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MenuKalc->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MenuKalc);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MenuKalc->setStatusBar(statusBar);

        retranslateUi(MenuKalc);

        QMetaObject::connectSlotsByName(MenuKalc);
    } // setupUi

    void retranslateUi(QMainWindow *MenuKalc)
    {
        MenuKalc->setWindowTitle(QApplication::translate("MenuKalc", "Kalc Menu", 0));
        btn_close->setText(QApplication::translate("MenuKalc", "Chiudi", 0));
        btn_rgb->setText(QApplication::translate("MenuKalc", "RGB", 0));
        btn_hsl->setText(QApplication::translate("MenuKalc", "HSL", 0));
        btn_raster->setText(QApplication::translate("MenuKalc", "Raster", 0));
    } // retranslateUi

};

namespace Ui {
    class MenuKalc: public Ui_MenuKalc {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MENUKALC_H
