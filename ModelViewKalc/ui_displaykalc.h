/********************************************************************************
** Form generated from reading UI file 'displaykalc.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DISPLAYKALC_H
#define UI_DISPLAYKALC_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QTableView>

QT_BEGIN_NAMESPACE

class Ui_displayKalc
{
public:
    QHBoxLayout *horizontalLayout;
    QTableView *tableView;

    void setupUi(QDialog *displayKalc)
    {
        if (displayKalc->objectName().isEmpty())
            displayKalc->setObjectName(QStringLiteral("displayKalc"));
        displayKalc->resize(400, 300);
        horizontalLayout = new QHBoxLayout(displayKalc);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        tableView = new QTableView(displayKalc);
        tableView->setObjectName(QStringLiteral("tableView"));
        tableView->horizontalHeader()->setVisible(false);
        tableView->horizontalHeader()->setHighlightSections(false);
        tableView->verticalHeader()->setVisible(false);
        tableView->verticalHeader()->setHighlightSections(false);

        horizontalLayout->addWidget(tableView);


        retranslateUi(displayKalc);

        QMetaObject::connectSlotsByName(displayKalc);
    } // setupUi

    void retranslateUi(QDialog *displayKalc)
    {
        displayKalc->setWindowTitle(QApplication::translate("displayKalc", "Display Kalc", 0));
    } // retranslateUi

};

namespace Ui {
    class displayKalc: public Ui_displayKalc {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DISPLAYKALC_H
