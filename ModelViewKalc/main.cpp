#include "menukalc.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MenuKalc w;
    w.show();

    return a.exec();
}
