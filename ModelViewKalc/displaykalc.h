#ifndef DISPLAYKALC_H
#define DISPLAYKALC_H

#include <qdialog.h>
//#include <QtCore>
#include <QtGui>
#include <QMainWindow>

namespace Ui {
class displayKalc;
}

class displayKalc : public QDialog
{
    Q_OBJECT

public:
    explicit displayKalc(int, int, int, int, QWidget *parent = 0);
    ~displayKalc();

    void setColore(int, int, int, int, int, int); //x,y,r,g,b,a

private:
    Ui::displayKalc *ui;
    int heightGrid;
    int widthGrid;
    int heightPixel;
    int widthPixel;
    QStandardItemModel *model;
};

#endif // DISPLAYKALC_H
