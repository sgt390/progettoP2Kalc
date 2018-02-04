#include "displaykalc.h"
#include "ui_displaykalc.h"
#include "eccezioni.h"

displayKalc::displayKalc(int _heightGrid, int _widthGrid,
                         int _heightPixel, int _widthPixel, QWidget *parent):
    QDialog(parent), ui(new Ui::displayKalc),
    heightGrid(_heightGrid), widthGrid(_widthGrid),
    heightPixel(_heightPixel),widthPixel(_widthPixel),
    model(new QStandardItemModel(heightGrid,widthGrid,this))
{
    ui->setupUi(this);

    QModelIndex index;
    QVector<QStandardItem*> items;
    QRadialGradient gradient(50,50,50,50,50);
    gradient.setColorAt(0, QColor::fromRgb(0,0,0));
    QBrush brush(gradient);
    for(int i=0; i<heightGrid; ++i)
        for(int j=0; j<widthGrid; ++j){
            items.push_back(new QStandardItem());
            items.last()->setBackground(brush);
        }
    for(int i=0; i<heightGrid; ++i)
        for(int j=0; j<widthGrid; ++j){
            index = model->index(i,j, QModelIndex());
            model->setItem(i,j, items[i*widthGrid+j]);
        }

    ui->tableView->setModel(model);
    resize(widthGrid*widthPixel+100, heightGrid*heightPixel+100); //eccezione grid 100x100

    for(int i=0; i<heightGrid; ++i)
        ui->tableView->setRowHeight(i,heightPixel);
    for(int i=0; i<widthGrid; ++i)
        ui->tableView->setColumnWidth(i,widthPixel);
}

displayKalc::~displayKalc()
{
    delete ui;
    for(int i=0; i<heightGrid; ++i)
        for(int j=0; j<widthGrid; ++j)
            delete model->itemFromIndex(model->index(i,j));
    delete model;
}

void displayKalc::setColore(int x, int y, int r, int g, int b, int a){
    QRadialGradient gradient(50,50,50,50,50);
    gradient.setColorAt(0, QColor::fromRgb(r,g,b,a));
    QBrush brush(gradient);
    model->itemFromIndex(model->index(x,y))->setBackground(brush);
    ui->tableView->setModel(model);
}
