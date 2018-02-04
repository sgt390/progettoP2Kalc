/********************************************************************************
** Form generated from reading UI file 'kalcgui.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_KALCGUI_H
#define UI_KALCGUI_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_kalcGui
{
public:
    QMenuBar *menubar;
    QWidget *centralwidget;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *kalcGui)
    {
        if (kalcGui->objectName().isEmpty())
            kalcGui->setObjectName(QStringLiteral("kalcGui"));
        kalcGui->resize(800, 600);
        menubar = new QMenuBar(kalcGui);
        menubar->setObjectName(QStringLiteral("menubar"));
        kalcGui->setMenuBar(menubar);
        centralwidget = new QWidget(kalcGui);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        kalcGui->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(kalcGui);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        kalcGui->setStatusBar(statusbar);

        retranslateUi(kalcGui);

        QMetaObject::connectSlotsByName(kalcGui);
    } // setupUi

    void retranslateUi(QMainWindow *kalcGui)
    {
        kalcGui->setWindowTitle(QApplication::translate("kalcGui", "MainWindow", 0));
    } // retranslateUi

};

namespace Ui {
    class kalcGui: public Ui_kalcGui {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_KALCGUI_H
